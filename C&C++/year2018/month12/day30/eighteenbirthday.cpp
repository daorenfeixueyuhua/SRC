//18岁生日
#include <iostream>
#include <stdio.h>
using namespace::std;
int Y, M, D;
int days=0;

//是否时闰年
int isLeap(int y){
    return ((y%4==0&&y%100!=0)||(y%400==0))?1:0;
}

//返回一个月中的最大天数
int DayMax(){
    switch(M){
        case 1:return 31;
        case 2:
            if(isLeap(Y))
                return 29;
            else
                return 28;
        case 3:return 31;
        case 4:return 30;
        case 5:return 31;
        case 6:return 30;
        case 7:return 31;
        case 8:return 31;
        case 9:return 30;
        case 10:return 31;
        case 11:return 30;
        case 12:return 31;
    }
}
//加一天
void Dadd(){
    D++;
    days++;
}
//加1月
void Madd(){
    int max=DayMax();
    while(D<=max){
        Dadd();
    }
    M++;
    D=1;
}
//加1年
void Yadd(){
    while(M<=12){
        Madd();
    }
    Y++;
    M=1;
}

int main(){
    int T;
    
    cin >> T;
    while(T--){
        cin >> Y >> M >> D;
        //scanf("%d-%d-%d",&Y,&M,&D);
        //特殊情况
        if(isLeap(Y+18)!=1&&M==2&&D==29){
            cout << -1 << endl;
            break;
        }
        int maxY=Y+18;
        int maxM=M;
        int maxD=D;
        while(Y<maxY){
            Yadd();
        }
        while(M<maxM){
            Madd();
        }
        while(D<maxD){
            Dadd();
        }
        cout << days << endl;
    }
    return 0;
}