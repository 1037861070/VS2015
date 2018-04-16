#include<iostream>
#include<string.h>
#include<cstdio>
#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
#define MAX 100+10
#define MOD 100000000
const int inf = 0x7fffffff;
int min_cap[MAX];
int max_cap[MAX];
int dp[1000010];
int item[4510];
bool in_item[4510];

inline int max(int x,int y)
{
	return x > y ? x : y;
}

int  main()
{
	int V,n;
	printf("�������ϾƵ���������ѡ�õľ�ƿ������:\n");
	while (scanf("%d %d",&V,&n)==2)
	{
		int sz = 0;
		memset(in_item,false,sizeof(in_item));
		int tem_min = inf;
		V *= 1000;
		bool ok = false;
		if (V==0) ok = true;
		for (int i = 1 ; i <= n ; ++i)
		{
			printf("�������%d�ֹ���ƿ�����������ޣ�\n",i);
			scanf("%d %d",min_cap+i,max_cap+i);
			if (ok) continue;
			tem_min = min(min_cap[i],tem_min);
			for (int j = min_cap[i] ; j <= max_cap[i] ; ++j)
			{
				if (V%j==0) 
				{
					ok = true;
					break;
				}

				if (!in_item[j])
				{
					item[sz++] = j;
					in_item[j] = true;
				}
			}
		}
		if (ok)
		{
			printf("���ʣ�������Ϊ��0\n");
			continue;
		}
		memset(dp,0,sizeof(dp));
		if (V>1000000) V = V-tem_min*(1+(V-1000000)/tem_min);
		for (int i = 0 ; i < sz ; ++i)
		{
			int w = item[i];
			for (int j = w ; j <= V ; ++j) if (dp[j-w]+w>dp[j])
				dp[j] = dp[j-w]+w;
		}
		printf("���ʣ�������Ϊ��%d\n",V-dp[V]);
	}
	return 0;
}

