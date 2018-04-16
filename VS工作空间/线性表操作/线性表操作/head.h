#ifndef HEAD

#define _CRT_SECURE_NO_WARNING
#define SIZE 50
//链表结构体
typedef struct node{
int data;
struct node *next;
}node,*linklist;

//顺序表结构体
typedef struct sqlist{
int data[SIZE];
int length;
}sqlist;

//初始化链表
linklist initiallist();
//创建链表
linklist createlist(linklist l);
//输出链表
void outputlist(linklist l);
//查找值
int  check(linklist l,int x);
//删除值为x的节点
linklist deletelist(linklist l,int x);

//linklist Getelem(linklist l,int i);
//插入值为x的节点，在表头插入
linklist insertlist(linklist l,int x);
#endif