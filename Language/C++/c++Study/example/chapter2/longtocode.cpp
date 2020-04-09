// longtocode.cpp -- convert long to code

#include <iostream>
using namespace std;
int longtocode(int);

int main(){
	int value, code;
	cout << "Enter a value: ";
	cin >> value;
	code = longtocode(value);
	cout << value << " long = ";
	cout << code << " code" << endl;
	return 0;
}

int longtocode(int value){
	return value * 200;
}
