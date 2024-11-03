#include "Estudiante.h"

Estudiante::Estudiante() :Persona(), especialidad("") {}

Estudiante::Estudiante(std::string nombre, std::string cedula, std::string telefono, std::string correo, std::string especialidad)
	: Persona(nombre, cedula, telefono, correo), especialidad(especialidad) {}

Estudiante::~Estudiante() {}

std::string Estudiante::toString() const
{
	std::stringstream s;
	s << "nombre: " << nombre << "\n";
	s << "cedula: " << cedula << "\n";
	s << "telefono: " << telefono << "\n";
	s << "correo: " << correo << "\n";
	s << "especialidad: " << especialidad << "\n";
	return s.str();
}

std::string Estudiante::toStringCSV() const
{
	std::stringstream s;
	s << nombre << "," << cedula << "," << telefono << "," << correo << "," << especialidad;
	return s.str();
}
