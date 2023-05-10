#include"Grupo.h"


//Desarrollo del Constructor parametrizado 
Grupo::Grupo(string id, string nom, int cM, int d, Fecha* fec, Horario* hor,int n) {
	IDInst = id;
	nombreInst = nom;
	cupoMaximo = cM;
	duracion = d;
	fecha = fec;
	horario = hor;
	numGrupo = n;
	listaDepo = new Contenedor<Deportista>;   //Internamente se crea el Contenedor Deportista(T)
}

//Desarrollo del destructor  
Grupo:: ~Grupo() {
	if (fecha != NULL)
		delete fecha;
	if (horario != NULL)
		delete horario;
}

//Desarrollo de Get's 
string Grupo::getIDInstructor() {
	return IDInst;
}

string Grupo::getNombreInstructor() {
	return nombreInst;
}

int Grupo::getCupoMaximo() {
	return cupoMaximo;
}

int Grupo::getDuracion() {
	return duracion;
}

Fecha* Grupo::getFecha() {
	return fecha;
}

Horario* Grupo::getHorario() {
	return horario;
}
int Grupo::getNumGrupo() {
	return numGrupo;
}

Contenedor<Deportista>* Grupo::getListaDepo()
{
	return listaDepo;
}

//Desarrollo de Set's 
void Grupo::setID(string id) {
	IDInst = id;
}

void Grupo::setNombre(string nom) {
	nombreInst = nom;
}

void Grupo::setCupoMaximo(int cM) {
	cupoMaximo = cM;
}

void Grupo::setDurarcion(int d) {
	duracion = d;
}

void Grupo::setFecha(Fecha* fec) {
	fecha = fec;
}

void Grupo::setHorario(Horario* hor) {
	horario = hor;
}
void Grupo::setNumGrupo(int n) {
	numGrupo = n;
}

//Desarrollo del toString 
string Grupo::toString() {
	stringstream s;
	s << "Numero del Grupo: " << numGrupo << endl
	<< "ID del Instructor: " << IDInst << endl
	<< "Nombre del Instructor: " << nombreInst << endl
	<< "Cupo Maximo: " << cupoMaximo << endl
	<< "Semanas de duracion: " << duracion << endl
	<< "Dia: " << horario->getDia() << endl
	<< "Horario: " << horario->toString() << endl;
	return s.str();
}