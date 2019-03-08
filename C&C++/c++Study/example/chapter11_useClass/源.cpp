#include <iostream>
#include "comlpex.h"

using namespace std;

int main() {
	comlpex a(3.0, 4.0);
	comlpex c;
	cin >> c;
	cout << "a is: " << a << endl;
	cout << "c is: " << c << endl;
	cout << "a+c is: " << a + c << endl;
	cout << "a-c is: " << a - c << endl;
	cout << "a*c is: " << a * c << endl;
	cout << "2*a is: " << 2 * a << endl;
	cout << "c*2 is: " << c * 2 << endl;
	cout << "~a  is: " << ~a	<< endl;
	cin.get();
	cin.get();
	return 0;
}