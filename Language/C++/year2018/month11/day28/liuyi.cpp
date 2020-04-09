#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace::std;
#define max 10
int N[max];
void mul(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = max - 1; N[j]; j--) {
			N[j] = N[j] * i;
		}
		int k = max - 1;
		while (N[k]) {
			N[k - 1] += N[k] / 10;
			N[k] %= 10;
			k--;
		}
	}
}
void out() {
	int i=0;
	while (!N[i])i++;
	while (i < max)
		cout << N[i++];
	cout << endl;
}
int main() {
	int n;
	while (cin >> n && n != -1) {
		memset(N, 0, sizeof(N));
		N[max - 1] = 1;
		mul(n);
		out();
	}
	return 0;
}