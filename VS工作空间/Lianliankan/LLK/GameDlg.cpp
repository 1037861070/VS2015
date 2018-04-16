// GameDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LLK.h"
#include "GameDlg.h"
#include "afxdialogex.h"
#include "GameControl.h"
#include "GameLogic.h"

CGameControl m_GameC;
// CGameDlg �Ի���

IMPLEMENT_DYNAMIC(CGameDlg, CDialogEx)

CGameDlg::CGameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGameDlg::IDD, pParent)
{
	m_bStart = false;
	//m_bPlaying=false;
	m_sizeElem.cy=40;
	m_sizeElem.cx=40;
	m_rtGameRect.left=20;
	m_rtGameRect.top=50;
	
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
	ON_WM_CLOSE()
	
	ON_BN_CLICKED(IDC_BtnStart, &CGameDlg::OnBnClickedBtnstart)
	ON_WM_LBUTTONUP()
	
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, &CGameDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CGameDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CGameDlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT2, &CGameDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CGameDlg ��Ϣ�������


void CGameDlg::InitBackground(void)
{
	CClientDC dc(this);
	HANDLE Game_bg=::LoadImageW(NULL,_T("theme\\picture\\default_bg.bmp"),0,0,IMAGE_BITMAP,LR_LOADFROMFILE);
	m_dcMem.CreateCompatibleDC(&dc);
	m_dcMem.SelectObject(Game_bg);
	m_bg.CreateCompatibleDC(&dc);
	UpdateWindow();
}


BOOL CGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_bStart=true;
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	if(flag == 0){
		GetDlgItem((IDC_EDIT2))->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(TRUE);
		SetWindowText(_T("����������-����ģʽ"));
	}
	if(flag == 1){
		GetDlgItem((IDC_EDIT2))->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(FALSE);
		SetWindowText(_T("����������-����ģʽ"));
	}
	if (flag==2)
	{
		GetDlgItem((IDC_EDIT2))->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(FALSE);
		SetWindowText(_T("����������-�ؿ�ģʽ"));
	}
		PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_LOOP);
	InitBackground();
	InitElement();
	UpdateWindow();
		
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CGameDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	dc.BitBlt(0,0,800,600,&m_dcMem,0,0,SRCCOPY);

	// ��Ϊ��ͼ��Ϣ���� 
	CDialogEx::OnPaint();
	
}

