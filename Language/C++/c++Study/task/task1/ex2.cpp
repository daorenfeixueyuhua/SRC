#include <iostream>
using namespace std;


// exchang two numbers
template<typename T>
void exchange(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp
		;
}


// sort three numbers by degrees
void sort(double &a, double &b, double &c) {
	if (a > b)
		exchange(a, b);
	if (b > c)
		exchange(b, c);
	if (a > b)
		exchange(a, b);
}

int main() {
	double a = -1, b = -1, c = -1;

	cout << "please input three numbers: " << endl;
	cin >> a >> b >> c;

	cout << "the old numbers is " << a << " " << b << " " << c << endl;
	sort(a, b, c);
	cout << "the new numbers is " << a << " " << b << " " << c << endl;

	cin.get();
	cin.get();
	return 0;
}