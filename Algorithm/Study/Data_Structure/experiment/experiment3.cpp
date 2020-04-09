#include <stdio.h>
#include <malloc.h>
#define error NULL
typedef int elementType;
typedef struct node*ptr;
struct node
{
	elementType data;
	ptr next;
};
typedef ptr position;
typedef ptr List;
List head;
List creat()
{
	List L,H,p;
	int x;
	H=NULL;
	scanf("%d",&x);
	while(x!=0)
	{
		L=(List)malloc(sizeof(struct node));
		L->data=x;
		L->next=NULL;
		if(H==NULL)
		{
			H=L;
			p=L;
		}
		else
		{
			p->next=L;
			p=L;
		}
		scanf("%d",&x); 
	}
	return H;
}
void print(List L)
{
	List p;
	p=L;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int Length(List L)
{
    position p;
	int k=0;
	p=L;
	while(p)
	{
		p=p->next;
		k++;
	}
	return k;	
}
position find(List L,elementType x)
{
	int i=1; 
	position p=L;
	while(p&&p->data!=x)
	{
		p=p->next;
		i++;
	}
	if(p)
	{
		printf(" 查找的数所在位置为：%d",i); 
	}
	else
	{
		printf(" 没有找到查找的数所在位置");
	}
}
int main()
{
	List L=creat();
	printf("打印输入的数:"); 
	print(L);
	printf("打印列表的长度:"); 
	int length=Length(L);
	printf("%d",length);
	printf("\n");
	int x;
	printf("输入查找的数:"); 
	scanf("%d",&x);
	printf("查找结果:"); 
	find(L,x); 
}
