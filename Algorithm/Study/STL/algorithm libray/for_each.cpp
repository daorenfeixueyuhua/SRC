#include <bits/stdc++.h>
using namespace std;

int main() {
    int array[6] = {3, 4, 5, 8, 90, 321};
    vector<int> A(&array[0], &array[5]);
    // warning: lambda expressions only available with -std=c++11 or
    // -std=gnu++11 [enabled by default]
    for_each(A.begin(), A.end(), [](int &i) { cout << i << " "; });
    return 0;
}
