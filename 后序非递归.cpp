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

//½¨Á¢ ¶þ²æÊ÷
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
int iskong(int top)
{
	if(top==-1)
	return 1;
	else 
	return 0;
} 

void houxu(BiTree root)
{
	BiTree Stack[N];
	int top=-1;
	BiTree p,q;
	p=root;
	q=NULL;
	while(p!=NULL||!iskong(top))
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
			if(p->Rchild==NULL||p->Rchild==q)
			{
				top--;
				printf("%c",p->data);
				q=p;
				p=NULL;
			}
			else
			p=p->Rchild;
		}
	}
} 

int main(void)
{
	BiTree root=NULL;
	CreateBiTree(&root);
	houxu(root);
}
