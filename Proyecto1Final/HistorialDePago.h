#pragma once
#include "Fecha.h"
#include "Triatlonista.h"
#include"Utiles.h"

class HistorialDePago {
private:
	string id;
	Fecha* fecha;
	double montoAPagar;
	int mesPagado;
public:
	HistorialDePago();
	HistorialDePago(string, Fecha*, double, int);
	virtual ~HistorialDePago();

	string getId();
	Fecha* getFecha();
	double getMontoAPagar();
	int getMesPagado();

	string toString();
};