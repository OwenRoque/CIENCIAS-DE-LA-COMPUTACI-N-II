#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
// pair<dtype,dtype> incluido en STL
//https://www.geeksforgeeks.org/pair-in-cpp-stl/
pair<T,T> findMaxMin(T val1, T val2, T val3){
	pair<T,T> res;
	vector<T> arr = {val1, val2, val3};
	auto max = max_element(arr.begin(),arr.end());
	auto min = min_element(arr.begin(),arr.end());
	// https://en.cppreference.com/w/cpp/algorithm/max_element
	res.first = arr.at(distance(arr.begin(), max));
	res.second = arr.at(distance(arr.begin(), min));
	return res;
}
	
int main(int argc, char *argv[]) {
	auto res1 = findMaxMin(5,8,-1);
	cout<<"Maximo valor: "<<res1.first<<endl;
	cout<<"Minimo valor: "<<res1.second<<endl;
	cout<<endl;
	auto res2 = findMaxMin(6.2,-1.7,14.3);
	cout<<"Maximo valor: "<<res2.first<<endl;
	cout<<"Minimo valor: "<<res2.second<<endl;
	cout<<endl;
	auto res3 = findMaxMin(3.141519487,5.12385798,-4.21654651);
	cout<<"Maximo valor: "<<res3.first<<endl;
	cout<<"Minimo valor: "<<res3.second<<endl;
	return 0;
}

