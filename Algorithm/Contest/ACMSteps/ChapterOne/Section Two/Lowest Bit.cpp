#include <bits/stdc++.h>
using namespace::std;
const int bits = 32;
int main(){
    int A;
    while(cin >> A && A){
        int i;
        for(i=1;i<bits;i++){
            if(A>>(i-1)&1){
                break;
            }

        }
        cout << pow(2, i-1) << endl;
    }
    return 0;
}
/*
去掉最后一位	101101->10110	x>>1
在最后加一个0	101101->1011010	x<<1
在最后加一个1	101101->1011011	(x<<1)+1
把最后一位变成1	101100->101101	x | 1
把最后一位变成0	101101->101100	(x |1) - 1
最后一位取反	101101->101100	x ^ 1
把右数第K位变成1	101001->101101,k=3	x  | (1<<(k-1))
把右数第K位变成0	101101->101101,k=3	x & ~(1<<(k-1))
右数第k位取反	101001->101101,k=3	x ^ (1<<(k-1))
取末三位	1101101->101	x &7
取末k位	1101101->1101,k=5	x & (1<<k-1)
取右数第k位	1101101->1,k=4	x >> (k-1)&1
把末k位变成1	101001->101111,k=4	x|(1<<k-1)
末k位取反	101001->100110,k=4	x^(1<<k-1)
把右边连续的1变成0	100101111->100100000	x&(x+1)
把右起第一个0变成1	100101111->100111111	x|(x+1)
把右边连续的0变成1	11011000->11011111	x|(x-1)
取右边连续的1	100101111->1111	(x^(x+1))>>1
去掉右起第一个1的左边	100101000->1000	x&(x^(x-1))
*/