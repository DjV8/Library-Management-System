#include "ksiazkiwobiegu.h"
#include <iostream>
using namespace std;

KsiazkiWObiegu::KsiazkiWObiegu() : iloscKsiazek(0) {}  
KsiazkiWObiegu::KsiazkiWObiegu(int ilosc) : iloscKsiazek(ilosc) {}



int KsiazkiWObiegu::zmianaIlosci(int nowaIlosc) {
    iloscKsiazek = nowaIlosc;
    return iloscKsiazek;
}

void KsiazkiWObiegu::zmienIlosc(const string& tytul, int nowaIlosc) {
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

void KsiazkiWObiegu::wypozycz(const string& tytul) {
    // Realizacja metody wypożyczania książek
    if (iloscKsiazek > 0) {
        cout << "Ksiazka wypozyczona. Pozostalo ksiazek w obiegu: " << --iloscKsiazek << endl;
    }
    else {
        cout << "Brak dostepnych ksiazek do wypozyczenia." << endl;
    }

}

void KsiazkiWObiegu::zwroc(const string& tytul) {
    cout << "Ksiazka zwrocona. Ilosc ksiazek w obiegu: " << ++iloscKsiazek << endl;
    // Realizacja metody zwrotu książki
}








//void KsiazkiWObiegu::wypozycz() {
//    
//}
//
//void KsiazkiWObiegu::zwrot() {
//    
//}



