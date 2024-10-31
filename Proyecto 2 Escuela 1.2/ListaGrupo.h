#pragma once
#include "NodoGrupo.h"
class ListaGrupo
{
private:
	NodoGrupo* Pirmas;
	NodoGrupo* Exo;
public:
	ListaGrupo();
	~ListaGrupo();
	bool isEmpty();
	bool insertar(Grupo* grupo);
	
	Grupo* NCRProfesor(Profesor* profesor);
	Grupo* NCRMatriculado(Estudiante* estudiante);
	bool ExisteEnOtroGrupo(Estudiante* estudiante, string NRC);
	Grupo* buscar(string NRC);
	string toString(); 

};

