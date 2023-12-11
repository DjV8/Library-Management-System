#include "pracownicy.h"
#include <iostream>
using namespace std;

void Pracownicy::dodajKsiazke(const KsiazkiWObiegu& ksiazka) {
    listaKsiazek.push_back(ksiazka);
}

void Pracownicy::usunKsiazke(const KsiazkiWObiegu& ksiazka) {
    // Załóżmy, że KsiazkiWObiegu mają przeciążony operator porównania do sprawdzania równości
    auto it = std::find(listaKsiazek.begin(), listaKsiazek.end(), ksiazka);
    if (it != listaKsiazek.end()) {
        listaKsiazek.erase(it);
    }
}

void Pracownicy::dodajUzytkownika(const Czytelnicy& czytelnik) {
    listaCzytelnikow.push_back(czytelnik);
    // Realizacja metody dodawania użytkownika
}

void Pracownicy::wyswietlCzasyWypozyczen() {
    // Realizacja metody wyświetlania wygasłych terminów wypozyczen
}

void Pracownicy::wyswietlSkonczoneCzasyWypozyczen() {
    for (auto& czytelnik : listaCzytelnikow) {
        czytelnik.wyswietlSkonczoneCzasyWypozyczen();
    }
}