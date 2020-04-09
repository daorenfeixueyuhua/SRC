#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;
const int MAX = 1e6;
int main()
{
    //ios::sync_with_stdio(false);
    vector<int> V(MAX);
    int start = clock();
    for (int i = 0; i < MAX; i++)
        cin >> V[i];
    sort(V.begin(), V.end());
    for (int i = 0; i < MAX; i++)
        cout << V[i] << " ";
    printf("%.3lf\n", double(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}