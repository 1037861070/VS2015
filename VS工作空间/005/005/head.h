#pragma once
 //�������Ĳ���
	typedef struct tree {
		struct tree   *lchild;	   //���ӽڵ�
		struct tree	*rchild;	   //�Һ��ӽڵ�
		char data;//������
	}Tree,*Bitree;

Bitree T;
Bitree InitBitree(Bitree T);//��ʼ��������
Bitree CreateBitree(Bitree T);//����һ�Ŷ�����
void PreOrder(Bitree T);//�������������
void InOrder(Bitree T);//�������������
void PostOrder(Bitree T);//��������������
int HeightTree(Bitree T);//��������߶�
