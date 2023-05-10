#pragma once
#include <iostream>
#include <sstream>
using namespace std;

// Se crea la clase Fecha
class Fecha {
private:
	int dia;
	int mes;
	int anio;
public:
	// Constructor
	Fecha(int, int, int);

	// Destructor
	virtual ~Fecha();

	// Metodos get's set's y toString de la clase
	int getDia();
	int getMes();
	int getAnio();

	void setDia(int);
	void setMes(int);
	void setAnio(int);

	string toString();

};