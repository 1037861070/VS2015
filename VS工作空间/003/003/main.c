#include<stdio.h>
#include "head.h"
void main() {
	int k,e;
	int a, b;
	l = InitList(l);
	do
	{
		printf("\n*******************\n");
		printf("��ѡ����Ҫ���еĲ�����\n");
		printf("1.��������\n");
		printf("2.ɾ����㣺\n");
		printf("3.����һ����㣺\n");
		printf("4.���ҽ�����Ƿ���ڣ�\n");
		printf("5.�鿴�����ȣ�\n");
		printf("6.��˳���ӡ����ֵ��\n");
		printf("7.�͵���������\n");
		printf("8.������ֵ��С��������\n");
		printf("9.ɾ������������ֵ֮��Ľڵ㣺\n");
		printf("10.�������нڵ����ֵ������֮ɾ����ֵ��ͷ�ڵ�\n");
		printf("0.�˳���\n");
		printf("*******************\n");
		scanf_s("%d", &k);
		switch (k)
		{
		case 1:CreatList(l);
			break;
		case 2:printf("������Ҫɾ����ֵ��\n");
			scanf_s("%d", &e);
			DeleteLinklist(l, e);
			break;
		case 3:printf("������Ҫ��Ҫ�����ֵ��\n");
			scanf_s("%d", &e);
			InsertLinklist(l, e);
			break;
		case 4:	printf("������Ҫ��Ҫ���ҵ�ֵ��\n");
			scanf_s("%d", &e);
			CheckLinklist(l, e);
			break;
		case 5:printf("������Ϊ��%d\n", length(l));
			break;
		case 6:PrintfList(l);
			break;
		case 7:	 printf("����������Ϊ��");
			PrintLinklist_back(l);
			break;
		case 8: Sort_Linklist(l);
			break;
		case 9:	  printf("��������������߽�ֵ(����֮���ո�)��");
		
			scanf_s("%d %d", &a, &b);
			Delete_Inboundary(l,a,b);
				break;
		case 10:  Find_max(l);
			printf("%d", &l->data);
			break;
		case 0:printf("��л����ʹ�ã�");
			break;
		default:
			break;
		}
	} while (k!=0);

	system("pause");   
}