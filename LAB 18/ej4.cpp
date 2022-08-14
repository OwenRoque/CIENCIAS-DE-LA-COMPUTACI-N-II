#include <iostream>
using namespace std;

string res; 
template <int N>
void hexa() {
	hexa<N/16>();
	if(N%16>9){
		//cout<<char(N%16+55);
		res.push_back(char(N%16+55));
	}
	else {
		//cout<<N%16;
		res.append(to_string(N%16));
	}
}
template<>
void hexa<0>(){
	return;
}

int main(int argc, char *argv[]) {
	hexa<1535>();
	cout << "1535 a Hex -> " << res << endl;
	system("pause");
	return 0;
}

