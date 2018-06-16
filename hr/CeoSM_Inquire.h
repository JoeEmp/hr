#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "UseDatabase.h"


// CCeoSM_Inquire 对话框

class CCeoSM_Inquire : public CDialogEx
{
	DECLARE_DYNAMIC(CCeoSM_Inquire)

public:
	CCeoSM_Inquire(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCeoSM_Inquire();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CEOSM_INQUIRE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//	CListCtrl CM_StaffDataDisplay;
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonIReturn();
	afx_msg void OnBnClickedButtonDeletedata();
	afx_msg void OnBnClickedButtonUpdatedata();
	afx_msg void OnBnClickedButtonIceoInquire();
	CListBox *pList;
//	CListCtrl CM_listStaffDataDisplay;
	CString CM_Name;
	CString CM_Birthday;
	CString CM_Account;
	CString CM_Sex;
	CString CM_Position;
	CString CM_Department;

	CString ua_id;
	INFO     query;
	UseDatabase db;
	void ShowData();
	int update_flag;
	CListCtrl CM_listStaffDataDisplay;
	afx_msg void OnLvnItemchangedListIceoStaffdatadisplay(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkListIceoStaffdatadisplay(NMHDR *pNMHDR, LRESULT *pResult);
};
