// typecase.cpp -- forcing type change

#include <iostream>

using namespace std;

int main(){
    int auks, bats, coots;
    auks = 11.99 + 19.99;

    bats = (int)11.99 + (int)19.99;     // old c syntax
    coots = int(11.99) + int(19.99);    // new c++ syntax

    cout << "auks = " << auks << endl;
    cout << "bats = " << bats << endl;
    cout << "coots = " << coots << endl;

    char ch = 'Z';
    cout << "the character " << ch << " is equal to " << int(ch) << endl;

    cout << static_cast<int>(ch) << endl;   // using static_cast
    
    return 0;
}