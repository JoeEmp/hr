// CeoSM_Inquire.cpp : 实现文件
//

#include "stdafx.h"
#include "hr.h"
#include "CeoSM_Inquire.h"
#include "afxdialogex.h"
#include "PersonalInfo.h"


// CCeoSM_Inquire 对话框

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


// CCeoSM_Inquire 消息处理程序

//初始化
BOOL CCeoSM_Inquire::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	////listbox
	CDialogEx::SetBackgroundImage(IDB_BITMAP_QUERY);
	CM_listStaffDataDisplay.InsertColumn(0, _T("账号"), LVCFMT_CENTER, 0);
	CM_listStaffDataDisplay.InsertColumn(1, _T("姓名"), LVCFMT_CENTER, 80);
	CM_listStaffDataDisplay.InsertColumn(2, _T("性别"), LVCFMT_CENTER, 60);
	CM_listStaffDataDisplay.InsertColumn(3, _T("婚姻状况"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(4, _T("出生地"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(5, _T("生日"), LVCFMT_CENTER, 80);
	CM_listStaffDataDisplay.InsertColumn(6, _T("毕业大学"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(7, _T("专业"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(8, _T("身份证号"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(9, _T("学位"), LVCFMT_CENTER, 70);
	CM_listStaffDataDisplay.InsertColumn(10, _T("电话"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(11, _T("入职时间"), LVCFMT_CENTER, 80);
	CM_listStaffDataDisplay.InsertColumn(12, _T("职位"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(13, _T("部门"), LVCFMT_CENTER, 50);
	CM_listStaffDataDisplay.InsertColumn(14, _T("居住地"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(15, _T("特长"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(16, _T("自我评价"), LVCFMT_CENTER, 100);
	CM_listStaffDataDisplay.InsertColumn(17, _T("ua_id"), LVCFMT_CENTER, 0);

	//选中某行使整行高亮（只适用与report风格的listctrl）
	CM_listStaffDataDisplay.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	update_flag = -1;
	db.InitDatabase();
	int cid = db.FindIdbyAccount(SaveUserName);
	query = db.QueyInfoByUA_id(cid);
	
	
	if (query.m_UI_Position == "经理")
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
				  // 异常: OCX 属性页应返回 FALSE
}


//热键捆绑(暂无捆绑)
BOOL CCeoSM_Inquire::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CDialogEx::PreTranslateMessage(pMsg);
}

//返回按钮
void CCeoSM_Inquire::OnBnClickedButtonIReturn()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}

//删除按钮
void CCeoSM_Inquire::OnBnClickedButtonDeletedata()
{
	// TODO: 在此添加控件通知处理程序代码

	CString Cur_ui_id, Cur_name, Cur_ua_id, sql, sql2;
	int ui_id, ua_id;
	CString fenhao = _T("'");
	int index = CM_listStaffDataDisplay.GetNextItem(-1, LVNI_SELECTED);

	//初始化（除了listbox）全部选项
	CM_Name = _T("");
	CM_Birthday = _T("");
	CM_Account = _T("");
	CM_Sex = _T("");
	CM_Position = _T("");
	CM_Department = _T("");
	//更新变量值
	UpdateData(TRUE);
	//ListBox 的选项被选中
	if (index != -1) {
		Cur_ui_id = CM_listStaffDataDisplay.GetItemText(index, 0);
		Cur_name = CM_listStaffDataDisplay.GetItemText(index, 1);
		Cur_ua_id = CM_listStaffDataDisplay.GetItemText(index, 17);
		ui_id = _ttoi(Cur_ui_id);
		ua_id = _ttoi(Cur_ua_id);
		//先确认删除
		if (MessageBox((_T("是否删掉") + Cur_ui_id + _T("号员工：") + Cur_name), _T("提示"), MB_OKCANCEL) == 1) {
			db.DeleteRecord(ui_id, _T("UserInformation"));
			db.DeleteRecord(ua_id, _T("UserAccountInfo"));
			CM_listStaffDataDisplay.DeleteItem(index);
		}
	}
	//使用非listbox控件删除(支持模糊)
	else {
		CString Sex_part, Name_part, Account_part, Position_part, Birthday_part;
		CString and = _T(" and ");

		Account_part = fenhao + CM_Account + _T("%") + fenhao;
		Name_part = _T("ui_Name like ") + fenhao + CM_Name + _T("%") + fenhao;
		Sex_part = _T("ui_sex like ") + fenhao + CM_Sex + _T("%") + fenhao;
		Position_part = _T("ui_Position like ") + fenhao + CM_Position + _T("%") + fenhao;
		Birthday_part = _T("UI_Borndate like ") + fenhao + CM_Birthday + _T("%") + fenhao;

		//删除提示 先确认删除
		if (MessageBox(_T("是否批删除一个或多个员工"), _T("提示"), MB_OKCANCEL) == 1) {
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
				AfxMessageBox(_T("删除失败"), 0);
			}
			END_CATCH
				//刷新表
				db.m_rs.Open(AFX_DB_USE_DEFAULT_TYPE, _T("select * from [dbo].[UserInformation] where ui_id !=0 "));
			ShowData();
			db.m_rs.Close();
		}
	}
}

//更新按钮	(控件id更新)
void CCeoSM_Inquire::OnBnClickedButtonUpdatedata()
{
	// TODO: 在此添加控件通知处理程序代码
	update_flag *= -1;
	if (update_flag == -1) {
		GetDlgItem(IDC_BUTTON_CM_I_INQUIRE)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON_CM_I_DELETEDATA)->EnableWindow(TRUE);
		return;
	}
	//更新模式
	else {
		//		LPPOINT mouse;
		int index = CM_listStaffDataDisplay.GetNextItem(-1, LVNI_SELECTED);
		//		CM_listStaffDataDisplay.GetItemPosition(index,mouse);

		GetDlgItem(IDC_BUTTON_CM_I_INQUIRE)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_CM_I_DELETEDATA)->EnableWindow(FALSE);

	}
}

//查询按钮
void CCeoSM_Inquire::OnBnClickedButtonIceoInquire()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	//组建查询的各部分语句
	CString sql;
	sql = db.CM_Inquire(CM_Account, CM_Sex, CM_Name, CM_Position, CM_Department);
	db.m_rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);
	ShowData();
	db.m_rs.Close();
}

//显示部分
//产生下一条信息，必先创建父项（首项），再插入子项。（均从零开始。）
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
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CCeoSM_Inquire::OnNMDblclkListIceoStaffdatadisplay(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	int index;
	index = CM_listStaffDataDisplay.GetNextItem(-1, LVNI_SELECTED);
	//选中
	if (index != -1) {
		ua_id = CM_listStaffDataDisplay.GetItemText(index, 0);
	}
	/*CPersonalInfo dlg;
	dlg.m_pInquery = this;
	dlg.DoModal();*/
	*pResult = 0;
}
