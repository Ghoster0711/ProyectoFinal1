#include"Excepciones.h"

//Abstrac 
Excepciones::Excepciones() {}
Excepciones::~Excepciones() {}


//Excepcion que ya existe un curso con x codigo
ExcepcionCodigoExiste::ExcepcionCodigoExiste() : Excepciones() {}
ExcepcionCodigoExiste::~ExcepcionCodigoExiste() {}
string ExcepcionCodigoExiste::toString() const {
	return "ERROR: Ya existe un curso con ese codigo.\n";
}

//Excepcion que no existe un curso con x codigo
ExcepcionCodigoNoExiste::ExcepcionCodigoNoExiste(): Excepciones() {}
ExcepcionCodigoNoExiste::~ExcepcionCodigoNoExiste(){}
string ExcepcionCodigoNoExiste::toString() const {
	return "ERROR: No existe un curso con ese codigo.\n";
}

//Excepcion de que ya existe un deportista con x ID
ExcepcionIDExiste::ExcepcionIDExiste(): Excepciones() {}
ExcepcionIDExiste::~ExcepcionIDExiste(){}
string ExcepcionIDExiste::toString() const {
	return "ERROR: Ya existe un deportista con ese ID.\n";
}

//Excepcion que no existe un deportista con x ID 
ExcepcionIDNoExiste::ExcepcionIDNoExiste() : Excepciones() {}
ExcepcionIDNoExiste::~ExcepcionIDNoExiste() {}
string ExcepcionIDNoExiste::toString() const {
	return "ERROR: No existe un deportista con ese ID. \n";
}

//Excepcion matricula deportista
ExcepcionMatricula::ExcepcionMatricula(): Excepciones() {}
ExcepcionMatricula::~ExcepcionMatricula(){}
string ExcepcionMatricula::toString() const {
	return "ERROR: No puede matricular mas de 4 cursos. \n";
}


//Excepcion de grupo lleno 
ExcepcionGrupoLleno::ExcepcionGrupoLleno() : Excepciones() {}
ExcepcionGrupoLleno::~ExcepcionGrupoLleno() {}
string ExcepcionGrupoLleno::toString() const {
	return "ERROR: El grupo no posee campos disponibles. \n";
}

//Excepcion que no existe numero de grupo
ExcepcionGrupoNoExiste::ExcepcionGrupoNoExiste(): Excepciones() {}
ExcepcionGrupoNoExiste::~ExcepcionGrupoNoExiste(){}
string ExcepcionGrupoNoExiste::toString() const{
	return "ERROR: No existe ese grupo en ese curso.\n";
}

//Excepcion deportista no matriculado en x grupo
ExcepcionDepoNoMatriculado::ExcepcionDepoNoMatriculado(): Excepciones() {}
ExcepcionDepoNoMatriculado::~ExcepcionDepoNoMatriculado(){}
string ExcepcionDepoNoMatriculado::toString() const {
	return "ERROR: El deportista no esta matriculado en ese grupo. \n";
}

//Excepcion de que no se digito una opcion del menu 
ExcepcionRango::ExcepcionRango() : Excepciones() {}
ExcepcionRango::~ExcepcionRango() {}
string ExcepcionRango::toString() const {
	return "ERROR: La opcion digitada esta fuera de rango.\n";
}

ExcepcionCambioEstado::ExcepcionCambioEstado(): Excepciones() {}
ExcepcionCambioEstado::~ExcepcionCambioEstado() {}
string ExcepcionCambioEstado::toString() const {
	return "ERROR: Este deportista no puede cambiar su estado. \n";
}