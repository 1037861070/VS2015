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

//��ʼ����ͼ
int ** CGameLogic::InitMap(void)
{
	//��ȡ��ͼ��С�ͻ�ɫ
	int nRows=CGameControl::s_nRows;
	int nCols=CGameControl::s_nCols;
	int nPicNum=CGameControl::s_nPicNum;
	//�����ڴ�����
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
		//�ظ���
		for(int j=0;j<nRepeatNum;j++)
		{
			pGameMap[nCount/nCols][nCount%nCols]=i;
			nCount++;
		}
	}
	//��������
	srand((int)time(NULL));
	//������⽻����������
	int nVertexNum=nRows*nCols;
	for (int i=0;i<nVertexNum;i++)
	{
		//����õ���������
		int nIndex1=rand()%nVertexNum;
		int nIndex2=rand()%nVertexNum;
		//����������ֵ
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


// ����
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


bool CGameLogic::LinkInRow(int ** pGameMap, Vertex V1, Vertex V2)  //һ��ֱ������
{
	int nCol1=V1.col;
	int nCol2=V2.col;
	int nRow=V1.row;
	//��֤nCol��ֵС��nCol2
	if (nCol1>nCol2)
	{
		//���ݽ���
		int nTemp=nCol1;
		nCol1=nCol2;
		nCol2=nTemp;
	}
	//ֱͨ
	for (int i=nCol1+1;i<=nCol2;i++)
	{
		if(i==nCol2)
		{return true;}
		if(pGameMap[nRow][i]!=BLANK)
		{break;}
	}
	return false;
}


// �ж������Ƿ���ͨ
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
	//ֱͨ
	for (int i=nRow1+1;i<=nRow2;i++)
	{
		if(i==nRow2)
		{return true;}
		if(pGameMap[i][nCol]!=BLANK)
		{break;}
	}
	return false;
}


// һ���յ���ͨ�ж�
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
	{if (LineY(pGameMap,V1.row,V2.row,V1.col)&&LineX(pGameMap,V2.row,V1.col,V2.col))//�Ƿ�y��ֱ��
		{Vertex v={V2.row,V1.col,BLANK};
			PushVertex(v);
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


// ֱ����ͨX��
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




// ���һ��·������
void CGameLogic::PushVertex(Vertex V)
{
	m_avPath[m_nVexNum++] = V;
}


// ȡ��һ������
void CGameLogic::PopVertex(void)
{
	m_nVexNum--;
}


// ���ջ
void CGameLogic::ClearStack(void)
{
	m_nVexNum = 0;
}


// ����ֱ�������ж�
bool CGameLogic::TwoCornerLink(int ** pGameMap, Vertex V1, Vertex V2)
{for(int nCol=0;nCol<CGameControl::s_nCols;nCol++)
	{//�ҵ�һ����Y��ƽ�е���ͨ�߶�
		if (pGameMap[V1.row][nCol]==BLANK&&pGameMap[V2.row][nCol]==BLANK)
		{if (LineY(pGameMap,V1.row,V2.row,nCol))
			{if (LineX(pGameMap,V1.row,V1.col,nCol)&&LineX(pGameMap,V2.row,V2.col,nCol))
				{//����ڵ�
					Vertex vx1={V1.row,nCol,BLANK};
					Vertex vx2={V2.row,nCol,BLANK};
					PushVertex(vx1);
					PushVertex(vx2);
					return true;}}}}
	for (int nRow=0;nRow<CGameControl::s_nRows;nRow++)
	{
		//�ҵ�һ����X��ƽ�е���ͨ�߶�
		if (pGameMap[nRow][V1.col]==BLANK&&pGameMap[nRow][V2.col]==BLANK)
		{if (LineX(pGameMap,nRow,V1.col,V2.col))
			{if (LineY(pGameMap,nRow,V1.row,V1.col)&&LineY(pGameMap,nRow,V2.row,V2.col))
				{//����ڵ�
					Vertex vx1={nRow,V1.col,BLANK};
					Vertex vx2={nRow,V2.col,BLANK};
					PushVertex(vx1);
					PushVertex(vx2);
					return true;}}}}
	return false;
}


// �Ƿ�Ϊ��
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
