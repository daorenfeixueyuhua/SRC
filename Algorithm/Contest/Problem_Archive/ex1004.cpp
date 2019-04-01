// Let the Balloon Rise
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace ::std;
typedef map<string, int> StringIntMap;
bool comp(const StringIntMap::iterator &it1, const StringIntMap::iterator &it2)
{
    return it1->second < it2->second ? 1 : 0;
}
int main()
{
    int n;
    while (cin >> n && n)
    {
        StringIntMap coll, max;
        StringIntMap::iterator pos, maxPos;
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            pos = coll.find(s);
            if (pos != coll.end())
                pos->second++;
            else
                coll[s] = 1;
        }
        maxPos = coll.begin();
        for (pos = coll.begin(); pos != coll.end(); ++pos)
        {
            if (maxPos->second < pos->second)
                maxPos = pos;
        }
        // 待更新comp函数
        // pos = max_element(coll.begin(), coll.end(), comp);
        cout << maxPos->first << endl;
    }
    return 0;
}