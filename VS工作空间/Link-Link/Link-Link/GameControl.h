#include "GameLogic.h"

#pragma once
class CGameControl
{
private:
	int ** m_pGameMap;//��Ϸ��ͼ����ָ��
	CGameLogic m_GameLogic;//��Ϸ�߼���������
	Vertex m_svSelFst; //ѡ�еĵ�һ����
	Vertex m_svSelSec; //ѡ�еĵڶ�����
public:
	static int s_nRows;//��Ϸ����
	static int s_nCols;//��Ϸ����
	static int s_nPicNum;//ͼƬ��
public:
	CGameControl();
	~CGameControl();
	void StartGame();// ��ʼ��Ϸ	 
	int GetElement(int nRow, int nCol);// �õ�ĳһ��Ԫ��									 
	void SetFirstPoint(int nRow, int nCol);  // ���õ�һ����
	void SetSecPoint(int nRow, int nCol);// ���õڶ�����
	bool Link(Vertex avPath[4], int & nVexnum);// �����жϣ�·���ݶ�Ϊ�������㣬�����ڶԸú��������޶���							  
	bool IsWin(); // �ж��Ƿ��ʤ		 
	void RearrangeMap(); // �������е�ͼԪ��
						 // ����
	void Clear();
};

