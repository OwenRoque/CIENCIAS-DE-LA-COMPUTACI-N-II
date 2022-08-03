#include <iostream>
using namespace std;

template <class T>
class calc {
public:
	T suma(T a, T b) {
		return a+b;
	}
	T resta(T a, T b){
		return a -b;
	}
	T mult(T a, T b){
		return a*b;
	}
	T div(T a, T b){
		return a/b;
	}
};

int main(int argc, char *argv[]) {
	calc<int> *iCalc = new calc<int>;
	calc<float> *fCalc = new calc<float>;
	cout << "Suma Enteros: (5, 4) -> " <<  iCalc->suma(5, 4) << endl;
	cout << "Resta Enteros: (5, 4) -> " << iCalc->resta(5, 4) << endl;
	cout << "Multiplicacion Enteros: (5, 4) -> " << iCalc->mult(5, 4) << endl;
	cout << "Divison Enteros: (5, 4) -> " << iCalc->div(5, 4) << endl;
	cout << endl;
	cout << "Suma Flotantes: (7.5, 3.5) -> " <<  fCalc->suma(7.5, 3.5) << endl;
	cout << "Resta Flotantes: (7.5, 3.5) -> " << iCalc->resta(7.5, 3.5) << endl;
	cout << "Multiplicacion Flotantes: (7.5, 3.5) -> " 
		 << fCalc->mult(7.5, 3.5) << endl;
	cout << "Divison Flotantes: (7.5, 3.5) -> " << fCalc->div(7.5, 3.5) << endl;
	
	delete iCalc;
	delete fCalc;
	return 0;
}

