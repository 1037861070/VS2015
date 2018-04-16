#include<stdio.h>
void main() {
	int t[10], i;
	for (i = 1; i < 10; i++)
	{
		t[i] = i;
		printf("%d  ", t[i]);
	}
	system("pause");
}