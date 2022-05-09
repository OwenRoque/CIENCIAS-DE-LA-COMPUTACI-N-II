#include <stdlib.h>
#include <time.h>
#include <iostream>
#define N 1000000 			// Cambiar el valor de N a 1 000 000
using namespace std;
// LAB 05 - PUNTEROS
// Cree dos vectores con valores flotantes y asígnele valores aleatorios, 
// para esto deberá de asignar memoria a cada vector. 
// Calcule el producto punto de vectores y muestre por pantalla. 
// Una vez finalizado este proceso, retire la memoria asignada a los punteros. 
// Repita este proceso de asignación y retiro de memoria dentro de un for de 1 000 000 veces.
int* fill(){
	int* arr = new int[10];
	//srand(time(NULL));
	for (int i=0;i<10;i++){
		arr[i]=rand()%10;
		cout<<arr[i]<<" "; 
	}
	cout<<endl;
	return arr;
}
void PPunto(int* a, int* b){
	int vect[10], res=0;
	for(int i=0;i<10;i++){
		vect[i]=(*(a+i))*(*(b+i));
		cout<<vect[i]<<" ";
		res+=vect[i];
	}
	cout<<endl;
	cout<<"Producto punto: "<<res<<endl;
}
int main(int argc, char *argv[]) {
	srand(time(NULL));
	for(int i=0; i<N; i++){
		int *a=NULL, *b=NULL;
		a=fill();
		b=fill();
		PPunto(a,b);
		cout<<endl;
		delete [] a;
		delete [] b;
		a=NULL;
		b=NULL;
	}
	return 0;
}

