#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n;++i)
        cin >> A[i];
    sort(A.begin(), A.end());
    cout << A[0];
    for (int i = 1; i < n; ++i)
        cout << " " << A[i];
    return 0;
}