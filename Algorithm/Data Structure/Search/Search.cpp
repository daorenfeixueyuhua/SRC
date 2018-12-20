#include <bits/stdc++.h>
using namespace::std;
typedef int ElementType;
typedef int Position;
const int EORRO=-1;
const int length = 10;

/**
 * 再A[start, end)内查找是否存在value，存在，返回位置；否则，返回-1；
 * 时间复杂度：O(n)
 * 
 * */
Position sequentialSearch(const int A[], const int start, const int end, const int value){
    for(int i=start;i<end;++i)
        if(A[i]==value)
            return i;
    return -1;
}

/**
 * 二分查找算法
 * 在A[strat, end)内查询value的位置,存在返回位置，否则，返回-1；
 * 前提：A[]为有序序列
 * 原理：通过中位值，将A[]划分为A[start, center)和A[center+1, end)，通过比较A[center]与value
 * 等于：返回center，即value在A[start, end]的的位置
 * 小于：递归调用 binarySearch(A, start, center, value)
 * 大于：递归调用 binarySearch(A, center+1, end, value)
 * 
 * */
Position binarySearch(const int A[], const int start, const int end, const int value){
    int center=(start+end)/2;
    if(start<end){
        if(A[center]==value)
            return center;
        else if(A[center]<value)
            binarySearch(A, start, center, value);
        else
            binarySearch(A, center+1, end, value);
    }else
        return -1;
}

/**
 * 打印A[start, end)
 * */
void show(int A[], int start, int end){
    for(int i=start;i<end;i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(){
    int A[length];
    for(int i=0;i<length;++i)
        A[i]=length-i-1;
    int value = 8;
    Position position=-1;
    int start=0, end=10; // 查找范围 A[start, end)
    // 测试sequentialSearch success
    // position=sequentialSearch(A, start, end, value);

    // 测试binarySearch
    position=binarySearch(A, start, end, value);

    if(position==-1){
        printf("A[%d, %d) no exit %d!\n", start, end, value);
    }else if(A[position]==value){
        printf("search successful! the position is %d\n", position);
    }
    show(A, 0, length);
    return 0;
}