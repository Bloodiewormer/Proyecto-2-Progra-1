#include "FileManager.h"
//ofstream is used to write to a file
//ifstream is used to read from a file

void FileManager::guardarEstudiantes(ListaEstudiante* e, std::string nombreArchivo)
{
	std::ofstream archivo(nombreArchivo, ios::out); //ios::out is used to write to a file
	if (archivo.is_open())							//this deletes the content of the file and writes the new content
	{
		archivo << "nombre,cedula,telefono,correo,especialidad\n";
		archivo << e->toStringCSV();
		archivo.close();
	}
	else
	{
		std::cout << "No se pudo abrir el archivo" << std::endl;
	}
	
}

void FileManager::guardarProfesores(ListaProfesor* p, std::string nombreArchivo)
{
	std::ofstream archivo(nombreArchivo);
	if (archivo.is_open())
	{
		archivo << "nombre,cedula,telefono,correo,GradoAcademico\n";
		archivo << p->toStringCSV();
		archivo.close();
	}
	else
	{
		std::cout << "No se pudo abrir el archivo" << std::endl;
	}
	
}

void FileManager::guardarCursos(ListaCurso* c, std::string nombreArchivo)
{
	std::ofstream archivo(nombreArchivo);
	if (archivo.is_open())
	{
		archivo << "nombre,codigo,creditos,costo,estado\n";
		archivo << c->toStringCSV();
		archivo.close();
	}
	else
	{
		std::cout << "No se pudo abrir el archivo" << std::endl;
	}
	
}

void FileManager::guardarPeriodos(Escuela *e, std::string nombreArchivo)
{
	std::ofstream archivo(nombreArchivo);
	if (archivo.is_open())
	{
		archivo << e->PeriodosToStringCSV();	
		archivo.close();
	}
	else
	{
		std::cout << "No se pudo abrir el archivo" << std::endl;
	}
	
	
}

void FileManager::guardarGrupos(Escuela* e, std::string nombreArchivo)
{
	std::ofstream archivo(nombreArchivo);
	if (archivo.is_open())
	{
		//"codigo","ncr","cupo","cantEst",hrIni,hrFi,Horario,cedp,cedA1,cedA2,cedAn
		archivo << e->GruposToStringCSV();
		archivo.close();
	}
	else
	{
		std::cout << "No se pudo abrir el archivo" << std::endl;
	}

}



void FileManager::cargarEstudiantes(Escuela* escuela, std::string nombreArchivo)
{
	std::ifstream archivo(nombreArchivo);
	if (archivo.is_open())
	{
		std::string linea;
		std::getline(archivo, linea);
		while (std::getline(archivo, linea))
		{
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
	else
	{
		std::cout << "No se pudo abrir el archivo A" << std::endl;
	}
}

void FileManager::cargarProfesores(Escuela* escuela, std::string nombreArchivo)
{
	std::ifstream archivo(nombreArchivo);
	if (archivo.is_open())
	{
		std::string linea;
		std::getline(archivo, linea);
		while (std::getline(archivo, linea))
		{
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
	else
	{
		std::cout << "No se pudo abrir el archivo P" << std::endl;
	}

}

void FileManager::cargarCursos(Escuela* escuela, std::string nombreArchivo)
{
	std::ifstream archivo(nombreArchivo);
	if (archivo.is_open())
	{
		std::string linea;
		std::getline(archivo, linea);
		while (std::getline(archivo, linea))
		{
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
	else
	{
		std::cout << "No se pudo abrir el archivo C" << std::endl;
	}


}

void FileManager::cargarPeriodos(Escuela* escuela, std::string nombreArchivo)
{
//Periodo1,Periodo2,Periodo3,Periodo4
//	1,0,0,0
// // 1 means the period is enabled

	std::ifstream archivo(nombreArchivo);
	if (archivo.is_open())
	{
		//first enable the periods
		std::string linea;
		std::getline(archivo, linea);
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
		for (int i = 0; i < 4; i++)
		{
			std::getline(archivo, linea);
			std::stringstream s2(linea);
			std::string cantidadCursos;
			std::getline(s2, cantidadCursos, ',');
				for (int i = 0; i < std::stoi(cantidadCursos); i++) {
					//in the same line nesxt to the number of courses is the ncr
					std::string ncr;
					std::getline(s2, ncr, ',');
					escuela->buscarPeriodo(1)->insertarCurso(escuela->buscarCurso(ncr));
				}
		}
	//then add the groups to the courses


		archivo.close();
	}
	else
	{
		std::cout << "No se pudo abrir el archivo P" << std::endl;
	}


}

void FileManager::cargarGrupos(Escuela* escuela, std::string nombreArchivo)
{/*
Periodo 1
Codigo , Cant. Grupos
EIF201,2
ncr,cupo,cantEst,hrIni,hrFi,Horario,cedp,cedA1,cedA2,cedAn
1,10,2,11,12,1000101,4,1,2
2,10,1,5,6,1000000,NULL,24

Codigo , Cant. Grupos
MAT001,1
ncr,cupo,cantEst,hrIni,hrFi,Horario,cedp,cedA1,cedA2,cedAn
3,14,2,9,11,0100001,6,11,13

Periodo 2
Codigo , Cant. Grupos
MAT002,1
ncr,cupo,cantEst,hrIni,hrFi,Horario,cedp,cedA1,cedA2,cedAn
4,9,1,3,7,1111111,38,22

Periodo 3
Codigo , Cant. Grupos
EIF203,1
ncr,cupo,cantEst,hrIni,hrFi,Horario,cedp,cedA1,cedA2,cedAn
5,14,14,6,8,0000010,3,1,2,7,8,9,10,11,12,13,14,15,16,17,18
*/
	std::ifstream archivo(nombreArchivo);
	if (archivo.is_open())
	{
		std::string linea;
		std::getline(archivo, linea);
		while (std::getline(archivo, linea))
		{
			std::stringstream s(linea);
			std::string codigo, cantidadGrupos;
			std::getline(s, codigo, ',');
			std::getline(s, cantidadGrupos, ',');
			for (int i = 0; i < std::stoi(cantidadGrupos); i++) {
				std::getline(archivo, linea);
				std::stringstream s2(linea);
				std::string ncr, cupo, cantEst, hrIni, hrFi, Horario, cedp, cedA1, cedA2, cedAn;
				std::getline(s2, ncr, ',');
				std::getline(s2, cupo, ',');
				std::getline(s2, cantEst, ',');
				std::getline(s2, hrIni, ',');
				std::getline(s2, hrFi, ',');
				std::getline(s2, Horario, ',');
				std::getline(s2, cedp, ',');
				std::getline(s2, cedA1, ',');
				std::getline(s2, cedA2, ',');
				std::getline(s2, cedAn, ',');
			}
		}
		archivo.close();
	}
	else
	{
		std::cout << "No se pudo abrir el archivo G" << std::endl;
	}



}







