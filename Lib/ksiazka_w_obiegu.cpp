//Laura Wiśniewska - konstruktory, próba automatycznego odliczania czasu do oddania, metody zwracające dane
#include "..\Header\ksiazka_w_obiegu.h"
#include <ctime>
#include <iostream>
#include <chrono>
#include <sstream>

Ksiazka_w_obiegu::Ksiazka_w_obiegu() {
    this->tytul = "";
    this->autor = "";
    this->ISBN = "";
    this->rok_wydania = 0;
    this->wydawnictwo = "";
    this->ilosc = 0;
    this->login = "";
    std::chrono::seconds countdown(10);
    // Konwersja duration na string
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(countdown).count();
    std::stringstream ss;
    ss << seconds;
    std::string countdown_str = ss.str();
    this->data_oddania = countdown_str;
}

Ksiazka_w_obiegu::Ksiazka_w_obiegu(std::string tytul, std::string autor, std::string ISBN, int rok_wydania, std::string wydawnictwo, int ilosc, std::string login, std::string data_oddania)
{
    this->tytul = tytul;
    this->autor = autor;
    this->ISBN = ISBN;
    this->rok_wydania = rok_wydania;
    this->wydawnictwo = wydawnictwo;
    this->ilosc = ilosc;
    this->login = login;
    this->data_oddania = data_oddania;
}

int Ksiazka_w_obiegu::get_rok_wydania() { return rok_wydania; }
int Ksiazka_w_obiegu::get_ilosc() { return ilosc; }
std::string Ksiazka_w_obiegu::get_tytul() { return tytul; }
std::string Ksiazka_w_obiegu::get_autor() { return autor; }
std::string Ksiazka_w_obiegu::get_ISBN() { return ISBN; }
std::string Ksiazka_w_obiegu::get_wydawnictwo() { return wydawnictwo; }
std::string Ksiazka_w_obiegu::get_login() { return login; }
std::string Ksiazka_w_obiegu::get_data_oddania() { return data_oddania; }

void Ksiazka_w_obiegu::zmien_ilosc(int ilosc) { this->ilosc = ilosc; }

bool operator==(Ksiazka_w_obiegu k1, Ksiazka_w_obiegu k2)
{
    if (k1.get_tytul() != k2.get_tytul()) return false;
    if (k1.get_autor() != k2.get_autor()) return false;
    if (k1.get_ISBN() != k2.get_ISBN()) return false;
    if (k1.get_rok_wydania() != k2.get_rok_wydania()) return false;
    if (k1.get_wydawnictwo() != k2.get_wydawnictwo()) return false;
    if (k1.get_data_oddania() != k2.get_data_oddania()) return false;
    return true;
}

std::ostream& operator<<(std::ostream& out, Ksiazka_w_obiegu& b) {
    if (&out == &std::cout) {
        out << "tytul: " << b.tytul << std::endl;
        out << "autor: " << b.autor << std::endl;
        out << "ISBN: " << b.ISBN << std::endl;
        out << "rok_wydania: " << b.rok_wydania << std::endl;
        out << "wydawnictwo: " << b.wydawnictwo << std::endl;
        out << "ilosc: " << b.ilosc << std::endl;
        //out << "data_oddania: " << std::asctime(std::localtime(&b.data_oddania));
    }
    else {
        out << std::endl << b.tytul << ";" << b.autor << ";" << b.ISBN << ";" << b.rok_wydania << ";" << b.wydawnictwo << ";" << b.ilosc << ";" << b.login << ";" << b.data_oddania << ";";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Ksiazka_w_obiegu& b) {
    std::string line;
    std::getline(in >> std::ws, line);
    int i = 0;
    int id_zmiennej = 0;
    char separator(';');
    std::string tmp;
    while (line[i] != '\0') {
        if (line[i] != separator)
            tmp += line[i];
        else {
            switch (id_zmiennej) {
            case 0:
                b.tytul = tmp;
                break;
            case 1:
                b.autor = tmp;
                break;
            case 2:
                b.ISBN = tmp;
                break;
            case 3:
                b.rok_wydania = std::stoi(tmp);
                break;
            case 4:
                b.wydawnictwo = tmp;
                break;
            case 5:
                b.ilosc = std::stoi(tmp);
                break;
            case 6:
                b.login = tmp;
            case 7:
                b.data_oddania = tmp;
                break;
            }
            id_zmiennej++;
            tmp.clear();
        }
        i++;
    }
    return in;
}