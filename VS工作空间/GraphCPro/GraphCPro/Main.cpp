#include<iostream>
#include "Graph.h"
#include "Tourism.h"
using namespace std;

int main()
{
	int i=-1;
	Graph graph=Graph();
	Graph *p=&graph;
	cout<<"*********景区信息管理系统**********"<<endl;
	do 
	{
		cout<<"1.创建景区信息图"<<endl;
		cout<<"2.查询景点信息"<<endl;
		cout<<"3.旅游景点导航"<<endl;
		cout<<"4.搜索最短路径"<<endl;
		cout<<"5.铺设电路规划"<<endl;
		cout<<"0.退出"<<endl;
		cout<<"请输入你要进行的选项(0-5)"<<endl;
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
	cout<<"欢迎再次使用，谢谢!"<<endl;
	system("pause");
	return 0;

}