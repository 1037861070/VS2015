#include <stdio.h>
#define bool char
#define TRUE 1
#define FALSE 0
#define Size 100
int b[50];
int sum=0;
int cnt;
bool countValue(int number);
void WriteDat();
int main()
{
	int I,i,j;
	int m;
	
	cnt=0;
	for (i=2;i<=Size - 10;i++)
    {  
		if(countValue(i) && countValue(i + 4) && countValue(i + 10))
			b[cnt++] = i;
	}
	for (i=0;i<cnt;i++)
	{
		sum=sum+b[i];
	}
	printf("%d %d",cnt,sum);
	WriteDat();
	system("pause");
	return 0;
}

bool countValue(int number){
	int m;
	int i, j;
	m=0;
	for (j=1;j<=number;j++)
	{ 
		if (number%j==0)
		{   
			m++;
		}			  
	}
	if (m==2)
		return TRUE;
	else
		return FALSE;
}
void WriteDat()
{
	FILE *p;
	p=fopen("out.txt","wt");
	fprintf(p,"%d %d",cnt,sum);
	printf("Êä³ö³É¹¦£¡");
	fclose(p);
}