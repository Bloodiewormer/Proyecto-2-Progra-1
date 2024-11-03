#pragma once
#include "ListaProfesor.h"
#include "ListaEstudiante.h"
#include "ListaCurso.h"
#include "Periodo.h"
#include <iostream>
#include <sstream>

class Escuela
{
private:
	ListaProfesor* listaProfesores;
	ListaEstudiante* listaEstudiantes;
	ListaCurso* listaCursos;
	Periodo* periodos[4];
public:
	Escuela();
	~Escuela();
	bool PersonaRepetida(std::string cedula);
	bool ingresarProfesor(Profesor* profesor);
	bool ingresarEstudiante(Estudiante* estudiante);
	bool ingresarCurso(Curso* curso);
	bool habilitarPeriodo(int numPe);
	bool ingresarGrupo(Grupo* grupo, Periodo* periodo, Curso* curso);
	bool asignarProfesor(Profesor* profesor, Grupo* grupo);
	bool matricularEstudiante(Estudiante* estudiante, Grupo* grupo);
	bool darBajaEstudiante(Estudiante* estudiante, Grupo* grupo);



	std::string informeProfesoresRegistrados();
	std::string informeEstudiantesRegistrados();
	std::string informePeriodosHabilitados();

	std::string informeCursosMatriculadosEstudiante(Estudiante* estudiante);
	std::string informeProfesorEspecifico(Profesor* profesor);


	int cantidadDeCursosMatriculadosEstudiantePeriodo(Estudiante* estudiante, Periodo* periodo);
	int cantidadDeCursosMatriculadosEstudiante(Estudiante* estudiante);
	ListaGrupo* gruposMatriculadosEstudiantePeriodo(Estudiante* estudiante, Periodo* periodo);
	ListaCurso* cursosImpartidosProfesor(Profesor* profesor,Periodo* p);
	Profesor* buscarProfesor(std::string cedula);
	Estudiante* buscarEstudiante(std::string cedula);
	Curso* buscarCurso(std::string codigo);
	Grupo* buscarGrupo(std::string NCR);
	Periodo* buscarPeriodo(int numPe);


	//Lo siguiente es para la Persistencia
	ListaCurso* getListaCursos();
	ListaGrupo* getListaGrupos();
	ListaProfesor* getListaProfesores();
	ListaEstudiante* getListaEstudiantes();

	std::string PeriodosToStringCSV();

	std::string GruposToStringCSV();


};

