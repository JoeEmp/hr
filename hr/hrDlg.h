
// hrDlg.h : 头文件
//

#pragma once

#include "UseDatabase.h"




// ChrDlg 对话框
class ChrDlg : public CDialogEx
{
// 构造
public:
	ChrDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedButtonLogin();
	afx_msg void OnBnClickedButtonRegister();
	
	
	//用于账号密码的变量
	CString m_UserName;
	CString m_Passkey;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//定义该类指针方便hrDlg使用该类的操作
	UseDatabase db;
	afx_msg void OnDestroy();
};
