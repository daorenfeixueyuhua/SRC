// hexcot2.cpp -- display values in hex and octal

#include <iostream>

using namespace std;

int main(){
	
	int chest = 42;
	int waist = 42;
	int inseam = 42;
	// dec : ʹ��ʮ�������
	// hex : ʹ��ʮ���������
	// oct : ʹ�ð˽������ 
	cout << dec << chest << endl;
	cout << hex << waist << endl;
	cout << oct << inseam << endl;
	
	return 0;
}
