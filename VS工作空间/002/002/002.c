#include<stdio.h>
#include "002.h"

void main() {
	int i=0, e;
	//sqlist l;
	l=InitList(l);
	printf("��������Ҫ���������Ա��ȣ�\n");
	scanf_s("%d", &i);
	l=CreatList(l, i);
	PrintList(l);
	printf("�����ǣ�%d\n", Length(l));
	printf("��������Ҫ��ѯ��ֵ��\n");
	scanf_s("%d", &e);
	if (LocateElem(l,e))
	{
		printf("���ڴ�Ԫ�أ����ҳɹ���\n");
	}
	else
	{
		printf("�����ڴ�Ԫ�أ�����ʧ�ܣ�\n");
	}
	printf("��������Ҫɾ����ֵλ�ã�\n");
	scanf_s("%d", &i);
	l= ListDelete(l, i);

	printf("���ڳ����ǣ�%d\n", Length(l));
	system("pause");
}