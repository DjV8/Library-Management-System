//Laura Wiœniewska - G³ówny plik odpalaj¹cy program

#include "MyForm.h"
#include <string>
#include "Header\baza_danych.h"
#include "Header\ksiazka.h"
#include "Header\pracownik.h"
#include "Header\czytelnik.h"
#include "Header\ksiazka_W_obiegu.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace std;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project9::MyForm form;
	Application::Run(% form);
	Database Baza;
	Baza.printAll();
	Baza.saveAll();
	Application::Exit();
}

