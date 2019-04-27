#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;
typedef long long ll;

int main()
{
    char s[100];
    gets(s);
    // getline(cin, s);
    int length = strlen(s);
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