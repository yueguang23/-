#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define MAXSIZE 100
#define N 100 
typedef struct Node
{
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
}*BiTree,BiTNode;
void CreateBiTree(BiTree * root)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
	*root=NULL;
	else
	{
		*root=(BiTree)malloc(sizeof(BiTNode));
	    (*root)->data=ch;
		CreateBiTree(&((*root)->Lchild));
		CreateBiTree(&((*root)->Rchild));
	}
} 

int pankong(int top)
{
	if(top==-1)
	return 1;
	else
	return 0;
}

void xianxu(BiTree root)
{
	BiTree Stack[N];
	int top=-1;
	BiTree p=root;
	while(p!=NULL||!pankong(top))
	{
	if(p!=NULL)
	{
		printf("%c",p->data);
		top++;
		Stack[top]=p;
		p=p->Lchild;
	}
	if(p==NULL)
	{
		p=Stack[top];
		top--;
		p=p->Rchild; 
	}
    }
}

void zhongxu(BiTree root)
{
	BiTree p=root;
	BiTree Stack[N];
	int top=-1;
	while(p||!pankong(top))
	{
		if(p!=NULL)
		{
			top++;
			Stack[top]=p;
			p=p->Lchild;
		}
		if(p==NULL)
		{
			p=Stack[top];
			top--;
			printf("%c",p->data);
			p=p->Rchild;
		}
	}
}

int main(void)
{
	BiTree root=NULL;
	CreateBiTree(&root);
	xianxu(root);
	printf("\n");
	zhongxu(root);
}
