#pragma once
#include <iostream>
#include "Escuela.h"
#include "Factura.h"
class Interfaz{//clase que se encarga de la interaccion con el usuario
public:
	static void mostarBanner();
	static int menuPrincipal();
	static int submenuAdmin();
	static int submenuMatricula();
	static int submenuBusqueda();
	static Profesor* ingresarProfesor();
	static Estudiante* ingresarEstudiante();
	static int habilitarPeriodoLectivo();
	static Curso* ingresarCurso();
	static Grupo* crearGruposCursos();
	static Grupo* MatricularEstudiante(Escuela* e, Estudiante* est);
	static Grupo* darBajaEstudiante(Escuela* e, Estudiante* est);
	static Profesor* BuscarProfesor(Escuela* e);
	static Estudiante* BuscarEstudiante(Escuela* e);
	static Curso* BuscarCurso(Escuela* e);
	static int BuscarPeriodo(Escuela* e);
	static Grupo* BuscarGrupo(Escuela* e);
	static void informeProfesoresRegistrados(Escuela* E);
	static void informeEstudiantesRegistrados(Escuela* E );
	static void informeCursosMatriculadosEstudiante(Escuela* E);
	static void informeProfesorEspecifico(Escuela* E);
	static void informePeriodosHabilitados(Escuela* E);
	static void informeGrupoEspecifico(Escuela* E);
	static void facturacionMatricula(Escuela* E, Estudiante* est,Periodo* p, Curso* Curso);
	static void mensaje(std::string mensaje);
	static bool ConfirmarSalida();
	static void opcionInvalida();
};