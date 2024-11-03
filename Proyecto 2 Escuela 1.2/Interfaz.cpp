#include "Interfaz.h"

void Interfaz::mostarBanner(){
	std::cout << "=====================================\n";
	std::cout << "||    Proyecto 2 - Escuela          ||\n";
	std::cout << "||    Version 1.0                   ||\n";
	std::cout << "||    Autores:                      ||\n";
	std::cout << "||    David Gonzalez                ||\n";
	std::cout << "||    Brandon Brenes                ||\n";
	std::cout << "||    Universidad Nacional de Costa ||\n";
	std::cout << "=====================================\n";
	system("pause");
	std::cout << "Presione ENTER para continuar...\n";
	system("cls");
}

int Interfaz::menuPrincipal(){
	system("cls");
	int opcion = 0;
	std::cout << "========= Eureka AI School ========= \n";
	std::cout << "========== Menu Principal ==========\n";
	std::cout << "1-Submenu Administracion\n";
	std::cout << "2-Submenu Matricula\n";
	std::cout << "3-Submenu Busqueda e Informacion\n";
	std::cout << "4-Guardar Archivos\n";
	std::cout << "0-Salir\n";
	std::cout << "=====================================\n";
	std::cin >> opcion;
	return opcion;
	system("cls");
}

int Interfaz::submenuAdmin(){
	system("cls");
	int opcion = 0;
	std::cout << "===== Submenu Administracion =====\n";
	std::cout << "1-Ingresar Profesor\n";
	std::cout << "2-Ingresar Estudiante\n";
	std::cout << "3-habilitar Periodo Lectivo\n";//Periodo 1: de enero a marzo ,Periodo 2: de abril a junio, Periodo 3 : de julio a setiembre Periodo 4 : de octubre a diciembre
	std::cout << "4-Ingresar Curso\n";
	std::cout << "5-Crear Grupos de Cursos\n";
	std::cout << "6-Asociar Profesor a Grupo\n";
	std::cout << "0-Regresar al Menu Principal\n";
	std::cout << "===================================\n";
	std::cin >> opcion;
	return opcion;
	system("cls");
}

int Interfaz::submenuMatricula(){
	system("cls");
	int opcion = 0;
	std::cout << "========= Submenu Matricula =========\n";
	std::cout << "1-Matricular Estudiante\n";
	std::cout << "2-Dar de Baja Estudiante\n";
	std::cout << "0-Regresar al Menu Principal\n";
	std::cout << "=====================================\n";
	std::cin >> opcion;
	return opcion;
	system("cls");
}

int Interfaz::submenuBusqueda(){
	system("cls");
	int opcion = 0;
	std::cout << "== Submenu Busqueda e Informacion ==\n";
	std::cout << "1-Informe Profesores Registrados\n";
	std::cout << "2-Informe Estudiantes Registrados\n";
	std::cout << "3-Informe Cursos Matriculados por un Estudiante\n";
	std::cout << "4-Informe Profesor Especifico\n";
	std::cout << "5-Informe Periodos Habilitados para el Año\n";
	std::cout << "6-Informe Grupo Especifico\n";
	std::cout << "0-Regresar al Menu Principal\n";
	std::cout << "=====================================\n";
	std::cin >> opcion;
	return opcion;
	system("cls");
}

Profesor* Interfaz::ingresarProfesor(){
	system("cls");
	std::string nombre, apellido, CI, telefono, correo;
	std::cout << "Ingrese el Nombre del Profesor: ";
	std::cin >> nombre;
	std::cout << "Ingrese la Cedula del Profesor: ";
	std::cin >> CI;
	std::cout << "Ingrese el Telefono del Profesor: ";
	std::cin >> telefono;
	std::cout << "Ingrese el Correo del Profesor: ";
	std::cin >> correo;
	std::cout << "Ingrese la Grado Academico del Profesor: ";
	std::string gradoAcademico;
	std::cin >> gradoAcademico;
	return new Profesor(nombre, CI, telefono, correo, gradoAcademico);
	system("cls");
}

Estudiante* Interfaz::ingresarEstudiante(){
	system("cls");
	std::string nombre, apellido, CI, telefono, correo, especialidad;
	std::cout << "Ingrese el Nombre del Estudiante: ";
	std::cin >> nombre;
	std::cout << "Ingrese la Cedula del Estudiante: ";
	std::cin >> CI;
	std::cout << "Ingrese el Telefono del Estudiante: ";
	std::cin >> telefono;
	std::cout << "Ingrese el Correo del Estudiante: ";
	std::cin >> correo;
	std::cout << "Ingrese la especialidad del Estudiante: ";
	std::cin >> especialidad;
	return new Estudiante(nombre, CI, telefono, correo, especialidad);
	
	system("cls");
}

