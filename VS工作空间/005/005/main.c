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

		printf("\n*******请选择你要进行的操作！********\n");
		printf("1.创建一颗二叉树\n");
		printf("2.先序遍历二茶树！\n");
		printf("3.中序遍历二叉树！\n");
		printf("4.后续遍历二叉树！\n");
		printf("5.求该树的高度！\n");
		printf("0.退出！\n");
		scanf_s("%d", &k);
		switch (k)
		{
		case 1:		 printf("前序创建二叉树，请输入连续字符，输入#后表示当前节点为空：\n");
			e = getchar();	  //去掉一个enter键位
			T=CreateBitree(T);
			//PreOrder(T);
			break;
		case 2:	PreOrder(T);
				 break;
		case 3:	InOrder(T);
			break;
		case 4:	 PostOrder(T);
			break;
		case 5:printf("该二叉树高度为：%d\n", HeightTree(T));
			break;
		case 0:	   printf("感谢您的使用！");
			break;
		default:
			break;
		}
	} while (k != 0);
}