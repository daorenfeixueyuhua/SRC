#include <bits/stdc++.h>
using namespace::std;
const string Ad = "advertise";
const string noAd = "do not advertise";
const string noMatter = "does not matter";
int main(){
    int n, r, e, c;
    cin >> n;
    while(n--){
        cin >> r >> e >> c;
        if(r + c < e){
            cout << Ad << endl;
        }else if(r + c == e){
            cout << noMatter << endl;
        }else{
            cout << noAd << endl;
        }
    }
    return 0;
}