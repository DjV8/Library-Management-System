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


void Czytelnik::powiadomOZblizajacymSieTerminie(int dni) {
	// Realizacja metody powiadamiania o zbliżającym się terminie zwrotu książki
}

void Czytelnik::wyszukajDostepneKsiazki(const string& tytul) {
	// Realizacja metody wyszukiwania dostępnych książeczek
}

void Czytelnik::wypozyczKsiazke(const string& tytul) {
	// Realizacja metody wypożyczania książek
}

void Czytelnik::zwrocKsiazke(const string& tytul) {
	// Realizacja metody zwrotu książki
}

void Czytelnik::wyswietlSkonczoneCzasyWypozyczen() {
	// Realizacja metody wyświetlania wygasłych terminów wypozyczen
}