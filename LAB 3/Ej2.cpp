#include <iostream>
using namespace std;
// LAB 03 - FUNCIONES
// 2. Hacer un programa que lea por teclado un año, calcule y muestre si es bisiesto. 
// Para realizar el cálculo utiliza una función llamada bisiesto. 
// La función bisiesto recibe el año leído por teclado, 
//	comprueba si es o no bisiesto.
bool esBisiesto(int y){
	if ((y % 4 ==0 && y % 100 !=0)|| y % 400==0)
		return true;
	else 
		return false;
}

int main(int argc, char *argv[]) {
	int a;
	cout<<"Ingrese el año: \n";
	cin>>a;
	if (esBisiesto(a))
		cout<<"El año ingresado es bisiesto.";
	else
		cout<<"El año ingresado NO es bisiesto.";
	return 0;
}

