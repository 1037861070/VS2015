#include "stdafx.h"
#include "GameControl.h"

CGameControl::CGameControl()
{
}


CGameControl::~CGameControl()
{
}

//初始化静态成员变量
int CGameControl::s_nRows = 10;
int CGameControl::s_nCols = 16;
int CGameControl::s_nPicNum = 20;

// 开始游戏
void CGameControl::StartGame()
{
	m_pGameMap =  m_GameLogic.InitMap();
	
}


// 得到某一个元素
int CGameControl::GetElement(int nRow, int nCol)
{
	return m_pGameMap[nRow][nCol];
}


// 设置第一个点
void CGameControl::SetFirstPoint(int nRow, int nCol)
{
	//m_svSelFst = { nRow, nCol, BLANK };
	m_svSelFst.row = nRow;
	m_svSelFst.col = nCol;
	m_svSelFst.picNum = BLANK;
}


// 设置第二个点
void CGameControl::SetSecPoint(int nRow, int nCol)
{
	//m_svSelSec = { nRow, nCol, BLANK };
	m_svSelSec.row = nRow;
	m_svSelSec.col = nCol;
	m_svSelSec.picNum = BLANK;
}


// 消子判断（路径暂定为两个顶点，后面在对该函数进行修订）
bool CGameControl::Link(Vertex avPath[4], int & nVexnum)
{
	//判断是否同一张图片
	if (m_svSelFst.row == m_svSelSec.row && m_svSelFst.col == m_svSelSec.col)
	{
		return false;
	}

	//判断是否是同一种图片
	if (m_pGameMap[m_svSelFst.row][m_svSelFst.col] != m_pGameMap[m_svSelSec.row][m_svSelSec.col])
	{
		return false;
	}

	//判断是否连通
	if (m_GameLogic.IsLink(m_pGameMap, m_svSelFst, m_svSelSec))
	{
		//消子
		//m_GameLogic.Clear(m_pGameMap, m_svSelFst, m_svSelSec);

		//返回路径顶点
		nVexnum = m_GameLogic.GetVexPath(avPath);

		return true;
	}
	return false;
}


// 判断是否获胜
bool CGameControl::IsWin()
{
	return m_GameLogic.IsBlank(m_pGameMap);
}


// 重新排列地图元素
void CGameControl::RearrangeMap()
{
	m_GameLogic.RearrangeMap(m_pGameMap);
}


// 消子
void CGameControl::Clear()
{
	m_GameLogic.Clear(m_pGameMap, m_svSelFst, m_svSelSec);
}
