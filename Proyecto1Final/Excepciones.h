#pragma once
#include<iostream>
#include<sstream>

using namespace std;

class Excepciones {  //Case abstracta para la creacion de distintos tipos de Excepciones 
public:
	Excepciones();
	virtual ~Excepciones();
	virtual string toString() const = 0;
};


class ExcepcionCodigoExiste : public Excepciones {   //Excepcion que ya existe un curso con algun codigo
public:
	ExcepcionCodigoExiste();
	virtual ~ExcepcionCodigoExiste();
	string toString() const;
};


class ExcepcionCodigoNoExiste : public Excepciones {  //Excepcion que no existe un curso con algun codigo
public:
	ExcepcionCodigoNoExiste();
	virtual ~ExcepcionCodigoNoExiste();
	string toString() const;
};

 
class ExcepcionIDNoExiste : public Excepciones {   //Excepcion que no existe un deportista con algun ID
public:
	ExcepcionIDNoExiste();
	virtual ~ExcepcionIDNoExiste();
	string toString() const;
};


class ExcepcionIDExiste : public Excepciones {    //Excepcion que ya existe un deportista con algun ID 
public:
	ExcepcionIDExiste();
	virtual ~ExcepcionIDExiste();
	string toString() const;
};


class ExcepcionMatricula : public Excepciones {    //Excepcion matricula deportista
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
