#include<stdio.h>
#include"head .h"

void main() {
	int e, k;
	//char c;
	s=InitStack(s);
	do
	{
		printf("\n*******请选择你要进行的操作！********\n");
		printf("1.元素入栈\n");
		printf("2.元素出栈！\n");
		printf("3.依次打印栈中元素！\n");
		printf("0.退出！\n");
		scanf_s("%d", &k);
		switch (k)
		{
		case 1:printf("请依次输入入栈元素（输入999结束）：\n");
			scanf_s("%d", &e);
				  while (e != 999)
				  {
					  Push(&s, e);
					  scanf_s("%d", &e);
				  }		
			break;
		case 2:	 if (Pop(&s, &e) != 0) {
			printf("出栈元素为：%d\n  ", e);
		}
			break;
		case 3:		PrintfStack(s);
			break;
		case 0:	   printf("感谢您的使用！：\n"); 
			break;
		default:
			break;
		}
	} while (k!=0);
}