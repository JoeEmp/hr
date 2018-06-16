#pragma once
#include "afxcmn.h"
#include "UseDatabase.h"


// CAccountServer 对话框

class CAccountServer : public CDialogEx
{
	DECLARE_DYNAMIC(CAccountServer)

public:
	CAccountServer(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAccountServer();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ACCOUNTSERVER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
