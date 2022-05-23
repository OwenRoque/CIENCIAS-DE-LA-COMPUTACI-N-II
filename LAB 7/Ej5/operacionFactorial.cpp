#include "operacionBase.h"
#include "operacionFactorial.h"
#include <iostream>
using namespace std;

operacionFactorial::operacionFactorial() {}

operacionFactorial::~operacionFactorial() {}

int operacionFactorial::devolverFactorial(){
	int res=1;
	for (int i = 1; i <= operador; i++)
		res*=i;
	return res;
}
