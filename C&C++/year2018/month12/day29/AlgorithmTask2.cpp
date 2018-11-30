//输入顶点个数
#include <iostream>
using namespace::std;
#define OK 0
const int MAX_VERTEX = 20;
typedef int Status;

typedef char Vertex;
typedef struct ArcNode {
	int adjver;							//该弧所指向的顶点的位置
	struct ArcNode * nextarc;			//指向下一条弧的指针
}ArcNode;
typedef struct VNode {
	Vertex data;						//顶点信息
	ArcNode *firistarc;					//指向第一条依附该定点的弧的指针
}VNode,AdjList;
typedef struct {
	AdjList vertices[MAX_VERTEX];		
	int vernums, arcnums;				//图的当前顶点数弧数
}ALGraph;

bool visited[MAX_VERTEX];			//访问标志数组
Status(*VisitedFunc)(int v);			//函数变量

Status CreateGraph(ALGraph& graph) {
	cout << "输入顶点个数" << endl;
	cin >> graph.vernums;
	graph.arcnums=0;
	for (int i = 1; i <= graph.vernums; i++) {
		cout << "输入第"<<i<<"个定点信息" << endl;
		cin >> graph.vertices[i].data;
		graph.vertices[i].firistarc = NULL;
		int ver;
		ArcNode * head = (ArcNode*)malloc(sizeof(ArcNode));
		head->nextarc = NULL;
		ArcNode * p = head;
		cout << "输入弧信息:(-1 结束)(邻接点)" << endl;
		while (cin >> ver&&(0<=ver&&ver<=graph.vernums)) {//输入弧信息
			ArcNode * q = (ArcNode*)malloc(sizeof(ArcNode));
			q->adjver = ver;
			q->nextarc = NULL;
			p->nextarc = q;
			p = p->nextarc;

			graph.arcnums++;
		}
		graph.vertices[i].firistarc = head->nextarc;
	}
	return OK;
}

Status ShowGraph(ALGraph graph) {
	for (int i = 1; i <= graph.vernums; i++) {
		cout << graph.vertices[i].data;
		ArcNode * p = graph.vertices[i].firistarc;
		while (p) {
			cout << "->" << p->adjver;
			p = p->nextarc;
		}
		cout << endl;
	}
	return OK;
}
 
/*
 从第v个定点出发递归地深度优先遍历图
*/
void DFS(ALGraph graph, int v) {
	visited[v] = true;
	cout << graph.vertices[v].data << " ";
	ArcNode * p = graph.vertices[v].firistarc;
	while (p) {
		if (!visited[p->adjver]) {
			DFS(graph, p->adjver);
		}
		p = p->nextarc;
	}
	
}

/*
 深度优先遍历
*/
void DFSTreavese(ALGraph graph,int v) {
	for (int v = 1; v <= graph.vernums; v++)
		visited[v] = false;							//访问标志数组初始化
	for (int v = 1; v <= graph.vernums; v++)
		if (!visited[v])
			DFS(graph, v);
}

int main() {
	ALGraph graph;
	CreateGraph(graph);
	ShowGraph(graph);
	DFSTreavese(graph,1);
	return 0;
}                                                     a b d h e c f g 