#pragma once
#include <iostream>
#include <sstream>
#include "ListaGrupo.h"
class Curso
{
private:
	std::string nombre;
	std::string codigo;
	int creditos;
	double costo;
	bool estado;//true=abierto, false=cerrado
	ListaGrupo* grupos;
public:
	Curso();
	Curso(std::string nombre, std::string codigo, int creditos, double costo, bool estado);
	~Curso();
	bool insertarGrupo(Grupo* grupo);
	Grupo* buscarGrupo(std::string NCR);

	Grupo* grupoImpartidoProfesor(Profesor* p);
	Grupo* grupoEstudianteMatriculado(Estudiante* e);
	bool ExisteEnOtroGrupo(Estudiante* estudiante, std::string NRC);

	std::string getcodigo();
	std::string getNombre();
	int getCreditos();
	double getCosto();
	bool getEstado();
	std::string cursoDisponible();
	std::string gruposDisponibles();
	std::string toStringDetallado();
};

