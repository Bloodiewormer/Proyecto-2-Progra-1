#pragma once
#include "NodoCurso.h"
class ListaCurso
{
private:
	NodoCurso* Pirmas;
	NodoCurso* Exo;
public:
	ListaCurso();
	~ListaCurso();
	bool isEmpty();
	bool insertar(Curso* curso);
	ListaCurso* cursosImpartidosProfesor(Profesor* profesor);
	ListaCurso* cursosMatriculadosEstudiante(Estudiante* e);
	Curso* buscar(std::string codigo);
	Grupo* buscarGrupo(std::string NCR);

	std::string toString();
	std::string cursosDisponibles();
};

