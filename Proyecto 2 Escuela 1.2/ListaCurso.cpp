#include "ListaCurso.h"

ListaCurso::ListaCurso()
{
	primer = NULL;
	actual = NULL;
}

ListaCurso::~ListaCurso()
{
	while (isEmpty())
	{
		actual = primer;
		primer = primer->getSig();
		delete actual;
	}
}

bool ListaCurso::isEmpty() const
{
	return primer == NULL;
}

bool ListaCurso::existeCurso(std::string codigo)
{
	actual = primer;
	while (actual != NULL)
	{
		if (actual->getCurso()->getcodigo() == codigo)
			return true;
		actual = actual->getSig();
	}
	return false;
}

bool ListaCurso::insertar(Curso* curso)
{
	NodoCurso* nuevo = new NodoCurso(curso);
	if (nuevo == NULL)
		return false;
	if (isEmpty())
	{
		primer = nuevo;
		actual = nullptr;
	}
	else
	{
		actual = primer;
		while (actual->getSig() != NULL)
		{
			actual = actual->getSig();
		}
		actual->setSig(nuevo);
		actual = nuevo;
	}
	return true;
}

bool ListaCurso::existeGrupo(std::string NCR)
{
	actual = primer;
	while (actual != NULL)
	{
		if (actual->getCurso()->existeGrupo(NCR))
			return true;
		actual = actual->getSig();
	}
	return false;
}

int ListaCurso::contarCursos()
{
	int cont = 0;
	actual = primer;
	while (actual != NULL)
	{
		cont++;
		actual = actual->getSig();
	}
	return cont;

}

int ListaCurso::cantidadDeCursosMatriculadosEstudiante(Estudiante* estudiante)
{
	int cantidad = 0;
	actual = primer;
	while (actual != NULL)
	{
		if (actual->getCurso()->grupoEstudianteMatriculado(estudiante) != NULL)
			cantidad++;
		actual = actual->getSig();
	}
	return cantidad;
}

ListaCurso* ListaCurso::cursosImpartidosProfesor(Profesor* profesor)
{
	//los cursos devueltos solo deben tener los grupos en los que el profesor imparte
	ListaCurso* cursos = new ListaCurso();
	actual = primer;
	int size = 0;
	while (actual != NULL)
	{
		if (actual->getCurso()->grupoImpartidoProfesor(profesor) != NULL)
		{
			Curso* c = new Curso(actual->getCurso()->getNombre(), actual->getCurso()->getcodigo(), actual->getCurso()->getCreditos(), actual->getCurso()->getCosto(), actual->getCurso()->getEstado());
			c->insertarGrupo(actual->getCurso()->grupoImpartidoProfesor(profesor));
			cursos->insertar(c);
			size++;
		}
		actual = actual->getSig();
	}
	if (size == 0)
	{
		return NULL;
	}
	return cursos;
}

std::string ListaCurso::cursosMatriculadosEstudiante(Estudiante* e)
{// este metodo devuelve un string con el nombre,codigo y NCR DE LOS GRUPOS EN LOS QUE ESTA MATRICULADO EL ESTUDIANTE
	std::stringstream s;
	actual = primer;
	while (actual != NULL)
	{
		if (actual->getCurso()->grupoEstudianteMatriculado(e) != NULL)
		{
			s << "Nombre: " << actual->getCurso()->getNombre() << " Codigo: " << actual->getCurso()->getcodigo() 
			  << " NCR: " << actual->getCurso()->grupoEstudianteMatriculado(e)->getNCR() << std::endl;
		}
		actual = actual->getSig();
	}
	return s.str();

}



Curso* ListaCurso::buscar(std::string codigo)
{
	NodoCurso* aux = primer;
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
	NodoCurso* aux = primer;
	while (aux != NULL)
	{
		if (aux->getCurso()->buscarGrupo(NCR) != NULL)
			return aux->getCurso()->buscarGrupo(NCR);
		aux = aux->getSig();
	}
	return NULL;
}

NodoCurso* ListaCurso::getPrimer()
{
	return primer;
}

std::string ListaCurso::toString()
{
	std::stringstream s;
	NodoCurso* aux = primer;
	s << "---------------------------------------------------" << std::endl;
	while (aux != NULL)
	{
		s << aux->getCurso()->toString() << std::endl;
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
	NodoCurso* aux = primer;
	s << "---------------------------------------------------" << std::endl;
	while (aux != NULL){
		if (aux->getCurso()->getEstado()){
			s << "Nombre:" << aux->getCurso()->getNombre() << std::endl;
			s << "Codigo:" << aux->getCurso()->getcodigo() << std::endl;
			s << "---------------------------------------------------" << std::endl;
		}
		aux = aux->getSig();
	}
	if (isEmpty())
		s << "No hay cursos registrados" << std::endl;

	return s.str();

	
}

std::string ListaCurso::toStringCSV()
{
	std::stringstream s;
	NodoCurso* aux = primer;
	while (aux != NULL)
	{
		s << aux->getCurso()->toStringCSV() << std::endl;
		aux = aux->getSig();
	}
	return s.str();
}

std::string ListaCurso::toStringPeriodoCSV()
{
	std::stringstream s;
	NodoCurso* aux = primer;
	int cont = contarCursos();
	s << cont;
	aux = primer;
	//lo siguienete metera los codigos de los cursos en un string de la forma "codigo1,codigo2,codigo3"
	while (aux != NULL)
	{
		s <<","<< aux->getCurso()->getcodigo();
		aux = aux->getSig();
	}
	s << "\n";
	return s.str();
	
}

std::string ListaCurso::toStringGruposCSV(int p)
{
	std::stringstream s;
	NodoCurso* aux = primer;
	while (aux != NULL)
	{
		s << aux->getCurso()->toStringGruposCSV(p);
		aux = aux->getSig();
	}
	return s.str();
}


