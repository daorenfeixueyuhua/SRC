#include <fstream>
#include <string>
#include <iostream>

using namespace std;
int main()
{
    string str;
    getline(cin, str);
    // cout << str << endl;
    unsigned int npos = str.find("a", 1, 7);
    if (string::npos == npos)
        cout << "not find!" << endl;
    else
        cout << npos << endl;

    cin.get();
    cin.get();
    return 0;
}