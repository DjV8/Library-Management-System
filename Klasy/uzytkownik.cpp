#include "..\Header\uzytkownik.h"

Uzytkownik::Uzytkownik()
{
	this->login = "";
	this->haslo = "";
	this->id = "";
}

Uzytkownik::Uzytkownik(string login, string haslo, string id)
{
	this->login = login;
	this->haslo = haslo;
	this->id = id;
}

string Uzytkownik::get_login() { return login; }
string Uzytkownik::get_haslo() { return haslo; }
string Uzytkownik::get_id() { return id; }

void Uzytkownik::zmien_login(string login) { this->login = login; }
void Uzytkownik::zmien_haslo(string haslo) { this->haslo = haslo; }
void Uzytkownik::zmien_id(string id) { this->id = id; }

