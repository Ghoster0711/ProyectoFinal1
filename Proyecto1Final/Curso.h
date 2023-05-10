#pragma once
#include <iostream>
#include <sstream>
#include "Grupo.h"
using namespace std;


// Se crea la clase Curso
class Curso {
protected:
    string codigo;
    string nombre;
    string descripcion;
    string nivel;
    int cantidadGrupos;
    Contenedor<Grupo>* COG;  // Un contenedor para los Grupos
public:
    // Constructor
    Curso();

    // Construcctor parametrizado
    Curso(string, string, string, string, int);

    // Destructor
    virtual ~Curso();

    // Metodos get's set's y toString de la clase
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
};
