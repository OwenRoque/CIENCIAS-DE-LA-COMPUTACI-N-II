#include <iostream>
using namespace std;

// Implementacion de la clase Point
class Point {
private:
	double x, y;
public:
	Point(double x_axis, double y_axis) : x(x_axis), y(y_axis) {}
	void print() const {
		cout << "(" << x << "," << y << ")" << endl;
	}
	~Point() { 
		cout << "Punto destruido" << endl; 
	}
	void X(double x) {
		this->x = x;
	}
	void Y(double y) {
		this->y = y;
	};
};

void ejercicio() 
{
	double* d = new double(1.0);
	Point* pt = new Point(1.0, 2.0);
	*d = 2.0;
	(*pt).X(3.0);
	(*pt).Y(3.0);
	pt->X(3.0);
	pt->Y(3.0);
	delete d;
	delete pt;
}


int main(int argc, char *argv[]) {
	ejercicio();
	return 0;
}

