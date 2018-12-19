#include <stdio.h>
#include <bits/stdc++.h>
using namespace::std;
const int length = 10;
typedef int ElementType;

/**
 * 功能：交换a，b
 * */
void swap(ElementType &a, ElementType &b){
    ElementType t = a;
    a=b;
    b=t;
}

/**
 * 简单选择排序
 * */
void simpleSelectionSort(ElementType A[], int n){
    int i, j, min;
    for(i=0;i<n-1;++i){ // 寻找最小元素
        min = i;
        for(j=i+1;j<n;++j){
            if(A[j]<A[min]){
                min = j;
                swap(A[i], A[min]);
            }
        }
    }
}

void perdown(ElementType A[], int p, int n){
    int parent, child;
    ElementType x;
    x=A[p];
    for(parent=p;(parent*2+1)<n;parent=child){
        child=parent*2+1;
        if(child!=n-1&&A[child]<A[child+1])
            ++child;
        if(x>=A[child]) break;
        else
            A[parent]=A[child];
    }
    A[parent]=x;
}

/**
 * 堆排序
 * 时间复杂度：O(N log N)
 * 空间复杂度：O(1)
 * */
void hearpSort(ElementType A[], int n){
    int i;
    for(i=n/2-1;i>=0;--i)    // 建立最大堆
        perdown(A, i, n);
    for(i=n-1;i>0;--i){
        // 删除最大堆
        swap(A[0], A[i]);
        perdown(A, 0, i);
    }
}

/**
 * 简单插入排序
 * 时间复杂度：O(n^2)
 * */
void insertionSort(ElementType A[], int n){
    int p, i;
    ElementType tmp;
    for(p=1;p<n;++p){
        tmp=A[p];   // 去除未排序序列中的第一个元素
        for(i=p;i>0&&A[i-1]>tmp;--i)
            A[i]=A[i-1];    // 依次与排序序列中元素进行比较并右移
        A[i]=tmp;
    }

}

/**
 * 希尔排序
 * 时间复杂度：O(n^(7/6))
 * */
void shellSort(ElementType A[], int n){
    int si, d, p, i;
    ElementType tmp;
    int sedewick[]={929, 505, 209, 109, 41, 19, 5, 1, 0};

    for(si=0;sedewick[si]>=n;++si);

    for(d=sedewick[si];d>0;d=sedewick[++si])
        for(p=d;p<n;++p){
            tmp=A[p];
            for(i=p;i>=d&&A[i-d]>tmp;i-=d)
                A[i]=A[i-d];
            A[i]=tmp;
        }

}

/**
 * 冒泡排序
 * 时间复杂度：O(n^2)
 * 
 * */
void bubbleSort(ElementType A[], int n){
    int p, i;
    bool flag;
    for(p=n-1;p>=0;--p){
        flag=false;
        for(i=0;i<p;++i){
            if(A[i]>A[i+1]){
                swap(A[i], A[i+1]);
                flag=true;
            }
        }
        if(flag==false) break;
    }

}


void show(int A[], int start, int end){
    printf("the array is :");
    for(int i=start;i<end;++i){
        printf("%3d",A[i]);
    }
    printf("\n");
}

int main(){
    ElementType A[length];
    for(int i=0;i<length;++i)
        A[i]=length-i-1;
    // 测试swap函数 success
    // swap(A[0], A[9]);

    // 测试simpleSelectionSort success
    // simpleSelectionSort(A,length);

    // 测试heapSort success
    // hearpSort(A, length);

    // 测试insertionSort success
    // insertionSort(A, length);

    // 测试shellSort success
    // shellSort(A, length);

    // 测试bubbleSort success
    bubbleSort(A, length);
    show(A, 0, length);
    return 0;
}