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


BiTree zhihouxu(char * in,char * h,int len)
{
	if(len==0)
	{
		return NULL;
	}
	int index;
	BiTree root;
	root=(BiTree)malloc(sizeof(BiTNode));
    root->data=*(h+len-1);
    for(index=0;index<len;index++)
        if(in[index]==root->data)
		break;
    root->Lchild=zhihouxu(in,h,index);
    root->Rchild=zhihouxu(in+index+1,h+index,len-index-1);
    return root;
} 

//ÏÈÐò±éÀú 
void xianxu(BiTree root) 
{
	if(root==NULL)
	return;
	printf("%c",root->data);
	xianxu(root->Lchild);
	xianxu(root->Rchild);
}


int main()
{
	char in[N];
	char hou[N];
	gets(in);
	fflush(stdin);
	gets(hou);
	BiTree root;
	root=zhihouxu(in,hou,strlen(in));
	xianxu(root);
}
