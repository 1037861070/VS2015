// GameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LLK.h"
#include "GameDlg.h"
#include "afxdialogex.h"
#include "GameControl.h"
#include "GameLogic.h"

CGameControl m_GameC;
// CGameDlg 对话框

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


// CGameDlg 消息处理程序


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
	// TODO:  在此添加额外的初始化
	if(flag == 0){
		GetDlgItem((IDC_EDIT2))->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(TRUE);
		SetWindowText(_T("欢乐连连看-基本模式"));
	}
	if(flag == 1){
		GetDlgItem((IDC_EDIT2))->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(FALSE);
		SetWindowText(_T("欢乐连连看-休闲模式"));
	}
	if (flag==2)
	{
		GetDlgItem((IDC_EDIT2))->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(FALSE);
		SetWindowText(_T("欢乐连连看-关卡模式"));
	}
		PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_LOOP);
	InitBackground();
	InitElement();
	UpdateWindow();
		
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CGameDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	dc.BitBlt(0,0,800,600,&m_dcMem,0,0,SRCCOPY);

	// 不为绘图消息调用 
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
	//标题栏和外边框大小
	int nSpanWidth =rtWin.Width()-rtClient.Width();
	int nSpanHeight =rtWin.Height()-rtClient.Height();
	//设置窗口大小
	MoveWindow(0,0,800+nSpanWidth,600+nSpanHeight);
	CenterWindow();
}


void CGameDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	PlaySound(NULL, NULL, SND_FILENAME);
	KillTimer(1);
	GetParent()->ShowWindow(SW_SHOW);
	CDialogEx::OnClose();
}


