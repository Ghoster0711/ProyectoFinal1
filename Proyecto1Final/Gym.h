#pragma once
#include "Contenedor.h"
#include "Triatlonista.h"
#include "HistorialDePago.h"
#include "Curso.h"
#include "Grupo.h"
#include"Utiles.h"


// Se crea la clase Gym
class Gym {
private:
	string nombre;  // Nombre del gym
	double mensualidad; // La mensualidad del gym
	Fecha* fecha; // La fecha actual
	Contenedor<Deportista>* COD; // Un contenedor para deportistas
	Contenedor<Curso>* COC;  // Un contenedor para los cursos
	Contenedor<HistorialDePago>* COHP; // Un contenedor para el historial de pagos
public:
	// Constructor
	Gym();

	// Destructor
	virtual ~Gym();

	// Metodos get's set's  de la clase
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
	// Metodos para los contenedores
	
	// -----Deportistas----
	bool encontrarDeportista(string);  // Metodo para encontrar deportista
	Deportista* retornaDeportista(string); // Metodo para retornar un deportista
	void listarDeportistas(); // Metodo para listar deportista
	void listarDeportistasActivos(); // Metodo para listar deportista activos
	void listarDeportistasInactivos(); // Metodo para listar deportista inactivos
	void listarDeportistasMorosos(); // Metodo para listar deportista morosos
	void deportistasMorosos(); // Metodo que calcula los morosos
	bool deportistaMoroso(string); // Metodo para encontrar quien esta moroso
	

	// ------Cursos------
	void listadoCurso(); // Metodo para listar los cursos
	bool encontrarCurso(string); // Metodo para encontrar curso
	Curso* retornaCurso(string); // Metodo para retonar curso
	

	// ------Grupos------
	string encontrarDeportistaEnGrupos(string); // Metodo para encontrar deportista en grupos
	bool seEncontraDeportistaEnGrupos(string ,string); // Metodo para ver si se encuentra el deportista en los grupos
	void listadoGrupos(Curso*); // Metodo para listar los grupos
	bool encontrarGrupo(Curso*, int); // Metodo para encontrar el grupo
	Grupo* retornaGrupo(Curso*, int); // Metodo para retornar el grupo
	void listadoGruposParaDepo(Curso*); // Metodo para listar
	void listaNumerosGrupos(Curso*); // Metodo para listar los numeros de grupos


	//--------Pagos--------

	string registroNuevoPago(string, int);  // Metodo para registrar un pago
  int fechaHistorialDeportista(string); // Metodo para calcular el mes del ultimo pago
	string calcularCuotasCanceladas(int); // Metodo para calcular las cuotas canceladas
	string reportePagosDeportista(string); // Metodo que lista los pagos hechos por los deportistas



};