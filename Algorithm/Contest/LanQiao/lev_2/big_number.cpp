#include <iostream>
#include <vector>
#include <string>

const int length = 8 + 1;
const int bitValue = 10;

using namespace std;

vector<int> translate(string s)
{
    vector<int> v(length, 0);
    for (int i = s.length() - 1; i >= 0; --i)
        v[length - 1 - (s.length() - 1 - i)] = s[i] - '0';
    return v;
}

/**
 * 基本加法器：
 * A, B 代加值
 * C0 低位的进位
 * result 结果
 * C1 向高位的进位
 * */
void add(const int &A, const int &B, const int &C0, int &result, int &C1)
{
    result = (A + B + C0) % bitValue;
    C1 = (A + B + C0) / bitValue;
}
/**
 * 大数加法
 * */
vector<int> add(const vector<int> &v1, const vector<int> &v2)
{
    vector<int> v(length, 0);
    int carry = 0;
    for (int i = length - 1; i >= 1; --i)
    {
        add(v1[i], v2[i], carry, v[i], carry);
    }
    v[0] = carry;
    return v;
}

void show(const vector<int> &v)
{
    for (int i = 1; i < length; i++)
        cout << v[i];
    cout << endl;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    show(translate(s1));
    show(add(translate(s1), translate(s2)));
    return 0;
}