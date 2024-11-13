#include "Profesor.h"

Profesor::Profesor() : Persona(), GradoAcademico("") {}

Profesor::Profesor(std::string nombre, std::string cedula, std::string telefono, std::string correo, std::string GradoAcademico)
	: Persona(nombre, cedula, telefono, correo), GradoAcademico(GradoAcademico) {}

Profesor::~Profesor() {}

std::string Profesor::getGradoAcademico() const{ 
	return GradoAcademico;
}

std::string Profesor::toString() const{
	std::stringstream s;
	s << "nombre: " << nombre << "\n";
	s << "cedula: " << cedula << "\n";
	s << "telefono: " << telefono << "\n";
	s << "correo: " << correo << "\n";
	s << "GradoAcademico: " << GradoAcademico << "\n";
	return s.str();
}

std::string Profesor::toStringCSV() const{
	std::stringstream s;
	s << nombre << "," << cedula << "," << telefono << "," << correo << "," << GradoAcademico;
	return s.str();
}
	