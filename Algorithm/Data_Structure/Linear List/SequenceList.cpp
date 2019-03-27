#include <stdio.h>
#include <malloc.h>
#include <bits/stdc++.h>
const int MAXSIZE = 100;
typedef int ElementType;
typedef struct LNOde * ptrToLNode;
typedef int Position;
struct LNOde{
    ElementType data[MAXSIZE];
    Position last;
};
typedef ptrToLNode List;
/**
 * 1.初始化
 * 顺序表的初始化即构造一个空表。首先动态分配表结构所需的存储空间，然后哦将表中last指针置为-1，表示表中没有数据。
 * 
 * */
List makeEmpty(){
    List L;
    L=(List)malloc(sizeof(struct LNOde));
    L.last=-1;
    return L;
}

/**
 * 2.查找
 * 顺序存储的线性表中，查找主要是指在线性表的查找与给定值x相等的数据元素。
 * 若存在，返回与x相等的元素的位置；
 * 否则，返回ERROR。
 * 时间复杂度：O(n)
 * */
#define ERROR -1

Position find(List L, ElementType x){
    Position i=0;
    while(i<L.last&&L->data[i]!=x)
        ++i;
    if(i>L->last)
        return ERROR;               /*不存在，返回ERROR*/
    else 
        return i;                   /*返回该元素的下标*/
}

/**
 * 3.插入
 * 在线性表的第i个位序前插入一个新的元素x；当i=1时，代表插入到序列最前端；当i=n+1时，代表插入到序列最后。
 * 具体步骤：
 * （1）将ai~an顺序向后移动（移动次序为从an到ai），为新元素让出位置
 * （2）将x置入空出的位置
 * （3）修改last指针，使之仍指向最后一个元素
 * 
 * */

bool insert(List L, ElementType x, int i){
    Position j;
    if(L->last>=MAXSIZE-1){
        printf("表已满\n");
        return false;
    }
    if(i<1||i>L->last+2){
        printf("位序不合法\n");
        return false;
    }
    for(j=L->last;j>=i-1;--j)
        L->data[j+1]=L->data[j];
    L->data[i]=x;
    L->last++;
    return true;
}

/**
 * 4.删除
 * 线性表的删除是指将表中位序为i（1<=i<=n）的元素从线性表中去掉。
 * 具体步骤：
 * （1）将ai+1~an顺序向前移动，ai被覆盖；
 * （2）修改last指针，是指仍指向最后一个元素。
 * 
 * */
bool delete(List L, int i){
    Position j;
    if(i<1||i>L->last+1){
        printf("位序%d不存在元素\n", i);
        return false;
    }
    for(j=i+1;j<L->last;++j)
        L->data[j-1]=L->data[j];
    L->last--;
    return true;
}