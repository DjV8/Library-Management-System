#include "..\Header\ksiazka_W_obiegu.h"
#include <iostream>
using namespace std;


ostream& operator<<(ostream& out, Ksiazka_W_Obiegu& ko) {
	if (&out == &cout) {
		//Wpisywanie do konsoli
		out << "Ksiazka W Obiegu: " << endl;
		out << "ISBN: " << ko.ISBN << endl;
		out << "Czas Wyporzyczenia: " << ko.czas_wyporzyczenia << endl;
		out << "Koniec Czasu Wyporzyczenia: " << ko.koniec_czasu_wyporzyczenia << endl;
		out << "Zwrócona:" << ko.zwrot << endl;
		out << "id uzytkownika: " << ko.id_osoby << endl;
	}
	else {
		//Wpisywanie do pliku
		out << endl << ko.ISBN << ";" << ko.czas_wyporzyczenia << ";" << ko.koniec_czasu_wyporzyczenia << ";" << ko.id_osoby << ";" << ko.zwrot << ";";
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
				ko.set_ISBN(tmp);
				break;
			case 1:
				ko.set_czas_wyporzyczenia(stoi(tmp));
				break;
			case 2:
				ko.set_koniec_czasu_wyporzyczenia(stoi(tmp));
				break;
			case 3:
				ko.set_id_osoby(tmp);
				break;
			case 4:
				ko.set_zwrot(stoi(tmp));
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
	this->id_osoby = "";
	this->ISBN = "";
	this->koniec_czasu_wyporzyczenia = 0;
	this->czas_wyporzyczenia = 0;
	this->zwrot = false;
}


Ksiazka_W_Obiegu::Ksiazka_W_Obiegu(string id_osoby, string ISBN, int czas_wyporzyczenia, int koniec_czasu_wyporzyczenia, bool zwrot)
{
	this->id_osoby = id_osoby;
	this->ISBN = ISBN;
	this->koniec_czasu_wyporzyczenia = koniec_czasu_wyporzyczenia;
	this->czas_wyporzyczenia = czas_wyporzyczenia;
	this->zwrot = zwrot;

}
