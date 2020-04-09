#include <iostream>
#include <memory>
using namespace std;

/* define output operator for auto_ptr
 * - print object value or NULL
 */
template <class T>
ostream &operator<<(ostream &strm, const auto_ptr<T> &p)
{
    // does p own an object ?
    if (p.get() == NULL)
    {
        strm << "NULL"; // NO: print NULL
    }
    else
    {
        strm << *p; // YES: print the object
    }
    return strm;
}

int main()
{
    const auto_ptr<int> p(new int(42));
    const auto_ptr<int> q(new int(0));
    const auto_ptr<int> r;

    cout << "after initialization:" << endl;
    cout << " p: " << p << endl;
    cout << " q: " << q << endl;
    cout << " r: " << r << endl;

    *q = *p;
    //  *r = *p;    // ERROR: undefined behavior
    *p = -77;
    cout << "after assigning values:" << endl;
    cout << " p: " << p << endl;
    cout << " q: " << q << endl;
    cout << " r: " << r << endl;

    //  q = p;      // ERROR at compile time
    //  r = p;      // ERROR at compile time
}