#pragma once
#include <fstream>

#include "Vector.h"

#include "ksiazka.h"
#include "ksiazka_W_obiegu.h"
#include "pracownik.h"
#include "czytelnik.h"
#include "admin.h"

using namespace std;

class Database {
	Vector<Czytelnik> Czytelnicy;
	Vector<Ksiazka_W_Obiegu> Ksiazki_W_Obiegu;
	Vector<Pracownik> Pracownicy;
	Vector<Ksiazka> Ksiazki;
	Vector<Admin> Admini;

	template <typename T> void load(ifstream& file, Vector<T>& destination);
	template <typename T> void save(ofstream& file, Vector<T>& source);

public:
	Database() { loadAll(); }

	Vector<Czytelnik>* getCzytelnicy();
	Vector<Ksiazka_W_Obiegu>* getKsiazkiWObiegu();
	Vector<Pracownik>* getPracownicy();
	Vector<Ksiazka>* getKsiazki();
	Vector<Admin>* getAdmins();

	Vector<Ksiazka_W_Obiegu> get_ksiazki_w_obiegy_by_ISBN(string ISBN);
	Vector<Ksiazka_W_Obiegu> get_ksiazki_w_obiegy_by_ID(string ID);

	Vector<Ksiazka> get_ksiazki_by_tytul(string tytul);
	Vector<Ksiazka> get_ksiazki_by_autor(string autor);
	Vector<Ksiazka> get_ksiazki_by_wydawnictwo(string wydawnictwo);
	Vector<Ksiazka> get_ksiazki_by_rok_wydania(int rok_wydania);
	Ksiazka* get_ksiazka_by_ISBN(string ISBN);

	void printAll();

	void loadAll();
	void saveAll();

};


template<typename T>
inline void Database::load(ifstream& file, Vector<T>& destination)
{
	T tmp = T();
	while (!file.eof()) {
		file >> tmp;
		//prawdopodobnie dodam tutaj sprawdzanie poprawnoœci obiektu tmp
		destination.push(tmp);
	}
}

template<typename T>
inline void Database::save(ofstream& file, Vector<T>& source)
{
	for (T b : source)
		//prawdopodobnie dodam tutaj sprawdzanie poprawnoœci obiektu b
		file << b;
}