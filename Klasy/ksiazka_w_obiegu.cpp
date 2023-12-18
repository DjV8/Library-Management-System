#include "..\Header\ksiazka_W_obiegu.h"
#include <iostream>
using namespace std;

/*
void Ksiazka_W_Obiegu::zmienIlosc(Ksiazka& k, int nowaIlosc)
{
	k.zmien_ilosc(nowaIlosc);
}
*/
/*
void Ksiazka_W_Obiegu::zmienIlosc(const string& tytul, int nowaIlosc) {
	// Realizacja metody zmiany ilości książki w obiegu

	for (auto& ksiazka : ksiazki) {
		if (ksiazka.tytul == tytul) {
			ksiazka.ilosc = nowaIlosc;
			cout << "Zmieniono ilość książki '" << tytul << "' na " << nowaIlosc << endl;
			return;
		}
	}

	// Jeśli książka o podanym tytule nie zostanie znaleziona
cout << "Książka '" << tytul << "' nie została znaleziona w obiegu." << endl;
}

*/
/*
void Ksiazka_W_Obiegu::wypozycz(const string& tytul) {
	// Realizacja metody wypożyczania książek
	if (iloscKsiazek > 0) {
		cout << "Ksiazka wypozyczona. Pozostalo ksiazek w obiegu: " << --iloscKsiazek << endl;
	}
	else {
		cout << "Brak dostepnych ksiazek do wypozyczenia." << endl;
	}

}

void Ksiazka_W_Obiegu::zwroc(const string& tytul) {
	cout << "Ksiazka zwrocona. Ilosc ksiazek w obiegu: " << ++iloscKsiazek << endl;
	// Realizacja metody zwrotu książki
}

*/

ostream& operator<<(ostream& out, Ksiazka_W_Obiegu& ko) {
	if (&out == &cout) {
		//Wpisywanie do konsoli
		cout << "Ksiazka W Obiegu: " << endl;
		out << "ISBN: " << ko.ISBN << endl;
		out << "login: " << ko.koniec_czasu << endl;
		cout << "id uzytkownika: " << ko.id_osoby << endl;
	}
	else {
		//Wpisywanie do pliku
		out << endl << ko.ISBN << ";" << ko.koniec_czasu << ";" << ko.id_osoby << ";";
	}
	return out;
}

istream& operator>>(istream& in, Ksiazka_W_Obiegu& ko) {
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
				ko.ISBN;
				break;
			case 1:
				ko.koniec_czasu;
				break;
			case 2:
				ko.id_osoby;
				break;
			}
			id_zmiennej++;
			tmp.clear();
		}
		i++;
	}
	return in;
}

Ksiazka_W_Obiegu::Ksiazka_W_Obiegu() {
	this->koniec_czasu = 0;
}

Ksiazka_W_Obiegu::Ksiazka_W_Obiegu(string ISBN, int koniec_czasu, string id_osoby)
{
	this->ISBN = ISBN;
	this->koniec_czasu = koniec_czasu;
	this->id_osoby = id_osoby;
}
