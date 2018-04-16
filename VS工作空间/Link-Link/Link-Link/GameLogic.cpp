#include "stdafx.h"
#include "GameLogic.h"
#include "GameControl.h"
#include "GameException.h"


CGameLogic::CGameLogic()
{
}


CGameLogic::~CGameLogic()
{
}

//初始化游戏地图
int ** CGameLogic::InitMap()
{
	//获取地图大小和花色
	int nRows = CGameControl::s_nRows;//游戏行数
	int nCols = CGameControl::s_nCols;//游戏列数
	int nPicNum = CGameControl::s_nPicNum;//图片数

	//开辟内存区域
	int ** pGameMap = new int *[nRows];
	if (NULL == pGameMap)
	{
		throw new CGameException("内存操作异常！\n");
	}
	else
	{
		for (int i = 0; i < nRows; i++)
		{
			pGameMap[i] = new int[nCols];
			if (NULL == pGameMap)
			{
				throw new CGameException("内存操作异常！\n");
			}
			memset(pGameMap[i], NULL, sizeof(int)* nCols);
		}
	}

	//根据花色种类计算出每种花色图片的平均个数，依次给数组赋值
	//多少花色
	if ((nRows*nCols) % (nPicNum * 2) != 0)
	{
		ReleaseMap(pGameMap);
		throw new CGameException("游戏花色与游戏地图大小不匹配！\n");
	}
	int nRepeatNumber = nRows * nCols / nPicNum;
	int nCount = 0;
	for (int i = 0; i < nPicNum; i++)
	{
		//重复数
		for (int j = 0; j < nRepeatNumber; j++)
		{
			pGameMap[nCount / nCols][nCount % nCols] = i;
			nCount++;
		}
	}

	//随即找到两个位置的图片，进行交换
	//设置种子
	srand((int)time(NULL));
	//随机任意交换两个数字
	int nVertexNum = nRows * nCols;
	for (int i = 0; i < nVertexNum; i++)
	{
		//随机得到两个坐标
		int nIndex1 = rand() % nVertexNum;
		int nIndex2 = rand() % nVertexNum;

		//交换两个数值
		int nTmp = pGameMap[nIndex1 / nCols][nIndex1 % nCols];
		pGameMap[nIndex1 / nCols][nIndex1 % nCols] = pGameMap[nIndex2 / nCols][nIndex2 % nCols];
		pGameMap[nIndex2 / nCols][nIndex2 % nCols] = nTmp;
	}

	return pGameMap;
}


// 释放地图
void CGameLogic::ReleaseMap(int ** & pGameMap)
{
	for (int i = 0; i < CGameControl::s_nRows; i++)
	{
		delete[]pGameMap[i];
	}
	delete[]pGameMap;
}


// 判断是否连通
bool CGameLogic::IsLink(int ** pGameMap, Vertex V1, Vertex V2)
{
	ClearStack();
	PushVertex(V1);

	//X直连方式
	if (V1.row == V2.row) 
	{
		if(LinkInRow(pGameMap, V1, V2))
		{
			PushVertex(V2);
			return true;
		}
	}

	//Y直连方式
	if (V1.col == V2.col) 
	{
		if (LinkInCol(pGameMap, V1, V2))
		{
			PushVertex(V2);
			return true;
		}
	}
	//两条直线消子
	if (OneCornerLink(pGameMap, V1, V2))
	{
		PushVertex(V2);
		return true;
	}
	//三条直线消子
	if (TwoCornerLink(pGameMap, V1, V2))
	{
		PushVertex(V2);
		return true;
	}

	return false;
}


// 消子
void CGameLogic::Clear(int ** pGameMap, Vertex V1, Vertex V2)
{
	pGameMap[V1.row][V1.col] = BLANK;
	pGameMap[V2.row][V2.col] = BLANK;
}


// 得到路径，返回的是顶点数
int CGameLogic::GetVexPath(Vertex avPath[4])
{
	for (int i = 0; i < m_nVexNum; i++)
	{
		avPath[i] = m_avPath[i];
	}

	return m_nVexNum;
}


