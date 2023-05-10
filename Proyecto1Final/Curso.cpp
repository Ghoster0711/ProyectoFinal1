#include "Curso.h"
// Desarrollo de los constructores
Curso::Curso()
	:codigo(""), nombre(""), descripcion(""), nivel(""), cantidadGrupos(0) {
	COG = new Contenedor<Grupo>;
}

Curso::Curso(string cod, string nom, string desc, string niv, int cant)
	:codigo(cod), nombre(nom), descripcion(desc), nivel(niv), cantidadGrupos(cant) {
	COG = new Contenedor<Grupo>;
}


// Desarrollo del destructor
Curso::~Curso() {
	if (COG->getPrimero() != NULL)
		delete COG;
}

// Desarrollo de lo metodos get's set's y toString
string Curso::getCodigo() { return codigo; }


string Curso::getNombre() { return nombre; }

string Curso::getDescription() { return descripcion; }

string Curso::getNivel() { return nivel; }

int Curso::getCantidadGrupos() {	return cantidadGrupos; }

Contenedor<Grupo>* Curso::getCOG() { return COG; }

void Curso::setCantidadGrupos(int x) { cantidadGrupos = x; }

void Curso::setCodigo(string cod) { codigo = cod; }

void Curso::setNombre(string nom) { nombre = nom; }

void Curso::setDescripcion(string desc) { descripcion = desc; }

void Curso::setNivel(string niv) { nivel = niv; }

string Curso::toString() {
	stringstream show;
	show << "Nombre del curso : " << nombre << endl
		<< "Nivel del curso: " << nivel << endl
		<< "Cantidad de grupos: " << cantidadGrupos << endl
		<< "Descripcion del curso: " << descripcion << endl;

	return show.str();
}


// Este metodo muestra nada mas el codigo, nombre y nivel
string Curso::toStringListado()
{
	stringstream show;
	show << codigo << "\t" << nombre << "\t" << nivel << endl;
	return show.str();
}
