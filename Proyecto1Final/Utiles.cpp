#include "Utiles.h"
string recibirGetline() {
	string s;
	getline(cin, s);
	return s;
}

void ignorar() {
	cin.ignore();
}

string convierteMes(int m) {
	if (m == 1) {
		return "Enero";
	}
	if (m == 2) {
		return "Febrero";
	}
	if (m == 3) {
		return "Marzo";
	}
	if (m == 4) {
		return "Abril";
	}
	if (m == 5) {
		return "Mayo";
	}
	if (m == 6) {
		return "Junio";
	}
	if (m == 7) {
		return "Julio";
	}
	if (m == 8) {
		return "Agosto";
	}
	if (m == 9) {
		return "Septiembre";
	}
	if (m == 10) {
		return "Octubre";
	}
	if (m == 11) {
		return "Noviembre";
	}
	if (m == 12) {
		return "Diciembre";
	}
	return "";
}

int entradaInt()
{
	int num;
	bool acceso = true;
	try {
		cin >> num;
		if (cin.fail()) {
			throw "Error: entrada no válida, la entrada debe ser un numero";
		}
		else
			acceso = true;

	}
	catch (const char* error) {
		cerr << error << endl;
	}
	return num;
}

double entradaDouble()
{
	double num;
	try {
		cin >> num;
		if (cin.fail()) {
			throw "Error: entrada no válida, la entrada debe ser un numero";
		}
	}
	catch (const char* error) {
		cerr << error << endl;
	}
	return num;
}

string entradaActivoInactivo()
{
	string input;
	try {
		cin >> input;
		if (input != "Activo" || input != "Inactivo") {
			throw "Error: entrada no válida debe ser Activo o Inactivo";
		}
	}
	catch (const char* error) {
		cerr << error << endl;
	}
	return input;
}

char entradaSexo()
{
	char input;
	try {
		cin >> input;
		if (input != 'f' && input != 'm') {
			throw "Error: entrada no válida debe ser f o m";
		}
	}
	catch (const char* error) {
		cerr << error << endl;
	}
	return input;
}

char entradaSemana()
{
	char input;
	try {
		cin >> input;
		if (input != 'l' && input != 'k' && input != 'm' && input != 'j' && input != 'v' && input != 's' && input != 'd') {
			throw "Error: entrada no válida debe ser f / k / m / j / v / s / d";
		}
	}
	catch (const char* error) {
		cerr << error << endl;
	}
	return input;
} 



