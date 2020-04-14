#include <bits/stdc++.h>
using namespace std;

int cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if ((a.second - (a.second - a.first) / 2 - 1) !=
        (b.second - (b.second - b.first) / 2 - 1))
        return (a.second - (a.second - a.first) / 2 - 1) <
               (b.second - (b.second - b.first) / 2 - 1);
    else
        return a.first < b.first;
}

int run(vector<pair<int, int>> table) {
    int ans = 1;
    int start = table[0].first;
    for (int i = 0; i < table.size(); ++i) {
        int len =
            table[i].second - ((table[i].second - table[i].first) / 2 + 1);
        if (start > len) {
            ans = -1;
            break;
        }
        int end = start + (table[i].second - table[i].first) / 2 + 1;
        start = max(end, table[i + 1].first);
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> table;
    int start, end;
    for (int i = 0; i < n; ++i) {
        cin >> start >> end;
        table.push_back({start, end});
    }
    sort(table.begin(), table.end(), cmp);
    cout << run(table) << endl;

    return 0;
}