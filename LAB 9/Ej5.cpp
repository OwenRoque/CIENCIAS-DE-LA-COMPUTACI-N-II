#include <iostream>
using namespace std;
template <typename P>
void printArray(P* arr, int size){
	for (int i=0;i<=size;i++){
		cout<<arr[i]<<" - ";
	}
	cout<<endl;
	delete [] arr;
}
template <typename P>
P* ascendente(P* arr, int first, int last){
	//array copia a ordenar
	P* arr_ord = new P[last+1];
	for (int i=0;i<=last;i++){
		arr_ord[i]=arr[i];
	}
	//metodo de burbuja
	P aux;
	for(int i=0;i<=last;i++){
		for(int j=0;j<=last-1;j++){
			if(arr_ord[j] > arr_ord[j+1]){
				aux = arr_ord[j];
				arr_ord[j] = arr_ord[j+1];
				arr_ord[j+1] = aux;
			}
		}
	}
	return arr_ord;
}
	
template <typename P>
P* descendente(P* arr, int first, int last){
	//array copia a ordenar
	P* arr_ord = new P[last+1];
	for (int i=0;i<=last;i++){
		arr_ord[i]=arr[i];
	}
	//metodo de burbuja
	P aux;
	for(int i=0;i<=last;i++){
		for(int j=0;j<=last-1;j++){
			if(arr_ord[j] < arr_ord[j+1]){
				aux = arr_ord[j];
				arr_ord[j] = arr_ord[j+1];
				arr_ord[j+1] = aux;
			}
		}
	}
	return arr_ord;
}
int main(int argc, char *argv[]) {
	int ArrayEntero [9] = {5,7,2,8,6,1,3,4,9};
	float ArrayFloat [5] = {10.1, 8.4, 3.6, 4.4, 11.2};
	int* ar1Ptr = ArrayEntero;
	float* ar2Ptr = ArrayFloat;
	cout<<"ArrayEntero ordenado Ascendente: ";
	printArray(ascendente(ar1Ptr,0,8),8);
	cout<<endl;
	cout<<"ArrayEntero ordenado Descendente: ";
	printArray(descendente(ar1Ptr,0,8),8);
	cout<<endl;
	cout<<"ArrayFloat ordenado Ascendente: ";
	printArray(ascendente(ar2Ptr,0,4),4);
	cout<<endl;
	cout<<"ArrayFloat ordenado Descendente: ";
	printArray(descendente(ar2Ptr,0,4),4);
	cout<<endl;
	return 0;
}

