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
	// cout.put(char) : ��ʾһ��char��������char�������ɴ��������<< 
	cout.put(i);
	cout.put('M');
	
	return 0;
}
