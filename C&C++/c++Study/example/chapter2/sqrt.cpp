// sqrt.cpp -- using the sqrt() function

#include <iostream>
#include <cmath>

int main(){
	using namespace std;
	
	double area;
	cout << "Enter the floor area, ina square, of your home: ";
	cin >> area;
	double side;
	side = sqrt(area);
	cout << "That's the equivalent of a square " << side << " feet to the side." << endl;
	cout << "How fascinationg!" << endl;
	return 0;
}