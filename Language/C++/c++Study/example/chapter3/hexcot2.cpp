// hexcot2.cpp -- display values in hex and octal

#include <iostream>

using namespace std;

int main(){
	
	int chest = 42;
	int waist = 42;
	int inseam = 42;
	// dec : 使用十进制输出
	// hex : 使用十六进制输出
	// oct : 使用八进制输出 
	cout << dec << chest << endl;
	cout << hex << waist << endl;
	cout << oct << inseam << endl;
	
	return 0;
}
