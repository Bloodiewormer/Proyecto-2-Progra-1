#pragma once
#include "Horario.h"
#include "Profesor.h"
#include "ListaEstudiante.h"
class Grupo{
private:
	std::string NCR;
	int cupo;
	int cantidadEstudiantes;
	Horario* horario;//This relationship is composition
	//Profesor can exist without a group and have multiple groups so this relationship is aggregation
	Profesor* profesor; //This relationship is aggregation
	ListaEstudiante* estudiantes;//This relationship is aggregation
public:
	//Constructors
	Grupo(std::string NCR, int cupo, Horario* horario);
	//Destructor
	virtual ~Grupo();
	//Getters
	std::string getNCR();
	int getCupo();
	int getCantidadEstudiantes();
	Horario* getHorario();
	Profesor* getProfesor();
	//Setters
	void setCupo(int cupo);
	void setCantidadEstudiantes(int cantidadEstudiantes);
	bool setProfesor(Profesor* profesor);
	// Tools
	bool ExisteEstudiante(std::string cedula);
	Estudiante* buscarEstudiante(std::string cedula);
	// Methods
	bool matricularEstudiante(Estudiante* estudiante);
	bool darBajaEstudiante(Estudiante* estudiante);
	//toString
	std::string toString();
	std::string toStringEstudiantes();
	std::string toStringCSV();
	std::string toStringIDCSV();
};
