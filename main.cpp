#include "pracownicy.h"
#include "czytelnicy.h"
#include "ksiazkiwobiegu.h"
using namespace std;
int main() {
    // Tworzenie obiektów klasy
    Pracownicy pracownicy;
    Czytelnicy czytelnicy;
    KsiazkiWObiegu ksiazkiWObiegu;

    // Przykład zastosowania metod
    pracownicy.dodajKsiazke("Wiedźmin", 10);
    pracownicy.usunKsiazke("Hobbit");
    pracownicy.dodajUzytkownika("Jan Kowalski");
    pracownicy.wyswietlCzasyWypozyczen();

    czytelnicy.powiadomOZblizajacymSieTerminie(7);
    czytelnicy.wyszukajDostepneKsiazki("Wiedźmin");
    czytelnicy.wypozyczKsiazke("Wiedźmin");
    czytelnicy.zwrocKsiazke("Wiedźmin");

    ksiazkiWObiegu.zmienIlosc("Wiedźmin", 5);
    ksiazkiWObiegu.wypozycz("Wiedźmin");
    ksiazkiWObiegu.zwroc("Wiedźmin");

    return 0;
}
