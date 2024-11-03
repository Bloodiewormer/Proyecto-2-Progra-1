#pragma once
#pragma once
#include "ListaCurso.h"
#include <iostream>
#include <sstream>
using namespace std;
class Periodo
{
private:
	string NumPeriodo;
	string fechaInicio;
	string fechaFin;
	ListaCurso* cursos;
public:
	Periodo(string numPer, string fechaInicio, string fechaFin);
	~Periodo();
	Curso* buscarCurso(string codigo);
	Grupo* buscarGrupo(string NCR);
	ListaCurso* cursosImpartidosProfesor(Profesor* profesor);
	ListaCurso* cursosMatriculadosEstudiante(Estudiante* e);
	int cantidadDeCursosMatriculadosEstudiante(Estudiante* estudiante);
	bool insertarCurso(Curso* curso);
	string cursosDisponibles();
	string toString();

	string ToStringCSV();
	string ToStringGrupoCSV();
	
};

