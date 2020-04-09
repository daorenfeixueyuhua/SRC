#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

int main()
{
    int coll[] = {1, 2, 3, 4, 5, 6};
    transform(coll, coll + 6, coll, multiplies<int>());
    random_shuffle(coll, coll + 6);
    sort(coll, coll + 6);
    copy(coll, coll + 6, ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}