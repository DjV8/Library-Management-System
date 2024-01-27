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
	Ksiazka_W_Obiegu(string id_osoby, string ISBN, int czas_wyporzyczenia, int koniec_czasu_wyporzyczenia, bool zwrot = false);

	string get_ISBN() { return ISBN; }
	int get_koniec_czasu_wyporzczenia() { return koniec_czasu_wyporzyczenia; }
	int get_czas_wyporzczenia() { return czas_wyporzyczenia; }
	string get_id_osoby() { return id_osoby; }
	bool get_zwrot() { return zwrot; }

	void set_ISBN(string ISBN) { this->ISBN = ISBN; }
	void set_koniec_czasu_wyporzyczenia(int koniec_czasu_wyporzyczenia) { this->koniec_czasu_wyporzyczenia = koniec_czasu_wyporzyczenia; }
	void set_czas_wyporzyczenia(int czas_wyporzyczenia) { this->czas_wyporzyczenia = czas_wyporzyczenia; }
	void set_id_osoby(string id_osoby) { this->id_osoby = id_osoby; }
	void set_zwrot(bool zwrot) { this->zwrot = zwrot; }


	friend ostream& operator<<(ostream& out, Ksiazka_W_Obiegu& ko);
	friend istream& operator>>(istream& in, Ksiazka_W_Obiegu& ko);

private:
	string ISBN;
	int koniec_czasu_wyporzyczenia;
	int czas_wyporzyczenia;
	string id_osoby;
	bool zwrot;
};

#endif
