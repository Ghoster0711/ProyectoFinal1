#pragma once
#include <iostream>
#include <sstream>
#include "Triatlonista.h"


// Se crea la clase Nodo
template<class T>
class Nodo {
private:
	T* dato;   // Guarda un dato
	Nodo<T>* siguiente; // Guarda el siguiente nodo
public:
	// Constructor
	Nodo();

	// Constructor parametrizado
	Nodo(T*, Nodo<T>*);
	
	// Destructor
	virtual ~Nodo();

	// Metodos get's set's de la clase
	T* getDato();
	Nodo<T>* getSiguiente();

	void setDato(T*);
	void setSiguiente(Nodo<T>*);
};

// Desarrollo de los constructores
template<class T>
Nodo<T>::Nodo() {
	this->dato = NULL;
	this->siguiente = NULL;
}

template<class T>
Nodo<T>::Nodo(T* dato, Nodo<T>* sig) {
	this->dato = dato;
	this->siguiente = sig;
}

// Desarrollo del destructor
template<class T>
Nodo<T>::~Nodo() {
	delete dato;
}

// Desarrollo de lo metodos get's set's 
template<class T>
T* Nodo<T>::getDato() { return dato; }

template<class T>
Nodo<T>* Nodo<T>::getSiguiente() { return siguiente; }

template<class T>
void Nodo<T>::setDato(T* dato) { this->dato = dato; }

template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente) { this->siguiente = siguiente; }