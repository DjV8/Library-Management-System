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
	//void wyswietlSkonczoneCzasyWypozyczen();
	void wyswietlSkonczoneCzasyWypozyczen(Database& a);//Zmieniłem 1-5
	void zmienTytul(string nowyTytul);//1
	void zmienAutora(string nowyAutor);//2
	void zmienISBN(string nowyISBN);//3
	void zmienRokWydania(int nowyRokWydania);//4
	void zmienWydawnictwo(string noweWydawnictwo);//5

	friend ostream& operator<<(ostream& out, Pracownik& p);
	friend istream& operator>>(istream& in, Pracownik& p);

private:
};

#endif
