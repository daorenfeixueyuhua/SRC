// assign.cpp -- type change on initialization

#include <iostream>

using namespace std;

int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;
    int guess(3.14159);
    // int debt = 7.2E12;
    cout << "tree = " << tree << endl;
    cout << "guss = " << guess << endl;
    // cout << "debt = " << debt << endl;
    return 0;
}