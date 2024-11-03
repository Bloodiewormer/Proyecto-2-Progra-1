#pragma once
#include <iostream>
#include <sstream>

class Factura
{
private:
	double precio;
	double subtotal;
	double iva;
	double descuento;
	double total;
public:
	Factura(double precio,double Descuento);
	virtual ~Factura();
	static int calcularDescuento(int cantidadCursos, int cantidadCursosAnio);
	double getPrecio();
	double getSubtotal();
	double getIva();
	double getDescuento();
	double getTotal();
	std::string toString();
};

