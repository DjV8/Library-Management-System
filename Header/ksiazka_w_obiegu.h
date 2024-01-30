#pragma once
#include <iostream>
#include <string>
#include <chrono> // Dodanie biblioteki <chrono>

#include "ksiazka.h"

using namespace std;
class Ksiazka_w_obiegu {
    int rok_wydania;
    int ilosc;
    string tytul;
    string autor;
    string ISBN;
    string wydawnictwo;
    string login;
    string data_oddania; // Zmiana typu na system_clock::time_point

public:
    Ksiazka_w_obiegu();
    Ksiazka_w_obiegu(string tytul, string autor, string ISBN, int rok_wydania, string wydawnictwo, int ilosc, std::string login, std::string data_oddania); // Zaktualizowany konstruktor

    void zmien_ilosc(int ilosc);

    int get_rok_wydania();
    int get_ilosc();
    string get_tytul();
    string get_autor();
    string get_ISBN();
    string get_wydawnictwo();
    string get_login();
    string get_data_oddania(); // Zaktualizowana metoda dostępu do data_oddania

    friend bool operator== (Ksiazka_w_obiegu k1, Ksiazka_w_obiegu k2);

    friend ostream& operator<<(ostream& out, Ksiazka_w_obiegu& b);
    friend istream& operator>>(istream& in, Ksiazka_w_obiegu& b);
};