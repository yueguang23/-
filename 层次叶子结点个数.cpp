#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
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

 void xianxu(BiTree root,int i) 
{
	if(root==NULL)
	return;
	i++;
	xianxu(root->Lchild,i); 
	xianxu(root->Rchild,i);
}


int leaf(BiTree root,int i,int k)
{
	int nl,nr;
	if(root==NULL)
	return 0;
	i++;
	if(i==k&&(root->Lchild==NULL)&&(root->Rchild==NULL))
	return 1;
	nl=leaf(root->Lchild,i,k);
	nr=leaf(root->Rchild,i,k);
	return nl+nr;
}
int main(void)
{
    BiTree root=NULL;
	CreateBiTree(&root);
	int i=0; 
	int k;
	scanf("%d",&k);
	printf("%d",leaf(root,i,k));
}