int Interfaz::habilitarPeriodoLectivo(){
	system("cls");
	int opcion = 0;
	std::cout << "===== Habilitar Periodo Lectivo =====\n";
	std::cout << "1-Periodo 1: de enero a marzo\n";
	std::cout << "2-Periodo 2: de abril a junio\n";
	std::cout << "3-Periodo 3: de julio a setiembre\n";
	std::cout << "4-Periodo 4: de octubre a diciembre\n";
	std::cout << "0-Regresar al Menu Principal\n";
	std::cout << "=====================================\n";
	std::cin >> opcion;
	return opcion;
	system("cls");
}

Curso* Interfaz::ingresarCurso(){
	system("cls");
	std::string nombre, codigo;
	int creditos;
	double costo;
	std::cout << "Ingrese el Nombre del Curso: ";
	std::cin >> nombre;
	std::cout << "Ingrese el Codigo del Curso: ";
	std::cin >> codigo;
	std::cout << "Ingrese los Creditos del Curso: ";
	std::cin >> creditos;
	std::cout << "Ingrese el Costo del Curso: ";
	std::cin >> costo;
	return new Curso(nombre, codigo,creditos, costo, false);
	system("cls");
}






Grupo* Interfaz::crearGruposCursos(){
	system("cls");// Grupo(std::string NCR, int cupo, Horario* horario);Horario(string horaInicio, string horaFin, bool Dia[7]);
	std::string NCR;
	int cupo;
	std::string horaInicio, horaFin;
	int dias;
	bool Dia[7] = { false,false,false,false,false,false,false };
	std::cout << "Ingrese el NCR de Grupo: ";
	std::cin >> NCR;
	std::cout << "Ingrese el Cupo del Grupo: ";
	std::cin >> cupo;
	std::cout << "Ingrese la Hora de Inicio del Grupo: ";
	std::cin >> horaInicio;
	std::cout << "Ingrese la Hora de Fin del Grupo: ";
	std::cin >> horaFin;
	std::cout << "Ingrese la cantidad de Dias que se impartira el Curso: ";
	std::cin >> dias;
	for (int i = 0; i < dias; i++){
		system("cls");
		std::cout << "Ingrese el Dia de la Semana: ";
		std::cout << "1-Lunes\n" << "2-Martes\n" << "3-Miercoles\n" << "4-Jueves\n" << "5-Viernes\n" << "6-Sabado\n" << "7-Domingo\n";
		int dia;
		std::cin >> dia;
		Dia[dia - 1] = true;
	}
	Horario* horario = new Horario(horaInicio, horaFin, Dia);
	return new Grupo(NCR, cupo, horario);
	system("cls");
}

Grupo* Interfaz::MatricularEstudiante(Escuela* e, Estudiante* est){
	system("cls");
	std::string codigo, NCR;
	int periodo;
	std::cout << "Ingrese el Periodo: ";
	std::cin >> periodo;
	if (est == NULL) {
		std::cout << "Estudiante no encontrado\n";
		system("pause");
		system("cls");
		return nullptr;
	}
	if (e->buscarPeriodo(periodo) == nullptr){
		std::cout << "Periodo no habilitado\n";
		system("pause");
		system("cls");
		return nullptr;
	}
	Periodo* p = e->buscarPeriodo(periodo);
	cout << p->cursosDisponibles();
	std::cout << "Ingrese el Codigo del Curso: ";
	std::cin >> codigo;
	system("cls");
	if (e->buscarPeriodo(periodo)->buscarCurso(codigo) == nullptr){
		std::cout << "Curso no encontrado\n";
		system("pause");
		system("cls");
		return nullptr;
	}
	else if (e->buscarPeriodo(periodo)->buscarCurso(codigo)->grupoEstudianteMatriculado(est) != nullptr){
		std::cout << "Estudiante ya matriculado en el curso\n";
		system("pause");
		system("cls");
		return nullptr;
	}
	else if (e->buscarPeriodo(periodo)->buscarCurso(codigo)->ExisteEnOtroGrupo(est, NCR)){
		std::cout << "Estudiante ya matriculado en otro grupo\n";
		system("pause");
		system("cls");
		return nullptr;
	}
	std::cout << e->buscarPeriodo(periodo)->buscarCurso(codigo)->gruposDisponibles();
	std::cout << "Ingrese el NCR del Grupo: ";
	std::cin >> NCR;
	if (e->buscarPeriodo(periodo)->buscarCurso(codigo)->buscarGrupo(NCR) == nullptr){
		std::cout << "Grupo no encontrado\n";
		system("pause");
		system("cls");
		return nullptr;
	}
	else if (e->buscarPeriodo(periodo)->buscarCurso(codigo)->buscarGrupo(NCR)->getCupo() == 0){
		std::cout << "Grupo lleno\n";
		system("pause");
		system("cls");
		return nullptr;
	}
	else{
		e->matricularEstudiante(est, e->buscarPeriodo(periodo)->buscarCurso(codigo)->buscarGrupo(NCR));
		//Mostrae curso y factura
		system("cls");
		std::cout << "=====================================\n";
		cout << "||	Curso Matriculado             ||\n";
		cout << "=====================================\n";
		cout <<"Nombre: " << e->buscarPeriodo(periodo)->buscarCurso(codigo)->getNombre() << "\n";
		cout << "Codigo: " << e->buscarPeriodo(periodo)->buscarCurso(codigo)->getcodigo() << "\n";
		cout << "Creditos: " << e->buscarPeriodo(periodo)->buscarCurso(codigo)->getCreditos() << "\n";
		cout << "Costo: " << e->buscarPeriodo(periodo)->buscarCurso(codigo)->getCosto() << "\n";
		cout << "=====================================\n";
		facturacionMatricula(e, est, p, e->buscarPeriodo(periodo)->buscarCurso(codigo));
		cout << "=====================================\n";
		system("pause");
		system("cls");
		return e->buscarPeriodo(periodo)->buscarCurso(codigo)->buscarGrupo(NCR);
	}
}

