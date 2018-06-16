#pragma once
#include "hrDlg.h"

// CStaff 对话框

class CStaff : public CDialogEx
{
	DECLARE_DYNAMIC(CStaff)

public:
	CStaff(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStaff();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_STAFF };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonEc();
	afx_msg void OnBnClickedButtonLogout();
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButtonPersonalinfo();
	afx_msg void OnClickedButtonDepartinfo();

};
