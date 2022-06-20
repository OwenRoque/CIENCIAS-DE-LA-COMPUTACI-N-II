#include<iostream>
#include "Cola.h"
using namespace std;

int main (int argc, char *argv[]) {
	Cola<float> B;
	B.insertar(2.75);
	B.insertar(12.03);
	B.insertar(7.2);
	B.insertar(12.03);
	B.insertar(8.88);
	B.insertar(12.03);
	B.insertar(7.2);
	B.insertar(8.88);
	B.insertar(8.88);
	B.imprimir();
	B.search(8.88);
	B.search(12.03);
	return 0;
}

