#pragma once
#include <iostream>
#include <sstream>
class Horario{
private:
	std::string horaInicio;
	std::string horaFin;
	bool Dia[7];// Vector de 7 posiciones que indica los dias de la semana
public:
	//Constructores
	Horario(std::string horaInicio, std::string horaFin, bool Dia[7]);
	//Destructor
	virtual ~Horario();
	//toString
	std::string toString();
	std::string toStringCSV();
};

