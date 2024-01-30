#pragma once
///Ca³y plik Laura Wiœniewska
#include <Windows.h>
#include "Header\baza_danych.h"
#include "Header\admin.h"
#include "Header\ksiazka.h"
#include "Header\pracownik.h"
#include "Header\czytelnik.h"
#include "Header\ksiazka_w_obiegu.h"
#include "Header\uzytkownik.h"
#include <msclr/marshal_cppstd.h>  // Do konwersji typów
#include "DodajForm.h"
#include <chrono>
#include <sstream>
#include <iostream>
bool CompareStrings(std::string str1, System::String^ str2) {
	return str1 == msclr::interop::marshal_as<std::string>(str2);
};


namespace Project9 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// Podsumowanie informacji o MyForm

	public ref class MyForm : public System::Windows::Forms::Form
	{
	
	public:
		MyForm(void)
		{
			InitializeComponent();

		}
	
	System::String^ user_login;
	System::String^ user_id;
	private: System::Windows::Forms::Button^ button_usunksi¹¿kê;
	private: System::Windows::Forms::Button^ button1;
	public: System::Windows::Forms::Label^ label_Input1;
	private:
	public: System::Windows::Forms::Label^ label_Input2;
	public: System::Windows::Forms::Label^ label_Input3;
	public: System::Windows::Forms::Label^ label_Input4;
	public: System::Windows::Forms::Label^ label_Input5;

	public: System::Windows::Forms::TextBox^ textBox_Input1;
	public: System::Windows::Forms::TextBox^ textBox_Input2;
	public: System::Windows::Forms::TextBox^ textBox_Input3;
	public: System::Windows::Forms::TextBox^ textBox_Input4;
	public: System::Windows::Forms::TextBox^ textBox_Input5;

	public: System::Windows::Forms::Button^ button_wypozycz2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	public: System::Windows::Forms::Button^ button2;
	private:
	public:

	private: System::Windows::Forms::Button^ button_wyszukaj;
	public:


	protected:
	
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_Login;
	private: System::Windows::Forms::Label^ label_Haslo;
	private: System::Windows::Forms::TextBox^ textbox_Login;
	private: System::Windows::Forms::TextBox^ textbox_Haslo;
	private: System::Windows::Forms::Label^ label_Intro;
	private: System::Windows::Forms::Button^ button_Login;
	private: System::Windows::Forms::Button^ button_Rejestracja;
	private: System::Windows::Forms::Button^ button_Dodaj_admina;
	private: System::Windows::Forms::Button^ button_Dodaj_pracownika;
	private: System::Windows::Forms::Button^ button_Dodaj_czytelnika;
	private: System::Windows::Forms::Button^ button_Dodaj_ksiazke;
	private: System::Windows::Forms::Button^ button_Wypozycz_ksiazke;
	private: System::Windows::Forms::Button^ button_Moj_profil;


	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label_Login = (gcnew System::Windows::Forms::Label());
			this->label_Haslo = (gcnew System::Windows::Forms::Label());
			this->textbox_Login = (gcnew System::Windows::Forms::TextBox());
			this->textbox_Haslo = (gcnew System::Windows::Forms::TextBox());
			this->label_Intro = (gcnew System::Windows::Forms::Label());
			this->button_Login = (gcnew System::Windows::Forms::Button());
			this->button_Rejestracja = (gcnew System::Windows::Forms::Button());
			this->button_Dodaj_admina = (gcnew System::Windows::Forms::Button());
			this->button_Dodaj_pracownika = (gcnew System::Windows::Forms::Button());
			this->button_Dodaj_czytelnika = (gcnew System::Windows::Forms::Button());
			this->button_Dodaj_ksiazke = (gcnew System::Windows::Forms::Button());
			this->button_Wypozycz_ksiazke = (gcnew System::Windows::Forms::Button());
			this->button_Moj_profil = (gcnew System::Windows::Forms::Button());
			this->button_usunksi¹¿kê = (gcnew System::Windows::Forms::Button());
			this->button_wyszukaj = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label_Input1 = (gcnew System::Windows::Forms::Label());
			this->label_Input2 = (gcnew System::Windows::Forms::Label());
			this->label_Input3 = (gcnew System::Windows::Forms::Label());
			this->label_Input4 = (gcnew System::Windows::Forms::Label());
			this->label_Input5 = (gcnew System::Windows::Forms::Label());
			this->textBox_Input1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Input2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Input3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Input4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Input5 = (gcnew System::Windows::Forms::TextBox());
			this->button_wypozycz2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label_Login
			// 
			this->label_Login->AutoSize = true;
			this->label_Login->BackColor = System::Drawing::Color::Transparent;
			this->label_Login->Location = System::Drawing::Point(100, 157);
			this->label_Login->Name = L"label_Login";
			this->label_Login->Size = System::Drawing::Size(36, 13);
			this->label_Login->TabIndex = 0;
			this->label_Login->Text = L"Login:";
			this->label_Login->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// label_Haslo
			// 
			this->label_Haslo->AutoSize = true;
			this->label_Haslo->BackColor = System::Drawing::Color::Transparent;
			this->label_Haslo->Location = System::Drawing::Point(100, 210);
			this->label_Haslo->Name = L"label_Haslo";
			this->label_Haslo->Size = System::Drawing::Size(39, 13);
			this->label_Haslo->TabIndex = 1;
			this->label_Haslo->Text = L"Has³o:";
			// 
			// textbox_Login
			// 
			this->textbox_Login->Location = System::Drawing::Point(142, 154);
			this->textbox_Login->Name = L"textbox_Login";
			this->textbox_Login->Size = System::Drawing::Size(100, 20);
			this->textbox_Login->TabIndex = 2;
			this->textbox_Login->TextChanged += gcnew System::EventHandler(this, &MyForm::Login_textbox_TextChanged);
			this->textbox_Login->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::Login_textbox_KeyDown);
			// 
			// textbox_Haslo
			// 
			this->textbox_Haslo->Location = System::Drawing::Point(142, 207);
			this->textbox_Haslo->Name = L"textbox_Haslo";
			this->textbox_Haslo->Size = System::Drawing::Size(100, 20);
			this->textbox_Haslo->TabIndex = 3;
			this->textbox_Haslo->UseSystemPasswordChar = true;
			this->textbox_Haslo->TextChanged += gcnew System::EventHandler(this, &MyForm::Haslo_textbox_TextChanged);
			this->textbox_Haslo->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::Haslo_textbox_KeyDown);
			// 
			// label_Intro
			// 
			this->label_Intro->AutoSize = true;
			this->label_Intro->BackColor = System::Drawing::Color::Transparent;
			this->label_Intro->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_Intro->Location = System::Drawing::Point(83, 56);
			this->label_Intro->Name = L"label_Intro";
			this->label_Intro->Size = System::Drawing::Size(209, 20);
			this->label_Intro->TabIndex = 5;
			this->label_Intro->Text = L"Witamy w systemie Biblioteki";
			this->label_Intro->Click += gcnew System::EventHandler(this, &MyForm::label2_Click_1);
			// 
			// button_Login
			// 
			this->button_Login->Location = System::Drawing::Point(87, 278);
			this->button_Login->Name = L"button_Login";
			this->button_Login->Size = System::Drawing::Size(75, 23);
			this->button_Login->TabIndex = 6;
			this->button_Login->Text = L"Zaloguj";
			this->button_Login->UseVisualStyleBackColor = true;
			this->button_Login->Click += gcnew System::EventHandler(this, &MyForm::button_Login_Click_1);
			// 
			// button_Rejestracja
			// 
			this->button_Rejestracja->Location = System::Drawing::Point(168, 278);
			this->button_Rejestracja->Name = L"button_Rejestracja";
			this->button_Rejestracja->Size = System::Drawing::Size(75, 23);
			this->button_Rejestracja->TabIndex = 7;
			this->button_Rejestracja->Text = L"Rejestracja";
			this->button_Rejestracja->UseVisualStyleBackColor = true;
			this->button_Rejestracja->Click += gcnew System::EventHandler(this, &MyForm::Rejestracja_button_Click_1);
			// 
			// button_Dodaj_admina
			// 
			this->button_Dodaj_admina->Location = System::Drawing::Point(33, 59);
			this->button_Dodaj_admina->Name = L"button_Dodaj_admina";
			this->button_Dodaj_admina->Size = System::Drawing::Size(307, 23);
			this->button_Dodaj_admina->TabIndex = 8;
			this->button_Dodaj_admina->Text = L"Dodaj admina";
			this->button_Dodaj_admina->UseVisualStyleBackColor = true;
			this->button_Dodaj_admina->Visible = false;
			this->button_Dodaj_admina->Click += gcnew System::EventHandler(this, &MyForm::button_Dodaj_admina_Click);
			// 
			// button_Dodaj_pracownika
			// 
			this->button_Dodaj_pracownika->Location = System::Drawing::Point(33, 105);
			this->button_Dodaj_pracownika->Name = L"button_Dodaj_pracownika";
			this->button_Dodaj_pracownika->Size = System::Drawing::Size(307, 23);
			this->button_Dodaj_pracownika->TabIndex = 9;
			this->button_Dodaj_pracownika->Text = L"Dodaj pracownika";
			this->button_Dodaj_pracownika->UseVisualStyleBackColor = true;
			this->button_Dodaj_pracownika->Visible = false;
			this->button_Dodaj_pracownika->Click += gcnew System::EventHandler(this, &MyForm::button_Dodaj_pracownika_Click);
			// 
			// button_Dodaj_czytelnika
			// 
			this->button_Dodaj_czytelnika->Location = System::Drawing::Point(33, 155);
			this->button_Dodaj_czytelnika->Name = L"button_Dodaj_czytelnika";
			this->button_Dodaj_czytelnika->Size = System::Drawing::Size(307, 23);
			this->button_Dodaj_czytelnika->TabIndex = 10;
			this->button_Dodaj_czytelnika->Text = L"Dodaj czytelnika";
			this->button_Dodaj_czytelnika->UseVisualStyleBackColor = true;
			this->button_Dodaj_czytelnika->Visible = false;
			this->button_Dodaj_czytelnika->Click += gcnew System::EventHandler(this, &MyForm::button_Dodaj_czytelnika_Click);
			// 
			// button_Dodaj_ksiazke
			// 
			this->button_Dodaj_ksiazke->Location = System::Drawing::Point(33, 208);
			this->button_Dodaj_ksiazke->Name = L"button_Dodaj_ksiazke";
			this->button_Dodaj_ksiazke->Size = System::Drawing::Size(307, 23);
			this->button_Dodaj_ksiazke->TabIndex = 11;
			this->button_Dodaj_ksiazke->Text = L"Dodaj ksiazke";
			this->button_Dodaj_ksiazke->UseVisualStyleBackColor = true;
			this->button_Dodaj_ksiazke->Visible = false;
			this->button_Dodaj_ksiazke->Click += gcnew System::EventHandler(this, &MyForm::button_Dodaj_ksiazke_Click);
			// 
			// button_Wypozycz_ksiazke
			// 
			this->button_Wypozycz_ksiazke->Location = System::Drawing::Point(33, 250);
			this->button_Wypozycz_ksiazke->Name = L"button_Wypozycz_ksiazke";
			this->button_Wypozycz_ksiazke->Size = System::Drawing::Size(307, 23);
			this->button_Wypozycz_ksiazke->TabIndex = 12;
			this->button_Wypozycz_ksiazke->Text = L"Wypozycz ksiazke";
			this->button_Wypozycz_ksiazke->UseVisualStyleBackColor = true;
			this->button_Wypozycz_ksiazke->Visible = false;
			this->button_Wypozycz_ksiazke->Click += gcnew System::EventHandler(this, &MyForm::button_Wypozycz_ksiazke_Click);
			// 
			// button_Moj_profil
			// 
			this->button_Moj_profil->Location = System::Drawing::Point(33, 12);
			this->button_Moj_profil->Name = L"button_Moj_profil";
			this->button_Moj_profil->Size = System::Drawing::Size(307, 23);
			this->button_Moj_profil->TabIndex = 13;
			this->button_Moj_profil->Text = L"Moj profil";
			this->button_Moj_profil->UseVisualStyleBackColor = true;
			this->button_Moj_profil->Visible = false;
			this->button_Moj_profil->Click += gcnew System::EventHandler(this, &MyForm::button_Moj_profil_Click);
			// 
			// button_usunksi¹¿kê
			// 
			this->button_usunksi¹¿kê->Location = System::Drawing::Point(33, 289);
			this->button_usunksi¹¿kê->Name = L"button_usunksi¹¿kê";
			this->button_usunksi¹¿kê->Size = System::Drawing::Size(307, 23);
			this->button_usunksi¹¿kê->TabIndex = 14;
			this->button_usunksi¹¿kê->Text = L"Usuñ ksiazke";
			this->button_usunksi¹¿kê->UseVisualStyleBackColor = true;
			this->button_usunksi¹¿kê->Visible = false;
			this->button_usunksi¹¿kê->Click += gcnew System::EventHandler(this, &MyForm::button_usunksi¹¿kê_Click);
			// 
			// button_wyszukaj
			// 
			this->button_wyszukaj->Location = System::Drawing::Point(33, 332);
			this->button_wyszukaj->Name = L"button_wyszukaj";
			this->button_wyszukaj->Size = System::Drawing::Size(307, 23);
			this->button_wyszukaj->TabIndex = 15;
			this->button_wyszukaj->Text = L"Wyszukaj ksiazke";
			this->button_wyszukaj->UseVisualStyleBackColor = true;
			this->button_wyszukaj->Visible = false;
			this->button_wyszukaj->Click += gcnew System::EventHandler(this, &MyForm::button_wyszukaj_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(33, 361);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(307, 23);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Zwroc ksiazke";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label_Input1
			// 
			this->label_Input1->AutoSize = true;
			this->label_Input1->Location = System::Drawing::Point(79, 36);
			this->label_Input1->Name = L"label_Input1";
			this->label_Input1->Size = System::Drawing::Size(35, 13);
			this->label_Input1->TabIndex = 26;
			this->label_Input1->Text = L"Tytu³:";
			this->label_Input1->Visible = false;
			this->label_Input1->Click += gcnew System::EventHandler(this, &MyForm::label_Input1_Click);
			// 
			// label_Input2
			// 
			this->label_Input2->AutoSize = true;
			this->label_Input2->Location = System::Drawing::Point(79, 62);
			this->label_Input2->Name = L"label_Input2";
			this->label_Input2->Size = System::Drawing::Size(35, 13);
			this->label_Input2->TabIndex = 24;
			this->label_Input2->Text = L"Autor:";
			this->label_Input2->Visible = false;
			// 
			// label_Input3
			// 
			this->label_Input3->AutoSize = true;
			this->label_Input3->Location = System::Drawing::Point(79, 88);
			this->label_Input3->Name = L"label_Input3";
			this->label_Input3->Size = System::Drawing::Size(35, 13);
			this->label_Input3->TabIndex = 22;
			this->label_Input3->Text = L"ISBN:";
			this->label_Input3->Visible = false;
			// 
			// label_Input4
			// 
			this->label_Input4->AutoSize = true;
			this->label_Input4->Location = System::Drawing::Point(42, 114);
			this->label_Input4->Name = L"label_Input4";
			this->label_Input4->Size = System::Drawing::Size(72, 13);
			this->label_Input4->TabIndex = 27;
			this->label_Input4->Text = L"Rok wydania:";
			this->label_Input4->Visible = false;
			// 
			// label_Input5
			// 
			this->label_Input5->AutoSize = true;
			this->label_Input5->Location = System::Drawing::Point(37, 140);
			this->label_Input5->Name = L"label_Input5";
			this->label_Input5->Size = System::Drawing::Size(77, 13);
			this->label_Input5->TabIndex = 25;
			this->label_Input5->Text = L"Wydawnictwo:";
			this->label_Input5->Visible = false;
			// 
			// textBox_Input1
			// 
			this->textBox_Input1->Location = System::Drawing::Point(120, 33);
			this->textBox_Input1->Name = L"textBox_Input1";
			this->textBox_Input1->Size = System::Drawing::Size(152, 20);
			this->textBox_Input1->TabIndex = 17;
			this->textBox_Input1->Visible = false;
			// 
			// textBox_Input2
			// 
			this->textBox_Input2->Location = System::Drawing::Point(120, 59);
			this->textBox_Input2->Name = L"textBox_Input2";
			this->textBox_Input2->Size = System::Drawing::Size(152, 20);
			this->textBox_Input2->TabIndex = 18;
			this->textBox_Input2->Visible = false;
			// 
			// textBox_Input3
			// 
			this->textBox_Input3->Location = System::Drawing::Point(120, 85);
			this->textBox_Input3->Name = L"textBox_Input3";
			this->textBox_Input3->Size = System::Drawing::Size(152, 20);
			this->textBox_Input3->TabIndex = 19;
			this->textBox_Input3->Visible = false;
			// 
			// textBox_Input4
			// 
			this->textBox_Input4->Location = System::Drawing::Point(120, 111);
			this->textBox_Input4->Name = L"textBox_Input4";
			this->textBox_Input4->Size = System::Drawing::Size(152, 20);
			this->textBox_Input4->TabIndex = 20;
			this->textBox_Input4->Visible = false;
			// 
			// textBox_Input5
			// 
			this->textBox_Input5->Location = System::Drawing::Point(120, 137);
			this->textBox_Input5->Name = L"textBox_Input5";
			this->textBox_Input5->Size = System::Drawing::Size(152, 20);
			this->textBox_Input5->TabIndex = 21;
			this->textBox_Input5->Visible = false;
			// 
			// button_wypozycz2
			// 
			this->button_wypozycz2->Location = System::Drawing::Point(57, 220);
			this->button_wypozycz2->Name = L"button_wypozycz2";
			this->button_wypozycz2->Size = System::Drawing::Size(260, 52);
			this->button_wypozycz2->TabIndex = 29;
			this->button_wypozycz2->Text = L"Wypozycz ksiazke";
			this->button_wypozycz2->UseVisualStyleBackColor = true;
			this->button_wypozycz2->Visible = false;
			this->button_wypozycz2->Click += gcnew System::EventHandler(this, &MyForm::button_wypozycz2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(33, 181);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(307, 21);
			this->comboBox1->TabIndex = 30;
			this->comboBox1->Visible = false;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(57, 363);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(260, 52);
			this->button2->TabIndex = 31;
			this->button2->Text = L"Zwróæ ksiazke";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(378, 481);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button_wypozycz2);
			this->Controls->Add(this->label_Input1);
			this->Controls->Add(this->label_Input2);
			this->Controls->Add(this->label_Input3);
			this->Controls->Add(this->label_Input4);
			this->Controls->Add(this->label_Input5);
			this->Controls->Add(this->textBox_Input1);
			this->Controls->Add(this->textBox_Input2);
			this->Controls->Add(this->textBox_Input3);
			this->Controls->Add(this->textBox_Input4);
			this->Controls->Add(this->textBox_Input5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button_wyszukaj);
			this->Controls->Add(this->button_usunksi¹¿kê);
			this->Controls->Add(this->button_Moj_profil);
			this->Controls->Add(this->button_Wypozycz_ksiazke);
			this->Controls->Add(this->button_Dodaj_ksiazke);
			this->Controls->Add(this->button_Dodaj_czytelnika);
			this->Controls->Add(this->button_Dodaj_pracownika);
			this->Controls->Add(this->button_Dodaj_admina);
			this->Controls->Add(this->button_Rejestracja);
			this->Controls->Add(this->button_Login);
			this->Controls->Add(this->label_Intro);
			this->Controls->Add(this->textbox_Haslo);
			this->Controls->Add(this->textbox_Login);
			this->Controls->Add(this->label_Haslo);
			this->Controls->Add(this->label_Login);
			this->Name = L"MyForm";
			this->Text = L"Biblioteka";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	};
	private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		Application::Exit();
	};

		   //Login button
	private: System::Void button_Login_Click_1(System::Object^ sender, System::EventArgs^ e) {
		Database Baza;
		Vector<Admin>* Admini = Baza.getAdmins();
		Vector<Pracownik>* Pracownicy = Baza.getPracownicy();
		Vector<Czytelnik>* Czytelnicy = Baza.getCzytelnicy();
		std::string login = "";
		std::string id = "";
		for (int i = 0; i < Admini->size(); ++i)
		{
			Admin A = Baza.getAdmins()->get(i);
			std::string login = msclr::interop::marshal_as<std::string>(textbox_Login->Text);

			if (login.length() == A.get_login().length()) // Sprawdzamy d³ugoœæ ci¹gów
			{
				bool identyczne_login = true;
				for (size_t i = 0; i < login.length(); ++i)
				{
					if (login[i] != A.get_login()[i])
					{
						identyczne_login = false;
						break; // Jeœli znaki siê ró¿ni¹, przerywamy pêtlê
					}
				}
				if (identyczne_login)
				{

					std::string haslo = msclr::interop::marshal_as<std::string>(textbox_Haslo->Text);

					if (haslo.length() == A.get_haslo().length()) // Sprawdzamy d³ugoœæ ci¹gów
					{
						bool identyczne_haslo = true;
						for (size_t i = 0; i < haslo.length(); ++i)
						{
							if (haslo[i] != A.get_haslo()[i])
							{
								identyczne_haslo = false;
								break;
							}
						}
						//ZALOGOWANIE JAKO ADMIN
						if (identyczne_haslo)
						{
							user_login = gcnew System::String(A.get_login().c_str());
							user_id = gcnew System::String(A.get_id().c_str());
							Ksiazka_w_obiegu ksiazka_w_obiegu;
							Vector<Ksiazka_w_obiegu>* Ksiazki_w_obiegu = Baza.getKsiazkiWObiegu();
							/* Próba odliczania
							auto now = std::chrono::system_clock::now();
							std::time_t now_c = std::chrono::system_clock::to_time_t(now);
							std::cout << "Biezaca data i czas: " << std::ctime(&now_c) << std::endl;
							auto today = std::chrono::system_clock::now();
							auto today_time = std::chrono::system_clock::to_time_t(today);
							auto tm = *std::localtime(&today_time);

							// Pobierz dzisiejsz¹ godzinê
							System::String^ message = "Dzisiejsza godzina: " + tm.tm_hour + ":" + tm.tm_min + ":" + tm.tm_sec;
							MessageBox::Show(message, "Godzina", MessageBoxButtons::OK, MessageBoxIcon::Information);
							*/
							//Ukrycie starego menu
							button_Login->Visible = false;
							button_Rejestracja->Visible = false;
							label_Intro->Text = "";
							label_Login->Text = "";
							label_Haslo->Text = "";
							textbox_Haslo->Visible = false;
							textbox_Login->Visible = false;
							//Nowe menu
							button_Dodaj_admina->Visible = true;
							button_Dodaj_pracownika->Visible = true;
							button_Dodaj_czytelnika->Visible = true;
							button_Dodaj_ksiazke->Visible = true;
							button_Wypozycz_ksiazke->Visible = true;
							button_Moj_profil->Visible = true;
							button_usunksi¹¿kê->Visible = true;
							button_wyszukaj->Visible = true;
							button1->Visible = true;
						}
						else
						{
							MessageBox::Show("Wrong password!!!", "ERROR", MessageBoxButtons::OK);
							break;
						}
					}
					else
					{
						MessageBox::Show("Nie ma takiego konta", "ERROR", MessageBoxButtons::OK);
						break;
					}
				}

			}
			
		}
		for (int i = 0; i < Pracownicy->size(); ++i)
		{
			Pracownik P = Baza.getPracownicy()->get(i);
			std::string login = msclr::interop::marshal_as<std::string>(textbox_Login->Text);

			if (login.length() == P.get_login().length()) // Sprawdzamy d³ugoœæ ci¹gów
			{
				bool identyczne_login = true;
				for (size_t i = 0; i < login.length(); ++i)
				{
					if (login[i] != P.get_login()[i])
					{
						identyczne_login = false;
						break; // Jeœli znaki siê ró¿ni¹, przerywamy pêtlê
					}
				}
				if (identyczne_login)
				{

					std::string haslo = msclr::interop::marshal_as<std::string>(textbox_Haslo->Text);

					if (haslo.length() == P.get_haslo().length()) // Sprawdzamy d³ugoœæ ci¹gów
					{
						bool identyczne_haslo = true;
						for (size_t i = 0; i < haslo.length(); ++i)
						{
							if (haslo[i] != P.get_haslo()[i])
							{
								identyczne_haslo = false;
								break;
							}
						}
						//ZALOGOWANIE JAKO PRACOWNIK
						if (identyczne_haslo)
						{
							user_login = gcnew System::String(P.get_login().c_str());
							user_id = gcnew System::String(P.get_id().c_str());
							//Ukrycie starego menu
							button_Login->Visible = false;
							button_Rejestracja->Visible = false;
							label_Intro->Text = "";
							label_Login->Text = "";
							label_Haslo->Text = "";
							textbox_Haslo->Visible = false;
							textbox_Login->Visible = false;
							//Nowe menu
							button_Dodaj_admina->Visible = false;
							button_Dodaj_pracownika->Visible = false;
							button_Dodaj_czytelnika->Visible = true;
							button_Dodaj_ksiazke->Visible = true;
							button_Wypozycz_ksiazke->Visible = true;
							button_Moj_profil->Visible = true;
							button_usunksi¹¿kê->Visible = true;
							button_wyszukaj->Visible = true;
							button1->Visible = true;
						}
						else
						{
							MessageBox::Show("Wrong password!!!", "ERROR", MessageBoxButtons::OK);
							break;
						}
					}
					else
					{
						MessageBox::Show("Nie ma takiego konta", "ERROR", MessageBoxButtons::OK);
						break;
					}
				}

			}
		}
		for (int i = 0; i < Czytelnicy->size(); ++i)
		{
			Czytelnik C = Baza.getCzytelnicy()->get(i);
			std::string login = msclr::interop::marshal_as<std::string>(textbox_Login->Text);

			if (login.length() == C.get_login().length()) // Sprawdzamy d³ugoœæ ci¹gów
			{
				bool identyczne_login = true;
				for (size_t i = 0; i < login.length(); ++i)
				{
					if (login[i] != C.get_login()[i])
					{
						identyczne_login = false;
						break; // Jeœli znaki siê ró¿ni¹, przerywamy pêtlê
					}
				}
				if (identyczne_login)
				{

					std::string haslo = msclr::interop::marshal_as<std::string>(textbox_Haslo->Text);

					if (haslo.length() == C.get_haslo().length()) // Sprawdzamy d³ugoœæ ci¹gów
					{
						bool identyczne_haslo = true;
						for (size_t i = 0; i < haslo.length(); ++i)
						{
							if (haslo[i] != C.get_haslo()[i])
							{
								identyczne_haslo = false;
								break;
							}
						}
						//ZALOGOWANIE JAKO CZYTELNIK
						if (identyczne_haslo)
						{
							user_login = gcnew System::String(C.get_login().c_str());
							std::string User_login;
							{
								marshal_context context;
								User_login = context.marshal_as<const char*>(user_login);
							}
							user_id = gcnew System::String(C.get_id().c_str());
							//Ukrycie starego menu
							button_Login->Visible = false;
							button_Rejestracja->Visible = false;
							label_Intro->Text = "";
							label_Login->Text = "";
							label_Haslo->Text = "";
							textbox_Haslo->Visible = false;
							textbox_Login->Visible = false;
							//Nowe menu
							button_Dodaj_admina->Visible = false;
							button_Dodaj_pracownika->Visible = false;
							button_Dodaj_czytelnika->Visible = false;
							button_Dodaj_ksiazke->Visible = false;
							button_Wypozycz_ksiazke->Visible = true;
							button_Moj_profil->Visible = true;
							button_wyszukaj->Visible = true;
							button1->Visible = true;
						}
						else
						{
							MessageBox::Show("Wrong password!!!", "ERROR", MessageBoxButtons::OK);
							break;
						}
					}
					else
					{
						MessageBox::Show("Nie ma takiego konta", "ERROR", MessageBoxButtons::OK);
						break;
					}
				}

			}
		}

	}
	private: System::Void Rejestracja_button_Click_1(System::Object^ sender, System::EventArgs^ e) {
		Database Baza;
		Vector<Czytelnik>* Czytelnicy = Baza.getCzytelnicy();
		if (textbox_Login->Text != "" && textbox_Haslo->Text != "")
		{
			Czytelnik czytelnik;
			int ID_number = Czytelnicy->size() + 1;
			std::string login = msclr::interop::marshal_as<std::string>(textbox_Login->Text);
			std::string haslo = msclr::interop::marshal_as<std::string>(textbox_Haslo->Text);

			for (int i = 0; i < ID_number; ++i)
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
						textbox_Login->Clear();
						textbox_Haslo->Clear();
						break;
					}
					else {
						Czytelnik C = Baza.getCzytelnicy()->get(0);
						Admin A = Baza.getAdmins()->get(0);
						char ID_prefix = 'C';
						std::string ID;
						ID.append(1, ID_prefix);
						ID.append(std::to_string(ID_number));
						A.dodajCzytelnik(Baza, Czytelnik(login, haslo, ID));
						Baza.saveAll();
						MessageBox::Show("Czytelnik zarejestrowany pomyœlnie", "HAPPY!!!", MessageBoxButtons::OK);
						textbox_Login->Clear();
						textbox_Haslo->Clear();
						int ID_number = Czytelnicy->size() + 1;
						break;
					}
				}
			}

		}
		else {
			MessageBox::Show("Uzupe³nij wszystkie dane", "B³¹d", MessageBoxButtons::OK);
		}
	}
	private: System::Void Haslo_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Login_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
		   // TEXTBOX
		   //enter w loginie
	private: System::Void Login_textbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
		{
			textbox_Haslo->Focus();
		}
	}
		   //enter haslo
	private: System::Void Haslo_textbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
		{
			button_Login->PerformClick();
		}
	}
	private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button_Moj_profil_Click(System::Object^ sender, System::EventArgs^ e) {
		Database Baza;
		System::String^ message = "Login: " + user_login + "\nID:" + user_id;
		MessageBox::Show(message, "Mój profil <3", MessageBoxButtons::OK);
	}
	private: System::Void button_Dodaj_admina_Click(System::Object^ sender, System::EventArgs^ e) {
		Project9::DodajForm form;
		Database Baza;
		form.label_Input4->Text = "";
		form.label_Input5->Text = "";
		form.label_Input6->Text = "";
		form.textBox_Input4->Visible = false;
		form.textBox_Input5->Visible = false;
		form.textBox_Input6->Visible = false;
		form.label_Input1->Text = "ID:";
		form.label_Input2->Text = "Login:";
		form.label_Input3->Text = "Has³o:";
		form.button_Dodajczytelnika->Visible = false;
		form.button_Dodajpracownika->Visible = false;
		form.button_Dodajksiazke->Visible = false;
		form.button_Dodajadmina->Visible = true;
		form.button_usunksiazke->Visible = false;
		Vector<Admin>* Admini = Baza.getAdmins();
		int ID_number = Admini->size() + 1;
		form.textBox_Input1->Text = "A" + ID_number;
		form.textBox_Input1->Enabled = false;
		form.ShowDialog();


	}
	private: System::Void button_Dodaj_pracownika_Click(System::Object^ sender, System::EventArgs^ e) {
		Project9::DodajForm form;
		Database Baza;
		form.label_Input4->Text = "";
		form.label_Input5->Text = "";
		form.label_Input6->Text = "";
		form.textBox_Input4->Visible = false;
		form.textBox_Input5->Visible = false;
		form.textBox_Input6->Visible = false;
		form.label_Input1->Text = "ID:";
		form.label_Input2->Text = "Login:";
		form.label_Input3->Text = "Has³o:";
		form.button_Dodajczytelnika->Visible = false;
		form.button_Dodajpracownika->Visible = true;
		form.button_Dodajksiazke->Visible = false;
		form.button_Dodajadmina->Visible = false;
		form.button_usunksiazke->Visible = false;
		Vector<Pracownik>* Pracownicy = Baza.getPracownicy();
		int ID_number = Pracownicy->size() + 1;
		form.textBox_Input1->Text = "P" + ID_number;
		form.textBox_Input1->Enabled = false;
		form.ShowDialog();


	}
	private: System::Void button_Dodaj_czytelnika_Click(System::Object^ sender, System::EventArgs^ e) {
		Project9::DodajForm form;
		form.label_Input1->Text = "ID:";
		form.label_Input2->Text = "Login:";
		form.label_Input3->Text = "Has³o:";
		form.label_Input4->Text = "";
		form.label_Input5->Text = "";
		form.label_Input6->Text = "";
		form.textBox_Input4->Visible = false;
		form.textBox_Input5->Visible = false;
		form.textBox_Input6->Visible = false;
		
		form.button_Dodajczytelnika->Visible = true;
		form.button_Dodajksiazke->Visible = false;
		Database Baza;
		Vector<Czytelnik>* Czytelnicy = Baza.getCzytelnicy();
		int ID_number = Czytelnicy->size() + 1;
		form.textBox_Input1->Text = "C" + ID_number;
		form.textBox_Input1->Enabled = false;
		form.ShowDialog();

	}
	private: System::Void button_Dodaj_ksiazke_Click(System::Object^ sender, System::EventArgs^ e) {
		Project9::DodajForm form;
		
		form.button_Dodajksiazke->Visible = true;
		form.ShowDialog();
	}
	private: System::Void button_Wypozycz_ksiazke_Click(System::Object^ sender, System::EventArgs^ e) {
		this->label_Input1->Visible = true;
		this->label_Input2->Visible = true;
		this->label_Input3->Visible = true;
		this->label_Input4->Visible = true;
		this->label_Input5->Visible = true;
		this->textBox_Input1->Visible = true;
		this->textBox_Input2->Visible = true;
		this->textBox_Input3->Visible = true;
		this->textBox_Input4->Visible = true;
		this->textBox_Input5->Visible = true;
		this->button_Dodaj_admina->Visible = false;
		this->button_Dodaj_czytelnika->Visible = false;
		this->button_Dodaj_ksiazke->Visible = false;
		this->button_Moj_profil->Visible = false;
		this->button_Dodaj_pracownika->Visible = false;
		this->button_usunksi¹¿kê->Visible = false;
		this->button_Wypozycz_ksiazke->Visible = false;
		this->button_wyszukaj->Visible = false;
		this->button1->Visible = false;
		this->button_wypozycz2->Visible = true;
		
	}
		   //BUTTONYYYYYYYYYYYYYYYY

	private: System::Void button_usunksi¹¿kê_Click(System::Object^ sender, System::EventArgs^ e) {
		Project9::DodajForm form;
		form.button_usunksiazke->Visible = true;
		form.button_Dodajksiazke->Visible = false;
		form.ShowDialog();
	}
	private: System::Void button_wyszukaj_Click(System::Object^ sender, System::EventArgs^ e) {
		Project9::DodajForm form;
		form.button_wyszukaj->Visible = true;
		form.button_Dodajksiazke->Visible = false;
		form.ShowDialog();

	}
	

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->button_Dodaj_admina->Visible = false;
	this->button_Dodaj_czytelnika->Visible = false;
	this->button_Dodaj_ksiazke->Visible = false;
	this->button_Moj_profil->Visible = false;
	this->button_Dodaj_pracownika->Visible = false;
	this->button_usunksi¹¿kê->Visible = false;
	this->button_Wypozycz_ksiazke->Visible = false;
	this->button_wyszukaj->Visible = false;
	this->button1->Visible = false;
	this->button2->Visible = true;
	this->button_wypozycz2->Visible = false;
	this->comboBox1->Visible = true;
	comboBox1->Items->Clear(); // Wyczyœæ poprzedni¹ zawartoœæ
	Database Baza;
	// Pobierz ksi¹¿ki zgodne z loginem
	Vector<Ksiazka_w_obiegu>* ksiazki = Baza.getKsiazkiWObiegu();
	std::string User_login;
	{
		marshal_context context;
		User_login = context.marshal_as<const char*>(user_login);
	}
	std::string str(User_login);
	for (int i = 0; i < ksiazki->size(); ++i) {
		Ksiazka_w_obiegu KO = Baza.getKsiazkiWObiegu()->get(i);
		if (KO.get_login() == User_login) {
			String^ titleAndISBN = gcnew String(("Tytu³: " + KO.get_tytul() + " - Autor: " + KO.get_autor().c_str() +" - ISBN: " + KO.get_ISBN()).c_str());
			comboBox1->Items->Add(titleAndISBN);
		}
	}
}
private: System::Void label_Input1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_wypozycz2_Click(System::Object^ sender, System::EventArgs^ e) {
	Database Baza;
	Ksiazka ksiazka;
	Ksiazka_w_obiegu ksiazka_w_obiegu;
	Vector<Ksiazka>* ksiazki = Baza.getKsiazki();
	Pracownik P = Baza.getPracownicy()->get(0);
	Vector<Ksiazka_w_obiegu>* Ksiazki_w_obiegu = Baza.getKsiazkiWObiegu();


	for (int i = 0; i < ksiazki->size(); i++) {

		Ksiazka K = Baza.getKsiazki()->get(i);
		if (((K.get_tytul() == marshal_as<std::string>(textBox_Input1->Text)) &&
			(K.get_autor() == marshal_as<std::string>(textBox_Input2->Text)) &&
			(K.get_ISBN() == marshal_as<std::string>(textBox_Input3->Text)) &&
			(K.get_rok_wydania() == Convert::ToInt32(textBox_Input4->Text)) &&
			(K.get_wydawnictwo() == marshal_as<std::string>(textBox_Input5->Text))) || (K.get_ISBN() == marshal_as<std::string>(textBox_Input3->Text)))
		{

			std::string tytul = K.get_tytul();
			std::string autor = K.get_autor();
			std::string ISBN = K.get_ISBN();
			int rok_wydania = K.get_rok_wydania();
			std::string wydawnictwo = K.get_wydawnictwo();
			int temp2 = K.get_ilosc();
			int temp = K.get_ilosc() - 1;
			P.usunKsiazke(Baza, Ksiazka(tytul, autor, ISBN, rok_wydania, wydawnictwo, temp2));
			P.dodajKsiazke(Baza, Ksiazka(tytul, autor, ISBN, rok_wydania, wydawnictwo, temp));
			std::string User_login;
			{
				marshal_context context;
				User_login = context.marshal_as<const char*>(user_login);
			}
			std::string str(User_login);
			
			//Próba odliczania czasu

			std::chrono::seconds countdown(86400);
			auto seconds = std::chrono::duration_cast<std::chrono::seconds>(countdown).count();
			std::stringstream ss;
			ss << seconds;
			std::string data_oddania = ss.str();


			int ilosc = 1;

			P.dodajwobiegu(Baza, Ksiazka_w_obiegu(tytul, autor, ISBN, rok_wydania, wydawnictwo, ilosc, User_login, data_oddania));

			Baza.saveAll();
			MessageBox::Show("Wypozyczono pomyœlnie", "Nie B³¹d", MessageBoxButtons::OK);
			break;
		}


	}
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ selectedBook = safe_cast<String^>(comboBox1->SelectedItem);
	Database Baza; 
	System::String^ message = selectedBook;
	
	int startIndex = selectedBook->IndexOf("ISBN: ");
	std::string ISBN = "";
	// Jeœli fragment "ISBN: " zosta³ znaleziony
	if (startIndex != -1) {
		// Wyodrêbnij fragment ³añcucha, który zawiera ISBN
		String^ ISBNPart = selectedBook->Substring(startIndex + 6); // +6, aby pomin¹æ "ISBN: "
		// Twórz std::string z System::String^
		ISBN = msclr::interop::marshal_as<std::string>(ISBNPart);
	}
	
	Ksiazka ksiazka;
	Ksiazka_w_obiegu ksiazka_w_obiegu;
	Vector<Ksiazka>* ksiazki = Baza.getKsiazki();
	Vector<Ksiazka_w_obiegu>* Ksiazki_w_obiegu = Baza.getKsiazkiWObiegu();
	Pracownik P = Baza.getPracownicy()->get(0);
	if (selectedBook != nullptr) {
		for (int i = 0; i < Ksiazki_w_obiegu->size(); ++i) {
			Ksiazka_w_obiegu KO = Baza.getKsiazkiWObiegu()->get(i);
			if (ISBN == KO.get_ISBN()) {
				std::string tytul = KO.get_tytul();
				std::string autor = KO.get_autor();
				std::string ISBN = KO.get_ISBN();
				int rok_wydania = KO.get_rok_wydania();
				std::string wydawnictwo = KO.get_wydawnictwo();
				string data_oddania = KO.get_data_oddania();
				std::string User_login;
				{
					marshal_context context;
					User_login = context.marshal_as<const char*>(user_login);
				}
				std::string str(User_login);
				P.usunwobiegu(Baza, Ksiazka_w_obiegu(tytul, autor, ISBN, rok_wydania, wydawnictwo, 1, User_login, data_oddania));
				P.dodajKsiazke(Baza, Ksiazka(tytul, autor, ISBN, rok_wydania, wydawnictwo, 1));
				MessageBox::Show("Ksi¹¿ka oddana", "Udane", MessageBoxButtons::OK);
				Baza.saveAll();
				comboBox1->Items->Remove(selectedBook);
				break;
			}
		}
	}

}
};
}