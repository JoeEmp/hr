// UserInformation.h : CUserInformation ���ʵ��



// CUserInformation ʵ��

// ���������� 2017��5��5��, 21:01

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

// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
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
// CUserInformation ���

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


