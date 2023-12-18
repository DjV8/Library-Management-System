#include "..\Header\ksiazka_W_obiegu.h"
#include <iostream>
using namespace std;

Ksiazka_W_Obiegu::Ksiazka_W_Obiegu() : iloscKsiazek(0) {}
Ksiazka_W_Obiegu::Ksiazka_W_Obiegu(int ilosc) : iloscKsiazek(ilosc) {}



int Ksiazka_W_Obiegu::zmianaIlosci(int nowaIlosc) {
	iloscKsiazek = nowaIlosc;
	return iloscKsiazek;
}


void Ksiazka_W_Obiegu::zmienIlosc(const string& tytul, int nowaIlosc) {
	// Realizacja metody zmiany ilości książki w obiegu
	/*
	for (auto& ksiazka : ksiazki) {
		if (ksiazka.tytul == tytul) {
			ksiazka.ilosc = nowaIlosc;
			cout << "Zmieniono ilość książki '" << tytul << "' na " << nowaIlosc << endl;
			return;
		}
	}
	*/
	// Jeśli książka o podanym tytule nie zostanie znaleziona
	cout << "Książka '" << tytul << "' nie została znaleziona w obiegu." << endl;
}

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





//void Ksiazka_W_Obiegu::wypozycz() {
//    
//}
//
//void Ksiazka_W_Obiegu::zwrot() {
//    
//}

