#pragma once

// CManager �Ի���

class CManager : public CDialogEx
{
	DECLARE_DYNAMIC(CManager)

public:
	CManager(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CManager();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MANAGER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonEc();
	afx_msg void OnBnClickedButtonLogout();
	afx_msg void OnClickedButtonMManagestaff();
	afx_msg void OnClickedButtonMManagedeparment();

};
