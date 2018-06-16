#pragma once
#include "afxcmn.h"
#include "UseDatabase.h"


// CAccountServer �Ի���

class CAccountServer : public CDialogEx
{
	DECLARE_DYNAMIC(CAccountServer)

public:
	CAccountServer(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAccountServer();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ACCOUNTSERVER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString AS_Code;
	CListCtrl AS_List;
	virtual BOOL OnInitDialog();
	UseDatabase db;
	void show();

	afx_msg void OnNMDblclkListAs(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedAccountUpdate();
	CString AS_Account;
	CString ua_id;
	CString   for_ua_id;
	int index;
};
