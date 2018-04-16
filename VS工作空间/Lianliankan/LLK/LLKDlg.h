
// LLKDlg.h : header file
//

#pragma once

#include "GameDlg.h"
// CLLKDlg dialog
class CLLKDlg : public CDialogEx
{
// Construction
public:
	CLLKDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LLK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CDC m_dcMem;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void InitBackground();//≥ı ºªØ±≥æ∞
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBinBasic();
	afx_msg void OnBnClickedBinRelax();
	afx_msg void OnBnClickedBinLevel();
	afx_msg void OnBnClickedBinHelp();
	afx_msg void OnBnClickedButton1();
};
