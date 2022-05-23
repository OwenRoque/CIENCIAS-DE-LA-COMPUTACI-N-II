#include "Color.h"
#include "Material.h"
#include "Objeto.h"
#include <iostream>
using namespace std;

Objeto::Objeto (string _obj, int _r, int _g, int _b, string _mat) {
	obj = _obj;
	R = _r;
	G = _g;
	B = _b;
	material = _mat;
}

Objeto::~Objeto() {
	
}

void Objeto::describirObj(){
	cout<<obj<<" de color "<<"("<<R<<", "<<G<<", "<<B<<"), y material de "<<material<<".\n";
}


