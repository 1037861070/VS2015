#include<stdio.h>
#include"head.h"
Bitree InitBitree(Bitree T)//��ʼ��������
{
	T = (Bitree)malloc(sizeof(Tree));
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}
Bitree CreateBitree(Bitree T)//���򴴽�һ�Ŷ�����
{
	char  e;
	scanf_s("%c", &e);
	fflush(stdin);
	if (e != '#')
	{
		
		T = (Bitree)malloc(sizeof(Tree));		 //��������ռ�
		T->data = e;
		T->lchild = NULL;
		T->rchild = NULL;
		T->lchild = CreateBitree(T->lchild);	//�ݹ鴴�����ӽڵ�ֵ
		T->rchild = CreateBitree(T->rchild);   //�ݹ鴴���Һ��ӽڵ�ֵ
	}
	return T;
}
void PreOrder(Bitree T)//�������������
{
	if (T!=NULL)
	{
		printf("%c", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(Bitree T)//�������������
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		printf("%c", T->data);
		InOrder(T->rchild);
	}
}
void PostOrder(Bitree T)//��������������
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c", T->data);
	}
}
int HeightTree(Bitree T) {
	int left, right;
	if (T!=NULL)
	{
		left = HeightTree(T->lchild);
		right = HeightTree(T->rchild);
		return (left > right ? left : right) + 1;
	}
	else
	{
		return 0;
	}
}