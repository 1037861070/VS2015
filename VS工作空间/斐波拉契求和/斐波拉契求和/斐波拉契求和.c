#include<stdio.h>

int fib(int n);
void main() {
	int n, sum;
	printf("��������Ҫn��ֵ��");
	scanf_s("%d", &n);
	sum = fib(n);
	printf("쳲�����ֵΪ��%d", sum);
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
