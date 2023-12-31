#include "..\Header\admin.h"

Admin::Admin() :Pracownik() {}
Admin::Admin(string login, string haslo, string id) :Pracownik(login, haslo, id) {}


ostream& operator<<(ostream& out, Admin& a) {
	if (&out == &cout) {
		//Wpisywanie do konsoli
		cout << "Admin: " << endl;
		out << "id: " << a.get_id() << endl;
		out << "login: " << a.get_login() << endl;
	}
	else {
		//Wpisywanie do pliku
		out << endl << a.get_id() << ";" << a.get_login() << ";" << a.get_haslo() << ";";
	}
	return out;
}

istream& operator>>(istream& in, Admin& a) {
	string line;
	getline(in >> ws, line);
	int i = 0;
	int id_zmiennej = 0;
	char separator(';');
	string tmp;
	while (line[i] != '\0') {
		if (line[i] != separator)
			tmp += line[i];
		else {
			switch (id_zmiennej) {
			case 0:
				a.zmien_id(tmp);
				break;
			case 1:
				a.zmien_login(tmp);
				break;
			case 2:
				a.zmien_haslo(tmp);
				break;
			}
			id_zmiennej++;
			tmp.clear();
		}
		i++;
	}
	return in;
}