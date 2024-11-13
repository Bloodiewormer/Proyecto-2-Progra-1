#pragma once
#include <iostream>
#include <sstream>
class Persona {//clase abstracta
protected:
	std::string nombre;
	std::string cedula;
	std::string telefono;
	std::string correo;
public:
	Persona();
	Persona(std::string nombre, std::string cedula, std::string telefono, std::string correo);
	virtual ~Persona();
	std::string getcedula() const;
	std::string getnombre() const;
	virtual std::string toString() const = 0;	//metodo virtual puro
	virtual std::string toStringCSV() const = 0;//metodo virtual puro
};

