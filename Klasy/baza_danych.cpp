#include <iostream>

#include "../Header/baza_Danych.h"


Vector<Czytelnik>* Database::getCzytelnicy() { return &Czytelnicy; }

Vector<Ksiazka_W_Obiegu>* Database::getKsiazkiWObiegu() { return &Ksiazki_W_Obiegu; }

Vector<Pracownik>* Database::getPracownicy() { return &Pracownicy; }

Vector<Ksiazka>* Database::getKsiazki() { return &Ksiazki; }

Vector<Admin>* Database::getAdmins() { return &Admini; }


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
	ifstream bookFile("Data\\book.txt");
	ifstream booksInUseFile("Data\\booksInUse.txt");
	ifstream readerFile("Data\\reader.txt");
	ifstream librarianFile("Data\\librarian.txt");
	ifstream adminFile("Data\\admin.txt");


	if (readerFile.is_open() && librarianFile.is_open() && adminFile.is_open() && bookFile.is_open() && booksInUseFile.is_open()) {

		load<Ksiazka>(bookFile, Ksiazki);
		load<Ksiazka_W_Obiegu>(booksInUseFile, Ksiazki_W_Obiegu);
		load<Czytelnik>(readerFile, Czytelnicy);
		load<Pracownik>(librarianFile, Pracownicy);
		load<Admin>(adminFile, Admini);
	}
	else
		cout << "Error during file opening." << endl;


	bookFile.close();
	booksInUseFile.close();
	readerFile.close();
	librarianFile.close();
	adminFile.close();
}

void Database::saveAll()
{
	ofstream bookFile("Data\\book.txt");
	ofstream booksInUseFile("Data\\booksInUse.txt");
	ofstream readerFile("Data\\reader.txt");
	ofstream librarianFile("Data\\librarian.txt");
	ofstream adminFile("Data\\admin.txt");


	if (readerFile.is_open() && librarianFile.is_open() && adminFile.is_open() && bookFile.is_open() && booksInUseFile.is_open()) {

		save<Ksiazka>(bookFile, Ksiazki);
		save<Ksiazka_W_Obiegu>(booksInUseFile, Ksiazki_W_Obiegu);
		save<Czytelnik>(readerFile, Czytelnicy);
		save<Pracownik>(librarianFile, Pracownicy);
		save<Admin>(adminFile, Admini);
	}
	else
		cout << "Error during file opening." << endl;


	bookFile.close();
	booksInUseFile.close();
	readerFile.close();
	librarianFile.close();
	adminFile.close();
}


// tylko do testowania czy dzia³a zapis do pliku
// bêdzie usuniête w przysz³oœci
/*
void Database::addbook(Book b)
{
	books.push(b);
}
*/