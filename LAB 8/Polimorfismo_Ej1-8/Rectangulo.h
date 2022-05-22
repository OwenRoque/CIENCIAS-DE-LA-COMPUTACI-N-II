#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Forma.h"
#include "Punto.h"
#include "Cuadrado.h"
#include <iostream>
using namespace std;

class Rectangulo : public Forma {
public:
	Rectangulo(char*, Punto*, string, float, float);
	~Rectangulo();
	void convertirCuadrado(Cuadrado c);
	void imprimir();
	float area();
	float perimetro();
	void resize(float);
private:
	float ladoMenor;
	float ladoMayor;
};

#endif



