// SuperManager.cpp : ʵ���ļ�
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


// CSuperManager �Ի���

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


// CSuperManager ��Ϣ�������

//�����ʼ��
BOOL CSuperManager::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CDialogEx::SetBackgroundImage(IDB_BITMAP_SM);
	//ͼ����ʾ
	ModifyStyleEx(0, WS_EX_APPWINDOW);
	ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

//ע��
void CSuperManager::OnBnClickedButtonLogout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(0);
	ChrDlg dlg;
	dlg.DoModal();
}

//�޸�����
void CSuperManager::OnBnClickedButtonEc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Change_Password dlg;
	dlg.DoModal();
}

//����Ա��
void CSuperManager::OnBnClickedButtonSmManagestaff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CCeoSM_Inquire dlg;
	dlg.DoModal();
}


void CSuperManager::OnClickedButtonSmManagedepartment()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPersonalInfo dlg;
	dlg.DoModal();
}


void CSuperManager::OnClickedButtonSmManageserver()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAccountServer dlg;
	dlg.DoModal();
}
