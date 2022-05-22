#ifndef FORMA_H
#define FORMA_H
#include "Punto.h"
#include <iostream>
using namespace std;
//class Punto;
class Forma {
public:
	Forma(char*,Punto*,string);
	~Forma();
	virtual void imprimir();
	virtual void cambiarColor();
	virtual void cambiarColor(string);
	virtual void moverForma();
	virtual void moverForma(float,float);
	virtual float area() = 0;
	virtual float perimetro() = 0;
	virtual void resize(float) = 0;
protected:
	char* nombre;
	Punto *coord_centro; 
	string color;
};
#endif
