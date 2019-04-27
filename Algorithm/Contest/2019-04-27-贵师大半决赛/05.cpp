#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    getline(cin, s);
    int length = s.length();
    for (int i = 0; i < length; ++i)
    {
        if (isspace(s[i - 1]) || i - 1 == -1)
        {
            s[i] = toupper(s[i]);
        }
    }
    cout << s << endl;
    return 0;
}