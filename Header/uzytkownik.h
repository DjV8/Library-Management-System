#pragma once
#include <string>

using namespace std;

class Uzytkownik
{
	string login;
	string haslo;
	string id;
public:
	Uzytkownik();
	Uzytkownik(string login, string haslo, string id);

	string get_login();
	string get_haslo();
	string get_id();

	void zmien_login(string login);
	void zmien_haslo(string haslo);
	void zmien_id(string id);

};
