#include <iostream>
using namespace std;
// LAB 03 - FUNCIONES
// 1. Hacer un programa que sin usar la funci�n pow(), 
// pero por medio de una funci�n, calcule la potencia 
// de un n�mero (ambos n�meros ingresados por teclado).
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

