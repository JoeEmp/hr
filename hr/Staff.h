#pragma once
#include "hrDlg.h"

// CStaff �Ի���

class CStaff : public CDialogEx
{
	DECLARE_DYNAMIC(CStaff)

public:
	CStaff(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStaff();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_STAFF };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonEc();
	afx_msg void OnBnClickedButtonLogout();
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButtonPersonalinfo();
	afx_msg void OnClickedButtonDepartinfo();

};
