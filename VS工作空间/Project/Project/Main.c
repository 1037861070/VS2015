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
		printf("=========景区信息管理系统===========\n");
		printf("1.创建景区景点图\n2.查询景点信息\n3.旅游景点导航\n4.搜索最短路径\n5.铺设电路规划\n0.退出\n");
		printf("请输入操作编号（0~5）:");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("=========创建景区景点图===========\n");
			GetGraphInfo();
			break;
		case 2:
			printf("============查询景点信息============\n");
			GetPointInfo();			
			GetSpotInfo();
			break;
		case 3:
			printf("===========旅游景点导航=============\n");
			GetPointInfo();		
			TravelPath();
			break;
		case 4:
			printf("===========搜索最短路径===========\n");
			GetPointInfo();
			FindSP();
			break;
		case 5:
			printf("============铺设电路规划=============\n");
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