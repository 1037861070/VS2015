#include <iostream>
#include "MaxSum.h"
using namespace std;

int main()
{
	int a,i,n;
	int kui[100];
	cout<<"����������Ԫ�ظ�����"<<endl;
	cin>>n;
	cout<<"������������:";
	for(i=0;i<n;i++)
	{
        cin>>kui[i];
	}
	a=MaxSum(kui,0,n);
	cout<<"��������������ֶκ�Ϊ:"<<a<<endl;
	system("pause");
	return 0;
}