#pragma once
#include "NodoGrupo.h"
class ListaGrupo
{
private:
	NodoGrupo* primer;
	NodoGrupo* actual;
public:
	ListaGrupo();
	~ListaGrupo();
	bool isEmpty();
	bool Existe(string NRC);
	bool insertar(Grupo* grupo);
	int contarGrupos();
	
	Grupo* NCRProfesor(Profesor* profesor);
	Grupo* NCRMatriculado(Estudiante* estudiante);
	bool ExisteEnOtroGrupo(Estudiante* estudiante, string NRC);
	Grupo* buscar(string NRC);
	string toString(); 

	string toStringGrupos();
	string toStringCSV();




};

