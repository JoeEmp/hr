// UserInformation.h : CUserInformation ������

#pragma once

// ���������� 2017��5��5��, 21:01

class CUserInformation : public CRecordset
{
public:
	CUserInformation(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CUserInformation)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	int	m_UI_id;
	int	m_UA_id;
	CStringW	m_UI_Idcard;
	CStringW	m_UI_Name;
	CStringW	m_UI_Sex;
	CStringW	m_UI_Marriage;
	CStringA	m_UI_Bornplace;
	CStringW	m_UI_Borndate;
	CStringW	m_UI_Univesity;
	CStringW	m_UI_Major;
	CStringW	m_UI_Edu_background;
	CStringW	m_UI_Phone;
	CStringW	m_UI_Entrytime;
	CStringW	m_UI_Position;
	CStringW	m_UI_Department;
	CStringW	m_UI_Location;
	CStringW	m_UI_Speciality;
	CStringW	m_UI_Comment;
	

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


