#define TRUE                1
#define FALSE               0
#define OK                  1
#define ERROR               0
#define INFEASIBLE          -1
#define OVERFLOW            -2
#include<cstdlib>
#include<cstdio>
typedef int Status;
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

Status GetElem_L(LinkList L, int i, ElemType &e) {
	// L为带头节点的单链表的头指针
	// 当第i个元素存在时，其值赋值给e并返回OK，否则返回ERROR
	LinkList p = L->next;
	int j = 1;
	while (p&&j < i) {
		p = p->next; j++;
	}
	// 第i个元素不存在
	if (!p || j >= i)return OVERFLOW;
	e = p->data;
	return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType e) {
	// 在带头节点的单线性表L中的第i个位置插入元素e
	LinkList p = L, int j = 0;
	while (p&&j < i - 1) {
		p = p->next; ++j;		//寻找第i-1个节点
	}
	if (!p || j > i - 1)return ERROR;	// i小于1或则大于表长+1
	LinkList s = (LinkList)malloc(sizeof(LNode));		// 生成新节点
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}


Status ListDelete_L(LinkList &L, int i, ElemType &e) {
	// 在带头节点的顺序线性表L中删除第i个节点元素，并将其值赋值给e
	LinkList p = L;
	int j = 1;
	while (p->next&&j < i - 1) {		//寻找第i个节点，并令p指向其前驱
		p = p->next; j++;
	}
	if (!(p->next) || j > i - 1)return ERROR;	//删除位置不合理
	LinkList q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
}

void CreateList_L(LinkList &L, int n) {
	// 逆位序输入n个元素的值，建立带头节点的单链线性表L
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = n; i > 0; --i) {
		LinkList p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;				// 插到表头
	}
}

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc) {
	// 已知单链线性表La和Lb的元素值非递减排列
	// 归并La和Lb到Lc中，Lc的元素值也非递减排列
	LinkList pa = La->next, pb = Lb->next;
	LinkList pc = Lc = pa;										//用la的头节点作为lc的头节点
	while (pa&&pb) {
		if (pa->data <= pb->data) {
			pc->next = pa; pc = pa; pa = pa->next;
		}
		else {
			pc->next = pb; pc = pb; pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;									// 插入剩余段
	free(Lb);
}