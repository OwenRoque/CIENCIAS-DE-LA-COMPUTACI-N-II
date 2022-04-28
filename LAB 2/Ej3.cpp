#include <iostream>
using namespace std;
// LAB 02 - Bucles
// 3. Escribir un programa que visualice en pantalla los números múltiplos de 5 comprendidos entre 1 y 100.
int main() {
	cout<<"Multiplos de 5 entre 1 y 100: ";
	for (int i=1;i<101;i++){
		if (i%5==0)
			cout << i << " ";
	}
	return 0;
}

