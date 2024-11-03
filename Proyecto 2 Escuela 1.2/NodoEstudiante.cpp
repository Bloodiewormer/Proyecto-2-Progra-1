#include "NodoEstudiante.h"

NodoEstudiante::NodoEstudiante()
{
	this->estudiante = NULL;
	this->siguiente = NULL;
}

NodoEstudiante::NodoEstudiante(Estudiante* estudiante)
{
	this->estudiante = estudiante;
	this->siguiente = NULL;
}

NodoEstudiante::~NodoEstudiante()
{
}

Estudiante* NodoEstudiante::getEstudiante()
{
	return estudiante;
}

void NodoEstudiante::setEstudiante(Estudiante* estudiante)
{
	this->estudiante = estudiante;
}

NodoEstudiante* NodoEstudiante::getSiguiente()
{
	return siguiente;
}

void NodoEstudiante::setSiguiente(NodoEstudiante* siguiente)
{
	this->siguiente = siguiente;
}


