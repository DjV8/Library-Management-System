
#include "..\Header\pracownik.h"
#include <iostream>
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


void Pracownik::dodajKsiazke(const Ksiazka_W_Obiegu& ksiazka) {
	//listaKsiazek.push_back(ksiazka);
}

void Pracownik::usunKsiazke(const Ksiazka_W_Obiegu& ksiazka) {
	// Załóżmy, że KsiazkiWObiegu mają przeciążony operator porównania do sprawdzania równości
	/*
	auto it = std::find(listaKsiazek.begin(), listaKsiazek.end(), ksiazka);
	if (it != listaKsiazek.end()) {
		listaKsiazek.erase(it);
	}
	*/
}

void Pracownik::dodajUzytkownika(const Czytelnik& czytelnik) {
	/*
	listaCzytelnikow.push_back(czytelnik);
	*/
	// Realizacja metody dodawania użytkownika

}

void Pracownik::wyswietlCzasyWypozyczen() {
	// Realizacja metody wyświetlania wygasłych terminów wypozyczen
}

void Pracownik::wyswietlSkonczoneCzasyWypozyczen() {
	/*
	for (auto& czytelnik : listaCzytelnikow) {
		czytelnik.wyswietlSkonczoneCzasyWypozyczen();
	}
	*/
}