#include <iostream>
#include <string>
#include <vector>

using namespace::std;
const int length = 4;
int* change(int n) {
	int s[length] = { 0 };
	int k = length - 1;
	while (n&&k >= 0) {
		s[k] = n % 10;
		n /= 10;
		k--;
	}
	return s;
}
 
bool equals(int n1, int n2, int k) {
	int * s1 = change(n1), *s2 = change(n2);
	for (int i = length - 1; i >= length - k; i--)
		if (s1[i] != s2[i])
			return false;
	return true;
}

int main() {
	int n1, n2, k;
	while (cin >> n1 >> n2 >> k && !(n1 == 0 && n2 == 0)) {
		if (equals(n1, n2, k))
			cout << -1 << endl;
		else
			cout << n1 + n2 << endl;
	}
	return 0;
}