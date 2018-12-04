#define TRUE                1
#define FALSE               0
#define OK                  1
#define ERROR               0
#define INFEASIBLE          -1
#define OVERFLOW            -2
#include <stdlib.h>

typedef int Status;
typedef int ElemType;

typedef struct DuLNode {
	ElemType data;
	struct DuLNode * prior;
	struct DuLNode * next;
}DuLNode, *DuLinkList;

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e) {
	// 再带头节点的双链循环链表L中的第i个位置之前插入元素e
	// i的合法值为1<=i<=表长+1
	DuLinkList p;
	if (!(p = GetElemP_DuL(L, i)))
		return ERROR;
	DuLinkList s;
	if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
		return ERROR;
	s->data = e;
	s->prior = p->prior;		// s的prior指向p的prior
	p->prior->next = s;			// 断开p的prior到p的指向
	s->next = p;				// 将s和p用s->next=p连接
	p->prior = s;				// 将s和p用p->prior=s连接
	return OK;
}
Status ListDelete_DuL(DuLinkList &L, int i, ElemType &e) {
	// 删除带头节点的双链循环线性表L的第i个元素，并用e返回，i的合法值为1<=i<=表长
	DuLinkList p;
	if (!(p = GetElemP_DuL(L, i)))
		return ERROR;
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}