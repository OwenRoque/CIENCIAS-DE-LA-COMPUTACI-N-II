#include "Color.h"
#include "Material.h"
#include "Objeto.h"
#include<iostream>
using namespace std;
//Crear una clase Color que mantenga 3 valores (RGB). Una segunda clase Material,
//tendr� como informaci�n una variable de texto que describa alg�n material (Ejemplo:
//madera, vidrio, platico, etc.) Una tercera clase, Objetos, deber� de heredar contenido
//de ambas clases con la finalidad de describir diferentes objetos en cuanto a color y el
//material. (Ejemplo: mesa de color caf� y material de pl�stico)
int main (int argc, char *argv[]) {
	Objeto Nuevo = Objeto("Silla",250,122,255,"vidrio");
	Nuevo.describirObj();
	return 0;
}

