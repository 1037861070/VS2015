#pragma once
//����Ĳ���
typedef struct node {
	struct node * next;
	int data;
}node,*linklist;
linklist l;
linklist CreatList(linklist l);//��������
linklist InitList(linklist l);//��ʼ������
void PrintfList(linklist l);//�������ֵ
int  DeleteLinklist(linklist l,int e);//ɾ������
int  InsertLinklist(linklist l, int e);//����ֵ
int  CheckLinklist(linklist l, int e);//����ֵ
int length(linklist l);//��������
int location(linklist l,int e);//��e���������λ��
void  PrintLinklist_back(linklist l);//������������е�ֵ
void  Sort_Linklist(linklist l);//����С�����������
int Delete_Inboundary(linklist l,int a,int b);//ɾ������a��b֮���ֵ��
int Find_max(linklist l);//�ҳ��������ֵ