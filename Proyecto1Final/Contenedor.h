#pragma once
#include "Nodo.h"
#include "Iterador.h"
#include <iostream>
#include <sstream>
#include <string>


// Se crea la clase Contenedor con template
template<class T>
class Contenedor {
private:
	Nodo<T>* _primero;
	int cantidad;
public:
	// Constructor
	Contenedor();

	// Destructor
	virtual ~Contenedor();

	// Metodos get's set's de la clase
	int getCantidad();
	Nodo<T>* getPrimero();

	// Metodo para ingresar en el contenedor
	bool ingresar(T&);

	// Metodo para clonar un deportista
	bool clonDepo(Deportista*);

	// Metodo para encontrar un deportista en el contenedor
	bool encontrarDeportista(string);

	// Metodo para listar las cedula y nombre de los deportistas
	void listarDeportistasCedNom();

	// Metodo para eliminar un deportista
	void deleteDepo(string);
		
};

// Desarrollo del constructor
template<class T>
Contenedor<T>::Contenedor() {
	_primero = NULL;
	cantidad = 0;
}

// Desarrollo del destructor
template<class T>
Contenedor<T>::~Contenedor() {
	Nodo<T>* actual = _primero;
	Nodo<T>* siguiente;
	while (actual != nullptr) {
		siguiente = actual->getSiguiente();
		delete actual;
		actual = siguiente;
	}
	_primero = nullptr;
}

// Desarrollo de lo metodos get's set's 
template<class T>
inline int Contenedor<T>::getCantidad()
{
	return cantidad;
}

template<class T>
Nodo<T>* Contenedor<T>::getPrimero() {
	return _primero;
}

// Desarrollo del metodo para ingresar
template<class T>
bool Contenedor<T>::ingresar(T& dato) {
	_primero = new Nodo<T>((T*)&dato, _primero);
	cantidad = cantidad + 1;
	return true;
}


// Desarrollo del metodo para clonar deportista
template<class T>
inline bool Contenedor<T>::clonDepo(Deportista* dep)
{
	Deportista* aux = dep;
	string id, tel, nom;
	double est, mas, pes, gras;
	int horas, iron, ganados;
	Fecha* f = NULL;
	char sex;
	id = aux->getCedula();
	tel = aux->getTelefono();
	nom = aux->getNombre();
	f = new Fecha(aux->getFecha()->getDia(), aux->getFecha()->getMes(), aux->getFecha()->getAnio());
	sex = aux->getSexo();
	horas = aux->getHorasEntrenadas();
	iron = aux->getCantParticEnIronMan();
	ganados = aux->getCantTriatGanados();
	est = aux->getEstatura();
	pes = aux->getPeso();
	gras = aux->getProcGrasaCorporal();
	mas = aux->getMasaMuscular();
	Deportista* d = new Triatlonista(id, nom, tel, f, sex, est, iron, ganados, horas, 0.0, mas, pes, gras);

	return ingresar(*d);
}


// Desarrollo del metodo para encontrar deportista
template<class T>
bool Contenedor<T>::encontrarDeportista(string ced) {
	Iterador<Deportista>* ite = new Iterador<Deportista>(_primero);
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			if (ite->getPNodo()->getDato()->getCedula() == ced) {
				return true;
			}
		}
		ite->operator++();
	}
	return false;
}


// Desarrollo del metodo para lista cedula, nombre de los deportistas
template<class T>
void Contenedor<T>::listarDeportistasCedNom()
{
	Iterador<Deportista>* ite = new Iterador<Deportista>(getPrimero());
	cout << "------------------------------------------------" << endl;
	while (ite->getPNodo() != NULL) {
		if (ite->getPNodo()->getDato() != NULL) {
			cout << ite->getPNodo()->getDato()->toStringCedNom();
			cout << "------------------------------------------------" << endl;
		}
		ite->operator++();
	}
}


// Desarrollo del metodo para eliminar deportista del contenedor
template<class T>
inline void Contenedor<T>::deleteDepo(string ced)
{
	Nodo<Deportista>* pExt = _primero;
	Nodo<Deportista>* pAnterior = _primero;
	if (pExt != NULL) {
		if (pExt->getDato() != NULL) {
			if (pExt->getDato()->getCedula() == ced) {
				pAnterior->setSiguiente(pExt->getSiguiente());
				cantidad--;
				delete pExt;
				return;
			}
			pExt = pExt->getSiguiente();
			while (pExt != NULL) {
				if (pExt->getDato() != NULL) {
					if (pExt->getDato()->getCedula() == ced) {
						pAnterior->setSiguiente(pExt->getSiguiente());
						delete pExt;
						cantidad--;
						return;
					}
					pAnterior = pExt;
					pExt = pExt->getSiguiente();
				}
			}
		}
	}
	

}

