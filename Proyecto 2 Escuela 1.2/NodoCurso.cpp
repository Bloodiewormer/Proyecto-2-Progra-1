#include "NodoCurso.h"


NodoCurso::NodoCurso(Curso* curso){
	this->curso = curso;
	this->Sig = NULL;
}

NodoCurso::~NodoCurso(){	
	if (curso != nullptr) {
		delete curso;
	}
}

Curso* NodoCurso::getCurso(){
	return curso;
}


NodoCurso* NodoCurso::getSig(){
	return Sig;
}

void NodoCurso::setSig(NodoCurso* Sig){
	this->Sig = Sig;
}

void NodoCurso::setCurso(Curso* curso){
	this->curso = curso;
}