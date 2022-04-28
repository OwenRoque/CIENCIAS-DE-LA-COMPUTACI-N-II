#include <iostream>
using namespace std;
// LAB 03 - FUNCIONES
// 1. Hacer un programa que sin usar la función pow(), 
// pero por medio de una función, calcule la potencia 
// de un número (ambos números ingresados por teclado).
// Hecho con recursividad
int pow(int b, int exp){
	int c;
	if (exp==0)
		c=1;
	else 
		c=b*pow(b,exp-1);
	return c;
}
int main(int argc, char *argv[]) {
	int a, b, c;
	cout<<"Ingrese LOS 2 VALORES: ";
	cin>>a>>b;
	c=pow(a,b);
	cout<<"resultado: "<<c;
	return 0;
}

