#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct Sq_Stack Sq_Stack;
const int maxStack = 100;
struct Sq_Stack {
	ElemType  *data;
	int _size;//栈顶标识 
};
//栈的大小 
int size(Sq_Stack stack);
//建空栈 
Sq_Stack create();
//是否为空 
bool empty(Sq_Stack stack);
//入栈 
ElemType push(Sq_Stack * stck, const ElemType e);
//出栈 
void pop(Sq_Stack * stack);
//取栈顶
ElemType top(Sq_Stack * stack);

int main() {
	int e;
	Sq_Stack stack = create();
	for (int i = 0; i < 10; i++) {
		scanf("%d", &e);
		push(&stack, e);
		printf("size: %d\n", size(stack));
	}
	//printf("%d",empty(stack));
	while (!empty(stack)) {
		e = top(&stack);
		printf("top elem: %d ", e);
		pop(&stack);
		printf("size: %d\n", size(stack));
	}
	return 0;
}
/*
测试数据：
	push测试：
		input:
			1 2 3 4 5 6 7 8 9 0
	top,pop测试：
		output:


*/
int size(Sq_Stack stack) {
	return stack._size;
}
Sq_Stack create() {
	Sq_Stack stack;
	stack.data = (ElemType*)malloc(maxStack * sizeof(ElemType));
	stack._size = 0;
	return stack;
}
bool empty(Sq_Stack stack) {
	return !stack._size;
}
ElemType push(Sq_Stack * stack, const ElemType e) {
	stack->data[stack->_size++] = e;
	return e;
}
ElemType top(Sq_Stack * stack) {
	return stack->data[stack->_size - 1];
}
void pop(Sq_Stack * stack) {
	stack->_size--;
}


/*
 * 学生信息队列保存
 */
#include <stdio.h>
#include <malloc.h>
#define OK 0
#define ERROR -1
typedef int Status;
typedef struct Student{
	char name[20];//名字
	int score;//成绩
}Student;
typedef Student ElemType;
typedef struct QNode{
	ElemType data;
	struct QNode * next;
}QNode;
typedef struct
{
	QNode * front;//对头指针
	QNode * rear;//队尾指针
}LinkQueue;
Status createStudent(Student * s);
	//创建一个学生
Status initQueue(LinkQueue * Q);
	//构造一个空对
Status EnQueue(LinkQueue * Q, const ElemType e);
	//插入元素e为Q的新队未元素
Status DeQueue(LinkQueue * Q, ElemType * e);
	//若队列非空，删除对头元素，e作为返回值，并返回OK
	//否则返回ERROR
/*
pengda 99
dage 79
dada 49
 */
int main()
{
	LinkQueue Q;
	Student s;
	initQueue(&Q);
	for(int i=0;i<3;i++)
	{
		createStudent(&s);
		EnQueue(&Q, s);
	}
	for(int i=0;i<3;i++)
	{
		DeQueue(&Q, &s);
		printf("%s %d\n", s.name, s.score);
	}
	return 0;
}

Status createStudent(Student * s)
{
	printf("please input name score:");
	scanf("%s %d", &s->name, &s->score);
	return OK;
}
Status initQueue(LinkQueue * Q)
{
	Q->front = Q->rear = (QNode*)malloc(sizeof(QNode));
	if (!Q->front)
		return ERROR;
	Q->front->next = NULL;
	return OK;
}
Status EnQueue(LinkQueue * Q, const ElemType e)
{
	QNode * p = (QNode*)malloc(sizeof(QNode));
	if (!p)return ERROR;
	p->data = e; p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}
Status DeQueue(LinkQueue * Q, ElemType * e)
{
	if (Q->front == Q->rear)return ERROR;
	QNode * p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)Q->rear = Q->front;
	free(p);
	return OK;
}

