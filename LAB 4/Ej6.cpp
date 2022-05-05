#include <iostream>
using namespace std;
// LAB 04 - ARRAY Y MATRICES
// Escribe un programa que pida nueve números enteros y los almacene en una matriz 3x3.
//	Calcula la suma de los números de cada fila y mostrar por pantalla el número de fila con mayor suma.

const int n=3;
void llenar_mostrar(int a[][n]){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cout<<"Digite el numero ["<<i<<"]["<<j<<"]: ";
			cin>>a[i][j];
		}
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
}
int main(int argc, char *argv[]) {
	int arr[n][n],nfila,max=0;
	llenar_mostrar(arr);
	
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<n;j++){
			sum+=arr[i][j];
		}
		if (max<sum){
			nfila=i;
			max=sum;
		}
	}
	cout<<"NroFila: "<<nfila<<"\t\t"<<"Cantidad: "<<max<<endl;
	return 0;
}

