#include<iostream>
#include "matriz.h"
using namespace std;
//  5. Implementar un programa con clases que haga la b�squeda de un dato  
//	almacenado en una matriz de 3x3 que tiene los n�meros de 1 al 9 ingresados 
//	aleatoriamente y debe indicar la posici�n donde se encuentra el dato.
int main (int argc, char *argv[]) {
	matriz ma;
	ma.mostrar();
	int v;
	cout<<"Ingrese el dato a buscar: ";
	cin>>v;
	ma.buscar(v);
	return 0;
}

