#include <iostream>
using namespace std;
// LAB 04 - ARRAY Y MATRICES
// 3. Hacer un array 5x3 que acepte números enteros ingresados por el usuario. 
// Al final, debe mostrar la suma de todos los números que estén en una fila par.

const int n=5, y=3;
void mostrar(int ma[][y]){
	for (int i=0;i<n;i++){
		for (int j=0;j<y;j++)
			cout<<ma[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
}
int main(int argc, char *argv[]) {
	int arr[n][y],s=0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < y; j++){
			cout<<"Digite el numero ["<<i<<"]["<<j<<"]: ";
			cin>>arr[i][j];
		}
	}
	mostrar(arr);
	for (int i = 0; i < n; i++){
		if (i%2==0){
			for (int j = 0; j < y; j++)
				s+=arr[i][j];
		}
	}
	cout<<"Suma filas pares: "<<s<<endl;
	return 0;
}

