#include "Controladora.h"

Controladora::Controladora(){
	escuela = new Escuela();
	fileManager = new FileManager();
}

Controladora::~Controladora(){
	delete escuela;
	delete fileManager;
}

void Controladora::iniciar(){
	cargarArchivos();
	Interfaz::mostarBanner();//Muestra el banner de Informacion del Proyecto
	menuPrincipal();
}

void Controladora::menuPrincipal(){
	int opcion;
	do {
		opcion = Interfaz::menuPrincipal();
		switch (opcion){
		case 1:
			submenuAdmin();
			break;
		case 2:
			submenuMatricula();
			break;
		case 3:
			submenuBusqueda();
			break;
		case 4:
			guardarArchivos();
			break;
		case 0:
			if (Interfaz::ConfirmarSalida() == true)
				opcion = -1 ;
			break;
		case -1:
			break;
		default:
			Interfaz::opcionInvalida();
			break;
		}
	} while (opcion != -1);
}

void Controladora::submenuAdmin(){
	int opcion;
	do {
		opcion = Interfaz::submenuAdmin();
		switch (opcion){
		case 1:
			//Ingresar Profesor
			ingresarProfesor();
			break;
		case 2:
			//Ingresar Estudiante
			ingresarEstudiante();
			break;
		case 3:
			//Crear Bloque o Periodo Lectivo
			habilitarPeriodoLectivo();
			break;
		case 4:
			//Ingresar Curso
			ingresarCurso();
			break;
		case 5:
			//Crear Grupos de Cursos
			crearGruposCursos();
			break;
		case 6:
			//Asociar Profesor a Grupo
			asociarProfesorGrupo();
			break;
		case 0:
			break;
		default:
			Interfaz::opcionInvalida();
			break;
		}
	} while (opcion != 0);
}

void Controladora::submenuMatricula(){
	int opcion;
	do {
		opcion = Interfaz::submenuMatricula();
		switch (opcion){
		case 1:
			//Matricular Estudiante
			matricularEstudiante();
			break;
		case 2:
			//Dar de Baja Estudiante
			darBajaEstudiante();
			break;
		case 0:
			break;
		default:
			Interfaz::opcionInvalida();
			break;
		}
	} while (opcion != 0);
}

void Controladora::submenuBusqueda(){
	int opcion;
	do {
		opcion = Interfaz::submenuBusqueda();
		switch (opcion){
		case 1:
			//Informe Profesores Registrados
			informeProfesoresRegistrados();
			break;
		case 2:
			//Informe Estudiantes Registrados
			informeEstudiantesRegistrados();
			break;
		case 3:
			//Informe Cursos Matriculados por un Estudiante
			informeCursosMatriculadosEstudiante();
			break;
		case 4:
			//Informe Profesor Especifico
			informeProfesorEspecifico();
			break;
		case 5:
			//Informe Periodos Habilitados para el Año
			informePeriodosHabilitados();
			break;
		case 6:
			//Informe Grupo Especifico
			informeGrupoEspecifico();
			break;
		case 0:
			break;
		default:
			Interfaz::opcionInvalida();
			break;
		}
	} while (opcion != 0);
}


void Controladora::guardarArchivos(){
	//Guardar Archivos
	std::cout << "Guardando Archivos" << std::endl;
	fileManager->guardarEstudiantes(escuela->getListaEstudiantes(),"Estudiantes.csv");
	fileManager->guardarProfesores(escuela->getListaProfesores(), "Profesores.csv");
	fileManager->guardarCursos(escuela->getListaCursos(), "Cursos.csv");
	fileManager->guardarPeriodos(escuela, "Periodos.csv");
	fileManager->guardarGrupos(escuela, "Grupos.csv");
}

void Controladora::cargarArchivos(){
	//Cargar Archivos
	std::cout << "Cargando Archivos" << std::endl;
	fileManager->cargarEstudiantes(escuela, "Estudiantes.csv");
	fileManager->cargarProfesores(escuela, "Profesores.csv");
	fileManager->cargarCursos(escuela, "Cursos.csv");
	fileManager->cargarPeriodos(escuela, "Periodos.csv");
	fileManager->cargarGrupos(escuela, "Grupos.csv");
}

void Controladora::ingresarProfesor(){
	Profesor* P = Interfaz::ingresarProfesor();
	if (escuela->PersonaRepetida(P->getcedula()) == true)
		Interfaz::mensaje("Persona Repetida");
	else if (escuela->ingresarProfesor(P) == true)
		Interfaz::mensaje("Profesor Ingresado Correctamente");
	else
		Interfaz::mensaje("Error al Ingresar Profesor");
}

