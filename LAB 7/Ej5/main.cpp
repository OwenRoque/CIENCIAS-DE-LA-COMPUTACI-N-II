#include "operacionBase.h"
#include "operacionFactorial.h"
#include<iostream>
using namespace std;

int main (int argc, char *argv[]) 	{
	operacionFactorial op;
	op.setOperador(7);
	cout<<"VALOR OPERADOR: "<<op.getOperador()<<endl;
	cout<<"Factorial: "<<op.devolverFactorial()<<endl;
	return 0;
}

