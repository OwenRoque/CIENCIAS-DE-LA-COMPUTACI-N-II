#include <iostream>
using namespace std;
// LAB 02 - Bucles
// 4. Escriba un código que solicite ingresar dos números 𝑥 y 𝑦, tal que 𝑥 < 𝑦.
// Muestre todos los números primos que se encuentren entre el rango de valores,
// de no encontrarse, mostrar el primo más cercano a 𝑥 o 𝑦.

int main(int argc, char *argv[]) {
	int x, y;
	cout<<"ingrese x, y: x<y ";
	cin>>x>>y;
	if (x==y || y<x){ 
		cout<<"X debe ser menor que Y";
		return 0;
	}
	bool primo=true;
	for(int i=x;i<y;i++){
		int divisor=2;
		while(divisor <= i/2 && primo){
			if (i%divisor == 0)
				primo=false;
			divisor++;
		}
		if (primo)
			cout << i << " ";		
	}
	if (primo==false){
		//primos cercanos x o y
	}
}

