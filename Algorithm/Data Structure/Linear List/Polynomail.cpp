#define TRUE                1
#define FALSE               0
#define OK                  1
#define ERROR               0
#define INFEASIBLE          -1
#define OVERFLOW            -2

#include "LinkList.h"

typedef int Status;
//typedef int ElemType;

typedef struct {
	float coef;			// 系数
	int expn;			// 指数
}term,ElemType;

typedef LinkList polynomial;

/*=======================基本操作的函数原型=====================*/
void CreatePoly(polynomial &P, int m);
	// 输入m项系数和指数，建立一个一元多项式的有序链表
void DetoryPoly(polynomial &P);
	// 销毁一元多项式
void PrintPoly(polynomial P);
	// 打印输出一元多项式P
void AddPoly(polynomial &Pa, polynomial &Pb);
	// 完成一元多项式的相加运算，即Pa=Pa+Pb，并销毁Pb
void SubstractPoly(polynomial &Pa, polynomial &Pb);
	// 完成一元多项式的相减运算，即Pa=Pa-Pb，并销毁Pb
void MultiplyPoly(polynomial &Pa, polynomial &Pb);
// 完成一元多项式的相乘运算，即Pa=Pa*Pb，并销毁Pb

/*=======================基本操作的算法描述部分=====================*/
int cmp(term a, term b);
	// 依a的指数<(或=)（或>）b的指数值，返回-1，0，1
