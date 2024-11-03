#pragma once
#include "NodoCurso.h"
class ListaCurso
{
private:
	NodoCurso* primer;
	NodoCurso* actual;
public:
	ListaCurso();
	~ListaCurso();
	bool isEmpty() const;
	bool Existe(std::string codigo);
	bool insertar(Curso* curso);
	int contarCursos();


	int cantidadDeCursosMatriculadosEstudiante(Estudiante* estudiante);
	ListaCurso* cursosImpartidosProfesor(Profesor* profesor);
	ListaCurso* cursosMatriculadosEstudiante(Estudiante* e);
	Curso* buscar(std::string codigo);
	Grupo* buscarGrupo(std::string NCR);

	std::string toString();;
	std::string cursosDisponibles();
	std::string toStringCSV();
	std::string toStringPeriodoCSV();
	std::string toStringGruposCSV();

};

