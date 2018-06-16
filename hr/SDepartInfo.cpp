// SDepartInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "hr.h"
#include "SDepartInfo.h"
#include "afxdialogex.h"


// CSDepartInfo 对话框

IMPLEMENT_DYNAMIC(CSDepartInfo, CDialogEx)

CSDepartInfo::CSDepartInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SDEPARTINFO, pParent)
	, m_strBelongDepart(_T(""))
	, m_strComment(_T(""))
	, m_Name1(_T(""))
	, m_Name2(_T(""))
	, m_Name3(_T(""))
	, m_Name4(_T(""))
	, m_phone1(_T(""))
	, m_Phone2(_T(""))
	, m_Phone3(_T(""))
	, m_Phone4(_T(""))
{

}

CSDepartInfo::~CSDepartInfo()
{
}

void CSDepartInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_BELONG, m_strBelongDepart);
	DDX_Text(pDX, IDC_STATIC_INTRODUTION, m_strComment);
	DDX_Text(pDX, IDC_STATIC_Name1, m_Name1);
	DDX_Text(pDX, IDC_STATIC_Name2, m_Name2);
	DDX_Text(pDX, IDC_STATIC_Name3, m_Name3);
	DDX_Text(pDX, IDC_STATIC_Name4, m_Name4);
	DDX_Text(pDX, IDC_STATIC_Phone1, m_phone1);
	DDX_Text(pDX, IDC_STATIC_Phone2, m_Phone2);
	DDX_Text(pDX, IDC_STATIC_Phone3, m_Phone3);
	DDX_Text(pDX, IDC_STATIC_Phone4, m_Phone4);
}


BEGIN_MESSAGE_MAP(CSDepartInfo, CDialogEx)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CSDepartInfo 消息处理程序


BOOL CSDepartInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	dbDepart.InitDatabase();
	CDialogEx::SetBackgroundImage(IDB_BITMAP_Depart);
	int id = dbDepart.FindIdbyAccount(SaveUserName);
	DepartInfo = dbDepart.QueyInfoByUA_id(id);
	m_strBelongDepart = DepartInfo.m_UI_Department;
	//CString Departinfo;
	if (m_strBelongDepart == "人事部")
	{
		m_strComment = "本部门主要处理公司招聘外交事务";
	}
	else if (m_strBelongDepart == "技术部")
	{
		m_strComment = "本部门主要处理公司技术维护事务";
	}
	else if (m_strBelongDepart == "市场部")
	{
		m_strComment = "本部门主要处理公司宣传营销事务";
	}
	else 
	{
		m_strComment = " ";
	}
	DepartInfo = dbDepart.Getchange(m_strBelongDepart);
	m_Name1 = DepartInfo.m_UI_Name;
	m_phone1 = DepartInfo.m_UI_Phone;

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CSDepartInfo::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}
