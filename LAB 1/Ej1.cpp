#include <iostream>
using namespace std;
// LAB 01 - Condicionales
// 1. Escriba un código que solicite al usuario ingresar dos números enteros y que muestre el producto de ambos.

int main(){
	int x, y;
	cout << "Ingresar 2 numeros: ";
	cin >> x >> y;
	int z = x*y;
	cout << "Producto: " << z;
	return 0;
}
