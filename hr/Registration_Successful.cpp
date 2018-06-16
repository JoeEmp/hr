// Registration_Successful.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "hr.h"
#include "Registration_Successful.h"
#include "afxdialogex.h"

#include "Register.h"
#include "hrDlg.h"

// Registration_Successful �Ի���

IMPLEMENT_DYNAMIC(Registration_Successful, CDialogEx)

Registration_Successful::Registration_Successful(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CREATE, pParent)
	, rs_UesrName(_T(""))
	, rs_NewCode(_T(""))
	, rs_AgainCode(_T(""))
{

}

Registration_Successful::~Registration_Successful()
{
}

void Registration_Successful::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_UesrName, rs_UesrName);
	DDX_Text(pDX, IDC_EDIT_NEWCODE, rs_NewCode);
	DDX_Text(pDX, IDC_EDIT_AGAINCODE, rs_AgainCode);
}


BEGIN_MESSAGE_MAP(Registration_Successful, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LASTSTEP, &Registration_Successful::OnBnClickedButtonLaststep)
	ON_BN_CLICKED(IDC_BUTTON_FINISH, &Registration_Successful::OnBnClickedButtonFinish)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// Registration_Successful ��Ϣ�������


void Registration_Successful::OnBnClickedButtonLaststep()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(0);
	Aid = ("UA_id");
	CString TableA("UserAccountInfo"), TableInfo("UserInformation");
	CString Aid("UA_id"), Infoid("UI_id");
	int LastAId = dbRS.GetLastRecord(TableA, Aid);
	int LastInfoId = dbRS.GetLastRecord(TableInfo, Infoid);
	dbRS.DeleteRecord(LastInfoId, TableInfo);
	dbRS.DeleteRecord(LastAId, TableA);
	Register dlg;
	dlg.DoModal();
}

//��ɰ�ť
void Registration_Successful::OnBnClickedButtonFinish()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(0);
	UpdateData(TRUE);
	int LastNewId = dbRS.GetLastRecord(TableA, Aid);
	if (rs_NewCode == "")
	{
		CString title("����");
		CString error(" �����벻��Ϊ�� ");
		MessageBox(error, title, MB_OK);
	}
	else
	{
	if (rs_NewCode == rs_AgainCode)
		{
			CString title("ע��");
			CString error(" �Ƿ�ȷ���޸����� ");
			if (Registration_Successful::MessageBox(error, title, MB_OKCANCEL) == IDOK)
			{
				dbRS.ChangPwd(LastNewId, rs_NewCode);
			}
			else
			{
				Registration_Successful dlg;
				dlg.DoModal();
			}
		
		}
		else
		{
			CString title("����");
			CString error(" ������������벻һ�� ");
			MessageBox(error, title, MB_OK);
			Registration_Successful dlg;
			dlg.DoModal();
		}
	}
	CString title("ע��ɹ�");
	CString error(" ��� OK ���ص�¼���� ");
	MessageBox(error, title, MB_OK);
	ChrDlg dlg;
	dlg.DoModal();
}


BOOL Registration_Successful::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	dbRS.InitDatabase();
	CDialogEx::SetBackgroundImage(IDB_BITMAP_PWD);
	column = ("Account");
	Aid = ("UA_id");
	TableA = ("UserAccountInfo");
	int LastNewId = dbRS.GetLastRecord(TableA,Aid);
	CString Account = dbRS.QueryById(LastNewId, column);
	GetDlgItem(IDC_STATIC_UesrName)->SetWindowTextW(Account);
	
	//ͼ����ʾ
	ModifyStyleEx(0, WS_EX_APPWINDOW);
	ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


BOOL Registration_Successful::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:    // ���λس�
			OnBnClickedButtonFinish();
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void Registration_Successful::OnDestroy()
{
	EndDialog(0);
	Aid = ("UA_id");
	CString TableA("UserAccountInfo"), TableInfo("UserInformation");
	CString Aid("UA_id"), Infoid("UI_id");
	int LastAId = dbRS.GetLastRecord(TableA, Aid);
	int LastInfoId = dbRS.GetLastRecord(TableInfo, Infoid);
	dbRS.DeleteRecord(LastInfoId, TableInfo);
	dbRS.DeleteRecord(LastAId, TableA);
	ChrDlg dlg;
	dlg.DoModal();
}
