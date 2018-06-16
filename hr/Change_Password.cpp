// Change_Password.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "hr.h"

#include "Change_Password.h"
#include "afxdialogex.h"


// Change_Password �Ի���

IMPLEMENT_DYNAMIC(Change_Password, CDialogEx)

Change_Password::Change_Password(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_EC, pParent)
	, m_OldPassWord(_T(""))
	, m_NewPassWord(_T(""))
	, m_AgainPassWord(_T(""))
{

}

Change_Password::~Change_Password()
{
}

void Change_Password::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OLDCODE, m_OldPassWord);
	DDX_Text(pDX, IDC_EDIT_NEWCODE, m_NewPassWord);
	DDX_Text(pDX, IDC_EDIT_AGAINCODE, m_AgainPassWord);
}


BEGIN_MESSAGE_MAP(Change_Password, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_RETURN, &Change_Password::OnBnClickedButtonReturn)
	ON_BN_CLICKED(IDC_BUTTON_ENSURE, &Change_Password::OnBnClickedButtonEnsure)
//	ON_WM_DESTROY()
END_MESSAGE_MAP()


// Change_Password ��Ϣ�������

//�����ʼ��
BOOL Change_Password::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CDialogEx::SetBackgroundImage(IDB_BITMAP_PWD);
	CString CurrentAccount = SaveUserName;
	id = dbC.FindIdbyAccount(CurrentAccount);
	column = ("Pwd");
	CString Pwd = dbC.QueryById(id,column);
    GetDlgItem(IDC_EDIT_OLDCODE)->SetWindowTextW(Pwd);
	//ͼ����ʾ
	ModifyStyleEx(0, WS_EX_APPWINDOW);
	ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

//���ذ�ť
void Change_Password::OnBnClickedButtonReturn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(0);
}

//ȷ���޸İ�ť P.S(���ܴ��������)
void Change_Password::OnBnClickedButtonEnsure()
{
	UpdateData(TRUE);
	if (m_NewPassWord == "")
	{
		CString title("����");
		CString error(" �����벻��Ϊ�� ");
		MessageBox(error, title, MB_OK);
	}
	else
	{
		if (m_NewPassWord == m_AgainPassWord)
		{
			CString title("ע��");
			CString error(" �Ƿ�ȷ���޸����� ");
			if (Change_Password::MessageBox(error, title, MB_OKCANCEL) == IDOK)
			{
				dbC.ChangPwd(id, m_NewPassWord);
			
				CString title("�޸ĳɹ�");
				CString error(" �������ڸ��˺�ע������Ч ");
				MessageBox(error, title, MB_OK);	
				EndDialog(0);
			}
			else
			{
				EndDialog(0);
				Change_Password dlg;
				dlg.DoModal();
			}

		}
		else
		{
			CString title("����");
			CString error(" ������������벻һ�� ");
			MessageBox(error, title, MB_OK);
			EndDialog(0);
			Change_Password dlg;
			dlg.DoModal();
		}
	}
	
}	






BOOL Change_Password::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:    // ���λس�
			OnBnClickedButtonEnsure();
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

