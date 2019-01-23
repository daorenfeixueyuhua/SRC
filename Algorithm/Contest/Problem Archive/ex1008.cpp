#include <iostream>
#include <cmath>
const int up = 6;
const int down = 4;
const int stop = 5;
const int length = 100;
using namespace::std;
int main() {
	int n;
	while (cin >> n && n) {
		int A[length + 1] = {0};
		int B[length + 1] = {0};
		int cnt = 0;
		A[0] = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> A[i];
			B[i] = A[i] - A[i - 1];
			if (B[i] > 0)
				cnt += B[i] * up;
			else
				cnt += abs(B[i]) * down;
			cnt += stop;
		}
		cout << cnt << endl;
	}
	return 0;
}