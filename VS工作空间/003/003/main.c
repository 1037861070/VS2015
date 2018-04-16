#include<stdio.h>
#include "head.h"
void main() {
	int k,e;
	int a, b;
	l = InitList(l);
	do
	{
		printf("\n*******************\n");
		printf("请选择你要进行的操作：\n");
		printf("1.创建链表：\n");
		printf("2.删除结点：\n");
		printf("3.插入一个结点：\n");
		printf("4.查找结点结点是否存在：\n");
		printf("5.查看链表长度：\n");
		printf("6.按顺序打印链表值：\n");
		printf("7.就地逆置链表：\n");
		printf("8.对链表值从小到大排序：\n");
		printf("9.删除给定得两个值之间的节点：\n");
		printf("10.求链表中节点最大值，并将之删除赋值给头节点\n");
		printf("0.退出：\n");
		printf("*******************\n");
		scanf_s("%d", &k);
		switch (k)
		{
		case 1:CreatList(l);
			break;
		case 2:printf("输入你要删除的值：\n");
			scanf_s("%d", &e);
			DeleteLinklist(l, e);
			break;
		case 3:printf("输入你要想要插入的值：\n");
			scanf_s("%d", &e);
			InsertLinklist(l, e);
			break;
		case 4:	printf("输入你要想要查找的值：\n");
			scanf_s("%d", &e);
			CheckLinklist(l, e);
			break;
		case 5:printf("链表长度为：%d\n", length(l));
			break;
		case 6:PrintfList(l);
			break;
		case 7:	 printf("逆置输出结果为：");
			PrintLinklist_back(l);
			break;
		case 8: Sort_Linklist(l);
			break;
		case 9:	  printf("输入给定的两个边界值(两数之间打空格)：");
		
			scanf_s("%d %d", &a, &b);
			Delete_Inboundary(l,a,b);
				break;
		case 10:  Find_max(l);
			printf("%d", &l->data);
			break;
		case 0:printf("感谢您的使用！");
			break;
		default:
			break;
		}
	} while (k!=0);

	system("pause");   
}