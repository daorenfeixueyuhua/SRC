#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

string add(const string &s1, const string &s2)
{
    string s(max(s1.size(), s2.size()) + 1, '0');
    int carry = 0; //进位
    int i = s1.size() - 1, j = s2.size() - 1, k = s.size() - 1;
    while (i >= 0 && j >= 0)
    {
        s[k] = (s1[i] - '0' + s2[j] - '0' + carry) % 10 + '0';
        carry = (s1[i] - '0' + s2[j] - '0' + carry) / 10;
        i--;
        j--;
        k--;
    }
    while (i >= 0)
    {
        s[k] = (s1[i] - '0' + carry) % 10 + '0';
        carry = (s1[i] - '0' + carry) / 10;
        i--;
        k--;
    }
    while (j >= 0)
    {
        s[k] = (s2[j] - '0' + carry) % 10 + '0';
        carry = (s2[j] - '0' + carry) / 10;
        j--;
        k--;
    }
    s[k] = carry + '0';
    if (s[0] == '0')
        s.erase(s.begin());
    return s;
}

int cmp(const string &s1, const string &s2)
{
    if (s1.size() < s2.size())
        return 1;
    else if (s1.size() == s2.size())
    {
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] > s2[i])
                return 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

string minString(const vector<string> &vs)
{
    string s = vs[0];
    for (int i = 1; i < vs.size(); ++i)
    {
        if (cmp(s, vs[i]))
            ;
        else
            s = vs[i];
        // cout << s << endl;
    }
    return s;
}

int main()
{
    // 4690 1801
    // string s1, s2;
    // cin >> s1 >> s2;
    // cout << cmp(s1 , s2) << endl;
    int n, k;
    string s, s1, s2;
    cin >> n >> s;
    k = n / 2;
    string res, temp;
    int cnt = 0;
    int i = k, j = k;

    int k1 = i - 2 ? 0 : i - 2, k2 = i + 2 < n ? i + 2 : n;
    while (i > k1)
    {
        s1 = s.substr(0, i);
        s2 = s.substr(i);
        if (s2[0] == '0')
        {
            i--;
            continue;
        }
        temp = add(s1, s2);
        if (cnt == 0)
        {
            res = temp;
        }else{
            if (cmp(res, temp))
                ;
            else
                res = temp;
        }
        i--;
    }
    while (j < k2)
    {
        s1 = s.substr(0, j);
        s2 = s.substr(j);
        if (s2[0] == '0')
        {
            j++;
            continue;
        }
        temp = add(s1, s2);
        if (cnt == 0)
        {
            res = temp;
        }
        else
        {
            if (cmp(res, temp))
                ;
            else
                res = temp;
        }
        j++;
    }
    // cout << vs.size() << " ";
    // copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, " "));
    // cout << endl;
    cout << res << endl;
    return 0;
}