// PersonalInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "hr.h"


#include "afxdialogex.h"
#include "PersonalInfo.h"

// CPersonalInfo 对话框

IMPLEMENT_DYNAMIC(CPersonalInfo, CDialogEx)

CPersonalInfo::CPersonalInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_PERSONALINFO, pParent)
	, m_strDepart1(_T(""))
	, m_strMarriage(_T(""))
	, m_strPosi1(_T(""))
	, m_strSex(_T(""))
	, m_strAddress(_T(""))
	, m_strBirthday1(_T(""))
	, m_strBornplace1(_T(""))
	, m_strEduBG(_T(""))
	, m_strEntrytime(_T(""))
	, m_strId(_T(""))
	, m_strMajor(_T(""))
	, m_strName(_T(""))
	, m_strPs(_T(""))
	, m_strSpeciality(_T(""))
	, m_strTelephone(_T(""))
	, m_strUniversity(_T(""))
{

}

CPersonalInfo::~CPersonalInfo()
{
}

void CPersonalInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_DEPARTMENT1, m_combox_Depart1);
	DDX_CBString(pDX, IDC_COMBO_DEPARTMENT1, m_strDepart1);
	DDX_CBString(pDX, IDC_COMBO_MARRIAGE1, m_strMarriage);
	DDX_Control(pDX, IDC_COMBO_POSITION1, m_combox_Position);
	DDX_CBString(pDX, IDC_COMBO_POSITION1, m_strPosi1);
	DDX_Control(pDX, IDC_COMBO_SEX1, m_combox_Sex);
	DDX_CBString(pDX, IDC_COMBO_SEX1, m_strSex);
	DDX_Text(pDX, IDC_EDIT_ADDRESS1, m_strAddress);
	DDX_Text(pDX, IDC_EDIT_BIRTHDAY1, m_strBirthday1);
	DDX_Text(pDX, IDC_EDIT_BORNPLACE1, m_strBornplace1);
	DDX_Text(pDX, IDC_EDIT_EDU_BACKGROUND1, m_strEduBG);
	DDX_Text(pDX, IDC_EDIT_ENTRYTIME1, m_strEntrytime);
	DDX_Text(pDX, IDC_EDIT_IDCARD1, m_strId);
	DDX_Text(pDX, IDC_EDIT_MAJOR1, m_strMajor);
	DDX_Text(pDX, IDC_EDIT_NAME1, m_strName);
	DDX_Text(pDX, IDC_EDIT_PS1, m_strPs);
	DDX_Text(pDX, IDC_EDIT_SPECIALITY1, m_strSpeciality);
	DDX_Text(pDX, IDC_EDIT_TELPHONE1, m_strTelephone);
	DDX_Text(pDX, IDC_EDIT_UNIVERSITY1, m_strUniversity);
}


BEGIN_MESSAGE_MAP(CPersonalInfo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CANCELUPDATE, &CPersonalInfo::OnClickedButtonCancelupdate)
	ON_BN_CLICKED(IDC_BUTTON_COMFIRM, &CPersonalInfo::OnClickedButtonComfirm)
END_MESSAGE_MAP()


// CPersonalInfo 消息处理程序


void CPersonalInfo::OnClickedButtonCancelupdate()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}


void CPersonalInfo::OnClickedButtonComfirm()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
	UpdateData(TRUE);
		CString title("注意");
		CString error(" 是否确定修改信息 ");
		if (CPersonalInfo::MessageBox(error, title, MB_OKCANCEL) == IDOK)
		{
			//m_pInquery->ua_id;
			CString RRet = dbP.EditbyAccount(SaveUserName,m_strName, m_strSex, m_strMarriage, m_strBornplace1, m_strBirthday1, m_strUniversity, m_strMajor, m_strId, m_strEduBG, m_strTelephone, m_strEntrytime, m_strPosi1, m_strDepart1, m_strAddress, m_strSpeciality, m_strPs);
			if (RRet == "OK")
			{
				EndDialog(0);
			}
			else if (RRet == "ERROR")
			{
				CString title("修改失败");
				CString error(" 请检查是否有必要填写的项未填写或者未按照格式填写 ");
				MessageBox(error, title, MB_OK);
				CPersonalInfo dlg;
				dlg.DoModal();
			}
			else
			{
				CString title("错误");
				CString error(" 更改错误 ");
				MessageBox(error, title, MB_OK);
				CPersonalInfo dlg;
				dlg.DoModal();
			}
		}
	else
	{
		CPersonalInfo dlg;
		dlg.DoModal();
	}
}


BOOL CPersonalInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	dbP.InitDatabase();
	CDialogEx::SetBackgroundImage(IDB_BITMAP_PI);
	CString UserName = SaveUserName;

	int Id = dbP.FindIdbyAccount(UserName);

	PINFO = dbP.QueyInfoByUA_id(Id);

	m_strName = PINFO.m_UI_Name;
	m_strName.TrimRight(' ');
	m_strSex = PINFO.m_UI_Sex;
	m_strSex.TrimRight(' ');
	m_strMarriage = PINFO.m_UI_Marriage;
	m_strMarriage.TrimRight(' ');
	m_strBornplace1 = PINFO.m_UI_Bornplace;
	m_strBornplace1.TrimRight(' ');
	m_strBirthday1 = PINFO.m_UI_Borndate;
	m_strBirthday1.TrimRight(' ');
	m_strUniversity = PINFO.m_UI_Univesity;
	m_strUniversity.TrimRight(' ');
	m_strMajor = PINFO.m_UI_Major;
	m_strMajor.TrimRight(' ');
	m_strId = PINFO.m_UI_Idcard;
	m_strId.TrimRight(' ');
	m_strEduBG = PINFO.m_UI_Edu_background;
	m_strEduBG.TrimRight(' ');
	m_strTelephone = PINFO.m_UI_Phone;
	m_strTelephone.TrimRight(' ');
	m_strEntrytime = PINFO.m_UI_Entrytime;
	m_strEntrytime.TrimRight(' ');
	m_strPosi1 = PINFO.m_UI_Position;
	m_strPosi1.TrimRight(' ');
	m_strDepart1 = PINFO.m_UI_Department;
	m_strDepart1.TrimRight(' ');
	m_strAddress = PINFO.m_UI_Location;
	m_strAddress.TrimRight(' ');
	m_strSpeciality = PINFO.m_UI_Speciality;
	m_strSpeciality.TrimRight(' ');
	m_strPs = PINFO.m_UI_Comment;
	m_strPs.TrimRight(' ');


	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
