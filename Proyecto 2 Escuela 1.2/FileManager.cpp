#include "FileManager.h"
//ofstream is used to write to a file
//ifstream is used to read from a file

void FileManager::guardarEstudiantes(ListaEstudiante* e, std::string nombreArchivo){
	std::ofstream archivo(nombreArchivo, std::ios::out); //ios::out is used to write to a file
	if (archivo.is_open())	{						//this deletes the content of the file and writes the new content
		archivo << "nombre,cedula,telefono,correo,especialidad\n";
		archivo << e->toStringCSV();
		archivo.close();
	}
	else{
		std::cout << "No se pudo abrir el archivo" << std::endl;
	}
}

void FileManager::guardarProfesores(ListaProfesor* p, std::string nombreArchivo){
	std::ofstream archivo(nombreArchivo);
	if (archivo.is_open()){
		archivo << "nombre,cedula,telefono,correo,GradoAcademico\n";
		archivo << p->toStringCSV();
		archivo.close();
	}
	else{
		std::cout << "No se pudo abrir el archivo" << std::endl;
	}
}

void FileManager::guardarCursos(ListaCurso* c, std::string nombreArchivo){
	std::ofstream archivo(nombreArchivo);
	if (archivo.is_open()){
		archivo << "nombre,codigo,creditos,costo,estado\n";
		archivo << c->toStringCSV();
		archivo.close();
	}
	else{
		std::cout << "No se pudo abrir el archivo" << std::endl;
	}
}

void FileManager::guardarPeriodos(Escuela *e, std::string nombreArchivo){
	std::ofstream archivo(nombreArchivo);
	if (archivo.is_open()){
		archivo << e->PeriodosToStringCSV();	
		archivo.close();
	}
	else{
		std::cout << "No se pudo abrir el archivo" << std::endl;
	}
}

void FileManager::guardarGrupos(Escuela* e, std::string nombreArchivo){
	std::ofstream archivo(nombreArchivo);
	if (archivo.is_open()){
		archivo << e->GruposToStringCSV();
		archivo.close();
	}
	else{
		std::cout << "No se pudo abrir el archivo" << std::endl;
	}
}

void FileManager::cargarEstudiantes(Escuela* escuela, std::string nombreArchivo){
	std::ifstream archivo(nombreArchivo);
	if (archivo.is_open()){
		std::string linea;
		std::getline(archivo, linea);
		while (std::getline(archivo, linea)){
			std::stringstream s(linea); 
			std::string nombre, cedula, telefono, correo, especialidad;
			std::getline(s, nombre, ',');
			std::getline(s, cedula, ',');
			std::getline(s, telefono, ',');
			std::getline(s, correo, ',');
			std::getline(s, especialidad, ',');
			escuela->ingresarEstudiante(new Estudiante(nombre, cedula, telefono, correo, especialidad));
		}
		archivo.close();
	}
	else{
		std::cout << "No se pudo abrir el archivo E" << std::endl;
	}
}

void FileManager::cargarProfesores(Escuela* escuela, std::string nombreArchivo){
	std::ifstream archivo(nombreArchivo);
	if (archivo.is_open()){
		std::string linea;
		std::getline(archivo, linea);
		while (std::getline(archivo, linea)){
			std::stringstream s(linea);
			std::string nombre, cedula, telefono, correo, GradoAcademico;
			std::getline(s, nombre, ',');
			std::getline(s, cedula, ',');
			std::getline(s, telefono, ',');
			std::getline(s, correo, ',');
			std::getline(s, GradoAcademico, ',');
			escuela->ingresarProfesor(new Profesor(nombre, cedula, telefono, correo, GradoAcademico));
		}
		archivo.close();
	}
	else{
		std::cout << "No se pudo abrir el archivo P" << std::endl;
	}
}

void FileManager::cargarCursos(Escuela* escuela, std::string nombreArchivo){
	std::ifstream archivo(nombreArchivo);
	if (archivo.is_open()){
		std::string linea;
		std::getline(archivo, linea);
		while (std::getline(archivo, linea)){
			std::stringstream s(linea);
			std::string nombre, codigo, creditos, costo, estado;
			std::getline(s, nombre, ',');
			std::getline(s, codigo, ',');
			std::getline(s, creditos, ',');
			std::getline(s, costo, ',');
			std::getline(s, estado, ',');
			escuela->ingresarCurso(new Curso(nombre, codigo, std::stoi(creditos), std::stod(costo), estado == "Abierto"));
		}
		archivo.close();
	}
	else{
		std::cout << "No se pudo abrir el archivo C" << std::endl;
	}
}

