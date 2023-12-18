
#include "..\Header\pracownik.h"
#include <iostream>
using namespace std;

void Pracownik::dodajKsiazke(const Ksiazka_W_Obiegu& ksiazka) {
	//listaKsiazek.push_back(ksiazka);
}

void Pracownik::usunKsiazke(const Ksiazka_W_Obiegu& ksiazka) {
	// Załóżmy, że KsiazkiWObiegu mają przeciążony operator porównania do sprawdzania równości
	/*
	auto it = std::find(listaKsiazek.begin(), listaKsiazek.end(), ksiazka);
	if (it != listaKsiazek.end()) {
		listaKsiazek.erase(it);
	}
	*/
}

void Pracownik::dodajUzytkownika(const Czytelnik& czytelnik) {
	/*
	listaCzytelnikow.push_back(czytelnik);
	*/
	// Realizacja metody dodawania użytkownika

}

void Pracownik::wyswietlCzasyWypozyczen() {
	// Realizacja metody wyświetlania wygasłych terminów wypozyczen
}

void Pracownik::wyswietlSkonczoneCzasyWypozyczen() {
	/*
	for (auto& czytelnik : listaCzytelnikow) {
		czytelnik.wyswietlSkonczoneCzasyWypozyczen();
	}
	*/
}