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

//构造空栈
Status init_stack(Stack & S); 
//销毁栈 
Status destory_stack(Stack & S);
//求栈的容量 
int size_stack(Stack S);
//元素入栈
Status push_stack(Stack & S,ElemType e); 
//元素出栈
Status pop_stack(Stack & S,ElemType & e); 
//判断栈是否为空 
bool empty_stack(Stack & S);
//打印栈元素
Status print_stack(Stack & S); 
//取栈顶元素
Status top_stack(Stack & S,ElemType & e); 
int main(){
	Stack S;
	init_stack(S);
	for(int i=0;i<10;i++)
		push_stack(S,i);
	print_stack(S);
	//取栈顶测试 
	ElemType top;
	top_stack(S,top);
	cout << "top: " << top << endl;
	//出栈测试 
	while(!empty_stack(S)){
		ElemType e;
		pop_stack(S,e);
		cout << e << " ";
	}cout << endl;
	
	destory_stack(S);
	return 0;
}

//构造空栈
Status init_stack(Stack & S){
	S.bottom=(ElemType*)malloc(MAX_SZIE_STACK*sizeof(ElemType));
	if(S.bottom==NULL)	return ERROR;
	S.top=S.bottom;
}
//销毁栈 
Status destory_stack(Stack & S){
	if(S.bottom==NULL)return OK;
	S.top=NULL;
	free(S.bottom);
	S.bottom=NULL;
	return OK;
}
//求栈的容量 
/*
	说明：空栈：返回0
			栈已销毁：返回-1
			其他：返回栈的容量 
*/
int size_stack(Stack S){
	if(S.bottom==NULL)	return -1;
	return S.top-S.bottom; 
} 
//元素入栈
Status push_stack(Stack & S,ElemType e){
	*S.top=e;
	S.top++;
	return OK;
}
//元素出栈
Status pop_stack(Stack & S,ElemType & e){
	S.top--;
	e=*S.top;
	return OK;
}

//判断栈是否为空 
bool empty_stack(Stack & S){
	return (S.top==S.bottom)?true:false;
}
//打印栈元素
Status print_stack(Stack & S){
	cout << "Stack:[ ";
	for(ElemType * p=S.bottom;p<S.top;p++){
		cout << *p << " ";
	}
	cout << endl;
}
//取栈顶元素
Status top_stack(Stack & S,ElemType & e){
	e=*(S.top-1);
	return OK;
} 
