#include "matriz.h"
#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
matriz::matriz() {
	srand(time(NULL));
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			matrix[i][j]=1 + rand() % (10 - 1) ;
}

matriz::~matriz(){}

void matriz::mostrar(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
void matriz::buscar(int value){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(matrix[i][j]==value){
				cout<<"Valor Encontrado en: ";
				cout<<"["<<i<<"] ["<<j<<"]\n";
			}
		}
	}
	cout<<endl;
}