void CGameDlg::InitElement(void)
{
	//获得当前的对话框的视频内存
	CClientDC dc(this);
	//加载BMP图片资源
	HANDLE hBmp=::LoadImageW(NULL,_T("theme\\picture\\fruit_element.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	//创建与视频内存相兼容的内存DC
	m_dcElement.CreateCompatibleDC(&dc);
    //将位图资源选入DC
	m_dcElement.SelectObject(hBmp);
	//加载掩码BMP图片资源
	HANDLE hMask=::LoadImageW(NULL,_T("theme\\picture\\fruit_mask.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	//创建与视频内存相兼容的内存DC
	m_dcMask.CreateCompatibleDC(&dc);
	m_dcMask.SelectObject(hMask);
}

int CGameDlg::TimeLeft = 300;
int CGameDlg::li=0;
void CGameDlg::OnBnClickedBtnstart()
{
	// TODO: 在此添加控件通知处理程序代码
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
	//初始化图片顶点坐标与图片大小
	int nleft=20,nTop=50;
	int nElemW=40,nElemH=40;
	//获取行数和列数
	int nRows=CGameControl::s_nRows;
	int nCols=CGameControl::s_nCols;
	for (int i=0;i<nRows;i++)
	{
		for (int j=0;j<nCols;j++)
		{
			//取得图片编号
			int nElemVal=m_GameC.GetElement(i,j);
			//将图片背景与掩码相或，边保留，图像区域为一；
			m_dcMem.BitBlt(nleft+j*nElemW,nTop+i*nElemH,nElemW,nElemH,&m_dcMask,0,nElemVal*nElemH,SRCPAINT);
			//与元素图片相与，边保留，图像区域为元素图片
			m_dcMem.BitBlt(nleft+j*nElemW,nTop+i*nElemH,nElemW,nElemH,&m_dcElement,0,nElemVal*nElemH,SRCAND);
		}
	}
}

bool CGameDlg::m_bFistPoint=true;
void CGameDlg::OnLButtonUp(UINT nFlags, CPoint point)  //消子阶段
{
	if(!isok)
		return ;
	//判断鼠标点击区域
	m_sizeElem.cy=40;
	m_sizeElem.cx=40;
	m_rtGameRect.left=0;
	m_rtGameRect.top=0;
	m_rtGameRect.right=20+16*40;
	m_rtGameRect.bottom=50+10*40;
	int row=(point.y-50)/m_sizeElem.cy;
	int col=(point.x-20)/m_sizeElem.cx;
	//判断点击的区域是否正确并执行相应的操作
	if (point.y<m_rtGameRect.top||point.y>m_rtGameRect.bottom||point.x<m_rtGameRect.left
		||point.x>m_rtGameRect.right||m_GameC.m_pGameMap[row][col]==BLANK)
	{
		return CDialogEx::OnLButtonUp(nFlags,point);
	}

	if (m_bFistPoint)//第一个点
	{
		DrawTipFrame(row,col);   //画矩形框
		m_GameC.SetFistPoint(row,col);
	}
	else
	{
		DrawTipFrame(row,col);  //画矩形框
		m_GameC.SetSecPoint(row,col);
		bool bSuc=m_GameC.Link(avPath,nVexnum);//判断是否可连通
		if (bSuc==true)
		{
			//画提示线
			DrawTipLine(avPath,nVexnum);
			//更新地图
			UpdateMapgame(avPath[0].row,avPath[0].col,avPath[nVexnum-1].row,avPath[nVexnum-1].col);
			if (flag==2)    //关卡模式下消一次加3s
			{
				TimeLeft=TimeLeft+3;
			}
		}
		Sleep(100);
		InvalidateRect(m_rtGameRect,FALSE);
		if (bSuc&&m_GameC.IsWin())  //如果在时间没有减少到-1的情况下消除所有的图篇，则判断胜利
		{
			KillTimer(1);
			AfxMessageBox(_T("恭喜过关！"), MB_OK);
			m_GameC.m_pGameMap = NULL;
			this->OnCancel();
			OnClose();	}
	}
	m_bFistPoint=!m_bFistPoint;
}

void CGameDlg::UpdateMapgame(int row1, int col1, int row2, int col2) //跟新地图操作
{
	HBITMAP Game_bg = (HBITMAP)LoadImage(AfxGetApp()->m_hInstance, _T("theme\\picture\\default_bg.bmp"), 
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);  //选中图片
	m_bg.SelectObject(Game_bg);
	//消除图片和它的掩码图片
	m_dcMem.BitBlt(20 + col1*40, 50 + row1*40, 40, 40, &m_bg, 20 + col1*40, 50 + row1*40, SRCCOPY);//
	m_dcMem.BitBlt(20 + col2*40, 50+ row2*40, 40, 40, &m_bg, 20 + col2*40, 50 + row2*40, SRCCOPY);
}



void CGameDlg::DrawTipFrame(int nRow, int nCol)                             //画图片的包围框
{
	CClientDC dc(this);
	CPen penFrame(PS_SOLID,2,RGB(233,43,43));                               //选择画笔颜色、种类
	 CPen *pOldPen = dc.SelectObject(&penFrame);
	 dc.SelectStockObject(NULL_BRUSH);                                      //画刷选择
	int nleft=20,ntop=50;
	dc.Rectangle( nleft + nCol*m_sizeElem.cx,ntop + nRow*m_sizeElem.cy,     //画矩形框
	nleft + nCol*m_sizeElem.cx + m_sizeElem.cy, ntop + nRow*m_sizeElem.cy + m_sizeElem.cy );
	dc.SelectObject(pOldPen);
}



void CGameDlg::DrawTipLine(Vertex  asvPath[4], int nVexnum)          //画提示线
{
	CClientDC dc(this);
	CPen penLine(PS_SOLID, 2, RGB(0, 255, 0));                      //选择画笔的种类、颜色
	CPen *pOldPen = dc.SelectObject(&penLine);                      //画两图片之间的连线
	dc.MoveTo(20 + asvPath[0].col*40 + 40 / 2, 50 + asvPath[0].row*40 + 40 / 2);
	for (int i = 1; i < nVexnum;i++)
	{
		dc.LineTo(20 + asvPath[i].col*40 + 40 / 2, 50 + asvPath[i].row*40 + 40 / 2);
	}
	dc.SelectObject(pOldPen);                                       //选中画笔
}






void CGameDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s1;
	if (nIDEvent==1&&TimeLeft!=-1)     //如果事件来源为1且时间不为-1
	{
		//将int类型转换为CString类型
		s1.Format(_T("倒计时:%d"),TimeLeft);  
		//输出此时时间
		GetDlgItem(IDC_EDIT2)->SetWindowTextW(s1);
		//刷新一次时间减少一秒
		--TimeLeft;                        
	}
	if (TimeLeft<0)   //如果时间小于0后，终止时间，此时算作游戏失败！
		{
			KillTimer(1);
			AfxMessageBox(_T("游戏失败！"), MB_OK);
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
	
	  
	// TODO: 在此添加控件通知处理程序代码
}




void CGameDlg::OnBnClickedButton3()
{
	bool flag = false;
	if (m_GameC.m_pGameMap==NULL)
	{
		AfxMessageBox(_T("请先开始游戏！"), true);
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
		AfxMessageBox(_T("游戏失败!"), MB_CANCELTRYCONTINUE);
	}
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
}


void CGameDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
