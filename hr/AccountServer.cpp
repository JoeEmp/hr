// AccountServer.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "hr.h"
#include "AccountServer.h"
#include "afxdialogex.h"


// CAccountServer �Ի���

IMPLEMENT_DYNAMIC(CAccountServer, CDialogEx)

CAccountServer::CAccountServer(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_ACCOUNTSERVER, pParent)
	, AS_Code(_T(""))
	, AS_Account(_T(""))
{

}

CAccountServer::~CAccountServer()
{
}

void CAccountServer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_AS_EC, AS_Code);
	DDX_Control(pDX, IDC_LIST_AS, AS_List);
	DDX_Text(pDX, IDC_EDIT_AS_ACCOUNT, AS_Account);
}


BEGIN_MESSAGE_MAP(CAccountServer, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_AS, &CAccountServer::OnNMDblclkListAs)
	ON_BN_CLICKED(ID_ACCOUNT_UPDATE, &CAccountServer::OnBnClickedAccountUpdate)
END_MESSAGE_MAP()


// CAccountServer ��Ϣ�������


BOOL CAccountServer::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetDlgItem(IDC_EDIT_AS_ACCOUNT)->EnableWindow(FALSE);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CDialogEx::SetBackgroundImage(IDB_BITMAP_AS);
	AS_List.InsertColumn(0, _T("ua_id"), LVCFMT_CENTER, 0);
	AS_List.InsertColumn(1, _T("�˺�"), LVCFMT_CENTER, 100);
	AS_List.InsertColumn(2, _T("����"), LVCFMT_CENTER, 80);

	//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
	AS_List.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	db.InitDatabase();
	db.m_rs.Open(AFX_DB_USE_DEFAULT_TYPE, _T("select  *  from UserAccountInfo"));
	show();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}



void CAccountServer::show() {
	AS_List.DeleteAllItems();
	CString psd;
	while (db.m_rs.IsEOF() == 0) {
		int i = 0;
		for (int j = 0; j < 3; j++) {
			db.m_rs.GetFieldValue(j, psd);
			if (j == 0) {
				AS_List.InsertItem(i, psd);
			}
			AS_List.SetItemText(i, j, psd);
		}
		i++;
		db.m_rs.MoveNext();
	}
}

//˫��ĳ��
void CAccountServer::OnNMDblclkListAs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	index = AS_List.GetNextItem(-1, LVNI_SELECTED);
	//ѡ��
	if (index != -1) {
		AS_Code = AS_List.GetItemText(index, 2);
		AS_Account = AS_List.GetItemText(index, 1);
		ua_id = AS_List.GetItemText(index, 0);
		//		int i=_ttoi(ua_id);
		SetDlgItemText(IDC_EDIT_AS_EC, AS_Code);
		SetDlgItemText(IDC_EDIT_AS_ACCOUNT, AS_Account);

	}
	*pResult = 0;
}


void CAccountServer::OnBnClickedAccountUpdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString fenhao = _T("'");
	CString mid = _T("where ua_id = ");
	for_ua_id.Format(_T("%d"), _ttoi(ua_id));
	UpdateData(TRUE);
	CString sql("update [dbo].[UserAccountInfo] set [UA_Password]= '");
	sql = sql + AS_Code + fenhao + mid + for_ua_id;
	TRY
	{
		db.m_db.ExecuteSQL(sql);
	AS_List.SetItemText(index,2,AS_Code);
	}
		CATCH(CDBException, e)
	{
		//The error code is in e->m_nRetCode
		AfxMessageBox(_T("����ʧ��"), 0);
	}
	END_CATCH
}


