#pragma once
// CCeo �Ի���

class CCeo : public CDialogEx
{
	DECLARE_DYNAMIC(CCeo)

public:
	CCeo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCeo();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CEO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonLogout();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonEc();
	afx_msg void OnClickedButtonInfomanage();
	afx_msg void OnClickedButtonCManagedepartment();

};
