#pragma once
#include "UseDatabase.h"

// Registration_Successful �Ի���

class Registration_Successful : public CDialogEx
{
	DECLARE_DYNAMIC(Registration_Successful)

public:
	Registration_Successful(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Registration_Successful();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CREATE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonLaststep();
	afx_msg void OnBnClickedButtonFinish();
	CString rs_UesrName;
	CString rs_NewCode;
	CString rs_AgainCode;
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	UseDatabase dbRS;
	CString TableA ;
	CString Aid ;
	CString column;
	afx_msg void OnDestroy();
};
