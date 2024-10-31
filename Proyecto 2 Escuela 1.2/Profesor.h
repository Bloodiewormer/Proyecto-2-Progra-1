#pragma once
#include "Persona.h"
class Profesor : public Persona
{
private:
	std::string GradoAcademico;
public:
	Profesor();
	Profesor(std::string nombre, std::string cedula, std::string telefono, std::string correo, std::string GradoAcademico);
	virtual ~Profesor();
	std::string getGradoAcademico();
	std::string toString();
};

