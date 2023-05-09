#pragma once
#include "Contenedor.h"
#include "Triatlonista.h"
#include "HistorialDePago.h"
#include "Curso.h"
#include "Grupo.h"
#include"Utiles.h"

class Gym {
private:
	string nombre;
	double mensualidad;
	Fecha* fecha;
	Contenedor<Deportista>* COD;
	Contenedor<Curso>* COC;
	Contenedor<HistorialDePago>* COHP;
public:
	Gym();
	virtual ~Gym();

	Contenedor<Deportista>* getCOD() const;
	Contenedor<Curso>* getCOC() const;
	Contenedor<HistorialDePago>* getCOHP() const;

	string getNombre();
	double getMensualidad();
	Fecha* getFecha();


	void setMensualidad(double);
	void setNombre(string);
	void setFecha(Fecha*);

	//------------------Contenedores----------------------
	
	// -----Deportistas----
	bool encontrarDeportista(string);
	Deportista* retornaDeportista(string);
	void listarDeportistas();
	void listarDeportistasActivos();
	void listarDeportistasInactivos();
	void listarDeportistasMorosos();
	bool deportistaMoroso(string);
	

	// ------Cursos------
	void listadoCurso();
	bool encontrarCurso(string);
	Curso* retornaCurso(string);
	

	// ------Grupos------
	string encontrarDeportistaEnGrupos(string);
	void listadoGrupos(Curso*);
	bool encontrarGrupo(Curso*, int);
	Grupo* retornaGrupo(Curso*, int);
	void listadoGruposParaDepo(Curso*);
	void listaNumerosGrupos(Curso*);


	//--------Pagos--------
	string registroNuevoPago(string, int);
	string calcularCuotasCanceladas(int);
	string reportePagosDeportista(string);


};