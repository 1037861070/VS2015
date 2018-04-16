#include<stdio.h>
#include "head.h"

//初始化链表
linklist initiallist(){
linklist l;
l=(node* )malloc(sizeof(node));
l->next=NULL;
return l;
}
//创建链表
linklist createlist(linklist l){
linklist r,p;
int x;
r=l;
scanf("%d",&x);
while(x!=999)
{
    p=(node* )malloc(sizeof(node));
	p->data=x;
	r->next=p;
	r=r->next;
	scanf("%d",&x);
}
r->next=NULL;
return l;
}
//输出链表
void outputlist(linklist l){
	linklist p;
	p=l->next;
while(p!=NULL)
{
	printf("%d  ",p->data);
	p=p->next;
}
printf("\n");
}
//查找值
int  check(linklist l,int x){
	linklist p;
	p=l->next;
	while(p!=NULL)
	{
		if(p->data==x)
		{
		   return 1;
		   
		}
		p=p->next;
	}
	return 0;
}
//删除值为x的节点
linklist deletelist(linklist l,int x){
linklist p,m,n;
int  k=0,count=0;
p=l->next;
m=l->next;
while(p!=NULL)
{
		k++;
	if(p->data==x)
	{
		count=k;
	}
	p=p->next;

}
k=0;
while(m!=NULL)
{
	k++;
	if(k==count-1)
	{  n=m->next;
	m->next=n->next;
	free(n);
	}
	else
	m=m->next;
}
return l;
}
/*linklist Getelem(linklist l,int x){
linklist p,n;
int k=0;
if(x==0)
printf("没有元素!");
p=l->next;
while(p!=NULL){
    k++;
	if(k==x){
    n=p;
	return n;
	}
	p=p->next;
}
return l;
}*/
//插入值为x的节点，在表头插入
linklist insertlist(linklist l,int x){
	linklist p,m;
	m=(node* )malloc(sizeof(node));
	m->data=x;
	m->next=l->next;
	l->next=m;
	return l;
	    
}