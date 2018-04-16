#pragma once
#include "GameLogic.h"
#include "global.h"
class CGameControl
{
public:
	CGameControl(void);
	~CGameControl(void);
	int **m_pGameMap;//��Ϸ��ͼ����ָ��
	CGameLogic m_GameLogic;//��Ϸ�߼���������
	static int s_nRows;//��Ϸ����
	static int s_nCols;//��Ϸ����
	static int s_nPicNum;//ͼƬ��
	void StartGame(void);      //��ʼ��Ϸ
	int GetElement(int nRow, int nCol);//�õ�һ��Ԫ��
	Vertex m_svSelFst;//ѡ�е�һ����
	Vertex n_svSelSec;//ѡ�еڶ�����
private:
	//int **pGameMap;
public:
	// ���õ�һ����
	void SetFistPoint(int nRow, int nCol);
	// ���õڶ�����
	void SetSecPoint(int nRow, int nCol);
	// �Ƿ�ʤ��
	bool Link(Vertex avPath[4], int & nVexnum);
	bool IsWin(void);
	// ��������Ƿ�Ϊ��
};

