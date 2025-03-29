#pragma once
#include "Escuela.h"
#include <iostream>
#include <fstream>
#include <string>
class FileManager { //clase de utilidades para guardar y cargar archivos
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

//Esta clase no tiene atributos, solo metodos estaticos para guardar y cargar archivos
//se considera una clase de utilidades y cualquier relacion de clases en el uml se como una
// Dependencia 
//	+----------------+			+------------------ +
//	| FileManager	 | 	< ----->	|    Controladora   |
//	|----------------|			+------------------ +
//	| +guardar...()	 |			|                   |
//	| +cargar...()	 |			|                   |
//	+----------------+			+------------------ +

