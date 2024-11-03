#pragma once
#include "Grupo.h"
class NodoGrupo
{
private:
	Grupo* grupo;
	NodoGrupo* siguiente;
public:
	NodoGrupo();
	NodoGrupo(Grupo* grupo);
	~NodoGrupo();
	Grupo* getGrupo();
	void setGrupo(Grupo* grupo);
	NodoGrupo* getSiguiente();
	void setSiguiente(NodoGrupo* siguiente);
};

