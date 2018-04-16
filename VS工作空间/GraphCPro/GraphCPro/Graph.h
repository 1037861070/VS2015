#ifndef GRAPH
#define GRAPH

#include <stdlib.h>
#include <string.h>
struct Vex{
	int num;//������
	char name[20];//��������
	char desc[50];//�������
};

struct Edge {
	int vex1;//�ߵĵ�һ������
	int vex2;//�ߵĵڶ�������
	int weight;//����֮��ĳ���
};
typedef struct Path 
{
	int vexs[20];
	Path *next;
}*PathList,Path;

class Graph{

public:
	int AdjMatrix[20][20];//�ڽӾ���
	Vex Vexs[20];         //��������
	int VexNum;           //�������
	int number;
	int sort[20];
	int aPath[20][20];
	 Graph(){}        //���캯��
	void Init();//��ʼ��ͼ�ṹ
	bool InsertVex(Vex sVex);//��������ӵ�����������

	bool InsertEdge(Edge sEdge);//���߱��浽�ڽӾ�����

	Vex GetVex(int nVex);//��ѯָ��������Ϣ

	bool FindEdge(int nVex,Edge aEdge);//��ѯ��ָ�����������ı�

	bool GetVexnum();//��ȡ��ǰ�������

	void DFS(int nVex,bool bvisted[],int &nindex,int apath[]);//ʹ��������������������

	 void DFSTraverse(int nVex);//����DFS�������õ�������������������

	 int *FindShortPath(int nVexStart,int nVexEnd,Edge aPath[]);//��ѯ���·��

	 int FindMinTree(Edge aPath[],int P[]);//�ҵ���С��

}; //ͼ��һ���ṹ����



#endif