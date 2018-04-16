#include<stdio.h>

int fib(int n);
void main() {
	int n, sum;
	printf("请输入你要n的值：");
	scanf_s("%d", &n);
	sum = fib(n);
	printf("斐波拉契值为：%d", sum);
	system("pause");
}
int  fib(int n)
{
	if (n == 2)
		return 1;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
