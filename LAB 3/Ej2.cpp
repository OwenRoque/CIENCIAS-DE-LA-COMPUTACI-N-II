#include <iostream>
using namespace std;
// LAB 03 - FUNCIONES
// 2. Hacer un programa que lea por teclado un a�o, calcule y muestre si es bisiesto. 
// Para realizar el c�lculo utiliza una funci�n llamada bisiesto. 
// La funci�n bisiesto recibe el a�o le�do por teclado, 
//	comprueba si es o no bisiesto.
bool esBisiesto(int y){
	if ((y % 4 ==0 && y % 100 !=0)|| y % 400==0)
		return true;
	else 
		return false;
}

int main(int argc, char *argv[]) {
	int a;
	cout<<"Ingrese el a�o: \n";
	cin>>a;
	if (esBisiesto(a))
		cout<<"El a�o ingresado es bisiesto.";
	else
		cout<<"El a�o ingresado NO es bisiesto.";
	return 0;
}

