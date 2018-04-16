#include<stdio.h>
#include "002.h"

sqlist InitList(sqlist l) {
	l.length = 0;
	return l;
}
//初始化线性表
sqlist CreatList(sqlist l,int length) {
	
	printf("请输出线性表的值：");
	while (l.length<length)
	{
		scanf_s("%d", &l.data[l.length++]);
	}
	return l;
}//创建线性表
int Length(sqlist l) {
	return l.length;
}
//求线性表长度
int  LocateElem(sqlist l, int e) {
	int i;
	for (i = 0; i < l.length; i++)
	{
		if (l.data[i] == e)
			return 1;
	}
	return 0;
}
//在线性表中查找是否有e元素,有返回1，无返回0
int GetElem(sqlist l, int i) {
	if (i > l.length || i < 0)
	{
		printf("数组越界");
		return 0;
	}
	else
		return l.data[i - 1];
}
//得到线性表中第i个元素的值
sqlist ListDelete(sqlist  l, int i) {
	int j;
	if (i<0 || i>l.length)
	{
		printf("位置不对！");
		return  l;
	}
	for (j = i - 1; j < l.length - 1;j++) 
		{ 
		l.data[j] = l.data[j + 1];
		}
	l.length--;
	return l;
}
//删除线性表中第i个元素的值，并用e返回删除元素的值
void PrintList(sqlist l) {
	int j = 0;
	while (j <l.length)
	{
		printf("%d  ",l.data[j]);
		j++;
	}
}
//输出线性表中的所有值
int  Empty(sqlist l) {
	if (l.length == 0)
		return 0;
	else
		return 1;
}
//有元素返回1，空表返回0