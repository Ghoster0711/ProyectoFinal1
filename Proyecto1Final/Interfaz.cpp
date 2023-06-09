#include"Interfaz.h"
#include"Excepciones.h"


void Interfaz::bienvenida(Gym* gym) {
	int d, m, a;
	cout << "Bienvenido Gimnasio UNAfitness" << endl;
	cout << "Ingrese la fecha actual(dd mm aaaa) " << endl;
	cout << "Dia: "; d = entradaInt();
	cout << "Mes: "; m = entradaInt();	
	cout << "Anio: "; a = entradaInt();
	Fecha* fecha = new Fecha(d, m, a);
	gym->setFecha(fecha);
	system("pause");
}

void Interfaz::menu() {
	cout << "\t\t MENU PRINCIPAL" << endl;
	cout << "1. Administracion General" << endl
		<< "2. Control de Deportistas" << endl
		<< "3. Control de Cursos" << endl
		<< "4. Control de Grupos" << endl
		<< "5. Control Pagos" << endl
		<< "6. Guardar en Archivo y salir" << endl
        << endl << "Digite una opcion del menu: ";
}


//--------------------------------Administracion------------------------------------------

void Interfaz::administracionGeneral() {
	system("cls");
	cout << "\t\t ADMINISTRACION GENERAL" << endl
		<< "1. Nombre del Gimnasio" << endl
		<< "2. Monto de Mensualidad" << endl
		<< "3. Volver" << endl
		<< endl << "Digite una opcion del menu: ";
}

void Interfaz::nombreGym(Gym* gym) {
	system("cls");
	string nombre;
	cout << "Administracion General >> Nombre del Gimnasio" << endl << endl;
	cout << "Ingrese el nombre del gimnasio: ";
	ignorar();
	nombre = recibirGetline();
	gym->setNombre(nombre);
	system("pause");
}

void Interfaz::mensualidad(Gym* gym) {
	system("cls");
	double men;
	cout << "Administracion General >> Mensualidad del Gimnasio" << endl << endl;
	cout << "Ingrese la mensualidad: ";
	men = entradaDouble();
	gym->setMensualidad(men);
}


//-------------------------------Control de Deportistas---------------------------------------

void Interfaz::controlDeDeportistas() {
	system("cls");
	cout << "\t\t CONTROL DE DEPORTISTAS" << endl
		<< "1. Ingreso de nuevo deportista" << endl
		<< "2. Modificacion de deportista" << endl
		<< "3. Listado de deportistas" << endl
		<< "4. Detalle de deportista especifico" << endl
		<< "5. Volver" << endl
		<< endl << "Digite una opcion del menu: ";
}

void Interfaz::ingresaDeportista(Gym* gym) {
	string id, tel, nom;
	double est = 0, masa = 0, peso = 0, grasa = 0;
	int dia = 0, mes = 0, anio = 0, horas = 0, iron = 0, ganados = 0;
	char sex = 'n';
	if (gym->getCOC()->getPrimero() != NULL) {
		try {
			system("cls");
			cout << "Control de Deportistas >> Ingreso Nuevo Deportista" << endl << endl;
			cout << "Datos Generales >>" << endl;
			cout << "ID: ";
			cin >> id;
			if (gym->encontrarDeportista(id) == true)
				throw(ExcepcionIDExiste());
		}
		catch (ExcepcionIDExiste& e) {
			cout << e.toString() << endl;
			system("pause");
			return;
		}
		cout << "Telefono: ";
		cin >> tel;
		cout << "Nombre Completo: ";
		ignorar();
		nom = recibirGetline();
		cout << "Fecha de nacimiento(dd mm aaaa): " << endl;
		cout << "Dia: "; dia = entradaInt();
		cout << "Mes: "; mes = entradaInt();
		cout << "Anio: "; anio = entradaInt();
		cout << "Sexo(f/m): ";
		sex = entradaSexo();
		cout << "Horas Entrenamiento: ";
		horas = entradaInt();
		cout << "Cantidad de partidos IronMan: ";
		iron = entradaInt();
		cout << "Cantidad de triatlones ganados: ";
		ganados = entradaInt();
		cout << endl;
		cout << "Datos Biometricos basicos >>" << endl;
		cout << "Estatura: ";
		est = entradaDouble();
		cout << "Peso: ";
		peso = entradaDouble();
		cout << "Grasa Corporal: ";
		grasa = entradaDouble();
		cout << "Masa Muscular: ";
		masa = entradaDouble();
		Fecha* x = new Fecha(dia, mes, anio);
		Deportista* d = new Triatlonista(id, string(nom), tel, x, sex, est, iron, ganados, horas, 0.0, masa, peso, grasa);
		gym->getCOD()->ingresar(*d);
		cout << "Deportista ingresado!!" << endl;
	}
	else {
		system("cls");
		cout << "ERROR: No existen cursos" << endl;
	}
	system("pause");
}

