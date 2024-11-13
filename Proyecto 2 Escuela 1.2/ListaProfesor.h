#pragma once
#include "NodoProfesor.h"
class ListaProfesor{
private:
	NodoProfesor* primero;
	NodoProfesor* actual;
public:
	ListaProfesor();
	~ListaProfesor();
	bool listaVacia();
	bool repetido(std::string cedula);
	bool insertarProfesor(Profesor* profesor);
	Profesor* buscarProfesor(std::string cedula);
	std::string toString();
	std::string toStringCSV();
};