#include<stdio.h>
#include"head .h"

void main() {
	int e, k;
	//char c;
	s=InitStack(s);
	do
	{
		printf("\n*******��ѡ����Ҫ���еĲ�����********\n");
		printf("1.Ԫ����ջ\n");
		printf("2.Ԫ�س�ջ��\n");
		printf("3.���δ�ӡջ��Ԫ�أ�\n");
		printf("0.�˳���\n");
		scanf_s("%d", &k);
		switch (k)
		{
		case 1:printf("������������ջԪ�أ�����999��������\n");
			scanf_s("%d", &e);
				  while (e != 999)
				  {
					  Push(&s, e);
					  scanf_s("%d", &e);
				  }		
			break;
		case 2:	 if (Pop(&s, &e) != 0) {
			printf("��ջԪ��Ϊ��%d\n  ", e);
		}
			break;
		case 3:		PrintfStack(s);
			break;
		case 0:	   printf("��л����ʹ�ã���\n"); 
			break;
		default:
			break;
		}
	} while (k!=0);
}