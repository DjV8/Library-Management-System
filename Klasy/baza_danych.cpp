#include <iostream>

#include "../Header/baza_Danych.h"




Vector<Czytelnik>* Database::getCzytelnicy() { return &Czytelnicy; }

Vector<Ksiazka_W_Obiegu>* Database::getKsiazkiWObiegu() { return &Ksiazki_W_Obiegu; }

Vector<Pracownik>* Database::getPracownicy() { return &Pracownicy; }

Vector<Ksiazka>* Database::getKsiazki() { return &Ksiazki; }

Vector<Admin>* Database::getAdmins() { return &Admini; }

Vector<Ksiazka_W_Obiegu> Database::get_ksiazki_w_obiegy_by_ID(string ID) {
	Vector<Ksiazka_W_Obiegu> wynik;


	for (int i = 0; i < Ksiazki_W_Obiegu.getLen(); i++) {
		//for (Ksiazka K : Ksiazki)
		Ksiazka_W_Obiegu K = Ksiazki_W_Obiegu.get(i);
		if (K.get_id_osoby() == ID) {
			Ksiazka_W_Obiegu* wynik_tmp = &(Ksiazki_W_Obiegu[i]);
			wynik.push(*wynik_tmp);

		};
	}
	return wynik;
}

//===============================================================================
//nie sprawdza³em

Vector<Ksiazka_W_Obiegu> Database::get_ksiazki_w_obiegy_by_ISBN(string ISBN) {
	Vector<Ksiazka_W_Obiegu> output;
	for (Ksiazka_W_Obiegu k_w_o : Ksiazki_W_Obiegu) {
		if (k_w_o.get_ISBN() == ISBN)
			output.push(k_w_o);
	}
	return output;
}

Vector<Ksiazka> Database::get_ksiazki_by_tytul(string tytul)
{
	Vector<Ksiazka> dostepne_ksiazki;
	for (Ksiazka ksiazka : Ksiazki) {
		if (ksiazka.get_tytul().find(tytul) != std::string::npos)
			dostepne_ksiazki.push(ksiazka);
	}
	return dostepne_ksiazki;
}

Vector<Ksiazka> Database::get_ksiazki_by_autor(string autor)
{
	Vector<Ksiazka> dostepne_ksiazki;
	for (Ksiazka ksiazka : Ksiazki) {
		if (ksiazka.get_autor().find(autor) != std::string::npos)
			dostepne_ksiazki.push(ksiazka);
	}
	return dostepne_ksiazki;
}

Vector<Ksiazka> Database::get_ksiazki_by_wydawnictwo(string wydawnictwo)
{
	Vector<Ksiazka> dostepne_ksiazki;
	for (Ksiazka ksiazka : Ksiazki) {
		//SPrawdzenie czy ksi¹¿ka o danym tytule istneije
		if (ksiazka.get_wydawnictwo().find(wydawnictwo) != std::string::npos)
			dostepne_ksiazki.push(ksiazka);
	}
	return dostepne_ksiazki;
}

Vector<Ksiazka> Database::get_ksiazki_by_rok_wydania(int rok_wydania)
{
	Vector<Ksiazka> dostepne_ksiazki;
	for (Ksiazka ksiazka : Ksiazki) {
		//SPrawdzenie czy ksi¹¿ka o danym tytule istneije
		if (ksiazka.get_rok_wydania() == rok_wydania)
			dostepne_ksiazki.push(ksiazka);
	}
	return dostepne_ksiazki;
}

//===============================================================================

Ksiazka* Database::get_ksiazka_by_ISBN(string ISBN)
{
	Ksiazka* wynik = nullptr;
	for (int i = 0; i < Ksiazki.getLen(); i++) {
		//for (Ksiazka K : Ksiazki)
		Ksiazka K = Ksiazki.get(i);
		if (K.get_ISBN() == ISBN) {
			wynik = &(Ksiazki[i]);

		};
	}
	return wynik;
}


void Database::printAll()
{

	Ksiazki.print();
	Ksiazki_W_Obiegu.print();
	Czytelnicy.print();
	Pracownicy.print();
	Admini.print();
}

void Database::loadAll()
{
	string book_loc = "Data\\book.txt";
	string book_in_use_loc = "Data\\booksInUse.txt";
	string reader_loc = "Data\\reader.txt";
	string librarian_loc = "Data\\librarian.txt";
	string admin_loc = "Data\\admin.txt";

	load<Ksiazka>(book_loc, Ksiazki);
	load<Ksiazka_W_Obiegu>(book_in_use_loc, Ksiazki_W_Obiegu);
	load<Czytelnik>(reader_loc, Czytelnicy);
	load<Pracownik>(librarian_loc, Pracownicy);
	load<Admin>(admin_loc, Admini);

}

void Database::saveAll()
{
	string book_loc = "Data\\book.txt";
	string book_in_use_loc = "Data\\booksInUse.txt";
	string reader_loc = "Data\\reader.txt";
	string librarian_loc = "Data\\librarian.txt";
	string admin_loc = "Data\\admin.txt";

	save<Ksiazka>(book_loc, Ksiazki);
	save<Ksiazka_W_Obiegu>(book_in_use_loc, Ksiazki_W_Obiegu);
	save<Czytelnik>(reader_loc, Czytelnicy);
	save<Pracownik>(librarian_loc, Pracownicy);
	save<Admin>(admin_loc, Admini);

}
