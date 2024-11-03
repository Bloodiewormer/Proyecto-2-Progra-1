#pragma once
#include "Persona.h"
class Estudiante : public Persona
{
private:
	std::string especialidad;
public:
	Estudiante();
	Estudiante(std::string nombre, std::string cedula, std::string telefono, std::string correo, std::string especialidad);
	virtual ~Estudiante();
	std::string toString() const override; //override indica que el metodo es virtual y se sobreescribe
	std::string toStringCSV() const override; //override indica que el metodo es virtual y se sobreescribe
};

