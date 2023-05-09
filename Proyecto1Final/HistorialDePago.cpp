#include "HistorialDePago.h"

HistorialDePago::HistorialDePago() {
	id = "";
	fecha = NULL;
	montoAPagar = 0;
	mesPagado = 0;
}
HistorialDePago::HistorialDePago(string Id, Fecha* fec, double monto, int m) {
	id = Id;
	fecha = fec;
	montoAPagar = monto;
	mesPagado = m;
}

HistorialDePago::~HistorialDePago() {
	if (fecha != NULL)
		delete fecha;
}

string HistorialDePago::getId() { return id; }

Fecha* HistorialDePago::getFecha() { return fecha; }

double HistorialDePago::getMontoAPagar() { return montoAPagar; }

int HistorialDePago::getMesPagado() { return mesPagado; }

string HistorialDePago::toString() {
	stringstream show;
	//  Fecha de pago               Mes pagado               Monto Cancelado
	show << " (" << fecha->getDia() << "/ " << fecha->getMes() << "/ " << fecha->getAnio() <<")" << "           "
		<< convierteMes(mesPagado) << "               " << montoAPagar << endl;

	return show.str();
}