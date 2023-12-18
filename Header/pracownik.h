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
	void dodajKsiazke(const string& tytul, int ilosc);
	void usunKsiazke(const string& tytul);
	void dodajUzytkownika(const string& imie);
	void wyswietlCzasyWypozyczen();

	void dodajKsiazke(const Ksiazka_W_Obiegu& ksiazka);
	void usunKsiazke(const Ksiazka_W_Obiegu& ksiazka);
	void dodajUzytkownika(const Czytelnik& czytelnik);
	void wyswietlSkonczoneCzasyWypozyczen();

private:
};

#endif
