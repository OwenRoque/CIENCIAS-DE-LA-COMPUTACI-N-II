#include <iostream>
#include <memory>
using namespace std;

class C1 {
private:
	std::shared_ptr<double> d;
public:
	C1(std::shared_ptr<double> value) : d(value) {}
	virtual ~C1() { std::cout << "\nC1 destructor\n";}
	void print() const { 
		cout << "Valor: " << *d; 
	}
};

class C2 {
private:
	std::shared_ptr<double> d;
public:
	C2(std::shared_ptr<double> value) : d(value) {}
	virtual ~C2() { std::cout << "\nC2 destructor\n";}
	void print() const { 
		cout << "Valor: " << *d; 
	}
};

int main(int argc, char* argv[]) {
	return 0;
}
