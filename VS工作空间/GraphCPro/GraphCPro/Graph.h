#ifndef GRAPH
#define GRAPH

#include <stdlib.h>
#include <string.h>
struct Vex{
	int num;//景点编号
	char name[20];//景点名字
	char desc[50];//景点介绍
};

struct Edge {
	int vex1;//边的第一个顶点
	int vex2;//边的第二个顶点
	int weight;//两点之间的长度
};
typedef struct Path 
{
	int vexs[20];
	Path *next;
}*PathList,Path;

class Graph{

public:
	int AdjMatrix[20][20];//邻接矩阵
	Vex Vexs[20];         //顶点数组
	int VexNum;           //顶点个数
	int number;
	int sort[20];
	int aPath[20][20];
	 Graph(){}        //构造函数
	void Init();//初始化图结构
	bool InsertVex(Vex sVex);//将顶点添加到顶点数组中

	bool InsertEdge(Edge sEdge);//将边保存到邻接矩阵中

	Vex GetVex(int nVex);//查询指定顶点信息

	bool FindEdge(int nVex,Edge aEdge);//查询与指定顶点相连的边

	bool GetVexnum();//获取当前顶点个数

	void DFS(int nVex,bool bvisted[],int &nindex,int apath[]);//使用深度优先搜索遍历结果

	 void DFSTraverse(int nVex);//调用DFS函数，得到深度优先搜索遍历结果

	 int *FindShortPath(int nVexStart,int nVexEnd,Edge aPath[]);//查询最短路径

	 int FindMinTree(Edge aPath[],int P[]);//找到最小树

}; //图的一个结构对象



#endif