//�㷨
//����һ���ַ�����������a�У����ַ�ȫ������ջ��
//�ٽ��ַ�pop����������һ������b�� 
//�Ƚ�a��b�������ȣ���Ϊ�����ַ� 
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define MAXSIZE 100
#define N 100 
typedef struct
{
	char data[MAXSIZE];
	int top;
}SeqStack;
SeqStack *Init_SeqStack(SeqStack *s)
{
	s->top=-1;
	return s;
}
int Empty_SeqStack(SeqStack *s)
{
	if(s->top==-1)
	return 1;
	else
	return 0;
}
int Push_SeqStack(SeqStack *s,char x)
{
	if(s->top==MAXSIZE-1)
	return 0;
	else
	{
		s->top++;
		s->data[s->top]=x;
		return 1;
	}
}
int Pop_SeqStack(SeqStack *s,char *x)
{
	if(Empty_SeqStack(s))
	   return 0;
	else{
		*x=s->data[s->top];
		s->top--;
		return 1;
	}
}
int main()
{
	char a[N];
	char b[N];
	char i;
	int n;
	int j=0;
	SeqStack *s;
	s=(SeqStack *)malloc(sizeof(SeqStack)); 
	Init_SeqStack(s);
	printf("�������ַ�\n");
	gets(a);
	n=strlen(a);
	for(j=0;j<n;j++)        //ʱ�临�Ӷ�o(n) 
	{
		Push_SeqStack(s,a[j]);
	}
	for(j=0;j<n;j++)       //ʱ�临�Ӷ�o(n) 
	{
		Pop_SeqStack(s,b+j);
	}
	for(j=0;j<n;j++)       //ʱ�临�Ӷ�o(n) 
	{
		if(b[j]!=a[j])
		break;
	}
	if(j<=n-1)
	printf("���ǻ�����\n");
	else
	printf("�ǻ�����\n");
}
