#pragma once
#include "NodoGrupo.h"
class ListaGrupo{
private:
	NodoGrupo* primer;
	NodoGrupo* actual;
public:
	ListaGrupo();
	~ListaGrupo();
	bool isEmpty();
	bool Existe(std::string NRC);
	bool insertar(Grupo* grupo);
	int contarGrupos();
	Grupo* NCRProfesor(Profesor* profesor);
	Grupo* NCRMatriculado(Estudiante* estudiante);
	bool ExisteEnOtroGrupo(Estudiante* estudiante, std::string NRC);
	bool existeNRC(std::string NRC);
	Grupo* buscar(std::string NRC);
	std::string toString();
	std::string toStringGrupos();
	std::string toStringCSV();
};