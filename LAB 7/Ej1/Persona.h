#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;

class Persona {
public:
	Persona(int,string);
	~Persona();
	void setNombre();
	void setEdad();
	void mostrar();
protected:
	int edad;
	string nombre;
};

#endif

