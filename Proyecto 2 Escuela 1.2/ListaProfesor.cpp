#include "ListaProfesor.h"

ListaProfesor::ListaProfesor()
{
	primero = NULL;
	actual = NULL;
}

ListaProfesor::~ListaProfesor()
{
	while (primero != NULL)
	{
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

bool ListaProfesor::listaVacia()
{
	return primero == NULL;
}

bool ListaProfesor::repetido(std::string cedula)
{
	NodoProfesor* aux = primero;
	while (aux != NULL)
	{
		if (aux->getProfesor()->getcedula() == cedula)
		{
			return true;
		}
		aux = aux->getSiguiente();
	}
	return false;
}

bool ListaProfesor::insertarProfesor(Profesor* profesor)
{
	if (repetido(profesor->getcedula()))
	{
		return false;
	}
	NodoProfesor* nuevo = new NodoProfesor(profesor);
	if (listaVacia())
	{
		primero = nuevo;
	}
	else
	{
		actual = primero;
		while (actual->getSiguiente() != NULL)
		{
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}
	return true;
}

Profesor* ListaProfesor::buscarProfesor(std::string cedula)
{
	NodoProfesor* aux = primero;
	while (aux != NULL)
	{
		if (aux->getProfesor()->getcedula() == cedula)
		{
			return aux->getProfesor();
		}
		aux = aux->getSiguiente();
	}
	return NULL;
}

std::string ListaProfesor::toString()
{
	std::stringstream s;
	NodoProfesor* aux = primero;
	while (aux != NULL)
	{
		s << aux->getProfesor()->toString();
		s << "-----------------------------------" << std::endl;
		aux = aux->getSiguiente();
	}
	return s.str();
}

std::string ListaProfesor::toStringCSV()
{
	std::stringstream s;
	NodoProfesor* aux = primero;
	while (aux != NULL)
	{
		s << aux->getProfesor()->toStringCSV() << std::endl;
		aux = aux->getSiguiente();
	}
	return s.str();

}

