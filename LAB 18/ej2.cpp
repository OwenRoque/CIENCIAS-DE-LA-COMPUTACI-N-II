#include <iostream>
using namespace std;

template <unsigned int N>
struct posFibonacci {
	enum {
		value = posFibonacci<N-1>::value + 
				posFibonacci<N-2>::value 
	};
};

template <>
struct posFibonacci <0> {
	enum { value = 0 };
};

template <>
struct posFibonacci <1> {
	enum { value = 1 };
};

int main(int argc, char *argv[]) {
	int x = posFibonacci<5>::value;
	cout << "posFibonacci<5> -> " << x << endl;
	system("pause");
	return 0;
}


