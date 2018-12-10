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

//后序遍历统计叶子结点个数
int leaf(BiTree root)
{
	int nl,nr;
	if(root==NULL)
	return 0;
	if((root->Lchild==NULL)&&(root->Rchild==NULL))
	return 1;
	nl=leaf(root->Lchild);
	nr=leaf(root->Rchild);
	return nl+nr;
}
 
 //先序遍历求度为一的结点 
int du1(BiTree root)
{	
	if(root!=NULL)
	{
	if(((root->Lchild!=NULL)&&(root->Rchild==NULL))||((root->Lchild==NULL)&&(root->Rchild!=NULL)))
	return 1+du1(root->Lchild)+du1(root->Rchild);
	else
	return du1(root->Lchild)+du1(root->Rchild);
}
}

//先序求度为2的节点个数 
int du2(BiTree root)
{
	if(root!=NULL){
	if((root->Lchild!=NULL)&&(root->Rchild!=NULL))
	return 1+du2(root->Lchild)+du2(root->Rchild);
	else
	return du2(root->Lchild)+du2(root->Rchild);
}
}

//先序遍历输出叶子结点
void  printPre(BiTree root)
{
	if(root)
	{
		if(root->Lchild==NULL&&root->Rchild==NULL)
		printf("%c",root->data);
		printPre(root->Lchild);
		printPre(root->Rchild);
	}
}
int main(void)
{
	BiTree root=NULL;
	CreateBiTree(&root);
	printf("%d %d %d\n",leaf(root),du1(root),du2(root));
	printPre(root);
}
