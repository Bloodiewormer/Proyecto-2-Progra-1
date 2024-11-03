#include "NodoCurso.h"


NodoCurso::NodoCurso(Curso* curso)
{
	this->curso = curso;
	this->Sig = NULL;
}

NodoCurso::~NodoCurso()
{	//Esto no se usa, al ser agregacion no se debe eliminar el curso
	//delete curso;
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
	s <<"Nombre: " << curso->getNombre() << endl;
	s <<"Codigo: " << curso->getcodigo() << endl;
	return s.str();
}
