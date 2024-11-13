#pragma once
#include <iostream>
#include <sstream>
#include "ListaGrupo.h"
class Curso{
private:
	std::string nombre;
	std::string codigo;
	int creditos;
	double costo;
	bool estado;//true=abierto, false=cerrado
	ListaGrupo* grupos;// Aqui existe una relacion de composicion con la clase ListaGrupo
public:
	Curso();
	Curso(std::string nombre, std::string codigo, int creditos, double costo, bool estado);
	virtual ~Curso();
	//Getters y Setters
	int getCreditos() const;
	double getCosto() const;
	bool getEstado() const;
	std::string getcodigo() const;
	std::string getNombre() const;
	void setEstado(bool estado);
	//Existe
	bool existeEnOtroGrupo(Estudiante* estudiante, std::string NRC);
	bool existeGrupo(std::string NCR);
	//Buscar
	Grupo* buscarGrupo(std::string NCR);
	Grupo* grupoImpartidoProfesor(Profesor* p);
	Grupo* grupoEstudianteMatriculado(Estudiante* e);
	//Insertar
	bool insertarGrupo(Grupo* grupo);
	//toString
	std::string gruposDisponibles() const;
	std::string toString() const;
	//Archivos
	std::string toStringCSV() const;
	std::string toStringGruposCSV(int p) const;
};