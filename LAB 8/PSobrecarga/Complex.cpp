#include "Complex.h"
#include "iostream"
using namespace std;
Complex::Complex(int r = 0, int i = 0)
{
	real = r;
	imag = i;
}
Complex::~Complex()
{
}
// Esto se llama automáticamente cuando se usa '+' con entre dos objetos
//complejos
Complex Complex::operator+(Complex const &obj)
{
	Complex res;
	res.real = real + obj.real;
	res.imag = imag + obj.imag;
	return res;
	return Complex();
}
void Complex::print()
{
	cout << real << " + i" << imag << endl;
}
