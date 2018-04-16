#include "Graph.h"
#include <stdio.h>
#define infinite 9999999
void Graph::Init()
{
	int i=0,j=0;
	for (;i<20;i++)
		for(;j<20;j++)
		   AdjMatrix[i][j]=0;
	memset(AdjMatrix,0,sizeof(AdjMatrix));
	VexNum=0;

}

bool Graph::InsertVex(Vex vex)
{
	
    Vexs[VexNum].num=vex.num;
	strcpy(Vexs[VexNum].name,vex.name);
	strcpy(Vexs[VexNum].desc,vex.desc);
	VexNum++;
	return 1;
}

bool Graph::InsertEdge(Edge sEdge)
{
	int i=0,j=0;
	for(i;i<20;i++)
		for (j;j<20;j++)
		{
			AdjMatrix[sEdge.vex1][sEdge.vex2]=sEdge.weight;
			AdjMatrix[sEdge.vex2][sEdge.vex1]=sEdge.weight;
		}
return 1;
}
Vex Graph::GetVex(int number)
{
	
    return Vexs[number];
}

void Graph::DFS(int nVex,bool avisted[],int &nindex,int apath[])
{
    avisted[nVex]=true;//改为已访问
//	PathList plist = pr;
//	plist->vexs[nindex++]=nVex;//访问顶点nvex
	apath[nindex++]= nVex;
	if (nindex==VexNum)
	{
		for(int i = 0; i < VexNum; i++)
			aPath[number][i] = apath[i];
		number++;
	}
	else
	{
		for(int i=0;i<VexNum;i++)
		{
			if (AdjMatrix[nVex][i]&&!avisted[i])  //如果i是nVex的下一个相邻顶点并且没被访问过
			{
				DFS(i,avisted,nindex,apath);
				avisted[i]=false;
				nindex --;
			}
		}
	}

}

void Graph::DFSTraverse(int nVex)
{
    int nindex=0;
	number = 0;
	int apath[20];
	bool avisited[20]={false};
	
	 DFS(nVex,avisited,nindex,apath);
}

int* Graph::FindShortPath(int nVexStart,int nVexEnd,Edge aPath[])
{
	int arr[20][20];
	for(int i = 0; i < VexNum;i++){
		for(int j = 0; j <VexNum; j++){
			if(AdjMatrix[i][j])
				arr[i][j] = AdjMatrix[i][j];
			else
				arr[i][j] = infinite + 1;
		}
	}
	int i=0,data=0;
	int k=-1,j;
	int P[20];
	for (int l=0;l<20;l++)
	{
		P[l]=nVexStart;
	}
	bool avisited[20]={false};
	avisited[nVexStart]=true;
	
	aPath[nVexStart].weight=0;
	for (i;i<VexNum;i++)
	{
		aPath[i].weight=arr[nVexStart][i];
	}
	for(i=1;i<VexNum;i++)
	{
		
		data=infinite;
		k = -1;
		for (j=0;j<VexNum;j++)
		{
			if (!avisited[j]){
				if(aPath[j].weight<data)
			    {
				k=j;
				data=aPath[j].weight;	
			   }
			}
		}
		avisited[k]=true;
		for (int m=0;m<VexNum;m++)
		{
			if (!avisited[m])
			{
				if((data+arr[k][m])<aPath[m].weight){
					aPath[m].weight=data+arr[k][m];
					P[m]=k;
				}				
			}}
	}
	return P;
}

int Graph:: FindMinTree(Edge aPath[],int P[])
{
	bool aVisited[20]={false};
	int arr[20][20];
	int pos=0,result=0;
	int i,j,data;
	int num = 0;
	
	aVisited[0]=true;
	for(int i = 0; i < VexNum;i++){
		for(int j = 0; j <VexNum; j++){
			if(AdjMatrix[i][j])
				arr[i][j] = AdjMatrix[i][j];
			else
				arr[i][j] = infinite + 1;
		}
	}
	
	for (i=0;i<VexNum;i++)
	{
		if (i!=pos)
		{aPath[i].weight=arr[pos][i];
		}
	}
	for (i=1;i<VexNum;i++)
	{
		data=infinite;
		for (j=0;j<VexNum;j++)
		{
			if (!aVisited[j]&&aPath[j].weight<data)
			{
				data=aPath[j].weight;
				pos=j;
			}
		}
		sort[num] = pos;
		num++;
		result=result+data;
		aVisited[pos]=true;
		//更新权值
		for (j=0;j<VexNum;j++)
		{
			if (!aVisited[j]&&aPath[j].weight>arr[pos][j])
			{
				aPath[j].weight=arr[pos][j];
				P[j]=pos;
			}
		}
	}
	return result;

}


