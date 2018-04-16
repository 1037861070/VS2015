#include <iostream>
#include "MaxSum.h"
using namespace std;

int main()
{
	int a,i,n;
	int kui[100];
	cout<<"请输入数组元素个数："<<endl;
	cin>>n;
	cout<<"输入整数序列:";
	for(i=0;i<n;i++)
	{
        cin>>kui[i];
	}
	a=MaxSum(kui,0,n);
	cout<<"所求数组中最大字段和为:"<<a<<endl;
	system("pause");
	return 0;
}