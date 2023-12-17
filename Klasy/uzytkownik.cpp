#include "..\Header\uzytkownik.h"

Uzytkownik::Uzytkownik()
{
	this->login = "";
	this->haslo = "";
	this->ID = "";
}

Uzytkownik::Uzytkownik(string login, string haslo, string ID)
{
	this->login = login;
	this->haslo = haslo;
	this->ID = ID;
}

