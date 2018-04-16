#include<stdio.h>
#include <stdlib.h>
#include "head.h"

void main(){
	int  x,flag;
	linklist  l,m;
	l=initiallist();
	printf("输入链表值：\n");
	l=createlist(l);
	printf("输出链表值：\n");
	outputlist(l);
	printf("查找值x：\n");
	scanf("%d",&x);
	flag=check(l,x);
	printf("查找结果(1存在，0不存在) ：%d\n",flag);
	/*printf("查找第X个元素：\n");
	scanf("%d",&x);
	m=Getelem(l,x);
	printf("第%d个元素值为：%d\n",&x,&m->data);*/
	printf("添加值x：\n");
	scanf("%d",&x);
	l=insertlist(l,x);
	outputlist(l);
	printf("删除值x：\n");
	scanf("%d",&x);
	l=deletelist(l,x);
    outputlist(l);

	system("pause");
}

