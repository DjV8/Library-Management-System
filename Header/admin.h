#pragma once
#include <string>

#include "pracownik.h"

using namespace std;

class Admin : public Pracownik {

public:
	Admin();
	Admin(string login, string haslo, string id);
	void dodajAdmin(Database& a, const Admin admin);
	void dodajPracownik(Database& a, const Pracownik pracownik);
	void dodajCzytelnik(Database& a, const Czytelnik czytelnik);
	friend ostream& operator<<(ostream& out, Admin& a);
	friend istream& operator>>(istream& in, Admin& a);
};