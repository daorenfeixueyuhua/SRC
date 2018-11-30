#include <iostream>
using namespace::std;
#define MAX_VERTEX 100   //最大定点数
#define INF 0          //无穷值
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct GNode {
	int num_vertex;         //定点数
	int num_edge;           //边数
	WeightType weight[MAX_VERTEX][MAX_VERTEX];    //权值
	DataType data[MAX_VERTEX];   //定点数据
}*MGraph;

typedef struct ENode {
	Vertex startVertex, endVertex;		//起始点，结束点
	WeightType weight;					//权值
}*Edge;
/*
 初始化一个有num_vertex定点没有边的图
*/
MGraph CreateGraph(int num_vertex) {
	MGraph graph = (MGraph)malloc(sizeof(struct GNode));
	for (int i = 1; i <= num_vertex; i++)
		for (int j = 1; j <= num_vertex; j++)
			graph->weight[i][j] = INF;
	graph->num_vertex = num_vertex;
	graph->num_edge = 0;
	return graph;
}

/*
 插入边<v1, v2>
*/
void InsertEdge(MGraph graph, Edge e) {
	graph->weight[e->startVertex][e->endVertex] = e->weight;
	/*
		若为有向图，则注释该语句
	*/
	graph->weight[e->endVertex][e->startVertex] = e->weight;
}

MGraph BuildGraph() {
	MGraph graph;
	int num_vertex;
	cout << "输入定点数" << endl;
	cin >> num_vertex;
	graph = CreateGraph(num_vertex);

	//插入边
	int num_edge;
	cout << "输入边个数" << endl;
	cin >> num_edge;
	cout << "输入边信息(格式：startVertex weigth endVertex 例如: 1 9 2)" << endl;
	for (int i = 0; i < num_edge; i++) {
		Edge e = (Edge)malloc(sizeof(struct ENode));
		cout << "第" << i << "条边信息:";
		cin >> e->startVertex >> e->weight >> e->endVertex;
		InsertEdge(graph, e);
	}

	//插入定点数据
	/*
	for (int i = 0; i < num_vertex; i++)
		cin >> graph->data[i];
	*/
	return graph;
}
/*
说明：以邻阶矩阵的形式删除图
参数：graph将要输出的图
返回值：无 
*/
void ShowGraph(MGraph graph) {
	//输出邻阶矩阵
	cout << "Adiacent order matrix:" << endl;
	for (int i = 1; i <= graph->num_vertex; i++) {
		for (int j = 1; j <= graph->num_vertex; j++)
			cout << graph->weight[i][j] << " ";
		cout << endl;
	}
	//输出定点数据
	/*
	for (int i = 0; i < graph->num_vertex; i++)
		cout << graph->data[i] << " ";
	cout << endl;
	*/
}

int main() {
	MGraph graph = BuildGraph();
	ShowGraph(graph);
	return 0;
}