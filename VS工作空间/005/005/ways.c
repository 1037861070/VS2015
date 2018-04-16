#include<stdio.h>
#include"head.h"
Bitree InitBitree(Bitree T)//初始化二叉树
{
	T = (Bitree)malloc(sizeof(Tree));
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}
Bitree CreateBitree(Bitree T)//先序创建一颗二叉树
{
	char  e;
	scanf_s("%c", &e);
	fflush(stdin);
	if (e != '#')
	{
		
		T = (Bitree)malloc(sizeof(Tree));		 //分配存贮空间
		T->data = e;
		T->lchild = NULL;
		T->rchild = NULL;
		T->lchild = CreateBitree(T->lchild);	//递归创建左孩子节点值
		T->rchild = CreateBitree(T->rchild);   //递归创建右孩子节点值
	}
	return T;
}
void PreOrder(Bitree T)//先序遍历二叉树
{
	if (T!=NULL)
	{
		printf("%c", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(Bitree T)//中序遍历二叉树
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		printf("%c", T->data);
		InOrder(T->rchild);
	}
}
void PostOrder(Bitree T)//后续遍历二叉树
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