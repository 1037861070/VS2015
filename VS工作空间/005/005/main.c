#include<stdio.h>
#include"head.h"

void main() {
	int k ;
	char e, buffer[1024];
	FILE *fp;
	if ((fp=fopen("1.txt","r+"))==NULL)
	{
		printf("The file can not be opened.\n");
	}
	while (fgets(buffer,"1024",fp)!=NULL)
	{
		printf("%s\n", buffer);
	}
	T=InitBitree(T);
	do
	{

		printf("\n*******��ѡ����Ҫ���еĲ�����********\n");
		printf("1.����һ�Ŷ�����\n");
		printf("2.���������������\n");
		printf("3.���������������\n");
		printf("4.����������������\n");
		printf("5.������ĸ߶ȣ�\n");
		printf("0.�˳���\n");
		scanf_s("%d", &k);
		switch (k)
		{
		case 1:		 printf("ǰ�򴴽��������������������ַ�������#���ʾ��ǰ�ڵ�Ϊ�գ�\n");
			e = getchar();	  //ȥ��һ��enter��λ
			T=CreateBitree(T);
			//PreOrder(T);
			break;
		case 2:	PreOrder(T);
				 break;
		case 3:	InOrder(T);
			break;
		case 4:	 PostOrder(T);
			break;
		case 5:printf("�ö������߶�Ϊ��%d\n", HeightTree(T));
			break;
		case 0:	   printf("��л����ʹ�ã�");
			break;
		default:
			break;
		}
	} while (k != 0);
}