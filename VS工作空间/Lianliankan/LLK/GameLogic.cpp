#include "StdAfx.h"
#include "GameLogic.h"

#include "GameControl.h"
#include "GameException.h"
CGameLogic::CGameLogic(void)
{
	m_nVexNum=0;
	
}


CGameLogic::~CGameLogic(void)
{
}

//初始化地图
int ** CGameLogic::InitMap(void)
{
	//获取地图大小和花色
	int nRows=CGameControl::s_nRows;
	int nCols=CGameControl::s_nCols;
	int nPicNum=CGameControl::s_nPicNum;
	//开辟内存区域
	int **pGameMap=new int *[nRows];
	if (NULL==pGameMap)
	{
		throw new CGameException();
	}
	else
	{
		for (int i=0;i<nRows;i++)
		{
			pGameMap[i]=new int[nCols];
			if (NULL==pGameMap)
			{
				throw new CGameException();
			}
             memset(pGameMap[i],NULL,sizeof(int)*nCols);}}
	if ((nRows*nCols)%(nPicNum*2)!=0)
	{
		ReleaseMap(pGameMap);
		throw new CGameException();
	}
	int nRepeatNum=nRows*nCols/nPicNum;
	int nCount=0;
	for (int i=0;i<nPicNum;i++)
	{
		//重复数
		for(int j=0;j<nRepeatNum;j++)
		{
			pGameMap[nCount/nCols][nCount%nCols]=i;
			nCount++;
		}
	}
	//设置种子
	srand((int)time(NULL));
	//随机任意交换两个数字
	int nVertexNum=nRows*nCols;
	for (int i=0;i<nVertexNum;i++)
	{
		//随机得到两个坐标
		int nIndex1=rand()%nVertexNum;
		int nIndex2=rand()%nVertexNum;
		//交换两个数值
		int nTmp=pGameMap[nIndex1/nCols][nIndex1%nCols];
		pGameMap[nIndex1/nCols][nIndex1%nCols]=pGameMap[nIndex2/nCols][nIndex2%nCols];
		pGameMap[nIndex2/nCols][nIndex2%nCols]=nTmp;
	}
	return pGameMap;
}





void CGameLogic::ReleaseMap(int **& pGameMap)
{
	for (int i=0;i<CGameControl::s_nRows;i++)
	{
		delete[]pGameMap[i];
	}
	delete[]pGameMap;
}


bool CGameLogic::IsLink(int ** pGameMap, Vertex V1, Vertex V2)
{
	ClearStack();
	bool flag = false;
	PushVertex(V1);
	if (V1.row==V2.row)
	{
		flag=LinkInRow(pGameMap, V1, V2);
	}
	else if (V1.col==V2.col)
	{
		flag=LinkInCol(pGameMap, V1, V2);
	}

	if (flag==true)
	{
		PushVertex(V2);
		return true;
	}
	else
	{
		if (OneCornerLink(pGameMap, V1, V2) || TwoCornerLink(pGameMap, V1, V2))
		{
			PushVertex(V2);
			return true;
		}
	}
	return false;
}


// 消子
void CGameLogic::Clear(int ** pGameMap, Vertex V1, Vertex V2)
{
	pGameMap[V1.row][V1.col] = BLANK;
	pGameMap[V2.row][V2.col] = BLANK;
}


int CGameLogic::GetVexPath(Vertex avPath[4])
{
	for (int i=0;i<m_nVexNum;i++)
	{
		avPath[i]=m_avPath[i];
	}
	return m_nVexNum;
}


bool CGameLogic::LinkInRow(int ** pGameMap, Vertex V1, Vertex V2)  //一条直线消子
{
	int nCol1=V1.col;
	int nCol2=V2.col;
	int nRow=V1.row;
	//保证nCol的值小于nCol2
	if (nCol1>nCol2)
	{
		//数据交换
		int nTemp=nCol1;
		nCol1=nCol2;
		nCol2=nTemp;
	}
	//直通
	for (int i=nCol1+1;i<=nCol2;i++)
	{
		if(i==nCol2)
		{return true;}
		if(pGameMap[nRow][i]!=BLANK)
		{break;}
	}
	return false;
}


