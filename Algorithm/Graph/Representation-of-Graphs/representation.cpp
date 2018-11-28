#include <iostream>
using namespace::std;
#define MAX_VERTEXT     10
#define INFINITY        65535
typedef int Vertex;     //顶点
typedef int WeightType; //权值
typedef char DataType;  //

typedef struct GNode{
    int NV;             //定点数
    int NE;             //边数
    WeightType G[MAX_VERTEXT][MAX_VERTEXT];
    DataType Data[MAX_VERTEXT];
}*MGraph;

typedef struct ENode{
    Vertex V1, V2;      //有向边<V1, V2>
    WeightType weight;  //权重
}*Edge;

//邻阶矩阵表示
int G[MAX_VERTEXT][MAX_VERTEXT]={0};

//邻接表表示


int main(){

    return 0;
}