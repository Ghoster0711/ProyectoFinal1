#include"Expediente.h"


Expediente::Expediente() {
	ID = " ";
	tel = " ";
	nombre = " ";
	ultimoPago = NULL;
	sex = ' ';
}
Expediente::Expediente(string id, string t, string nom, Fecha* ultPa, char s) {
	ID = id;
	tel = t;
	nombre = nom;
	ultimoPago = ultPa;
	sex = s;
}
Expediente::~Expediente() {
	if (ultimoPago != NULL) {
		delete ultimoPago;
	}
}
string Expediente::getID() { return ID; }
string Expediente::getTel() { return tel; }
string Expediente::getNombre() { return nombre; }
Fecha* Expediente::getUltimoPago() { return ultimoPago; }
char Expediente::getSex() { return sex; }

void Expediente::setID(string id) { ID = id; }
void Expediente::setTel(string t) { tel = t; }
void Expediente::setNombre(string nom) { nombre = nom; }
void Expediente::setFecha(Fecha* ultPa) { ultimoPago = ultPa; }
void Expediente::setSex(char s) { sex = s; }