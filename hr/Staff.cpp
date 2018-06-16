// Staff.cpp : 实现文件
//

#include "stdafx.h"
#include "hr.h"
#include "Staff.h"
#include "afxdialogex.h"

#include "Change_Password.h"
#include "hrDlg.h"
#include  "PersonalInfo.h"
#include  "SDepartInfo.h"

// CStaff 对话框

IMPLEMENT_DYNAMIC(CStaff, CDialogEx)

CStaff::CStaff(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_STAFF, pParent)
{
}

CStaff::~CStaff()
{
}

void CStaff::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}



BEGIN_MESSAGE_MAP(CStaff, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_EC, &CStaff::OnBnClickedButtonEc)
	ON_BN_CLICKED(IDC_BUTTON_LOGOUT, &CStaff::OnBnClickedButtonLogout)
	ON_BN_CLICKED(IDC_BUTTON_PERSONALINFO, &CStaff::OnClickedButtonPersonalinfo)
	ON_BN_CLICKED(IDC_BUTTON_DEPARTINFO, &CStaff::OnClickedButtonDepartinfo)
//	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CStaff 消息处理程序

//界面初始化
BOOL CStaff::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CDialogEx::SetBackgroundImage(IDB_BITMAP_SM);
	//图标显示
	ModifyStyleEx(0, WS_EX_APPWINDOW);
	ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

//修改密码
void CStaff::OnBnClickedButtonEc()
{
	// TODO: 在此添加控件通知处理程序代码
	Change_Password dlg;
	dlg.DoModal();

}

//注销
void CStaff::OnBnClickedButtonLogout()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
	ChrDlg dlg;
	dlg.DoModal();
}





void CStaff::OnClickedButtonPersonalinfo()
{
	// TODO: 在此添加控件通知处理程序代码
	CPersonalInfo dlg;
	dlg.DoModal();
}


void CStaff::OnClickedButtonDepartinfo()
{
	// TODO: 在此添加控件通知处理程序代码
	CSDepartInfo dlg;
	dlg.DoModal();
}


