#include "Punto.h"
#include <iostream>
using namespace std;

Punto::Punto(float _x, float _y) {
	this->x = _x;
	this->y = _y;
}

Punto::~Punto(){}

float Punto::getX(){
	return x;
}

float Punto::getY(){
	return y;
}
