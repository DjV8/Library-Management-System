#include "..\Header\czytelnik.h"
#include "..\Header\ksiazka_W_obiegu.h"
#include "..\Header\baza_danych.h"
#include <iostream>
using namespace std;


// Załadowanie wskaźnika na ksiażki w obiegu by były zsynchronizowane z bazą danych
void Czytelnik::zaladuj_ksiazki_wypozyczone(Database& db) {
	Vector<Ksiazka_W_Obiegu>* K_W_O = db.getKsiazkiWObiegu();
	ksiazkiWypozyczone = new Vector<Ksiazka_W_Obiegu*>;
	for (Ksiazka_W_Obiegu& K : (*K_W_O))
		if (K.get_id_osoby() == get_id())
			ksiazkiWypozyczone->push(&K);
}

Czytelnik::~Czytelnik()
{
	delete ksiazkiWypozyczone;
}

Czytelnik::Czytelnik() : Uzytkownik() {}

Czytelnik::Czytelnik(string login, string haslo, string id) :Uzytkownik(login, haslo, id) {};

ostream& operator<<(ostream& out, Czytelnik& c) {
	if (&out == &cout) {
		//Wpisywanie do konsoli
		cout << "Czytelnik: " << endl;
		out << "id: " << c.get_id() << endl;
		out << "login: " << c.get_login() << endl;
	}
	else {
		//Wpisywanie do pliku
		out << endl << c.get_id() << ";" << c.get_login() << ";" << c.get_haslo() << ";";
	}
	return out;
}

istream& operator>>(istream& in, Czytelnik& c) {
	string line;
	getline(in >> ws, line);
	int i = 0;
	int id_zmiennej = 0;
	char separator(';');
	string tmp;
	while (line[i] != '\0') {
		if (line[i] != separator)
			tmp += line[i];
		else {
			switch (id_zmiennej) {
			case 0:
				c.zmien_id(tmp);
				break;
			case 1:
				c.zmien_login(tmp);
				break;
			case 2:
				c.zmien_haslo(tmp);
				break;
			}
			id_zmiennej++;
			tmp.clear();
		}
		i++;
	}
	return in;
}

void Czytelnik::powiadomOZblizajacymSieTerminie(int dni, Database& db) {
	// Pobierz bieżącą datę
	time_t now = time(nullptr);

	// Zakładamy, że Czytelnik ma listę książek, które wypożyczył
	for (Ksiazka_W_Obiegu* KW : *ksiazkiWypozyczone) {
		bool zwrot = KW->get_zwrot();

		// Sprawdź, czy książka ma ustalony okres zwrotu
		if (!zwrot) {
			int czasZakonczenia = KW->get_koniec_czasu_wyporzczenia();

			// Oblicz, ile dni pozostało do terminu zwrotu.
			int dniDoZakonczenia = (czasZakonczenia - now) / (24 * 60 * 60);

			// Sprawdź, czy do terminu zwrotu pozostało mniej niż "dni".
			if (dniDoZakonczenia <= dni) {
				//wyslijPowiadomienie("Zbliża się termin zwrotu książki: " + tytul);
				string isbn = KW->get_ISBN();
				Ksiazka* K = db.get_ksiazka_by_ISBN(isbn);
				cout << "Zbliża się termin zwrotu książki: " << K->get_tytul();
			}
		}
	}
}

void Czytelnik::wyszukajDostepneKsiazki(const string& tytul, Database& db) {
	cout << "Dostępne książki o tytule '" << tytul << "':" << endl;
	Vector<Ksiazka> dostepne_ksiazki = db.get_ksiazki_by_tytul(tytul);
	dostepne_ksiazki.print();
}

//Wypożyczamy po ISBN bo tytuł może nie być unikalny
void Czytelnik::wypozyczKsiazke(const string& ISBN, Database& db, int czas_wyporzyczenia) {
	Ksiazka* wybrana_ksiazka = db.get_ksiazka_by_ISBN(ISBN);
	// Jeśli książka istnieje i jest dostępna
	if (wybrana_ksiazka->get_tytul() != "" && wybrana_ksiazka->get_ilosc() > 0) {
		//zmniejsz jej ilość i dodaj informację o wydaniu do obiegu
		wybrana_ksiazka->zmienIlosc(wybrana_ksiazka->get_ilosc() - 1);
		db.getKsiazkiWObiegu()->push(Ksiazka_W_Obiegu(this->get_id(), wybrana_ksiazka->get_ISBN(), int(time(nullptr)), int(time(nullptr) + czas_wyporzyczenia)));
		//Synchronizacja wyporzyczonych ksiażek
		zaladuj_ksiazki_wypozyczone(db);
		cout << "Ksiazka '" << wybrana_ksiazka->get_tytul() << "' została wypozyczona." << endl;
	}
	else {
		cout << "Ksizaka nie jest dostepna." << endl;
	}
}
//Zwracamy po ISBN bo tytuł może nie być unikalny
void Czytelnik::zwrocKsiazke(const string& ISBN, Database& db) {
	for (Ksiazka_W_Obiegu* KW : *ksiazkiWypozyczone) {
		bool zwrot = KW->get_zwrot();
		// Jeśli książka należy do tego czytelnika i jest w obiegu, należy ją mu zwrócić
		if (!zwrot && KW->get_ISBN() == ISBN) {
			KW->set_zwrot(true);
			Ksiazka* wybrana_ksiazka = db.get_ksiazka_by_ISBN(ISBN);
			wybrana_ksiazka->zmienIlosc(wybrana_ksiazka->get_ilosc() + 1);
			cout << "Ksiazka '" << wybrana_ksiazka->get_tytul() << "' została zwrocona." << endl;
			return;
		}
	}
	cout << "Nie mozesz zwrocic ksiazki '" << "'." << endl;
}

void Czytelnik::wyswietlSkonczoneCzasyWypozyczen(Database& db) {
	cout << "Ksiazki o wygaslych terminach wypozyczen:" << endl;

	for (auto* ksiazkaWObiegu : *ksiazkiWypozyczone) {
		if (!ksiazkaWObiegu->get_zwrot() && ksiazkaWObiegu->get_koniec_czasu_wyporzczenia() < time(nullptr)) {
			cout << "ISBN: " << ksiazkaWObiegu->get_ISBN() << endl;
			cout << "Czas wypozyczenia: " << ksiazkaWObiegu->get_czas_wyporzczenia() << endl;
			cout << "Czas zakonczenia wypozyczenia: " << ksiazkaWObiegu->get_koniec_czasu_wyporzczenia() << endl;
			cout << endl;
		}
	}
}

void Czytelnik::wyswietlWyporzyczoneKsiazki(Database& db)
{
	for (Ksiazka_W_Obiegu* ksiazkaWObiegu : *ksiazkiWypozyczone) {
		if (!ksiazkaWObiegu->get_zwrot()) {
			cout << "ISBN: " << ksiazkaWObiegu->get_ISBN() << endl;
			cout << "Czas wypożyczenia: " << ksiazkaWObiegu->get_czas_wyporzczenia() << endl;
			cout << "Czas zakończenia wypożyczenia: " << ksiazkaWObiegu->get_koniec_czasu_wyporzczenia() << endl;
			cout << endl;
		}
	}

}
