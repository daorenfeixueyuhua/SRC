#include <iostream>
#include <string>
using namespace std;

const int MAX = 20;

// exchang two numbers
template<typename T>
void exchange(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp
		;
}

// bubbling sort-int
void sort(int A[MAX], int n) {
	for (int i = n -1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (A[j] > A[j + 1])
				exchange(A[j], A[j + 1]);
}

// bubbling sort-float
void sort(float A[MAX], int n) {
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (A[j] > A[j + 1])
				exchange(A[j], A[j + 1]);
}

// bubbling sort-double
void sort(double A[MAX], int n) {
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (A[j] > A[j + 1])
				exchange(A[j], A[j + 1]);
}

// bubbling sort-char
void sort(char A[MAX], int n) {
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (A[j] > A[j + 1])
				exchange(A[j], A[j + 1]);
}
int main() {

	// update int type to char, float, double type
	int A[MAX];
	int n;
	cout << "please input a value: ";
	cin >> n;

	cout << "please input " << n << " numbers :" << endl;
	for (int i = 0; i < n; ++i)
		cin >> A[i];

	sort(A, n);

	cout << "after the sorted: ";
	for (int i = 0; i < n; ++i)
		cout << A[i] << " ";
	cout << endl;

	cin.get();
	cin.get();
	return 0;
}