// 判断横向是否连通
bool CGameLogic::LinkInRow(int ** pGameMap, Vertex V1, Vertex V2)
{
	int nCol1 = V1.col;
	int nCol2 = V2.col;
	int nRow = V1.row;
	//保证nCol1的值小于nCol2
	if (nCol1 > nCol2)
	{
		//数据交换
		int nTemp = nCol1;
		nCol1 = nCol2;
		nCol2 = nTemp;
	}

	//直通
	for (int i = nCol1 + 1; i <= nCol2; i++) 
	{
		if (i == nCol2) return true;
		if (pGameMap[nRow][i] != BLANK)	break;
	}
	return false;
}


// 判断纵向是否连通
bool CGameLogic::LinkInCol(int ** pGameMap, Vertex V1, Vertex V2)
{
	int nRow1 = V1.row;
	int nRow2 = V2.row;
	int nCol = V1.col;
	if (nRow1 > nRow2) {
		int nTemp = nRow1;
		nRow1 = nRow2;
		nRow2 = nTemp;
	}

	//直通
	for (int i = nRow1 + 1; i <= nRow2; i++) 
	{
		if (i == nRow2)	return true;
		if (pGameMap[i][nCol] != BLANK)	break;
	}
	return false;
}


// 一个拐点连通判断
bool CGameLogic::OneCornerLink(int ** pGameMap, Vertex V1, Vertex V2)
{
	//直角能够消子，那么顶点一定在两个点的行和列相交的点，只有这两个点为空，才有可能实现两条直线消子

	if (pGameMap[V1.row][V2.col] == BLANK) 
	{
		if (LineY(pGameMap, V1.row, V2.row, V2.col) && LineX(pGameMap, V1.row, V1.col, V2.col))
		{
			Vertex V = { V1.row, V2.col, BLANK };
			PushVertex(V);
			return true;
		}
	}
	if (pGameMap[V2.row][V1.col] == BLANK)
	{
		if (LineY(pGameMap, V1.row, V2.row, V1.col) && LineX(pGameMap, V2.row, V1.col, V2.col))
		{
			Vertex V = { V2.row, V1.col, BLANK };
			PushVertex(V);
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
		if (i == nRow2)	return true;
		if (pGameMap[i][nCol] != BLANK) break;
	}
	return false;
}


// 直线连通X轴
bool CGameLogic::LineX(int ** pGameMap, int nRow, int nCol1, int nCol2)
{
	if (nCol1 > nCol2)
	{
		int temp = nCol1;
		nCol1 = nCol2;
		nCol2 = temp;
	}
	for (int i = nCol1 + 1; i <= nCol2; i++)
	{
		if (i == nCol2)	return true;
		if (pGameMap[nRow][i] != BLANK)	break;
	}
	return false;
}


// 添加一个顶点
void CGameLogic::PushVertex(Vertex V)
{
	m_avPath[m_nVexNum++] = V;
}


// 取出一个顶点
void CGameLogic::PopVertex()
{
	m_nVexNum--;
}


// 清除栈
void CGameLogic::ClearStack()
{
	m_nVexNum = 0;
}


// 三条直线消子判断
bool CGameLogic::TwoCornerLink(int ** pGameMap, Vertex V1, Vertex V2)
{
	//
	for (int nCol = 0; nCol < CGameControl::s_nCols; nCol++)
	{
		//找到一条与Y轴平行的连通线段
		if (pGameMap[V1.row][nCol] == BLANK && pGameMap[V2.row][nCol] == BLANK)
		{
			if (LineY(pGameMap, V1.row, V2.row, nCol))
			{
				if (LineX(pGameMap, V1.row, V1.col, nCol) && LineX(pGameMap, V2.row, V2.col, nCol))
				{
					//保存节点
					Vertex Vx1 = { V1.row, nCol, BLANK };
					Vertex Vx2 = { V2.row, nCol, BLANK };
					PushVertex(Vx1);
					PushVertex(Vx2);
					return true;
				}
			}
		}
	}
	for (int nRow = 0; nRow < CGameControl::s_nRows; nRow++)
	{
		//找到一条与X轴平行的连通线段
		if (pGameMap[nRow][V1.col] == BLANK && pGameMap[nRow][V2.col] == BLANK)
		{
			if (LineX(pGameMap, nRow, V1.col, V2.col))
			{
				if (LineY(pGameMap, nRow, V1.row, V1.col) && LineY(pGameMap, nRow, V2.row, V2.col))
				{
					//保存节点
					Vertex Vx1 = { nRow, V1.col, BLANK };
					Vertex Vx2 = { nRow, V2.col, BLANK };
					PushVertex(Vx1);
					PushVertex(Vx2);
					return true;
				}
			}
		}
	}
	if (LineTop(pGameMap, V1) && LineTop(pGameMap, V2))
	{
		Vertex Vx1 = { -1, V1.col, BLANK };
		Vertex Vx2 = { -1, V2.col, BLANK };
		PushVertex(Vx1);
		PushVertex(Vx2);
		return true;
	}
	if (LineLeft(pGameMap, V1) && LineLeft(pGameMap, V2))
	{
		Vertex Vx1 = { V1.row, -1, BLANK };
		Vertex Vx2 = { V2.row, -1, BLANK };
		PushVertex(Vx1);
		PushVertex(Vx2);
		return true;
	}
	if (LineRight(pGameMap, V1) && LineRight(pGameMap, V2))
	{
		Vertex Vx1 = { V1.row, CGameControl::s_nCols, BLANK };
		Vertex Vx2 = { V2.row, CGameControl::s_nCols, BLANK };
		PushVertex(Vx1);
		PushVertex(Vx2);
		return true;
	}
	if (LineBottom(pGameMap, V1) && LineBottom(pGameMap, V2))
	{
		Vertex Vx1 = { CGameControl::s_nRows, V1.col, BLANK };
		Vertex Vx2 = { CGameControl::s_nRows, V2.col, BLANK };
		PushVertex(Vx1);
		PushVertex(Vx2);
		return true;
	}

	return false;
}


// 判断图中顶点是否全为空
bool CGameLogic::IsBlank(int ** pGameMap)
{
	for (int i = 0; i < CGameControl::s_nRows; i++)
		for (int j = 0; j < CGameControl::s_nCols; j++)
		{
			if (pGameMap[i][j] != BLANK)	return false;
		}
	return true;
}

// 判断该点至左边界是否为空
bool CGameLogic::LineLeft(int ** pGameMap, Vertex V)
{
	if (LineX(pGameMap, V.row, -1, V.col))
	{
		return true;
	}
	return false;
}


// 判断该点至右边界是否为空
bool CGameLogic::LineRight(int ** pGameMap, Vertex V)
{
	if (LineX(pGameMap, V.row, V.col, CGameControl::s_nCols))
	{
		return true;
	}
	return false;
}


// 判断该点至上边界是否为空
bool CGameLogic::LineTop(int ** pGameMap, Vertex V)
{
	if (LineY(pGameMap, -1, V.row, V.col))
	{
		return true;
	}
	return false;
}


// 判断该点至下边界是否为空
bool CGameLogic::LineBottom(int ** pGameMap, Vertex V)
{
	if (LineY(pGameMap, V.row, CGameControl::s_nRows, V.col))
	{
		return true;
	}
	return false;
}


// 重新排列地图元素
void CGameLogic::RearrangeMap(int ** pGameMap)
{
	//获取地图大小和花色
	int nRows = CGameControl::s_nRows;//游戏行数
	int nCols = CGameControl::s_nCols;//游戏列数
	int nPicNum = CGameControl::s_nPicNum;//图片数

	//设置种子
	srand((int)time(NULL));
	for (int i = 0; i <nRows; i++)
		for (int j = 0; j < nCols; j++)
		{
			if (pGameMap[i][j] != BLANK)
			{
				int nIndex1 = rand() % nRows;
				int nIndex2 = rand() % nCols;
				int temp = pGameMap[i][j];
				pGameMap[i][j] = pGameMap[nIndex1][nIndex2];
				pGameMap[nIndex1][nIndex2] = temp;
			}
		}

}
