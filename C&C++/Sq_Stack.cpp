#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct Sq_Stack Sq_Stack;
const int maxStack=100;
struct Sq_Stack{
	ElemType * data;
	int _size;//ջ����ʶ 
};
//ջ�Ĵ�С 
int size(Sq_Stack stack);
//����ջ 
Sq_Stack create();
//�Ƿ�Ϊ�� 
bool empty(Sq_Stack stack);
//��ջ 
ElemType push(Sq_Stack * stck,const ElemType e);
//��ջ 
void pop(Sq_Stack * stack);
//ȡջ��
ElemType top(Sq_Stack * stack);

int main(){
	int e;
	Sq_Stack stack=create();
	for(int i=0;i<10;i++){
		scanf("%d",&e);
		push(&stack,e);
		printf("size: %d\n",size(stack));
	}
	//printf("%d",empty(stack));
	while(!empty(stack)){
		e=top(&stack);
		printf("top elem: %d ",e);
		pop(&stack);
		printf("size: %d\n",size(stack));
	}
	return 0;
}
/*
�������ݣ�
	push���ԣ�
		input:
			1 2 3 4 5 6 7 8 9 0
	top,pop���ԣ�
		output:
			 

*/
int size(Sq_Stack stack){
	return stack._size;
}
Sq_Stack create(){
	Sq_Stack stack;
	stack.data=(ElemType*)malloc(maxStack*sizeof(ElemType));
	stack._size=0;
	return stack;
}
bool empty(Sq_Stack stack){
	return !stack._size;
}
ElemType push(Sq_Stack * stack,const ElemType e){
	stack->data[stack->_size++]=e;
	return e;
}
ElemType top(Sq_Stack * stack){
	return stack->data[stack->_size-1]; 
}
void pop(Sq_Stack * stack){
	stack->_size--;
}

