#ifndef CZYTELNICY_H
#define CZYTELNICY_H

#include <iostream>
#include <vector>
using namespace std;
class Czytelnik {
public:
	void powiadomOZblizajacymSieTerminie(int dni);
	void wyszukajDostepneKsiazki(const string& tytul);
	void wypozyczKsiazke(const string& tytul);
	void zwrocKsiazke(const string& tytul);
	void wyswietlSkonczoneCzasyWypozyczen();

private:
	vector<pair<string, bool>> ksiazkiWypozyczone;
};

#endif