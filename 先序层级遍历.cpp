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
	   printf("(%d,%c)",i,root->data);
	xianxu(root->Lchild,i); 
	xianxu(root->Rchild,i);
}

int main(void)
{
    BiTree root=NULL;
	CreateBiTree(&root);
	int i=0; 
	xianxu(root,i);
}
