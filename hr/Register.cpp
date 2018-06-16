// Register.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "hr.h"
#include "Register.h"
#include "afxdialogex.h"
#include "Registration_Successful.h"
#include "hrDlg.h"


// Register �Ի���

IMPLEMENT_DYNAMIC(Register, CDialogEx)

Register::Register(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_REGISTER, pParent)
	, m_Address(_T(""))
	, m_Birthday(_T(""))
	, m_id(_T(""))
	, m_Name(_T(""))
	, m_Telphonne(_T(""))
	, m_Marriage(_T("δ��"))
	, m_Bornplace(_T(""))
	, m_EduBG(_T(""))
	, m_Entrytime(_T(""))
	, m_Major(_T(""))
	, m_University(_T(""))
	, m_strDepart(_T("������"))
	, m_strPosi(_T("Ա��"))
	, m_strSex(_T("��"))
{

}

Register::~Register()
{
}

void Register::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_DEPARTMENT, m_Department);
	DDX_Control(pDX, IDC_COMBO_POSITION, m_Position);
	DDX_Control(pDX, IDC_COMBO_SEX, m_Sex);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_Address);
	DDX_Text(pDX, IDC_EDIT_BIRTHDAY, m_Birthday);
	DDX_Text(pDX, IDC_EDIT_IDCARD, m_id);
	DDX_Text(pDX, IDC_EDIT_NAME, m_Name);
	DDX_Text(pDX, IDC_EDIT_PS, m_Ps);
	DDX_Text(pDX, IDC_EDIT_SPECIALITY, m_Speciality);
	DDX_Text(pDX, IDC_EDIT_TELPHONE, m_Telphonne);
	DDX_Text(pDX, IDC_EDIT_BORNPLACE, m_Bornplace);
	DDX_CBString(pDX, IDC_COMBO_MARRIAGE, m_Marriage);
	DDX_Text(pDX, IDC_EDIT_EDU_BACKGROUND, m_EduBG);
	DDX_Text(pDX, IDC_EDIT_ENTRYTIME, m_Entrytime);
	DDX_Text(pDX, IDC_EDIT_MAJOR, m_Major);
	DDX_Text(pDX, IDC_EDIT_UNIVERSITY, m_University);
	DDX_CBString(pDX, IDC_COMBO_DEPARTMENT, m_strDepart);
	DDX_Control(pDX, IDC_COMBO_MARRIAGE, m_CMarriage);
	DDX_CBString(pDX, IDC_COMBO_POSITION, m_strPosi);
	DDX_CBString(pDX, IDC_COMBO_SEX, m_strSex);
}


BEGIN_MESSAGE_MAP(Register, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &Register::OnBnClickedButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_RETURN, &Register::OnBnClickedButtonReturn)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// Register ��Ϣ�������


void Register::OnBnClickedButtonNext()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	EndDialog(0);
	UpdateData(TRUE);
	CString RRet = dbR.Registeration(m_Name, m_strSex, m_Marriage,m_Bornplace, m_Birthday, m_University, m_Major,m_id, m_EduBG, m_Telphonne, m_Entrytime, m_strPosi, m_strDepart, m_Address, m_Speciality, m_Ps);
	if (RRet == "OK")
	{
		 Registration_Successful dlg;
		dlg.DoModal();
	}
	else if (RRet == "ERROR")
	{
		CString title("д������ʧ��");
		CString error(" �����Ƿ��б�Ҫ��д����δ��д����δ���ո�ʽ��д ");
		MessageBox(error, title, MB_OK);
		Register dlg;
		dlg.DoModal();
	}
	else
	{
		CString title("����");
		CString error(" ע����� ");
		MessageBox(error, title, MB_OK);
		Register dlg;
		dlg.DoModal();
	}
	
}


void Register::OnBnClickedButtonReturn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(0);
	ChrDlg dlg;
	dlg.DoModal();
}



BOOL Register::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CDialogEx::SetBackgroundImage(IDB_BITMAP_PI);
	dbR.InitDatabase();
	//ͼ����ʾ
	ModifyStyleEx(0, WS_EX_APPWINDOW);
	ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


BOOL Register::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:    // ���λس�
			OnBnClickedButtonNext();
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}



void Register::OnDestroy()
{
	
	// TODO: �ڴ˴������Ϣ����������
	EndDialog(0);
	ChrDlg dlg;
	dlg.DoModal();
}
