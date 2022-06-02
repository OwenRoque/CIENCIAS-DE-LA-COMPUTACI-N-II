#include <iostream>
using namespace std;
// T entero, S float
template <typename T, typename S>
S suma(T a, S b){
	return a + b;
}
template <typename T, typename S>	
S resta(T a, S b){
	return a - b;
}
template <typename T, typename S>
S mult(T a, S b){
	return a * b;
}
template <typename T, typename S>
S divis(T a, S b){
	return a / b;
}
template <typename T, typename S>
void calculadora(T a, S b){
	cout<<"Suma: "<<suma(a,b)<<endl;
	cout<<"Resta: "<<resta(a,b)<<endl;
	cout<<"Multiplicacion: "<<mult(a,b)<<endl;
	cout<<"Division: "<<divis(a,b)<<endl;
}
// El resultado en base al datatype 
// de la 2da variable
int main(int argc, char *argv[]) {
	calculadora(5,4.15);
	cout<<endl;
	calculadora(2.1,5.3);
	cout<<endl;
	return 0;
}

