#pragma once
#include <iostream>
#include <sstream>
using namespace std;


// Se crea la clase Ciclista
class Ciclista {
private:
	int horasEntrenadas;
	double temPromedio;
public:
	// Constructor
	Ciclista(int, double);

	// Destructor
	virtual ~Ciclista();

	// Metodos get's set's y toString de la clase
	int getHorasEntrenadas();
	double getTemPromedio();

	void setHorasEntrenadas(int);
	void setTemPromedio(double);

	string toString();

};
