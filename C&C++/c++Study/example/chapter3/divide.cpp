// divide.cpp -- integer and floating-point division

#include<iostream>

using namespace std;

int main(){
	cout.setf(ios_base::fixed, ios_base::floatfield);
	
	cout << "9 / 5 = " << 9 / 5 << endl;
	cout << "9.0 / 5.0 = " << 9.0 / 5.0 << endl;
	// ���㳣��Ĭ��Ϊdouble���� 
	cout << "1e7 / 9.0 = " << 1e7 / 9.0 << endl;
	cout << "1e7f / 9.0f = " << 1e7f / 9.0f << endl;
	return 0;
} 
