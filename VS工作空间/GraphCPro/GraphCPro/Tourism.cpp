#include<iostream>
#include "Graph.h"
#include "Tourism.h"

using namespace std;

void CreateGraph(Graph *p)
{
	cout<<"创建景点景区图"<<endl;
	//设置图的顶点
	(*p).Init();
	FILE *in=fopen("Vex.txt","r");
	if(!in)
	{
		cout<<"文件读取失败！"<<endl;
	}
	int nsize=0;//顶点个数
	fscanf(in,"%d\n",&nsize);
	cout<<"顶点数目："<<nsize<<endl;
	cout<<"-----顶点-------"<<endl;
	Vex vex;
	while (fscanf(in,"%d\n%s\n%s\n",&vex.num,&vex.name,&vex.desc)!=-1)
	{
		cout<<vex.num<<"-"<<vex.name<<endl;
		//新增顶点
		if (!(*p).InsertVex(vex))    
		{
			cout<<"存储顶点失败！"<<endl;
			continue;
		}

	}
	fclose(in);
	in=NULL;
	cout<<"------边------"<<endl;
	in=fopen("Edge.txt","rb");
	if(!in)
	{
		cout<<"文件读取失败！"<<endl;
	}
	Edge edge;
	while (fscanf(in,"%d\t%d\t%d\t",&edge.vex1,&edge.vex2,&edge.weight)!=-1)
	{
		cout<<"<V"<<edge.vex1<<",V"<<edge.vex2<<"> "<<edge.weight<<endl;
	
		if (!(*p).InsertEdge(edge))//新增边
		{
			cout<<"存储边失败！"<<endl;
			continue;
		}
	}
	fclose(in);
	in=NULL;
	
}

void GetSpotInfo(Graph *p)
{
	int number;
	Vex vex;
	cout<<"请选择你要查询的景点编号:"<<endl;
	cin>>number;
	vex=(*p).GetVex(number);//查询指定顶点信息
	cout<<"景点名字:"<<vex.name<<endl;
	cout<<"景点介绍:"<<vex.desc<<endl;

}


void TravelPath(Graph *p)
{
	int vex;
/*	PathList phead, pr;
//	phead=(PathList)malloc(sizeof(Path));
//	pr = phead;
//	phead->next = NULL;
//	PathList plist;
//	plist=(PathList)malloc(sizeof(Path));
    plist->next=NULL;*/

	cout<<"=====旅游景点导航====="<<endl;
	cout<<"0-A区"<<endl;
	cout<<"1-B区"<<endl;
	cout<<"2-C区"<<endl;
	cout<<"3-D区"<<endl;
	cout<<"4-E区"<<endl;
	cout<<"5-F区"<<endl;
	cout<<"6-G区"<<endl;
	cout<<"请输入起始点编号：";
	cin>>vex;
	cout<<"导游路线为："<<endl;
	(*p).DFSTraverse(vex);
	for(int i = 0; i < (*p).number; i++){
		cout<<"路线"<<i + 1<<":";
		cout<<(*p).Vexs[(*p).aPath[i][0]].name;
		for(int j = 1; j < (*p).VexNum; j++)
		{
			cout<<"->"<<(*p).Vexs[(*p).aPath[i][j]].name;
		}
		cout<<endl;
	}
}

void findShortPath(Graph *p)
{
	int nVexStar,nVexEnd;
	int* q;
	Edge aPath[20];
	
	for (int j=0;j<20;j++)
	{aPath[j].vex1=-1;
	aPath[j].vex2=j;
	aPath[j].weight=0;
	}

	cout<<"=====搜索最短路径======"<<endl;
	cout<<"0-A区"<<endl;
	cout<<"1-B区"<<endl;
	cout<<"2-C区"<<endl;
	cout<<"3-D区"<<endl;
	cout<<"4-E区"<<endl;
	cout<<"5-F区"<<endl;
	cout<<"6-G区"<<endl;
	cout<<"请输入起点编号：";
	cin>>nVexStar;
	cout<<"请输入终点编号：";
	cin>>nVexEnd;
	
	q = (*p).FindShortPath(nVexStar,nVexEnd,aPath);

	cout<<"最短路线为：";
	cout<<(*p).Vexs[nVexEnd].name;
	
	
	int k = nVexEnd;
	int m;
	while(q[k]!=nVexStar){	
		m= q[k];
		cout<<"<-"<<(*p).Vexs[m].name;
		k = m;
	}
	m = q[k];
	cout<<"<-"<<(*p).Vexs[m].name<<endl;
	cout<<"最短距离为："<<aPath[nVexEnd].weight<<endl;
}

void DesingPath(Graph *p)
{
	int alllength;
	int P[20];
	for (int l=0;l<20;l++)
	{
		P[l]=0;
	}
	cout<<"=====铺设电路规划====="<<endl;
	cout<<"在以下两个景点之间铺设电路"<<endl;
	Edge apath[20];
	for (int j=0;j<20;j++)
	{
		apath[j].weight=0;
	}
	int m=0;
	int k;
	alllength=(*p).FindMinTree(apath,P);
	for (int i = 0; i < (*p).VexNum - 1; i++)
	{
		int m = p->sort[i];
		int n = P[m];
		Vex vex1 = (*p).GetVex(m);
		Vex vex2 = (*p).GetVex(n);
		printf("%s-%s %d\n",vex2.name,vex1.name,apath[m].weight);
	}
/*	for (m=0;m<(*p).VexNum;m++)
	{while (P[m]=0)
	{
		k=m;
		break;
	}
	}
	while (P[m]!=-1)
	{
		k=P[m];

	}

	while(P[])*/
	cout<<"铺设电路的总长度为:"<<alllength<<endl;
}
