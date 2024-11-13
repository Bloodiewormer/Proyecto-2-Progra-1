#pragma once
#pragma once
#include "ListaCurso.h"
#include <iostream>
#include <sstream>
class Periodo{
private:
	std::string NumPeriodo;
	std::string fechaInicio;
	std::string fechaFin;
	ListaCurso* cursos;//Aqui existe una relacion de agregacion
public:
	Periodo(std::string numPer, std::string fechaInicio, std::string fechaFin);
	virtual ~Periodo();
	Curso* buscarCurso(std::string codigo);
	Grupo* buscarGrupo(std::string NCR);
	ListaCurso* cursosImpartidosProfesor(Profesor* profesor);
	std::string cursosMatriculadosEstudiante(Estudiante* e);
	int cantidadDeCursosMatriculadosEstudiante(Estudiante* estudiante);
	bool insertarCurso(Curso* curso);
	bool existecodigo(std::string codigo);
	bool existeGrupo(std::string NCR);
	std::string cursosDisponibles();
	std::string toString();
	std::string ToStringCSV();
	std::string ToStringGrupoCSV();
};

