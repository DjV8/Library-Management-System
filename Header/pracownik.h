#ifndef PRACOWNICY_H
#define PRACOWNICY_H

#include <iostream>

#include "czytelnik.h"

using namespace std;

class Database;

class Pracownik :public Czytelnik {
public:
	Pracownik();
	Pracownik(string login, string haslo, string id);

	void wyswietlCzasyWypozyczen();
	void zmienIlosc(Ksiazka& k, int nowaIlosc);

	void dodajKsiazke(Database& a, Ksiazka k);
	void usunKsiazke(Database& a, const Ksiazka k);
	void dodajCzytelnik(Database& a, const Czytelnik czytelnik);
	void wyswietlSkonczoneCzasyWypozyczen();

	friend ostream& operator<<(ostream& out, Pracownik& p);
	friend istream& operator>>(istream& in, Pracownik& p);

private:
};

#endif
