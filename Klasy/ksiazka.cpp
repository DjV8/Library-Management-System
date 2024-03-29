#pragma once
#include "..\Header\ksiazka.h"


Ksiazka::Ksiazka() {
	this->tytul = "";
	this->autor = "";
	this->ISBN = "";
	this->rok_wydania = 0;
	this->wydawnictwo = "";
	this->ilosc = 0;
};

Ksiazka::Ksiazka(string tytul, string autor, string ISBN, int rok_wydania, string wydawnictwo, int ilosc)
{
	this->tytul = tytul;
	this->autor = autor;
	this->ISBN = ISBN;
	this->rok_wydania = rok_wydania;
	this->wydawnictwo = wydawnictwo;
	this->ilosc = ilosc;
}


//====================dodałem

void Ksiazka::zmienTytul(string nowyTytul) {
	tytul = nowyTytul;
}

void Ksiazka::zmienAutora(string nowyAutor) {
	autor = nowyAutor;
}

void Ksiazka::zmienISBN(string nowyISBN) {
	ISBN = nowyISBN;
}

void Ksiazka::zmienRokWydania(int nowyRokWydania) {
	rok_wydania = nowyRokWydania;
}

void Ksiazka::zmienWydawnictwo(string noweWydawnictwo) {
	wydawnictwo = noweWydawnictwo;
}

void Ksiazka::zmienIlosc(int nowaIlosc) {
	ilosc = nowaIlosc;
}


//=============================================

int Ksiazka::get_rok_wydania() { return ilosc; }
int Ksiazka::get_ilosc() { return ilosc; }
string Ksiazka::get_tytul() { return tytul; }
string Ksiazka::get_autor() { return autor; }
string Ksiazka::get_ISBN() { return ISBN; }
string Ksiazka::get_wydawnictwo() { return wydawnictwo; }


bool operator==(Ksiazka k1, Ksiazka k2)
{
	if (k1.get_tytul() != k2.get_tytul()) return false;
	if (k1.get_autor() != k2.get_autor()) return false;
	if (k1.get_ISBN() != k2.get_ISBN()) return false;
	if (k1.get_rok_wydania() != k2.get_rok_wydania()) return false;
	if (k1.get_wydawnictwo() != k2.get_wydawnictwo()) return false;
	return true;
}

ostream& operator<<(ostream& out, Ksiazka& b) {
	if (&out == &cout) {
		//Wpisywanie do konsoli
		out << "tytul: " << b.tytul << endl;
		out << "autor: " << b.autor << endl;
		out << "ISBN: " << b.ISBN << endl;
		out << "rok_wydania: " << b.rok_wydania << endl;
		out << "wydawnictwo: " << b.wydawnictwo << endl;
		out << "ilosc: " << b.ilosc << endl;
	}
	else {
		//Wpisywanie do pliku
		out << endl << b.tytul << ";" << b.autor << ";" << b.ISBN << ";" << b.rok_wydania << ";" << b.wydawnictwo << ";" << b.ilosc << ";";
	}
	return out;
}

istream& operator>>(istream& in, Ksiazka& b) {
	string line;
	getline(in >> ws, line);
	int i = 0;
	int id_zmiennej = 0;
	char separator(';');
	string tmp;
	while (line[i] != '\0') {
		if (line[i] != separator)
			tmp += line[i];
		else {
			switch (id_zmiennej) {
			case 0:
				b.tytul = tmp;
				break;
			case 1:
				b.autor = tmp;
				break;
			case 2:
				b.ISBN = tmp;
				break;
			case 3:
				b.rok_wydania = stoi(tmp);
				break;
			case 4:
				b.wydawnictwo = tmp;
				break;
			case 5:
				b.ilosc = stoi(tmp);
				break;
			}
			id_zmiennej++;
			tmp.clear();
		}
		i++;
	}
	return in;
}

