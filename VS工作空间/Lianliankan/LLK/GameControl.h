#pragma once
#include "GameLogic.h"
#include "global.h"
class CGameControl
{
public:
	CGameControl(void);
	~CGameControl(void);
	int **m_pGameMap;//游戏地图数组指针
	CGameLogic m_GameLogic;//游戏逻辑操作对象
	static int s_nRows;//游戏行数
	static int s_nCols;//游戏列数
	static int s_nPicNum;//图片数
	void StartGame(void);      //开始游戏
	int GetElement(int nRow, int nCol);//得到一个元素
	Vertex m_svSelFst;//选中第一个点
	Vertex n_svSelSec;//选中第二个点
private:
	//int **pGameMap;
public:
	// 设置第一个点
	void SetFistPoint(int nRow, int nCol);
	// 设置第二个点
	void SetSecPoint(int nRow, int nCol);
	// 是否胜利
	bool Link(Vertex avPath[4], int & nVexnum);
	bool IsWin(void);
	// 点击区域是否为空
};

