#include "Periodo.h"

Periodo::Periodo(string numPer, string fechaInicio, string fechaFin)
{
	this->NumPeriodo = numPer;
	this->fechaInicio = fechaInicio;
	this->fechaFin = fechaFin;
	cursos = new ListaCurso();
}

Periodo::~Periodo()
{
}

Curso* Periodo::buscarCurso(string codigo)
{
	return cursos->buscar(codigo);
}

Grupo* Periodo::buscarGrupo(string NCR)
{
	return cursos->buscarGrupo(NCR);
}

ListaCurso* Periodo::cursosImpartidosProfesor(Profesor* profesor)
{
	return cursos->cursosImpartidosProfesor(profesor);
}

ListaCurso* Periodo::cursosMatriculadosEstudiante(Estudiante* e)
{
	return cursos->cursosMatriculadosEstudiante(e);
}



int Periodo::cantidadDeCursosMatriculadosEstudiante(Estudiante* estudiante)
{
	return cursos->cantidadDeCursosMatriculadosEstudiante(estudiante);
	
}



bool Periodo::insertarCurso(Curso* curso)
{
	return cursos->insertar(curso);
}

string Periodo::cursosDisponibles()
{
	return cursos->cursosDisponibles();
}

string Periodo::toString()
{
	std::stringstream s;
	s << "===================================================" << std::endl;
	s << "Periodo: " << NumPeriodo << " Fecha Inicio: " << fechaInicio << " Fecha Fin: " << fechaFin << std::endl;
	s << "===================================================" << std::endl;
	s << cursos->toString();
	s << "===================================================" << std::endl;
	
	return s.str();
}

string Periodo::ToStringCSV()
{
	std::stringstream s;
	s << cursos->toStringPeriodoCSV();
	return s.str();
	
}

string Periodo::ToStringGrupoCSV()
{
	std::stringstream s;
	s << NumPeriodo << endl
	<< cursos->toStringGruposCSV();
	return s.str();
}





