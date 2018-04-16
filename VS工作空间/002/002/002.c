#include<stdio.h>
#include "002.h"

void main() {
	int i=0, e;
	//sqlist l;
	l=InitList(l);
	printf("请输入你要创建的线性表长度：\n");
	scanf_s("%d", &i);
	l=CreatList(l, i);
	PrintList(l);
	printf("长度是：%d\n", Length(l));
	printf("请输入你要查询的值：\n");
	scanf_s("%d", &e);
	if (LocateElem(l,e))
	{
		printf("存在此元素，查找成功！\n");
	}
	else
	{
		printf("不存在此元素，查找失败！\n");
	}
	printf("请输入你要删除的值位置：\n");
	scanf_s("%d", &i);
	l= ListDelete(l, i);

	printf("现在长度是：%d\n", Length(l));
	system("pause");
}