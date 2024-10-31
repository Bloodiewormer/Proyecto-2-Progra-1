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
	Horario* horario;
	Profesor* profesor; 
	ListaEstudiante* estudiantes;
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

};
