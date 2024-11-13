#include "Persona.h"

Persona::Persona(){}

Persona::Persona(std::string nombre, std::string cedula, std::string telefono, std::string correo)
:nombre(nombre), cedula(cedula), telefono(telefono), correo(correo){}

Persona::~Persona() {}
std::string Persona::getcedula() const{return cedula;}

std::string Persona::getnombre() const{return nombre;}