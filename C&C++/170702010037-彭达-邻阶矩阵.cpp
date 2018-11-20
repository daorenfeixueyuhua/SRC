#include <stdio.h>
#include <malloc.h>
#define MaxVertexNum 100 //最大定点数
#define INFINITY 65535   //
typedef int Vertex;      //定点
typedef int WeightType;  //权值
typedef char DataType;   //
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv; //定点数
    int Ne; //边数
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex v1, v2;     //有向边<v1,v2>
    WeightType weight; //权重
};
typedef PtrToENode Edge;
MGraph Creat(int vertexnum)
{
    Vertex v, w;
    MGraph Graph;
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = vertexnum;
    Graph->Ne = 0;
    for (v = 0; v < Graph->Nv; v++)
        for (w = 0; w < Graph->Nv; w++)
            Graph->G[v][w] = INFINITY;
    return Graph;
}
void inserEdge(MGraph Graph, Edge E)
{
    Graph->G[E->v1][E->v2] = E->weight;
    Graph->G[E->v2][E->v1] = E->weight;
}
MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex v;
    int Nv, i;
    printf("please input the numbers of the vertex: ");
    scanf("%d", &Nv);
    Graph = Creat(Nv);
    printf("please input the numbers of the edge: ");
    scanf("%d", &(Graph->Ne));
    if (Graph->Ne != 0)
    {
        E = (Edge)malloc(sizeof(struct ENode));
        for (i = 0; i < Graph->Ne; i++)
        {
            printf("please input the index and weight of the edge %d: ", i);
            scanf("%d %d %d", &E->v1, &E->v2, &E->weight);
            inserEdge(Graph, E);
        }
    }

    for (v = 0; v < Graph->Nv; v++)
    {
        printf("please input the data of the vertex %d: ", v);
        getchar(); //用于吸收'\n'字符
        scanf("%c", &(Graph->Data[v]));
    }
    return Graph;
}
void showGraph(MGraph graph)
{
    printf("the edge:\n");
    for (int i = 0; i < graph->Nv; i++)
    {
        for (int j = 0; j < graph->Nv; j++)
        {
            printf("%6d", graph->G[i][j]);
        }
        printf("\n");
    }
    printf("the vertex:\n");
    for (int i = 0; i < graph->Nv; i++)
    {
        printf("%c ", graph->Data[i]);
    }
}
int main()
{
    MGraph graph = BuildGraph();
    showGraph(graph);
    return 0;
}
