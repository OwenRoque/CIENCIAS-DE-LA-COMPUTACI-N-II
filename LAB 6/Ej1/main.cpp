#include <iostream>
#include "rect.h"
using namespace std;
// 1. Implemente un programa con clases que calcule
// el �rea de un rect�ngulo y per�metro.

int main()
{
	int b, h;
	cout<<"Base y altura del rectangulo: "<<endl;
	cin>>b>>h;
	rect Rectangle(b,h);
	Rectangle.area();
	Rectangle.perimetro();
	
	return 0;
}

