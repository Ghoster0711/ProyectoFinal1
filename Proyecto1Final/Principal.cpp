#include "Gym.h"
#include"Interfaz.h"
#include"Excepciones.h"

using namespace std;

int main() {
	bool salir = true;
	int opcion = 0;
	int op = 0;
	Gym* gym = new Gym();
	Interfaz::bienvenida(gym);
	system("cls");
	while (salir) {
		try {
			Interfaz::menu();
			opcion = entradaInt();
			if (opcion < 1 || opcion > 6) 
				throw(ExcepcionRango());
			
		}
		catch (ExcepcionRango& e) {
			cout << e.toString() << endl;
			system("pause");
		}
		switch (opcion) {
		case 1: {
			do {
				try {
					Interfaz::administracionGeneral();
				    op = entradaInt();
					if (op < 1 || op > 3)
						throw(ExcepcionRango());
				}
				catch (ExcepcionRango& e) {
					cout << e.toString() << endl;
					system("pause");
				}
				switch (op) {
				case 1:
					Interfaz::nombreGym(gym);
					break;
				case 2:
					Interfaz::mensualidad(gym);
					break;
				}
			} while (op != 3);
		}break;
		case 2: {
			do {
				try {
					Interfaz::controlDeDeportistas();
					op = entradaInt();
					if (op < 1 || op > 5)
						throw(ExcepcionRango());
				}
				catch (ExcepcionRango& e) {
					cout << e.toString() << endl;
					system("pause"); 
				}
				switch (op) {
				case 1:
					Interfaz::ingresaDeportista(gym);
					break;
				case 2:
					Interfaz::modificaDeportista(gym);
					break;
				case 3:
					Interfaz::listaDeporsitas(gym);
					break;
				case 4:
					Interfaz::detalleDeportistaEspecifico(gym);
					break;
				}
			} while (op != 5);
		}break;
		case 3: {
			do {
				try {
					Interfaz::controlDeCursos();
					op = entradaInt();
					if (op < 1 || op > 4)
						throw(ExcepcionRango());
				}
				catch (ExcepcionRango& e) {
					cout << e.toString() << endl;
					system("pause");
				}
				switch (op) {
				case 1:
					Interfaz::ingresarCurso(gym);
					break;
				case 2:
					Interfaz::reporteDeCurso(gym);
					break;
				case 3:
					Interfaz::modificarCurso(gym);
					break;
				}
			} while (op != 4);
		}break;
		case 4: {
			do {
				try {
					Interfaz::controlDeGrupos();
					op = entradaInt();
					if (op < 1 || op > 7)
						throw(ExcepcionRango());
				}
				catch (ExcepcionRango& e) {
					cout << e.toString() << endl;
					system("pause");
				}
				switch (op) {
				case 1:
					Interfaz::ingresarGrupo(gym);
					break;
				case 2:
					Interfaz::modificarGrupo(gym);
					break;
				case 3:
					Interfaz::matricularEnGrupo(gym);
					break;
				case 4:
					Interfaz::reporteDeGrupo(gym);
					break;
				case 5:
					Interfaz::reporteDeportistasEnGrupo(gym);
					break;
				case 6:
					Interfaz::cancelacionDeMatriculaEnGrupo(gym);
					break;
				}
			} while (op != 7);
		}break;
		case 5: {
			do {
				try {
					Interfaz::controlPagos();
					op = entradaInt();
					if (op < 1 || op > 3)
						throw(ExcepcionRango());
				}
				catch (ExcepcionRango& e) {
					cout << e.toString() << endl;
					system("pause");
				}
				switch (op) {
				case 1:
					Interfaz::registroNuevoPago(gym);
					break;
				case 2:
					Interfaz::reporteDePagosDeportista(gym);
					break;
				}
			} while (op != 3);
		}break;
		case 6: {
			salir = false;
		}break;
		}
		system("color 07");
		system("cls");
	}
	return 0;
}