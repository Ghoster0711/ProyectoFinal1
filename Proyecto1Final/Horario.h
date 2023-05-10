#pragma once
#pragma once
#include <iostream>
#include <sstream>
#include"Hora.h"

using namespace std;


class Horario {    //Horario del grupo 
private:
    char dia;    //Dia del horario 
    Hora* horaI;  //Hora de inicio  
    Hora* horaF;  //Hora de final 
public:
    Horario();
    Horario(char, Hora*, Hora*);
    virtual ~Horario();
    char getDia();
    Hora* getHoraI();
    Hora* getHoraF();
    void setDia(char);
    void setHoraI(Hora*);
    void setHoraF(Hora*);
    string toString();

};