#pragma once
#include "NodoEstudiante.h"
class ListaEstudiante
{
private:
	NodoEstudiante* primero;
	NodoEstudiante* actual;
public:
	ListaEstudiante();
	~ListaEstudiante();
	bool listaVacia();
	bool repetido(std::string cedula);
	bool insertarEstudiante(Estudiante* estudiante);
	bool eliminarEstudiante(std::string cedula);
	Estudiante* buscarEstudiante(std::string cedula);
	std::string toString();
};

