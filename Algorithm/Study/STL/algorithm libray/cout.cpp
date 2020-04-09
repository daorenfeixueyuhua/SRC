#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A[10] = {1, 2, 3, 4, 4, 3, 7, 8, 9, 10};
    vector<int> v(&A[0], &A[9]);
    // 确定vector中有多少个整数匹配目标
    int target1 = 3;
    int target2 = 5;
    int num_items1 = count(v.begin(), v.end(), target1);
    int num_items2 = count(v.begin(), v.end(), target2);
    std::cout << "number: " << target1 << " count: " << num_items1 << '\n';
    std::cout << "number: " << target2 << " count: " << num_items2 << '\n';
    int num_items3 =
        count_if(v.begin(), v.end(), [](int i) { return i % 3 == 0; });
    cout << "number divisible by three: " << num_items3 << endl;
    return 0;
}