// limits.cpp -- some integer limits

#include <iostream>
#include <climits>

using namespace std;

int main(){
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;
	
	cout << "int is " << sizeof(int) << "bytes." << endl;
	cout << "short is " << sizeof(short) << "bytes." << endl;
	cout << "long is " << sizeof(long) << "bytes." << endl;
	cout << "long long is " << sizeof(long long) << "bytes." << endl;
	
	cout << "Maxinum values:" << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;
	cout << "long long: " << n_llong << endl;
	
	cout << "Minmum int values: " << INT_MIN << endl;
	cout << "Bites per byte = " << CHAR_BIT << endl;	
	return 0;
}
