#include <iostream>
#include <string>

using namespace std;

int main()
{
    char fname[20];
    string lname;
    // cin >> fname;
    // cin >> lname;

    // cin.get(fname, 20);
    // cin.clear();
    getline(cin, lname);

    cout << "fname : " << fname << endl;
    cout << "lname : " << lname << endl;

    cin.get();
    cin.get();
    return 0;
}