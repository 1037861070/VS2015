#include<stdio.h>
#include"head .h"

stack InitStack(stack s)//初始化栈
{
	s.top = -1;
	return s;
}
int StackEmpty(stack s)//判断栈是否为空
{
	if (s.top==-1)
	{
		return 1;//栈为空
	}
	else
	{
		return 0;
	}
}
int Push(stack *s, int e)//进栈
{
	if ((*s).top==maxsize-1)
	{
		printf("栈满了!/n");
		return 0;
	}
	else
	{
		(*s).data[++(*s).top] = e;
		return 1;
	}
}
int Pop(stack *s, int *e)//出栈，返回e
{
	if ((*s).top==-1)
	{
		printf("栈为空！\n");
		return 0;
	}
	else
	{
		(*e) = (*s).data[(*s).top--];
		return 1;
	}
}
int GetTop(stack s, int *e)//  得到栈顶元素，并用e来返回
{
	if (s.top==-1)
	{
		printf("栈为空！\n");
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
		printf("栈为空！\n");
	}
	else
	{
		printf("栈中元素依次为：\n");
		while (k!=-1)
		{
			printf("%d  ", s.data[k--]);
		}
	}
}