#pragma once
#include "afxwin.h"
#include "GameControl.h"



// CGameDlg 对话框

class CGameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameDlg)

public:
	CGameDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGameDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAME_DIDLOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void InitElement();//初始化元素图片与DC
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();//窗口初始化函数
	afx_msg void OnPaint();//WM_PAINT函数
	afx_msg void OnClickedBtnStart();//开始按钮
	void UpdataWindow();//更新界面
	void InitBackground();//初始化窗口背景
	void UpdataMap();	// 更新游戏地图
	int flag;//模式标志
private:
	HICON m_hIcon;//图标
	CDC m_bg;
	CDC m_dcMem;//内存DC
	CDC m_dcBG;//背景DC
	CDC m_dcElement;//元素内存DC
	CDC m_dcMask;//掩码内存DC
	CPoint m_ptGameTop;//游戏区起始点（游戏第一张图片的顶点坐标，坐标相对于窗口客户区）
	CPoint m_ptFirstPoint;
	CSize m_sizeElem;//元素图片大小
	CRect m_rtGameRect;//游戏区域大小（该区域为游戏更新区域大小，考虑到后面画的线，可能会超出图片区域一定范围）
	CGameControl m_GameC;//游戏控制类
	CProgressCtrl *timeProgress;
	bool m_bFirstPoint; //标志位，标识是否是第一个点，true表示是第一次点击，false表示是第二次点击。
	bool m_bPlaying;//游戏状态标识
	bool m_bPause;
	Vertex avPath[4];
	int nVexnum;
	int timeLeft;
	Vertex m_tipVx1;		//连线提示点
	Vertex m_tipVx2;
	int lastTime;  //上次消子时间
public:
	afx_msg void OnClose();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	void DrawTipFrame(int nRow, int nCol);// 绘制矩形提示框
	void DrawTipLine(Vertex asvPath[4], int nVexnum);//绘制连线
	void UpdataMapGame(Vertex V1, Vertex V2);// 游戏中更新地图	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClickedBtnPause();
	afx_msg void OnClickedBtnBackmain();
	// 清空地图
	void ClearMap();
	afx_msg void OnClickedBtnReareange();
	// 连线提示
	bool LinkTip();
};