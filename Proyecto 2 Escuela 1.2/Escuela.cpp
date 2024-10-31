#include "Escuela.h"

Escuela::Escuela()
{
	listaCursos = new ListaCurso();
	listaProfesores = new ListaProfesor();
	listaEstudiantes = new ListaEstudiante();
	for (int i = 0; i <4 ; i++){
	periodos[i] = nullptr;
	}
}

Escuela::~Escuela()
{
	delete listaProfesores;
	delete listaEstudiantes;
}

bool Escuela::PersonaRepetida(std::string cedula)
{
	if (listaProfesores->repetido(cedula) || listaEstudiantes->repetido(cedula))
	{
		return true;
	}
	return false;
}

bool Escuela::ingresarProfesor(Profesor* profesor)
{
	return listaProfesores->insertarProfesor(profesor);
}

bool Escuela::ingresarEstudiante(Estudiante* estudiante)
{
	return listaEstudiantes->insertarEstudiante(estudiante);
}

bool Escuela::ingresarCurso(Curso* curso)
{
	return listaCursos->insertar(curso);
}

bool Escuela::habilitarPeriodo(int numPe)
{
	Periodo* Periodo1 = new Periodo("Periodo 1", "enero", "marzo");
	Periodo* Periodo2 = new Periodo("Periodo 2", "abril", "junio");
	Periodo* Periodo3 = new Periodo("Periodo 3", "julio", "setiembre");
	Periodo* Periodo4 = new Periodo("Periodo 4", "octubre", "diciembre");
	switch (numPe)
	{
	case 1:
		periodos[0] = Periodo1;
		return true;
		break;
	case 2:
		periodos[1] = Periodo2;
		return true;
		break;
	case 3:
		periodos[2] = Periodo3;
		return true;
		break;
	case 4:
		periodos[3] = Periodo4;
		return true;
		break;
	default:
		return false;
		break;
	}
}

bool Escuela::ingresarGrupo(Grupo* grupo, Periodo* periodo, Curso* curso)
{
	//need to create a new course equal to the actual course to dont share the list on curso
	//need to create a new group equal to the actual group to dont share the list on grupo
	if (periodo->buscarCurso(curso->getcodigo()) == nullptr)
	{
		periodo->insertarCurso(new Curso(curso->getNombre(), curso->getcodigo(), curso->getCreditos(), curso->getCosto(), curso->getEstado()));
	}
	if (periodo->buscarCurso(curso->getcodigo())->insertarGrupo(new Grupo(grupo->getNCR(), grupo->getCupo(), grupo->getHorario())))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Escuela::asignarProfesor(Profesor* profesor, Grupo* grupo)
{
	if (grupo->setProfesor(profesor))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool Escuela::matricularEstudiante(Estudiante* estudiante, Grupo* grupo){
	if (estudiante == nullptr) {
		return false;
	}
	if (grupo->matricularEstudiante(estudiante))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Escuela::darBajaEstudiante(Estudiante* estudiante, Grupo* grupo)
{
	if (grupo->darBajaEstudiante(estudiante))
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string Escuela::informeProfesoresRegistrados()
{
	return listaProfesores->toString();
}

std::string Escuela::informeEstudiantesRegistrados()
{
	return listaEstudiantes->toString();
}

std::string Escuela::informePeriodosHabilitados()
{
	std::stringstream s;
	for (int i = 0; i < 4; i++)
	{
		if (periodos[i] != nullptr)
		{
			s << periodos[i]->toString() << std::endl;
		}
		else
		{
			s << "Periodo " << i + 1 << " no habilitado" << std::endl;
		}
	}
	return s.str();

}

std::string Escuela::informeCursosMatriculadosEstudiante(Estudiante* estudiante)
{
	std::stringstream s;
	for (int i = 0; i < 4; i++)
	{
		if (periodos[i] != nullptr)
		{
			s << "Periodo " << i + 1 << std::endl;	
			s << periodos[i]->cursosMatriculadosEstudiante(estudiante)->toString() << std::endl;
		}
		else
		{
			s << "Periodo " << i + 1 << " no habilitado" << std::endl;
		}
	}
	return s.str();
	
}

std::string Escuela::informeProfesorEspecifico(Profesor* profesor)
{
	return profesor->toString();
}


ListaGrupo* Escuela::gruposMatriculadosEstudiantePeriodo(Estudiante* estudiante, Periodo* periodo)
{
	ListaGrupo* grupos = new ListaGrupo();
	periodo->cursosMatriculadosEstudiante(estudiante);
	return grupos;
}

ListaCurso* Escuela::cursosImpartidosProfesor(Profesor* profesor, Periodo* p)
{
	return p->cursosImpartidosProfesor(profesor);
}

Profesor* Escuela::buscarProfesor(std::string cedula)
{
	return listaProfesores->buscarProfesor(cedula);
}

Estudiante* Escuela::buscarEstudiante(std::string cedula)
{
	return listaEstudiantes->buscarEstudiante(cedula);
}

Curso* Escuela::buscarCurso(std::string codigo)
{
	return listaCursos->buscar(codigo);
}

Grupo* Escuela::buscarGrupo(std::string NCR)
{
	Grupo* grupo = nullptr;
	for (int i = 0; i < 4; i++)
	{
		if (periodos[i] != nullptr)
		{
			grupo = periodos[i]->buscarGrupo(NCR);
			if (grupo != nullptr)
			{
				return grupo;
			}
		}
	}
	return nullptr;
}

Periodo* Escuela::buscarPeriodo(int numPe)
{
	return periodos[numPe - 1];
}
	


