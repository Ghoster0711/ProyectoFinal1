#include "Ciclista.h"


// Desarrollo del constructor
Ciclista::Ciclista(int horas, double tem)
	:horasEntrenadas(horas), temPromedio(tem) {}

// Desarrollo del destructor
Ciclista::~Ciclista() {}

// Desarrollo de lo metodos get's set's y toString
int Ciclista::getHorasEntrenadas() { return horasEntrenadas; }
double Ciclista::getTemPromedio() { return temPromedio; }

void Ciclista::setHorasEntrenadas(int horas) { horasEntrenadas = horas; }
void Ciclista::setTemPromedio(double tem) { temPromedio = tem; }

string Ciclista::toString() {
	stringstream show;
	show << "| Horas Entrenadas: " << horasEntrenadas << endl;
	return show.str();
}