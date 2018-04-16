#pragma once
#include "global.h"
#define BLANK -1
class CGameLogic
{
public:
	CGameLogic(void);
	~CGameLogic(void);
	int ** InitMap(void);
	Vertex m_avPath[4];   //保存在进行链接判断时所经过的顶点
	int m_nVexNum;//顶点数
	void ReleaseMap(int **& pGameMap);
	//判断是否连通
	bool IsLink(int ** pGameMap, Vertex V1, Vertex V2);
	// 消子
	void Clear(int ** pGameMap, Vertex V1, Vertex V2);
	//得到路径，返回顶点数
	int GetVexPath(Vertex avPath[4]);
	// 是否为空
	bool IsBlank(int ** pGameMap);
protected:
	//判断横向是否联通
	bool LinkInRow(int ** pGameMap, Vertex V1, Vertex V2);
	// 判断纵向是否联通
	bool LinkInCol(int ** pGameMap, Vertex V1, Vertex V2);
	// 一个拐点连通判断
	bool OneCornerLink(int ** pGameMap, Vertex V1, Vertex V2);
	// 直线连通Y轴
	bool LineY(int ** pGameMap, int nRow1, int nRow2, int nCol);
	// 直线连通X轴
	bool LineX(int ** pGameMap, int nRow , int nCol1 , int nCol2);
	// 添加一个路径顶点
	void PushVertex(Vertex V);
	// 取出一个顶点
	void PopVertex(void);
	// 清楚栈
	void ClearStack(void);
	// 三条直线消子判断
	bool TwoCornerLink(int ** pGameMap, Vertex V1, Vertex V2);
	
};

