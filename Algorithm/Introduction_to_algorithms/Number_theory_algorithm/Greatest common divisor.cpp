// 最大公因数算法
#include <bits/stdc++.h>
using namespace::std;
/**
 * GCD递归定理：对任意非负整数a和任意正整数b，
 *              gcd(a, b)=gcd(b, a%b)
 * 
 * d=gcd(a, b)=ax+by 
 **/
// 欧几里得算法
int euclid(int a, int b){
    if(b==0)
        return a;
    else return euclid(b, a%b);
}

// // 返回三元组(d, x, y)满足：d=gcd(a, b)=ax+by
// void extended_euclid(int a, int b, int *d, int *x, int *y){
//     if(b==0){
//         *d=a; *x=1;*y=0;
//     }else{
//         extended_euclid(b, a%b, d, x, y);
        
//         myclass.setMyclass(myclass.d, myclass.y, myclass.x-a/b*myclass.y);
//     }
// }

// n个整数得最小公倍数
int lcm(int A[], int n){
    int x=A[0], g=A[0];
    for(int i=1;i<n;++i){
        x=x*A[i];
        g=euclid(g, A[i]);
    }
    return x/g;
}
int main(){
    // lcm算法测试
    int n;
    while(cin >> n && n>1){
        int A[n];
        for(int i=0;i<n;++i)
            cin >> A[i];
        int result = lcm(A, n);
        cout << result << endl;
    }
    // int a, b;
    // while(cin>>a>>b&&(a||b)){
    //     cout << euclid(a, b) << endl;        
    // }
    return 0;
}