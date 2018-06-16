// CeoSM_Inquire.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "hr.h"
#include "CeoSM_Inquire.h"
#include "afxdialogex.h"
#include "PersonalInfo.h"


// CCeoSM_Inquire �Ի���

IMPLEMENT_DYNAMIC(CCeoSM_Inquire, CDialogEx)

CCeoSM_Inquire::CCeoSM_Inquire(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CEOSM_INQUIRE, pParent)
	, CM_Name(_T(""))
	, CM_Birthday(_T(""))
	, CM_Account(_T(""))
	, CM_Sex(_T(""))
	, CM_Position(_T(""))
	, CM_Department(_T(""))
{

}

CCeoSM_Inquire::~CCeoSM_Inquire()
{
}

void CCeoSM_Inquire::DoDataExchange(CDataExchange* pDX)
{	
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ICEO_STAFFDATADISPLAY, CM_listStaffDataDisplay);
	DDX_CBString(pDX, IDC_COMBO_CM_I_SEX, CM_Sex);
	DDX_CBString(pDX, IDC_COMBO_CM_I_POSITION, CM_Position);
	DDX_CBString(pDX, IDC_COMBO_CM_I_DEPARTMENT, CM_Department);
	DDX_Text(pDX, IDC_EDIT_CM_I_ACCOUNT, CM_Account);
	DDX_Text(pDX, IDC_EDIT_CM_I_BIRTHDAY, CM_Birthday);
	DDX_Text(pDX, IDC_EDIT_CM_I_NAME, CM_Name);
	
}


BEGIN_MESSAGE_MAP(CCeoSM_Inquire, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CM_I_RETURN, &CCeoSM_Inquire::OnBnClickedButtonIReturn)
	ON_BN_CLICKED(IDC_BUTTON_CM_I_DELETEDATA, &CCeoSM_Inquire::OnBnClickedButtonDeletedata)
	ON_BN_CLICKED(IDC_BUTTON_CM_I_UPDATEDATA, &CCeoSM_Inquire::OnBnClickedButtonUpdatedata)
	ON_BN_CLICKED(IDC_BUTTON_CM_I_INQUIRE, &CCeoSM_Inquire::OnBnClickedButtonIceoInquire)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ICEO_STAFFDATADISPLAY, &CCeoSM_Inquire::OnLvnItemchangedListIceoStaffdatadisplay)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_ICEO_STAFFDATADISPLAY, &CCeoSM_Inquire::OnNMDblclkListIceoStaffdatadisplay)
END_MESSAGE_MAP()


// CCeoSM_Inquire ��Ϣ�������

