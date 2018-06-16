
// hrDlg.h : ͷ�ļ�
//

#pragma once

#include "UseDatabase.h"




// ChrDlg �Ի���
class ChrDlg : public CDialogEx
{
// ����
public:
	ChrDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedButtonLogin();
	afx_msg void OnBnClickedButtonRegister();
	
	
	//�����˺�����ı���
	CString m_UserName;
	CString m_Passkey;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//�������ָ�뷽��hrDlgʹ�ø���Ĳ���
	UseDatabase db;
	afx_msg void OnDestroy();
};
