#include "NodoGrupo.h"

NodoGrupo::NodoGrupo()
{
	this->grupo = NULL;
	this->siguiente = NULL;
}

NodoGrupo::NodoGrupo(Grupo* grupo)
{
	this->grupo = grupo;
	this->siguiente = NULL;
}

NodoGrupo::~NodoGrupo()
{
}

Grupo* NodoGrupo::getGrupo()
{
	return grupo;
}

void NodoGrupo::setGrupo(Grupo* grupo)
{
	this->grupo = grupo;
}

NodoGrupo* NodoGrupo::getSiguiente()
{
	return siguiente;
}

void NodoGrupo::setSiguiente(NodoGrupo* siguiente)
{
	this->siguiente = siguiente;
}

