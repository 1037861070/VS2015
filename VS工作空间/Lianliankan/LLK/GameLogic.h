#pragma once
#include "global.h"
#define BLANK -1
class CGameLogic
{
public:
	CGameLogic(void);
	~CGameLogic(void);
	int ** InitMap(void);
	Vertex m_avPath[4];   //�����ڽ��������ж�ʱ�������Ķ���
	int m_nVexNum;//������
	void ReleaseMap(int **& pGameMap);
	//�ж��Ƿ���ͨ
	bool IsLink(int ** pGameMap, Vertex V1, Vertex V2);
	// ����
	void Clear(int ** pGameMap, Vertex V1, Vertex V2);
	//�õ�·�������ض�����
	int GetVexPath(Vertex avPath[4]);
	// �Ƿ�Ϊ��
	bool IsBlank(int ** pGameMap);
protected:
	//�жϺ����Ƿ���ͨ
	bool LinkInRow(int ** pGameMap, Vertex V1, Vertex V2);
	// �ж������Ƿ���ͨ
	bool LinkInCol(int ** pGameMap, Vertex V1, Vertex V2);
	// һ���յ���ͨ�ж�
	bool OneCornerLink(int ** pGameMap, Vertex V1, Vertex V2);
	// ֱ����ͨY��
	bool LineY(int ** pGameMap, int nRow1, int nRow2, int nCol);
	// ֱ����ͨX��
	bool LineX(int ** pGameMap, int nRow , int nCol1 , int nCol2);
	// ���һ��·������
	void PushVertex(Vertex V);
	// ȡ��һ������
	void PopVertex(void);
	// ���ջ
	void ClearStack(void);
	// ����ֱ�������ж�
	bool TwoCornerLink(int ** pGameMap, Vertex V1, Vertex V2);
	
};

