#pragma once
 //二叉树的操作
	typedef struct tree {
		struct tree   *lchild;	   //左孩子节点
		struct tree	*rchild;	   //右孩子节点
		char data;//数据域
	}Tree,*Bitree;

Bitree T;
Bitree InitBitree(Bitree T);//初始化二叉树
Bitree CreateBitree(Bitree T);//创建一颗二叉树
void PreOrder(Bitree T);//先序遍历二叉树
void InOrder(Bitree T);//中序遍历二叉树
void PostOrder(Bitree T);//后续遍历二叉树
int HeightTree(Bitree T);//求二叉树高度
