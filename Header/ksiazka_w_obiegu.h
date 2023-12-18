#ifndef KSIAZKIWOBIEGU_H
#define KSIAZKIWOBIEGU_H

#include <iostream>
#include <vector>

#include "ksiazka.h"

using namespace std;
class Ksiazka_W_Obiegu {
public:
	void zmienIlosc(const string& tytul, int nowaIlosc);
	void wypozycz(const string& tytul);
	void zwroc(const string& tytul);

	Ksiazka_W_Obiegu();
	Ksiazka_W_Obiegu(int ilosc);
	int zmianaIlosci(int nowaIlosc);
	void wypozycz();
	void zwrot();

private:
	int iloscKsiazek;

	vector<Ksiazka> ksiazki;
	vector<pair<string, int>> ksiazkiWObiegu;
};

#endif
