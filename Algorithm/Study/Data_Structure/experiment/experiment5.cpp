#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define OK 0
#define ERROR -1
typedef int Status;
typedef struct Student{
	char name[20];
	int age;
	int score;
}Student;
typedef Student ElemType;
typedef struct Node{
	ElemType  data;
	struct Node * next;
}Node;

Status create(Node* head);
	//创建一个链表，并初始化
Status trave(Node * head);
	//链表遍历
Status find(Node * head, char * name,ElemType * s);
	//查找name信息
int size(Node * head);
	//求表长
Status update(Node * head);
	//更新链表
int main()
{
/*
pengda 1 100
dada 2 34
dage 3 45
 */
	char name[20];
	Node head;
	Student s;
	create(&head);
	printf("size:%d\n", size(&head));
	printf("please input the find's name: ");
	scanf("%s", name);
	if (find(&head, name, &s) == -1)
		printf("not find!\n");
	else
		printf("student info:%s %d %d\n", s.name, s.age, s.score);
	printf("trave:\n");
	trave(&head);
	update(&head);
	trave(&head);
	return 0;
}
Status create(Node* head)
{
	//head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	Node * p = head,*q;
	Student s;
	int flag = 1;
	while(flag)
	{
		q = (Node*)malloc(sizeof(Node));
		scanf("%s %d %d", &q->data.name, &q->data.age, &q->data.score);
		q->next = NULL;
		p->next = q;
		p = q;
		printf("end:0\tcontinue:1\n");
		scanf("%d", &flag);
	}
	return OK;
}
Status trave(Node * head)
{
	Node * p = head->next;
	while(p)
	{
		printf("%s %d %d\t", p->data.name, p->data.age, p->data.score);
		p = p->next;
	}
	return OK;
}
Status find(Node * head, char * name, ElemType * s)
{
	Node * p = head->next;
	while(p)
	{
		if(p->data.name==name)
		{
			s = &p->data;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}
int size(Node * head)
{
	int c = 0;
	Node* p = head->next;
	while(p)
	{
		c++; p = p->next;
	}
	return c;
}
Status update(Node * head)
{
	int c = 0;
	Node * p = head->next;
	while(p)
	{
		if(p->data.score<60)
		{
			p->data.score = 60;
			c++;
		}
		p = p->next;
	}
	return c;
}