void FileManager::cargarPeriodos(Escuela* escuela, std::string nombreArchivo){
	std::ifstream archivo(nombreArchivo);
	if (archivo.is_open()){
		//first enable the periods
		std::string linea;
		std::getline(archivo, linea);
		//if file is empty
		if (linea == "") {
			archivo.close();
			return;
		}
		std::getline(archivo, linea);
		std::stringstream s(linea);
		std::string periodo1, periodo2, periodo3, periodo4;
		std::getline(s, periodo1, ',');
		std::getline(s, periodo2, ',');
		std::getline(s, periodo3, ',');
		std::getline(s, periodo4, ',');
		if (periodo1 == "1")
			escuela->habilitarPeriodo(1);
		if (periodo2 == "1")
			escuela->habilitarPeriodo(2);
		if (periodo3 == "1")
			escuela->habilitarPeriodo(3);
		if (periodo4 == "1")
			escuela->habilitarPeriodo(4);
		//then add the courses to the periods
		std::getline(archivo, linea);
		for (int i = 1; i <= 4; i++){
			std::getline(archivo, linea);
			std::stringstream s2(linea);
			std::string cantidadCursos;
			std::getline(s2, cantidadCursos, ',');
			for (int j = 0; j < std::stoi(cantidadCursos); j++) {
				//in the same line next to the number of courses is the ncr
				std::string ncr;
				std::getline(s2, ncr, ',');
				Curso* c = escuela->buscarCurso(ncr);
				escuela->buscarPeriodo(i)->insertarCurso(new Curso(c->getNombre(), c->getcodigo(), c->getCreditos(), c->getCosto(), c->getEstado()));//create a new course to dont share the list
			}
		}
		archivo.close();
	}
	else{
		std::cout << "No se pudo abrir el archivo P" << std::endl;
	}
}

void FileManager::cargarGrupos(Escuela* escuela, std::string nombreArchivo){//odio mucho a este metodo
	std::ifstream archivo(nombreArchivo);
	if (!archivo.is_open()) {
		std::cout << "No se pudo abrir el archivo." << std::endl;
		return;
	}
	std::string linea;
	while (std::getline(archivo, linea)) {
		std::string periodo, codigo;
		int cantGrupos, periodoNum;
		std::getline(archivo, linea);
		// Leer periodo, codigo y cantGrupos
		std::stringstream ss(linea);
		std::getline(ss, periodo, ',');
		std::getline(ss, codigo, ',');
		ss >> cantGrupos;
		if (periodo == "1") periodoNum = 1;
		else if (periodo == "2") periodoNum = 2;
		else if (periodo == "3") periodoNum = 3;
		else if (periodo == "4") periodoNum = 4;
		else periodoNum = 0;
		std::getline(archivo, linea);//fin de curso info
		// Leer cada grupo asociado
		for (int i = 0; i < cantGrupos; ++i) {
			std::getline(archivo, linea);
			std::stringstream grupoStream(linea);
			std::string ncr, cupo, cantEst, hrIni, hrFi,horariob,cedp;
			// Leer campos del grupo
			std::getline(grupoStream, ncr, ',');
			std::getline(grupoStream, cupo, ',');
			std::getline(grupoStream, cantEst, ',');
			std::getline(grupoStream, hrIni, ',');
			std::getline(grupoStream, hrFi, ',');
			std::getline(grupoStream, horariob, ',');				
			std::getline(grupoStream, cedp, ',');
			// Convertir el horario en bits a un arreglo de booleanos
			bool dias[7] = { false, false, false, false, false, false, false };
			for (int j = 0; j < 7 && j < horariob.size(); ++j) {
			dias[j] = horariob[j] == '1';
			}
			// Crear el objeto Horario
			Horario* horario = new Horario(hrIni, hrFi, dias);
			// Crear el objeto Grupo
			Grupo* grupo = new Grupo(ncr, std::stoi(cupo), horario);
			// Asignar profesor si existe
			Profesor* profesor = escuela->buscarProfesor(cedp);
			if (profesor != nullptr) {
			grupo->setProfesor(profesor);
			}
			else {
			grupo->setProfesor(NULL);
			}
			// Matricular estudiantes
			for (int j = 0; j <std::stoi( cantEst); ++j) {
				std::string cedA;
				std::getline(grupoStream, cedA, ',');
				// Verifica si la cédula no es "NULL"
				if (!cedA.empty() && cedA != "NULL") {
					Estudiante* estudiante = escuela->buscarEstudiante(cedA);
					if (estudiante != nullptr) {
						grupo->matricularEstudiante(estudiante);
					}
				}
			}
			if (periodoNum != 0) {
				escuela->buscarPeriodo(periodoNum)->buscarCurso(codigo)->insertarGrupo(grupo);
			}
		}
	}
	archivo.close();
}