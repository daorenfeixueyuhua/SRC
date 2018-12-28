#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace::std;
int main(){
    int n;
    cin >> n;
    vector<int> A(n, 0);
    for(int i=0;i<n;++i)
        cin >> A[i];
    sort(A.begin(), A.end());
    cout << A[A.size()/2] << endl;
    return 0;
}