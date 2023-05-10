#include "Nadador.h"

// Desarrollo del constructor
Nadador::Nadador(double mas, double pes, double porc)
	: masaMuscular(mas), peso(pes), porcGrasaCorporal(porc) {}

// Desarrollo del destructor
Nadador::~Nadador() {}



// Desarrollo de lo metodos get's set's y toString
double Nadador::getMasaMuscular() { return masaMuscular; }
double Nadador::getPeso() { return peso; }
double Nadador::getProcGrasaCorporal() { return porcGrasaCorporal; }

void Nadador::setMasaMuscular(double masa) { masaMuscular = masa; }
void Nadador::setPeso(double pes) { peso = pes; }
void Nadador::setProcGrasaCorporal(double porc) { porcGrasaCorporal = porc; }

string Nadador::toString() {
	stringstream show;
	show << "| Mesa Muscular: " << masaMuscular << endl
		<< "| Peso: " << peso << endl
		<< "| Porcentaje de grasa corporal: " << porcGrasaCorporal << endl;

	return show.str();
}
