#include <iostream>
#include "rect.h"
using namespace std;

rect::rect(int _b, int _h){
	b = _b;
	h = _h;
}

rect::~rect(){}

void rect::area(){
	cout << "Area: " << b*h << endl;
}

void rect::perimetro(){
	cout << "Perimetro: " << 2*(b+h) << endl;
}
