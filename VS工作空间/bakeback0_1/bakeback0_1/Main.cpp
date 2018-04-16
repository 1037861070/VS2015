
#include <iostream>
#include <algorithm>
using namespace std;
#define Size 50
int x[Size]={-1};
int V[Size][Size];

int knapsack(int w[],int v[],int n,int c)
{
	int i,j;
	for (i=0;i<=n;i++)
		V[i][0]=0;
	for (j=0;j<=c;j++)
		V[0][j]=0;
	for(i=1;i<=n;i++)
		for (j=1;j<=c;j++)
		    if(j<w[i])  
				V[i][j]=V[i-1][j];
			else
				V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+v[i]);
		for (j=c,i=n;i>0;i--)
		{
			if(V[i][j]>V[i-1][j])
			{
				x[i]=1;
				j=j-w[i];
			}
			else
				x[i]=0;
		}
	return V[n][c];
}

void main()
{
     int i,j,n,c,price=0;
	 int w[Size]={0},v[Size]={0};
	 cout<<"��������Ʒ�����ͱ���������"<<endl;
	 cin>>n;
	 cin>>c;
	 cout<<"��������Ʒ������"<<endl;
	 for (i=1;i<=n;i++)
	 {
		 cin>>w[i];
	 }
	 cout<<"��������Ʒ��ֵ��"<<endl;
	 for (j=1;j<=n;j++)
	 {
		 cin>>v[j];
	 }
	
	 price=knapsack(w,v,n,c);
	 cout<<"����������ֵ:"<<price<<endl;
	 cout<<"װ�뱳������ƷΪ:"<<endl;
	for (i=1;i<=n;i++)
	{
		if (x[i]==1)
		{
			cout<<i<<endl;
		}
	}
	system("pause");
}