#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <thread>
#include <algorithm>
using namespace std;
const int length = 1000;

/**
 * 使用g++编译，并将结果重定向至out文件
 * */
vector<int> trans(string s)
{
    vector<int> v(length + 1, 0);
    for (int i = s.size() - 1, j = length; i >= 0; i--, j--)
        v[j] = s[i] - '0';
    return v;
}
string trans1(vector<int> v)
{
    string s(length + 1, '0');
    for (int i = 0; i < s.size(); ++i)
        s[i] = v[i] + '0';
    int k = 0;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] != '0')
        {
            k = i;
            break;
        }
    s.erase(0, k);
    return s;
}
vector<int> add(vector<int> &v1, vector<int> v2)
{
    vector<int> v3(length + 1, 0);
    int carry = 0;
    for (int i = v1.size() - 1; i > 0; i--)
    {
        int temp = v1[i] + v2[i] + carry;
        v3[i] = temp % 10;
        carry = temp / 10;
    }
    return v3;
}

int main()
{
    int T, i = 0;
    cin >> T;
    while (T--)
    {
        i++;
        string s1, s2, s3;
        vector<int> v1, v2, v3;
        cin >> s1 >> s2;
        v1 = trans(s1);
        v2 = trans(s2);
        v3 = add(v1, v2);
        s3 = trans1(v3);
        cout << "Case " << i << ":" << endl;
        cout << s1 << " + " << s2 << " = " << s3 << endl;
        if (T != 0)
            cout << endl;
    }
    return 0;
}