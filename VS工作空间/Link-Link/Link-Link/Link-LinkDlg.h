
// Link-LinkDlg.h : ͷ�ļ�
//

#pragma once


// CLinkLinkDlg �Ի���
class CLinkLinkDlg : public CDialogEx
{
// ����
public:
	CLinkLinkDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LINKLINK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CDC m_dcMem;		//λͼ�ڴ�

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void InitBackground();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnBasic();
	afx_msg void OnClickedBtnRelex();
};
