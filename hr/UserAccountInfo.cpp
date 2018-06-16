// UserAccountInfo.h : CUserAccountInfo 类的实现



// CUserAccountInfo 实现

// 代码生成在 2017年5月5日, 21:01

#include "stdafx.h"
#include "UserAccountInfo.h"
IMPLEMENT_DYNAMIC(CUserAccountInfo, CRecordset)

CUserAccountInfo::CUserAccountInfo(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_UA_id = 0;
	m_UA_Account = "";
	m_UA_Password = "";
	m_UA_Type = "";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}

// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CUserAccountInfo::GetDefaultConnect()
{
	return _T("DSN=sql;Description=sql\x6570\x636e;UID=sa;PWD=rlzyglxt;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=LENOVO;DATABASE=HR");
}

CString CUserAccountInfo::GetDefaultSQL()
{
	return _T("[dbo].[UserAccountInfo]");
}

void CUserAccountInfo::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Int(pFX, _T("[UA_id]"), m_UA_id);
	RFX_Text(pFX, _T("[UA_Account]"), m_UA_Account);
	RFX_Text(pFX, _T("[UA_Password]"), m_UA_Password);
	RFX_Text(pFX, _T("[UA_Type]"), m_UA_Type);

}
/////////////////////////////////////////////////////////////////////////////
// CUserAccountInfo 诊断

#ifdef _DEBUG
void CUserAccountInfo::AssertValid() const
{
	CRecordset::AssertValid();
}

void CUserAccountInfo::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


