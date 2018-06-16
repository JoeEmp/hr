// SuperManager.cpp : 实现文件
//

#include "stdafx.h"
#include "hr.h"
#include "SuperManager.h"
#include "afxdialogex.h"

#include "hrDlg.h"
#include "Change_Password.h"
#include "CeoSM_Inquire.h"
#include  "PersonalInfo.h"
#include "AccountServer.h"


// CSuperManager 对话框

IMPLEMENT_DYNAMIC(CSuperManager, CDialogEx)

CSuperManager::CSuperManager(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_SUPERMANAGER, pParent)
{
}

CSuperManager::~CSuperManager()
{
}

void CSuperManager::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSuperManager, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOGOUT, &CSuperManager::OnBnClickedButtonLogout)
	ON_BN_CLICKED(IDC_BUTTON_EC, &CSuperManager::OnBnClickedButtonEc)
	ON_BN_CLICKED(IDC_BUTTON_SM_MANAGESTAFF, &CSuperManager::OnBnClickedButtonSmManagestaff)
	ON_BN_CLICKED(IDC_BUTTON_SM_MANAGEDEPARTMENT, &CSuperManager::OnClickedButtonSmManagedepartment)
	ON_BN_CLICKED(IDC_BUTTON_SM_MANAGESERVER, &CSuperManager::OnClickedButtonSmManageserver)
END_MESSAGE_MAP()


// CSuperManager 消息处理程序

//界面初始化
BOOL CSuperManager::OnInitDialog()
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

//注销
void CSuperManager::OnBnClickedButtonLogout()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
	ChrDlg dlg;
	dlg.DoModal();
}

//修改密码
void CSuperManager::OnBnClickedButtonEc()
{
	// TODO: 在此添加控件通知处理程序代码
	Change_Password dlg;
	dlg.DoModal();
}

//管理员工
void CSuperManager::OnBnClickedButtonSmManagestaff()
{
	// TODO: 在此添加控件通知处理程序代码
	CCeoSM_Inquire dlg;
	dlg.DoModal();
}


void CSuperManager::OnClickedButtonSmManagedepartment()
{
	// TODO: 在此添加控件通知处理程序代码
	CPersonalInfo dlg;
	dlg.DoModal();
}


void CSuperManager::OnClickedButtonSmManageserver()
{
	// TODO: 在此添加控件通知处理程序代码
	CAccountServer dlg;
	dlg.DoModal();
}
