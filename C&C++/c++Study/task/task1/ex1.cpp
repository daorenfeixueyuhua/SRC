#include <iostream>
using namespace std;

double max(double a = -1, double b = -1, double c = -1) {
	int max = -1;
	if (a > b)
		max = a;
	else max = b;
	if (max < c)
		max = c;
	return max;
}

int main() {
	double a = -1, b = -1, c = -1;

	cout << "please input some numbers: " << endl;
	cin >> a >> b >> c;

	double max_num = max(a, b, c);
	
	cout << a << " " << b << " " << c << " the maxinum is " << max_num << endl;

	cin.get();
	cin.get();
	return 0;
}