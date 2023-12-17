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
	friend ostream& operator<<(ostream& out, Ksiazka& b);
	friend istream& operator>>(istream& in, Ksiazka& b);
};