#include"Excepciones.h"


Excepciones::Excepciones() {}
Excepciones::~Excepciones() {}

ExcepcionCodigoExiste::ExcepcionCodigoExiste() : Excepciones() {}
ExcepcionCodigoExiste::~ExcepcionCodigoExiste() {}
string ExcepcionCodigoExiste::toString() const {
	return "ERROR: Ya existe un curso con ese codigo.\n";
}


ExcepcionCodigoNoExiste::ExcepcionCodigoNoExiste(): Excepciones() {}
ExcepcionCodigoNoExiste::~ExcepcionCodigoNoExiste(){}
string ExcepcionCodigoNoExiste::toString() const {
	return "ERROR: No existe un curso con ese codigo.\n";
}


ExcepcionIDExiste::ExcepcionIDExiste(): Excepciones() {}
ExcepcionIDExiste::~ExcepcionIDExiste(){}
string ExcepcionIDExiste::toString() const {
	return "ERROR: Ya existe un deportista con ese ID.\n";
}


ExcepcionIDNoExiste::ExcepcionIDNoExiste() : Excepciones() {}
ExcepcionIDNoExiste::~ExcepcionIDNoExiste() {}
string ExcepcionIDNoExiste::toString() const {
	return "ERROR: No existe un deportista con ese ID. \n";
}



ExcepcionGrupoLleno::ExcepcionGrupoLleno() : Excepciones() {}
ExcepcionGrupoLleno::~ExcepcionGrupoLleno() {}
string ExcepcionGrupoLleno::toString() const {
	return "ERROR: El grupo no posee campos disponibles. \n";
}


ExcepcionGrupoNoExiste::ExcepcionGrupoNoExiste(): Excepciones() {}
ExcepcionGrupoNoExiste::~ExcepcionGrupoNoExiste(){}
string ExcepcionGrupoNoExiste::toString() const{
	return "ERROR: No existe ese grupo en ese curso.\n";
}


ExcepcionDepoNoMatriculado::ExcepcionDepoNoMatriculado(): Excepciones() {}
ExcepcionDepoNoMatriculado::~ExcepcionDepoNoMatriculado(){}
string ExcepcionDepoNoMatriculado::toString() const {
	return "ERROR: El deportista no esta matriculado en ese grupo. \n";
}


ExcepcionRango::ExcepcionRango() : Excepciones() {}
ExcepcionRango::~ExcepcionRango() {}
string ExcepcionRango::toString() const {
	return "ERROR: La opcion digitada esta fuera de rango.\n";
}
