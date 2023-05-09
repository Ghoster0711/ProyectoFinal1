#pragma once
#include "Nodo.h"
#include "Iterador.h"
#include <iostream>
#include <sstream>
#include <string>

template<class T>
class Contenedor {
private:
	Nodo<T>* _primero;
	int cantidad;
public:
	Contenedor();
	virtual ~Contenedor();

	int getCantidad();
	Nodo<T>* getPrimero();
	bool ingresar(T&);
	bool clonDepo(Deportista*);

	bool encontrarDeportista(string);
	void listarDeportistasCedNom();
	void deleteDepo(string);
		
};


template<class T>
Contenedor<T>::Contenedor() {
	_primero = NULL;
	cantidad = 0;
}

template<class T>
Contenedor<T>::~Contenedor() {}

template<class T>
inline int Contenedor<T>::getCantidad()
{
	return cantidad;
}

template<class T>
Nodo<T>* Contenedor<T>::getPrimero() {
	return _primero;
}


template<class T>
bool Contenedor<T>::ingresar(T& dato) {
	_primero = new Nodo<T>((T*)&dato, _primero);
	cantidad++;
	return true;
}

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

//template<class T>
//inline void Contenedor<T>::deleteDepo(string ced)
//{
//	Nodo<Deportista>* pExt = _primero;
//	Nodo<Deportista>* pAnterior = NULL;
//	if (pExt != NULL && pExt->getDato() != NULL) {
//		if (pExt->getDato()->getCedula() == ced) {
//			_primero = _primero->getSiguiente();
//			cantidad--;
//			delete pExt;
//			return;
//		}
//
//	}
//
//
//
//}
