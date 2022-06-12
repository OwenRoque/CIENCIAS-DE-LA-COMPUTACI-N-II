#include<iostream>
#include"Lista.h"
using namespace std;

int main (int argc, char *argv[]) {
	Lista<int> A;
	A.insertarFinal(450);
	A.insertarFinal(8);
	A.insertarFinal(10);
	A.insertarFinal(51);
	A.insertarInicio(4);
	A.insertarInicio(75);
	A.insertar(14,5);
	A.insertar(78,3);
	A.imprimir();
	A.eliminar(2);
	A.ordenamiento();
	return 0;
}

