#include "NodoProfesor.h"

NodoProfesor::NodoProfesor(){
	profesor = NULL;
	siguiente = NULL;
}

NodoProfesor::NodoProfesor(Profesor* profesor){
	this->profesor = profesor;
	siguiente = NULL;
}

NodoProfesor::~NodoProfesor(){
	if (profesor != nullptr) {
		delete profesor;
	}
}

Profesor* NodoProfesor::getProfesor(){
	return profesor;
}

void NodoProfesor::setProfesor(Profesor* profesor){
	this->profesor = profesor;
}

NodoProfesor* NodoProfesor::getSiguiente(){
	return siguiente;
}

void NodoProfesor::setSiguiente(NodoProfesor* siguiente){
	this->siguiente = siguiente;
}