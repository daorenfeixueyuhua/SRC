#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>
#include <iterator>

using namespace std;
const int MAX = 10;
int main()
{
    vector<int> v(MAX, 1);
    list<int> l(MAX, 1);
    // 以始于 value 并重复地求值 ++value 的顺序递增值填充范围 [first, last) 。
    iota(v.begin(), v.end(), 0);
    iota(l.begin(), l.end(), 99);
    // 输出容器内区间内的值
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
