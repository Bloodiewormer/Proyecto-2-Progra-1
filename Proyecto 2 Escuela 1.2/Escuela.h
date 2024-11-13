#pragma once
#include "ListaProfesor.h"
#include "ListaEstudiante.h"
#include "ListaCurso.h"
#include "Periodo.h"
class Escuela{
private:
	ListaProfesor* listaProfesores;//Aqui existe una relacion de composicion con la clase ListaProfesor
	ListaEstudiante* listaEstudiantes;//Aqui existe una relacion de composicion con la clase ListaEstudiante
	ListaCurso* listaCursos;//Aqui existe una relacion de composicion con la clase ListaCurso
	Periodo* periodos[4]; //Aqui existe una relacion de Composicion con la clase Periodo
public:
	//Constructor
	Escuela();
	//Destructor
	virtual ~Escuela();
	//Getters
	ListaCurso* getListaCursos();
	ListaGrupo* getListaGrupos();
	ListaProfesor* getListaProfesores();
	ListaEstudiante* getListaEstudiantes();
	//Methods
	bool PersonaRepetida(std::string cedula);
	bool ingresarProfesor(Profesor* profesor);
	bool ingresarEstudiante(Estudiante* estudiante);
	bool ingresarCurso(Curso* curso);
	bool habilitarPeriodo(int numPe);
	bool ingresarGrupo(Grupo* grupo, Periodo* periodo, Curso* curso);
	bool asignarProfesor(Profesor* profesor, Grupo* grupo);
	bool matricularEstudiante(Estudiante* estudiante, Grupo* grupo);
	bool darBajaEstudiante(Estudiante* estudiante, Grupo* grupo);
	//Informes
	std::string informeProfesoresRegistrados();
	std::string informeEstudiantesRegistrados();
	std::string informePeriodosHabilitados();
	std::string informeCursosMatriculadosEstudiante(Estudiante* estudiante);
	std::string informeProfesorEspecifico(Profesor* profesor);
	//Tools
	int cantidadDeCursosMatriculadosEstudiantePeriodo(Estudiante* estudiante, Periodo* periodo);
	int cantidadDeCursosMatriculadosEstudiante(Estudiante* estudiante);
	//Search
	Profesor* buscarProfesor(std::string cedula);
	Estudiante* buscarEstudiante(std::string cedula);
	Curso* buscarCurso(std::string codigo);
	Grupo* buscarGrupo(std::string NCR);
	Periodo* buscarPeriodo(int numPe);
	ListaGrupo* gruposMatriculadosEstudiantePeriodo(Estudiante* estudiante, Periodo* periodo);
	ListaCurso* cursosImpartidosProfesor(Profesor* profesor,Periodo* p);
	//Strings
	std::string PeriodosToStringCSV();
	std::string GruposToStringCSV();
};