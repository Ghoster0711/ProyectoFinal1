#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Gym.h"
#include "Utiles.h"

using namespace std;

class Interfaz {
public:
	static void bienvenida(Gym*); // Da la bienvenida y solicita la fecha actual
	static void menu(); // Menu general para el funcionamiento del programa

	//Administracion general
	static void administracionGeneral(); // Menu de administracion general
	static void nombreGym(Gym*); // Para cambiar el nombre del gym
	static void mensualidad(Gym*); // Para agregar la mensualidad del gym

	//Control de Deportistas 
	static void controlDeDeportistas(); // Menu para el control de deportistas
	static void ingresaDeportista(Gym*); // Se encarga de mostrar la informacion para el ingreso de un deportista
	static void modificaDeportista(Gym*); // Se encarga de mostrar la informacion para la modificacion de un deportista
	static void modificacionesDeportista(Deportista*, int); // Se encarga de ir al dato a modificar
	static void listaDeporsitas(Gym*); // Menu para los diferentes tipos de listados que se pueden hacer
	static void detalleDeportistaEspecifico(Gym*); // Se encarga de mostrar la informacion para un deportista especifico

	//Control de Cursos 
	static void controlDeCursos();// Menu para el control de cursos
	static void ingresarCurso(Gym*); // Se encarga de mostrar la informacion para el ingreso de un curso
	static void reporteDeCurso(Gym*); // Se encarga de listar los cursos
	static void modificarCurso(Gym*); // Se encarga de mostrar la informacion para la modificacion de los cursos
	static void modificacionesCurso(Curso*, int); // Se encarga de ir al dato a modificar


	//Control de Grupos 
	static void controlDeGrupos(); // Menu para el control de grupos
	static void ingresarGrupo(Gym*); // Se encarga de mostrar la informacion para el ingreso de un curso
	static void modificarGrupo(Gym*); // Se encarga de mostrar la informacion para la modificacion de los grupos
	static void modificacionesGrupo(Grupo*, int); // Se encarga de ir al dato a modificar
	static void matricularEnGrupo(Gym*); // Se encarga de mostrar la informacion para la matricula de los deportistas
	static void reporteDeGrupo(Gym*); // Se encarga de mostrar la informacion de los grupos
	static void reporteDeportistasEnGrupo(Gym*); // Se encarga de mostrar la informacion de los deportista matriculados
	static void cancelacionDeMatriculaEnGrupo(Gym*); // Se encarga de cancelar la matricula en un grupo


	//Control de Pagos 
	static void controlPagos(); // Menu para el control de pagos
	static void registroNuevoPago(Gym*); // Se encarga de mostrar la informacion para el resgistro de un nuevo pago
	static void reporteDePagosDeportista(Gym*); // // Se encarga de mostrar la informacion de los pagos del deportista
};
