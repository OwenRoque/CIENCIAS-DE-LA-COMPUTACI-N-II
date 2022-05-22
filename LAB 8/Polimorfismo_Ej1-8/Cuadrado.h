// Guia adquirida de: https://m.cplusplus.com/doc/tutorial/inheritance/
#ifndef CUADRADO_H
#define CUADRADO_H

#include "Forma.h"
#include "Punto.h"
#include "Rectangulo.h"
#include <iostream>
using namespace std;

class Cuadrado{
friend class Rectangulo;
public:
	Cuadrado(float);
	~Cuadrado();
private:
	float lado;
};

#endif

