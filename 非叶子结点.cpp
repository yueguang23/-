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
//先序遍历求度为一的结点 
int du3(BiTree root)
{	
	if(root!=NULL)
	{
		if(!((root->Lchild==NULL)&&(root->Rchild==NULL)))
	return 1+du3(root->Lchild)+du3(root->Rchild);
	else
	return du3(root->Lchild)+du3(root->Rchild);
}
}
int main(void)
{
	BiTree root=NULL;
	CreateBiTree(&root);
	printf("%d %d %d\n",du1(root),du2(root),du3(root));
}
 
