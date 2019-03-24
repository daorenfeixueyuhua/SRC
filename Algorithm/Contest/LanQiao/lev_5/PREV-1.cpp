#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b, a % b);
}

int lcm(vector<int> & v){
    int x = v[0], g = v[0];
    for (int i = 1; i < v.size();++i){
        x *= v[i];
        g = gcd(g, v[i]);
    }
    return x / g;
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int lcmV = (a * b) / gcd(a, b);
    lcmV = (lcmV * c) / gcd(lcmV, c);
    cout << lcmV << endl;
    return 0;
}