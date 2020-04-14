#include <iostream>
#include <vector>
using namespace std;

void addOne(int someInt) { //pass by value
	someInt += 1;
	//cout << someInt <<end;
}

int addOneV2(int someInt) {
	someInt += 1;
	//cout << someInt << endl;
	return someInt;
}

void printVec(vector<int> someVec) {
	for (int item : someVec) {
		cout << item << ' ';
	}
}
