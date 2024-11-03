#include "Factura.h"

Factura::Factura(double precio, double descuento) : precio(precio), descuento(descuento), subtotal(0), iva(0), total(0)
{
	this->subtotal = precio - (precio * descuento / 100);
	this->iva = subtotal * 0.13;
	this->total = subtotal + iva;
}

Factura::~Factura()
{
}

int Factura::calcularDescuento(int cantidadCursos, int cantidadCursosAnio)
{
	if (cantidadCursos >= 2 && cantidadCursosAnio >= 4)
	{
		return 40;
	}
	else if (cantidadCursos >= 2)
	{
		return 15;
	}
	else
	{
		return 0;
	}
}

double Factura::getPrecio()
{
	return precio;
}

double Factura::getSubtotal()
{
	return subtotal;
}

double Factura::getIva()
{
	return iva;
}

double Factura::getDescuento()
{
	return descuento;
}

double Factura::getTotal()
{
	return total;
}

std::string Factura::toString()
{
	std::stringstream s;
	s << "precio: " << precio << "\n";
	s << "subtotal: " << subtotal << "\n";
	s << "iva: " << iva << "\n";
	s << "descuento: " << descuento << "\n";
	s << "total: " << total << "\n";
	return s.str();
}
