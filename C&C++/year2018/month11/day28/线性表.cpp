#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
typedef struct Student ElemType;

struct Student{
	int id;//idΨһ 
	char name[20];
};
//����ͷ�ڱ� ���ڱ����ɼ��� 
struct Node{
	ElemType data;
	Node * next;
}; 
void create(Node * head){
	head=(Node*)malloc(sizeof(Node));
	head->next=NULL;
} 
//�涨��ֻ���ں�� 
Node* insert(Node * x,const ElemType e){
	Node * p=(Node*)malloc(sizeof(Node));
	p->next=x->next;
	p=x->next;
	return p;
}
int size(Node * head){
	int count=0;
	Node * p=head->next;
	while(p){
		count++;
		p=p->next;
	}
	return count;
}
int main(){
	Node* head,*p;
	ElemType e;
	create(head);
	p=head;
	for(int i=0;i<2;i++){// 1 pengda 2 dage
		scanf("%d %s",&e.id,&e.name);
		p=insert(p,e);
		printf("����%d\n",size(head));
	}
	return 0;
}
