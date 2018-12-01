#include<stdio.h>
 #include<stdlib.h> 
 typedef struct BiTNode 
 { 
 	int data; 
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree; 

void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL) return ; 
	printf("%d ",T->data); 
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild); 
 } 
  
  
void CreateBiTree(BiTree *T) 
{ 
  int ch; 
  scanf("%d",&ch); 
  if(ch==0) *T=NULL; 
  else { 
  		*T=(BiTree )malloc(sizeof(BiTNode)); 
	  if(!*T) exit(-1);
		   (*T)->data=ch;
		   CreateBiTree(&(*T)->lchild);
			CreateBiTree(&(*T)->rchild); 
		 } 
} 
	 
int main() 
{ 
		BiTree T; CreateBiTree(&T); 
		 PreOrderTraverse (T); 
		 return 0; 
}

