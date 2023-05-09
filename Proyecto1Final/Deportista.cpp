#include "Deportista.h"

Deportista::Deportista(string ced, string nom, string tel, Fecha* fec)
	:cedula(ced), nombre(nom), telefono(tel), fecha(fec), estado("Activo"), cantGrupo(0) {}
Deportista::~Deportista() {}
