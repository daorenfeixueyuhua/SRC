// morechar.cpp -- the char type and int type contrasted

#include <iostream>

using namespace std;

int main(){
	
	char ch = 'M';
	int i = ch;
	
	cout << "The ASCII code for" << ch << " is " << i << endl;
	
	ch = ch + 1;
	i = ch;
	
	cout << "The ASCII code for" << ch << " is " << i << endl;
	// cout.put(char) : 显示一个char变量或者char常量，可代替运算符<< 
	cout.put(i);
	cout.put('M');
	
	return 0;
}
