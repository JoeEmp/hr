#pragma once

#include "UserAccountInfo.h"
#include "UserInformation.h"

// UseDatabase ����Ŀ��
typedef struct{
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
}INFO;


class UseDatabase : public CDatabase
{
public:
	UseDatabase();
	virtual ~UseDatabase();

		
	
	// ���ݿ����
	CDatabase m_db;
	CRecordset m_rs;
	//ʹ��������ݿ�ı���

	CUserAccountInfo UserAI;
	CUserInformation UserIM;

	// ���ڳ�ʼ�����ݿ�
	void InitDatabase();
	// ������֤�˺�����ģ�� ���󷵻ش�����Ϣ �ɹ��򷵻��˺�����
	CString Verify(CString account, CString pwd);
	CString Registeration(CString Name, CString Sex, CString Marriage, CString Bornplace, CString Borndate, CString University, CString Major, CString Idcard, CString Edubg, CString Phone, CString Entrytime, CString Posi, CString Depart, CString Location, CString Speciality, CString Comment);
	int GetLastRecord(CString table, CString id);
	CString QueryById(int UseId,CString column);
	void ChangPwd(int Useid, CString NewPwd);
	void DeleteRecord(int Useid, CString table);
	int FindIdbyAccount(CString Account);
	INFO QueyInfoByUA_id(int id);
	CString EditbyAccount(CString Account, CString Name, CString Sex, CString Marriage, CString Bornplace, CString Borndate, CString University, CString Major, CString Idcard, CString Edubg, CString Phone, CString Entrytime, CString Posi, CString Depart, CString Location, CString Speciality, CString Comment);
	INFO Getchange(CString Depart);
	CString UseDatabase::CM_Inquire(CString id, CString Sex, CString Name, CString Position, CString Department);
};


