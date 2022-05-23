#ifndef OPERACIONFACTORIAL_H
#define OPERACIONFACTORIAL_H
#include "operacionBase.h"
#include <iostream>
using namespace std;

class operacionFactorial : public operacionBase {
public:
	operacionFactorial();
	~operacionFactorial();
	int devolverFactorial();
private:
};

#endif

