#include <iostream>
#include <string>
using namespace std;


int main() {
	string s;
	cout << "Enter a string: ";
	cin >> s;
	cout << "Your string is " << s << endl;
	cout << "New string is ";
	for (int i = s.length() - 1; i >= 0; --i)
		cout.put(s[i]);
	cout << endl;

	cin.get();
	cin.get();
	return 0;
}