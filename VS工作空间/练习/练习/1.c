#include<stdio.h>
#define maxsize 100
void  buble(int a[], int ncount);
void main() {
	int a[maxsize];
	int i,ncount,flag;
	printf("��������Ҫ�����������Ŀ��");
	scanf_s("%d", &ncount);
	printf("��������Ҫ��������֣�");
	for (i = 0;i <ncount; i++)
		scanf_s("%d", &a[i]);
	    buble(a, ncount);
	for (i = 0; i <ncount; i++)
		printf("%d  ",a[i]);
	system("pause");
}

//ð������
void buble(int a[], int ncount) {
	int i, j, flag;
	for (i = 0; i < ncount - 1; i++)
	{
		for (j = 0; j < ncount - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				flag = a[j];
				a[j] = a[j + 1];
				a[j + 1] = flag;
			}
		}
	}
}