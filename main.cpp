#include <string>

#include "Header\baza_danych.h"
#include "Header\ksiazka.h"
#include "Header\pracownik.h"
#include "Header\czytelnik.h"
#include "Header\ksiazka_W_obiegu.h"

using namespace std;

string get_line() {
	string tmp = "";
	do { getline(cin, tmp); } while (tmp == "" || tmp == "\n" || tmp == "\r");
	return tmp;
}

Ksiazka get_kiazka() {
	int rok_wydania;
	int ilosc;
	cout << "Tytul: ";
	string tytul = get_line();
	cout << "Autor: ";
	string autor = get_line();
	cout << "ISBN: ";
	string ISBN = get_line();
	cout << "Wydawnictwo: ";
	string wydawnictwo = get_line();
	cout << "Rok Wydania: ";
	cin >> rok_wydania;
	cout << "Ilosc: ";
	cin >> ilosc;
	return Ksiazka(tytul, autor, ISBN, rok_wydania, wydawnictwo, ilosc);
}

Czytelnik get_czytelnik() {
	string login;
	string haslo;
	string id;
	cout << "Login: ";
	cin >> login;
	cout << "Haslo: ";
	cin >> haslo;
	cout << "ID: ";
	cin >> id;
	cout << endl;
	return Czytelnik(login, haslo, id);
}

int main() {
	Database a;
	a.printAll();

	cout << "\n\nTest Test\n\n";
	cout << "\n Wczytanie Pierwszego Pracownika\n";
	Pracownik P = a.getPracownicy()->get(0);
	cout << P;
	cout << "\nDodanie Ksiazki\n";
	P.dodajKsiazke(a, get_kiazka());
	cout << "\nDodanie Czytelnika\n";
	P.dodajCzytelnik(a, get_czytelnik());

	cout << "\nUsuwanie Ksiazki" << endl;
	P.usunKsiazke(a, get_kiazka());

	a.saveAll();

	/*
	pracownik1.wyswietlCzasyWypozyczen();
	*/

	/*
	czytelnicy.powiadomOZblizajacymSieTerminie(7);
	czytelnicy.wyszukajDostepneKsiazki("Wiedźmin");
	czytelnicy.wypozyczKsiazke("Wiedźmin");
	czytelnicy.zwrocKsiazke("Wiedźmin");

	ksiazkiWObiegu.zmienIlosc("Wiedźmin", 5);
	ksiazkiWObiegu.wypozycz("Wiedźmin");
	ksiazkiWObiegu.zwroc("Wiedźmin");
	*/

	return 0;
}
