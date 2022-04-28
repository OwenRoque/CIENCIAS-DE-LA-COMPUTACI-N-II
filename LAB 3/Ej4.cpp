#include <iostream>
using namespace std;
// LAB 03 - FUNCIONES
// 4. Hacer un programa que desarrolle una función, que genere en pantalla el 
// listado de números primos ubicados entre 1 hasta un numero x 
// (x es ingresado por teclado).
void listaPrimos(int n){ //Codigo reusado de la practica anterior
	for(int i=2;i<n;i++){
		//1 por convención 1 no es numero primo, asi que empezamos de 2
		bool primo=true;
		int divisor=2;
		while(divisor <= i/2 && primo){
			if (i%divisor == 0)
				primo=false;
			divisor++;
		}
		if (primo)
			cout << i << " ";		
	}
}
int main(int argc, char *argv[]) {
	int n;
	cout<<"Ingrese un numero: ";
	cin>>n;
	listaPrimos(n);
	return 0;
}

