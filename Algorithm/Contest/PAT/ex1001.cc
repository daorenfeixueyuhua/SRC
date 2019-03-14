#include <iostream>

using namespace std;

// 比较A+B 和C 的大小
// 无法直接相加 应为-2147483648-2147483648 = -4294967296 计算机中表示为0
// 使用double保存数据，A+B>C---->A/2+B/2>C/2

int main(){
    int T;
    cin >> T;
    int cnt = 1;
    double A, B, C;
    while(T--){
        cin >> A >> B >> C;
        double K = (A/2) + (B/2);
        if(K>(C/2)){
            cout << "Case #"<<cnt<<": true" << endl;
        }else{
            cout << "Case #"<<cnt<<": false" << endl;
        }
        // cout << "A + B = " << K << endl;
        ++cnt;
    }
    return 0;
}