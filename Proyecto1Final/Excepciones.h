#pragma once
#include<iostream>
#include<sstream>

using namespace std;
//Abstrac 
class Excepciones {
public:
	Excepciones();
	virtual ~Excepciones();
	virtual string toString() const = 0;
};

//Excepcion existe un grupo con x codigo
class ExcepcionCodigoExiste : public Excepciones {
public:
	ExcepcionCodigoExiste();
	virtual ~ExcepcionCodigoExiste();
	string toString() const;
};

//Excepcion que no existe un grupo con x codigo
class ExcepcionCodigoNoExiste : public Excepciones {
public:
	ExcepcionCodigoNoExiste();
	virtual ~ExcepcionCodigoNoExiste();
	string toString() const;
};


//Excepcion que no existe un deportista con x ID 
class ExcepcionIDNoExiste : public Excepciones {
public:
	ExcepcionIDNoExiste();
	virtual ~ExcepcionIDNoExiste();
	string toString() const;
};

//Excepcion que un deportista ya existe 
class ExcepcionIDExiste : public Excepciones {
public:
	ExcepcionIDExiste();
	virtual ~ExcepcionIDExiste();
	string toString() const;
};

//Excepcion matricula deportista
class ExcepcionMatricula : public Excepciones {
public:
	ExcepcionMatricula();
	virtual ~ExcepcionMatricula();
	string toString() const;
};

//Excepcion de grupo lleno 
class ExcepcionGrupoLleno : public Excepciones {
public:
	ExcepcionGrupoLleno();
	virtual ~ExcepcionGrupoLleno();
	string toString() const;
};

//Excepcion que no existe numero de grupo 
class ExcepcionGrupoNoExiste : public Excepciones {
public:
	ExcepcionGrupoNoExiste();
	virtual ~ExcepcionGrupoNoExiste();
	string toString() const;

};

//Excepcion no existe deportista en x grupo
class ExcepcionDepoNoMatriculado : public Excepciones {
public:
	ExcepcionDepoNoMatriculado();
	virtual ~ExcepcionDepoNoMatriculado();
	string toString() const;
};


//Excepcion de que no se digito una opcion del menu 
class ExcepcionRango : public Excepciones {
public:
	ExcepcionRango();
	virtual ~ExcepcionRango();
	string toString() const;
};

//Excepcion de cambio de estado 
class ExcepcionCambioEstado : public Excepciones {
public:
	ExcepcionCambioEstado();
	virtual ~ExcepcionCambioEstado();
	string toString() const;
};
