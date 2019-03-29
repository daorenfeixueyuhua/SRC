#include <iostream>
#include <string>

using namespace std;

int main()
{
    char str[25] = "I my name is pengda.";
    cout << "str : " << str << endl;
    string s1(str);
    cout << "s1 : " << s1 << endl;
    string s2(20, '#');
    cout << "s2 : " << s2 << endl;
    string s3(str, 10);
    cout << "s3 : " << s3 << endl;
    string s4(s1);
    cout << "s4 : " << s4 << endl;
    cin.get();
    cin.get();
    return 0;
}