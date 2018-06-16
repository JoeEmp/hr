// Ceo.cpp : 实现文件
//

#include "stdafx.h"
#include "hr.h"
#include "Ceo.h"
#include "afxdialogex.h"

#include "hrDlg.h"
#include "Change_Password.h"
#include  "PersonalInfo.h"
#include  "CeoSM_Inquire.h"


// CCeo 对话框

IMPLEMENT_DYNAMIC(CCeo, CDialogEx)

CCeo::CCeo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CEO, pParent)
{
}

CCeo::~CCeo()
{
}

void CCeo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCeo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOGOUT, &CCeo::OnBnClickedButtonLogout)
	ON_BN_CLICKED(IDC_BUTTON_EC, &CCeo::OnBnClickedButtonEc)
	ON_BN_CLICKED(IDC_BUTTON_INFOMANAGE, &CCeo::OnClickedButtonInfomanage)
	ON_BN_CLICKED(IDC_BUTTON_C_MANAGEDEPARTMENT, &CCeo::OnClickedButtonCManagedepartment)
END_MESSAGE_MAP()


// CCeo 消息处理程序

//界面初始化
BOOL CCeo::OnInitDialog()
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
void CCeo::OnBnClickedButtonLogout()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
	ChrDlg dlg;
	dlg.DoModal();
}

//修改密码
void CCeo::OnBnClickedButtonEc()
{
	// TODO: 在此添加控件通知处理程序代码
	Change_Password dlg;
	dlg.DoModal();
}




void CCeo::OnClickedButtonInfomanage()
{
	// TODO: 在此添加控件通知处理程序代码
	CPersonalInfo dlg;
	dlg.DoModal();
}


void CCeo::OnClickedButtonCManagedepartment()
{
	// TODO: 在此添加控件通知处理程序代码
	CCeoSM_Inquire dlg;
	dlg.DoModal();
}

