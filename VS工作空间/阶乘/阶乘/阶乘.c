#include<stdio.h>

#define Maxsize 1000
void factorial(long N[], int n);
void main() {
	long N[Maxsize];
	int n = 0, i;
	printf("请输入你要的阶乘数：（输入非正数自动结束！）\n");
	scanf_s("%d", &N[n]);
	while (N[n]>0)
	{
		scanf_s("%d", &N[++n]);
	}
	factorial(N, n);
	for (i = 0; i < n; i++)
	printf("%d\n", N[i]);
	system("pause");
}
void factorial(long N[], int n) {
	int i, k, sum = 1;
	for (i = 0; i < n; i++)
	{
		k = N[i];
		while (k != 0)
		{
			sum = k*sum;
			k--;
		}
		N[i] = sum;
		sum = 1;
	}
}