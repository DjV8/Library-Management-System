#ifndef KSIAZKIWOBIEGU_H
#define KSIAZKIWOBIEGU_H

#include <iostream>
#include <vector>
using namespace std;
class KsiazkiWObiegu {
public:
    void zmienIlosc(const string& tytul, int nowaIlosc);
    void wypozycz(const string& tytul);
    void zwroc(const string& tytul);

   // void zmienIlosc(const std::string& tytul, int nowaIlosc);

    KsiazkiWObiegu();
    KsiazkiWObiegu(int ilosc);
    int zmianaIlosci(int nowaIlosc);
    void wypozycz();
    void zwrot();

private:
    int iloscKsiazek;


    struct Ksiazka {
        std::string tytul;
        int ilosc;
    };

    std::vector<Ksiazka> ksiazki;
    vector<pair<string, int>> ksiazkiWObiegu;
};

#endif
