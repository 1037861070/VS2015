#include<iostream>
#include "Graph.h"
#include "Tourism.h"

using namespace std;

void CreateGraph(Graph *p)
{
	cout<<"�������㾰��ͼ"<<endl;
	//����ͼ�Ķ���
	(*p).Init();
	FILE *in=fopen("Vex.txt","r");
	if(!in)
	{
		cout<<"�ļ���ȡʧ�ܣ�"<<endl;
	}
	int nsize=0;//�������
	fscanf(in,"%d\n",&nsize);
	cout<<"������Ŀ��"<<nsize<<endl;
	cout<<"-----����-------"<<endl;
	Vex vex;
	while (fscanf(in,"%d\n%s\n%s\n",&vex.num,&vex.name,&vex.desc)!=-1)
	{
		cout<<vex.num<<"-"<<vex.name<<endl;
		//��������
		if (!(*p).InsertVex(vex))    
		{
			cout<<"�洢����ʧ�ܣ�"<<endl;
			continue;
		}

	}
	fclose(in);
	in=NULL;
	cout<<"------��------"<<endl;
	in=fopen("Edge.txt","rb");
	if(!in)
	{
		cout<<"�ļ���ȡʧ�ܣ�"<<endl;
	}
	Edge edge;
	while (fscanf(in,"%d\t%d\t%d\t",&edge.vex1,&edge.vex2,&edge.weight)!=-1)
	{
		cout<<"<V"<<edge.vex1<<",V"<<edge.vex2<<"> "<<edge.weight<<endl;
	
		if (!(*p).InsertEdge(edge))//������
		{
			cout<<"�洢��ʧ�ܣ�"<<endl;
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
	cout<<"��ѡ����Ҫ��ѯ�ľ�����:"<<endl;
	cin>>number;
	vex=(*p).GetVex(number);//��ѯָ��������Ϣ
	cout<<"��������:"<<vex.name<<endl;
	cout<<"�������:"<<vex.desc<<endl;

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

	cout<<"=====���ξ��㵼��====="<<endl;
	cout<<"0-A��"<<endl;
	cout<<"1-B��"<<endl;
	cout<<"2-C��"<<endl;
	cout<<"3-D��"<<endl;
	cout<<"4-E��"<<endl;
	cout<<"5-F��"<<endl;
	cout<<"6-G��"<<endl;
	cout<<"��������ʼ���ţ�";
	cin>>vex;
	cout<<"����·��Ϊ��"<<endl;
	(*p).DFSTraverse(vex);
	for(int i = 0; i < (*p).number; i++){
		cout<<"·��"<<i + 1<<":";
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

	cout<<"=====�������·��======"<<endl;
	cout<<"0-A��"<<endl;
	cout<<"1-B��"<<endl;
	cout<<"2-C��"<<endl;
	cout<<"3-D��"<<endl;
	cout<<"4-E��"<<endl;
	cout<<"5-F��"<<endl;
	cout<<"6-G��"<<endl;
	cout<<"����������ţ�";
	cin>>nVexStar;
	cout<<"�������յ��ţ�";
	cin>>nVexEnd;
	
	q = (*p).FindShortPath(nVexStar,nVexEnd,aPath);

	cout<<"���·��Ϊ��";
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
	cout<<"��̾���Ϊ��"<<aPath[nVexEnd].weight<<endl;
}

void DesingPath(Graph *p)
{
	int alllength;
	int P[20];
	for (int l=0;l<20;l++)
	{
		P[l]=0;
	}
	cout<<"=====�����·�滮====="<<endl;
	cout<<"��������������֮�������·"<<endl;
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
	cout<<"�����·���ܳ���Ϊ:"<<alllength<<endl;
}
