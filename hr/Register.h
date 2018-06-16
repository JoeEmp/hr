#pragma once
#include "afxwin.h"
#include "ATLComTime.h"
#include "UseDatabase.h"


// Register �Ի���

class Register : public CDialogEx
{
	DECLARE_DYNAMIC(Register)

public:
	Register(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Register();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_REGISTER };
#endif

protected:
//	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonNext();
	afx_msg void OnBnClickedButtonReturn();

	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void DoDataExchange(CDataExchange* pDX);

	CComboBox m_Department;
	CComboBox m_Position;
	CComboBox m_Sex;
	CString m_Address;
	CString m_Birthday;
	CString m_id;
	CString m_Name;
	CString m_Ps;
	CString m_Speciality;
	CString m_Telphonne;
	CString m_Bornplace;
	CString m_Marriage;
	CString m_EduBG;
	CString m_Entrytime;
	CString m_Major;
	CString m_University;
	CString m_strDepart;
	CComboBox m_CMarriage;
	CString m_strPosi;
	CString m_strSex;

	UseDatabase dbR;
	afx_msg void OnDestroy();
};
