#ifndef PRACOWNICY_H
#define PRACOWNICY_H

#include <iostream>
#include <vector>
#include "ksiazka_W_obiegu.h"
#include "czytelnik.h"
#include "uzytkownik.h"
using namespace std;

class Pracownik :public Czytelnik {
public:
	Pracownik();
	Pracownik(string login, string haslo, string id);

	void dodajKsiazke(const string& tytul, int ilosc);
	void usunKsiazke(const string& tytul);
	void dodajUzytkownika(const string& imie);
	void wyswietlCzasyWypozyczen();
	void zmienIlosc(Ksiazka& k, int nowaIlosc);

	void dodajKsiazke(const Ksiazka_W_Obiegu& ksiazka);
	void usunKsiazke(const Ksiazka_W_Obiegu& ksiazka);
	void dodajUzytkownika(const Czytelnik& czytelnik);
	void wyswietlSkonczoneCzasyWypozyczen();

	friend ostream& operator<<(ostream& out, Pracownik& p);
	friend istream& operator>>(istream& in, Pracownik& p);

private:
};

#endif
