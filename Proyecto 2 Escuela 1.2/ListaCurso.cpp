#include "ListaCurso.h"

ListaCurso::ListaCurso()
{
	Pirmas = NULL;
	Exo = NULL;
}

ListaCurso::~ListaCurso()
{
	/*while (!isEmpty())
	{
		NodoCurso* aux = Pirmas;
		Pirmas = Pirmas->getSig();
		delete aux;
	}*/
}

bool ListaCurso::isEmpty()
{
	return Pirmas == NULL;
}

bool ListaCurso::insertar(Curso* curso)
{
	NodoCurso* nuevo = new NodoCurso(curso);
	if (nuevo == NULL)
		return false;
	if (isEmpty())
	{
		Pirmas = nuevo;
		Exo = nuevo;
	}
	else
	{
		Exo->setSig(nuevo);
		Exo = nuevo;
	}
	return true;
}

ListaCurso* ListaCurso::cursosImpartidosProfesor(Profesor* profesor)
{
	//los cursos devueltos solo deben tener los grupos en los que el profesor imparte
	ListaCurso* cursos = new ListaCurso();
	Exo = Pirmas;
	int size = 0;
	while (Exo != NULL)
	{
		if (Exo->getCurso()->grupoImpartidoProfesor(profesor) != NULL)
		{
			Curso* c = new Curso(Exo->getCurso()->getNombre(), Exo->getCurso()->getcodigo(), Exo->getCurso()->getCreditos(), Exo->getCurso()->getCosto(), Exo->getCurso()->getEstado());
			c->insertarGrupo(Exo->getCurso()->grupoImpartidoProfesor(profesor));
			cursos->insertar(c);
			size++;
		}
		Exo = Exo->getSig();
	}
	if (size == 0)
	{
		return NULL;
	}
	return cursos;
}

ListaCurso* ListaCurso::cursosMatriculadosEstudiante(Estudiante* e)
{
	//los cursos devueltos solo deben tener los grupos en los que el estudiante esta matriculado
	ListaCurso* cursos = new ListaCurso();
	Exo = Pirmas;

	while (Exo != NULL)
	{
		if (Exo->getCurso()->grupoEstudianteMatriculado(e) != NULL)
		{
			Curso* c = new Curso(Exo->getCurso()->getNombre(), Exo->getCurso()->getcodigo(), Exo->getCurso()->getCreditos(), Exo->getCurso()->getCosto(), Exo->getCurso()->getEstado());
			c->insertarGrupo(Exo->getCurso()->grupoEstudianteMatriculado(e));
			cursos->insertar(c);
		}
		Exo = Exo->getSig();
	}
	return cursos;
}



Curso* ListaCurso::buscar(std::string codigo)
{
	NodoCurso* aux = Pirmas;
	while (aux != NULL)
	{
		if (aux->getCurso()->getcodigo() == codigo)
			return aux->getCurso();
		aux = aux->getSig();
	}
	return NULL;
}

Grupo* ListaCurso::buscarGrupo(std::string NCR)
{
	NodoCurso* aux = Pirmas;
	while (aux != NULL)
	{
		if (aux->getCurso()->buscarGrupo(NCR) != NULL)
			return aux->getCurso()->buscarGrupo(NCR);
		aux = aux->getSig();
	}
	return NULL;
}

std::string ListaCurso::toString()
{
	std::stringstream s;
	NodoCurso* aux = Pirmas;
	s << "---------------------------------------------------" << std::endl;
	while (aux != NULL)
	{
		s << aux->toStringDetallado() << std::endl;
		aux = aux->getSig();
		s << "---------------------------------------------------" << std::endl;
	}
	if (isEmpty())
		s << "No hay cursos registrados" << std::endl;

	return s.str();
}

std::string ListaCurso::cursosDisponibles()
{
	std::stringstream s;
	NodoCurso* aux = Pirmas;
	s << "---------------------------------------------------" << std::endl;
	while (aux != NULL)
	{
		if (aux->getCurso()->getEstado())
		{
			s << aux->cursosDisponibles() << std::endl;
			s << "---------------------------------------------------" << std::endl;
		}
		aux = aux->getSig();
	}

	return s.str();

	
}