void Interfaz::modificaDeportista(Gym* gym) {
	string id;
	int op;
	try {
		system("cls");
		cout << "Control de Deportistas >> Modificar Deportista" << endl << endl;
		cout << "Ingrese el ID del Deportista: ";
		cin >> id;
		if (gym->encontrarDeportista(id) != true)
			throw(ExcepcionIDNoExiste());
	}
	catch (ExcepcionIDNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	do {
		try {
			system("cls");
			cout << "Control de Deportistas >> Modificar Deportista" << endl << endl
				<< "Deportista encontrado!!" << endl << endl
				<< "Que dato desea modificar: " << endl
				<< "1. Nombre" << endl
				<< "2. Telefono" << endl
				<< "3. Fecha de nacimiento" << endl
				<< "4. Sexo" << endl
				<< "5. Estatura" << endl
				<< "6. Peso" << endl
				<< "7. Porcentaje de grasa corporal" << endl
				<< "8. Porcentaje de grasa muscular" << endl
				<< "9. Estado" << endl
				<< "10. Horas de entrenamiento" << endl
				<< "10. Cantidad de partidos Iron Man" << endl
				<< "12. Cantidad de triatlones ganados" << endl
				<< "13. Volver" << endl
				<< "Digite una opcion del menu: ";
			op = entradaInt();
			if (op < 1 || op > 13)
				throw(ExcepcionRango());
		}
		catch (ExcepcionRango& e) {
			cout << e.toString() << endl;
			system("pause");
		}
		modificacionesDeportista(gym->retornaDeportista(id), op);
	} while (op != 13);
}

void Interfaz::modificacionesDeportista(Deportista* depo, int op) {
	string text;
	double num1 = 0;
	int num2 = 0, d = 0, m = 0,a = 0;
	char s = 'n';
	switch (op) {
	case 1: {
		cout << "Digite el nuevo nombre: ";
		ignorar();
		text = recibirGetline();
		depo->setNombre(text); 
		cout << "Hecho!!" << endl;
		system("pause");

	}break;
	case 2: {
		cout << "Digite el nuevo numero de telefono: ";
		ignorar();
		text = recibirGetline();
		depo->setTelefono(text);
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	case 3: {
		cout << "Digite la nueva fecha de nacimiento(dd mm aaaa): " << endl;
		cout << "Dia: "; d = entradaInt();
		cout << "Mes: "; m = entradaInt();
		cout << "Anio: "; a = entradaInt();
		depo->setFecha(new Fecha(d, m, a));
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	case 4: {
		cout << "Digite el nuevo sexo('f''m'): ";
		s = entradaSexo();
		depo->setSexo(s);
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	case 5: {
		cout << "Digite la nueva estatura: ";
		num1 = entradaDouble();
		depo->setEstatura(num1);
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	case 6: {
		cout << "Digite el nuevo peso: ";
		num1 = entradaDouble();
		depo->setPeso(num1);
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	case 7: {
		cout << "Digite el nuevo porcentaje de grasa corporal: ";
		num1 = entradaDouble();
		depo->setProcGrasaCorporal(num1);
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	case 8: {
		cout << "Digite el nuevo porcentaje de masa muscular: ";
		num1 = entradaDouble();
		depo->setMasaMuscular(num1);
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	case 9: {
		cout << "Digite el estado del deportista (Activo/Inactivo)";
		text = entradaActivoInactivo();
		depo->setEstado(text);
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	case 10: {
		cout << "Digite las nuevas horas de entrenamiento: ";
		num2 = entradaInt();
		depo->setHorasEntrenadas(num2);
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	case 11: {
		cout << "Digite la nueva cantidad de partidos Iron Main: ";
		num2 = entradaInt();
		depo->setCantParticEnIronMan(num2);
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	case 12: {
		cout << "Digite la nueva cantidad de triatlones ganados: ";
		num2 = entradaInt();
		depo->setCantTriatGanados(num2);
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	}
}

void Interfaz::listaDeporsitas(Gym* gym) {

	int op = 0;
	if(gym->getCOHP()->getPrimero() != NULL)
		gym->deportistasMorosos();
	do {
		try {
			system("cls");
			cout << "Control de Deportistas >> Lista Deportistas" << endl << endl
				<< "1. Listado general" << endl
				<< "2. Listado de deportistas activos" << endl
				<< "3. Listado de deportistas inactivos" << endl
				<< "4. Listado de deportistas en morosidad" << endl
				<< "5. Volver" << endl
				<< endl << "Digite una opcion del menu: ";
			op = entradaInt();
			if (op < 1 || op > 5)
				throw(ExcepcionRango());
		}
		catch (ExcepcionRango& e) {
			cout << e.toString() << endl;
			system("pause");
		}
		switch (op) {
		case 1: {
			system("cls");
			cout << "Control de Deportistas >> Lista Deportistas >> Listado General" << endl << endl;
			gym->listarDeportistas();
			system("pause");
		}break;
		case 2: {
			system("cls");
			cout << "Control de Deportistas >> Lista Deportistas >> Listado de Deportistas Activos" << endl << endl;
			gym->listarDeportistasActivos();
			system("pause");
		}break;
		case 3: {
			system("cls");
			cout << "Control de Deportistas >> Lista Deportistas >> Listado de Deportistas Inactivos" << endl << endl;
			gym->listarDeportistasInactivos();
			system("pause");
		}break;
		case 4: {
			system("cls");
			cout << "Control de Deportistas >> Lista Deportistas >> Listado de Deportistas en Morosidad" << endl << endl;
			gym->listarDeportistasMorosos();
			system("pause");
		}break;
		}
	} while (op != 5);
	
}

void Interfaz::detalleDeportistaEspecifico(Gym* gym) {
	string id;
	try {
		system("cls");
		cout << "Control de Deportistas >> Detalle de Deportista Especifico" << endl << endl;
		cout << "Digite el ID del Deportista: ";
		cin >> id;
		if (gym->encontrarDeportista(id) != true)
			throw(ExcepcionIDNoExiste());
	}
	catch (ExcepcionIDNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	Deportista* depo = gym->retornaDeportista(id);
	cout << endl;
	cout << "Deportista encontrado!!" << endl << endl;
	cout << "Datos Generales >> " << endl
		<< "	ID: " << depo->getCedula() << endl
		<< "	Nombre:" << depo->getNombre() << endl
		<< "	Estado:" << depo->getEstado() << endl
		<< "    Telefono:" << depo->getTelefono() << endl
		<< "    Fecha de nacimiento: " << depo->getFecha() << endl
		<< "    Sexo: " << depo->getSexo() << endl
		<< "	Horas entrenamiento: " << depo->getHorasEntrenadas() << endl
		<< "	Cantidad de partidos IronMan: " << depo->getCantParticEnIronMan() << endl
		<< "    Cantidad de tratlones ganados: " << depo->getCantTriatGanados() << endl
		<< endl
		<< "Datos biometricos basicos >> " << endl
		<< "    Estatura: " << depo->getEstatura() << endl
		<< "	Peso: " << depo->getPeso() << endl
		<< "	Grasa Corporal: " << depo->getProcGrasaCorporal() << "%" << endl
		<< "    Masa muscular: " << depo->getMasaMuscular() << "%" << endl
		<< endl;
	if (gym->getCOC()->getPrimero() != NULL) {
		cout << "Grupos matriculados:" << endl;
		cout << gym->encontrarDeportistaEnGrupos(id);
	}
	else
		cout << "No tiene grupos matriculados" << endl;
	system("pause");
}

//--------------------------------Control de Cursos------------------------------------------

void Interfaz::controlDeCursos() {
	system("cls");
	cout << "\t\t CONTROL DE CURSOS" << endl
		<< "1. Ingreso de nuevo curso" << endl
		<< "2. Reporte de curso especifico" << endl
		<< "3. Modificacion de curso especifico" << endl
		<< "4. Volver" << endl
		<< endl << "Digite una opcion del menu: ";
}

void Interfaz::ingresarCurso(Gym* gym) {
	string cod, nom, niv, descrip;
	int cant = 0;
	try {
		system("cls");
		cout << "Control de Cursos >> Ingreso Nuevo Curso" << endl << endl;
		cout << "Digite el codigo del curso: ";
		cin >> cod;
		if (gym->encontrarCurso(cod) == true)
			throw(ExcepcionCodigoExiste());
	}
	catch (ExcepcionCodigoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	cout << "Digite el nombre del curso: ";
	cin >> nom;
	cout << "Digite el nivel: ";
	cin >> niv;
	cout << "Cantidad de grupos: ";
	cant = entradaInt();
	cout << "Descripcion: ";
	ignorar();
	descrip = recibirGetline();
	Curso* curso = new Curso(cod, nom, descrip, niv, cant);
	gym->getCOC()->ingresar(*curso);
	cout << "Curso ingresado!!" << endl;
	system("pause");

}

void Interfaz::reporteDeCurso(Gym* gym) {
	string cod;
	try {
		system("cls");
		cout << "Control de Cursos >> Reporte de Curso Especifico" << endl << endl;
		cout << "Listado de cursos: " << endl;
		gym->listadoCurso();
		cout << endl;
		cout << "Digite el codigo del curso: ";
		cin >> cod;
		if (gym->encontrarCurso(cod) != true)
			throw(ExcepcionCodigoNoExiste());
	}
	catch (ExcepcionCodigoNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	cout << "Curso encontrado!!" << endl;
	cout << "A continuacion se muestra la informacion del curso " << cod;
	cout << endl << endl;
	cout << gym->retornaCurso(cod)->toString() << endl; 
	cout << "Detalle de grupos abiertos para el curso:" << endl;
	cout << "# Grupo     	Cupo		Cantidad" << endl;
	gym->listadoGrupos(gym->retornaCurso(cod));
	system("pause");
}

void Interfaz::modificarCurso(Gym* gym) {
	string cod;
	int op;
	try {
		system("cls");
		cout << "Control de Cursos >> Modificacion de Curso Especifico" << endl << endl;
		cout << "Digite el codigo del curso: ";
		cin >> cod;
		if (gym->encontrarCurso(cod) != true)
			throw(ExcepcionCodigoNoExiste());
	}
	catch (ExcepcionCodigoNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	do {
		try {
			system("cls");
			cout << "Control de Cursos >> Modificacion de Curso Especifico" << endl << endl
				<< "Curso encontrado!!" << endl << endl
				<< "Cual dato desea modificar: " << endl
				<< "1. Codigo de curso" << endl
				<< "2. Nombre del curso" << endl
				<< "3. Nivel" << endl
				<< "4. Descripcion" << endl
				<< "5. Cantidad de grupos" << endl
				<< "6. Volver" << endl
				<< "Digite una opcion del menu: ";
			op = entradaInt();
			if (op < 1 || op > 6)
				throw(ExcepcionRango());
		}
		catch (ExcepcionRango& e) {
			cout << e.toString() << endl;
			system("pause");
		}
		modificacionesCurso(gym->retornaCurso(cod), op);
	} while (op != 6);
}

void Interfaz::modificacionesCurso(Curso* curso, int op) {
	string text;
	int num;
	switch (op) {
	case 1: {
		cout << "Digite el nuevo codigo:" << endl;
		cin >> text;
		curso->setCodigo(text);
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	case 2: {
		cout << "Digite el nuevo nombre:" << endl;
		ignorar();
		text = recibirGetline();
		curso->setNombre(text);
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	case 3: {
		cout << "Digite el nuevo nivel:" << endl;
		cin >> text;
		curso->setNivel(text);
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	case 4: {
		cout << "Digite la nueva descripcion:" << endl;
		ignorar();
		text = recibirGetline();
		curso->setDescripcion(text);
		cout << "Hecho!!" << endl;
		system("pause");
	}break;
	case 5: {
		cout << "Digite la nueva cantidad de grupos:" << endl;
		num = entradaInt();
		if (curso->getCantidadGrupos() < num) {
			curso->setCantidadGrupos(num);
			cout << "Hecho!!" << endl;
		}
		else
			cout << "No se puede cambiar a esa cantidad" << endl;
	}break;
	}
}


//--------------------------------Control de Grupos------------------------------------------

void Interfaz::controlDeGrupos() {
	system("cls");
	cout << "\t\t CONTROL DE GRUPOS" << endl
		<< "1. Ingreso de nuevo grupo" << endl
		<< "2. Modificacion de grupo especifico" << endl
		<< "3. Matricula en grupo especifico" << endl
		<< "4. Reporte de grupo especifico" << endl
		<< "5. Reporte deportistas matriculados en grupo" << endl
		<< "6. Cancelacion de matricula en grupo" << endl
		<< "7. Volver" << endl
		<< endl << "Digite una opcion del menu: ";
	
}

void Interfaz::ingresarGrupo(Gym* gym) {
	string cod, id, nom;
	int cup, dia, mes, anio, semas, h1, m1, h2, m2;
	char d;
	try {
		system("cls");
		cout << "Control de Grupos >> Ingreso de Grupo" << endl << endl;
		cout << "Listado de cursos: " << endl;

		gym->listadoCurso();

		cout << "Digite el codigo del curso: ";
		cin >> cod;
		if (gym->encontrarCurso(cod) != true)
			throw(ExcepcionCodigoNoExiste());
	}
	catch (ExcepcionCodigoNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	cout << "Curso encontrado!!" << endl << endl;
	cout << "Digite el ID del Instructor: ";
	cin >> id;
	cout << "Digite el nombre del Instructor: ";
	ignorar();
	nom = recibirGetline();
	cout << "Digite el cupo maximo: ";
	cup = entradaInt();;
	cout << "Fecha de inicio(dd mm aaaa): " << endl;
	cout << "Dia: "; dia = entradaInt();
	cout << "Mes: "; mes = entradaInt();
	cout << "Anio: "; anio = entradaInt();
	cout << "Semanas de duracion: ";
	semas = entradaInt();
	cout << "Horario: " << endl;
	cout << "Digite el dia de la semana (l,k,m,j,v,s,d): ";
	d = entradaSemana();
	cout << "Digite la hora de inicio (en hora militar): " << endl;
	cout << "Hora: "; h1 = entradaInt();
	cout << "Minuto: "; m1 = entradaInt();
	cout << "Digite la hora de finalizacion (en hora militar): " << endl;
	cout << "Hora: "; h2 = entradaInt();
	cout << "Minuto: "; m2 = entradaInt();

	Fecha* fechaInicio = new Fecha(dia, mes, anio);
	Hora* horaInicio = new Hora(h1, m1);
	Hora* horaFinal = new Hora(h2, m2);
	Horario* horario = new Horario(d, horaInicio, horaFinal);
	Grupo* grupo = new Grupo(id, nom, cup, semas, fechaInicio, horario, gym->retornaCurso(cod)->getCOG()->getCantidad() + 1);
	gym->retornaCurso(cod)->getCOG()->ingresar(*grupo);
	cout << "Se ha creado el grupo " << gym->retornaCurso(cod)->getCOG()->getCantidad() << endl;


	system("pause");
	
}

void Interfaz::modificarGrupo(Gym* gym) {
	int op,num;
	string cod;
	
	try {
		system("cls");
		cout << "Control de Grupos >> Modificacion de Grupo Especifico" << endl << endl;
		cout << "Listado de cursos: " << endl;

		 gym->listadoCurso();

		cout << "Digite el codigo del curso: ";
		cin >> cod;
		if (gym->encontrarCurso(cod) != true)
			throw(ExcepcionCodigoNoExiste());
	}
	catch (ExcepcionCodigoNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	try {
		system("cls");
		cout << "Control de Grupos >> Modificacion de Grupo Especifico" << endl << endl;
		cout << "Curso encontrado!!" << endl << endl;
		cout << "Digite el numero de grupo: ";
		num = entradaInt();
		if(gym->encontrarGrupo(gym->retornaCurso(cod), num) != true) // Si NO existe el numero de grupo en el curso
			throw(ExcepcionGrupoNoExiste());
	}
	catch (ExcepcionGrupoNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	do {
		try {
			system("cls");
			cout << "Control de Grupos >> Modificacion de Grupo Especifico" << endl << endl;
			cout << "Curso encontrado!!" << endl;
			cout << "Grupo encontrado!!" << endl << endl;
			cout << "Que desea modificar: " << endl
				<< "1. ID del Instructor " << endl
				<< "2. Nombre del Instructor " << endl
				<< "3. Cupo maximo " << endl
				<< "4. Fecha de inicio " << endl
				<< "5. Semanas de duracion " << endl
				<< "6. Dia de la semana" << endl
				<< "7. Hora de inicio" << endl
				<< "8. Hora de finalizacion" << endl
				<< "9. Volver" << endl
				<< "Digite una opcion del menu: ";
			op = entradaInt();
			if (op < 1 || op > 9)
				throw(ExcepcionRango());
		}
		catch (ExcepcionRango& e) {
			cout << e.toString();
			system("pause");
		}
	   modificacionesGrupo(gym->retornaGrupo(gym->retornaCurso(cod), num), op);  
	} while (op != 9);
}

void Interfaz::modificacionesGrupo(Grupo* grupo, int op) {
	string text;
	int num = 0, d = 0, m = 0, a = 0;
	char letra;
	switch (op) {
	case 1:
		cout << "Digite el nuevo ID del instructor:" << endl;
		cin >> text;

		grupo->setID(text);
		cout << "Hecho!!" << endl;
		system("pause");
		break;
	case 2:
		cout << "Digite el nuevo nombre del instructor:" << endl;
		ignorar();
		text = recibirGetline();
		grupo->setNombre(text);
		cout << "Hecho!!" << endl;
		system("pause");
		break;
	case 3:
		cout << "Digite el nuevo cupo maximo:" << endl;
		num = entradaInt();
		grupo->setCupoMaximo(num);
		cout << "Hecho!!" << endl;
		system("pause");
		break;
	case 4:
		cout << "Digite la nueva fecha de inicio(dd mm aaaa):" << endl;
		cout << "Dia: "; d = entradaInt();
		cout << "Mes: "; m = entradaInt();
		cout << "Anio: "; a = entradaInt();
		grupo->setFecha(new Fecha(d, m, a));
		cout << "Hecho!!" << endl;
		system("pause");
		break;
	case 5:
		cout << "Digite la nueva cantidad de semanas de duracion:" << endl;
		num = entradaInt();
		grupo->setDurarcion(num);
		cout << "Hecho!!" << endl;
		system("pause");
		break;
	case 6:
		cout << "Digite el nuevo dia de la semana (l,k,m,j,v,s,d):" << endl;
		letra = entradaSemana();
		grupo->getHorario()->setDia(letra);
		cout << "Hecho!!" << endl;
		system("pause");
		break;
	case 7:
		cout << "Digite la nueva hora de incio:" << endl;
		cout << "Hora: "; d = entradaInt();
		cout << "Minuto: "; m = entradaInt();
		grupo->getHorario()->setHoraI(new Hora(d, m));
		cout << "Hecho!!" << endl;
		system("pause");
		break;
	case 8:
		cout << "Digite la nueva hora de finalizacion:" << endl;
		cout << "Hora: "; d = entradaInt();
		cout << "Minuto: "; m = entradaInt();
		grupo->getHorario()->setHoraF(new Hora(d, m));
		cout << "Hecho!!" << endl;
		system("pause");
	}
}

void Interfaz::matricularEnGrupo(Gym* gym) {
	string id, cod;
	int dia, mes, anio;
	int op;
	bool acceso = true;
	try {
		system("cls");
		cout << "Control de Grupos >> Matricula en Grupo Especifico" << endl << endl;
		cout << "Digite el ID del deportista: ";
		cin >> id;
		if (gym->encontrarDeportista(id) != true)
			throw(ExcepcionIDNoExiste());
	}
	catch (ExcepcionIDNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	if (gym->retornaDeportista(id)->getEstado() == "Activo" && gym->retornaDeportista(id)->getCantGrupo() < 4) {
		try {
			system("cls");
			cout << "Control de Grupos >> Matricula en Grupo Especifico" << endl << endl;
			cout << "Deportista encontrado!!" << endl;
			cout << "Listado de cursos: " << endl;

			gym->listadoCurso();

			cout << "Digite el codigo del curso: ";
			cin >> cod;
			if (gym->encontrarCurso(cod) != true)
				throw(ExcepcionCodigoNoExiste());
		}
		catch (ExcepcionCodigoNoExiste& e) {
			cout << e.toString() << endl;
			system("pause");
			return;
		}
		if (gym->seEncontraDeportistaEnGrupos(cod, id) != true) {
			try {
				system("cls");
				cout << "Control de Grupos >> Matricula en Grupo Especifico" << endl << endl;
				cout << "Deportista encontrado!!" << endl;
				cout << "Curso encontrado!!" << endl << endl;
				cout << "Para el curso deseado existen los siguientes grupos disponibles: " << endl;
				cout << "# Grupo         Dia           Horario             Cupo           Cantidad" << endl;
				gym->listadoGruposParaDepo(gym->retornaCurso(cod));
				cout << "Digite el numero de grupo deseado: " << endl;
				op = entradaInt();
				if (gym->encontrarGrupo(gym->retornaCurso(cod), op) != true)
					throw(ExcepcionGrupoNoExiste());
				Grupo* grupo = gym->retornaGrupo(gym->retornaCurso(cod), op);
				if (grupo->getListaDepo()->getCantidad() >= grupo->getCupoMaximo())
					throw(ExcepcionGrupoLleno());
			}
			catch (ExcepcionGrupoNoExiste& e) {
				cout << e.toString() << endl;
				system("pause");
				return;
			}
			catch (ExcepcionGrupoLleno& e) {
				cout << e.toString() << endl;
				system("pause");
				return;
			}
			cout << "Grupo encontrado!!" << endl;
			Grupo* grupo = gym->retornaGrupo(gym->retornaCurso(cod), op);
			cout << "Digite la fecha de matricula (dd mm aaaa):" << endl;
			cout << "Dia: "; dia = entradaInt();
			cout << "Mes: "; mes = entradaInt();
			cout << "Anio: "; anio = entradaInt();
			Fecha* fecha = new Fecha(dia, mes, anio);

			grupo->getListaDepo()->clonDepo(gym->retornaDeportista(id));
			gym->retornaDeportista(id)->sumar();
			cout << "Deportista matriculado!!" << endl;
		}
		else
			cout << "El Deportista ya existe en este curso" << endl;
	}
	else
		cout << "No se puede matricular porque ya esta al limite de los cursos permitidos por deportista o no se encuentra activo" << endl;
	system("pause");
}

void Interfaz::reporteDeGrupo(Gym* gym) {
	string cod;
	int op;
	try {
		system("cls");
		cout << "Control de Grupos >> Reporte de Grupo Especifico" << endl << endl;
		cout << "Listado de cursos: " << endl;

		gym->listadoCurso();

		cout << "Digite el codigo del curso: ";
		cin >> cod;
		if (gym->encontrarCurso(cod) != true)
			throw(ExcepcionCodigoNoExiste());
	}
	catch (ExcepcionCodigoNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	try {
		system("cls");
		cout << "Control de Grupos >> Reporte de Grupo Especifico" << endl << endl;
		cout << "Curso encontrado!!" << endl << endl;
		cout << "Listado de grupos para el curso seleccionado: " << endl;
		gym->listaNumerosGrupos(gym->retornaCurso(cod));
		cout << "Digite el numero de grupo deseado: " << endl;
		op = entradaInt();
		if (gym->encontrarGrupo(gym->retornaCurso(cod), op) != true)
			throw(ExcepcionGrupoNoExiste());
	}
	catch (ExcepcionGrupoNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	cout << "Grupo encontrado!!" << endl;
	cout << "A continuacion se muestra la infomacion del grupo #" << op << " del curso " << cod << ":" << endl;
	cout << "Nombre del curso: " << gym->retornaCurso(cod)->getNombre() << endl
	<< gym->retornaGrupo(gym->retornaCurso(cod), op)->toString();
	system("pause");

}

void Interfaz::reporteDeportistasEnGrupo(Gym* gym) {
	string cod;
	int op;
	try {
		system("cls");
		cout << "Control de Grupos >> Reporte Deportistas Matriculados en Grupo" << endl << endl;

		gym->listadoCurso();

		cout << "Digite el codigo del curso: ";
		cin >> cod;
		if (gym->encontrarCurso(cod) != true)
			throw(ExcepcionCodigoNoExiste());
	}
	catch (ExcepcionCodigoNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	try {
		system("cls");
		cout << "Control de Grupos >> Reporte Deportistas Matriculados en Grupo" << endl <<endl;
		cout << "Curso encontrado!!" << endl << endl;
		cout << "Listado de grupos para el curso seleccionado: " << endl;
		gym->listaNumerosGrupos(gym->retornaCurso(cod));
		cout << "Digite el numero de grupo deseado: " << endl;
		op = entradaInt();
		if (gym->encontrarGrupo(gym->retornaCurso(cod), op) != true)
			throw(ExcepcionGrupoNoExiste());
	}
	catch (ExcepcionGrupoNoExiste& e) {
		   cout << e.toString() << endl;
		   system("pause");
		   return;
	}
	cout << "Grupo encontrado!!" << endl << endl;
	cout << "Listado de matriculados en el grupo " << gym->retornaGrupo(gym->retornaCurso(cod), op)->getNumGrupo() << " del curso " << cod << endl;
		gym->retornaGrupo(gym->retornaCurso(cod), op)->getListaDepo()->listarDeportistasCedNom();
		system("pause");
}

void Interfaz::cancelacionDeMatriculaEnGrupo(Gym* gym) {
	string id, cod, idd;
	int op;
	try {
		system("cls");
		cout << "Control de Grupos >> Cancelacion de matricula en grupo" << endl << endl;
		cout << "Digite el ID del deportistas: " << endl;
		cin >> id;
		if (gym->encontrarDeportista(id) != true)
			throw(ExcepcionIDNoExiste());
	}
	catch (ExcepcionIDNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	try {
		system("cls");
		cout << "Control de Grupos >> Cancelacion de matricula en grupo" << endl << endl;
		cout << "Deportista encontrado!!" << endl;
		gym->listadoCurso();
		cout << "Digite el codigo de curso: " << endl;
		cin >> cod;
		if (gym->encontrarCurso(cod) != true)
			throw(ExcepcionCodigoNoExiste());
	}
	catch (ExcepcionCodigoNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	if (gym->seEncontraDeportistaEnGrupos(cod, id) == true) {
		try {
			system("cls");
			cout << "Control de Grupos >> Cancelacion de matricula en grupo" << endl;
			cout << "Deportista encontrado!!" << endl;
			cout << "Curso encontrado!!" << endl << endl;
			cout << "Listado de grupos para el curso seleccionado: " << endl;
			gym->listaNumerosGrupos(gym->retornaCurso(cod));
			cout << "Digite el numero de grupo deseado: " << endl;
			op = entradaInt();
			if (gym->encontrarGrupo(gym->retornaCurso(cod), op) != true)
				throw(ExcepcionGrupoNoExiste());
			Grupo* grupo = gym->retornaGrupo(gym->retornaCurso(cod), op);
			if (grupo->getListaDepo()->encontrarDeportista(id) != true)
				throw(ExcepcionDepoNoMatriculado());
		}
		catch (ExcepcionGrupoNoExiste& e) {
			cout << e.toString() << endl;
			system("pause");
			return;
		}
		catch (ExcepcionDepoNoMatriculado& e) {
			cout << e.toString() << endl;
			system("pause");
			return;
		}
		cout << "Grupo encontrado!!" << endl;
		Grupo* grupo = gym->retornaGrupo(gym->retornaCurso(cod), op);
		grupo->getListaDepo()->deleteDepo(id);
		cout << "Se ha des-matriculado el deportista " << id << endl;
		gym->retornaDeportista(id)->restar();
	}
	system("pause");
}


//--------------------------------Control de Pagos------------------------------------------

void Interfaz::controlPagos() {
	system("cls");
	cout << "\t\t CONTROL PAGOS" << endl
		<< "1. Registro de nuevo pago" << endl
		<< "2. Reporte de pagos por deportista" << endl
		<< "3. Volver" << endl
		<< endl << "Digite una opcion del menu: ";
}

void Interfaz::registroNuevoPago(Gym* gym) {
	string id;
	int cuotas;
	try {
		system("cls");
		cout << "Fecha actual: " << gym->getFecha()->toString() << endl;
		cout << "Control de Pagos >> Registro de Nuevo Pago" << endl << endl;
		cout << gym->getFecha()->toString() << endl;
		cout << "Digite el ID del deportista: ";
		cin >> id;
		if (gym->encontrarDeportista(id) != true)
			throw(ExcepcionIDNoExiste());
	}
	catch (ExcepcionIDNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
		return;
	}
	cout << "Deportista encontrado!!" << endl << endl;
	cout << "Cuantas cuotas desea cancelar o pagar: ";
	cuotas = entradaInt();
	cout << "Monto a pagar: " << gym->getMensualidad() * cuotas << "(" << gym->getMensualidad()
		<< " x " << cuotas << ")" << endl;
	cout << "Excelente se han cancelado las siguientes cuotas: " << endl;
	cout << gym->calcularCuotasCanceladas(id, cuotas) << endl;

	cout << "El deportista " << gym->retornaDeportista(id)->getNombre() << " tiene hasta el mes de "
		<< gym->registroNuevoPago(id, cuotas) << endl;
	system("pause");


}

void Interfaz::reporteDePagosDeportista(Gym* gym) {
	string id;
	try {
		system("cls");
		cout << "Control de Pagos >> Reporte de Pagos por Deportista" << endl << endl;
		cout << gym->getFecha()->toString() << endl;
		cout << "Digite el ID del deportista: ";
		cin >> id;
		if (gym->encontrarDeportista(id) != true)
			throw(ExcepcionIDNoExiste());
	}
	catch (ExcepcionIDNoExiste& e) {
		cout << e.toString() << endl;
		system("pause");
	}
	cout << "Deportista encontrado!!" << endl << endl;
	cout << "A continuacion se detalla el historial de pagos: " << endl;
	cout << gym->reportePagosDeportista(id) << endl;
	system("pause");
}

