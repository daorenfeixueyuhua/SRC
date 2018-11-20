#include <iostream>
#include <cstdlib>

#define OK				1
#define ERROR			0
#define MAX_SZIE_STACK	100

using namespace::std;
typedef int Status;
typedef int ElemType;

typedef struct Stack{
	ElemType *bottom;
	ElemType *top;
}Stack;

//�����ջ
Status init_stack(Stack & S); 
//����ջ 
Status destory_stack(Stack & S);
//��ջ������ 
int size_stack(Stack S);
//Ԫ����ջ
Status push_stack(Stack & S,ElemType e); 
//Ԫ�س�ջ
Status pop_stack(Stack & S,ElemType & e); 
//�ж�ջ�Ƿ�Ϊ�� 
bool empty_stack(Stack & S);
//��ӡջԪ��
Status print_stack(Stack & S); 
//ȡջ��Ԫ��
Status top_stack(Stack & S,ElemType & e); 
int main(){
	Stack S;
	init_stack(S);
	for(int i=0;i<10;i++)
		push_stack(S,i);
	print_stack(S);
	//ȡջ������ 
	ElemType top;
	top_stack(S,top);
	cout << "top: " << top << endl;
	//��ջ���� 
	while(!empty_stack(S)){
		ElemType e;
		pop_stack(S,e);
		cout << e << " ";
	}cout << endl;
	
	destory_stack(S);
	return 0;
}

//�����ջ
Status init_stack(Stack & S){
	S.bottom=(ElemType*)malloc(MAX_SZIE_STACK*sizeof(ElemType));
	if(S.bottom==NULL)	return ERROR;
	S.top=S.bottom;
}
//����ջ 
Status destory_stack(Stack & S){
	if(S.bottom==NULL)return OK;
	S.top=NULL;
	free(S.bottom);
	S.bottom=NULL;
	return OK;
}
//��ջ������ 
/*
	˵������ջ������0
			ջ�����٣�����-1
			����������ջ������ 
*/
int size_stack(Stack S){
	if(S.bottom==NULL)	return -1;
	return S.top-S.bottom; 
} 
//Ԫ����ջ
Status push_stack(Stack & S,ElemType e){
	*S.top=e;
	S.top++;
	return OK;
}
//Ԫ�س�ջ
Status pop_stack(Stack & S,ElemType & e){
	S.top--;
	e=*S.top;
	return OK;
}

//�ж�ջ�Ƿ�Ϊ�� 
bool empty_stack(Stack & S){
	return (S.top==S.bottom)?true:false;
}
//��ӡջԪ��
Status print_stack(Stack & S){
	cout << "Stack:[ ";
	for(ElemType * p=S.bottom;p<S.top;p++){
		cout << *p << " ";
	}
	cout << endl;
}
//ȡջ��Ԫ��
Status top_stack(Stack & S,ElemType & e){
	e=*(S.top-1);
	return OK;
} 
