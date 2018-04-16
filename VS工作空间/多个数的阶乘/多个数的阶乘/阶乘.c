#include<stdio.h>
#define Maxsize 100
void factorial(int N[], int n);
void main() {
	int N[Maxsize];
	int n = 0, i;
	//printf("请输入你要的阶乘数：（输入非正数自动结束！）");
	while (scanf_s("%d", &N[n]) != EOF)
	{
		n++;
	}
	factorial(N, n);
	for (i = 0; i < n; i++)
		printf("%d\n", N[i]);
	 system("pause");
}
void factorial(int N[], int n) {
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
	}
}