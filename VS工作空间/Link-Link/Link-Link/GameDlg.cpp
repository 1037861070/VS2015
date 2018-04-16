// GameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Link-Link.h"
#include "GameDlg.h"
#include "afxdialogex.h"
#include "Link-LinkDlg.h"


// CGameDlg 对话框

IMPLEMENT_DYNAMIC(CGameDlg, CDialogEx)

CGameDlg::CGameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GAME_DIDLOG, pParent)
{

}

CGameDlg::~CGameDlg()
{
}

void CGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGameDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BTN_START, &CGameDlg::OnClickedBtnStart)
	ON_WM_CLOSE()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTN_PAUSE, &CGameDlg::OnClickedBtnPause)
	ON_BN_CLICKED(IDC_BTN_BACKMAIN, &CGameDlg::OnClickedBtnBackmain)
	ON_BN_CLICKED(IDC_BTN_REAREANGE, &CGameDlg::OnClickedBtnReareange)
END_MESSAGE_MAP()


// CGameDlg 消息处理程序




//BOOL CGameDlg::OnInitDialog()
//{
//	InitBackground();
//	CDialogEx::OnInitDialog();
//
//	
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//				  // 异常: OCX 属性页应返回 FALSE
//}


void CGameDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	dc.BitBlt(0, 0, 800, 600, &m_dcMem, 0, 0, SRCCOPY);
}


void CGameDlg::UpdataWindow()
{
	//调整窗口大小
	CRect rtWin;
	CRect rtClient;
	this->GetWindowRect(rtWin);		//获得窗口大小
	this->GetClientRect(rtClient);		//获得客户区大小

	//标题栏和外边框大小
	int nSpanWidth = rtWin.Width() - rtClient.Width();
	int nSpanHeight = rtWin.Height() - rtClient.Height();

	//设置窗口大小
	MoveWindow(0, 0, 800 + nSpanWidth, 600 + nSpanHeight);

	//设置对话框显示，在windows窗口正中央。
	CenterWindow();
}


void CGameDlg::InitBackground()
{
	//HANDLE hBmp = ::LoadImageW(NULL, _T("theme\\picture\\W11_800X600.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmpBasic;
	bmpBasic.LoadBitmapW(IDB_BASIC_BG);
	CClientDC dc(this);

	//创建与视频内存兼容的内存DC
	m_dcMem.CreateCompatibleDC(&dc);
	//将位图资源选入DC
	m_dcMem.SelectObject(bmpBasic);
	m_bg.CreateCompatibleDC(&dc);
}


