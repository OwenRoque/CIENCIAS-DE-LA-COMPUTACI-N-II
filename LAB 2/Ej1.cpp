#include <iostream>
using namespace std;
// LAB 02 - Bucles
// 1. Sumar todos los enteros pares desde 2 hasta 100.

int main() {
	int x=0;
	for (int i=2; i<=100; i+=2)
		x+=i;
	cout << "Suma de numeros enteres desde 2 al 100: "<< x;
	return 0;
}

