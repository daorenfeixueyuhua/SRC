// floatnum.cpp -- floating-point types

#include <iostream>

using namespace std;

int main(){
	// cout ͨ����ɾ����β���㣬��cout.setf()������������Ϊ�� 
	cout.setf(ios_base::fixed, ios_base::floatfield);
	
	double f = 3.14;
	cout << f << endl;
	return 0;
}
