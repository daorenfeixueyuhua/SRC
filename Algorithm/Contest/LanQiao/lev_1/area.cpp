#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323;

int main()
{
    // c++控制精度
    int r;
    cout.setf(ios_base::fixed);
    cout.precision(7);
    cin >> r;
    double area = r * r * PI;
    cout << area << endl;
    return 0;
}