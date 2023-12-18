#ifndef KSIAZKIWOBIEGU_H
#define KSIAZKIWOBIEGU_H

#include <iostream>
#include <string>

#include "ksiazka.h"

using namespace std;
class Ksiazka_W_Obiegu {
public:
	/*
	void zmienIlosc(Ksiazka& k, int nowaIlosc);
	void wypozycz(Ksiazka& k, string id_osoby, int koniec_czasu);
	void zwroc(Ksiazka& k);
	*/

	Ksiazka_W_Obiegu();
	Ksiazka_W_Obiegu(string ISBN, int koniec_czasu, string id_osoby);

	friend ostream& operator<<(ostream& out, Ksiazka_W_Obiegu& ko);
	friend istream& operator>>(istream& in, Ksiazka_W_Obiegu& ko);

private:
	string ISBN;
	int koniec_czasu;
	string id_osoby;
};

#endif
