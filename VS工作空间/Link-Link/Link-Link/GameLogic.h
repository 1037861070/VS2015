#pragma once
#include "global.h"
class CGameLogic
{
private:
	int m_nVexNum;//������
	Vertex m_avPath[4];//������������ж�ʱ�������Ķ���
protected:
	bool LinkInRow(int ** pGameMap, Vertex V1, Vertex V2);// �жϺ����Ƿ���ͨ	
	bool LinkInCol(int ** pGameMap, Vertex V1, Vertex V2);// �ж������Ƿ���ͨ	
	bool OneCornerLink(int ** pGameMap, Vertex V1, Vertex V2);// һ���յ���ͨ�ж�
	bool TwoCornerLink(int ** pGameMap, Vertex V1, Vertex V2);// ����ֱ�������ж�	
	bool LineY(int ** pGameMap, int nRow1, int nRow2, int nCol);// ֱ����ͨY��	
	bool LineX(int ** pGameMap, int nRow, int nCol1, int nCol2);// ֱ����ͨX��
	void PushVertex(Vertex V);	// ���һ������
	void PopVertex();// ȡ��һ������
	void ClearStack();// ���ջ
public:
	CGameLogic();
	~CGameLogic();
	int ** InitMap();//��ʼ����Ϸ��ͼ			
	void ReleaseMap(int ** & pGameMap); // �ͷŵ�ͼ
	bool IsLink(int ** pGameMap, Vertex V1, Vertex V2);// �ж��Ƿ���ͨ
	void Clear(int ** pGameMap, Vertex V1, Vertex V2);// ����											 
	int GetVexPath(Vertex avPath[4]); // �õ�·�������ص��Ƕ�����
	bool IsBlank(int ** pGameMap);// �ж�ͼ�ж����Ƿ�ȫΪ��
	bool LineLeft(int ** pGameMap, Vertex V);// �жϸõ�����߽��Ƿ�Ϊ��	
	bool LineRight(int ** pGameMap, Vertex V);// �жϸõ����߽��Ƿ�Ϊ��
											  // �жϸõ����ϱ߽��Ƿ�Ϊ��
	bool LineTop(int ** pGameMap, Vertex V);
	// �жϸõ����±߽��Ƿ�Ϊ��
	bool LineBottom(int ** pGameMap, Vertex V);
	// �������е�ͼԪ��
	void RearrangeMap(int ** pGameMap);
};

