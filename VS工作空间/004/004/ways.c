#include<stdio.h>
#include"head .h"

stack InitStack(stack s)//��ʼ��ջ
{
	s.top = -1;
	return s;
}
int StackEmpty(stack s)//�ж�ջ�Ƿ�Ϊ��
{
	if (s.top==-1)
	{
		return 1;//ջΪ��
	}
	else
	{
		return 0;
	}
}
int Push(stack *s, int e)//��ջ
{
	if ((*s).top==maxsize-1)
	{
		printf("ջ����!/n");
		return 0;
	}
	else
	{
		(*s).data[++(*s).top] = e;
		return 1;
	}
}
int Pop(stack *s, int *e)//��ջ������e
{
	if ((*s).top==-1)
	{
		printf("ջΪ�գ�\n");
		return 0;
	}
	else
	{
		(*e) = (*s).data[(*s).top--];
		return 1;
	}
}
int GetTop(stack s, int *e)//  �õ�ջ��Ԫ�أ�����e������
{
	if (s.top==-1)
	{
		printf("ջΪ�գ�\n");
		return 0;
	}
	else
	{
		*e = s.data[s.top];
		return 1;
	}
}
void PrintfStack(stack s) {
	int k = s.top;
	if (s.top==-1)
	{
		printf("ջΪ�գ�\n");
	}
	else
	{
		printf("ջ��Ԫ������Ϊ��\n");
		while (k!=-1)
		{
			printf("%d  ", s.data[k--]);
		}
	}
}