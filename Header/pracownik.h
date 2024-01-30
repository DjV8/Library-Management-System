//Laura Wiśniewska - dodanie metod dla książek wypożyczonych
#pragma once
#include <iostream>
#include "ksiazka.h"
#include "czytelnik.h"
#include "..\Header\ksiazka_w_obiegu.h"
using namespace std;

class Database;

class Pracownik :public Czytelnik {
public:
	Pracownik();
	Pracownik(string login, string haslo, string id);

	void wyswietlCzasyWypozyczen();
	void zmienIlosc(Ksiazka& k, int nowaIlosc);

	void dodajKsiazke(Database& a, Ksiazka k);
	void dodajwobiegu(Database& a, Ksiazka_w_obiegu o); 
	bool usunwobiegu(Database& a, Ksiazka_w_obiegu o);
	bool usunKsiazke(Database& a, Ksiazka k);
	void dodajCzytelnik(Database& a, const Czytelnik czytelnik);
	void wyswietlSkonczoneCzasyWypozyczen();

	friend ostream& operator<<(ostream& out, Pracownik& p);
	friend istream& operator>>(istream& in, Pracownik& p);

private:
};