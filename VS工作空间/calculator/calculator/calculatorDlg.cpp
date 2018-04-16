
// calculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include <tchar.h>
#include<stdlib.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg dialog




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CcalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CcalculatorDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &CcalculatorDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON3, &CcalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CcalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CcalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalculatorDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CcalculatorDlg message handlers

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	Initbackground();


	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		dc.BitBlt(0,0,800,600,&m_dcMem,0,0,SRCCOPY);
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::Initbackground(void)
{
		CBitmap bmpMain;
		bmpMain.LoadBitmapW(IDB_BITMAP1);
		CClientDC dc(this); 
		m_dcMem.CreateCompatibleDC(&dc);
		m_dcMem.SelectObject(bmpMain);	
}


void CcalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CcalculatorDlg::OnBnClickedButton1()
{
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(s1);
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(s2);
	float a;
	a=_tstof(s1)+_tstof(s2);
	s3.Format(_T("%f"),a);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorDlg::OnEnChangeEdit2()
{
	
	
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CcalculatorDlg::OnBnClickedButton3()
{GetDlgItem(IDC_EDIT2)->GetWindowTextW(s1);
GetDlgItem(IDC_EDIT1)->GetWindowTextW(s2);
float a;
a=_tstof(s1)-_tstof(s2);
s3.Format(_T("%f"),a);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorDlg::OnBnClickedButton2()
{
	GetDlgItem(IDC_EDIT3)->SetWindowTextW(s3);
	
	// TODO: 在此添加控件通知处理程序代码
}



void CcalculatorDlg::OnBnClickedButton4()
{GetDlgItem(IDC_EDIT2)->GetWindowTextW(s1);
GetDlgItem(IDC_EDIT1)->GetWindowTextW(s2);
float a;
a=_tstof(s1)*_tstof(s2);
s3.Format(_T("%f"),a);

	// TODO: 在此添加控件通知处理程序代码
}

void CcalculatorDlg::OnBnClickedButton5()
{
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(s1);
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(s2);
	float a;
	a=_tstof(s1)/_tstof(s2);
	s3.Format(_T("%f"),a);
// TODO: 在此添加控件通知处理程序代码
}
