#include "ListaGrupo.h"

ListaGrupo::ListaGrupo()
{
	Pirmas = NULL;
	Exo = NULL;
}

ListaGrupo::~ListaGrupo()
{
}


bool ListaGrupo::isEmpty()
{
	return Pirmas == NULL;
}

	
bool ListaGrupo::insertar(Grupo* grupo)
{
	NodoGrupo* nuevo = new NodoGrupo(grupo);
	if (nuevo == NULL)
		return false;
	if (isEmpty())
	{
		Pirmas = nuevo;
		Exo = nuevo;
	}
	else
	{
		Exo->setSiguiente(nuevo);
		Exo = nuevo;
	}
	return true;
}





Grupo* ListaGrupo::NCRProfesor(Profesor* profesor)
{
	if (Pirmas == nullptr) {
		return nullptr;
	}
	Exo = Pirmas;
	while (Exo != NULL)
	{
		if (Exo->getGrupo()->getProfesor()->getcedula() == profesor->getcedula()) {
			return Exo->getGrupo();
		}
	}
	return NULL;
}

Grupo* ListaGrupo::NCRMatriculado(Estudiante* estudiante)
{
	if (Pirmas == nullptr) {
		return nullptr;
	}
	Exo = Pirmas;
	while (Exo != NULL)
	{
		if (Exo->getGrupo()->ExisteEstudiante(estudiante->getcedula())) {
			return Exo->getGrupo();
		}
		Exo = Exo->getSiguiente();
	}
	return NULL;
}

bool ListaGrupo::ExisteEnOtroGrupo(Estudiante* estudiante, string NRC)
{
	NodoGrupo* aux = Pirmas;
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

Grupo* ListaGrupo::buscar(string NRC)
{
	NodoGrupo* aux = Pirmas;
	while (aux != NULL)
	{
		if (aux->getGrupo()->getNCR() == NRC)
			return aux->getGrupo();
		aux = aux->getSiguiente();
	}
	return NULL;
}

string ListaGrupo::toString()
{
	int cont = 0;
	std::stringstream s;
	NodoGrupo* aux = Pirmas;
	while (aux != NULL)
	{
		cont++;
		s << "-------------\n";
		s << "Grupo " << cont << "\n";
		s << aux->toString();
		s << "-------------\n";
		aux = aux->getSiguiente();
	}
	return s.str();
	
}


