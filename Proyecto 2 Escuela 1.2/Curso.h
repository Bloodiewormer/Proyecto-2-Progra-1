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
	std::string getcodigo() const;
	std::string getNombre() const;
	int getCreditos() const;
	double getCosto() const;
	bool getEstado() const;
	void setEstado(bool estado);
	std::string gruposDisponibles() const;
	std::string toString() const;

	//getters for Persistance
	std::string toStringCSV() const;
	std::string toStringGruposCSV() const;
};

