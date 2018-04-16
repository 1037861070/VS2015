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

//��ʼ����Ϸ��ͼ
int ** CGameLogic::InitMap()
{
	//��ȡ��ͼ��С�ͻ�ɫ
	int nRows = CGameControl::s_nRows;//��Ϸ����
	int nCols = CGameControl::s_nCols;//��Ϸ����
	int nPicNum = CGameControl::s_nPicNum;//ͼƬ��

	//�����ڴ�����
	int ** pGameMap = new int *[nRows];
	if (NULL == pGameMap)
	{
		throw new CGameException("�ڴ�����쳣��\n");
	}
	else
	{
		for (int i = 0; i < nRows; i++)
		{
			pGameMap[i] = new int[nCols];
			if (NULL == pGameMap)
			{
				throw new CGameException("�ڴ�����쳣��\n");
			}
			memset(pGameMap[i], NULL, sizeof(int)* nCols);
		}
	}

	//���ݻ�ɫ��������ÿ�ֻ�ɫͼƬ��ƽ�����������θ����鸳ֵ
	//���ٻ�ɫ
	if ((nRows*nCols) % (nPicNum * 2) != 0)
	{
		ReleaseMap(pGameMap);
		throw new CGameException("��Ϸ��ɫ����Ϸ��ͼ��С��ƥ�䣡\n");
	}
	int nRepeatNumber = nRows * nCols / nPicNum;
	int nCount = 0;
	for (int i = 0; i < nPicNum; i++)
	{
		//�ظ���
		for (int j = 0; j < nRepeatNumber; j++)
		{
			pGameMap[nCount / nCols][nCount % nCols] = i;
			nCount++;
		}
	}

	//�漴�ҵ�����λ�õ�ͼƬ�����н���
	//��������
	srand((int)time(NULL));
	//������⽻����������
	int nVertexNum = nRows * nCols;
	for (int i = 0; i < nVertexNum; i++)
	{
		//����õ���������
		int nIndex1 = rand() % nVertexNum;
		int nIndex2 = rand() % nVertexNum;

		//����������ֵ
		int nTmp = pGameMap[nIndex1 / nCols][nIndex1 % nCols];
		pGameMap[nIndex1 / nCols][nIndex1 % nCols] = pGameMap[nIndex2 / nCols][nIndex2 % nCols];
		pGameMap[nIndex2 / nCols][nIndex2 % nCols] = nTmp;
	}

	return pGameMap;
}


// �ͷŵ�ͼ
void CGameLogic::ReleaseMap(int ** & pGameMap)
{
	for (int i = 0; i < CGameControl::s_nRows; i++)
	{
		delete[]pGameMap[i];
	}
	delete[]pGameMap;
}


// �ж��Ƿ���ͨ
bool CGameLogic::IsLink(int ** pGameMap, Vertex V1, Vertex V2)
{
	ClearStack();
	PushVertex(V1);

	//Xֱ����ʽ
	if (V1.row == V2.row) 
	{
		if(LinkInRow(pGameMap, V1, V2))
		{
			PushVertex(V2);
			return true;
		}
	}

	//Yֱ����ʽ
	if (V1.col == V2.col) 
	{
		if (LinkInCol(pGameMap, V1, V2))
		{
			PushVertex(V2);
			return true;
		}
	}
	//����ֱ������
	if (OneCornerLink(pGameMap, V1, V2))
	{
		PushVertex(V2);
		return true;
	}
	//����ֱ������
	if (TwoCornerLink(pGameMap, V1, V2))
	{
		PushVertex(V2);
		return true;
	}

	return false;
}


// ����
void CGameLogic::Clear(int ** pGameMap, Vertex V1, Vertex V2)
{
	pGameMap[V1.row][V1.col] = BLANK;
	pGameMap[V2.row][V2.col] = BLANK;
}


// �õ�·�������ص��Ƕ�����
int CGameLogic::GetVexPath(Vertex avPath[4])
{
	for (int i = 0; i < m_nVexNum; i++)
	{
		avPath[i] = m_avPath[i];
	}

	return m_nVexNum;
}