//��ʼ��
BOOL CCeoSM_Inquire::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	////listbox
	CDialogEx::SetBackgroundImage(IDB_BITMAP_QUERY);
	CM_listStaffDataDisplay.InsertColumn(0, _T("�˺�"), LVCFMT_CENTER, 0);
	CM_listStaffDataDisplay.InsertColumn(1, _T("����"), LVCFMT_CENTER, 80);
	CM_listStaffDataDisplay.InsertColumn(2, _T("�Ա�"), LVCFMT_CENTER, 60);
	CM_listStaffDataDisplay.InsertColumn(3, _T("����״��"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(4, _T("������"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(5, _T("����"), LVCFMT_CENTER, 80);
	CM_listStaffDataDisplay.InsertColumn(6, _T("��ҵ��ѧ"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(7, _T("רҵ"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(8, _T("���֤��"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(9, _T("ѧλ"), LVCFMT_CENTER, 70);
	CM_listStaffDataDisplay.InsertColumn(10, _T("�绰"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(11, _T("��ְʱ��"), LVCFMT_CENTER, 80);
	CM_listStaffDataDisplay.InsertColumn(12, _T("ְλ"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(13, _T("����"), LVCFMT_CENTER, 50);
	CM_listStaffDataDisplay.InsertColumn(14, _T("��ס��"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(15, _T("�س�"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(16, _T("��������"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(17, _T("ua_id"), LVCFMT_CENTER, 0);

	//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
	CM_listStaffDataDisplay.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	update_flag = -1;
	db.InitDatabase();
	int cid = db.FindIdbyAccount(SaveUserName);
	query = db.QueyInfoByUA_id(cid);
	
	
	if (query.m_UI_Position == "����")
	{  
		CM_Department = query.m_UI_Department;
		GetDlgItem(IDC_COMBO_CM_I_DEPARTMENT)->EnableWindow(FALSE);
		UpdateData(FALSE);
	}
	else
	{
		UpdateData(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


//�ȼ�����(��������)
BOOL CCeoSM_Inquire::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���

	return CDialogEx::PreTranslateMessage(pMsg);
}

//���ذ�ť
void CCeoSM_Inquire::OnBnClickedButtonIReturn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(0);
}

//ɾ����ť
void CCeoSM_Inquire::OnBnClickedButtonDeletedata()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString Cur_ui_id, Cur_name, Cur_ua_id, sql, sql2;
	int ui_id, ua_id;
	CString fenhao = _T("'");
	int index = CM_listStaffDataDisplay.GetNextItem(-1, LVNI_SELECTED);

	//��ʼ��������listbox��ȫ��ѡ��
	CM_Name = _T("");
	CM_Birthday = _T("");
	CM_Account = _T("");
	CM_Sex = _T("");
	CM_Position = _T("");
	CM_Department = _T("");
	//���±���ֵ
	UpdateData(TRUE);
	//ListBox ��ѡ�ѡ��
	if (index != -1) {
		Cur_ui_id = CM_listStaffDataDisplay.GetItemText(index, 0);
		Cur_name = CM_listStaffDataDisplay.GetItemText(index, 1);
		Cur_ua_id = CM_listStaffDataDisplay.GetItemText(index, 17);
		ui_id = _ttoi(Cur_ui_id);
		ua_id = _ttoi(Cur_ua_id);
		//��ȷ��ɾ��
		if (MessageBox((_T("�Ƿ�ɾ��") + Cur_ui_id + _T("��Ա����") + Cur_name), _T("��ʾ"), MB_OKCANCEL) == 1) {
			db.DeleteRecord(ui_id, _T("UserInformation"));
			db.DeleteRecord(ua_id, _T("UserAccountInfo"));
			CM_listStaffDataDisplay.DeleteItem(index);
		}
	}
	//ʹ�÷�listbox�ؼ�ɾ��(֧��ģ��)
	else {
		CString Sex_part, Name_part, Account_part, Position_part, Birthday_part;
		CString and = _T(" and ");

		Account_part = fenhao + CM_Account + _T("%") + fenhao;
		Name_part = _T("ui_Name like ") + fenhao + CM_Name + _T("%") + fenhao;
		Sex_part = _T("ui_sex like ") + fenhao + CM_Sex + _T("%") + fenhao;
		Position_part = _T("ui_Position like ") + fenhao + CM_Position + _T("%") + fenhao;
		Birthday_part = _T("UI_Borndate like ") + fenhao + CM_Birthday + _T("%") + fenhao;

		//ɾ����ʾ ��ȷ��ɾ��
		if (MessageBox(_T("�Ƿ���ɾ��һ������Ա��"), _T("��ʾ"), MB_OKCANCEL) == 1) {
			sql = _T("delete from [dbo].[UserInformation] where ui_id !=0 and ui_id like ") + Account_part + and+Name_part + and+Sex_part + and+Position_part + and+Birthday_part;
			sql2 = _T("delete  from [dbo].[UserAccountInfo] where NOT exists (select UA_id from [dbo].[UserInformation] where [dbo].[UserInformation].ua_id = [dbo].[UserAccountInfo].ua_id)");
			TRY
			{
				db.m_db.ExecuteSQL(sql);
				db.m_db.ExecuteSQL(sql2);
			}
				CATCH(CDBException, e)
			{
				//The error code is in e->m_nRetCode
				AfxMessageBox(_T("ɾ��ʧ��"), 0);
			}
			END_CATCH
				//ˢ�±�
				db.m_rs.Open(AFX_DB_USE_DEFAULT_TYPE, _T("select * from [dbo].[UserInformation] where ui_id !=0 "));
			ShowData();
			db.m_rs.Close();
		}
	}
}

//���°�ť	(�ؼ�id����)
void CCeoSM_Inquire::OnBnClickedButtonUpdatedata()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	update_flag *= -1;
	if (update_flag == -1) {
		GetDlgItem(IDC_BUTTON_CM_I_INQUIRE)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON_CM_I_DELETEDATA)->EnableWindow(TRUE);
		return;
	}
	//����ģʽ
	else {
		//		LPPOINT mouse;
		int index = CM_listStaffDataDisplay.GetNextItem(-1, LVNI_SELECTED);
		//		CM_listStaffDataDisplay.GetItemPosition(index,mouse);

		GetDlgItem(IDC_BUTTON_CM_I_INQUIRE)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_CM_I_DELETEDATA)->EnableWindow(FALSE);

	}
}

//��ѯ��ť
void CCeoSM_Inquire::OnBnClickedButtonIceoInquire()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);
	//�齨��ѯ�ĸ��������
	CString sql;
	sql = db.CM_Inquire(CM_Account, CM_Sex, CM_Name, CM_Position, CM_Department);
	db.m_rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);
	ShowData();
	db.m_rs.Close();
}

//��ʾ����
//������һ����Ϣ�����ȴ������������ٲ�������������㿪ʼ����
void CCeoSM_Inquire::ShowData()
{
	CM_listStaffDataDisplay.DeleteAllItems();
	CString psd;
	int Col_index = db.m_rs.GetODBCFieldCount();
	while (db.m_rs.IsEOF() == 0) {
		int i = 0;
		for (int j = 0; j < Col_index; j++) {
			db.m_rs.GetFieldValue(j, psd);
			if (j == 0) {
				CM_listStaffDataDisplay.InsertItem(i, psd);
			}
			CM_listStaffDataDisplay.SetItemText(i, j, psd);
		}
		i++;
		db.m_rs.MoveNext();
	}
}







void CCeoSM_Inquire::OnLvnItemchangedListIceoStaffdatadisplay(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CCeoSM_Inquire::OnNMDblclkListIceoStaffdatadisplay(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index;
	index = CM_listStaffDataDisplay.GetNextItem(-1, LVNI_SELECTED);
	//ѡ��
	if (index != -1) {
		ua_id = CM_listStaffDataDisplay.GetItemText(index, 0);
	}
	/*CPersonalInfo dlg;
	dlg.m_pInquery = this;
	dlg.DoModal();*/
	*pResult = 0;
}
