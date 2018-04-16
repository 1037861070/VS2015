#include "stdafx.h"
#include "GameControl.h"

CGameControl::CGameControl()
{
}


CGameControl::~CGameControl()
{
}

//��ʼ����̬��Ա����
int CGameControl::s_nRows = 10;
int CGameControl::s_nCols = 16;
int CGameControl::s_nPicNum = 20;

// ��ʼ��Ϸ
void CGameControl::StartGame()
{
	m_pGameMap =  m_GameLogic.InitMap();
	
}


// �õ�ĳһ��Ԫ��
int CGameControl::GetElement(int nRow, int nCol)
{
	return m_pGameMap[nRow][nCol];
}


// ���õ�һ����
void CGameControl::SetFirstPoint(int nRow, int nCol)
{
	//m_svSelFst = { nRow, nCol, BLANK };
	m_svSelFst.row = nRow;
	m_svSelFst.col = nCol;
	m_svSelFst.picNum = BLANK;
}


// ���õڶ�����
void CGameControl::SetSecPoint(int nRow, int nCol)
{
	//m_svSelSec = { nRow, nCol, BLANK };
	m_svSelSec.row = nRow;
	m_svSelSec.col = nCol;
	m_svSelSec.picNum = BLANK;
}


// �����жϣ�·���ݶ�Ϊ�������㣬�����ڶԸú��������޶���
bool CGameControl::Link(Vertex avPath[4], int & nVexnum)
{
	//�ж��Ƿ�ͬһ��ͼƬ
	if (m_svSelFst.row == m_svSelSec.row && m_svSelFst.col == m_svSelSec.col)
	{
		return false;
	}

	//�ж��Ƿ���ͬһ��ͼƬ
	if (m_pGameMap[m_svSelFst.row][m_svSelFst.col] != m_pGameMap[m_svSelSec.row][m_svSelSec.col])
	{
		return false;
	}

	//�ж��Ƿ���ͨ
	if (m_GameLogic.IsLink(m_pGameMap, m_svSelFst, m_svSelSec))
	{
		//����
		//m_GameLogic.Clear(m_pGameMap, m_svSelFst, m_svSelSec);

		//����·������
		nVexnum = m_GameLogic.GetVexPath(avPath);

		return true;
	}
	return false;
}


// �ж��Ƿ��ʤ
bool CGameControl::IsWin()
{
	return m_GameLogic.IsBlank(m_pGameMap);
}


// �������е�ͼԪ��
void CGameControl::RearrangeMap()
{
	m_GameLogic.RearrangeMap(m_pGameMap);
}


// ����
void CGameControl::Clear()
{
	m_GameLogic.Clear(m_pGameMap, m_svSelFst, m_svSelSec);
}
