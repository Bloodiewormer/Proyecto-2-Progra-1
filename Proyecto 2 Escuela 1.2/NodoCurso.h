#pragma once
#include "Curso.h"
class NodoCurso{
private:
	Curso* curso;
	NodoCurso* Sig;
public:
	NodoCurso(Curso* curso);
	~NodoCurso();
	Curso* getCurso();
	NodoCurso* getSig();
	void setSig(NodoCurso* Sig);
	void setCurso(Curso* curso);
};