void CGameDlg::InitElement()
{
	//获得当前对话框的视频内存
	CClientDC dc(this);

	//加载BMP图片资源
	HANDLE hBmp = ::LoadImageW(NULL, _T("theme\\picture\\waibozi_element.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	//创建与视频内存兼容的内存DC
	m_dcElement.CreateCompatibleDC(&dc);
	//将位图资源选入DC
	m_dcElement.SelectObject(hBmp);

	//加载掩码BMP图片资源
	HANDLE bMask = ::LoadImageW(NULL, _T("theme\\picture\\waibozi_mask.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	//创建与视频内存兼容的内存DC
	m_dcMask.CreateCompatibleDC(&dc);
	//将位图资源选入DC
	m_dcMask.SelectObject(bMask);
}


BOOL CGameDlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	if (flag == 0)
	{
		GetDlgItem(IDC_TIMEPROGRESS)->ShowWindow(TRUE);
		SetWindowText(_T("欢乐连连看-基本模式"));
	}
	if (flag == 1) 
	{
		GetDlgItem(IDC_TIMEPROGRESS)->ShowWindow(FALSE);
		SetWindowText(_T("欢乐连连看-休闲模式"));
	}
	 CPoint p(30, 120);
	m_ptGameTop = p;//游戏区起始点（游戏第一张图片的顶点坐标，坐标相对于窗口客户区）
	CSize s(40, 40);
	m_sizeElem = s;//元素图片大小
	CRect rt( 0, 90, 700, 570 );
	m_rtGameRect =rt;//游戏区域大小（该区域为游戏更新区域大小，考虑到后面画的线，可能会超出图片区域一定范围）
	m_bPlaying = false;//游戏状态标识

	//m_bPlaying = false;//游戏状态标识

	InitBackground();
	InitElement();
	UpdataWindow();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CGameDlg::OnClickedBtnStart()
{
	//if (m_bPlaying == true)
	//	return;
	ClearMap();
	m_bFirstPoint = true;
	m_bPlaying = true;
	m_bPause = false;
	timeLeft = 60;
	lastTime = timeLeft;
	m_GameC.StartGame();
	UpdataMap();
	if (flag == 0)
	{
		SetTimer(1, 1000, NULL);
	}
	timeProgress = (CProgressCtrl*)GetDlgItem(IDC_TIMEPROGRESS);
	timeProgress->SetRange(0, 60);
	timeProgress->SetStep(1);
	timeProgress->SetPos(60);
	InvalidateRect(m_rtGameRect);
	SetDlgItemText(IDC_BTN_START, _T("重新开始"));
}


// 更新游戏地图
void CGameDlg::UpdataMap()
{
	//计算图片的顶点坐标与图片大小
	int nLeft = m_ptGameTop.x;//起始位置左
	int nTop = m_ptGameTop.y;//起始位置上
	int nElemW = m_sizeElem.cx;//元素图片宽
	int nELemH = m_sizeElem.cy;//元素图片高

	//获取行数和列数
	int nRows = CGameControl::s_nRows;//游戏行数
	int nCols = CGameControl::s_nCols;//游戏列数

	//
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			//得到图片编号值
			int nElemVal = m_GameC.GetElement(i, j);

			if (nElemVal == BLANK)
				continue;

			//将背景与掩码相或，边保留，图像区域为1
			m_dcMem.BitBlt(nLeft + j * nElemW, nTop + i * nELemH, nElemW, nELemH, &m_dcMask, 0, nElemVal * nELemH, SRCPAINT);

			//与元素图片相与，边保留，图像区域为元素图片
			m_dcMem.BitBlt(nLeft + j * nElemW, nTop + i * nELemH, nElemW, nELemH, &m_dcElement, 0, nElemVal * nELemH, SRCAND);
		}
	}
	
}


void CGameDlg::OnClose()
{
	GetParent()->ShowWindow(SW_SHOW);
	CDialogEx::OnClose();
}


void CGameDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	//判断是否暂停
	if (m_bPause)
	{
		return CDialogEx::OnLButtonUp(nFlags, point);
	}
	//判断鼠标点击的区域
	if (point.y < m_ptGameTop.y || point.y > m_ptGameTop.y +m_sizeElem.cy * CGameControl::s_nRows || point.x < m_ptGameTop.x || point.x > m_ptGameTop.x + m_sizeElem.cx * CGameControl::s_nCols)
	{
		return CDialogEx::OnLButtonUp(nFlags, point);
	}

	int row = (point.y - m_ptGameTop.y) / m_sizeElem.cy;
	int col = (point.x - m_ptGameTop.x) / m_sizeElem.cx;
	if (m_GameC.GetElement(row, col) == BLANK)
	{
		return CDialogEx::OnLButtonUp(nFlags, point);
	}
	if (m_bFirstPoint) //第一个点
	{
		m_GameC.SetFirstPoint(row, col);
		DrawTipFrame(row, col);
		CPoint p(col * m_sizeElem.cy, row * m_sizeElem.cx);
		m_ptFirstPoint = m_ptGameTop + p;
			//(CPoint)(m_ptGameTop.x + col * m_sizeElem.cy, m_ptGameTop.y + row * m_sizeElem.cx);
		m_bFirstPoint = !m_bFirstPoint;
	} 
	else
	{
		m_GameC.SetSecPoint(row, col);
		DrawTipFrame(row, col);
		//连子判断
		bool bSuc = m_GameC.Link(avPath, nVexnum);
		if (bSuc) {
			//画提示线
			DrawTipLine(avPath, nVexnum);
			UpdataMapGame(avPath[0], avPath[nVexnum - 1]);
			m_GameC.Clear();
			if ((timeLeft + 5) > 60)
			{
				timeLeft = 60;
			}
			else
			{
				timeLeft += 5;
			}			
			lastTime = timeLeft;
			Sleep(100);
			InvalidateRect(m_rtGameRect, FALSE);
			timeProgress->SetPos(timeLeft);
			m_bFirstPoint = !m_bFirstPoint;
		}
		else
		{
			CPoint p(col * m_sizeElem.cy, row * m_sizeElem.cx);
			CRect rt(m_ptFirstPoint, m_sizeElem);
			InvalidateRect(rt, FALSE);
			if (m_ptFirstPoint == m_ptGameTop + p)
			{
				m_bFirstPoint = !m_bFirstPoint;
				return CDialogEx::OnLButtonUp(nFlags, point);
			}
			DrawTipFrame(row, col);
			m_GameC.SetFirstPoint(row, col);
			//CPoint p(col * m_sizeElem.cy, row * m_sizeElem.cx);
			m_ptFirstPoint = m_ptGameTop + p;
			//m_bFirstPoint = !m_bFirstPoint;
		}
		
		if (bSuc && m_GameC.IsWin())
		{
			KillTimer(1);
			AfxMessageBox(_T("恭喜过关！"), MB_OK);
			SetDlgItemText(IDC_BTN_START, _T("重新开始"));
			//m_bPlaying = false;
		}
	}

	//m_bFirstPoint = !m_bFirstPoint;
}


// 绘制矩形提示框
void CGameDlg::DrawTipFrame(int nRow, int nCol)
{
	CClientDC dc(this);

	HPEN hPen = CreatePen(
		PS_SOLID,
		0,
		RGB(233, 43, 43));
	HPEN hPenOld = (HPEN)dc.SelectObject(hPen);

	HBRUSH hBr = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH hBrOld = (HBRUSH)dc.SelectObject(hBr);

	int top = nRow * m_sizeElem.cy + m_ptGameTop.y;
	int bottom = (nRow + 1) * m_sizeElem.cy + m_ptGameTop.y;
	int left = nCol * m_sizeElem.cx + m_ptGameTop.x;
	int right = (nCol + 1) * m_sizeElem.cy + m_ptGameTop.x;
	Rectangle(
		dc,
		left, top,
		right, bottom);
	dc.SelectObject(hPenOld);
	dc.SelectObject(hBrOld);
	DeleteObject(hPen);
	DeleteObject(hBr);
}


// 绘制连线
void CGameDlg::DrawTipLine(Vertex asvPath[4], int nVexnum)
{
	CClientDC dc(this);
	HPEN hPen = CreatePen(
		PS_SOLID,
		2,
		RGB(0, 255, 0));
	HPEN hPenOld = (HPEN)dc.SelectObject(hPen);

	dc.MoveTo(m_ptGameTop.x + asvPath[0].col * m_sizeElem.cx + m_sizeElem.cx / 2,
		m_ptGameTop.y + asvPath[0].row * m_sizeElem.cy + m_sizeElem.cy / 2);

	for (int i = 1; i < nVexnum; i++)
	{
		dc.LineTo(m_ptGameTop.x + asvPath[i].col * m_sizeElem.cx + m_sizeElem.cx / 2,
			m_ptGameTop.y + asvPath[i].row * m_sizeElem.cy + m_sizeElem.cy / 2);
	}

	dc.SelectObject(hPenOld);
	DeleteObject(hPen);
}


// 游戏中更新地图
void CGameDlg::UpdataMapGame(Vertex V1, Vertex V2)
{
	HBITMAP hBmp = (HBITMAP)LoadImage(AfxGetApp()->m_hInstance, _T("theme\\picture\\W11_800X600.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_bg.SelectObject(hBmp);
	m_dcMem.BitBlt(
		m_ptGameTop.x + V1.col * m_sizeElem.cx, m_ptGameTop.y + V1.row * m_sizeElem.cy,
		m_sizeElem.cx, m_sizeElem.cy, 
		&m_bg, 
		m_ptGameTop.x + V1.col * m_sizeElem.cx, m_ptGameTop.y + V1.row * m_sizeElem.cy,
		SRCCOPY);
	m_dcMem.BitBlt(
		m_ptGameTop.x + V2.col * m_sizeElem.cx, m_ptGameTop.y + V2.row * m_sizeElem.cy,
		m_sizeElem.cx, m_sizeElem.cy,
		&m_bg,
		m_ptGameTop.x + V2.col * m_sizeElem.cx, m_ptGameTop.y + V2.row * m_sizeElem.cy,
		SRCCOPY);
}


void CGameDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1)
	{
		CString s1;
		timeLeft--;
		timeProgress->SetPos(timeLeft);
		if ((lastTime - timeLeft) == 20)
		{
			CRect rt(m_ptFirstPoint, m_sizeElem);
			InvalidateRect(rt, FALSE);
			LinkTip();
			m_bFirstPoint = true;
		}
		if (timeLeft < 0)
		{
			KillTimer(1);
			AfxMessageBox(_T("游戏结束！"), MB_OK);
			SetDlgItemTextW(IDC_BTN_START, _T("重新开始"));
			//m_bPlaying = false;
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CGameDlg::OnClickedBtnPause()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_bPlaying)
		return;
	if (m_bPause) {
		if (flag == 0)
		{
			SetTimer(1, 1000, NULL);
		}
		SetDlgItemTextW(IDC_BTN_PAUSE, _T("暂停"));
		m_bPause = false;
	}
	else
	{
		SetDlgItemTextW(IDC_BTN_PAUSE, _T("继续"));
		KillTimer(1);
		m_bPause = true;
	}
}



void CGameDlg::OnClickedBtnBackmain()
{
	// TODO: 在此添加控件通知处理程序代码
	SendMessage(WM_CLOSE);
}


// 清空地图
void CGameDlg::ClearMap()
{
	HBITMAP hBmp = (HBITMAP)LoadImage(AfxGetApp()->m_hInstance, _T("theme\\picture\\W11_800X600.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_bg.SelectObject(hBmp);
	m_dcMem.BitBlt(
		m_ptGameTop.x, m_ptGameTop.y,
		CGameControl::s_nCols * m_sizeElem.cx, CGameControl::s_nRows * m_sizeElem.cy,
		&m_bg,
		m_ptGameTop.x, m_ptGameTop.y,
		SRCCOPY);
}


void CGameDlg::OnClickedBtnReareange()
{
	// TODO: 在此添加控件通知处理程序代码
	int nRows = m_GameC.s_nRows;
	int nCols = m_GameC.s_nCols;
	m_GameC.RearrangeMap();
	ClearMap();
	UpdataMap();
	InvalidateRect(m_rtGameRect, FALSE);
	/*
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++)
		{
			if (m_GameC.GetElement(i, j) != BLANK) {
				
				m_dcMem.BitBlt(
					m_ptGameTop.x + j * m_sizeElem.cx, m_ptGameTop.y + i * m_sizeElem.cy,
					m_sizeElem.cx, m_sizeElem.cy,
					&m_bg,
					m_ptGameTop.x + j * m_sizeElem.cx, m_ptGameTop.y + i * m_sizeElem.cy,
					SRCCOPY);
			}
		}
		*/
}


// 连线提示
bool CGameDlg::LinkTip()
{
	int nRows = m_GameC.s_nRows;
	int nCols = m_GameC.s_nCols;
	int picElem;
	int Vexnum;
	Vertex path[4];
	CPoint p1, p2;
	for (int i = 0; i < nRows - 1; i++)
		for (int j = 0; j < nCols - 1; j++)
		{
			picElem = m_GameC.GetElement(i, j);
			if (picElem == BLANK)
			{
				continue;
			}
			//m_tipVx1 = { i, j, picElem };
			m_tipVx1.row = i;
			m_tipVx1.col = j;
			m_tipVx1.picNum = picElem;
			for (int m = i; m < nRows; m++)
				for (int n = j; n < nCols; n++)
				{
					picElem = m_GameC.GetElement(m, n);
					if (picElem == BLANK)
					{
						continue;
					}
					//m_tipVx2 = { m, n, picElem };
					m_tipVx2.row = i;
					m_tipVx2.col = j;
					m_tipVx2.picNum = picElem;
					m_GameC.SetFirstPoint(i, j);
					m_GameC.SetSecPoint(m, n);
					if (m_GameC.Link(path, Vexnum))
					{
						//CRect rt1(p1, m_sizeElem);
						//InvalidateRect(rt1, FALSE);
						//CRect rt2(p2, m_sizeElem);
						//InvalidateRect(rt2, FALSE);
						DrawTipFrame(m_tipVx1.row, m_tipVx1.col);
						DrawTipFrame(m_tipVx2.row, m_tipVx2.col);
						//p1 = (i * m_sizeElem.cy, j * m_sizeElem.cx);
						//p2 = (m * m_sizeElem.cy, n * m_sizeElem.cx);
						return true;
					}
				}
		}
	return false;
}
