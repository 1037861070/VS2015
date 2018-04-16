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


// ���õ�һ����
void CGameControl::SetFistPoint(int nRow, int nCol)
{
	m_svSelFst.row=nRow;
	m_svSelFst.col=nCol;
}


// ���õڶ�����
void CGameControl::SetSecPoint(int nRow, int nCol)
{
	n_svSelSec.row=nRow;
	n_svSelSec.col=nCol;
}


bool CGameControl::Link(Vertex avPath[4], int & nVexnum)   // �����жϣ�·���ݶ�Ϊ��������
{   //�ж��Ƿ�Ϊͬһ��ͼƬ
	if (m_svSelFst.row == n_svSelSec.row&&m_svSelFst.col == n_svSelSec.col)  
	{
		return false;
	}
	//�ж�ͼƬ�Ƿ���ͬ
	if (m_pGameMap[m_svSelFst.row][m_svSelFst.col] != m_pGameMap[n_svSelSec.row][n_svSelSec.col])
	{return false;}
	//�ж���Ϸ�����Ƿ�Ϊ��
	if (m_pGameMap[m_svSelFst.row][m_svSelFst.col]==BLANK||m_pGameMap[n_svSelSec.row][n_svSelSec.col]==BLANK)
	{
		return false;
	}
	//�ж�ͼƬ�Ƿ���ͨ
	if (m_GameLogic.IsLink(m_pGameMap, m_svSelFst, n_svSelSec))
	{
		m_GameLogic.Clear(m_pGameMap, m_svSelFst, n_svSelSec);    //����
		nVexnum = m_GameLogic.GetVexPath(avPath);      //����·������
		return true;
	}
	return false;
}


// �Ƿ�ʤ��
bool CGameControl::IsWin(void)
{
	if (m_GameLogic.IsBlank(m_pGameMap))
	{
		return true;
	}
	return false;
}


// ��������Ƿ�Ϊ��
