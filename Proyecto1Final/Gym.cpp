#include "Gym.h"


Gym::Gym() {
	nombre = "UNAfitness";
	mensualidad = 0;
	fecha = NULL;
	COD = new Contenedor<Deportista>();
	COC = new Contenedor<Curso>();
	COHP = new Contenedor<HistorialDePago>();
}


Gym::~Gym() {}


Contenedor<Deportista>* Gym::getCOD() const { return COD; }
Contenedor<Curso>* Gym::getCOC() const { return COC; }
Contenedor<HistorialDePago>* Gym::getCOHP() const { return COHP; }


string Gym::getNombre() { return nombre; }

double Gym::getMensualidad() { return mensualidad; }

Fecha* Gym::getFecha() { return fecha; }

void Gym::setMensualidad(double men) { mensualidad = men; }

void Gym::setNombre(string nom) { nombre = nom; }

void Gym::setFecha(Fecha* fec) { fecha = fec; }


//--------------------Deportistas--------------

bool Gym::encontrarDeportista(string ced)
{
	Iterador<Deportista>* ite = new Iterador<Deportista>(COD->getPrimero());
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			if (ite->getPNodo()->getDato()->getCedula() == ced)
				return true;
		}
		ite->operator++();
	}
	return false;
}

Deportista* Gym::retornaDeportista(string ced)
{
	Iterador<Deportista>* ite = new Iterador<Deportista>(COD->getPrimero());
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			if (ite->getPNodo()->getDato()->getCedula() == ced)
				return ite->getPNodo()->getDato();
		}
		ite->operator++();
	}
	return NULL;
}

void Gym::listarDeportistas()
{
	Iterador<Deportista>* ite = new Iterador<Deportista>(COD->getPrimero());
	cout << "------------------------------------------------" << endl;
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			cout << ite->getPNodo()->getDato()->toString();
			cout << "------------------------------------------------" << endl;
		}
		ite->operator++();
	}
}

void Gym::listarDeportistasActivos()
{
	Iterador<Deportista>* ite = new Iterador<Deportista>(COD->getPrimero());
	cout << "------------------------------------------------" << endl;
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			if (ite->getPNodo()->getDato()->getEstado() == "Activo") {
				cout << ite->getPNodo()->getDato()->toString();
				cout << "------------------------------------------------" << endl;
			}
		}
		ite->operator++();
	}
}

void Gym::listarDeportistasInactivos()
{
	Iterador<Deportista>* ite = new Iterador<Deportista>(COD->getPrimero());
	cout << "------------------------------------------------" << endl;
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			if (ite->getPNodo()->getDato()->getEstado() == "Inactivo") {
				cout << ite->getPNodo()->getDato()->toString();
				cout << "------------------------------------------------" << endl;
			}
		}
		ite->operator++();
	}
}

void Gym::listarDeportistasMorosos()
{
	Iterador<Deportista>* ite = new Iterador<Deportista>(COD->getPrimero());
	cout << "------------------------------------------------" << endl;
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			if (ite->getPNodo()->getDato()->getEstado() == "Moroso") {
				cout << ite->getPNodo()->getDato()->toString();
				cout << "------------------------------------------------" << endl;
			}
		}
		ite->operator++();
	}
}

void Gym::deportistasMorosos() {
	Iterador<Deportista>* ite = new Iterador<Deportista>(COD->getPrimero());
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			if (deportistaMoroso(ite->getPNodo()->getDato()->getCedula()) == true) {
				ite->getPNodo()->getDato()->setEstado("Moroso");
			}
			else {
				if(ite->getPNodo()->getDato()->getEstado() != "Inactivo")
					ite->getPNodo()->getDato()->setEstado("Activo");
			}
		}
		ite->operator++();
	}
	
}

bool Gym::deportistaMoroso(string id) {
	Iterador<HistorialDePago>* ite = new Iterador<HistorialDePago>(COHP->getPrimero());
	HistorialDePago* aux = NULL;
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			if (ite->getPNodo()->getDato()->getId() == id) {
				aux = ite->getPNodo()->getDato();
				break;
			}
			else {
				ite->operator++();
			}
		}
	}
	if (aux->getMesPagado() < fecha->getMes())
		return true;
	else
		return false;
}



// ----------------------Cursos----------------------
void Gym::listadoCurso()
{
	Iterador<Curso>* ite = new Iterador<Curso>(COC->getPrimero());
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			cout << ite->getPNodo()->getDato()->toStringListado();
		}
		ite->operator++();
	}
}

bool Gym::encontrarCurso(string cod)
{
	Iterador<Curso>* ite = new Iterador<Curso>(COC->getPrimero());
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			if (ite->getPNodo()->getDato()->getCodigo() == cod)
				return true;
		}
		ite->operator++();
	}
	return false;
}

Curso* Gym::retornaCurso(string cod)
{
	Iterador<Curso>* ite = new Iterador<Curso>(COC->getPrimero());
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			if (ite->getPNodo()->getDato()->getCodigo() == cod)
				return ite->getPNodo()->getDato();
		}
		ite->operator++();
	}
	return NULL;
}


// ---------------------Grupos----------------------
string Gym::encontrarDeportistaEnGrupos(string ced)
{
	stringstream show;
	Iterador<Curso>* ite = new Iterador<Curso>(COC->getPrimero());
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			Contenedor<Grupo>* cog = ite->getPNodo()->getDato()->getCOG();
			Iterador<Grupo>* ite2 = new Iterador<Grupo>(cog->getPrimero());
			while (ite2->getPNodo() != NULL) {
				if (ite2->getPNodo()->getDato() != NULL) {
					if (ite2->getPNodo()->getDato()->getListaDepo()->encontrarDeportista(ced) == true) {
						show << "(" << ite->getPNodo()->getDato()->getCodigo() << ") ";
						show << ite->getPNodo()->getDato()->getNombre() << ", ";
						show << "grupo #" << ite2->getPNodo()->getDato()->getNumGrupo() << endl;
					}
				}
				ite2->operator++();
			}
		}
		ite->operator++();
	}
	return show.str();
}

bool Gym::seEncontraDeportistaEnGrupos(string cod, string ced)
{
	Curso* cur = retornaCurso(cod);
	Iterador<Grupo>* ite2 = new Iterador<Grupo>(cur->getCOG()->getPrimero());
	while (ite2->getPNodo() != NULL) {
		if (ite2->getPNodo()->getDato() != NULL) {
			if (ite2->getPNodo()->getDato()->getListaDepo()->encontrarDeportista(ced) == true) {
				return true;
			}
		}
		ite2->operator++();
	}
	return false;
}

void Gym::listadoGrupos(Curso* cur)
{
	Iterador<Grupo>* ite = new Iterador<Grupo>(cur->getCOG()->getPrimero());
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			cout << ite->getPNodo()->getDato()->getNumGrupo()
				<< "		"
				<< ite->getPNodo()->getDato()->getCupoMaximo()
				<< "		"
				<< ite->getPNodo()->getDato()->getListaDepo()->getCantidad() << endl;
		}
		ite->operator++();
	}
}

bool Gym::encontrarGrupo(Curso* cur, int numG)
{
	Iterador<Grupo>* ite = new Iterador<Grupo>(cur->getCOG()->getPrimero());
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			if (ite->getPNodo()->getDato()->getNumGrupo() == numG)
				return true;
		}
		ite->operator++();
	}
	return false;
}

Grupo* Gym::retornaGrupo(Curso* cur, int numG)
{
	Iterador<Grupo>* ite = new Iterador<Grupo>(cur->getCOG()->getPrimero());
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			if (ite->getPNodo()->getDato()->getNumGrupo() == numG)
				return ite->getPNodo()->getDato();
		}
		ite->operator++();
	}
	return NULL;
}

void Gym::listadoGruposParaDepo(Curso* cur) {
	Iterador<Grupo>* ite = new Iterador<Grupo>(cur->getCOG()->getPrimero());
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			cout << ite->getPNodo()->getDato()->getNumGrupo()
				<< "		"
				<< ite->getPNodo()->getDato()->getHorario()->getDia()
				<< "		"
				<< ite->getPNodo()->getDato()->getHorario()->toString()
				<< "		"
				<< ite->getPNodo()->getDato()->getCupoMaximo()
				<< "		"
				<< ite->getPNodo()->getDato()->getListaDepo()->getCantidad() << endl;
		}
		ite->operator++();
	}
}

void Gym::listaNumerosGrupos(Curso* cur)
{
	Iterador<Grupo>* ite = new Iterador<Grupo>(cur->getCOG()->getPrimero());
	cout << "# Grupo" << endl;
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			cout << ite->getPNodo()->getDato()->getNumGrupo() << endl;
		}
		ite->operator++();
	}
}

//---------------Control Pagos----------------
string Gym::registroNuevoPago(string id,int cuotas) {

	int dia = fecha->getDia();
	int mes = fecha->getMes();
	int anio = fecha->getAnio();

	int diaAux = fecha->getDia();
	int mesAux = fecha->getMes();
	int anioAux = fecha->getAnio();

	while (cuotas != 0) {
		if (mes > 12) {
			mesAux = 1;
			anioAux++;
		}
		Fecha* fecha = new Fecha(dia, mes, anio);
		HistorialDePago* historial = new HistorialDePago(id, fecha, mensualidad, mesAux);
		mesAux++;
		cuotas--;
		COHP->ingresar(*historial);
	}
	return convierteMes(mesAux - 1);
}

string Gym::calcularCuotasCanceladas(int cuotas) {
	stringstream s;
	int dia = fecha->getDia();
	int mes = fecha->getMes();
	int anio = fecha->getAnio();

	while (cuotas != 0) {
		if (mes > 12) {
			mes = 1;;
			anio++;
		}
		s << "- " << convierteMes(mes) << "   " << anio << endl;
		mes++;
		cuotas--;
	}
	return s.str();
}

string Gym::reportePagosDeportista(string id) {
	stringstream s;
	s << " Fecha de Pago          Mes Pagado        Monto cancelado" << endl;
	Iterador<HistorialDePago>* ite = new Iterador<HistorialDePago>(COHP->getPrimero());
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			if (ite->getPNodo()->getDato()->getId() == id)
				s << ite->getPNodo()->getDato()->toString();
		}
		ite->operator++();
	}
	return s.str();
}


