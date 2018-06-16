#pragma once

// CSuperManager 对话框

class CSuperManager : public CDialogEx
{
	DECLARE_DYNAMIC(CSuperManager)

public:
	CSuperManager(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSuperManager();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SUPERMANAGER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonLogout();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonEc();
	afx_msg void OnBnClickedButtonSmManagestaff();
	afx_msg void OnClickedButtonSmManagedepartment();
	afx_msg void OnClickedButtonSmManageserver();
};
