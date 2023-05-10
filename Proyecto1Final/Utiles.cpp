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
	do {
		try {
			cin >> num;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				acceso = false;
				throw "Error: entrada no valida, la entrada debe ser un numero, vuelva a ingresar";
			}
			else
				acceso = true;

		}
		catch (const char* error) {
			cerr << error << endl;
		}
	} while (acceso != true);
	return num;
}

double entradaDouble()
{
	double num;
	bool acceso = true;
	do {
		try {
			cin >> num;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				acceso = false;
				throw "Error: entrada no valida, la entrada debe ser un numero vuelva a ingresar";
			}
			else
				acceso = true;
		}
		catch (const char* error) {
			cerr << error << endl;
		}
	} while (acceso != true);
	return num;
}

string entradaActivoInactivo()
{
	string input;
	bool acceso = true;
	do {
		try {
			cin >> input;
			if (input != "Activo" || input != "Inactivo") {
				acceso = false;
				throw "Error: entrada no valida debe ser Activo o Inactivo, vuelva a ingresar";
			}
			else
				acceso = true;
		}
		catch (const char* error) {
			cerr << error << endl;
		}
	} while (acceso != true);
	return input;
}

char entradaSexo()
{
	char input;
	bool acceso = true;
	do {
		try {
			cin >> input;
			if (input != 'f' && input != 'm') {
				acceso = false;
				throw "Error: entrada no valida debe ser f o m, vuelva a ingresar";
			}
			else
				acceso = true;
		}
		catch (const char* error) {
			cerr << error << endl;
		}
	} while (acceso != true);
	return input;
}

char entradaSemana()
{
	char input;
	bool acceso = true;
	do {
		try {
			cin >> input;
			if (input != 'l' && input != 'k' && input != 'm' && input != 'j' && input != 'v' && input != 's' && input != 'd') {
				acceso = false;
				throw "Error: entrada no valida debe ser l / k / m / j / v / s / d";
			}
			else
				acceso = true;
		}
		catch (const char* error) {
			cerr << error << endl;
		}
	} while (acceso != true);
	return input;
} 



