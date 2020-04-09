#include <iostream>
#include <cstdlib>
#include <Windows.h>
using namespace::std;

#define TRUE                1
#define FALSE               0
#define OK                  1
#define ERROR               0
#define INFEASIBLE          -1
#define OVERFLOW            -2

typedef int Status;
typedef int ElemType;
#define LIST_INIT_SIZE  100     
#define LISTINCREMENT   10

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;

Status InitList_Sq(SqList &L) {
	// 构造一个空的线性表L
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e) {
	// 在顺序线性表的第i个数据元插入新的数据元素e
	if (i<1 || i>L.length) return ERROR;
	if (L.length >= L.listsize) {
		// 扩容
		ElemType * newbase = (ElemType*)malloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	return OK;
}

Status ListDelete(SqList &L, int i, ElemType &e) {
	// 在顺序线性表中删除第i个数据元素，并用e返回其值
	// i的合法值为 1<<i<< ListLength_Sq(L)
	if (i < 1 || i >= L.length)exit(OVERFLOW);
	// p为删除元素的位置
	ElemType *p = &(L.elem[i - 1]);
	// 将要删除的值赋值为e
	e = *p;
	// 表尾位置
	ElemType *q = L.elem + L.length - 1;
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--L.length;
	return OK;
}

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
	// 在顺序线性表中查找第一个值与e满足compare()的元素位序
	// 若找到，则返回其在L中位序，否则返回0
	int i = 1;
	ElemType *p = L.elem;
	while (i <= L.length && !(*compare)(*p++, e))++i;
	if (i <= L.length)return i;
	else return 0;
}

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc) {
	// 已知顺序线性表La和Lb的元素非递减排列
	// 归并La和Lb得到新的顺序线性表Lc，Lc的元素也按照值非递减排列
	ElemType *pa = La.elem, *pb = Lb.elem;
	Lc.listsize = La.listsize + Lb.listsize;
	ElemType *pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem)exit(OVERFLOW);
	ElemType *pa_last = La.elem + La.length - 1;
	ElemType *pb_last = Lb.elem + Lb.length - 1;
	// 归并
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa < *pb)*pc++ = *pa;
		else *pc++ = *pb;
	}
	// 插入La剩余的元素
	while (pa <= pa_last)*pc++ = *pa;
	// 插入Lb剩余的元素
	while (pb <= pb_last)*pc++ = *pb;
}