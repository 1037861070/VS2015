#include<stdio.h>
#include <stdlib.h>

int a = 0, b = 0, c = 0;
void shuru();
void panduan(int a1, int b1, int c1);
void main()
{
	char se;
	shuru();
	panduan(a, b, c);
	while (1)
	{
		printf("是否要继续y or n :");
		scanf("%c", &se);
		if (se == '\n') scanf("%c", &se);
		switch (se)
		{
		case 'y':
			shuru();
			panduan(a, b, c);
			break;
		case 'n':
			return;
		}
	}
}
void shuru()
{
	printf("Please enter 三角形三边 (a,b,c)\n");
	scanf("%d,%d,%d", &a, &b, &c);
	while ((a<1 || a>100) || (b<1 || b>100) || (c<1 || c>100))
	{
		if (a == 0 || b == 0 || c == 0) printf("边长不能为0\n");
		else if (a<0 || b<0 || c<0) printf("边长不能为负\n");
		else printf("Please enter 1-100之间的整数\n");
		scanf("%d,%d,%d", &a, &b, &c);
	}
}
void panduan(int a1, int b1, int c1)
{
	int m1 = a1 + b1;
	int m2 = a1 + c1;
	int m3 = b1 + c1;
	if (a1 >= m3 || b1 >= m2 || c1 >= m1) printf("非三角形\n");
	else if (a1 != b1&&a1 != c1&&b1 != c1) printf("一般三角形\n");
	else if ((a1 == b1&&b1 != c1) || (a1 == c1&&a1 != b1) || (c1 == b1&&a1 != c1)) printf("等腰三角形\n");
	else if (a1 == b1&&b1 == c1) printf("等边三角形\n");
}

