#include<iostream>
#include<iomanip>
#include "Pila.h"
using namespace std;
int main (int argc, char *argv[]) {
	Pila<int> org; // origen
	Pila<int> aux; // auxiliar
	Pila<int> dest; // destino
	int n;
	cout<<"Ingresa el nro de discos: ";
	cin>>n;
	for (int v=1;v<=n;v++){
		org.insertar(v);
	}
	// funciona con la pila ya ordenada, con el 
	// puntero first siendo el menor value de 
	// la pila (torre), con recursividad
	imprimirHanoi(org,dest,aux);
	hanoi(org.getSize(),org,dest,aux);
	imprimirHanoi(org,dest,aux);
	return 0;
}

