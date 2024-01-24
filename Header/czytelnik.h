#ifndef CZYTELNICY_H
#define CZYTELNICY_H

#include <iostream>
#include <vector>

#include "uzytkownik.h"
using namespace std;
class Czytelnik :public Uzytkownik {
public:
	Czytelnik();
	Czytelnik(string login, string haslo, string id);

	//void powiadomOZblizajacymSieTerminie(int dni);
	void powiadomOZblizajacymSieTerminie(int dni);
	//void wyszukajDostepneKsiazki(const string& tytul);
	void wyszukajDostepneKsiazki(const string& tytul, const Database& db) const;
	//void wypozyczKsiazke(const string& tytul);
	void wypozyczKsiazke(const string& tytul, Database& db);
	//void zwrocKsiazke(const string& tytul);
	void zwrocKsiazke(const string& tytul, Database& db);
	//void wyswietlSkonczoneCzasyWypozyczen();
	void wyswietlSkonczoneCzasyWypozyczen(Database& db);

	friend ostream& operator<<(ostream& out, Czytelnik& b);
	friend istream& operator>>(istream& in, Czytelnik& b);

private:
	vector<pair<string, bool>> ksiazkiWypozyczone;
};

#endif
