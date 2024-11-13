#include "Curso.h"

Curso::Curso() :nombre(""), codigo(""), creditos(0), costo(0), estado(false){
	grupos = new ListaGrupo();
}

Curso::Curso(std::string nombre, std::string codigo, int creditos, double costo, bool estado){
	this->nombre = nombre;
	this->codigo = codigo;
	this->creditos = creditos;
	this->costo = costo;
	this->estado = estado;
	//inicializar la lista de grupos
	grupos = new ListaGrupo();
}

Curso::~Curso(){
	delete grupos;
}

bool Curso::insertarGrupo(Grupo* grupo){
	return grupos->insertar(grupo);
}

Grupo* Curso::buscarGrupo(std::string NCR){
	if (grupos == nullptr){
		return nullptr;
	}
	else{
		return grupos->buscar(NCR);
	}
}

Grupo* Curso::grupoImpartidoProfesor(Profesor* p){
	//Este metodo devuelve el grupo que el profesor esta impartiendo
	grupos->NCRProfesor(p);
	if (grupos->NCRProfesor(p) != NULL){
		return grupos->buscar(grupos->NCRProfesor(p)->getNCR());
	}
	else{
		return NULL;
	}
}

//Este metodo devuelve el grupo en el que el estudiante esta matriculado
//Si el estudiante no esta matriculado en ningun grupo, devuelve NULL
//Para que funcione correctamente, el estudiante debe estar matriculado en un solo grupo
Grupo* Curso::grupoEstudianteMatriculado(Estudiante* e)
{
	//Este metodo devuelve el grupo en el que el estudiante esta matriculado
	grupos->NCRMatriculado(e);
	if (grupos->NCRMatriculado(e) != NULL){
		return grupos->buscar(grupos->NCRMatriculado(e)->getNCR());
	}
	else{
		return NULL;
	}
}

bool Curso::existeGrupo(std::string NCR){
	return grupos->existeNRC(NCR);
}

bool Curso::existeEnOtroGrupo(Estudiante* estudiante, std::string NRC){
	return grupos->ExisteEnOtroGrupo(estudiante, NRC);
}

std::string Curso::getcodigo() const{
		return codigo;
}

int Curso::getCreditos() const{
	return creditos;	
}

double Curso::getCosto() const{
	return costo;
}

bool Curso::getEstado() const{
	return estado;
}

void Curso::setEstado(bool estado){
	this->estado = estado;
}

std::string Curso::getNombre() const{
	return nombre;
}

std::string Curso::gruposDisponibles() const{
	return grupos->toString();
}

std::string Curso::toString() const{
	std::stringstream s;
	s << "Nombre: " << nombre << std::endl;
	s << "Codigo: " << codigo << std::endl;
	s << "Creditos: " << creditos << std::endl;
	s << "Costo: " << costo << std::endl;
	s << "Estado: " << (estado ? "Abierto" : "Cerrado") << std::endl;
	return s.str();
}

std::string Curso::toStringCSV() const{
	std::stringstream s;
	s << nombre << "," << codigo << "," << creditos << "," << costo << "," << (estado ? "Abierto" : "Cerrado");
	return s.str();
}

std::string Curso::toStringGruposCSV(int p) const{
	std::stringstream s;
	int c = grupos->contarGrupos();
	if (c == 0){
		s << "";
	}
	else{
		s << "Periodo, Codigo , Cant. Grupos" << std::endl;
		s << p<<"," << codigo << "," << c << std::endl;
		s << "ncr,cupo,cantEst,hrIni,hrFi,Horario,cedp,cedA1,cedA2,cedAn" << std::endl;
		s << grupos->toStringCSV();
	}
	return s.str();
}