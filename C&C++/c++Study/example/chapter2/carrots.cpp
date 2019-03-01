// carrots.cpp -- food propcessing program
// uses and dispalys a variable

#include <iostream>

int main(){
	using namespace std;
	int carrots;
	
	carrots = 25;
	cout << "I have ";
	cout << carrots;
	cout << " carrots.";
	cout << endl;
	carrots = carrots - 1;
	cout << "Crunch. crunch. Now I hava " << carrots << " carrots." << endl;
	return 0;
}
