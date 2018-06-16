// UserInformation.h : CUserInformation 类的实现



// CUserInformation 实现

// 代码生成在 2017年5月5日, 21:01

#include "stdafx.h"
#include "UserInformation.h"
IMPLEMENT_DYNAMIC(CUserInformation, CRecordset)

CUserInformation::CUserInformation(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_UI_id = 0;
	m_UI_Name = L"";
	m_UI_Sex = L"";
	m_UI_Marriage = L"";
	m_UI_Bornplace = "";
	m_UI_Borndate = L"";
	m_UI_Univesity = L"";
	m_UI_Major = L"";
	m_UI_Idcard = L"";
	m_UI_Edu_background = L"";
	m_UI_Phone = L"";
	m_UI_Entrytime = L"";
	m_UI_Position = L"";
	m_UI_Department = L"";
	m_UI_Location = L"";
	m_UI_Speciality = L"";
	m_UI_Comment = L"";
	m_UA_id = 0;
	m_nFields = 18;
	m_nDefaultType = dynaset;
}

// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CUserInformation::GetDefaultConnect()
{
	return _T("DSN=sql;Description=sql\x6570\x636e;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=LENOVO;DATABASE=HR");
}

CString CUserInformation::GetDefaultSQL()
{
	return _T("[dbo].[UserInformation]");
}

void CUserInformation::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Int(pFX, _T("[UI_id]"), m_UI_id);
	RFX_Text(pFX, _T("[UI_Name]"), m_UI_Name);
	RFX_Text(pFX, _T("[UI_Sex]"), m_UI_Sex);
	RFX_Text(pFX, _T("[UI_Marriage]"), m_UI_Marriage);
	RFX_Text(pFX, _T("[UI_Bornplace]"), m_UI_Bornplace);
	RFX_Text(pFX, _T("[UI_Borndate]"), m_UI_Borndate);
	RFX_Text(pFX, _T("[UI_Univesity]"), m_UI_Univesity);
	RFX_Text(pFX, _T("[UI_Major]"), m_UI_Major);
	RFX_Text(pFX, _T("[UI_Idcard]"), m_UI_Idcard);
	RFX_Text(pFX, _T("[UI_Edu_background]"), m_UI_Edu_background);
	RFX_Text(pFX, _T("[UI_Phone]"), m_UI_Phone);
	RFX_Text(pFX, _T("[UI_Entrytime]"), m_UI_Entrytime);
	RFX_Text(pFX, _T("[UI_Position]"), m_UI_Position);
	RFX_Text(pFX, _T("[UI_Department]"), m_UI_Department);
	RFX_Text(pFX, _T("[UI_Location]"), m_UI_Location);
	RFX_Text(pFX, _T("[UI_Speciality]"), m_UI_Speciality);
	RFX_Text(pFX, _T("[UI_Comment]"), m_UI_Comment);
	RFX_Int(pFX, _T("[UA_id]"), m_UA_id);

}
/////////////////////////////////////////////////////////////////////////////
// CUserInformation 诊断

#ifdef _DEBUG
void CUserInformation::AssertValid() const
{
	CRecordset::AssertValid();
}

void CUserInformation::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


