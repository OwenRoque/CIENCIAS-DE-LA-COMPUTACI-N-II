#ifndef ELIPSE_H
#define ELIPSE_H

#include "Forma.h"
#include "Punto.h"
#include "Circulo.h"
#include <iostream>
using namespace std;

class Elipse : public Forma {
public:
	Elipse(char*, Punto*, string, float, float);
	~Elipse();
	void convertirCirculo(Circulo c);
	void imprimir();
	float area();
	float perimetro();
	void resize(float);
private:
	float radioMenor;
	float radioMayor;
};

#endif



