#include <iostream>
using namespace std;

template <class T>
class Array {
private:
	T* ptr;
	int size;
public:
	Array(T arr[], int s) {
		ptr = new T[s];
		size = s;
		for (int i = 0; i < size; i++)
			ptr[i] = arr[i];
	}
	void print() {
		for (int i = 0; i < size; i++)
			cout << " - " << *(ptr + i);
		cout << endl;
	};
	void insert(T add) {
		size++;
		T *tmpPtr = new T[size];
		for (int i = 0; i < size; i++)
			tmpPtr[i] = ptr[i];
		delete ptr;
		tmpPtr[size-1] = add;
		ptr = tmpPtr;
	}
};

int main(int argc, char *argv[]) {
	float arr[5] = { 4.1, 2.56, 3.07, 5.15, 10.12 };
	Array<float> a(arr, 5);
	cout << "Array Inicial: " << endl;
	a.print();
	cout << "Agregando un valor: " << endl;
	a.insert(6.98);
	a.print();
	cout << "Agregando varios valores: " << endl;
	a.insert(7.102);
	a.insert(13.001);
	a.insert(20.99);
	a.insert(0.04);
	a.print();
	system("pause");

	return 0;
}

