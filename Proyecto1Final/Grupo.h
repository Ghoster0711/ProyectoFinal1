#pragma once
#include "Triatlonista.h"
#include "Horario.h"
#include "Fecha.h"
#include "Contenedor.h"


class Grupo {
private:
	int numGrupo;     //Numero de grupo
	string IDInst;    //ID del instructor 
	string nombreInst;   //Nombre del instructor 
	int cupoMaximo;     //Cupo maximo del grupo
	int duracion;      //Duracion del curso 
	Fecha* fecha;      //Fecha de inicio
	Horario* horario;  //Horario 
	Contenedor<Deportista>* listaDepo;   //Contenedor Deportista(T) 
public:
	//Contructor Parametrizado 
	Grupo(string, string, int, int, Fecha*, Horario*,int);

	//Destructor
	virtual ~Grupo();

	//Get's 
	string getIDInstructor();
	string getNombreInstructor();
	int getCupoMaximo();
	int getDuracion();
	Fecha* getFecha();
	Horario* getHorario();
	int getNumGrupo();
	Contenedor<Deportista>* getListaDepo();

	//Set's 
	void setID(string);
	void setNombre(string);
	void setCupoMaximo(int);
	void setDurarcion(int);
	void setFecha(Fecha*);
	void setHorario(Horario*);
	void setNumGrupo(int);

	//ToString 
	string toString();
	
};