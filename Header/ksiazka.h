#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ksiazka {
	int rok_wydania;
	int ilosc;
	string tytul;
	string autor;
	string ISBN;
	string wydawnictwo;

public:
	Ksiazka();
	Ksiazka(string tytul, string autor, string ISBN, int rok_wydania, string wydawnictwo, int ilosc);

	void zmien_ilosc(int ilosc);

	int get_rok_wydania();
	int get_ilosc();
	string get_tytul();
	string get_autor();
	string get_ISBN();
	string get_wydawnictwo();

	friend bool operator== (Ksiazka k1, Ksiazka k2);

	friend ostream& operator<<(ostream& out, Ksiazka& b);
	friend istream& operator>>(istream& in, Ksiazka& b);
};