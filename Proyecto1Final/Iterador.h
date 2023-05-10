#pragma once
#include"Nodo.h"


template<class T>
class Iterador{
private:
	Nodo<T>* pNodo;  //Es el puntero al que esta viendo en ese momento (current)
public:
	Iterador();
	Iterador(Nodo<T>*);
	virtual~Iterador();
	Nodo<T>* getPNodo();
	T& operator  *();    //Obtiene el elemento que ve y lo retorna 
	void operator ++();  //Se pasa de un elemento a otro
};

template<class T>
Iterador<T>::Iterador() {
	pNodo = NULL;
}

template<class T>
Iterador<T>::Iterador(Nodo<T>* aux) {
	pNodo = aux;
}

template<class T>
Iterador<T>::~Iterador() {

}

template<class T>
Nodo<T>* Iterador<T>::getPNodo() {
	return pNodo;
}

template<class T>
T& Iterador<T>::operator*() {
	return pNodo->getDato();
}

template<class T>
void Iterador<T>::operator++() {
	if (pNodo != NULL)
		pNodo = pNodo->getSiguiente();
}
