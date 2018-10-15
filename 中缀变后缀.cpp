#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 50
int ji(char x)
{
	switch(x)
	{
		case '+':
		case '-':return 1;break;
		case '*':
		case '/':return 2;break;
		case '(':return 0;break;
		case '#':return -1; 
	}
}
int main()
{
	char Stack[N];
	int top=0;
	Stack[top]='#';
	char a[100];
	gets(a);
	int n;
	n=strlen(a);
	int i=0;
	while(n)
	{
		if(a[i]<='z'&&a[i]>='a')
		printf("%c",a[i]);
		else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
		{
		while(ji(a[i])<=ji(Stack[top]))
		{
		printf("%c",Stack[top]);
		top--;
	    }
	    top++;
	    Stack[top]=a[i];
	}
	    else if(a[i]=='(')
	    {
	    	top++;
	        Stack[top]=a[i];
	}
	    else if(a[i]==')')
	    	{
			while(Stack[top]!='(')
			{
	    	printf("%c",Stack[top]);
	    	top--;
			}
			top--;
		}
		n--;
		i++;
	}
	while(top!=0)
		{
		printf("%c",Stack[top]);
		top--;
	}
	
}

