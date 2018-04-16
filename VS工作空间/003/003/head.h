#pragma once
//链表的操作
typedef struct node {
	struct node * next;
	int data;
}node,*linklist;
linklist l;
linklist CreatList(linklist l);//创建链表
linklist InitList(linklist l);//初始化链表
void PrintfList(linklist l);//输出链表值
int  DeleteLinklist(linklist l,int e);//删除链表
int  InsertLinklist(linklist l, int e);//插入值
int  CheckLinklist(linklist l, int e);//查找值
int length(linklist l);//求链表长度
int location(linklist l,int e);//求e所在链表的位置
void  PrintLinklist_back(linklist l);//反向输出链表中的值
void  Sort_Linklist(linklist l);//按从小到大进行排序
int Delete_Inboundary(linklist l,int a,int b);//删除介于a和b之间的值；
int Find_max(linklist l);//找出链表最大值