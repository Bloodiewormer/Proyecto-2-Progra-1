#include "Periodo.h"

Periodo::Periodo(std::string numPer, std::string fechaInicio, std::string fechaFin){
	this->NumPeriodo = numPer;
	this->fechaInicio = fechaInicio;
	this->fechaFin = fechaFin;
	cursos = new ListaCurso();
}

Periodo::~Periodo(){
	//al ser un relacion de agregacion, no se elimina los cursos de la lista,
	//solamente se vacia la lista antes de eliminarla
	if (cursos != nullptr) {
		NodoCurso* aux = cursos->getPrimer();
		while (aux != NULL){
			if (aux->getCurso() != nullptr) {
				aux->setCurso(nullptr);
			}
			aux = aux->getSig();	
		}
	}
	delete cursos;
}

Curso* Periodo::buscarCurso(std::string codigo){
	return cursos->buscar(codigo);
}

Grupo* Periodo::buscarGrupo(std::string NCR){
	return cursos->buscarGrupo(NCR);
}

ListaCurso* Periodo::cursosImpartidosProfesor(Profesor* profesor){
	return cursos->cursosImpartidosProfesor(profesor);
}

std::string Periodo::cursosMatriculadosEstudiante(Estudiante* e){
	std::stringstream s;
	s << "Periodo: " << NumPeriodo << std::endl;
	if (cursos->cantidadDeCursosMatriculadosEstudiante(e) == 0){
		s << "No tiene cursos matriculados" << std::endl;
	}
	s << cursos->cursosMatriculadosEstudiante(e);
	s << "===================================================" << std::endl;
	return s.str();
}

int Periodo::cantidadDeCursosMatriculadosEstudiante(Estudiante* estudiante){
	return cursos->cantidadDeCursosMatriculadosEstudiante(estudiante);
}

bool Periodo::insertarCurso(Curso* curso){
	return cursos->insertar(curso);
}

bool Periodo::existecodigo(std::string codigo){
	return cursos->existeCurso(codigo);
}

bool Periodo::existeGrupo(std::string NCR){
	if (cursos == nullptr){
		return false;
	}
	else{
		return cursos->existeGrupo(NCR);
	}
}

std::string Periodo::cursosDisponibles(){
	return cursos->cursosDisponibles();
}

std::string Periodo::toString(){
	std::stringstream s;
	s << "===================================================" << std::endl;
	s << "Periodo: " << NumPeriodo << " Fecha Inicio: " << fechaInicio << " Fecha Fin: " << fechaFin << std::endl;
	s << "===================================================" << std::endl;
	s << cursos->toString();
	s << "===================================================" << std::endl;
	return s.str();
}

std::string Periodo::ToStringCSV(){
	std::stringstream s;
	s << cursos->toStringPeriodoCSV();
	return s.str();
}

std::string Periodo::ToStringGrupoCSV(){
	std::stringstream s;
	int p = 0;
	if (NumPeriodo == "Periodo 1") {
		p = 1;
	}
	else if (NumPeriodo == "Periodo 2") {
		p = 2;
	}
	else if (NumPeriodo == "Periodo 3") {
		p = 3;
	}
	else if (NumPeriodo == "Periodo 4") {
		p = 4;
	}
	else {
		p = 0;
	}
	s<< cursos->toStringGruposCSV(p);
	return s.str();
}