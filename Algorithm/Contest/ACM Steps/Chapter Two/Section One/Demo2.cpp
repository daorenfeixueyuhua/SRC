#include <iostream>
#include <cmath>
using namespace::std;
bool isPrime(int n) {
	if (n == 1 || n == 0)
		return false;
	else {
		for (int i = 2; i <= sqrt(n); ++i)
			if (n%i==0)
				return false;
	}
	return true;
}
int main() {
	int n;
	while (cin >> n) {
		int cnt = 0;
		int *A = new int[n];
		for (int i = 0; i < n; ++i) {
			cin >> A[i];
			if (isPrime(A[i]))
				++cnt;
		}
		cout << cnt << endl;
	}
	return 0;
}