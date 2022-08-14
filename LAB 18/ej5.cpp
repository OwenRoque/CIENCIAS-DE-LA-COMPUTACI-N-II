#include <iostream>
using namespace std;
template <int N>
void toBinary() {
	toBinary<N/2>();
	cout << N%2;
}
template <>
void toBinary<0>() {
	return;
}

int main(int argc, char *argv[]) {
	cout << "Binario de 18 -> ";
	toBinary<18>();
	return 0;
}

