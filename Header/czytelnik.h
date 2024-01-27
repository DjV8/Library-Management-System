#ifndef CZYTELNICY_H
#define CZYTELNICY_H
#pragma once

#include <iostream>
#include "uzytkownik.h"
#include "ksiazka_W_obiegu.h"
#include "Vector.h"


using namespace std;

class Database;

class Czytelnik :public Uzytkownik {
public:
	~Czytelnik();
	Czytelnik();
	Czytelnik(string login, string haslo, string id);

	void powiadomOZblizajacymSieTerminie(int dni, Database& db);
	void wyszukajDostepneKsiazki(const string& tytul, Database& db);
	//Domyślny czas wypożczenia : 2 tyg
	void wypozyczKsiazke(const string& ISBN, Database& db, int czas_wyporzyczenia = 2 * 7 * 24 * 60 * 60);
	void zwrocKsiazke(const string& tytul, Database& db);

	void zaladuj_ksiazki_wypozyczone(Database& db);

	void wyswietlSkonczoneCzasyWypozyczen(Database& db);
	void wyswietlWyporzyczoneKsiazki(Database& db);


	friend ostream& operator<<(ostream& out, Czytelnik& b);
	friend istream& operator>>(istream& in, Czytelnik& b);

private:
	//Wskaźnik bo miałem problemy z inicjalizacją
	Vector<Ksiazka_W_Obiegu*>* ksiazkiWypozyczone = nullptr;
};

#endif
