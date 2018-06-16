// Manager.cpp : 实现文件
//

#include "stdafx.h"
#include "hr.h"
#include "Manager.h"
#include "afxdialogex.h"

#include "hrDlg.h"
#include "Change_Password.h"
#include  "PersonalInfo.h"
#include  "CeoSM_Inquire.h"


// CManager 对话框

IMPLEMENT_DYNAMIC(CManager, CDialogEx)

CManager::CManager(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_MANAGER, pParent)
{
}

CManager::~CManager()
{
}

void CManager::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CManager, CDialogEx)
	
	ON_BN_CLICKED(IDC_BUTTON_EC, &CManager::OnBnClickedButtonEc)
	ON_BN_CLICKED(IDC_BUTTON_LOGOUT, &CManager::OnBnClickedButtonLogout)
	ON_BN_CLICKED(IDC_BUTTON_M_MANAGESTAFF, &CManager::OnClickedButtonMManagestaff)
	ON_BN_CLICKED(IDC_BUTTON_M_MANAGEDEPARMENT, &CManager::OnClickedButtonMManagedeparment)
END_MESSAGE_MAP()


// CManager 消息处理程序

//界面初始化
BOOL CManager::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//saveUserNameM = m_phrDlg->m_UserName;
	CDialogEx::SetBackgroundImage(IDB_BITMAP_SM);
	//图标显示
	ModifyStyleEx(0, WS_EX_APPWINDOW);
	ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

//修改密码
void CManager::OnBnClickedButtonEc()
{
	// TODO: 在此添加控件通知处理程序代码
	Change_Password dlg;
	dlg.DoModal();
}

//注销
void CManager::OnBnClickedButtonLogout()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
	ChrDlg dlg;
	dlg.DoModal();
}


void CManager::OnClickedButtonMManagestaff()
{
	// TODO: 在此添加控件通知处理程序代码
	CPersonalInfo dlg;
	dlg.DoModal();
}


void CManager::OnClickedButtonMManagedeparment()
{
	// TODO: 在此添加控件通知处理程序代码
	CCeoSM_Inquire dlg;
	dlg.DoModal();
}
