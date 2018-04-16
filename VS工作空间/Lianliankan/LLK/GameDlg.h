#pragma once
#include <mmsystem.h>
#pragma comment( lib, "Winmm.lib" )

// CGameDlg �Ի���
#include "GameControl.h"

#include <string.h>

class CGameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameDlg)

public:
	CGameDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGameDlg();
    static bool isok;
	Vertex Vfir, Vsec;
	
// �Ի�������
	enum { IDD = IDD_GAME_DIALOG };
	bool GiveTip();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
	CPoint m_ptGameTop;//��Ϸ��ʼ����
	CSize m_sizeElem;//Ԫ��ͼƬ��С
	CRect m_rtGameRect;//��Ϸ�����С
//	CGameControl m_GameC;//��Ϸ������
	 bool m_bStart;
	 Vertex avPath[4],Path[4];
	 int nVexnum;
	 int num;
	 int flag;//ģʽ��ʶ
	 bool m_bPlaying;//��Ϸ״̬��ʶ
	 
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
	// ������ʾ��
	
	void DrawTipFrame(int nRow, int nCol);
	// //����ʾ��
	void DrawTipLine(Vertex  asvPath[4], int nVexnum);
	afx_msg void OnEnChangeEdit1();
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit2();
};