Grupo* Interfaz::darBajaEstudiante(Escuela* e,Estudiante* est){
	int S = 0;//S=0 no se encontro el grupo
	std::string NCR;
	for (int i = 0; i < 4; i++){
		if (e->buscarPeriodo(i+1)!=nullptr){
			ListaCurso* cursos = e->buscarPeriodo(i+1)->cursosMatriculadosEstudiante(est);
			if (cursos->isEmpty()){
				std::cout << "Periodo " << i + 1 << " no hay cursos matriculados" << std::endl;
			}
			else{
				std::cout << "Periodo " << i + 1 << std::endl;
				std::cout << cursos->toString() << std::endl;
				S++;
			}
		}else{
			std::cout << "Periodo " << i + 1 << " no habilitado" << std::endl;
		}
	}
	if (S == 0){
		std::cout << "No hay cursos matriculados" << std::endl;
		system("pause");
		system("cls");
		return nullptr;
	}
	cout << "Ingrese el Codigo del NCR: ";
	cin >> NCR;
	Grupo* grupo = e->buscarGrupo(NCR);
	if (grupo != nullptr){
		return grupo;
	}
	else{
		std::cout << "Grupo no encontrado\n";
		system("pause");
		system("cls");
		return nullptr;
	}
}

Profesor* Interfaz::BuscarProfesor(Escuela* e){
	system("cls");
	std::string CI;
	std::cout << "Ingrese la Cedula del Profesor: ";
	std::cin >> CI;
	return e->buscarProfesor(CI);
}

Estudiante* Interfaz::BuscarEstudiante(Escuela* e){
	system("cls");
	std::string CI;
	std::cout << "Ingrese la Cedula del Estudiante: ";
	std::cin >> CI;
	return e->buscarEstudiante(CI);
}

Curso* Interfaz::BuscarCurso(Escuela* e){	
	std::string codigo;
	std::cout << "Ingrese el Codigo del Curso: ";
	std::cin >> codigo;
	system("cls");
	return  e->buscarCurso(codigo);
}


int Interfaz::BuscarPeriodo(Escuela* e){
	system("cls");
	int periodo;
	std::cout << "Ingrese el Periodo: ";
	std::cin >> periodo;
	if (e->buscarPeriodo(periodo) != nullptr)
		return periodo;
	else return 0;
}

Grupo* Interfaz::BuscarGrupo(Escuela* e){
	system("cls");
	std::string NCR;
	std::string codigo;
	int periodo;
	cout << "Ingrese el periodo: ";
	cin >> periodo;
	//mostrar cursos del periodo
	cout << "Ingrese el codigo del Curso: ";
	cin >> codigo;
	//mostrar grupos del curso
	std::cout << "Ingrese el NCR del Grupo: ";
	std::cin >> NCR;
	return e->buscarPeriodo(periodo)->buscarCurso(codigo)->buscarGrupo(NCR);
}

void Interfaz::informeCursosMatriculadosEstudiante(Escuela* E){
	std::cout << "Ingrese la Cedula del Estudiante: ";
	std::string CI;
	std::cin >> CI;
	Estudiante* estudiante = E->buscarEstudiante(CI);
	system("cls");
	std::cout << "=====================================================\n";
	std::cout << "||    Informe Cursos Matriculados por un Estudiante ||\n";
	std::cout << "=====================================================\n";
	std::cout << E->informeCursosMatriculadosEstudiante(estudiante);
	system("pause");
	system("cls");
}

