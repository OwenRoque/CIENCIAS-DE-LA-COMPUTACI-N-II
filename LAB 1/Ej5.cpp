#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;
// LAB 01 - Condicionales
// 5. Elabore un código que reciba como entrada una secuencia de caracteres que 
// contiene un numero flotante y retorne el número redondeado.
int main(int argc, char *argv[]) {
	char input[] = "asd45dt65dfhs5";
	char out[100], index=0;
	for(int i=0;i<14;i++){
		if (isdigit(input[i])){
			out[index]=input[i];
			index++;
		}
	}
	for(int i=0;i<index;i++)
		cout<<out[i];
	return 0;
}

