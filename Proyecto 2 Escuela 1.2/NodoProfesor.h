#pragma once
#include "Profesor.h"
class NodoProfesor
{
private:
	Profesor* profesor;
	NodoProfesor* siguiente;
public:
	NodoProfesor();
	NodoProfesor(Profesor* profesor);
	~NodoProfesor();
	Profesor* getProfesor();
	void setProfesor(Profesor* profesor);
	NodoProfesor* getSiguiente();
	void setSiguiente(NodoProfesor* siguiente);
	std::string toString();

};

