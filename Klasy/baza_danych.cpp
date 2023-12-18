#include <iostream>

#include "../Header/baza_Danych.h"


Vector<Czytelnik> Database::getCzytelnicy() { return Czytelnicy; }

Vector<Ksiazka_W_Obiegu> Database::getKsiazkiWObiegu() { return Ksiazki_W_Obiegu; }

Vector<Pracownik> Database::getPracownicy() { return Pracownicy; }

Vector<Ksiazka> Database::getBooks() { return Ksiazki; }

Vector<Admin> Database::getAdmins() { return Admini; }



void Database::printAll()
{

	Ksiazki.print();
	//Ksiazki_W_Obiegu.print();
	//Czytelnicy.print();
	//Pracownicy.print();
	//Admini.print();
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
		/*
		load<BookInUse>(booksInUseFile, booksInUse);
		load<Reader>(readerFile, readers);
		load<Liblarian>(librarianFile, liblarians);
		load<admin>(adminFile, admins);
		*/
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
		/*
		save<BookInUse>(booksInUseFile, booksInUse);
		save<Reader>(readerFile, readers);
		save<Liblarian>(librarianFile, liblarians);
		save<admin>(adminFile, admins);
		*/
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