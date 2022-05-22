#ifndef PUNTO_H
#define PUNTO_H
#include <iostream>
using namespace std;

class Punto {
friend class Forma;
public:
	Punto(float,float);
	~Punto();
	float getX();
	float getY();
protected:
	float x;
	float y;
	
};

#endif


