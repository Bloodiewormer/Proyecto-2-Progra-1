#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Horario
{
private:
	string horaInicio;
	string horaFin;
	bool Dia[7];
public:
	Horario(string horaInicio, string horaFin, bool Dia[7]);
	~Horario();
	string toString();
};

