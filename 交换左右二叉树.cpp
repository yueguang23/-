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
//交换
void jiaohuan(BiTree root)
{
	if(root==NULL)
	return ;
	BiTree t;
	t=root->Lchild;
	root->Lchild=root->Rchild;
	root->Rchild=t;
	jiaohuan(root->Lchild);
	jiaohuan(root->Rchild);
} 


//先序遍历 
void xianxu(BiTree root) 
{
	if(root==NULL)
	return;
	printf("%c",root->data);
	xianxu(root->Lchild);
	xianxu(root->Rchild);
}
//中序 
void zhongxu(BiTree root)
{
	if(root==NULL)
	return;
	zhongxu(root->Lchild);
	printf("%c",root->data);
	zhongxu(root->Rchild);
}

//后序
void houxu(BiTree root)
{
	if(root==NULL)
	return;
	houxu(root->Lchild);
	houxu(root->Rchild);
	printf("%c",root->data);
} 

int main(void)
{
	
	BiTree root=NULL;
	CreateBiTree(&root);
	jiaohuan(root);
	xianxu(root);
	printf("\n");
	zhongxu(root);
	printf("\n");
	houxu(root);
}
