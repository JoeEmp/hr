#pragma once
#include "hrDlg.h"

// Change_Password �Ի���

class Change_Password : public CDialogEx
{
	DECLARE_DYNAMIC(Change_Password)

public:
	Change_Password(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Change_Password();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_OldPassWord;
	CString m_NewPassWord;
	CString m_AgainPassWord;
	afx_msg void OnBnClickedButtonReturn();
	afx_msg void OnBnClickedButtonEnsure();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	ChrDlg pHrDlg;
	UseDatabase dbC;
	CString column;
	int id;
//	afx_msg void OnDestroy();
};
