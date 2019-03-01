// floatnum.cpp -- floating-point types

#include <iostream>

using namespace std;

int main(){
	// cout 通常会删除结尾的零，而cout.setf()将覆盖这种行为。 
	cout.setf(ios_base::fixed, ios_base::floatfield);
	
	double f = 3.14;
	cout << f << endl;
	return 0;
}
