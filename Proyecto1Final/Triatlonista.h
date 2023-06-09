#pragma once
#include "Corredor.h"
#include "Nadador.h"
#include "Ciclista.h"


class Triatlonista : public Corredor {
private:
	int cantParticEnIronMan;
	int cantTriatGanados;
	Nadador* nadador;
	Ciclista* ciclista;
public:
	// Constructor
	Triatlonista(string, string, string, Fecha*, char, double, int, int, int, double, double, double, double);
	
	// Destructor
	virtual ~Triatlonista();

	// Metodos get's, set's, toString de la clase y metodos virtuales puros
	string getCedula();
	string getNombre();
	string getTelefono();
	Fecha* getFecha();
	char getSexo();
	double getEstatura();
	int getCantParticEnIronMan();
	int getCantTriatGanados();
	Nadador* getNadador();
	Ciclista* getCiclista();
	double getMasaMuscular();
	double getPeso();
	double getProcGrasaCorporal();
	int getHorasEntrenadas();
	double getTemPromedio();
	string getEstado();

	int getCantGrupo();
	void setCantGrupo(int);
	void sumar();
	void restar();

	void setEstado(string);
	void setHorasEntrenadas(int);
	void setTemPromedio(double);
	void setMasaMuscular(double);
	void setPeso(double);
	void setProcGrasaCorporal(double);
	void setCedula(string);
	void setNombre(string);
	void setTelefono(string);
	void setFecha(Fecha*);
	void setSexo(char);
	void setEstatura(double);
	void setCantParticEnIronMan(int);
	void setCantTriatGanados(int);
	void setNadador(Nadador*);
	void setCiclista(Ciclista*);

	string toString();
	string toStringCedNom();
};