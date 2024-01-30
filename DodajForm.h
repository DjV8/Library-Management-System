#pragma once
///Ca³y plik Laura Wiœniewska
#include <Windows.h>
#include <iostream>
#include <chrono>
#include "Header\baza_danych.h"
#include "Header\admin.h"
#include "Header\ksiazka.h"
#include "Header\pracownik.h"
#include "Header\czytelnik.h"
#include "Header\ksiazka_w_obiegu.h"
#include "Header\uzytkownik.h"
#include <msclr/marshal_cppstd.h> // Do konwersji typów
#include "MyForm1.h"
#include "sstream"

namespace Project9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;


	public ref class DodajForm : public System::Windows::Forms::Form
	{
	
	public:
		String^ user_login;

	public:
		void SetUserLogin(String^ login) {
			user_login = login;
			MessageBox::Show("User ID: " + user_login, "Informacja", MessageBoxButtons::OK);
		}
	
	public:
		DodajForm(void)
		{
			InitializeComponent();

		}

	protected:
		~DodajForm()
		{
			if (components)
			{
				delete components;
			}
		}
		//ready for use>>
	//TEXTBOX
	public: System::Windows::Forms::TextBox^ textBox_Input1;
	public: System::Windows::Forms::TextBox^ textBox_Input2;
	public: System::Windows::Forms::TextBox^ textBox_Input3;
	public: System::Windows::Forms::TextBox^ textBox_Input4;
	public: System::Windows::Forms::TextBox^ textBox_Input5;
	public: System::Windows::Forms::TextBox^ textBox_Input6;
	//LABELS
	public: System::Windows::Forms::Label^ label_tytul;
	public: System::Windows::Forms::Label^ label_Input1;
	public: System::Windows::Forms::Label^ label_Input2;
	public: System::Windows::Forms::Label^ label_Input3;
	public: System::Windows::Forms::Label^ label_Input4;
	public: System::Windows::Forms::Label^ label_Input5;
	public: System::Windows::Forms::Label^ label_Input6;
	//BUTTONS
	public: System::Windows::Forms::Button^ button_Dodajksiazke;
	public: System::Windows::Forms::Button^ button_Dodajczytelnika;
	public: System::Windows::Forms::Button^ button_Dodajpracownika;
	public: System::Windows::Forms::Button^ button_Dodajadmina;
	public: System::Windows::Forms::Button^ button_usunksiazke;
	public: System::Windows::Forms::Button^ button_wyszukaj;
	public: System::Windows::Forms::Button^ button_Wypozycz_ksiazke;
	public: System::Windows::Forms::Button^ button1;
	private:
		System::String^ userLogin;
	public:
		property System::String^ UserLogin {
			System::String^ get() { return userLogin; }
			void set(System::String^ value) { userLogin = value; }
		}
	
	
		//ready for use<<
	private:
	
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
	
		void InitializeComponent(void)
		{
			this->textBox_Input3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Input2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Input5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Input1 = (gcnew System::Windows::Forms::TextBox());
			this->button_Dodajksiazke = (gcnew System::Windows::Forms::Button());
			this->label_Input3 = (gcnew System::Windows::Forms::Label());
			this->label_Input2 = (gcnew System::Windows::Forms::Label());
			this->label_Input5 = (gcnew System::Windows::Forms::Label());
			this->label_Input1 = (gcnew System::Windows::Forms::Label());
			this->label_tytul = (gcnew System::Windows::Forms::Label());
			this->label_Input4 = (gcnew System::Windows::Forms::Label());
			this->textBox_Input4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Input6 = (gcnew System::Windows::Forms::TextBox());
			this->label_Input6 = (gcnew System::Windows::Forms::Label());
			this->button_Dodajczytelnika = (gcnew System::Windows::Forms::Button());
			this->button_Dodajpracownika = (gcnew System::Windows::Forms::Button());
			this->button_Dodajadmina = (gcnew System::Windows::Forms::Button());
			this->button_usunksiazke = (gcnew System::Windows::Forms::Button());
			this->button_wyszukaj = (gcnew System::Windows::Forms::Button());
			this->button_Wypozycz_ksiazke = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox_Input3
			// 
			this->textBox_Input3->Location = System::Drawing::Point(90, 98);
			this->textBox_Input3->Name = L"textBox_Input3";
			this->textBox_Input3->Size = System::Drawing::Size(152, 20);
			this->textBox_Input3->TabIndex = 2;
			// 
			// textBox_Input2
			// 
			this->textBox_Input2->Location = System::Drawing::Point(90, 72);
			this->textBox_Input2->Name = L"textBox_Input2";
			this->textBox_Input2->Size = System::Drawing::Size(152, 20);
			this->textBox_Input2->TabIndex = 1;
			// 
			// textBox_Input5
			// 
			this->textBox_Input5->Location = System::Drawing::Point(90, 150);
			this->textBox_Input5->Name = L"textBox_Input5";
			this->textBox_Input5->Size = System::Drawing::Size(152, 20);
			this->textBox_Input5->TabIndex = 4;
			// 
			// textBox_Input1
			// 
			this->textBox_Input1->Location = System::Drawing::Point(90, 46);
			this->textBox_Input1->Name = L"textBox_Input1";
			this->textBox_Input1->Size = System::Drawing::Size(152, 20);
			this->textBox_Input1->TabIndex = 0;
			// 
			// button_Dodajksiazke
			// 
			this->button_Dodajksiazke->Location = System::Drawing::Point(10, 493);
			this->button_Dodajksiazke->Name = L"button_Dodajksiazke";
			this->button_Dodajksiazke->Size = System::Drawing::Size(260, 52);
			this->button_Dodajksiazke->TabIndex = 4;
			this->button_Dodajksiazke->Text = L"Dodaj Ksi¹¿kê";
			this->button_Dodajksiazke->UseVisualStyleBackColor = true;
			this->button_Dodajksiazke->Click += gcnew System::EventHandler(this, &DodajForm::button_Dodaj_Click);
			// 
			// label_Input3
			// 
			this->label_Input3->AutoSize = true;
			this->label_Input3->Location = System::Drawing::Point(49, 101);
			this->label_Input3->Name = L"label_Input3";
			this->label_Input3->Size = System::Drawing::Size(35, 13);
			this->label_Input3->TabIndex = 5;
			this->label_Input3->Text = L"ISBN:";
			// 
			// label_Input2
			// 
			this->label_Input2->AutoSize = true;
			this->label_Input2->Location = System::Drawing::Point(49, 75);
			this->label_Input2->Name = L"label_Input2";
			this->label_Input2->Size = System::Drawing::Size(35, 13);
			this->label_Input2->TabIndex = 6;
			this->label_Input2->Text = L"Autor:";
			// 
			// label_Input5
			// 
			this->label_Input5->AutoSize = true;
			this->label_Input5->Location = System::Drawing::Point(7, 153);
			this->label_Input5->Name = L"label_Input5";
			this->label_Input5->Size = System::Drawing::Size(77, 13);
			this->label_Input5->TabIndex = 7;
			this->label_Input5->Text = L"Wydawnictwo:";
			// 
			// label_Input1
			// 
			this->label_Input1->AutoSize = true;
			this->label_Input1->Location = System::Drawing::Point(49, 49);
			this->label_Input1->Name = L"label_Input1";
			this->label_Input1->Size = System::Drawing::Size(35, 13);
			this->label_Input1->TabIndex = 8;
			this->label_Input1->Text = L"Tytu³:";
			// 
			// label_tytul
			// 
			this->label_tytul->AutoSize = true;
			this->label_tytul->Location = System::Drawing::Point(87, 20);
			this->label_tytul->Name = L"label_tytul";
			this->label_tytul->Size = System::Drawing::Size(118, 13);
			this->label_tytul->TabIndex = 9;
			this->label_tytul->Text = L"PANEL STEROWANIA";
			this->label_tytul->Click += gcnew System::EventHandler(this, &DodajForm::label_tytul_Click);
			// 
			// label_Input4
			// 
			this->label_Input4->AutoSize = true;
			this->label_Input4->Location = System::Drawing::Point(12, 127);
			this->label_Input4->Name = L"label_Input4";
			this->label_Input4->Size = System::Drawing::Size(72, 13);
			this->label_Input4->TabIndex = 10;
			this->label_Input4->Text = L"Rok wydania:";
			// 
			// textBox_Input4
			// 
			this->textBox_Input4->Location = System::Drawing::Point(90, 124);
			this->textBox_Input4->Name = L"textBox_Input4";
			this->textBox_Input4->Size = System::Drawing::Size(152, 20);
			this->textBox_Input4->TabIndex = 3;
			// 
			// textBox_Input6
			// 
			this->textBox_Input6->Location = System::Drawing::Point(90, 177);
			this->textBox_Input6->Name = L"textBox_Input6";
			this->textBox_Input6->Size = System::Drawing::Size(152, 20);
			this->textBox_Input6->TabIndex = 5;
			// 
			// label_Input6
			// 
			this->label_Input6->AutoSize = true;
			this->label_Input6->Location = System::Drawing::Point(52, 180);
			this->label_Input6->Name = L"label_Input6";
			this->label_Input6->Size = System::Drawing::Size(32, 13);
			this->label_Input6->TabIndex = 12;
			this->label_Input6->Text = L"Ilosc:";
			// 
			// button_Dodajczytelnika
			// 
			this->button_Dodajczytelnika->Location = System::Drawing::Point(10, 435);
			this->button_Dodajczytelnika->Name = L"button_Dodajczytelnika";
			this->button_Dodajczytelnika->Size = System::Drawing::Size(260, 52);
			this->button_Dodajczytelnika->TabIndex = 14;
			this->button_Dodajczytelnika->Text = L"Dodaj Czytelnika";
			this->button_Dodajczytelnika->UseVisualStyleBackColor = true;
			this->button_Dodajczytelnika->Visible = false;
			this->button_Dodajczytelnika->Click += gcnew System::EventHandler(this, &DodajForm::button_Dodajczytelnika_Click);
			// 
			// button_Dodajpracownika
			// 
			this->button_Dodajpracownika->Location = System::Drawing::Point(10, 203);
			this->button_Dodajpracownika->Name = L"button_Dodajpracownika";
			this->button_Dodajpracownika->Size = System::Drawing::Size(260, 52);
			this->button_Dodajpracownika->TabIndex = 15;
			this->button_Dodajpracownika->Text = L"Dodaj Pracownika";
			this->button_Dodajpracownika->UseVisualStyleBackColor = true;
			this->button_Dodajpracownika->Visible = false;
			this->button_Dodajpracownika->Click += gcnew System::EventHandler(this, &DodajForm::button_Dodajpracownika_Click);
			// 
			// button_Dodajadmina
			// 
			this->button_Dodajadmina->Location = System::Drawing::Point(10, 551);
			this->button_Dodajadmina->Name = L"button_Dodajadmina";
			this->button_Dodajadmina->Size = System::Drawing::Size(260, 52);
			this->button_Dodajadmina->TabIndex = 16;
			this->button_Dodajadmina->Text = L"Dodaj Admina";
			this->button_Dodajadmina->UseVisualStyleBackColor = true;
			this->button_Dodajadmina->Visible = false;
			this->button_Dodajadmina->Click += gcnew System::EventHandler(this, &DodajForm::Dodajadmina_Click);
			// 
			// button_usunksiazke
			// 
			this->button_usunksiazke->Location = System::Drawing::Point(10, 377);
			this->button_usunksiazke->Name = L"button_usunksiazke";
			this->button_usunksiazke->Size = System::Drawing::Size(260, 52);
			this->button_usunksiazke->TabIndex = 17;
			this->button_usunksiazke->Text = L"Usun ksiazke";
			this->button_usunksiazke->UseVisualStyleBackColor = true;
			this->button_usunksiazke->Visible = false;
			this->button_usunksiazke->Click += gcnew System::EventHandler(this, &DodajForm::button_usunksiazke_Click);
			// 
			// button_wyszukaj
			// 
			this->button_wyszukaj->Location = System::Drawing::Point(10, 319);
			this->button_wyszukaj->Name = L"button_wyszukaj";
			this->button_wyszukaj->Size = System::Drawing::Size(260, 52);
			this->button_wyszukaj->TabIndex = 18;
			this->button_wyszukaj->Text = L"Wyszukaj ksiazke";
			this->button_wyszukaj->UseVisualStyleBackColor = true;
			this->button_wyszukaj->Visible = false;
			this->button_wyszukaj->Click += gcnew System::EventHandler(this, &DodajForm::button_wyszukaj_Click);
			// 
			// button_Wypozycz_ksiazke
			// 
			this->button_Wypozycz_ksiazke->Location = System::Drawing::Point(10, 261);
			this->button_Wypozycz_ksiazke->Name = L"button_Wypozycz_ksiazke";
			this->button_Wypozycz_ksiazke->Size = System::Drawing::Size(260, 52);
			this->button_Wypozycz_ksiazke->TabIndex = 19;
			this->button_Wypozycz_ksiazke->Text = L"Wypozycz ksiazke";
			this->button_Wypozycz_ksiazke->UseVisualStyleBackColor = true;
			this->button_Wypozycz_ksiazke->Visible = false;
			this->button_Wypozycz_ksiazke->Click += gcnew System::EventHandler(this, &DodajForm::button_Wypozycz_ksiazke_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(10, 609);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(260, 52);
			this->button1->TabIndex = 20;
			this->button1->Text = L"Zwroc ksiazke";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &DodajForm::button1_Click);
			// 
			// DodajForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 754);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button_Wypozycz_ksiazke);
			this->Controls->Add(this->button_wyszukaj);
			this->Controls->Add(this->button_usunksiazke);
			this->Controls->Add(this->label_tytul);
			this->Controls->Add(this->label_Input1);
			this->Controls->Add(this->label_Input2);
			this->Controls->Add(this->label_Input3);
			this->Controls->Add(this->label_Input4);
			this->Controls->Add(this->label_Input5);
			this->Controls->Add(this->label_Input6);
			this->Controls->Add(this->textBox_Input1);
			this->Controls->Add(this->textBox_Input2);
			this->Controls->Add(this->textBox_Input3);
			this->Controls->Add(this->textBox_Input4);
			this->Controls->Add(this->textBox_Input5);
			this->Controls->Add(this->textBox_Input6);
			this->Controls->Add(this->button_Dodajczytelnika);
			this->Controls->Add(this->button_Dodajksiazke);
			this->Controls->Add(this->button_Dodajadmina);
			this->Controls->Add(this->button_Dodajpracownika);
			this->Name = L"DodajForm";
			this->Text = L"Dodawanie";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma 

	private: System::Void button_Dodaj_Click(System::Object^ sender, System::EventArgs^ e) {
		Database Baza;
		if (textBox_Input1->Text != "" && textBox_Input2->Text != "" && textBox_Input3->Text != "" && textBox_Input4->Text != "" && textBox_Input5->Text != "")
		{

			Ksiazka ksiazka;
			std::string tytul = msclr::interop::marshal_as<std::string>(textBox_Input1->Text);
			std::string autor = msclr::interop::marshal_as<std::string>(textBox_Input2->Text);
			std::string ISBN = msclr::interop::marshal_as<std::string>(textBox_Input3->Text);
			int rok_wydania = 0;
			int ilosc = 0;
			String^ textFromTextBox1 = textBox_Input4->Text;
			std::string wydawnictwo = msclr::interop::marshal_as<std::string>(textBox_Input5->Text);
			String^ textFromTextBox2 = textBox_Input6->Text;
			int numericValue;
			if (int::TryParse(textFromTextBox1, numericValue) && int::TryParse(textFromTextBox2, numericValue))
			{
				//Jeœli numeryczna
				rok_wydania = Convert::ToInt32(textBox_Input4->Text);
				ilosc = Convert::ToInt32(textBox_Input6->Text);
			}
			else
			{
				// Jeœli nie numeryczna
				MessageBox::Show("B³¹d danych!", "ERROR", MessageBoxButtons::OK);
				textBox_Input1->Clear();
				textBox_Input2->Clear();
				textBox_Input3->Clear();
				textBox_Input4->Clear();
				textBox_Input5->Clear();
				textBox_Input6->Clear();
				return;
			}

			Pracownik P = Baza.getPracownicy()->get(0);
			P.dodajKsiazke(Baza, Ksiazka(tytul, autor, ISBN, rok_wydania, wydawnictwo, ilosc));
			Baza.saveAll();
			MessageBox::Show("Ksi¹¿ka dodana pomyœlnie", "HAPPY!!!", MessageBoxButtons::OK);
			textBox_Input1->Clear();
			textBox_Input2->Clear();
			textBox_Input3->Clear();
			textBox_Input4->Clear();
			textBox_Input5->Clear();
			textBox_Input6->Clear();
		}
		else
			MessageBox::Show("Uzupe³nij wszystkie dane", "B³¹d", MessageBoxButtons::OK);

	}

	private: System::Void Dodajadmina_Click(System::Object^ sender, System::EventArgs^ e) {
		Database Baza;
		Vector<Admin>* Admini = Baza.getAdmins();
		if (textBox_Input1->Text != "" && textBox_Input2->Text != "" && textBox_Input3->Text != "")
		{

			Admin admin;
			std::string ID = msclr::interop::marshal_as<std::string>(textBox_Input1->Text);
			std::string login = msclr::interop::marshal_as<std::string>(textBox_Input2->Text);
			std::string haslo = msclr::interop::marshal_as<std::string>(textBox_Input3->Text);

			for (int i = 0; i < Admini->size(); ++i)
			{
				bool identyczne_login = true;
				Admin A = Baza.getAdmins()->get(i);
				if (login.length() == A.get_login().length()) // Sprawdzamy d³ugoœæ ci¹gów
				{

					for (size_t i = 0; i < login.length(); ++i)
					{
						if (login[i] != A.get_login()[i])
						{
							identyczne_login = false;
							break; // Jeœli znaki siê ró¿ni¹, przerywamy pêtlê
						}
					}
					if (identyczne_login) {
						MessageBox::Show("Ju¿ istnieje takie konto", "B³¹d", MessageBoxButtons::OK);
						textBox_Input2->Clear();
						textBox_Input3->Clear();
						break;
					}
					
				}
				else {
					Admin A = Baza.getAdmins()->get(0);
					A.dodajAdmin(Baza, Admin(login, haslo, ID));
					Baza.saveAll();
					MessageBox::Show("Admin dodany pomyœlnie", "HAPPY!!!", MessageBoxButtons::OK);
					textBox_Input2->Clear();
					textBox_Input3->Clear();
					int ID_number = Admini->size() + 1;
					textBox_Input1->Text = "A" + ID_number;
					break;
				}
			}

		}

	}
	private: System::Void button_Dodajpracownika_Click(System::Object^ sender, System::EventArgs^ e) {
		Database Baza;
		Vector<Pracownik>* Pracownicy = Baza.getPracownicy();
		if (textBox_Input1->Text != "" && textBox_Input2->Text != "" && textBox_Input3->Text != "")
		{

			Pracownik pracownik;
			std::string ID = msclr::interop::marshal_as<std::string>(textBox_Input1->Text);
			std::string login = msclr::interop::marshal_as<std::string>(textBox_Input2->Text);
			std::string haslo = msclr::interop::marshal_as<std::string>(textBox_Input3->Text);

			for (int i = 0; i < Pracownicy->size(); ++i)
			{
				bool identyczne_login = true;
				Pracownik P = Baza.getPracownicy()->get(i);
				if (login.length() == P.get_login().length()) // Sprawdzamy d³ugoœæ ci¹gów
				{

					for (size_t i = 0; i < login.length(); ++i)
					{
						if (login[i] != P.get_login()[i])
						{
							identyczne_login = false;
							break; // Jeœli znaki siê ró¿ni¹, przerywamy pêtlê
						}
					}
					if (identyczne_login) {
						MessageBox::Show("Ju¿ istnieje takie konto", "B³¹d", MessageBoxButtons::OK);
						textBox_Input2->Clear();
						textBox_Input3->Clear();
						break;
					}
					
				}
				else {
					Pracownik P = Baza.getPracownicy()->get(0);
					Admin A = Baza.getAdmins()->get(0);
					A.dodajPracownik(Baza, Pracownik(login, haslo, ID));
					Baza.saveAll();
					MessageBox::Show("Pracownik dodany pomyœlnie", "HAPPY!!!", MessageBoxButtons::OK);
					textBox_Input2->Clear();
					textBox_Input3->Clear();
					int ID_number = Pracownicy->size() + 1;
					textBox_Input1->Text = "P" + ID_number;
					break;
				}
			}
		}
	}
	private: System::Void button_Dodajczytelnika_Click(System::Object^ sender, System::EventArgs^ e) {
		Database Baza;
		Vector<Czytelnik>* Czytelnicy = Baza.getCzytelnicy();
		MessageBox::Show("Im here", "B³¹d", MessageBoxButtons::OK);
		if (textBox_Input1->Text != "" && textBox_Input2->Text != "" && textBox_Input3->Text != "")
		{
			MessageBox::Show("Im here 2", "B³¹d", MessageBoxButtons::OK);
			Czytelnik czytelnik;
			std::string ID = msclr::interop::marshal_as<std::string>(textBox_Input1->Text);
			std::string login = msclr::interop::marshal_as<std::string>(textBox_Input2->Text);
			std::string haslo = msclr::interop::marshal_as<std::string>(textBox_Input3->Text);

			for (int i = 0; i < Czytelnicy->size(); ++i)
			{
				bool identyczne_login = true;
				Czytelnik C = Baza.getCzytelnicy()->get(i);
				if (login.length() == C.get_login().length()) // Sprawdzamy d³ugoœæ ci¹gów
				{

					for (size_t i = 0; i < login.length(); ++i)
					{
						if (login[i] != C.get_login()[i])
						{
							identyczne_login = false;
							break; // Jeœli znaki siê ró¿ni¹, przerywamy pêtlê
						}
					}
					if (identyczne_login) {
						MessageBox::Show("Ju¿ istnieje takie konto", "B³¹d", MessageBoxButtons::OK);
						textBox_Input2->Clear();
						textBox_Input3->Clear();
						break;
					}
					
				}
				else {
					Czytelnik C = Baza.getCzytelnicy()->get(0);
					Admin A = Baza.getAdmins()->get(0);
					A.dodajCzytelnik(Baza, Czytelnik(login, haslo, ID));
					Baza.saveAll();
					MessageBox::Show("Czytelnik dodany pomyœlnie", "HAPPY!!!", MessageBoxButtons::OK);
					textBox_Input2->Clear();
					textBox_Input3->Clear();
					int ID_number = Czytelnicy->size() + 1;
					textBox_Input1->Text = "C" + ID_number;
					break;
				}
			}

		}
	}
	private: System::Void button_usunksiazke_Click(System::Object^ sender, System::EventArgs^ e) {
		Database Baza;
		if (textBox_Input1->Text != "" && textBox_Input2->Text != "" && textBox_Input3->Text != "" && textBox_Input4->Text != "" && textBox_Input5->Text != "")
		{
			Ksiazka ksiazka;
			std::string tytul = msclr::interop::marshal_as<std::string>(textBox_Input1->Text);
			std::string autor = msclr::interop::marshal_as<std::string>(textBox_Input2->Text);
			std::string ISBN = msclr::interop::marshal_as<std::string>(textBox_Input3->Text);
			int rok_wydania = 0;
			int zmien_ilosc = 0;
			String^ textFromTextBox1 = textBox_Input4->Text;
			std::string wydawnictwo = msclr::interop::marshal_as<std::string>(textBox_Input5->Text);
			String^ textFromTextBox2 = textBox_Input6->Text;
			int numericValue;
			if (int::TryParse(textFromTextBox1, numericValue) && int::TryParse(textFromTextBox2, numericValue))
			{
				//Jeœli numeryczna
				rok_wydania = Convert::ToInt32(textBox_Input4->Text);
				zmien_ilosc = Convert::ToInt32(textBox_Input6->Text);
			}
			else
			{
				// Jeœli nie numeryczna
				MessageBox::Show("B³¹d danych!", "ERROR", MessageBoxButtons::OK);
				textBox_Input1->Clear();
				textBox_Input2->Clear();
				textBox_Input3->Clear();
				textBox_Input4->Clear();
				textBox_Input5->Clear();
				textBox_Input6->Clear();
				return;
			}
			int ilosc = 0;
			
			Vector<Ksiazka>* ksiazki = Baza.getKsiazki();


			Pracownik P = Baza.getPracownicy()->get(0);
			for (int i = 0; i < Baza.getKsiazki()->size(); ++i) {
				Ksiazka ak = Baza.getKsiazki()->get(i);
				string ISBN_szukane = ak.get_ISBN();
				if (ISBN == ISBN_szukane) {
					ilosc = ak.get_ilosc();
					Baza.saveAll();
					break;
				}

			}
			if (P.usunKsiazke(Baza, Ksiazka(tytul, autor, ISBN, rok_wydania, wydawnictwo, ilosc))) {
				Baza.saveAll();
				MessageBox::Show("Ksi¹¿ka usuniêta pomyœlnie", "HAPPY!!!", MessageBoxButtons::OK);
			}
			else {
				MessageBox::Show("Nie ma podanej ksi¹¿ki", "B³¹d", MessageBoxButtons::OK);
			}
			Baza.saveAll();
			textBox_Input1->Clear();
			textBox_Input2->Clear();
			textBox_Input3->Clear();
			textBox_Input4->Clear();
			textBox_Input5->Clear();
			textBox_Input6->Clear();

		}
		else
		{
			MessageBox::Show("Uzupe³nij wszystkie dane", "B³¹d", MessageBoxButtons::OK);
		}

	}
	private: System::Void button_wyszukaj_Click(System::Object^ sender, System::EventArgs^ e) {
		Database Baza;
		Ksiazka ksiazka;
		std::string tytul = msclr::interop::marshal_as<std::string>(textBox_Input1->Text);
		std::string autor = msclr::interop::marshal_as<std::string>(textBox_Input2->Text);
		std::string ISBN = msclr::interop::marshal_as<std::string>(textBox_Input3->Text);
		std::string wydawnictwo = msclr::interop::marshal_as<std::string>(textBox_Input5->Text);
		int rok_wydania = 0;
		int zmien_ilosc = 0;
		String^ textFromTextBox1 = textBox_Input4->Text;
		String^ textFromTextBox2 = textBox_Input6->Text;
		int numericValue;
		if (int::TryParse(textFromTextBox1, numericValue))
		{
			//Jeœli numeryczna
			rok_wydania = Convert::ToInt32(textBox_Input4->Text);
		}
		else
		{
			if (textFromTextBox1 == "" )
			{
				rok_wydania = 0;
			}
			else
			{
				// Jeœli nie numeryczna
				MessageBox::Show("B³¹d danych!", "ERROR", MessageBoxButtons::OK);
				textBox_Input1->Clear();
				textBox_Input2->Clear();
				textBox_Input3->Clear();
				textBox_Input4->Clear();
				textBox_Input5->Clear();
				textBox_Input6->Clear();
				return;
			}
			
		}
		Pracownik P = Baza.getPracownicy()->get(0);
		Vector<Ksiazka>* ksiazki = Baza.getKsiazki();
		Vector<Ksiazka>* foundBooks = new Vector<Ksiazka>();
		std::string message = "Znalezione ksi¹¿ki:\n\n";
		
		//Admin A = Baza.getAdmins()->get(i);

		for (int i = 0; i < ksiazki->size(); i++) {
			Ksiazka K = Baza.getKsiazki()->get(i);
			if ((textBox_Input1->Text == "" || K.get_tytul() == marshal_as<std::string>(textBox_Input1->Text)) &&
				(textBox_Input2->Text == "" || K.get_autor() == marshal_as<std::string>(textBox_Input2->Text)) &&
				(textBox_Input3->Text == "" || K.get_ISBN() == marshal_as<std::string>(textBox_Input3->Text)) &&
				(textBox_Input4->Text == "" || K.get_rok_wydania()== Convert::ToInt32(textBox_Input4->Text)) &&
				(textBox_Input5->Text == "" || K.get_wydawnictwo() == marshal_as<std::string>(textBox_Input5->Text)))
			{
				// Jeœli spe³niony jest warunek, dodaj ksi¹¿kê do wektora foundBooks
				foundBooks->push(K);
			}
		}
		
		// Tworzymy now¹ DataTable
		DataTable^ table = gcnew DataTable();

		// Dodajemy kolumny do DataTable
		table->Columns->Add("Tytul");
		table->Columns->Add("Autor");
		table->Columns->Add("ISBN");
		table->Columns->Add("Rok Wydania");
		table->Columns->Add("Wydawnictwo");

		// Wype³niamy DataTable danymi z wektora foundBooks
		for (int i = 0; i < foundBooks->size(); i++) {
			Ksiazka K = foundBooks->get(i);
			DataRow^ row = table->NewRow();
			row["Tytul"] = gcnew String(K.get_tytul().c_str());
			row["Autor"] = gcnew String(K.get_autor().c_str());
			row["ISBN"] = gcnew String(K.get_ISBN().c_str());
			row["Rok Wydania"] = K.get_rok_wydania();
			row["Wydawnictwo"] = gcnew String(K.get_wydawnictwo().c_str());
			table->Rows->Add(row);
		}

		// Tworzymy instancjê formularza MyForm1 i przekazujemy do niego DataTable
		MyForm1^ form1 = gcnew MyForm1(table);
		// Wyœwietlamy formularz
		form1->Show();
		MessageBox::Show(gcnew String(message.c_str()), "Znalezione Ksi¹¿ki", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}

public: System::Void button_Wypozycz_ksiazke_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label_tytul_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
