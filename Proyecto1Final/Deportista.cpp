#include "Deportista.h"


// Desarrollo del constructor
Deportista::Deportista(string ced, string nom, string tel, Fecha* fec)
	:cedula(ced), nombre(nom), telefono(tel), fecha(fec), estado("Activo"), cantGrupo(0) {}

// Desarrollo del destructor
Deportista::~Deportista() { if (fecha != NULL) delete fecha; }
