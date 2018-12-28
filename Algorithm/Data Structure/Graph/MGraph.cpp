#define MAX 100
#define INF 65535
typedef int Vertex;
typedef int Weight;
typedef char Data;
typedef struct GNode *PtrToGNode;
struct GNode{
    int nv;
    int ve;
    Weight G[MAX][MAX];
    Data data[MAX];
};
typedef struct ENode *PtrToENode;

struct ENode{
    Vertex v1, v2;
    Weight weight;
};
typedef PtrToENode Edge;
