/**
 * 输入一年内的天数，请计算一个屋子里最少要有多少个人才能是两个人生日相同的概念为1/2
 * */

#include <iostream>
using namespace::std;
int main(){
    int n;
    while(cin>>n&&n){
        float p = 1.0, t = 0;
        int cnt = 0;
        while(t<0.5){
            cnt++;
            p *= (n - cnt) * 1.0 / n;
            t = 1 - p;
        }
        cout << cnt << endl;
    }
    return 0;
}