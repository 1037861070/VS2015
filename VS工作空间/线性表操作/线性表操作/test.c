#include<stdio.h>
#include <stdlib.h>
#include "head.h"

void main(){
	int  x,flag;
	linklist  l,m;
	l=initiallist();
	printf("��������ֵ��\n");
	l=createlist(l);
	printf("�������ֵ��\n");
	outputlist(l);
	printf("����ֵx��\n");
	scanf("%d",&x);
	flag=check(l,x);
	printf("���ҽ��(1���ڣ�0������) ��%d\n",flag);
	/*printf("���ҵ�X��Ԫ�أ�\n");
	scanf("%d",&x);
	m=Getelem(l,x);
	printf("��%d��Ԫ��ֵΪ��%d\n",&x,&m->data);*/
	printf("���ֵx��\n");
	scanf("%d",&x);
	l=insertlist(l,x);
	outputlist(l);
	printf("ɾ��ֵx��\n");
	scanf("%d",&x);
	l=deletelist(l,x);
    outputlist(l);

	system("pause");
}