void Controladora::ingresarEstudiante(){
	Estudiante* E = Interfaz::ingresarEstudiante();
	if (escuela->PersonaRepetida(E->getcedula()) == true)
		Interfaz::mensaje("Persona Repetida");
	else if (escuela->ingresarEstudiante(E) == true)
		Interfaz::mensaje("Estudiante Ingresado Correctamente");
	else
		Interfaz::mensaje("Error al Ingresar Estudiante");
}

void Controladora::habilitarPeriodoLectivo(){
	int numP = Interfaz::habilitarPeriodoLectivo();
	if (escuela->habilitarPeriodo(numP) == true)
		Interfaz::mensaje("Periodo Habilitado Correctamente");
	else
		Interfaz::mensaje("Error al Habilitar Periodo");
}

void Controladora::ingresarCurso(){
	Curso* C = Interfaz::ingresarCurso();
	if (escuela->ingresarCurso(C) == true)
		Interfaz::mensaje("Curso Ingresado Correctamente");
	else
		Interfaz::mensaje("Error al Ingresar Curso");
}

void Controladora::crearGruposCursos(){
	int numP = Interfaz::BuscarPeriodo(escuela);
	std::cout << escuela->getListaCursos()->cursosDisponibles();//cout no deberia estar aca, pero estoy cansado, sorry
	Curso* C = Interfaz::BuscarCurso(escuela);			   //Dejalo ahi, tampoco es que sea un error
	Grupo* G = Interfaz::crearGruposCursos();
	for (int i = 1; i <= 4; i++){
		if (escuela->buscarPeriodo(i) != nullptr){
			if (escuela->buscarPeriodo(i)->existeGrupo(G->getNCR())){
				Interfaz::mensaje("Grupo Repetido");
				return;
			}
		}	
	}
	if (C == nullptr) 
		Interfaz::mensaje("Error al Buscar Curso");
	else if (escuela->buscarPeriodo(numP) == NULL)
		Interfaz::mensaje("Periodo No Habilitado");
	else if (escuela->ingresarGrupo(G, escuela->buscarPeriodo(numP), C) == true)
		Interfaz::mensaje("Grupo Ingresado Correctamente");
	else
		Interfaz::mensaje("Error al Ingresar Grupo");
}

void Controladora::asociarProfesorGrupo(){
	Profesor* P = Interfaz::BuscarProfesor(escuela);
	if (P == NULL) {
		Interfaz::mensaje("Error al Buscar Profesor");
		return;
	}
	Grupo* G = Interfaz::BuscarGrupo(escuela);
	if (G == NULL) {
		Interfaz::mensaje("Error al Buscar Grupo");
		return;
	}
	if (escuela->asignarProfesor(P, G) == true)
		Interfaz::mensaje("Profesor Asignado Correctamente");
	else
		Interfaz::mensaje("Error al Asignar Profesor");
}

void Controladora::matricularEstudiante(){
	Estudiante* E = Interfaz::BuscarEstudiante(escuela);
	Grupo* G = Interfaz::MatricularEstudiante(escuela, E);
	if (G == nullptr) {
		Interfaz::mensaje("ERROR");
	}
	else if (escuela->matricularEstudiante(E, G) == true)
		Interfaz::mensaje("Estudiante Matriculado Correctamente");
}

void Controladora::darBajaEstudiante(){
	Estudiante* E = Interfaz::BuscarEstudiante(escuela);
	Grupo* G = Interfaz::darBajaEstudiante(escuela,E);
	if (G == nullptr) {
		Interfaz::mensaje("ERROR");
	}
	else if (escuela->darBajaEstudiante(E, G) == true)
		Interfaz::mensaje("Estudiante Dado de Baja Correctamente");
	else
		Interfaz::mensaje("Error al Dar de Baja Estudiante");
}

void Controladora::informeProfesoresRegistrados(){
	Interfaz::informeProfesoresRegistrados(escuela);
}

void Controladora::informeEstudiantesRegistrados(){
	Interfaz::informeEstudiantesRegistrados(escuela);
}

void Controladora::informeCursosMatriculadosEstudiante(){
	Interfaz::informeCursosMatriculadosEstudiante(escuela);
}

void Controladora::informeProfesorEspecifico(){
	Interfaz::informeProfesorEspecifico(escuela);
}

void Controladora::informePeriodosHabilitados(){
	Interfaz::informePeriodosHabilitados(escuela);
}

void Controladora::informeGrupoEspecifico(){
	Interfaz::informeGrupoEspecifico(escuela);
}