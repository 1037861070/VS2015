#ifndef HEAD

#define _CRT_SECURE_NO_WARNING
#define SIZE 50
//����ṹ��
typedef struct node{
int data;
struct node *next;
}node,*linklist;

//˳���ṹ��
typedef struct sqlist{
int data[SIZE];
int length;
}sqlist;

//��ʼ������
linklist initiallist();
//��������
linklist createlist(linklist l);
//�������
void outputlist(linklist l);
//����ֵ
int  check(linklist l,int x);
//ɾ��ֵΪx�Ľڵ�
linklist deletelist(linklist l,int x);

//linklist Getelem(linklist l,int i);
//����ֵΪx�Ľڵ㣬�ڱ�ͷ����
linklist insertlist(linklist l,int x);
#endif