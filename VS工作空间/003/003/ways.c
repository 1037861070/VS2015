#include<stdio.h>
#include "head.h"

linklist CreatList(linklist l)//尾插法创建链表
{
	linklist p, r = l;
	int data;
	//r = (linklist)malloc(sizeof(node));
	printf("请输入链表值：(输入999结束)\n");
	scanf_s("%d", &data);
	while (data!=999)
	{
		p = (linklist)malloc(sizeof(node));
		p->data = data;
		r->next = p;
		r = p;
		scanf_s("%d", &data);
	}
	r->next = NULL;
	return l;
}

linklist InitList(linklist l)//初始化链表
{
	linklist h;
	h= (linklist)malloc(sizeof(node));
	h->next = NULL;
	return h;
}
void PrintfList(linklist l)
{
	linklist p = l->next;
	printf("链表值为：\n");
	while (p!=NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}
int  DeleteLinklist(linklist l,int e)//删除链表	中值为e的节点
{
	linklist p = l->next, r = l,q;
	if (CheckLinklist(l, e) != 0)
	{
		while (p != NULL)
		{
			if (p->data == e)
			{
				q = p;
				r->next = q->next;
				p = p->next;
				free(q);
			}
			else
			{
				p = p->next;
				r = r->next;
			}
		}
		printf("删除成功！\n");
		return 1;
	}
	else
		
	return 0;
}
int  InsertLinklist(linklist l, int e)//头插法插入值 为e的节点
{
	linklist  q;
	q = (linklist)malloc(sizeof(node));
	q->data = e;
	q->next = l->next;
	l->next = q;
}
int  CheckLinklist(linklist l, int e)//查找值
{
	linklist p = l->next;
	while (p!=NULL)
	{
		if (p->data == e)
		{
			printf("存在这个数！位置为：%d\n", location(l,p->data));
			return 	1;
		}
		p = p->next;
	}
	printf("不存在这个数！");
	return 0;
}
int length(linklist l)//求链表长度
{
	int k=0;
	linklist p = l->next;
	while (p!=NULL)
	{
		k++;
		p = p->next;
	}
	return k;
}
int location(linklist l, int e) 		  //找出元素e的位置
{
	int k=0;
	linklist p=l->next;
	while (p!=NULL)
	{
		if (p->data == e)
		{
			k++;
			break;
		}
		else
		{
			k++;
			p = p->next;
		}
	}
	return k;
}
void  PrintLinklist_back(linklist l)	  //头插法反向输出链表值
{
	linklist pre = l->next;
	linklist  q;
	l->next = NULL;
		//就地逆置，在原空间上逆置操作
	while (pre!=NULL)
	{
		q = pre;
		pre = pre->next;
		q->next = l->next;
		l->next = q;
		
	}
	PrintfList(l);
}

void  Sort_Linklist(linklist l) 	 //按从小到大进行排序
{
	linklist p = l->next, pre;
	linklist r = p->next;
	p->next = NULL;
	p = r;
	while (p!=NULL)
	{
		r = p->next;
		pre = l;
		while (pre->next!=NULL&&pre->next->data<p->data)
		{
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
		
	}
	PrintfList(l);
}
int Delete_Inboundary(linklist l, int a, int b)//删除给定a和b之间的值
{
	int min, max,k=0;
	linklist p = l->next, pre = l, q;
	if (a>b)								   //找出其中小的值和大的值
	{
		min = b;
		max = a;
	}
	else
	{
		min = a;
		max = b;
	}
	while (p!=NULL)
	{
		if (p->data>min&&p->data<max)			//用p来遍历，q来赋值删除
		{
			q = p;
			pre->next = q->next;				  //pre不需要移动，删除后移动p，还在p前面一个结点
			p = p->next;
			free(q);
			k++;
		}
		pre = pre->next;
		p = p->next;
	}
	if (k!=0)
	{
		printf("删除成功！结果为：\n");
		PrintfList(l);
	}
	else
	{
		printf("删除失败！\n");
	}
	return k;
}
int Find_max(linklist l) {
	linklist p = l->next, q;
	int max=0;
	if (p=NULL)
	{
		return 0;
	}
	max = p->data;

	while (p->next!=NULL )
	{
		if (p->data<p->next->data)
		{
			max = p->next->data;
		}
		p = p->next;
	}
	l->data = max;
}