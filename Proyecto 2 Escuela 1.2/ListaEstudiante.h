#pragma once
#include "NodoEstudiante.h"
class ListaEstudiante
{
private:
	NodoEstudiante* primer;
	NodoEstudiante* actual;
public:
	ListaEstudiante();
	~ListaEstudiante();
	bool listaVacia();
	bool repetido(std::string cedula);
	int cantidadEstudiantes();
	bool insertarEstudiante(Estudiante* estudiante);
	bool eliminarEstudiante(std::string cedula);
	Estudiante* buscarEstudiante(std::string cedula);
	NodoEstudiante* getPrimer();
	std::string toString();
	std::string toStringCSV();
	std::string toStringIDCSV();
};

