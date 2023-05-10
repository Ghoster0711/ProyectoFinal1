#include "Utiles.h"


string recibirGetline() {   //Ingreso de muchos caracteres(con espacios)
	string s;
	getline(cin, s);
	return s;
}

void ignorar() {        
	cin.ignore();
}

string convierteMes(int m) {    //Convierte el numero de mes en el nombre del mes 
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

int entradaInt() {  //Valora si el dato ingresado es de tipo int 
	int num;
	bool acceso = true;
	do {
		try {
			cin >> num;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				acceso = false;
				throw "Error: entrada no válida, la entrada debe ser un numero, vuelva a ingresar";
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

double entradaDouble() {   //Valora si el dato ingresado es de tipo double 
	double num;
	bool acceso = true;
	do {
		try {
			cin >> num;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				acceso = false;
				throw "Error: entrada no válida, la entrada debe ser un numero vuelva a ingresar";
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
 
string entradaActivoInactivo() {   //Valora si el estado ingresado es "Activo" o "Inactivo"
	string input;
	bool acceso = true;
	do {
		try {
			cin >> input;
			if (input != "Activo" || input != "Inactivo") {
				acceso = false;
				throw "Error: entrada no válida debe ser Activo o Inactivo, vuelva a ingresar";
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

char entradaSexo() {    //Valora si el sexo ingresado es 'f' o 'm'
	char input;
	bool acceso = true;
	do {
		try {
			cin >> input;
			if (input != 'f' && input != 'm') {
				acceso = false;
				throw "Error: entrada no válida debe ser f o m, vuelva a ingresar";
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

char entradaSemana() {  //Valora la letra del dia ingresado es alguno de los que estan permitidos 
	char input;
	bool acceso = true;
	do {
		try {
			cin >> input;
			if (input != 'l' && input != 'k' && input != 'm' && input != 'j' && input != 'v' && input != 's' && input != 'd') {
				acceso = false;
				throw "Error: entrada no válida debe ser l / k / m / j / v / s / d";
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



