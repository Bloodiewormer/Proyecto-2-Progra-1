#pragma once
#include "Persona.h"
class Profesor : public Persona {//hereda de persona 
private:
	std::string GradoAcademico;
public:
	Profesor();
	Profesor(std::string nombre, std::string cedula, std::string telefono, std::string correo, std::string GradoAcademico);
	virtual ~Profesor();
	std::string getGradoAcademico() const;
	std::string toString() const override;//override indica que el metodo es virtual y se sobreescribe
	std::string toStringCSV() const override;//override indica que el metodo es virtual y se sobreescribe
};

