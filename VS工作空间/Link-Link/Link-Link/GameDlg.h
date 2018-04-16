#pragma once
#include "afxwin.h"
#include "GameControl.h"



// CGameDlg �Ի���

class CGameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameDlg)

public:
	CGameDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGameDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAME_DIDLOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	void InitElement();//��ʼ��Ԫ��ͼƬ��DC
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();//���ڳ�ʼ������
	afx_msg void OnPaint();//WM_PAINT����
	afx_msg void OnClickedBtnStart();//��ʼ��ť
	void UpdataWindow();//���½���
	void InitBackground();//��ʼ�����ڱ���
	void UpdataMap();	// ������Ϸ��ͼ
	int flag;//ģʽ��־
private:
	HICON m_hIcon;//ͼ��
	CDC m_bg;
	CDC m_dcMem;//�ڴ�DC
	CDC m_dcBG;//����DC
	CDC m_dcElement;//Ԫ���ڴ�DC
	CDC m_dcMask;//�����ڴ�DC
	CPoint m_ptGameTop;//��Ϸ����ʼ�㣨��Ϸ��һ��ͼƬ�Ķ������꣬��������ڴ��ڿͻ�����
	CPoint m_ptFirstPoint;
	CSize m_sizeElem;//Ԫ��ͼƬ��С
	CRect m_rtGameRect;//��Ϸ�����С��������Ϊ��Ϸ���������С�����ǵ����滭���ߣ����ܻᳬ��ͼƬ����һ����Χ��
	CGameControl m_GameC;//��Ϸ������
	CProgressCtrl *timeProgress;
	bool m_bFirstPoint; //��־λ����ʶ�Ƿ��ǵ�һ���㣬true��ʾ�ǵ�һ�ε����false��ʾ�ǵڶ��ε����
	bool m_bPlaying;//��Ϸ״̬��ʶ
	bool m_bPause;
	Vertex avPath[4];
	int nVexnum;
	int timeLeft;
	Vertex m_tipVx1;		//������ʾ��
	Vertex m_tipVx2;
	int lastTime;  //�ϴ�����ʱ��
public:
	afx_msg void OnClose();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	void DrawTipFrame(int nRow, int nCol);// ���ƾ�����ʾ��
	void DrawTipLine(Vertex asvPath[4], int nVexnum);//��������
	void UpdataMapGame(Vertex V1, Vertex V2);// ��Ϸ�и��µ�ͼ	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClickedBtnPause();
	afx_msg void OnClickedBtnBackmain();
	// ��յ�ͼ
	void ClearMap();
	afx_msg void OnClickedBtnReareange();
	// ������ʾ
	bool LinkTip();
};