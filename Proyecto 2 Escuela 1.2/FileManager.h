#pragma once
#include "Escuela.h"
#include <iostream>
#include <fstream>
#include <string>
/*El sistema deberá permitir guardar y acceder archivos para la siguiente información:
Lista de cursos, Lista de bloques o periodos (adecuadamente relacionada con grupos y cursos),
Listas de profesores,Listas de estudiantes,
Lista de grupos (adecuadamente relacionada con el periodo, el profesor y el horario)*/

class FileManager
{
public:
	static void guardarEstudiantes(ListaEstudiante* e, std::string nombreArchivo);
	static void guardarProfesores(ListaProfesor* p, std::string nombreArchivo);
	static void guardarCursos(ListaCurso* c, std::string nombreArchivo);
	static void guardarPeriodos(Escuela *e , std::string nombreArchivo);
	static void guardarGrupos(Escuela *e, std::string nombreArchivo);

	static void cargarEstudiantes(Escuela* escuela, std::string nombreArchivo);
	static void cargarProfesores(Escuela* escuela, std::string nombreArchivo);
	static void cargarCursos(Escuela* escuela, std::string nombreArchivo);
	static void cargarPeriodos(Escuela* escuela, std::string nombreArchivo);
	static void cargarGrupos(Escuela* escuela, std::string nombreArchivo);
	


};

