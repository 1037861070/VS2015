#pragma once
#include <mmsystem.h>
#pragma comment( lib, "Winmm.lib" )

// CGameDlg 对话框
#include "GameControl.h"

#include <string.h>

class CGameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameDlg)

public:
	CGameDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGameDlg();
    static bool isok;
	Vertex Vfir, Vsec;
	
// 对话框数据
	enum { IDD = IDD_GAME_DIALOG };
	bool GiveTip();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void InitBackground(void);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	CDC m_dcMem;
	CDC m_dcElement;
	CDC m_dcMask;
	CDC m_dcBG;
	CDC m_bg;
	static int TimeLeft, li;
	CPoint m_ptGameTop;//游戏起始顶点
	CSize m_sizeElem;//元素图片大小
	CRect m_rtGameRect;//游戏区域大小
//	CGameControl m_GameC;//游戏控制类
	 bool m_bStart;
	 Vertex avPath[4],Path[4];
	 int nVexnum;
	 int num;
	 int flag;//模式标识
	 bool m_bPlaying;//游戏状态标识
	 
	 static bool m_bFistPoint;
	void UpdateWindow(void);
	afx_msg void OnClose();
	 
protected:
	void InitElement(void);
public:
	
	afx_msg void OnBnClickedBtnstart();
	void UpdateMapgame(int ,int,int ,int);
	void UpdateMap();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	// 绘制提示框
	
	void DrawTipFrame(int nRow, int nCol);
	// //画提示线
	void DrawTipLine(Vertex  asvPath[4], int nVexnum);
	afx_msg void OnEnChangeEdit1();
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit2();
};