// �жϺ����Ƿ���ͨ
bool CGameLogic::LinkInRow(int ** pGameMap, Vertex V1, Vertex V2)
{
	int nCol1 = V1.col;
	int nCol2 = V2.col;
	int nRow = V1.row;
	//��֤nCol1��ֵС��nCol2
	if (nCol1 > nCol2)
	{
		//���ݽ���
		int nTemp = nCol1;
		nCol1 = nCol2;
		nCol2 = nTemp;
	}

	//ֱͨ
	for (int i = nCol1 + 1; i <= nCol2; i++) 
	{
		if (i == nCol2) return true;
		if (pGameMap[nRow][i] != BLANK)	break;
	}
	return false;
}


// �ж������Ƿ���ͨ
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

	//ֱͨ
	for (int i = nRow1 + 1; i <= nRow2; i++) 
	{
		if (i == nRow2)	return true;
		if (pGameMap[i][nCol] != BLANK)	break;
	}
	return false;
}


// һ���յ���ͨ�ж�
bool CGameLogic::OneCornerLink(int ** pGameMap, Vertex V1, Vertex V2)
{
	//ֱ���ܹ����ӣ���ô����һ������������к����ཻ�ĵ㣬ֻ����������Ϊ�գ����п���ʵ������ֱ������

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


// ֱ����ͨY��
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


// ֱ����ͨX��
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


// ���һ������
void CGameLogic::PushVertex(Vertex V)
{
	m_avPath[m_nVexNum++] = V;
}


// ȡ��һ������
void CGameLogic::PopVertex()
{
	m_nVexNum--;
}


// ���ջ
void CGameLogic::ClearStack()
{
	m_nVexNum = 0;
}


// ����ֱ�������ж�
bool CGameLogic::TwoCornerLink(int ** pGameMap, Vertex V1, Vertex V2)
{
	//
	for (int nCol = 0; nCol < CGameControl::s_nCols; nCol++)
	{
		//�ҵ�һ����Y��ƽ�е���ͨ�߶�
		if (pGameMap[V1.row][nCol] == BLANK && pGameMap[V2.row][nCol] == BLANK)
		{
			if (LineY(pGameMap, V1.row, V2.row, nCol))
			{
				if (LineX(pGameMap, V1.row, V1.col, nCol) && LineX(pGameMap, V2.row, V2.col, nCol))
				{
					//����ڵ�
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
		//�ҵ�һ����X��ƽ�е���ͨ�߶�
		if (pGameMap[nRow][V1.col] == BLANK && pGameMap[nRow][V2.col] == BLANK)
		{
			if (LineX(pGameMap, nRow, V1.col, V2.col))
			{
				if (LineY(pGameMap, nRow, V1.row, V1.col) && LineY(pGameMap, nRow, V2.row, V2.col))
				{
					//����ڵ�
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


// �ж�ͼ�ж����Ƿ�ȫΪ��
bool CGameLogic::IsBlank(int ** pGameMap)
{
	for (int i = 0; i < CGameControl::s_nRows; i++)
		for (int j = 0; j < CGameControl::s_nCols; j++)
		{
			if (pGameMap[i][j] != BLANK)	return false;
		}
	return true;
}

// �жϸõ�����߽��Ƿ�Ϊ��
bool CGameLogic::LineLeft(int ** pGameMap, Vertex V)
{
	if (LineX(pGameMap, V.row, -1, V.col))
	{
		return true;
	}
	return false;
}


// �жϸõ����ұ߽��Ƿ�Ϊ��
bool CGameLogic::LineRight(int ** pGameMap, Vertex V)
{
	if (LineX(pGameMap, V.row, V.col, CGameControl::s_nCols))
	{
		return true;
	}
	return false;
}


// �жϸõ����ϱ߽��Ƿ�Ϊ��
bool CGameLogic::LineTop(int ** pGameMap, Vertex V)
{
	if (LineY(pGameMap, -1, V.row, V.col))
	{
		return true;
	}
	return false;
}


// �жϸõ����±߽��Ƿ�Ϊ��
bool CGameLogic::LineBottom(int ** pGameMap, Vertex V)
{
	if (LineY(pGameMap, V.row, CGameControl::s_nRows, V.col))
	{
		return true;
	}
	return false;
}


// �������е�ͼԪ��
void CGameLogic::RearrangeMap(int ** pGameMap)
{
	//��ȡ��ͼ��С�ͻ�ɫ
	int nRows = CGameControl::s_nRows;//��Ϸ����
	int nCols = CGameControl::s_nCols;//��Ϸ����
	int nPicNum = CGameControl::s_nPicNum;//ͼƬ��

	//��������
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
