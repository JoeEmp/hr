// Staff.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "hr.h"
#include "Staff.h"
#include "afxdialogex.h"

#include "Change_Password.h"
#include "hrDlg.h"
#include  "PersonalInfo.h"
#include  "SDepartInfo.h"

// CStaff �Ի���

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


// CStaff ��Ϣ�������

//�����ʼ��
BOOL CStaff::OnInitDialog()
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

//�޸�����
void CStaff::OnBnClickedButtonEc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Change_Password dlg;
	dlg.DoModal();

}

//ע��
void CStaff::OnBnClickedButtonLogout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(0);
	ChrDlg dlg;
	dlg.DoModal();
}





void CStaff::OnClickedButtonPersonalinfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPersonalInfo dlg;
	dlg.DoModal();
}


void CStaff::OnClickedButtonDepartinfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSDepartInfo dlg;
	dlg.DoModal();
}


