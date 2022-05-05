#include <iostream>
using namespace std;
// LAB 04 - ARRAY Y MATRICES
// Implementar un programa que rellene un array con los números primos comprendidos 
// entre 1 y 100 y los muestre en pantalla en orden descendente.

int main(int argc, char *argv[]) {
	int arr[100],x=0;
	for(int i=2;i<100;i++){ //Codigo reusado de la practica anterior
		bool primo=true;
		int divisor=2;
		while(divisor <= i/2 && primo){
			if (i%divisor == 0)
				primo=false;
			divisor++;
		}
		if (primo){
			arr[x]=i;
			x++;
		}
	}
	for(int i=x-1;i>=0;i--)
		cout<<arr[i]<<" ";
	return 0;
}

