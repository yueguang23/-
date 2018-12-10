#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50 
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

//ÅÐ¿Õ
int isEmpty(int top)
{
	if(top==-1)
	return 1;
	else
	return 0;
} 

//²ã´Î±éÀú·ÇµÝ¹é 
void cengci(BiTree root)
{
	BiTree p;
	BiTree Queue[N];
	int in=-1;
	int out=-1;
	int size=0;
	in++;size++;
	Queue[in]=root;
	while(!isEmpty(in))
	{
		out++;
		if(out<=size-1)
		{
		p=Queue[out];
		printf("%c",p->data);
	    }   
	    else
	    break;
		if(p->Lchild!=NULL)
		{
			in++;size++;
			Queue[in]=p->Lchild;
		}
		if(p->Rchild!=NULL)
		{
			in++;size++;
			Queue[in]=p->Rchild;
		}
	}
}

int main(void)
{
	BiTree root=NULL;
	CreateBiTree(&root);
	cengci(root);
}
