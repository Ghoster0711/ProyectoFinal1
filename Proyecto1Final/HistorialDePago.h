#pragma once
#include "Fecha.h"
#include "Triatlonista.h"
#include"Utiles.h"

class HistorialDePago {   //Clase de historial de cada pago 
private:
	string id;		//Identificacion del deportista que pago 
	Fecha* fecha;		//Fecha en la que realizo el pago
	double montoAPagar;		//Monto que pago 
	int mesPagado;		//Mes que se cancelo 
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