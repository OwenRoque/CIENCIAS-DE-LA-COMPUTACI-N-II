#include "Complex.h"
#include <iostream>
using namespace std;
int main()
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2; // Un ejemplo de llamado al "operator+"
	c3.print();
	system("pause");
}

