#pragma once
#include "Estudiante.h"
class NodoEstudiante
{
private:
	Estudiante* estudiante;
	NodoEstudiante* siguiente;
public:
	NodoEstudiante();
	NodoEstudiante(Estudiante* estudiante);
	~NodoEstudiante();
	Estudiante* getEstudiante();
	void setEstudiante(Estudiante* estudiante);
	NodoEstudiante* getSiguiente();
	void setSiguiente(NodoEstudiante* siguiente);
};

