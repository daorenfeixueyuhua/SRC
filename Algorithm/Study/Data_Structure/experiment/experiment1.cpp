#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace::std;

#define LIST_INIT_SIZE 100
#define LISTINCREAMENT 10
#define OK	1
#define ERROR -1
typedef int ElemType;
typedef int Status;
typedef int Position;

typedef struct SqList
{
	ElemType *elem;
	//ElemType * elem;
	int length;
	int listsize;
}SqList;

//建立空顺序表
SqList create();
//初始化顺序表
Status init(SqList & L);
//插入元素(前插）p为下标位置
Status insert(SqList & L, Position p, ElemType e);
//删除元素
Status del(SqList & L, Position p);
//查找p的元素
Status find(SqList L, Position p, ElemType &e);
//打印顺序表
void print(SqList L);

int main()
{
	int p;ElemType e;
	SqList L = create();
	init(L);
	print(L);
	
	printf("please input insert position and element:");
	scanf("%d %d",&p,&e);
	insert(L, p,e);
	print(L);
	
	printf("please input del position:");
	scanf("%d",&p);
	del(L, p);
	print(L);
	
	printf("please input find position:");
	scanf("%d",&p);
	find(L,p,e);
	printf("the element is: ");
	printf("%d\n",e);
	return 0;
}

SqList create()
{
	SqList p;
	p.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	p.length = 0;
	p.listsize = 100;
	return p;
}

Status init(SqList & L)
{
	cout << "please input the elem nums:" << endl;
	cin >> L.length;
	cout << "please input the SqList's elem:" << endl;
	for (int i = 0; i < L.length; ++i)
		cin >> L.elem[i];
	return OK;
}

Status insert(SqList& L, Position p, ElemType e)
{
	if (p < 0 || p > L.length)return ERROR;
	for (int i = L.length; i > p; --i)
		L.elem[i] = L.elem[i - 1];
	L.elem[p] = e;
	L.length++;
	return OK;
}

Status del(SqList& L, Position p)
{
	for (int i = p + 1; i < L.length; i++)
		L.elem[i - 1] = L.elem[i];
	L.length--;
	return OK;
}

Status find(SqList L, Position p, ElemType& e)
{
	e = L.elem[p];
	return OK;
}

void print(SqList L)
{
	cout << "all elems is: ";
	for (int i = 0; i < L.length; ++i)
		cout << L.elem[i] << " ";
	cout << endl;
}
