#include <iostream>
using namespace std;
// LAB 02 - Bucles
// 2. Calcule los primeros 50 numeros primos y muestre el resultado en pantalla.
int main() {
	cout << "Lista de primos del 1 al 50: ";
	for(int i=1;i<51;i++){
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
	return 0;
}

