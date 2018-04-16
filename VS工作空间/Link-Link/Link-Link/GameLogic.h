#pragma once
#include "global.h"
class CGameLogic
{
private:
	int m_nVexNum;//顶点数
	Vertex m_avPath[4];//保存进行连接判断时所经过的顶点
protected:
	bool LinkInRow(int ** pGameMap, Vertex V1, Vertex V2);// 判断横向是否连通	
	bool LinkInCol(int ** pGameMap, Vertex V1, Vertex V2);// 判断纵向是否连通	
	bool OneCornerLink(int ** pGameMap, Vertex V1, Vertex V2);// 一个拐点连通判断
	bool TwoCornerLink(int ** pGameMap, Vertex V1, Vertex V2);// 三条直线消子判断	
	bool LineY(int ** pGameMap, int nRow1, int nRow2, int nCol);// 直线连通Y轴	
	bool LineX(int ** pGameMap, int nRow, int nCol1, int nCol2);// 直线连通X轴
	void PushVertex(Vertex V);	// 添加一个顶点
	void PopVertex();// 取出一个顶点
	void ClearStack();// 清除栈
public:
	CGameLogic();
	~CGameLogic();
	int ** InitMap();//初始化游戏地图			
	void ReleaseMap(int ** & pGameMap); // 释放地图
	bool IsLink(int ** pGameMap, Vertex V1, Vertex V2);// 判断是否连通
	void Clear(int ** pGameMap, Vertex V1, Vertex V2);// 消子											 
	int GetVexPath(Vertex avPath[4]); // 得到路径，返回的是顶点数
	bool IsBlank(int ** pGameMap);// 判断图中顶点是否全为空
	bool LineLeft(int ** pGameMap, Vertex V);// 判断该点至左边界是否为空	
	bool LineRight(int ** pGameMap, Vertex V);// 判断该点至边界是否为空
											  // 判断该点至上边界是否为空
	bool LineTop(int ** pGameMap, Vertex V);
	// 判断该点至下边界是否为空
	bool LineBottom(int ** pGameMap, Vertex V);
	// 重新排列地图元素
	void RearrangeMap(int ** pGameMap);
};

