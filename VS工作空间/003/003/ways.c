#include<stdio.h>
#include "head.h"

linklist CreatList(linklist l)//β�巨��������
{
	linklist p, r = l;
	int data;
	//r = (linklist)malloc(sizeof(node));
	printf("����������ֵ��(����999����)\n");
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

linklist InitList(linklist l)//��ʼ������
{
	linklist h;
	h= (linklist)malloc(sizeof(node));
	h->next = NULL;
	return h;
}
void PrintfList(linklist l)
{
	linklist p = l->next;
	printf("����ֵΪ��\n");
	while (p!=NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}
int  DeleteLinklist(linklist l,int e)//ɾ������	��ֵΪe�Ľڵ�
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
		printf("ɾ���ɹ���\n");
		return 1;
	}
	else
		
	return 0;
}
int  InsertLinklist(linklist l, int e)//ͷ�巨����ֵ Ϊe�Ľڵ�
{
	linklist  q;
	q = (linklist)malloc(sizeof(node));
	q->data = e;
	q->next = l->next;
	l->next = q;
}
int  CheckLinklist(linklist l, int e)//����ֵ
{
	linklist p = l->next;
	while (p!=NULL)
	{
		if (p->data == e)
		{
			printf("�����������λ��Ϊ��%d\n", location(l,p->data));
			return 	1;
		}
		p = p->next;
	}
	printf("�������������");
	return 0;
}
int length(linklist l)//��������
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
int location(linklist l, int e) 		  //�ҳ�Ԫ��e��λ��
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
void  PrintLinklist_back(linklist l)	  //ͷ�巨�����������ֵ
{
	linklist pre = l->next;
	linklist  q;
	l->next = NULL;
		//�͵����ã���ԭ�ռ������ò���
	while (pre!=NULL)
	{
		q = pre;
		pre = pre->next;
		q->next = l->next;
		l->next = q;
		
	}
	PrintfList(l);
}

void  Sort_Linklist(linklist l) 	 //����С�����������
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
int Delete_Inboundary(linklist l, int a, int b)//ɾ������a��b֮���ֵ
{
	int min, max,k=0;
	linklist p = l->next, pre = l, q;
	if (a>b)								   //�ҳ�����С��ֵ�ʹ��ֵ
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
		if (p->data>min&&p->data<max)			//��p��������q����ֵɾ��
		{
			q = p;
			pre->next = q->next;				  //pre����Ҫ�ƶ���ɾ�����ƶ�p������pǰ��һ�����
			p = p->next;
			free(q);
			k++;
		}
		pre = pre->next;
		p = p->next;
	}
	if (k!=0)
	{
		printf("ɾ���ɹ������Ϊ��\n");
		PrintfList(l);
	}
	else
	{
		printf("ɾ��ʧ�ܣ�\n");
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