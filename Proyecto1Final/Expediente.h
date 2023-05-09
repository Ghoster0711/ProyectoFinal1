#pragma once
#include"Fecha.h"
#include<iostream>
#include<sstream>

using namespace std;

class Expediente {
private:
	string ID;
	string tel;
	string nombre;
	Fecha* ultimoPago;
	char sex;
public:
	Expediente();
	Expediente(string, string, string, Fecha*, char);
	virtual ~Expediente();
	
	string getID();
	string getTel();
	string getNombre();
	Fecha* getUltimoPago();
	char getSex();

	void setID(string);
	void setTel(string);
	void setNombre(string);
	void setFecha(Fecha*);
	void setSex(char);

};