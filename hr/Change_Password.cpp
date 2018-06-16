// Change_Password.cpp : 实现文件
//

#include "stdafx.h"
#include "hr.h"

#include "Change_Password.h"
#include "afxdialogex.h"


// Change_Password 对话框

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


// Change_Password 消息处理程序

//界面初始化
BOOL Change_Password::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CDialogEx::SetBackgroundImage(IDB_BITMAP_PWD);
	CString CurrentAccount = SaveUserName;
	id = dbC.FindIdbyAccount(CurrentAccount);
	column = ("Pwd");
	CString Pwd = dbC.QueryById(id,column);
    GetDlgItem(IDC_EDIT_OLDCODE)->SetWindowTextW(Pwd);
	//图标显示
	ModifyStyleEx(0, WS_EX_APPWINDOW);
	ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

//返回按钮
void Change_Password::OnBnClickedButtonReturn()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}

//确认修改按钮 P.S(功能代码待补充)
void Change_Password::OnBnClickedButtonEnsure()
{
	UpdateData(TRUE);
	if (m_NewPassWord == "")
	{
		CString title("错误");
		CString error(" 新密码不能为空 ");
		MessageBox(error, title, MB_OK);
	}
	else
	{
		if (m_NewPassWord == m_AgainPassWord)
		{
			CString title("注意");
			CString error(" 是否确定修改密码 ");
			if (Change_Password::MessageBox(error, title, MB_OKCANCEL) == IDOK)
			{
				dbC.ChangPwd(id, m_NewPassWord);
			
				CString title("修改成功");
				CString error(" 新密码在该账号注销后生效 ");
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
			CString title("错误");
			CString error(" 两次输入的密码不一致 ");
			MessageBox(error, title, MB_OK);
			EndDialog(0);
			Change_Password dlg;
			dlg.DoModal();
		}
	}
	
}	






BOOL Change_Password::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:    // 屏蔽回车
			OnBnClickedButtonEnsure();
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

