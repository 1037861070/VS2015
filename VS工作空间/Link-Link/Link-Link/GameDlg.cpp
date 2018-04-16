// GameDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Link-Link.h"
#include "GameDlg.h"
#include "afxdialogex.h"
#include "Link-LinkDlg.h"


// CGameDlg �Ի���

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


// CGameDlg ��Ϣ�������




//BOOL CGameDlg::OnInitDialog()
//{
//	InitBackground();
//	CDialogEx::OnInitDialog();
//
//	
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//				  // �쳣: OCX ����ҳӦ���� FALSE
//}


void CGameDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	dc.BitBlt(0, 0, 800, 600, &m_dcMem, 0, 0, SRCCOPY);
}


void CGameDlg::UpdataWindow()
{
	//�������ڴ�С
	CRect rtWin;
	CRect rtClient;
	this->GetWindowRect(rtWin);		//��ô��ڴ�С
	this->GetClientRect(rtClient);		//��ÿͻ�����С

	//����������߿��С
	int nSpanWidth = rtWin.Width() - rtClient.Width();
	int nSpanHeight = rtWin.Height() - rtClient.Height();

	//���ô��ڴ�С
	MoveWindow(0, 0, 800 + nSpanWidth, 600 + nSpanHeight);

	//���öԻ�����ʾ����windows���������롣
	CenterWindow();
}


void CGameDlg::InitBackground()
{
	//HANDLE hBmp = ::LoadImageW(NULL, _T("theme\\picture\\W11_800X600.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmpBasic;
	bmpBasic.LoadBitmapW(IDB_BASIC_BG);
	CClientDC dc(this);

	//��������Ƶ�ڴ���ݵ��ڴ�DC
	m_dcMem.CreateCompatibleDC(&dc);
	//��λͼ��Դѡ��DC
	m_dcMem.SelectObject(bmpBasic);
	m_bg.CreateCompatibleDC(&dc);
}


void CGameDlg::InitElement()
{
	//��õ�ǰ�Ի������Ƶ�ڴ�
	CClientDC dc(this);

	//����BMPͼƬ��Դ
	HANDLE hBmp = ::LoadImageW(NULL, _T("theme\\picture\\waibozi_element.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	//��������Ƶ�ڴ���ݵ��ڴ�DC
	m_dcElement.CreateCompatibleDC(&dc);
	//��λͼ��Դѡ��DC
	m_dcElement.SelectObject(hBmp);

	//��������BMPͼƬ��Դ
	HANDLE bMask = ::LoadImageW(NULL, _T("theme\\picture\\waibozi_mask.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	//��������Ƶ�ڴ���ݵ��ڴ�DC
	m_dcMask.CreateCompatibleDC(&dc);
	//��λͼ��Դѡ��DC
	m_dcMask.SelectObject(bMask);
}


BOOL CGameDlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	if (flag == 0)
	{
		GetDlgItem(IDC_TIMEPROGRESS)->ShowWindow(TRUE);
		SetWindowText(_T("����������-����ģʽ"));
	}
	if (flag == 1) 
	{
		GetDlgItem(IDC_TIMEPROGRESS)->ShowWindow(FALSE);
		SetWindowText(_T("����������-����ģʽ"));
	}
	 CPoint p(30, 120);
	m_ptGameTop = p;//��Ϸ����ʼ�㣨��Ϸ��һ��ͼƬ�Ķ������꣬��������ڴ��ڿͻ�����
	CSize s(40, 40);
	m_sizeElem = s;//Ԫ��ͼƬ��С
	CRect rt( 0, 90, 700, 570 );
	m_rtGameRect =rt;//��Ϸ�����С��������Ϊ��Ϸ���������С�����ǵ����滭���ߣ����ܻᳬ��ͼƬ����һ����Χ��
	m_bPlaying = false;//��Ϸ״̬��ʶ

	//m_bPlaying = false;//��Ϸ״̬��ʶ

	InitBackground();
	InitElement();
	UpdataWindow();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
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
	SetDlgItemText(IDC_BTN_START, _T("���¿�ʼ"));
}


// ������Ϸ��ͼ
void CGameDlg::UpdataMap()
{
	//����ͼƬ�Ķ���������ͼƬ��С
	int nLeft = m_ptGameTop.x;//��ʼλ����
	int nTop = m_ptGameTop.y;//��ʼλ����
	int nElemW = m_sizeElem.cx;//Ԫ��ͼƬ��
	int nELemH = m_sizeElem.cy;//Ԫ��ͼƬ��

	//��ȡ����������
	int nRows = CGameControl::s_nRows;//��Ϸ����
	int nCols = CGameControl::s_nCols;//��Ϸ����

	//
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			//�õ�ͼƬ���ֵ
			int nElemVal = m_GameC.GetElement(i, j);

			if (nElemVal == BLANK)
				continue;

			//��������������򣬱߱�����ͼ������Ϊ1
			m_dcMem.BitBlt(nLeft + j * nElemW, nTop + i * nELemH, nElemW, nELemH, &m_dcMask, 0, nElemVal * nELemH, SRCPAINT);

			//��Ԫ��ͼƬ���룬�߱�����ͼ������ΪԪ��ͼƬ
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
	//�ж��Ƿ���ͣ
	if (m_bPause)
	{
		return CDialogEx::OnLButtonUp(nFlags, point);
	}
	//�ж������������
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
	if (m_bFirstPoint) //��һ����
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
		//�����ж�
		bool bSuc = m_GameC.Link(avPath, nVexnum);
		if (bSuc) {
			//����ʾ��
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
			AfxMessageBox(_T("��ϲ���أ�"), MB_OK);
			SetDlgItemText(IDC_BTN_START, _T("���¿�ʼ"));
			//m_bPlaying = false;
		}
	}

	//m_bFirstPoint = !m_bFirstPoint;
}


// ���ƾ�����ʾ��
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


// ��������
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


// ��Ϸ�и��µ�ͼ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
			AfxMessageBox(_T("��Ϸ������"), MB_OK);
			SetDlgItemTextW(IDC_BTN_START, _T("���¿�ʼ"));
			//m_bPlaying = false;
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CGameDlg::OnClickedBtnPause()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!m_bPlaying)
		return;
	if (m_bPause) {
		if (flag == 0)
		{
			SetTimer(1, 1000, NULL);
		}
		SetDlgItemTextW(IDC_BTN_PAUSE, _T("��ͣ"));
		m_bPause = false;
	}
	else
	{
		SetDlgItemTextW(IDC_BTN_PAUSE, _T("����"));
		KillTimer(1);
		m_bPause = true;
	}
}



void CGameDlg::OnClickedBtnBackmain()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SendMessage(WM_CLOSE);
}


// ��յ�ͼ
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


// ������ʾ
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
