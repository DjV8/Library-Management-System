
#include "..\Header\pracownik.h"
#include <iostream>
#include "..\Header\baza_danych.h"
using namespace std;

Pracownik::Pracownik() : Czytelnik() {}
Pracownik::Pracownik(string login, string haslo, string id) :Czytelnik(login, haslo, id) {};

ostream& operator<<(ostream& out, Pracownik& p) {
	if (&out == &cout) {
		//Wpisywanie do konsoli
		cout << "Pracownik: " << endl;
		out << "id: " << p.get_id() << endl;
		out << "login: " << p.get_login() << endl;
	}
	else {
		//Wpisywanie do pliku
		out << endl << p.get_id() << ";" << p.get_login() << ";" << p.get_haslo() << ";";
	}
	return out;
}

istream& operator>>(istream& in, Pracownik& p) {
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
				p.zmien_id(tmp);
				break;
			case 1:
				p.zmien_login(tmp);
				break;
			case 2:
				p.zmien_haslo(tmp);
				break;
			}
			id_zmiennej++;
			tmp.clear();
		}
		i++;
	}
	return in;
}

//==================================zmieniłem

void Pracownik::dodajKsiazke(Database& a, const Ksiazka k) {
	a.getKsiazki()->push(k);
	cout << "Ksiazka dodana do bazy danych." << endl;
}

void Pracownik::usunKsiazke(Database& a, Ksiazka k) {
	int vector_size = a.getKsiazki()->size();
	for (int i = 0; i < vector_size; i++) {
		Ksiazka ak = a.getKsiazki()->get(i);
		if (ak == k) {
			a.getKsiazki()->remove(i);
			cout << "Ksiazka usunięta z bazy danych." << endl;
			return;
		}
	}
	cout << "Ksiazka nie znaleziona w bazie danych." << endl;
}

//==================================================

void Pracownik::dodajCzytelnik(Database& a, const Czytelnik czytelnik) {
	a.getCzytelnicy()->push(czytelnik);
	// Realizacja metody dodawania czytelnika
}

//=========================================zmieniłem
void Pracownik::wyswietlSkonczoneCzasyWypozyczen(Database& a) {
	cout << "Wyświetlanie skończonych czasów wypożyczeń:" << endl;

	for (int i = 0; i < a.getKsiazkiWObiegu()->size(); ++i) {
		Ksiazka_W_Obiegu ko = a.getKsiazkiWObiegu()->get(i);

		string ISBN = ko.get_ISBN();
		int czas_wypozyczenia = ko.get_czas_wypozczenia();
		int czas_zakonczenia = ko.get_koniec_czasu_wypozczenia();

		if (czas_zakonczenia < time(nullptr)) {
			cout << "ISBN: " << ISBN << endl;
			cout << "Czas wypożyczenia: " << czas_wypozyczenia << endl;
			cout << "Czas zakończenia wypożyczenia: " << czas_zakonczenia << endl;

			cout << endl;
		}
	}
}
