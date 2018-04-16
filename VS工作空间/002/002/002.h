#pragma once
   //线性表的操作
#define maxsize 50
typedef struct list//结构体
{
	int data[maxsize];//数组下标从0开始
	int length;
}sqlist;
sqlist l;
sqlist InitList(sqlist l);//初始化线性表
sqlist CreatList(sqlist l,int length);//创建线性表
int Length(sqlist l);//求线性表长度
int  LocateElem(sqlist l, int e);//在线性表中查找是否有e元素,有返回1，无返回0
int GetElem(sqlist l,int i);//得到线性表中第i个元素的位置
sqlist ListDelete(sqlist l,int i );//删除线性表中第i个元素的位置，并返回删除元素的值
void PrintList(sqlist l);//输出线性表中的所有值
int  Empty(sqlist l);//有元素返回1，空表返回0




