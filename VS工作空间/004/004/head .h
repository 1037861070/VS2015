#pragma once
#define maxsize 100
//˳��ջ�Ĳ���
typedef struct node {		  //˳�������ջ
	int data[maxsize];
	int top;
 }stack;
stack s;
stack InitStack(stack s); //��ʼ��ջ
int StackEmpty(stack s);//�ж�ջ�Ƿ�Ϊ��
int Push(stack *s, int e);//��ջ
int Pop(stack *s, int *e);//��ջ������e
int GetTop(stack s, int *e);//  �õ�ջ��Ԫ�أ�����e������
void PrintfStack(stack s);//��ӡջ��Ԫ��