// divide.cpp -- integer and floating-point division

#include<iostream>

using namespace std;

int main(){
	cout.setf(ios_base::fixed, ios_base::floatfield);
	
	cout << "9 / 5 = " << 9 / 5 << endl;
	cout << "9.0 / 5.0 = " << 9.0 / 5.0 << endl;
	// 浮点常量默认为double类型 
	cout << "1e7 / 9.0 = " << 1e7 / 9.0 << endl;
	cout << "1e7f / 9.0f = " << 1e7f / 9.0f << endl;
	return 0;
} 
