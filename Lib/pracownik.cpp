//Laura Wiśniewska - dodanie funkcji obsługujących wypożyczone książki
#include "..\Header\pracownik.h"
#include <iostream>
#include "..\Header\baza_danych.h"
#include "..\Header\ksiazka.h"
#include "..\Header\ksiazka_w_obiegu.h"
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

void Pracownik::dodajKsiazke(Database& a, Ksiazka k)
{
	a.getKsiazki()->push(k);
}

bool Pracownik::usunKsiazke(Database& a, Ksiazka k) {
	int vector_size = a.getKsiazki()->size();
	for (int i = 0; i < vector_size; i++) {
		Ksiazka ak = a.getKsiazki()->get(i);
		if (ak == k) {
			a.getKsiazki()->remove(i);
			return 1;
		}
	}
}

void Pracownik::dodajwobiegu(Database& a, Ksiazka_w_obiegu o)
{
	a.getKsiazkiWObiegu()->push(o);
}
bool Pracownik::usunwobiegu(Database& a, Ksiazka_w_obiegu k) {
	int vector_size = a.getKsiazkiWObiegu()->size();
	for (int i = 0; i < vector_size; i++) {
		Ksiazka_w_obiegu ak = a.getKsiazkiWObiegu()->get(i);
		if (ak == k) {
			a.getKsiazkiWObiegu()->remove(i);
			return 1;
		}
	}
}



void Pracownik::dodajCzytelnik(Database& a, const Czytelnik czytelnik) {
	a.getCzytelnicy()->push(czytelnik);
	// Realizacja metody dodawania czytelnika
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