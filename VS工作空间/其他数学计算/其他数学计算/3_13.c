#include <stdio.h>

#define Size 50
int b[3];
void WriteDate();
int main()
{
	int i=0,si=0;
	int a[Size];
	int s[Size];
	 a[0]=1,a[1]=1;
	si=a[0]+a[1];
	for (i=2;i<Size;i++)
	{
		a[i]=a[i-1]+a[i-2];
		si=si+a[i];
		s[i]=si;
	}
	for (i=0;i<Size;i++)
	{
		int M1=100;
		if (s[i]<M1&&s[i+1]>M1)
		{
			b[0]=i;
			break;
		}
	
	}
	for (i=0;i<Size;i++)
	{
		int M2=1000;
		if (s[i]<M2&&s[i+1]>M2)
		{
			b[1]=i;
			break;
		}
	}
	for (i=0;i<Size;i++)
	{
		int M3=10000;
		if (s[i]<M3&&s[i+1]>M3)
		{
			b[2]=i;
			break;
		}
	}
	printf("%d %d %d",b[0],b[1],b[2]);
	WriteDate();
	system("pause");
	return 0;
}

void WriteDate()
{
	FILE *p;
	int i=0;
	p=fopen("out.txt","wt");
	for (i;i<3;i++)
	{
		fprintf(p,"%d  ",b[i]);
		printf("\n");
		printf("文件写入成功！");
	}
	fclose(p);
}