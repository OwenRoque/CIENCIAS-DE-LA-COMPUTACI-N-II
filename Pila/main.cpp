#include<iostream>
#include "Pila.h"
using namespace std;

int main (int argc, char *argv[]) {
	Pila<int> A;
	A.insertar(1);
	A.insertar(2);
	A.insertar(1);
	A.insertar(1);
	A.insertar(5);
	A.insertar(6);
	A.insertar(8);
	A.insertar(8);
	A.insertar(2);
	A.imprimir();
	A.search(1);
	A.search(2);
	return 0;
}

