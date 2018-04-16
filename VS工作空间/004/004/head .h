#pragma once
#define maxsize 100
//顺序栈的操作
typedef struct node {		  //顺序存贮的栈
	int data[maxsize];
	int top;
 }stack;
stack s;
stack InitStack(stack s); //初始化栈
int StackEmpty(stack s);//判断栈是否为空
int Push(stack *s, int e);//进栈
int Pop(stack *s, int *e);//出栈，返回e
int GetTop(stack s, int *e);//  得到栈顶元素，并用e来返回
void PrintfStack(stack s);//打印栈中元素