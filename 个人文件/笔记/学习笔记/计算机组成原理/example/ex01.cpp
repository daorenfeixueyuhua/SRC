#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

const int MAX = 16;

void show(vector<int>& v){
    for(int i = v.size()-1; i >= 0; --i)
        cout << v.at(i);
    cout << endl;
}

void showN(float n){
    bitset<16> N(n);
    cout << N.to_string() << endl;
}

vector<int> getN(int n){
    vector<int> N(MAX, 0);
    int flag = n > 0 ? 0 : 1;
    n = abs(n);
    for(int i = 0; i < MAX; ++i)
        N[i] = (n >> i) & 1;        // bit operate, get per bit value
    
    N[MAX-1] = flag;
    return N;
}

void travse(vector<int>& v){
    for(int i = 0; i < v.size(); ++i)
        v[i] = !v[i];
}

int main(){

    int n;
    vector<int> N(MAX, 0);
    
    cout << "please input a number: ";
    cin >> n;

    // cout << "the binary number is: ";
    // showN(n);

    cout << n << endl;
    N = getN(n);
    show(N);
    travse(N);
    show(N);

    return 0;
}