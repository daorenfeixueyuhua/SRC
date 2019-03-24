#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

const int MAX = 100000;

// 将hex转十进制，再转八进制
// decimalist 十进制
// hexadecimal 十六进制
// octonary 八进制

// failure

vector<int> stringtovector(string s)
{
    vector<int> A(MAX, 0);
    int length = s.length();
    for (int i = length-1; i >= 0; i++)
    {
        A[MAX - i];
    }
}

int getValue(const char c)
{
    if ('0' <= c && c <= '9')
    {
        return c - '0';
    }
    else if ('A' <= c && c <= 'Z')
    {
        return c - 'A' + 10;
    }
}

int hex_to_dec(string s)
{
    int result = 0;
    for (int i = s.length() - 1; i >= 0; --i)
    {
        result += getValue(s[i]) * int(pow(16, s.length() - 1 - i));
    }
    return result;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string hexS;
        cin >> hexS;

        int decV = hex_to_dec(hexS);
        cout << oct << decV << endl;
    }
    return 0;
}