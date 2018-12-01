/*
 功能描述：二分查找算法
 时间复杂度：O(lgn)
*/
#include <iostream>
using namespace::std;
const int length = 10;
/*
 功能描述：在区间A[p, r]内查找是否存在v；
 参数：A[]代查找的区间，p区间左端点，r区间右端点，v待查找的值
 返回值：存在，则返回v值；否则，返回
*/
int BinSearch(int A[], int p, int r, int v){
    if(p>r)
        return -1;                  //不存在v值
    else{
        int q=(p+r)/2;
        if(A[q]==v){                //中位数等于v
            return A[q];
        }else if(A[q]<v){
            return BinSearch(A, q+1, r, v);//查找左半区间
        }else{
            return BinSearch(A, p, q, v);  //查找右半区间
        }
    }
}

int main(){
    int A[length+1]={0};
    // initial A[]
    for(int i=1;i<=length;i++)
        A[i]=i;
    int val;
    int startP,endP;
    cout << "please input the start positation and end positation and val that your findtion is val equals -1 then end progarming" << endl;
    while(cin >> startP >> endP >> val&&val!=-1){
        int key=-1;
        if((key=BinSearch(A, startP, endP, val))==-1){
            cout << "nonentity" << endl;
        }else{
            cout << key << endl;
        }
    }
    return 0;
}
/*
 bug1:如果val是负值，则报Segmentation fault异常
    解决：未解决
*/