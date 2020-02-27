#include <bits/stdc++.h>
using namespace std;
int binary_reach(int array[], int size, int x) {
    // 返回所在位置下标
    int l = 1, r = size;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (array[mid - 1] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}
int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "position is " << binary_reach(array, 10, 11) << endl;
    return 0;
}