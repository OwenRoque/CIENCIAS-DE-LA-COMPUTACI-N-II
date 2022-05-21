#include<iostream>
#include "arreglo.h"
using namespace std;

arreglo::arreglo(){
	for(int i=0;i<5;i++){
		arr[i]=0;
	}
	//arr = {0, 0, 0, 0, 0};
}

arreglo::~arreglo(){}

void arreglo::agregarDato(int value,int &pos){
	if (arr[4]!=0) //todos los valores pretederminados a 0 
		cout<<"Array lleno! elimine elementos para agregar nuevos datos."<<endl;
	else {
		arr[pos]=value;
	}
	cout<<endl;
}

void arreglo::removerDato(int value){
	bool vacio=true;
	for(int i=0;i<5;i++){
		if (arr[i]!=0){
			vacio=false;
			break;
		}
	}
	if (vacio)
		cout<<"Array Vacio! agregue elementos al arreglo."<<endl;
	else {
		for(int i=0;i<5;i++){
			if(arr[i]==value){
				arr[i]=0;
				int j=i;
				while (j!=4){
					int aux=arr[j+1];
					arr[j+1]=arr[j];
					arr[j]=aux;
					j++;
				}
				break;
			} //para eliminar solo al 1er dato coincidente
		}
	}
	cout<<endl;
}
void arreglo::mostrar(){
	for(int i=0;i<5;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
