#include "Horario.h"

Horario::Horario(string horaInicio, string horaFin, bool Dia[7])
{
	this->horaInicio = horaInicio;
	this->horaFin = horaFin;
	for (int i = 0; i < 7; i++)
	{
		this->Dia[i] = Dia[i];
	}
}

Horario::~Horario()
{

}

string Horario::toString()
{
	stringstream s;
	s << "Hora de inicio: " << horaInicio << endl;
	s << "Hora de fin: " << horaFin << endl;
	s << "Dias: ";
	for (int i = 0; i < 7; i++)
	{
		if (Dia[i])
		{
			switch (i)
			{
			case 0:
				s << "Lunes ";
				break;
			case 1:
				s << "Martes ";
				break;
			case 2:
				s << "Miercoles ";
				break;
			case 3:
				s << "Jueves ";
				break;
			case 4:
				s << "Viernes ";
				break;
			case 5:
				s << "Sabado ";
				break;
			case 6:
				s << "Domingo ";
				break;
			}
		}
	}
	return s.str();
}

string Horario::toStringCSV()
{
	stringstream s;
	s << horaInicio << "," << horaFin << ",";
	for (int i = 0; i < 7; i++)
	{
		if (Dia[i])
		{
			s << "1";
		}
		else
		{
			s << "0";
		}
	}
	return s.str();
	
}


