#include "StdAfx.h"
#include "GameControl.h"
#include "GameLogic.h"

CGameControl::CGameControl(void)
{
}


CGameControl::~CGameControl(void)
{
}

int CGameControl::s_nRows =10;
int CGameControl::s_nCols=16;
int CGameControl::s_nPicNum=16;

void CGameControl::StartGame(void)
{
	m_pGameMap=m_GameLogic.InitMap();
}


int CGameControl::GetElement(int nRow, int nCol)
{
	return m_pGameMap[nRow][nCol];
}


// 设置第一个点
void CGameControl::SetFistPoint(int nRow, int nCol)
{
	m_svSelFst.row=nRow;
	m_svSelFst.col=nCol;
}


// 设置第二个点
void CGameControl::SetSecPoint(int nRow, int nCol)
{
	n_svSelSec.row=nRow;
	n_svSelSec.col=nCol;
}


bool CGameControl::Link(Vertex avPath[4], int & nVexnum)   // 消子判断，路径暂定为两个顶点
{   //判断是否为同一张图片
	if (m_svSelFst.row == n_svSelSec.row&&m_svSelFst.col == n_svSelSec.col)  
	{
		return false;
	}
	//判断图片是否相同
	if (m_pGameMap[m_svSelFst.row][m_svSelFst.col] != m_pGameMap[n_svSelSec.row][n_svSelSec.col])
	{return false;}
	//判断游戏界面是否为空
	if (m_pGameMap[m_svSelFst.row][m_svSelFst.col]==BLANK||m_pGameMap[n_svSelSec.row][n_svSelSec.col]==BLANK)
	{
		return false;
	}
	//判断图片是否连通
	if (m_GameLogic.IsLink(m_pGameMap, m_svSelFst, n_svSelSec))
	{
		m_GameLogic.Clear(m_pGameMap, m_svSelFst, n_svSelSec);    //消子
		nVexnum = m_GameLogic.GetVexPath(avPath);      //返回路径顶点
		return true;
	}
	return false;
}


// 是否胜利
bool CGameControl::IsWin(void)
{
	if (m_GameLogic.IsBlank(m_pGameMap))
	{
		return true;
	}
	return false;
}


// 点击区域是否为空
