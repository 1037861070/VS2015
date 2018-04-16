#include "GameLogic.h"

#pragma once
class CGameControl
{
private:
	int ** m_pGameMap;//游戏地图数组指针
	CGameLogic m_GameLogic;//游戏逻辑操作对象、
	Vertex m_svSelFst; //选中的第一个点
	Vertex m_svSelSec; //选中的第二个点
public:
	static int s_nRows;//游戏行数
	static int s_nCols;//游戏列数
	static int s_nPicNum;//图片数
public:
	CGameControl();
	~CGameControl();
	void StartGame();// 开始游戏	 
	int GetElement(int nRow, int nCol);// 得到某一个元素									 
	void SetFirstPoint(int nRow, int nCol);  // 设置第一个点
	void SetSecPoint(int nRow, int nCol);// 设置第二个点
	bool Link(Vertex avPath[4], int & nVexnum);// 消子判断（路径暂定为两个顶点，后面在对该函数进行修订）							  
	bool IsWin(); // 判断是否获胜		 
	void RearrangeMap(); // 重新排列地图元素
						 // 消子
	void Clear();
};

