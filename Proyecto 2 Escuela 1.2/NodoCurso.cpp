#include "NodoCurso.h"


NodoCurso::NodoCurso(Curso* curso)
{
	this->curso = curso;
	this->Sig = NULL;
}

NodoCurso::~NodoCurso()
{

}

Curso* NodoCurso::getCurso()
{
	return curso;
}


NodoCurso* NodoCurso::getSig()
{
	return Sig;
}

void NodoCurso::setSig(NodoCurso* Sig)
{
	this->Sig = Sig;
}

std::string NodoCurso::cursosDisponibles()
{
	std::stringstream s;
	s << curso->cursoDisponible();
	return s.str();
}


std::string NodoCurso::toStringDetallado()
{
	std::stringstream s;
	s << curso->toStringDetallado();
	return s.str();
}
