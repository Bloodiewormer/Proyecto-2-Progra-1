#pragma once
#include "Interfaz.h"
#include "Escuela.h"
#include "FileManager.h"
class Controladora
{

private:
	Escuela* escuela;
	FileManager* fileManager;

public:
	Controladora();
	void iniciar();
	void menuPrincipal();
	void submenuAdmin();
	void submenuMatricula();
	void submenuBusqueda();
	void guardarArchivos();
	void cargarArchivos();
	void ingresarProfesor();
	void ingresarEstudiante();
	void habilitarPeriodoLectivo();
	void ingresarCurso();
	void crearGruposCursos();
	void asociarProfesorGrupo();
	void matricularEstudiante();
	void darBajaEstudiante();
	void informeProfesoresRegistrados();
	void informeEstudiantesRegistrados();
	void informeCursosMatriculadosEstudiante();
	void informeProfesorEspecifico();
	void informePeriodosHabilitados();
	void informeGrupoEspecifico();
};
