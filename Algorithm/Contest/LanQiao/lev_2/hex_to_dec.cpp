#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int result = 0;
    int length = s.length();
    for (int i = length - 1; i >= 0; --i)
    {
        int tmp = 0;
        if (isdigit(s[i]))
        {
            tmp = s[i] - '0';
        }
        else
        {
            tmp = s[i] - 'A' + 10;
        }
        result += tmp * int(pow(16, length - 1 - i));
    }
    cout << result << endl;
    return 0;
}