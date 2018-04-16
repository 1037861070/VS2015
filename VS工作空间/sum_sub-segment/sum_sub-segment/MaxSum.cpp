#include "MaxSum.h"


int MaxSum(int a[],int lleft,int rright)
{
	int sum=0,midsum=0,leftsum=0,rightsum=0,i=0,j=0;
	int center,s1,s2,lefts,rights;
	if(lleft==rright)
	{
		sum=lleft;
	}
	else
	{
		center=(lleft+rright)/2;
		leftsum=MaxSum(a,lleft,center);
		rightsum=MaxSum(a,center+1,rright);
		s1=0;lefts=0;
		for (i=center;i>=lleft;i--)
		{
			lefts=lefts+a[i];
			if(lefts>s1)
				s1=lefts;
         }
		s2=0;rights=0;
			for (j=center+1;j<=rright;j++)
			{
				rights=rights+a[j];
				if(rights>s2)
					s2=rights;
			}
			midsum=s1+s2;
			if(midsum<leftsum)
				sum=leftsum;
			else sum=midsum;
			if(sum<rightsum)
				sum=rightsum;
	}
	return sum;
}