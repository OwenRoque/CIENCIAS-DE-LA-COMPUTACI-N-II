#include <iostream>
using namespace std;
// LAB 05 - PUNTEROS
// 1. Asignar valores a dos variables enteras, intercambie estos 
// valores almacenados usando solo punteros a enteros.

void switchvalues(int &a, int &b){
	int aux=a;
	a=b;
	b=aux;
}
int main(int argc, char *argv[]) {
	int a, b;
	cout<<"Valor A: \n";
	cin>>a;
	cout<<"Valor B: \n";
	cin>>b;
	switchvalues(a,b);
	cout<<"Valor NuevoA: "<<a<<endl;
	cout<<"Valor NuevoB: "<<b<<endl;
	return 0;
}

