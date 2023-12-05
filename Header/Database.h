#pragma once
#include <fstream>

#include "Vector.h"

//miejce na import klas
//nazwy plików mog¹ byæ inne 
// to tylko placeholder
/*
#include "Book.h"
#include "Reader.h"
#include "BookInUse.h"
#include "Librarian.h"
#include "Admin.h"
*/

using namespace std;

class Database {
	//placeholder na wektory
	/*
	Vector<Book> books;
	Vector<Reader> readers;
	Vector<BookInUse> booksInUse;
	Vector<Liblarian> liblarians;
	Vector<admin> admins;
	*/
	template <typename T> void load(ifstream& file, Vector<T>& destination);
	template <typename T> void save(ofstream& file, Vector<T>& source);

public:
	Database() { loadAll(); }

	//placeholder na dostêp do zawartoœci wektorów
	/*
	Vector<Book> getBooks();
	Vector<Reader> getReaders();
	Vector<BookInUse> getBooksInUse();
	Vector<Liblarian> getliblarians();
	Vector<admin> getAdmins();
	*/
	void printAll();

	void loadAll();
	void saveAll();

	//funkcja u¿yta do testu
	//void addbook(Book b);
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