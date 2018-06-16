#pragma once


#include "UseDatabase.h"
#include "afxwin.h"
#include "CeoSM_Inquire.h"






// CPersonalInfo 对话框


class CPersonalInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CPersonalInfo)

public:
	CPersonalInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPersonalInfo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PERSONALINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonCancelupdate();
	afx_msg void OnClickedButtonComfirm();
	virtual BOOL OnInitDialog();

	CComboBox m_combox_Depart1;
	CString m_strDepart1;
	CString m_strMarriage;
	CComboBox m_combox_Position;
	CString m_strPosi1;
	CComboBox m_combox_Sex;
	CString m_strSex;
	CString m_strAddress;
	CString m_strBirthday1;
	CString m_strBornplace1;
	CString m_strEduBG;
	CString m_strEntrytime;
	CString m_strId;
	CString m_strMajor;
	CString m_strName;
	CString m_strPs;
	CString m_strSpeciality;
	CString m_strTelephone;
	CString m_strUniversity;

	UseDatabase dbP;
	INFO      PINFO;
	CCeoSM_Inquire *m_pInquery;
	
};