// 判断纵向是否联通
bool CGameLogic::LinkInCol(int ** pGameMap, Vertex V1, Vertex V2)
{
	int nRow1=V1.row;
	int nRow2=V2.row;
	int nCol=V1.col;
	if (nRow1>nRow2)
	{
		int nTemp=nRow1;
		nRow1=nRow2;
		nRow2=nTemp;
	}
	//直通
	for (int i=nRow1+1;i<=nRow2;i++)
	{
		if(i==nRow2)
		{return true;}
		if(pGameMap[i][nCol]!=BLANK)
		{break;}
	}
	return false;
}


// 一个拐点连通判断
bool CGameLogic::OneCornerLink(int ** pGameMap, Vertex V1, Vertex V2)
{
	if (pGameMap[V1.row][V2.col]==BLANK)// 
	{
		if (LineY(pGameMap,V1.row,V2.row,V2.col)&&LineX(pGameMap,V1.row,V1.col,V2.col))
		{
			Vertex V={V1.row,V2.col,BLANK};
			PushVertex(V);
			return true;}
	}
	if (pGameMap[V2.row][V1.col]==BLANK)
	{if (LineY(pGameMap,V1.row,V2.row,V1.col)&&LineX(pGameMap,V2.row,V1.col,V2.col))//是否y轴直连
		{Vertex v={V2.row,V1.col,BLANK};
			PushVertex(v);
			return true;
		}
	}
	return false;
}


// 直线连通Y轴
bool CGameLogic::LineY(int ** pGameMap, int nRow1, int nRow2, int nCol)
{
	if (nRow1 > nRow2)
	{
		int temp = nRow1;
		nRow1 = nRow2;
		nRow2 = temp;
	}
	for (int i = nRow1 + 1; i <= nRow2; i++)
	{
		if (i == nRow2)
		{
			return true;
		}
		if (pGameMap[i][nCol] != BLANK)
		{
			break;
		}
	}
	return false;
}


// 直线连通X轴
bool CGameLogic::LineX(int ** pGameMap, int nRow , int nCol1 , int nCol2)
{
	if (nCol1 > nCol2)
	{
		int temp = nCol1;
		nCol1 = nCol2;
		nCol2 = temp;
	}
	for (int i = nCol1 + 1; i <= nCol2; i++)
	{
		if (i == nCol2)
		{
			return true;
		}
		if (pGameMap[nRow][i] != BLANK)
		{
			break;
		}
	}
	return false;
}




// 添加一个路径顶点
void CGameLogic::PushVertex(Vertex V)
{
	m_avPath[m_nVexNum++] = V;
}


// 取出一个顶点
void CGameLogic::PopVertex(void)
{
	m_nVexNum--;
}


// 清楚栈
void CGameLogic::ClearStack(void)
{
	m_nVexNum = 0;
}


// 三条直线消子判断
bool CGameLogic::TwoCornerLink(int ** pGameMap, Vertex V1, Vertex V2)
{for(int nCol=0;nCol<CGameControl::s_nCols;nCol++)
	{//找到一条与Y轴平行的联通线段
		if (pGameMap[V1.row][nCol]==BLANK&&pGameMap[V2.row][nCol]==BLANK)
		{if (LineY(pGameMap,V1.row,V2.row,nCol))
			{if (LineX(pGameMap,V1.row,V1.col,nCol)&&LineX(pGameMap,V2.row,V2.col,nCol))
				{//保存节点
					Vertex vx1={V1.row,nCol,BLANK};
					Vertex vx2={V2.row,nCol,BLANK};
					PushVertex(vx1);
					PushVertex(vx2);
					return true;}}}}
	for (int nRow=0;nRow<CGameControl::s_nRows;nRow++)
	{
		//找到一条与X轴平行的联通线段
		if (pGameMap[nRow][V1.col]==BLANK&&pGameMap[nRow][V2.col]==BLANK)
		{if (LineX(pGameMap,nRow,V1.col,V2.col))
			{if (LineY(pGameMap,nRow,V1.row,V1.col)&&LineY(pGameMap,nRow,V2.row,V2.col))
				{//保存节点
					Vertex vx1={nRow,V1.col,BLANK};
					Vertex vx2={nRow,V2.col,BLANK};
					PushVertex(vx1);
					PushVertex(vx2);
					return true;}}}}
	return false;
}


// 是否为空
bool CGameLogic::IsBlank(int ** pGameMap)
{
	for (int i = 0; i < CGameControl::s_nRows;i++)
	{
		for (int j = 0; j < CGameControl::s_nCols; j++)
		{
			if (pGameMap[i][j]!=BLANK)
			{
				return false;
			}
		}
	}
	return true;
}
