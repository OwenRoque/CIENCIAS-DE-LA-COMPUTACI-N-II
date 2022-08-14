#include <iostream>
using namespace std;

template <int N>
struct SumDigitos {
	enum { 
		value = (N % 10) + SumDigitos<N/10>::value 
	};
};
template <>
struct SumDigitos <0> {
	enum { value = 0 };
};

int main(int argc, char *argv[]) {
	int x = SumDigitos<1564>::value;
	cout << "Suma de 1564 -> " << x << endl;
	system("pause");
	return 0;
}

