#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Gym.h"
#include "Utiles.h"

using namespace std;

class Interfaz {
public:
	static void bienvenida(Gym*);
	static void menu();

	//Administracion general
	static void administracionGeneral();
	static void nombreGym(Gym*);
	static void mensualidad(Gym*);

	//Control de Deportistas 
	static void controlDeDeportistas();
	static void ingresaDeportista(Gym*);
	static void modificaDeportista(Gym*);
	static void modificacionesDeportista(Deportista*, int);
	static void listaDeporsitas(Gym*);
	static void detalleDeportistaEspecifico(Gym*);

	//Control de Cursos 
	static void controlDeCursos();
	static void ingresarCurso(Gym*);
	static void reporteDeCurso(Gym*);
	static void modificarCurso(Gym*);
	static void modificacionesCurso(Curso*, int);


	//Control de Grupos 
	static void controlDeGrupos();
	static void ingresarGrupo(Gym*);
	static void modificarGrupo(Gym*);
	static void modificacionesGrupo(Grupo*, int);
	static void matricularEnGrupo(Gym*);
	static void reporteDeGrupo(Gym*);
	static void reporteDeportistasEnGrupo(Gym*);
	static void cancelacionDeMatriculaEnGrupo(Gym*);


	//Control de Pagos 
	static void controlPagos();
	static void registroNuevoPago(Gym*);
	static void reporteDePagosDeportista(Gym*);
};
