// UserAccountInfo.h : CUserAccountInfo ���ʵ��



// CUserAccountInfo ʵ��

// ���������� 2017��5��5��, 21:01

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

// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Int(pFX, _T("[UA_id]"), m_UA_id);
	RFX_Text(pFX, _T("[UA_Account]"), m_UA_Account);
	RFX_Text(pFX, _T("[UA_Password]"), m_UA_Password);
	RFX_Text(pFX, _T("[UA_Type]"), m_UA_Type);

}
/////////////////////////////////////////////////////////////////////////////
// CUserAccountInfo ���

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


