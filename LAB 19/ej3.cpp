#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
using namespace std;

class Elementos {
public:
	int a;
	int b;
	Elementos (int _a, int _b) : a(_a), b(_b) {}
};

struct SortV {
	friend class Elementos;
	bool operator()(Elementos *e) { return (e->a < e->b); }
} sortFunct;

int main(int argc, char *argv[]) {
	vector<Elementos> vectorElem = {};
	srand(time(NULL));
	for (int i = 0; i < 20; i++){
		vectorElem.push_back(Elementos((0 + rand() % (51 - 1)), (0 + rand() % (51 - 1))));
		cout << vectorElem[i].a << "	";
		cout << vectorElem[i].b << endl;
	}
	
	std::sort(vectorElem.begin(), vectorElem.end(), sortFunct);
	
	return 0;
}
// a	b
// 4	4		
// 2	5	
// 7	10
// 6	1

