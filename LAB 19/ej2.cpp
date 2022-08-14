#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class SearchFunct {
public:
	void operator()(vector<int>::iterator ib, vector<int>::iterator ie, int x) {
		vector<int> res;
		unsigned int idx=0;
		while (ib != ie) {
			if (*ib == x) 
				res.push_back(idx);
			idx++;
			++ib;
		}
		if (res.empty())	
			cout << "No se encontro el valor en el vector.\n";
		else  {
			for (unsigned int i=0; i<res.size(); i++){
				cout << x << " encontrado en posicion ";
				cout << res.at(i) << "\n";
			}
			cout << endl;
		}
	}
};

int main(int argc, char *argv[]) {
	vector<int> searchList = {
		10, 12, 16, 81, 32, 54, 78,
		56, 9, 45, 78, 90, 101, 33, 
		21, 37, 49, 98, 67, 12, 89,
		78, 12, 90, 24, 59, 49, 56
	};
	SearchFunct searchVector;
	cout << "Busqueda en toda la lista: Valor 90" << endl;
	searchVector(searchList.begin(), searchList.end(), 90);
	cout << endl;
	cout << "Busqueda dentro de un rango: [1 - 10] Valor 90" << endl;
	searchVector(searchList.begin()+1, searchList.begin()+10, 90);
	return 0;
}

