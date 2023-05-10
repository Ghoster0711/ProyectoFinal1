#pragma once
#include <iostream>
#include <sstream>
using namespace std;


// Se crea la clase nadador
class Nadador {
private:
	double masaMuscular;
	double peso;
	double porcGrasaCorporal;
public:
	// Constructor
	Nadador(double, double, double);

	// Destructor
	virtual ~Nadador();


	// Metodos get's set's y toString de la clase
	double getMasaMuscular();
	double getPeso();
	double getProcGrasaCorporal();

	void setMasaMuscular(double);
	void setPeso(double);
	void setProcGrasaCorporal(double);

	string toString();
};