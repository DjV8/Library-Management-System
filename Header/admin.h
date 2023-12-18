#pragma once
#include <string>

#include "pracownik.h"

using namespace std;

class Admin : public Pracownik {

public:
	Admin();
	Admin(string login, string haslo, string id);

	friend ostream& operator<<(ostream& out, Admin& a);
	friend istream& operator>>(istream& in, Admin& a);
};