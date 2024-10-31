#include "ListaEstudiante.h"

ListaEstudiante::ListaEstudiante()
{
	primero = NULL;
	actual = NULL;
}

ListaEstudiante::~ListaEstudiante()
{
	while (primero != NULL)
	{
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

bool ListaEstudiante::listaVacia()
{
	return primero == NULL;
}

bool ListaEstudiante::repetido(std::string cedula)
{
	NodoEstudiante* aux = primero;
	while (aux != NULL)
	{
		if (aux->getEstudiante()->getcedula() == cedula)
		{
			return true;
		}
		aux = aux->getSiguiente();
	}
	return false;
}

bool ListaEstudiante::insertarEstudiante(Estudiante* estudiante)
{
	if (repetido(estudiante->getcedula()))
	{
		return false;
	}
	NodoEstudiante* nuevo = new NodoEstudiante(estudiante);
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

bool ListaEstudiante::eliminarEstudiante(std::string cedula)
{
	if (listaVacia())
	{
		return false;
	}
	if (primero->getEstudiante()->getcedula() == cedula)
	{
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
		return true;
	}
	else
	{
		NodoEstudiante* anterior = primero;
		actual = primero->getSiguiente();
		while (actual != NULL && actual->getEstudiante()->getcedula() != cedula)
		{
			anterior = actual;
			actual = actual->getSiguiente();
		}
		if (actual != NULL)
		{
			anterior->setSiguiente(actual->getSiguiente());
			delete actual;
			return true;
		}
	}
	return false;
}

Estudiante* ListaEstudiante::buscarEstudiante(std::string cedula)
{
	if (listaVacia())
	{
		return NULL;
	}
	actual = primero;
	while (actual != NULL)
	{
		if (actual->getEstudiante()->getcedula() == cedula)
		{
			return actual->getEstudiante();
		}
		actual = actual->getSiguiente();
	}
	return NULL;
}

std::string ListaEstudiante::toString()
{
	std::stringstream s;
	actual = primero;
	while (actual != NULL)
	{
		s << actual->toString() << std::endl;
		s << "-----------------------------------" << std::endl;
		actual = actual->getSiguiente();
	}
	if (listaVacia())
	{
		s << "No hay estudiantes registrados" << std::endl;
	}
	return s.str();
}


