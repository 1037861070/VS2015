#include<iostream>
#include "Graph.h"
#include "Tourism.h"
using namespace std;

int main()
{
	int i=-1;
	Graph graph=Graph();
	Graph *p=&graph;
	cout<<"*********������Ϣ����ϵͳ**********"<<endl;
	do 
	{
		cout<<"1.����������Ϣͼ"<<endl;
		cout<<"2.��ѯ������Ϣ"<<endl;
		cout<<"3.���ξ��㵼��"<<endl;
		cout<<"4.�������·��"<<endl;
		cout<<"5.�����·�滮"<<endl;
		cout<<"0.�˳�"<<endl;
		cout<<"��������Ҫ���е�ѡ��(0-5)"<<endl;
		cin>>i;
		switch (i)
		{
		case 1:CreateGraph(p);
			break;
		
		case 2:GetSpotInfo(p);
			break;
		case 3:TravelPath(p);
			break;
		case 4:findShortPath(p);
			break;
		case 5:DesingPath(p);
			break;
		}
	} while (i!=0);
	cout<<"��ӭ�ٴ�ʹ�ã�лл!"<<endl;
	system("pause");
	return 0;

}