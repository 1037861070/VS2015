#pragma once
   //���Ա�Ĳ���
#define maxsize 50
typedef struct list//�ṹ��
{
	int data[maxsize];//�����±��0��ʼ
	int length;
}sqlist;
sqlist l;
sqlist InitList(sqlist l);//��ʼ�����Ա�
sqlist CreatList(sqlist l,int length);//�������Ա�
int Length(sqlist l);//�����Ա���
int  LocateElem(sqlist l, int e);//�����Ա��в����Ƿ���eԪ��,�з���1���޷���0
int GetElem(sqlist l,int i);//�õ����Ա��е�i��Ԫ�ص�λ��
sqlist ListDelete(sqlist l,int i );//ɾ�����Ա��е�i��Ԫ�ص�λ�ã�������ɾ��Ԫ�ص�ֵ
void PrintList(sqlist l);//������Ա��е�����ֵ
int  Empty(sqlist l);//��Ԫ�ط���1���ձ���0




