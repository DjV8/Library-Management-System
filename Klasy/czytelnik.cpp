#include "..\Header\czytelnik.h"
#include <iostream>
using namespace std;

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

/*
void Czytelnik::powiadomOZblizajacymSieTerminie(int dni) {
	// Realizacja metody powiadamiania o zbliżającym się terminie zwrotu książki
}
*/

void Czytelnik::powiadomOZblizajacymSieTerminie(int dni) {
    // Pobierz bieżącą datę
    time_t now = time(nullptr);

    // Zakładamy, że Czytelnik ma listę książek, które wypożyczył
    for (const auto& para : ksiazkiWypozyczone) {
        const string& tytul = para.first;
        bool zwrot = para.second;

        // Sprawdź, czy książka ma ustalony okres zwrotu
        if (!zwrot) {
            Ksiazka_W_Obiegu* ksiazkaWObiegu = znajdzKsiazkeWObiegu(tytul);  // Załóżmy, że masz w obiegu funkcję wyszukiwania książek
            if (ksiazkaWObiegu) {
                int czasZakonczenia = ksiazkaWObiegu->getCzasZakonczenia();
                
                // Oblicz, ile dni pozostało do terminu zwrotu.
                int dniDoZakonczenia = (czasZakonczenia - now) / (24 * 60 * 60);

                // Sprawdź, czy do terminu zwrotu pozostało mniej niż "dni".
                if (dniDoZakonczenia <= dni) {
                    wyslijPowiadomienie("Zbliża się termin zwrotu książki: " + tytul);
                }
            }
        }
    }
}


/*
void Czytelnik::wyszukajDostepneKsiazki(const string& tytul) {
	// Realizacja metody wyszukiwania dostępnych książeczek
}
*/
void Czytelnik::wyszukajDostepneKsiazki(const string& tytul, const Database& db) const {
    cout << "Dostępne książki o tytule '" << tytul << "':" << endl;

    for (const auto& ksiazka : db.getKsiazki()) {
        if (ksiazka.get_tytul() == tytul && ksiazka.get_ilosc() > 0) {
            cout << ksiazka << endl;
        }
    }
}


/*
void Czytelnik::wypozyczKsiazke(const string& tytul) {
	// Realizacja metody wypożyczania książek
}
*/

void Czytelnik::wypozyczKsiazke(const string& tytul, Database& db) {
    // Zakłada się, że w Bazie Danych istnieje metoda sprawdzenia dostępności książki
    if (db.sprawdzDostepnoscKsiazki(tytul)) {
        // Jeśli książka jest dostępna, zmniejsz jej ilość i dodaj informację o wydaniu do obiegu
        db.zmniejszIloscKsiazki(tytul);
        db.dodajKsiazkeWObiegu(tytul, getId());
        cout << "Książka '" << tytul << "' została wypożyczona." << endl;
    } else {
        cout << "Książka '" << tytul << "' nie jest dostępna." << endl;
    }
}


/*
void Czytelnik::zwrocKsiazke(const string& tytul) {
	// Realizacja metody zwrotu książki
}
*/

void Czytelnik::zwrocKsiazke(const string& tytul, Database& db) {

    if (db.sprawdzObecnoscKsiazki(tytul, getId())) {
        // Jeśli książka należy do tego czytelnika i jest w obiegu, należy ją mu zwrócić
        db.usunKsiazkeWObiegu(tytul);
        db.zwiekszIloscKsiazki(tytul);
        cout << "Książka '" << tytul << "' została zwrócona." << endl;
    } else {
        cout << "Nie możesz zwrócić książki '" << tytul << "'." << endl;
    }
}


/*
void Czytelnik::wyswietlSkonczoneCzasyWypozyczen() {
	// Realizacja metody wyświetlania wygasłych terminów wypozyczen
}
*/

void Czytelnik::wyswietlSkonczoneCzasyWypozyczen(Database& db) {
    vector<Ksiazka_W_Obiegu> ksiazkiWObiegu = db.getKsiazkiWObiegu();

    cout << "Książki o wygasłych terminach wypożyczeń:" << endl;

    for (const auto& ksiazkaWObiegu : ksiazkiWObiegu) {
        if (ksiazkaWObiegu.getIdOsoby() == getId() && ksiazkaWObiegu.isCzasWypozyczeniaWygasl()) {
            cout << "ISBN: " << ksiazkaWObiegu.getISBN() << endl;
            cout << "Czas wypożyczenia: " << ksiazkaWObiegu.getCzasWypozyczenia() << endl;
            cout << "Czas zakończenia wypożyczenia: " << ksiazkaWObiegu.getCzasZakonczenia() << endl;
            cout << endl;
        }
    }
}
