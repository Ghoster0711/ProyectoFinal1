#pragma once
#include<iostream>
#include<sstream>

using namespace std;

class Excepciones {  //Case abstracta para la creacion de distintos tipos de Excepciones 
public:
	Excepciones();
	virtual ~Excepciones();
	virtual string toString() const = 0;   //Metodo virtual puro 
};


class ExcepcionCodigoExiste : public Excepciones {   //Clase Derivada: Excepcion que ya existe un curso con algun codigo
public:
	ExcepcionCodigoExiste();
	virtual ~ExcepcionCodigoExiste();
	string toString() const;
};


class ExcepcionCodigoNoExiste : public Excepciones {  //Clase Derivada: Excepcion que no existe un curso con algun codigo
public:
	ExcepcionCodigoNoExiste();
	virtual ~ExcepcionCodigoNoExiste();
	string toString() const;
};

 
class ExcepcionIDNoExiste : public Excepciones {   //Clase Derivada: Excepcion que no existe un deportista con algun ID
public:
	ExcepcionIDNoExiste();
	virtual ~ExcepcionIDNoExiste();
	string toString() const;
};


class ExcepcionIDExiste : public Excepciones {    //Clase Derivada: Excepcion que ya existe un deportista con algun ID 
public:
	ExcepcionIDExiste();
	virtual ~ExcepcionIDExiste();
	string toString() const;
};

 
class ExcepcionGrupoLleno : public Excepciones {    //Clase Derivada: Excepcion que un grupo esta lleno
public:
	ExcepcionGrupoLleno();
	virtual ~ExcepcionGrupoLleno();
	string toString() const;
};


class ExcepcionGrupoNoExiste : public Excepciones {    //Clase Derivada: Excepcion que no existe un grupo 
public:
	ExcepcionGrupoNoExiste();
	virtual ~ExcepcionGrupoNoExiste();
	string toString() const;

};


class ExcepcionDepoNoMatriculado : public Excepciones {    //Clase Derivada: Excepcion no existe deportista en x grupo
public:
	ExcepcionDepoNoMatriculado();
	virtual ~ExcepcionDepoNoMatriculado();
	string toString() const;
};


class ExcepcionRango : public Excepciones {    //Clase Derivada: Excepcion de que no se digito una opcion del menu 
public:
	ExcepcionRango();
	virtual ~ExcepcionRango();
	string toString() const;
};
 

