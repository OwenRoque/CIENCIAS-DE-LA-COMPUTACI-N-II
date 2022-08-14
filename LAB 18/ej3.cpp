#include <iostream>
using namespace std;

template <int B, int EXP>
struct Power
{
	enum { value = B * Power<B, EXP-1>::value };
};
template <int B>
struct Power <B, 0>
{
	enum { value = 1 };
};

int main(int argc, char *argv[]) {
	int x = Power<4,6>::value;
	cout << "Potencia de 4 a la 6 -> " << x << endl;
	system("pause");
	return 0;
}

