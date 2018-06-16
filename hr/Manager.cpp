// Manager.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "hr.h"
#include "Manager.h"
#include "afxdialogex.h"

#include "hrDlg.h"
#include "Change_Password.h"
#include  "PersonalInfo.h"
#include  "CeoSM_Inquire.h"


// CManager �Ի���

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


// CManager ��Ϣ�������

//�����ʼ��
BOOL CManager::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//saveUserNameM = m_phrDlg->m_UserName;
	CDialogEx::SetBackgroundImage(IDB_BITMAP_SM);
	//ͼ����ʾ
	ModifyStyleEx(0, WS_EX_APPWINDOW);
	ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

//�޸�����
void CManager::OnBnClickedButtonEc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Change_Password dlg;
	dlg.DoModal();
}

//ע��
void CManager::OnBnClickedButtonLogout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(0);
	ChrDlg dlg;
	dlg.DoModal();
}


void CManager::OnClickedButtonMManagestaff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPersonalInfo dlg;
	dlg.DoModal();
}


void CManager::OnClickedButtonMManagedeparment()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CCeoSM_Inquire dlg;
	dlg.DoModal();
}
