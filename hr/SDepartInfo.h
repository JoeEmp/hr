#pragma once
#include "UseDatabase.h"

// CSDepartInfo �Ի���

class CSDepartInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CSDepartInfo)

public:
	CSDepartInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSDepartInfo();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SDEPARTINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strBelongDepart;
	CString m_strComment;
	CString m_Name1;
	CString m_Name2;
	CString m_Name3;
	CString m_Name4;
	CString m_phone1;
	CString m_Phone2;
	CString m_Phone3;
	CString m_Phone4;
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();

	UseDatabase dbDepart;
	INFO        DepartInfo;
};
