#include<iostream>
#include "Cola.h"
using namespace std;
// ej 4
int main (int argc, char *argv[]) {
	int size_A, size_B, it=0;
	Cola<int> A, B;
	cout << "Ingrese tamanho de colas a comparar: ";
	cin >> size_A >> size_B;
	cout<<"Cola A: \n";
	fill(A,size_A);
	cout<<"Cola B: \n";
	fill(B,size_B);
	cout << endl;
	
	A.imprimir();
	B.imprimir();
	
	cout << "Nro de bucles: ";
	cin >> it;
	
	for (int i = 0; i < it; i++){
		int head_A = A.getFirstValue();
		int head_B = B.getFirstValue();
		if (head_A > head_B){
			A.reset();
		} else if (head_A == head_B){
			A.reset();
			B.reset();
		} else {
			B.reset();
		}
	}
	// para recuperar el mayor de la ultima iteración 
	// y no resetear la cola
	cout << "Comparacion final\n";
	int res;
	A.imprimir();
	B.imprimir();
	int head_A = A.getFirstValue();
	int head_B = B.getFirstValue();
	if (head_A > head_B){
		res = head_A;
	} else if (head_A == head_B){
		res = head_A;
	} else {
		res = head_B;
	}
	cout << "Mayor luego de " << it << " iteraciones: " << res << endl;
	return 0;
}

