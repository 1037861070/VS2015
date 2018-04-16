
// LLKDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LLK.h"
#include "LLKDlg.h"
#include "afxdialogex.h"
#include "GameDlg.h"


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
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLLKDlg dialog




CLLKDlg::CLLKDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLLKDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLLKDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLLKDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CLLKDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BIN_BASIC, &CLLKDlg::OnBnClickedBinBasic)
	ON_BN_CLICKED(IDC_BIN_RELAX, &CLLKDlg::OnBnClickedBinRelax)
	ON_BN_CLICKED(IDC_BIN_LEVEL, &CLLKDlg::OnBnClickedBinLevel)
	ON_BN_CLICKED(IDC_BIN_HELP, &CLLKDlg::OnBnClickedBinHelp)
	ON_BN_CLICKED(IDC_BUTTON1, &CLLKDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CLLKDlg message handlers

BOOL CLLKDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	InitBackground();
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

void CLLKDlg::InitBackground()
{
	CBitmap bmpMain;
	bmpMain.LoadBitmapW(IDB_MAIN_BG);
	CClientDC dc(this); 
	m_dcMem.CreateCompatibleDC(&dc);
	m_dcMem.SelectObject(bmpMain);
	CRect rtWin;
	CRect rtClient;
	this->GetWindowRect(rtWin);
	this->GetClientRect(rtClient);
	//����������߿�
	int nSpanWidth=rtWin.Width()-rtClient.Width();
	int nSpanHeight=rtWin.Height()-rtClient.Height();

	//���ô��ڴ�С
	MoveWindow(0,0,800+nSpanWidth,600+nSpanHeight);
	CenterWindow(NULL);
}
void CLLKDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLLKDlg::OnPaint()
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
HCURSOR CLLKDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLLKDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CLLKDlg::OnBnClickedBinBasic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CGameDlg dlg;
	CWnd::ShowWindow(FALSE);
    dlg.flag = 0;
	dlg.DoModal();
}


void CLLKDlg::OnBnClickedBinRelax()
{
	CWnd::ShowWindow(FALSE);

	CGameDlg alg;
	alg.flag = 1;
	alg.DoModal();
	
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CLLKDlg::OnBnClickedBinLevel()
{
	CWnd::ShowWindow(FALSE);
	CGameDlg blg;
	blg.flag=2;
	blg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CLLKDlg::OnBnClickedBinHelp()
{
	MessageBox(_T("����ģʽ�¿�ʵ�����й��ܣ���ʼʱ��Ϊ300s\n����ģʽû��ʱ������\n�ؿ�ģʽ��ʱ���ʼֵΪ60s��ÿ��һ�μ�3s"),_T("����"),MB_OK);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CLLKDlg::OnBnClickedButton1()
{
	MessageBox(_T("������ V1.0\n�������ѧ�뼼��ѧԺ\n0121410880220 ���1401 ���"),_T("����"),MB_OK);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
