#include "ListaGrupo.h"

ListaGrupo::ListaGrupo()
{
	primer = NULL;
	actual = NULL;
}

ListaGrupo::~ListaGrupo()
{
	while (primer != NULL)
	{
		actual = primer;
		primer = primer->getSiguiente();
		delete actual;
	}
}


bool ListaGrupo::isEmpty()
{
	return primer == NULL;
}

bool ListaGrupo::Existe(std::string NRC)
{
	NodoGrupo* aux = primer;
	while (aux != NULL)
	{
		if (aux->getGrupo()->getNCR() == NRC)
			return true;
		aux = aux->getSiguiente();
	}
	return false;
}

	
bool ListaGrupo::insertar(Grupo* grupo)
{
	NodoGrupo* nuevo = new NodoGrupo(grupo);
	if (nuevo == NULL)
		return false;
	if (isEmpty())
	{
		primer = nuevo;
		actual = nuevo;
	}
	else
	{
		actual->setSiguiente(nuevo);
		actual = nuevo;
	}
	return true;
}

int ListaGrupo::contarGrupos()
{
	int cont = 0;
	NodoGrupo* aux = primer;
	while (aux != NULL)
	{
		cont++;
		aux = aux->getSiguiente();
	}
	return cont;
}





Grupo* ListaGrupo::NCRProfesor(Profesor* profesor)
{
	if (primer == nullptr) {
		return nullptr;
	}
	actual = primer;
	while (actual != NULL)
	{
		if (actual->getGrupo()->getProfesor()!=NULL)
		{
			if (actual->getGrupo()->getProfesor()->getcedula() == profesor->getcedula())
			{
				return actual->getGrupo();
			}
		}
		actual = actual->getSiguiente();
	}
	return NULL;
}

Grupo* ListaGrupo::NCRMatriculado(Estudiante* estudiante)
{
	if (primer == nullptr) {
		return nullptr;
	}
	actual = primer;
	while (actual != NULL)
	{
		if (actual->getGrupo()->ExisteEstudiante(estudiante->getcedula())) {
			return actual->getGrupo();
		}
		actual = actual->getSiguiente();
	}
	return NULL;
}

bool ListaGrupo::ExisteEnOtroGrupo(Estudiante* estudiante, std::string NRC)
{
	NodoGrupo* aux = primer;
	while (aux != NULL)
	{
		if (aux->getGrupo()->ExisteEstudiante(estudiante->getcedula()) && aux->getGrupo()->getNCR() != NRC)
		{
			return true;
		}
		aux = aux->getSiguiente();
	}
	return false;
	
}

bool ListaGrupo::existeNRC(std::string NRC)
{
	if (primer == nullptr)
	{
		return false;
	}
	NodoGrupo* aux = primer;
	while (aux != NULL)
	{
		if (aux->getGrupo()->getNCR() == NRC)
			return true;
		aux = aux->getSiguiente();
	}
	return false;
}

Grupo* ListaGrupo::buscar(std::string NRC)
{
	NodoGrupo* aux = primer;
	while (aux != NULL)
	{
		if (aux->getGrupo()->getNCR() == NRC)
			return aux->getGrupo();
		aux = aux->getSiguiente();
	}
	return NULL;
}

std::string ListaGrupo::toString()
{
	int cont = 0;
	std::stringstream s;
	NodoGrupo* aux = primer;
	while (aux != NULL)
	{
		cont++;
		s << "-------------\n";
		s << "Grupo " << cont << "\n";
		s << aux->getGrupo()->toString() << "\n";
		s << "-------------\n";
		aux = aux->getSiguiente();
	}
	return s.str();
	
}



std::string ListaGrupo::toStringGrupos()
{
	std::stringstream s;
	NodoGrupo* aux = primer;
	int cont = 0;
	while (aux != NULL)
	{
		cont++;
		s << "-----------------------------------\n";
		s << "Group" << cont << std::endl;
		s << aux->getGrupo()->toString() << "\n";
		s << "-----------------------------------\n";
		aux = aux->getSiguiente();
	}
	if (cont == 0)
		s << "NA" << std::endl;
	return s.str();



}

std::string ListaGrupo::toStringCSV()
{
	std::stringstream s;
	NodoGrupo* aux = primer;
	while (aux != NULL)
	{
		s << aux->getGrupo()->toStringCSV() << aux->getGrupo()->toStringIDCSV() << std::endl;
		aux = aux->getSiguiente();
	}
	return s.str();
}
