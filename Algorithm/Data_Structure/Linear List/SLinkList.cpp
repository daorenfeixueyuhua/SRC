#define TRUE                1
#define FALSE               0
#define OK                  1
#define ERROR               0
#define INFEASIBLE          -1
#define OVERFLOW            -2

#include <cstdio>

typedef int Status;
typedef int ElemType;


// 线性表的静态链表存储结构

#define MAXSIZE 1000
typedef struct {
	ElemType data;
	int cur;
}component,SLinkList[MAXSIZE];

int LocateElem_SL(SLinkList S, ElemType e) {
	// 在静态单链线性表S中查找第1个值为e的元素
	// 若找到，则返回它的位序，否则返回0
	int i = S[0].cur;
	while (i&&S[i].data != e)
		i = S[i].cur;
	return i;
}

void InitSpace_SL(SLinkList &space) {
	// 将一位数组space中的各分量链成一个备用链表，space[0].cur为头指针
	// "0"表示空指针
	for (int i = 0; i < MAXSIZE - 1; ++i)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
}
int Malloc_SL(SLinkList &space) {
	// 若备用空间链表非空，则返回分配的节点下标，否则返回0
	int i = space[0].cur;
	if (space[0].cur)space[0].cur = space[i].cur;
	return i;
}
void Free_SL(SLinkList &space, int k) {
	// 将下标为k的节点回收到备用节点
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

void difference(SLinkList &space, int &S) {
	// 依次输入集合A和B的元素，在一维数组space中建立几个(A-B)U(B-A)
	// 的静态链表，S为其头指针，假设备用空间足够大，space[0].cur为其头节点
	InitSpace_SL(space);			// 初始化备用空间
	S = Malloc_SL(space);			//生成S的头节点
	int r = S;
	int n, m;
	scanf("%d %d", &n, &m);
	int i;
	for (int j = 1; j <= m; j++) {
		i = Malloc_SL(space);
		scanf("%d", &space[i].data);
		space[r].cur = i; r = i;
	}
	space[r].cur = 0;
	for (int j = 1; j <= n; ++j) {

	}
}
// 未完成，待续中...