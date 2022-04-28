#include <iostream>
using namespace std;
// LAB 03 - FUNCIONES
// 5. Desarrollar un programa, utilizando funciones con un tipo de retorno,
// con las siguientes opciones:
// a. Introducir un valor x entero comprendido entre 0 y 100.
// b. Validar que sea un valor par.
// c. Sumar todos los números impares desde el 0 hasta el valor de x.

bool validarIntervalo(int x){
	if (x > 0 && x <=100)
		return true;
	else {
		cout<<"No esta entre 0 y 100.";
		return false;
	}
}
bool validarPar(int x){
	if (x %2==0)
		return true;
	else {
		cout<<"No es par.";
		return false;
	}
}
int sumaImpar(int x){
	int r=0;
	for(int i=0;i<x;i++){
		if (i%2!=0)
			r+=i;
	}
	return r;
}
int main(int argc, char *argv[]) {
	int x;
	cin>>x;
	if (validarIntervalo(x)){
		if (validarPar(x)){
			cout<<"Suma impar: "<<sumaImpar(x);
		}
	}
	return 0;
}

