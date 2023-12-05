#include <iostream>

#include "../Header/Database.h"

/*
Vector<Book> Database::getBooks() { return books; }

Vector<Reader> Database::getReaders() { return readers; }

Vector<BookInUse> Database::getBooksInUse() { return booksInUse; }

Vector<Liblarian> Database::getliblarians() { return liblarians; }

Vector<admin> Database::getAdmins() { return admins; }
*/

void Database::printAll()
{
	/*
	books.print();
	booksInUse.print();
	readers.print();
	liblarians.print();
	admins.print();*/
}

void Database::loadAll()
{
	ifstream bookFile("Data\\book.txt");
	ifstream booksInUseFile("Data\\booksInUse.txt");
	ifstream readerFile("Data\\reader.txt");
	ifstream librarianFile("Data\\librarian.txt");
	ifstream adminFile("Data\\admin.txt");


	if (readerFile.is_open() && librarianFile.is_open() && adminFile.is_open() && bookFile.is_open() && booksInUseFile.is_open()) {
		/*
		load<Book>(bookFile, books);
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
		/*
		save<Book>(bookFile, books);
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