bool CGameDlg::GiveTip()
{
	for (int i = 0; i < CGameControl::s_nRows; i++)
	{
		for (int j = 0; j < CGameControl::s_nCols; j++)
		{
			int value = m_GameC.GetElement(i, j);
			if (value != -1)
			{
				Vfir.row=i;
				Vfir.col=j;
				Vfir.info=value;
				for (int r = 0; r < CGameControl::s_nRows; r++)
				{
					for (int c = 0; c < CGameControl::s_nCols; c++)
					{
						int info = m_GameC.GetElement(r, c);
						if (value == info)
						{
							Vsec.row=r;
							Vsec.col=c;
							Vsec.info=info;
							m_GameC.SetFistPoint(i, j);
							m_GameC.SetSecPoint(r, c);
							if (m_GameC.Link(Path, num))
							{
								m_GameC.m_pGameMap[i][j] = info;
								m_GameC.m_pGameMap[r][c] = info;
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}


void CGameDlg::UpdateWindow(void)
{
	CRect rtWin;
	CRect  rtClient;
	m_rtGameRect = rtClient;
	this->GetWindowRect(rtWin);
	this->GetClientRect(rtClient);
	//����������߿��С
	int nSpanWidth =rtWin.Width()-rtClient.Width();
	int nSpanHeight =rtWin.Height()-rtClient.Height();
	//���ô��ڴ�С
	MoveWindow(0,0,800+nSpanWidth,600+nSpanHeight);
	CenterWindow();
}


void CGameDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	PlaySound(NULL, NULL, SND_FILENAME);
	KillTimer(1);
	GetParent()->ShowWindow(SW_SHOW);
	CDialogEx::OnClose();
}


void CGameDlg::InitElement(void)
{
	//��õ�ǰ�ĶԻ������Ƶ�ڴ�
	CClientDC dc(this);
	//����BMPͼƬ��Դ
	HANDLE hBmp=::LoadImageW(NULL,_T("theme\\picture\\fruit_element.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	//��������Ƶ�ڴ�����ݵ��ڴ�DC
	m_dcElement.CreateCompatibleDC(&dc);
    //��λͼ��Դѡ��DC
	m_dcElement.SelectObject(hBmp);
	//��������BMPͼƬ��Դ
	HANDLE hMask=::LoadImageW(NULL,_T("theme\\picture\\fruit_mask.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	//��������Ƶ�ڴ�����ݵ��ڴ�DC
	m_dcMask.CreateCompatibleDC(&dc);
	m_dcMask.SelectObject(hMask);
}

int CGameDlg::TimeLeft = 300;
int CGameDlg::li=0;
void CGameDlg::OnBnClickedBtnstart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//m_bPlaying=true;
	TimeLeft=300;
	if (m_bStart)
	{
		if(flag == 0)
		{
			SetTimer(1,1000,NULL);
		}
		if (flag==2)
		{
			TimeLeft=60;
			SetTimer(1,1000,NULL);
		}
		m_bStart=false;
		m_GameC.StartGame();
		UpdateMap();
		Invalidate(FALSE);
		}
	else
		return;
	
}


void CGameDlg::UpdateMap(void)
{
	//��ʼ��ͼƬ����������ͼƬ��С
	int nleft=20,nTop=50;
	int nElemW=40,nElemH=40;
	//��ȡ����������
	int nRows=CGameControl::s_nRows;
	int nCols=CGameControl::s_nCols;
	for (int i=0;i<nRows;i++)
	{
		for (int j=0;j<nCols;j++)
		{
			//ȡ��ͼƬ���
			int nElemVal=m_GameC.GetElement(i,j);
			//��ͼƬ������������򣬱߱�����ͼ������Ϊһ��
			m_dcMem.BitBlt(nleft+j*nElemW,nTop+i*nElemH,nElemW,nElemH,&m_dcMask,0,nElemVal*nElemH,SRCPAINT);
			//��Ԫ��ͼƬ���룬�߱�����ͼ������ΪԪ��ͼƬ
			m_dcMem.BitBlt(nleft+j*nElemW,nTop+i*nElemH,nElemW,nElemH,&m_dcElement,0,nElemVal*nElemH,SRCAND);
		}
	}
}

bool CGameDlg::m_bFistPoint=true;
void CGameDlg::OnLButtonUp(UINT nFlags, CPoint point)  //���ӽ׶�
{
	if(!isok)
		return ;
	//�ж����������
	m_sizeElem.cy=40;
	m_sizeElem.cx=40;
	m_rtGameRect.left=0;
	m_rtGameRect.top=0;
	m_rtGameRect.right=20+16*40;
	m_rtGameRect.bottom=50+10*40;
	int row=(point.y-50)/m_sizeElem.cy;
	int col=(point.x-20)/m_sizeElem.cx;
	//�жϵ���������Ƿ���ȷ��ִ����Ӧ�Ĳ���
	if (point.y<m_rtGameRect.top||point.y>m_rtGameRect.bottom||point.x<m_rtGameRect.left
		||point.x>m_rtGameRect.right||m_GameC.m_pGameMap[row][col]==BLANK)
	{
		return CDialogEx::OnLButtonUp(nFlags,point);
	}

	if (m_bFistPoint)//��һ����
	{
		DrawTipFrame(row,col);   //�����ο�
		m_GameC.SetFistPoint(row,col);
	}
	else
	{
		DrawTipFrame(row,col);  //�����ο�
		m_GameC.SetSecPoint(row,col);
		bool bSuc=m_GameC.Link(avPath,nVexnum);//�ж��Ƿ����ͨ
		if (bSuc==true)
		{
			//����ʾ��
			DrawTipLine(avPath,nVexnum);
			//���µ�ͼ
			UpdateMapgame(avPath[0].row,avPath[0].col,avPath[nVexnum-1].row,avPath[nVexnum-1].col);
			if (flag==2)    //�ؿ�ģʽ����һ�μ�3s
			{
				TimeLeft=TimeLeft+3;
			}
		}
		Sleep(100);
		InvalidateRect(m_rtGameRect,FALSE);
		if (bSuc&&m_GameC.IsWin())  //�����ʱ��û�м��ٵ�-1��������������е�ͼƪ�����ж�ʤ��
		{
			KillTimer(1);
			AfxMessageBox(_T("��ϲ���أ�"), MB_OK);
			m_GameC.m_pGameMap = NULL;
			this->OnCancel();
			OnClose();	}
	}
	m_bFistPoint=!m_bFistPoint;
}

void CGameDlg::UpdateMapgame(int row1, int col1, int row2, int col2) //���µ�ͼ����
{
	HBITMAP Game_bg = (HBITMAP)LoadImage(AfxGetApp()->m_hInstance, _T("theme\\picture\\default_bg.bmp"), 
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);  //ѡ��ͼƬ
	m_bg.SelectObject(Game_bg);
	//����ͼƬ����������ͼƬ
	m_dcMem.BitBlt(20 + col1*40, 50 + row1*40, 40, 40, &m_bg, 20 + col1*40, 50 + row1*40, SRCCOPY);//
	m_dcMem.BitBlt(20 + col2*40, 50+ row2*40, 40, 40, &m_bg, 20 + col2*40, 50 + row2*40, SRCCOPY);
}



void CGameDlg::DrawTipFrame(int nRow, int nCol)                             //��ͼƬ�İ�Χ��
{
	CClientDC dc(this);
	CPen penFrame(PS_SOLID,2,RGB(233,43,43));                               //ѡ�񻭱���ɫ������
	 CPen *pOldPen = dc.SelectObject(&penFrame);
	 dc.SelectStockObject(NULL_BRUSH);                                      //��ˢѡ��
	int nleft=20,ntop=50;
	dc.Rectangle( nleft + nCol*m_sizeElem.cx,ntop + nRow*m_sizeElem.cy,     //�����ο�
	nleft + nCol*m_sizeElem.cx + m_sizeElem.cy, ntop + nRow*m_sizeElem.cy + m_sizeElem.cy );
	dc.SelectObject(pOldPen);
}



void CGameDlg::DrawTipLine(Vertex  asvPath[4], int nVexnum)          //����ʾ��
{
	CClientDC dc(this);
	CPen penLine(PS_SOLID, 2, RGB(0, 255, 0));                      //ѡ�񻭱ʵ����ࡢ��ɫ
	CPen *pOldPen = dc.SelectObject(&penLine);                      //����ͼƬ֮�������
	dc.MoveTo(20 + asvPath[0].col*40 + 40 / 2, 50 + asvPath[0].row*40 + 40 / 2);
	for (int i = 1; i < nVexnum;i++)
	{
		dc.LineTo(20 + asvPath[i].col*40 + 40 / 2, 50 + asvPath[i].row*40 + 40 / 2);
	}
	dc.SelectObject(pOldPen);                                       //ѡ�л���
}






void CGameDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s1;
	if (nIDEvent==1&&TimeLeft!=-1)     //����¼���ԴΪ1��ʱ�䲻Ϊ-1
	{
		//��int����ת��ΪCString����
		s1.Format(_T("����ʱ:%d"),TimeLeft);  
		//�����ʱʱ��
		GetDlgItem(IDC_EDIT2)->SetWindowTextW(s1);
		//ˢ��һ��ʱ�����һ��
		--TimeLeft;                        
	}
	if (TimeLeft<0)   //���ʱ��С��0����ֹʱ�䣬��ʱ������Ϸʧ�ܣ�
		{
			KillTimer(1);
			AfxMessageBox(_T("��Ϸʧ�ܣ�"), MB_OK);
			this->OnCancel();
			OnClose();
		}
	CDialogEx::OnTimer(nIDEvent);
}

bool CGameDlg::isok=true;
void CGameDlg::OnBnClickedButton2()
{
	if (isok)
	{
		KillTimer(1);

		isok=false;
	}
	  else  
	{
	SetTimer(1,1000,NULL);
	isok=true;
	  }
	
	  
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}




void CGameDlg::OnBnClickedButton3()
{
	bool flag = false;
	if (m_GameC.m_pGameMap==NULL)
	{
		AfxMessageBox(_T("���ȿ�ʼ��Ϸ��"), true);
		return;
	}
	else
	{ 
		flag = GiveTip();
	}
	if (flag==true)
	{
		DrawTipFrame(Vfir.row, Vfir.col);
		DrawTipFrame(Vsec.row, Vsec.col);
	}
	else
	{
		AfxMessageBox(_T("��Ϸʧ��!"), MB_CANCELTRYCONTINUE);
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CGameDlg::OnBnClickedButton4()
{
	if (m_GameC.m_pGameMap==NULL)
	{
		return;
	} 
	else
	{
		srand((int)time(NULL));
		int nVertexNum = m_GameC.s_nCols*m_GameC.s_nRows;
		for (int i = 0; i < nVertexNum; i++)
		{
			int nIndex1 = rand() % nVertexNum;
			int nIndex2 = rand() % nVertexNum;
			int temp1 = m_GameC.m_pGameMap[nIndex1 / m_GameC.s_nCols][nIndex1 % m_GameC.s_nCols];
			int temp2 = m_GameC.m_pGameMap[nIndex2 /m_GameC.s_nCols][nIndex2 % m_GameC.s_nCols];
			if (temp1 == -1 || temp2 == -1)
			{

			}
			else
			{
				int nTemp = m_GameC.m_pGameMap[nIndex1 / m_GameC.s_nCols][nIndex1 % m_GameC.s_nCols];
				m_GameC.m_pGameMap[nIndex1 / m_GameC.s_nCols][nIndex1 % m_GameC.s_nCols] = m_GameC.m_pGameMap[nIndex2 / 
					m_GameC.s_nCols][nIndex2 % m_GameC.s_nCols];
				m_GameC.m_pGameMap[nIndex2 / m_GameC.s_nCols][nIndex2 % m_GameC.s_nCols] = nTemp;
			}
		}
		HBITMAP Game_bg = (HBITMAP)LoadImage(AfxGetApp()->m_hInstance, _T("theme\\picture\\default_bg.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		m_bg.SelectObject(Game_bg);
		m_dcMem.BitBlt(20, 50, 40*m_GameC.s_nCols, 40*m_GameC.s_nRows, &m_bg, 20,50, SRCCOPY);
		UpdateMap();
		InvalidateRect(m_rtGameRect, false);
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CGameDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
