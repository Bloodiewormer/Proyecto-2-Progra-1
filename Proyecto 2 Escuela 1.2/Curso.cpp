#include "Curso.h"

Curso::Curso() :nombre(""), codigo(""), creditos(0), costo(0), estado(false)
{
	grupos = new ListaGrupo();
}

Curso::Curso(std::string nombre, std::string codigo, int creditos, double costo, bool estado)
{
	this->nombre = nombre;
	this->codigo = codigo;
	this->creditos = creditos;
	this->costo = costo;
	this->estado = estado;
	//inicializar la lista de grupos
	grupos = new ListaGrupo();

}

Curso::~Curso()
{
	delete grupos;
}

bool Curso::insertarGrupo(Grupo* grupo)
{
	return grupos->insertar(grupo);
}

Grupo* Curso::buscarGrupo(std::string NCR)
{
	if (grupos == nullptr)
	{
		return nullptr;
	}
	else
	{
		return grupos->buscar(NCR);
	}
}

Grupo* Curso::grupoImpartidoProfesor(Profesor* p)
{
	//Este metodo devuelve el grupo que el profesor esta impartiendo
	grupos->NCRProfesor(p);
	if (grupos->NCRProfesor(p) != NULL)
	{
		return grupos->buscar(grupos->NCRProfesor(p)->getNCR());
	}
	else
	{
		return NULL;
	}
}

Grupo* Curso::grupoEstudianteMatriculado(Estudiante* e)
{
	//Este metodo devuelve el grupo en el que el estudiante esta matriculado
	grupos->NCRMatriculado(e);
	if (grupos->NCRMatriculado(e) != NULL)
	{
		return grupos->buscar(grupos->NCRMatriculado(e)->getNCR());
	}
	else
	{
		return NULL;

	}
}

bool Curso::ExisteEnOtroGrupo(Estudiante* estudiante, std::string NRC)
{
	return grupos->ExisteEnOtroGrupo(estudiante, NRC);
}


std::string Curso::getcodigo()
{
	return codigo;
}

int Curso::getCreditos()
{
	return creditos;
	
}

double Curso::getCosto()
{
	return costo;
}

bool Curso::getEstado()
{
	return estado;
}

std::string Curso::getNombre()
{
	return nombre;

}

std::string Curso::cursoDisponible()
{
	std::stringstream s;
	s << "Nombre: " << nombre << std::endl;
	s << "Codigo: " << codigo << std::endl;
	return s.str();
}

std::string Curso::gruposDisponibles()
{
	return grupos->toString();
}

std::string Curso::toStringDetallado()
{
	std::stringstream s;
	s << "Nombre: " << nombre << std::endl;
	s << "Codigo: " << codigo << std::endl;
	s << "Creditos: " << creditos << std::endl;
	s << "Costo: " << costo << std::endl;
	s << "Estado: " << (estado ? "Abierto" : "Cerrado") << std::endl;
	s << "Grupos: " << std::endl;
	s << grupos->toString();
	return s.str();
}


