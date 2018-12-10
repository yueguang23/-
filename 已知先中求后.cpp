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


BiTree BinaryFromOrderings(char * in,char * pre,int len)
{
	if(len==0)
	{
		return NULL;
	}
	BiTree root;
	root=(BiTree)malloc(sizeof(BiTNode));
    root->data=*pre;
    int index=0;
    for(;index<len;index++)
    {
    	if(in[index]==*pre) 
		break;
    }
    root->Lchild=BinaryFromOrderings(in,pre+1,index);
    root->Rchild=BinaryFromOrderings(in+index+1,pre+index+1,len-(index+1));
    return root;
} 

//ÅÐ¿Õ
int iskong(int top)
{
	if(top==-1)
	return 1;
	else 
	return 0;
} 

//ºóÐò 
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

int main()
{
	char in[N];
	char pre[N];
	int n;
	gets(pre);
	fflush(stdin);
	gets(in);
	BiTree root;
	n=strlen(in);
	root=BinaryFromOrderings(in,pre,strlen(in));
	houxu(root);
}
