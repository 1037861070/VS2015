#include <stdio.h>
#define SIZE 100
void ReaDat(int n);
void jsSort(int n);
void WriteDat(int n);
int aa[SIZE];
int bb[SIZE];
int main()
{
	int n;
	printf("������Ҫ�����ѧ��������");
	scanf("%d",&n);
	ReaDat(n);
	jsSort(n);
	WriteDat(n);
	system("pause");
	return 0;
}


void ReaDat(int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("�������%d���˵�ѧ��,�ɼ�(ѧ�źͳɼ��м�ո�):\n",i+1);
		scanf("%d %d",&aa[i],&bb[i]);
	}
}

void jsSort(int n)
{
	int i,j,temp;
	for (i=0;i<n;i++)
		for(j=i+1;j<n;j++)
	{
		if (aa[i]>aa[j])
	{   temp=aa[i];
		aa[i]=aa[j];
		aa[j]=temp;
	}
		if (bb[i]>bb[j])
		{
			temp=bb[i];
			bb[i]=bb[j];
			bb[j]=temp;
		}
	}
}

void WriteDat(int n)
{
	int i;
	printf("�����ѧ��ѧ��������ʾ��\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",aa[i]);
	}
	printf("\n");
	printf("�����ѧ���ɼ�������ʾ��\n");
	for (i=0;i<n;i++)
	{
		printf("%d  ",bb[i]);	
	}
	printf("\n");

}