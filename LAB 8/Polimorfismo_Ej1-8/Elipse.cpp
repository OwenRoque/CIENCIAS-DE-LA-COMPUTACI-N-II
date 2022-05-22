#include "Forma.h"
#include "Punto.h"
#include "Elipse.h"
#include "Circulo.h"
#define PI 3.14159
#include <iostream>
using namespace std;

Elipse::Elipse(char* _nombre, Punto *_centro,string _color, float _rmenor, float _rmayor) 
	: Forma(_nombre,_centro,_color) {
	radioMenor = _rmenor;
	radioMayor = _rmayor;
}

Elipse::~Elipse() {}

void Elipse::convertirCirculo(Circulo c) {
	radioMenor = c.radio;
	radioMayor = c.radio;
}

void Elipse::imprimir(){
	Forma::imprimir();
	if (radioMayor == radioMenor)
		cout<<"Radio: "<<radioMayor<<endl;
	else {
		cout<<"Radio Menor: "<<radioMenor<<endl;
		cout<<"Radio Mayor: "<<radioMayor<<endl;
	}
}

float Elipse::area(){
	float area = PI*(radioMayor*radioMenor);
	return area;
}

float Elipse::perimetro(){
	if (radioMayor == radioMenor){
		float per = 2*PI*radioMayor;
		return per;
	}
	else
		return 0;
}

void Elipse::resize(float factor){
	radioMayor *= factor;
	radioMenor *= factor;
	if (radioMayor == radioMenor)
		cout<<"Nuevo Radio: "<<radioMayor<<endl;
	else {
		cout<<"Nuevo Radio Menor: "<<radioMenor<<endl;
		cout<<"Nuevo Radio Mayor: "<<radioMayor<<endl;
	}
}
