#include "Forma.h"
#include "Punto.h"
#include "Rectangulo.h"
#include "Cuadrado.h"
#include <iostream>
using namespace std;

Rectangulo::Rectangulo(char* _nombre, Punto *_centro,string _color, float _menor, float _mayor) 
	: Forma(_nombre,_centro,_color){
	ladoMenor = _menor;
	ladoMayor = _mayor;
}

Rectangulo::~Rectangulo() {}

void Rectangulo::convertirCuadrado(Cuadrado c) {
	ladoMenor = c.lado;
	ladoMayor = c.lado;
}

void Rectangulo::imprimir(){
	Forma::imprimir();
	if (ladoMayor == ladoMenor)
		cout<<"Lado: "<<ladoMayor<<endl;
	else {
	cout<<"Lado Menor: "<<ladoMenor<<endl;
	cout<<"Lado Mayor: "<<ladoMayor<<endl;
	}
}

float Rectangulo::area(){
	float area = ladoMayor*ladoMenor;
	return area;
}

float Rectangulo::perimetro(){
	float per = 2*(ladoMayor+ladoMenor);
	return per;
}

void Rectangulo::resize(float factor){
	ladoMayor *= factor;
	ladoMenor *= factor;
	if (ladoMayor == ladoMenor)
		cout<<"Nuevo Lado: "<<ladoMayor<<endl;
	else {
	cout<<"Nuevo Lado Menor: "<<ladoMenor<<endl;
	cout<<"Nuevo Lado Mayor: "<<ladoMayor<<endl;
	}
}
