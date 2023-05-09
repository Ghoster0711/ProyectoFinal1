#pragma once
#include <iostream>
#include <sstream>
#include "Grupo.h"
using namespace std;



class Curso {
protected:
    string codigo;
    string nombre;
    string descripcion;
    string nivel;
    int cantidadGrupos;
    Contenedor<Grupo>* COG;
public:
    Curso();
    Curso(string, string, string, string, int);
    virtual ~Curso();
    string getCodigo();
    string getNombre();
    string getDescription();
    string getNivel();
    int getCantidadGrupos();
    Contenedor<Grupo>* getCOG();

    void setCantidadGrupos(int);
    void setCodigo(string);
    void setNombre(string);
    void setDescripcion(string);
    void setNivel(string);
    string toString();
    string toStringListado();
    //void ingresarGrupo(Grupo*);
};
