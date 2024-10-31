#include "Controladora.h"

Controladora::Controladora()
{
	escuela = new Escuela();
}

void Controladora::iniciar()
{
	// ingresar datos de prueba
	//Profesor* P = new Profesor("David", "1", "1", "
	escuela->ingresarProfesor(new Profesor("David", "1", "1", "dbfc@gmail.com", "Informatica"));
	escuela->ingresarProfesor(new Profesor("Brandon", "2", "7187", "alfa@gmail.xom", "Informatica"));
	escuela->ingresarProfesor(new Profesor("Fernando", "3", "1", "a.com", "Informatica"));
	//Estudiante* E = new Estudiante("Juan", "1", "1", "a.com", "Informatica");
	escuela->ingresarEstudiante(new Estudiante("Juan", "1", "1", "a.com", "Informatica"));
	escuela->ingresarEstudiante(new Estudiante("Pedro", "2", "1", "a.com", "Informatica"));
	escuela->ingresarEstudiante(new Estudiante("Maria", "3", "1", "a.com", "Informatica"));
	//
	escuela->habilitarPeriodo(1);
	escuela->habilitarPeriodo(2);

	escuela->ingresarCurso(new Curso("Informatica", "1", 4, 2000, 1));
	escuela->ingresarCurso(new Curso("Matematica", "2", 4, 2000, 1));


	bool dia[7] = { true, false, true, false, true, false, true };
	bool dia2[7] = { false, true, false, true, false, true, false };
	bool dia3[7] = { true, true, true, true, true, true, true };
	bool dia4[7] = { false, false, false, false, false, false, false };
	bool dia5[7] = { true, false, true, false, true, false, true };


	Horario* h = new Horario("10:00", "12:00", dia);
	Horario* h2 = new Horario("1:00", "2:00", dia2);
	Horario* h3 = new Horario("3:00", "4:00", dia3);
	Horario* h4 = new Horario("5:00", "6:00", dia4);
	Horario* h5 = new Horario("7:00", "8:00", dia5);

	escuela->ingresarGrupo(new Grupo("1", 20, h), escuela->buscarPeriodo(1), escuela->buscarCurso("1"));
	escuela->ingresarGrupo(new Grupo("2", 20, h2), escuela->buscarPeriodo(1), escuela->buscarCurso("1"));
	escuela->ingresarGrupo(new Grupo("3", 20, h3), escuela->buscarPeriodo(2), escuela->buscarCurso("1"));
	escuela->ingresarGrupo(new Grupo("4", 20, h4), escuela->buscarPeriodo(2), escuela->buscarCurso("1"));
	escuela->ingresarGrupo(new Grupo("5", 20, h5), escuela->buscarPeriodo(2), escuela->buscarCurso("2"));

	escuela->asignarProfesor(escuela->buscarProfesor("1"), escuela->buscarPeriodo(1)->buscarCurso("1")->buscarGrupo("1"));
	escuela->asignarProfesor(escuela->buscarProfesor("2"), escuela->buscarPeriodo(1)->buscarCurso("1")->buscarGrupo("2"));
	escuela->asignarProfesor(escuela->buscarProfesor("1"), escuela->buscarPeriodo(2)->buscarCurso("1")->buscarGrupo("3"));
	escuela->asignarProfesor(escuela->buscarProfesor("3"), escuela->buscarPeriodo(2)->buscarCurso("1")->buscarGrupo("4"));
	escuela->asignarProfesor(escuela->buscarProfesor("2"), escuela->buscarPeriodo(2)->buscarCurso("2")->buscarGrupo("5"));


	Interfaz::mostarBanner();
	menuPrincipal();
}

