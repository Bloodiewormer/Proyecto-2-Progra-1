#include "ListaEstudiante.h"

ListaEstudiante::ListaEstudiante()
{
	primer = NULL;
	actual = NULL;
}

ListaEstudiante::~ListaEstudiante()
{
	while (primer != NULL)
	{
		actual = primer;
		primer = primer->getSiguiente();
		delete actual;
	}
}

bool ListaEstudiante::listaVacia()
{
	return primer == NULL;
}

bool ListaEstudiante::repetido(std::string cedula)
{
	NodoEstudiante* aux = primer;
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

int ListaEstudiante::cantidadEstudiantes()
{
	int cont = 0;
	actual = primer;
	while (actual != NULL)
	{
		cont++;
		actual = actual->getSiguiente();
	}
	return cont;

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
		primer = nuevo;
	}
	else
	{
		actual = primer;
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
	if (primer->getEstudiante()->getcedula() == cedula)
	{
		actual = primer;
		primer = primer->getSiguiente();
		delete actual;
		return true;
	}
	else
	{
		NodoEstudiante* anterior = primer;
		actual = primer->getSiguiente();
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
	actual = primer;
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

NodoEstudiante* ListaEstudiante::getPrimer()
{
	return primer;
}

std::string ListaEstudiante::toString() 
{
	std::stringstream s;
	actual = primer;
	while (actual != NULL)
	{
		s << actual->getEstudiante()->toString();
		s << "-----------------------------------" << std::endl;
		actual = actual->getSiguiente();
	}
	if (listaVacia())
	{
		s << "No hay estudiantes registrados" << std::endl;
	}
	return s.str();
}

std::string ListaEstudiante::toStringCSV()
{
	std::stringstream s;
	actual = primer;
	while (actual != NULL)
	{
		s << actual->getEstudiante()->toStringCSV() << std::endl;
		actual = actual->getSiguiente();
	}
	return s.str();

}

std::string ListaEstudiante::toStringIDCSV()
{
	std::stringstream s;
	actual = primer;
	while (actual != NULL)
	{
		s << actual->getEstudiante()->getcedula() << ",";
		actual = actual->getSiguiente();
	}
	if (listaVacia())
	{
		s << "" << std::endl;
	}
	return s.str();
	
}



