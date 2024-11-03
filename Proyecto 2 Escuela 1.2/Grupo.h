#pragma once
#include "Horario.h"
#include "Profesor.h"
#include "ListaEstudiante.h"
class Grupo
{
private:
	std::string NCR;
	int cupo;
	int cantidadEstudiantes;
	Horario* horario;//This relationship is composition
	//Profesor can exist without a group and have multiple groups so this relationship is aggregation
	Profesor* profesor; //This relationship is aggregation
	ListaEstudiante* estudiantes;//This relationship is aggregation
public:
	Grupo(std::string NCR, int cupo, Horario* horario);
	~Grupo();
	std::string getNCR();
	int getCupo();
	int getCantidadEstudiantes();

	bool ExisteEstudiante(std::string cedula);


	Estudiante* buscarEstudiante(std::string cedula);
	Horario* getHorario();
	Profesor* getProfesor();

	void setCupo(int cupo);
	void setCantidadEstudiantes(int cantidadEstudiantes);
	bool setProfesor(Profesor* profesor);

	bool matricularEstudiante(Estudiante* estudiante);
	bool darBajaEstudiante(Estudiante* estudiante);

	std::string toString();
	std::string toStringEstudiantes();
	std::string toStringCSV();
	std::string toStringIDCSV();

};