void Controladora::menuPrincipal()
{
	int opcion;
	do {
		opcion = Interfaz::menuPrincipal();
		switch (opcion)
		{
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
			//guardarArchivos();
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

void Controladora::submenuAdmin()
{
	int opcion;
	do {
		opcion = Interfaz::submenuAdmin();
		switch (opcion)
		{
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

void Controladora::submenuMatricula()
{
	int opcion;
	do {
		opcion = Interfaz::submenuMatricula();
		switch (opcion)
		{
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

void Controladora::submenuBusqueda()
{
	int opcion;
	do {
		opcion = Interfaz::submenuBusqueda();
		switch (opcion)
		{
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

/*
void Controladora::guardarArchivos()
{
	//Guardar Archivos


}

void Controladora::cargarArchivos()
{
	//Cargar Archivos
}
*/
void Controladora::ingresarProfesor()
{
	Profesor* P = Interfaz::ingresarProfesor();
	if (escuela->PersonaRepetida(P->getcedula()) == true)
		Interfaz::mensaje("Persona Repetida");
	else if (escuela->ingresarProfesor(P) == true)
		Interfaz::mensaje("Profesor Ingresado Correctamente");
	else
		Interfaz::mensaje("Error al Ingresar Profesor");
	
}

void Controladora::ingresarEstudiante()
{
	Estudiante* E = Interfaz::ingresarEstudiante();
	if (escuela->PersonaRepetida(E->getcedula()) == true)
		Interfaz::mensaje("Persona Repetida");
	else if (escuela->ingresarEstudiante(E) == true)
		Interfaz::mensaje("Estudiante Ingresado Correctamente");
	else
		Interfaz::mensaje("Error al Ingresar Estudiante")
;
}

void Controladora::habilitarPeriodoLectivo()
{
	int numP = Interfaz::habilitarPeriodoLectivo();
	if (escuela->habilitarPeriodo(numP) == true)
		Interfaz::mensaje("Periodo Habilitado Correctamente");
	else
		Interfaz::mensaje("Error al Habilitar Periodo");
}

void Controladora::ingresarCurso()
{
	Curso* C = Interfaz::ingresarCurso();
	if (escuela->ingresarCurso(C) == true)
		Interfaz::mensaje("Curso Ingresado Correctamente");
	else
		Interfaz::mensaje("Error al Ingresar Curso");
}

void Controladora::crearGruposCursos()
{
	int numP = Interfaz::BuscarPeriodo(escuela);
	Curso* C = Interfaz::BuscarCurso(escuela);
	Grupo* G = Interfaz::crearGruposCursos();

	if (escuela->buscarPeriodo(numP) == NULL)
		Interfaz::mensaje("Periodo No Habilitado");
	else if (escuela->buscarCurso(C->getcodigo()) == NULL)
		Interfaz::mensaje("Curso No Existe");
	else if (escuela->ingresarGrupo(G, escuela->buscarPeriodo(numP), C) == true)
		Interfaz::mensaje("Grupo Ingresado Correctamente");
	else
		Interfaz::mensaje("Error al Ingresar Grupo");
}

void Controladora::asociarProfesorGrupo()
{
	Profesor* P = Interfaz::BuscarProfesor(escuela);
	Grupo* G = Interfaz::BuscarGrupo(escuela);
	if (escuela->asignarProfesor(P, G) == true)
		Interfaz::mensaje("Profesor Asignado Correctamente");
	else
		Interfaz::mensaje("Error al Asignar Profesor");
}

void Controladora::matricularEstudiante()
{
	Estudiante* E = Interfaz::BuscarEstudiante(escuela);
	Grupo* G = Interfaz::MatricularEstudiante(escuela, E);
	if (G == nullptr) {
		Interfaz::mensaje("ERROR");
	}
	else if (escuela->matricularEstudiante(E, G) == true)
		Interfaz::mensaje("Estudiante Matriculado Correctamente");
	else
		Interfaz::mensaje("Error al Matricular Estudiante");


		
}

void Controladora::darBajaEstudiante()
{
	Estudiante* E = Interfaz::BuscarEstudiante(escuela);
	Grupo* G = Interfaz::darBajaEstudiante(escuela,E);
	if (G == nullptr) {
		Interfaz::mensaje("ERROR");
	}
	else
	if (escuela->darBajaEstudiante(E, G) == true)
		Interfaz::mensaje("Estudiante Dado de Baja Correctamente");
	else
		Interfaz::mensaje("Error al Dar de Baja Estudiante");
}

void Controladora::informeProfesoresRegistrados()
{
	Interfaz::informeProfesoresRegistrados(escuela);
}

void Controladora::informeEstudiantesRegistrados()
{
	Interfaz::informeEstudiantesRegistrados(escuela);
}

void Controladora::informeCursosMatriculadosEstudiante()
{
	Interfaz::informeCursosMatriculadosEstudiante(escuela);
}

void Controladora::informeProfesorEspecifico()
{
	Interfaz::informeProfesorEspecifico(escuela);
}

void Controladora::informePeriodosHabilitados()
{
	Interfaz::informePeriodosHabilitados(escuela);

}

void Controladora::informeGrupoEspecifico()
{
	Interfaz::informeGrupoEspecifico(escuela);
}






