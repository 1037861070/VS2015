#include<stdio.h>
#include<stdlib.h>
#include"Tourism.h"
#define bool char
#define TRUE 1
#define FALSE 0	

int main() {
	int num;
	bool frag = TRUE;
	CreatGraph();
	while (frag) {
		printf("=========������Ϣ����ϵͳ===========\n");
		printf("1.������������ͼ\n2.��ѯ������Ϣ\n3.���ξ��㵼��\n4.�������·��\n5.�����·�滮\n0.�˳�\n");
		printf("�����������ţ�0~5��:");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("=========������������ͼ===========\n");
			GetGraphInfo();
			break;
		case 2:
			printf("============��ѯ������Ϣ============\n");
			GetPointInfo();			
			GetSpotInfo();
			break;
		case 3:
			printf("===========���ξ��㵼��=============\n");
			GetPointInfo();		
			TravelPath();
			break;
		case 4:
			printf("===========�������·��===========\n");
			GetPointInfo();
			FindSP();
			break;
		case 5:
			printf("============�����·�滮=============\n");
			DesignPath();
			break;
		case 0:
			frag = FALSE;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}