// Ceo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "hr.h"
#include "Ceo.h"
#include "afxdialogex.h"

#include "hrDlg.h"
#include "Change_Password.h"
#include  "PersonalInfo.h"
#include  "CeoSM_Inquire.h"


// CCeo �Ի���

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


// CCeo ��Ϣ�������

//�����ʼ��
BOOL CCeo::OnInitDialog()
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
void CCeo::OnBnClickedButtonLogout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(0);
	ChrDlg dlg;
	dlg.DoModal();
}

//�޸�����
void CCeo::OnBnClickedButtonEc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Change_Password dlg;
	dlg.DoModal();
}




void CCeo::OnClickedButtonInfomanage()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPersonalInfo dlg;
	dlg.DoModal();
}


void CCeo::OnClickedButtonCManagedepartment()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CCeoSM_Inquire dlg;
	dlg.DoModal();
}

