#include "Triatlonista.h"


// Desarrollo del constructor
Triatlonista::Triatlonista(string ced, string nom, string tel, Fecha* fec, char sex, double est, int cantP, int cantT, 
	int horasEntrenas, double temPro, double masa, double peso, double porcG)
	:Corredor(ced, nom, tel, fec, sex, est), cantParticEnIronMan(cantP), cantTriatGanados(cantT) {
	ciclista = new Ciclista(horasEntrenas, temPro);
	nadador = new Nadador(masa, peso, porcG);

}

// Desarrollo del destructor
Triatlonista::~Triatlonista() {
	if (ciclista != NULL)
		delete ciclista;
	if (nadador != NULL)
		delete nadador;
}

// Desarrollo de lo metodos get's set's toString y de los metodos virtuales puros
string Triatlonista::getCedula() { return cedula; }
string Triatlonista::getNombre() { return nombre; }
string Triatlonista::getTelefono() { return telefono; }
Fecha* Triatlonista::getFecha() { return fecha; }
char Triatlonista::getSexo() { return sexo; }
double Triatlonista::getEstatura() { return estatura; }
int Triatlonista::getCantParticEnIronMan() { return cantParticEnIronMan; }
int Triatlonista::getCantTriatGanados() { return cantTriatGanados; }
Nadador* Triatlonista::getNadador() { return nadador; }
Ciclista* Triatlonista::getCiclista() { return ciclista; }
double Triatlonista::getMasaMuscular() { return nadador->getMasaMuscular(); }
double Triatlonista::getPeso() { return nadador->getPeso(); }
double Triatlonista::getProcGrasaCorporal() { return nadador->getProcGrasaCorporal(); }
int Triatlonista::getHorasEntrenadas() { return ciclista->getHorasEntrenadas(); }
double Triatlonista::getTemPromedio() { return ciclista->getTemPromedio(); }
string Triatlonista::getEstado() { return estado; }

int Triatlonista::getCantGrupo() { return cantGrupo; }
void Triatlonista::setCantGrupo(int x) { cantGrupo = x; }
void Triatlonista::sumar() { cantGrupo++; }
void Triatlonista::restar() { cantGrupo--; }

void Triatlonista::setEstado(string est) { estado = est; }
void Triatlonista::setHorasEntrenadas(int horas) { ciclista->setHorasEntrenadas(horas); }
void Triatlonista::setTemPromedio(double tem) { ciclista->setTemPromedio(tem); }
void Triatlonista::setMasaMuscular(double mas) { nadador->setMasaMuscular(mas); }
void Triatlonista::setPeso(double pes) { nadador->setPeso(pes); }
void Triatlonista::setProcGrasaCorporal(double proc) { nadador->setProcGrasaCorporal(proc); }
void Triatlonista::setCedula(string ced) { cedula = ced; }
void Triatlonista::setNombre(string nom) { nombre = nom; }
void Triatlonista::setTelefono(string tel) { telefono = tel; }
void Triatlonista::setFecha(Fecha* fec) { fecha = fec; }
void Triatlonista::setSexo(char sex) { sexo = sex; }
void Triatlonista::setEstatura(double est) { estatura = est; }
void Triatlonista::setCantParticEnIronMan(int cantP) { cantParticEnIronMan = cantP; }
void Triatlonista::setCantTriatGanados(int cantT) { cantTriatGanados = cantT; }
void Triatlonista::setNadador(Nadador* nad) { nadador = nad; }
void Triatlonista::setCiclista(Ciclista* cic) { }

string Triatlonista::toString() {
	stringstream show;

	show << "Deportista >>" << endl
		<< "| Cedula: " << cedula << endl
		<< "| Nombre: " << nombre << endl
		<< "| Estado: " << estado << endl
		<< "| Telefono: " << telefono << endl
		<< "| Fecha de Nacimiento: " << fecha->toString() << endl
		<< "| Sexo: " << sexo << endl
		<< "| Estatura: " << estatura << endl
		<< "| Cantidad de participantes en Iron Man: " << cantParticEnIronMan << endl
		<< "| Cantidad de triatlonistas ganados: " << cantTriatGanados << endl;
	if (nadador != NULL)
		show << nadador->toString();
	if (ciclista != NULL)
		show << ciclista->toString();

	return show.str();
}

string Triatlonista::toStringCedNom()
{
	stringstream show;
	show << cedula << " " << nombre << endl;
	return show.str();
}
