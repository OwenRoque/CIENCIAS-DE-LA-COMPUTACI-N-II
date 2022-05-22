#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
public:
	Complex(int,int);
	~Complex();
	Complex operator+(Complex const & obj);
	void print();
private:
	int real, imag;
};

#endif

