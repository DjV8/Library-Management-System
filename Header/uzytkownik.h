#pragma once
#include <string>

using namespace std;

class Uzytkownik
{
public:
	Uzytkownik();
	Uzytkownik(string login, string haslo, string ID);

private:
	string login;
	string haslo;
	string ID;
};