void Interfaz::informeProfesorEspecifico(Escuela* E){
	system("cls");
	std::cout << "=====================================\n";
	std::cout << "||    Informe Profesor Especifico ||\n";
	std::cout << "=====================================\n";
	Profesor* profesor = Interfaz::BuscarProfesor(E);
	std::cout << E->informeProfesorEspecifico(profesor);
	std::cout << "Cursos Impartidos\n";
	for (int i = 1; i <= 4; i++){
		if (E->buscarPeriodo(i ) != nullptr)	{
			std::cout << "Periodo " << i << std::endl;
			if (E->cursosImpartidosProfesor(profesor, E->buscarPeriodo(i))==nullptr){
				std::cout << "No hay cursos impartidos\n";
			}
			else {
				std::cout << "Prueba";
				std::cout << E->cursosImpartidosProfesor(profesor, E->buscarPeriodo(i))->toString();
			}
		}
		else{
			std::cout << "Periodo " << i  << " no habilitado" << std::endl;
		}
	}
	system("pause");
	system("cls");
}

void Interfaz::informeGrupoEspecifico(Escuela* E){
	system("cls");
	string NCR;
	std::cout << "Ingrese el NCR del Grupo: ";
	std::cin >> NCR;
	Grupo* grupo = E->buscarGrupo(NCR);
	system("cls");
	std::cout << "=====================================\n";
	std::cout << "||    Informe Grupo Especifico ||\n";
	std::cout << "=====================================\n";
	if (grupo != nullptr){
		std::cout << grupo->toString();
		std::cout << "Estudiantes Matriculados\n";
		std::cout << grupo->toStringEstudiantes();
	}
	else{
		std::cout << "Grupo no encontrado\n";
	}
	system("pause");
	system("cls");
}


void Interfaz::informeProfesoresRegistrados(Escuela* E){
	system("cls");
	std::cout << "=======================================\n";
	std::cout << "||    Informe Profesores Registrados ||\n";
	std::cout << "=======================================\n";
	std::cout << E->informeProfesoresRegistrados();
	system("pause");
	system("cls");
}

void Interfaz::informeEstudiantesRegistrados(Escuela* E){
	system("cls");
	std::cout << "========================================\n";
	std::cout << "||    Informe Estudiantes Registrados ||\n";
	std::cout << "========================================\n";
	std::cout << E->informeEstudiantesRegistrados();
	system("pause");
	system("cls");
}

void Interfaz::informePeriodosHabilitados(Escuela* E){
	system("cls");
	std::cout << "=====================================\n";
	std::cout << "||    Informe Periodos Habilitados ||\n";
	std::cout << "=====================================\n";
	std::cout << E->informePeriodosHabilitados();
	system("pause");
	system("cls");
}

void Interfaz::facturacionMatricula(Escuela* E, Estudiante* est, Periodo* p, Curso* curso){
	std::cout << "======================================\n";
	std::cout << "||       Factura de Matricula       ||\n";
	std::cout << "======================================\n";
	double descuento = 0.00;
	descuento = Factura::calcularDescuento(E->cantidadDeCursosMatriculadosEstudiantePeriodo(est,p), E->cantidadDeCursosMatriculadosEstudiante(est));
	Factura* factura = new Factura(curso->getCosto(), descuento);
	std::cout << factura->toString();
}

void Interfaz::mensaje(std::string mensaje){
	system("cls");
	size_t mensajeSize = mensaje.size();
	//need to ajust the size of the message to fit the box
	std::cout << "=====================================\n";
	if (mensajeSize < 30){
		std::cout << "||    " << mensaje;
		for (int i = 0; i < 30 - mensajeSize; i++){
			std::cout << " ";
		}
		std::cout << "||\n";
	}
	else{
		std::cout << "||    " << mensaje << "    ||\n";
	}
	std::cout << "||    Presione ENTER para continuar ||\n";
	std::cout << "=====================================\n";
	system("pause");
	system("cls");
}

bool Interfaz::ConfirmarSalida(){
	system("cls");
	std::string opcion;
	std::cout << "====================================================\n";
	std::cout << "||  Recuerde Guardar los Archivos antes de Salir  ||\n";
	std::cout << "||        Desea Salir del Programa? (s/n)         ||\n";
	std::cout << "====================================================\n";
	std::cin >> opcion;
	return (opcion == "s" || opcion == "S") ? true : false;
	system("cls");
}

void Interfaz::opcionInvalida(){
	system("cls");
	std::cout << "=====================================\n";
	std::cout << "||    Opcion Invalida               ||\n";
	std::cout << "||    Presione ENTER para continuar ||\n";
	std::cout << "=====================================\n";
	system("pause");
	system("cls");
}