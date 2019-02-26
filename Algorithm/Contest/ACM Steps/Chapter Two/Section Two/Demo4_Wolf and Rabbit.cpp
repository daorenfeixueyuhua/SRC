#include <iostream>
using namespace::std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	int P, m, n;
	cin >> P;
	while (P--) {
		cin >> m >> n;
		if (gcd(m,n)==1)
			cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}