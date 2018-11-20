#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Node Node;
typedef struct LStack LStack;
//Á´Ê½Õ»
struct Node{
	Node * pre;
	ElemType e;
	Node * next;
}; 
struct LStack{
	Node * bottom;//Õ»µ×Ö¸Õë 
	Node * top;//Õ»¶¥Ö¸Õë 
};
LStack create();
int size(LStack stack);
bool empty(LStack stack);
void push(LStack * stack,const ElemType e);
void pop(LStack * stack);
ElemType top(LStack * stack);
int main(){
	int e;
	LStack stack=create();
//	push(&stack,10);
//	printf("the stack size:%d\n",size(stack));
//	printf("ths stack is empty:%d\n",empty(stack));
	//push test
	for(int i=0;i<10;i++){//	1 2 3 4 5 6 7 8 9 0
		scanf("%d",&e);
		push(&stack,e);
		printf("size: %d \n",size(stack));
	}
	//top pop test
	while(!empty(stack)){
		e=top(&stack);
		pop(&stack);
		printf("the stack's elem is :%d\t",e);
		printf("the stack size:%d\n",size(stack));
	}

	return 0;
}
LStack create(){
	LStack stack;
	stack.bottom=(Node*)malloc(sizeof(Node));
	stack.bottom->next=NULL;
	stack.top=stack.bottom;
	return stack; 
}
int size(LStack stack){
	int count=0;
	Node *p=stack.bottom;
	while(p!=stack.top){
		count++;
		p=p->next;
	}
	return count;
}
bool empty(LStack stack){
	return stack.top==stack.bottom;
}
void push(LStack * stack,const ElemType e){
	Node * p=(Node*)malloc(sizeof(Node));
	p->e=e;
	p->next=NULL;
	stack->top->next=p;
	p->pre=stack->top;
	stack->top=stack->top->next;
}
void pop(LStack * stack){
	stack->top=stack->top->pre;
	free(stack->top->next);
}
ElemType top(LStack * stack){
	return stack->top->e;
}
