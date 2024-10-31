#include "Estudiante.h"

Estudiante::Estudiante() :Persona(), especialidad("") {}

Estudiante::Estudiante(std::string nombre, std::string cedula, std::string telefono, std::string correo, std::string especialidad)
	: Persona(nombre, cedula, telefono, correo), especialidad(especialidad) {}

Estudiante::~Estudiante() {}

std::string Estudiante::toString()
{
	std::stringstream s;
	s << "nombre: " << nombre << "\n";
	s << "cedula: " << cedula << "\n";
	s << "telefono: " << telefono << "\n";
	s << "correo: " << correo << "\n";
	s << "grado academico: " << especialidad << "\n";
	return s.str();
}