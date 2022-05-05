#include <iostream>
using namespace std;
// LAB 04 - ARRAY Y MATRICES
// Hacer un array unidimensional que acepte ocho números enteros. 
// Luego le pregunte al usuario que ingrese un número a buscar, 
// implementar una función que busque ese número, si lo encuentra, 
//	debe retornar un valor de verdaderos, en caso contrario, retornar falso.
void mostrar(int arr[]){
	for (int i=0;i<8;i++){
		cout<<arr[i]<<" ";
	}
}
bool buscar(int arr[],int x){
	for (int i=0;i<8;i++)
		if (arr[i]==x)
			return true;
	return false;
}
int main(int argc, char *argv[]) {
	int arr[8], x;
	for (int i=0;i<8;i++){
		cout<<"Numero "<<i+1<<": \n";
		cin>>arr[i];
	}
	mostrar(arr);
	cout<<endl;
	cout<<"\n************Ingrese numero a buscar: ****************\n";
	cin>>x;
	if(buscar(arr, x))
		cout<<"True";
	else
		cout<<"False";
	return 0;
}

