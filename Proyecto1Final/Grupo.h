#pragma once
#include "Triatlonista.h"
#include "Horario.h"
#include "Fecha.h"
#include "Contenedor.h"


class Grupo {
private:
	int numGrupo;
	string IDInst;
	string nombreInst;
	int cupoMaximo;
	int duracion;
	Fecha* fecha;
	Horario* horario;
	Contenedor<Deportista>* listaDepo;
public:
	Grupo(string, string, int, int, Fecha*, Horario*,int);
	virtual ~Grupo();
	string getIDInstructor();
	string getNombreInstructor();
	int getCupoMaximo();
	int getDuracion();
	Fecha* getFecha();
	Horario* getHorario();
	int getNumGrupo();
	Contenedor<Deportista>* getListaDepo();

	void setID(string);
	void setNombre(string);
	void setCupoMaximo(int);
	void setDurarcion(int);
	void setFecha(Fecha*);
	void setHorario(Horario*);
	void setNumGrupo(int);

	string toString();
	
};