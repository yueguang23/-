#include<stdio.h>
#include<string.h>
//���������ַ�
void Swap(char *a ,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
//�ݹ�ȫ���У�start Ϊȫ���п�  ʼ���±꣬ length Ϊstr����ĳ���
void AllRange(char* str,int start,int length)
{
	int i;
	if(start == length-1)
	{
		printf("%s\n",str);
	}
	else
	{
		for(i=start;i<=length-1;i++)	
		{	//���±�Ϊstart������ʼ���ֱ�������������ֽ���
			Swap(&str[start],&str[i]); 
			AllRange(str,start+1,length);
			Swap(&str[start],&str[i]); 
		}
	}
}
void Permutation(char* str)
{
	if(str == NULL)
		return;
	AllRange(str,0,strlen(str));
}
void main()
{
	char str[] = "abcd";
	Permutation(str);
}

