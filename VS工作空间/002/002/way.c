#include<stdio.h>
#include "002.h"

sqlist InitList(sqlist l) {
	l.length = 0;
	return l;
}
//��ʼ�����Ա�
sqlist CreatList(sqlist l,int length) {
	
	printf("��������Ա��ֵ��");
	while (l.length<length)
	{
		scanf_s("%d", &l.data[l.length++]);
	}
	return l;
}//�������Ա�
int Length(sqlist l) {
	return l.length;
}
//�����Ա���
int  LocateElem(sqlist l, int e) {
	int i;
	for (i = 0; i < l.length; i++)
	{
		if (l.data[i] == e)
			return 1;
	}
	return 0;
}
//�����Ա��в����Ƿ���eԪ��,�з���1���޷���0
int GetElem(sqlist l, int i) {
	if (i > l.length || i < 0)
	{
		printf("����Խ��");
		return 0;
	}
	else
		return l.data[i - 1];
}
//�õ����Ա��е�i��Ԫ�ص�ֵ
sqlist ListDelete(sqlist  l, int i) {
	int j;
	if (i<0 || i>l.length)
	{
		printf("λ�ò��ԣ�");
		return  l;
	}
	for (j = i - 1; j < l.length - 1;j++) 
		{ 
		l.data[j] = l.data[j + 1];
		}
	l.length--;
	return l;
}
//ɾ�����Ա��е�i��Ԫ�ص�ֵ������e����ɾ��Ԫ�ص�ֵ
void PrintList(sqlist l) {
	int j = 0;
	while (j <l.length)
	{
		printf("%d  ",l.data[j]);
		j++;
	}
}
//������Ա��е�����ֵ
int  Empty(sqlist l) {
	if (l.length == 0)
		return 0;
	else
		return 1;
}
//��Ԫ�ط���1���ձ���0