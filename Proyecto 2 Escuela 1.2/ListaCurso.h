#pragma once
#include "NodoCurso.h"
class ListaCurso{
private:
	NodoCurso* primer;
	NodoCurso* actual;
public:
	ListaCurso();
	~ListaCurso();
	bool isEmpty() const;
	bool existeCurso(std::string codigo);
	bool insertar(Curso* curso);
	bool existeGrupo(std::string NCR);
	int contarCursos();
	int cantidadDeCursosMatriculadosEstudiante(Estudiante* estudiante);
	ListaCurso* cursosImpartidosProfesor(Profesor* profesor);
	Curso* buscar(std::string codigo);
	Grupo* buscarGrupo(std::string NCR);
	NodoCurso* getPrimer();
	std::string cursosMatriculadosEstudiante(Estudiante* e);
	std::string toString();
	std::string cursosDisponibles();
	std::string toStringCSV();
	std::string toStringPeriodoCSV();
	std::string toStringGruposCSV(int p);
};