#ifndef PRACOWNICY_H
#define PRACOWNICY_H

#include <iostream>
#include <vector>
#include "ksiazkiwobiegu.h"
#include "czytelnicy.h"
using namespace std;
class Pracownicy {
public:
    void dodajKsiazke(const string& tytul, int ilosc);
    void usunKsiazke(const string& tytul);
    void dodajUzytkownika(const string& imie);
    void wyswietlCzasyWypozyczen();

    void dodajKsiazke(const KsiazkiWObiegu& ksiazka);
    void usunKsiazke(const KsiazkiWObiegu& ksiazka);
    void dodajUzytkownika(const Czytelnicy& czytelnik);
    void wyswietlSkonczoneCzasyWypozyczen();

private:
    vector<string> pracownicy;
    vector<pair<string, int>> ksiazki;
    vector<pair<string, int>> wypozyczenia;
    vector<KsiazkiWObiegu> listaKsiazek;
    vector<Czytelnicy> listaCzytelnikow;
};

#endif