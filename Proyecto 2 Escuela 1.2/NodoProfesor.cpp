#include "NodoProfesor.h"

NodoProfesor::NodoProfesor()
{
	profesor = NULL;
	siguiente = NULL;
}

NodoProfesor::NodoProfesor(Profesor* profesor)
{
	this->profesor = profesor;
	siguiente = NULL;
}

NodoProfesor::~NodoProfesor()
{
}

Profesor* NodoProfesor::getProfesor()
{
	return profesor;
}

void NodoProfesor::setProfesor(Profesor* profesor)
{
	this->profesor = profesor;
}

NodoProfesor* NodoProfesor::getSiguiente()
{
	return siguiente;
}

void NodoProfesor::setSiguiente(NodoProfesor* siguiente)
{
	this->siguiente = siguiente;
}

std::string NodoProfesor::toString()
{
	std::stringstream s;
	s << profesor->toString();
	return s.str();
}


