#pragma once
#include <iostream>
#include <sstream>
class Factura{
private:
	double precio;
	double subtotal;
	double iva;
	double descuento;
	double total;
public:
	//Constructores
	Factura(double precio,double Descuento);
	//Destructor
	virtual ~Factura();
	//Metodos
	static int calcularDescuento(int cantidadCursos, int cantidadCursosAnio);
	//Getters
	double getPrecio();
	double getSubtotal();
	double getIva();
	double getDescuento();
	double getTotal();
	//toString
	std::string toString();
};
//Esta clase es una clase de servicio que se encarga de calcular el precio de la factura