#include <iostream>
#include <memory>
using namespace std;

class Point {
private:
	double x, y;
public:
	Point(double x_axis, double y_axis) : x(x_axis), y(y_axis) {}
	void print() const {
		cout << "(" << x << "," << y << ")" << endl;
	}
	~Point() { 
		cout << "\nPunto " << "(" << x << "," << y << ")" << " destruido\n" << endl; 
	}
	void X(double x) {
		this->x = x;
	}
	void Y(double y) {
		this->y = y;
	};
};

class C1 {
private:
	std::shared_ptr<Point> d;
public:
	C1(std::shared_ptr<Point> value) : d(value) {
		cout << "\nC1 constructor\n";
	}
	virtual ~C1() { std::cout << "\nC1 destructor\n";}
	void print() const { 
		d->print();
	}
};

class C2 {
private:
	std::shared_ptr<Point> d;
public:
	C2(std::shared_ptr<Point> value) : d(value) {
		cout << "\nC2 constructor\n";
	}
	virtual ~C2() { std::cout << "\nC2 destructor\n";}
	void print() const { 
		d->print();
	}
};

int main(int argc, char* argv[]) {
	std::shared_ptr<Point> p(new Point(5.0,6.7));
	C1 c1(p);
	cout << "C1 -> ";	c1.print();
	C2 c2(p);
	cout << "C2 -> ";	c2.print();
	return 0;
}
