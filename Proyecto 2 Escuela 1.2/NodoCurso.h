#pragma once
#include "Curso.h"
class NodoCurso
{
private:
	Curso* curso;
	NodoCurso* Sig;
public:
	NodoCurso(Curso* curso);
	~NodoCurso();
	Curso* getCurso();
	NodoCurso* getSig();
	void setSig(NodoCurso* Sig);
	std::string cursosDisponibles();

};

