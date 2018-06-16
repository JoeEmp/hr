// UseDatabase.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "hr.h"
#include "UseDatabase.h"
#include "stdafx.h"
#include "afxdialogex.h"
//���������ͷ�ļ�
#include "hrDlg.h"
#include "Register.h"
#include "Manager.h"
#include "Staff.h"
#include "Ceo.h"
#include "SuperManager.h"

// UseDatabase

UseDatabase::UseDatabase()
{
}

UseDatabase::~UseDatabase()
{
}


// UseDatabase ��Ա����


// ���ڳ�ʼ�����ݿ�
void UseDatabase::InitDatabase()
{
	//���ݿ����Ӵ���

	TRY
	{	//����һ���ַ������ڴ��UserAccountInformation�������������ݿ����
		CString Connect = UserAI.GetDefaultConnect();
		//�������ݿ����
		m_db.OpenEx(Connect, CDatabase::noOdbcDialog);
		m_rs.m_pDatabase = &m_db;
		
	}
		//////////////////////////�����쳣��Ϣ  
		CATCH(CDBException, ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException, pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	} AND_CATCH(CException, ex)
	{
		TCHAR szError[100];
		ex->GetErrorMessage(szError, 100);
		AfxMessageBox(szError);
	}
	END_CATCH
	m_rs.Close();
	
}





// ������֤�˺�����ģ�� ���󷵻ش�����Ϣ �ɹ��򷵻��˺�����
CString UseDatabase::Verify(CString account, CString pwd)
{
	CString Account = account;  //��Ŵ�����˺�
	CString Pwd = pwd;			//��Ŵ��������
	CString error;				//��Ŵ������
	CString strResultType;		//��Ų�ѯ�����˺�����
	CString strResultPwd;		//��Ų�ѯ��������
	
	TRY
	{	//Ҫִ�е����ݿ���� ѡ����Ӧ�˺ŵ�һ������
		CString strSql("select * from UserAccountInfo where UA_Account=");
		    strSql.Format(strSql + Account);
		//�򿪲�ѯ��¼  
		 m_rs.Open(AFX_DB_USE_DEFAULT_TYPE, strSql);
		//�õ����� 
		 m_rs.GetFieldValue(2, strResultPwd); //�õ����� ��Ӧ���д�0��ʼ���������� ��λΪ2 ��strResultPwd���
		 m_rs.GetFieldValue(3, strResultType);//�õ��û����� ͬ��
		 m_rs.Close();
		 
	}
		CATCH(CDBException, ex)
	{
		/*��ʾ���ݿ��������
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);*/
		//�鲻���˺�ʱ �����˺ų������101
		error = ("101");
		return error;
		
	}
	AND_CATCH(CMemoryException, pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	END_CATCH
		//�����ж�ͨ�� �򷵻���Ӧ�˺����� �����򷵻ش����� 102
		if (strResultPwd == Pwd)
			{		
			if (strResultType == "300")
				{
				return strResultType;
				}
			else if (strResultType == "200")
				{
				return strResultType;
				}
			else if (strResultType == "100")
				{
				return strResultType;
				}
			else if (strResultType == "111") 
				{
				return strResultType;
				}
			else
				{
				error = ("δ֪����");
				return error;
				}	
			}
			else
				{
				error = ("102");
				return error;
				}
}



CString UseDatabase::Registeration(CString Name, CString Sex, CString Marriage, CString Bornplace, CString Borndate, CString University, CString Major, CString Idcard, CString Edubg, CString Phone, CString Entrytime, CString Posi, CString Depart, CString Location, CString Speciality, CString Comment)
{
	CString Result;
	CString rName = Name, rSex = Sex, rMarriage = Marriage, rBornplace = Bornplace, rBorndate = Borndate, rUniversity = University, rMajor = Major, rIdcard = Idcard,rEdubg = Edubg,rPhone = Phone,rEntrytime = Entrytime,rPosi = Posi,rDepart = Depart,rLocation = Location, rSpeciality = Speciality,rComment = Comment;
	if (rName == "" || rSex == "" || rMarriage == "" || rBorndate == "" || rIdcard == "" || rPhone == "" || rEntrytime == "" || rPosi == "" || rDepart == "")
	{
		Result = ("ERROR");
		return Result;
	}
	CString TableA("UserAccountInfo"), TableInfo("UserInformation");
	CString Aid("UA_id"), Infoid("UI_id");
	int LastAID = GetLastRecord(TableA,Aid);
	int LastInfoID = GetLastRecord(TableInfo,Infoid);
	LastAID ++ ;
	LastInfoID ++;
	TRY
	{
	UserAI.Open(CRecordset::dynaset, _T("select * from [UserAccountInfo]"));
	UserAI.AddNew();
	UserAI.m_UA_id = LastAID;

	
	UserIM.Open(CRecordset::dynaset, _T("select * from [UserInformation]"));
	UserIM.AddNew(); //�ڱ��ĩβ�����¼�¼
	UserIM.m_UI_id = LastInfoID;
	UserIM.m_UA_id = LastAID;
	UserIM.m_UI_Name = rName;
	UserIM.m_UI_Sex = rSex;
	UserIM.m_UI_Marriage = rMarriage;
	UserIM.m_UI_Bornplace = rBornplace;
	UserIM.m_UI_Borndate = rBorndate;
	UserIM.m_UI_Univesity = rUniversity;
	UserIM.m_UI_Major = rMajor;
	UserIM.m_UI_Idcard = rIdcard;
	UserIM.m_UI_Edu_background = rEdubg;
	UserIM.m_UI_Phone = rPhone;
	UserIM.m_UI_Entrytime = rEntrytime;
	UserIM.m_UI_Position = rPosi;
	UserIM.m_UI_Department = rDepart;
	UserIM.m_UI_Location = rLocation;
	UserIM.m_UI_Speciality = rSpeciality;
	UserIM.m_UI_Comment = rComment;	
	
	int mDepart, mPosi;
	if (rDepart == "���²�")
	{
		mDepart = 101;
	}
	else if (rDepart == "������")
	{
		mDepart = 102;
	}
	else if (rDepart == "�г���")
	{
		mDepart = 103;
	}

	if (rPosi == "CEO")
	{
		mPosi = 22;
	}
	else if (rPosi == "����")
	{
		mPosi = 23;
	}
	else if (rPosi == "Ա��")
	{
		mPosi = 24;

	}
	rDepart.Format(L"%d", mDepart);
	rPosi.Format(L"%d", mPosi);
	CString strAccount;
	if (LastAID<10)
	{
		strAccount.Format(L"%d", LastAID);
		strAccount.Format(rDepart + rPosi + "00" + strAccount);
	}
	else if (LastAID>9 && LastAID<100)
	{
		strAccount.Format(L"%d", LastAID);
		strAccount.Format(rDepart + rPosi + "0" + strAccount);
	}
	else if (LastAID>100)
	{
		strAccount.Format(L"%d", LastAID);
		strAccount.Format(rDepart + rPosi + strAccount);
	}

	CString strType;

		if (mPosi == 22)
		{
			strType = ("100");
		}
		else if (mPosi == 23)
		{
			strType = ("200");
		}
		else if (mPosi == 24)
		{
			strType = ("300");
		}
		else 
		{
			strType = ("");
		}

	UserAI.m_UA_Account = strAccount;
	UserAI.m_UA_Type = strType;

	}
	CATCH(CDBException, ex)
	{
		////��ʾ���ݿ��������
		//AfxMessageBox(ex->m_strError);
		//AfxMessageBox(ex->m_strStateNativeOrigin);
		Result = ("ERROR");
		return Result;
	}
	AND_CATCH(CMemoryException, pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	END_CATCH
	UserAI.Update();
	UserAI.Requery();
	UserIM.Update(); //���¼�¼�������ݿ�
	UserIM.Requery(); //�ؽ���¼��
	UserAI.Close();
	UserIM.Close();
	Result = ("OK");
	return Result;
}

int UseDatabase::GetLastRecord(CString table, CString Uid)
{
	TRY
	{
		CString Usetable = table;
		CString Useid = Uid;
		CString Sql("select * from ");
		Sql.Format(Sql + Usetable);
		int id = 0;
		if (m_db.IsOpen())
		{
			m_rs.Open(CRecordset::dynaset, Sql);
			m_rs.MoveLast();
			CString strAccount;
			m_rs.GetFieldValue(Useid, strAccount);
			m_rs.Close();
			id = _ttoi(strAccount);

		}
		return id;
	}

	CATCH(CDBException, ex)
	{
		//��ʾ���ݿ��������
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException, pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	END_CATCH
}




CString UseDatabase::QueryById(int UseId,CString column)
{
	TRY
	{
	int LastNewId = UseId; 
	CString LastId;
	CString Column = column;
	LastId.Format(L"%d", LastNewId);
	CString Sql("select * from [UserAccountInfo] where UA_id = ");
	Sql.Format(Sql + LastId);
	UserAI.Open(CRecordset::dynaset, Sql);
	if (Column == "Account")
	{
		Column = UserAI.m_UA_Account;
	}
	else if (Column == "Pwd")
	{
		Column = UserAI.m_UA_Password;
	}
	else if (Column == "Type")
	{
		Column = UserAI.m_UA_Type;
	}
	
	UserAI.Close();
	
	return Column;

	}
	CATCH(CDBException, ex)
	{
		//��ʾ���ݿ��������
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException, pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	END_CATCH

}	


void UseDatabase::ChangPwd(int Useid,CString NewPwd)
{

	TRY
	{
	int LastNewId = Useid;
	CString Pwd = NewPwd;
	CString LastId;
	LastId.Format(L"%d", LastNewId);
	CString Sql("select * from [UserAccountInfo] where UA_id = ");
	Sql.Format(Sql + LastId);
	UserAI.Open(CRecordset::dynaset, Sql);
	UserAI.Edit();
	UserAI.m_UA_Password = Pwd;
	UserAI.Update();
	UserAI.Requery();
	UserAI.Close();


	}
		CATCH(CDBException, ex)
	{
		//��ʾ���ݿ��������
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException, pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	END_CATCH

}


void UseDatabase::DeleteRecord(int Useid,CString table)
{
	
	TRY
	{
	int Lastid = Useid;
	CString UseLastId;
	CString UseTable = table;
	CString UseId;
	CString Sqlpart1("select * from ");
	CString Sqlpart2(" where ");
	CString Sqlpart3(" = ");

	if (UseTable == "UserAccountInfo")
	{
		UseId = ("UA_id");
	}
	else if (UseTable == "UserInformation")
	{
		UseId = ("UI_id");
	}
	UseLastId.Format(L"%d", Lastid);
	Sqlpart1.Format(Sqlpart1 + UseTable + Sqlpart2 + UseId + Sqlpart3 + UseLastId);
	m_rs.Open(CRecordset::dynaset, Sqlpart1);
	m_rs.Delete();
	m_rs.Requery();
	m_rs.Close();
	}
		CATCH(CDBException, ex)
	{
		//��ʾ���ݿ��������
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException, pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	END_CATCH
}


int UseDatabase::FindIdbyAccount(CString Account)
{
	TRY
	{   int id;
		CString UseAccount = Account;
		CString Sql("select * from [UserAccountInfo] where UA_Account = ");
		Sql.Format(Sql + UseAccount);
		UserAI.Open(CRecordset::dynaset, Sql);
		id = UserAI.m_UA_id;
		UserAI.Close();
		return id;
	}
	CATCH(CDBException, ex)
	{
		//��ʾ���ݿ��������
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException, pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	END_CATCH
	
}


INFO UseDatabase::QueyInfoByUA_id(int id)
{
	TRY
	{ 
	INFO  info;
	int Useid=id;
	CString UseId;
	UseId.Format(L"%d", Useid);
	CString Sql("select * from [UserInformation] where UA_id = ");
	Sql.Format(Sql + UseId);
	UserIM.Open(CRecordset::dynaset, Sql);
	info.m_UI_Name = UserIM.m_UI_Name;
	info.m_UI_Sex = UserIM.m_UI_Sex;
	info.m_UI_Marriage = UserIM.m_UI_Marriage;
	info.m_UI_Bornplace = UserIM.m_UI_Bornplace;
	info.m_UI_Borndate = UserIM.m_UI_Borndate;
	info.m_UI_Univesity = UserIM.m_UI_Univesity;
	info.m_UI_Major = UserIM.m_UI_Major;
	info.m_UI_Idcard = UserIM.m_UI_Idcard;
	info.m_UI_Edu_background = UserIM.m_UI_Edu_background;
	info.m_UI_Phone = UserIM.m_UI_Phone;
	info.m_UI_Entrytime = UserIM.m_UI_Entrytime;
	info.m_UI_Position = UserIM.m_UI_Position;
	info.m_UI_Department = UserIM.m_UI_Department;
	info.m_UI_Location = UserIM.m_UI_Location;
	info.m_UI_Speciality = UserIM.m_UI_Speciality;
	info.m_UI_Comment = UserIM.m_UI_Comment;
	UserIM.Close();
	return info;
	
	}
		CATCH(CDBException, ex)
	{
		//��ʾ���ݿ��������
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException, pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	END_CATCH
	
}



CString UseDatabase::EditbyAccount(CString Account, CString Name, CString Sex, CString Marriage, CString Bornplace, CString Borndate, CString University, CString Major, CString Idcard, CString Edubg, CString Phone, CString Entrytime, CString Posi, CString Depart, CString Location, CString Speciality, CString Comment)
{
	CString Result;
	CString rAccount = Account,rName = Name, rSex = Sex, rMarriage = Marriage, rBornplace = Bornplace, rBorndate = Borndate, rUniversity = University, rMajor = Major, rIdcard = Idcard, rEdubg = Edubg, rPhone = Phone, rEntrytime = Entrytime, rPosi = Posi, rDepart = Depart, rLocation = Location, rSpeciality = Speciality, rComment = Comment;
	if (rAccount == "" || rName == "" || rSex == "" || rMarriage == "" || rBorndate == "" || rIdcard == "" || rPhone == "" || rEntrytime == "" || rPosi == "" || rDepart == "")
	{
		Result = ("ERROR");
		return Result;
	}
	int id = FindIdbyAccount(rAccount);
	CString UseId;
	UseId.Format(L"%d", id);
	CString Sql("select * from [UserInformation] where UA_id = ");
	Sql.Format(Sql + UseId);
	TRY
	{
	UserIM.Open(CRecordset::dynaset,Sql);
	UserIM.Edit(); //�ڱ��ĩβ�����¼�¼
	UserIM.m_UI_Name = rName;
	UserIM.m_UI_Sex = rSex;
	UserIM.m_UI_Marriage = rMarriage;
	UserIM.m_UI_Bornplace = rBornplace;
	UserIM.m_UI_Borndate = rBorndate;
	UserIM.m_UI_Univesity = rUniversity;
	UserIM.m_UI_Major = rMajor;
	UserIM.m_UI_Idcard = rIdcard;
	UserIM.m_UI_Edu_background = rEdubg;
	UserIM.m_UI_Phone = rPhone;
	UserIM.m_UI_Entrytime = rEntrytime;
	UserIM.m_UI_Position = rPosi;
	UserIM.m_UI_Department = rDepart;
	UserIM.m_UI_Location = rLocation;
	UserIM.m_UI_Speciality = rSpeciality;
	UserIM.m_UI_Comment = rComment;
	}
		CATCH(CDBException, ex)
	{
		////��ʾ���ݿ��������
		//AfxMessageBox(ex->m_strError);
		//AfxMessageBox(ex->m_strStateNativeOrigin);
		Result = ("ERROR");
		return Result;
	}
	AND_CATCH(CMemoryException, pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	END_CATCH

	UserIM.Update(); //���¼�¼�������ݿ�
	UserIM.Requery(); //�ؽ���¼��
	UserIM.Close();
	Result = ("OK");
	return Result;
}


INFO UseDatabase::Getchange(CString Depart)
{
	CString Department = Depart;
	INFO change;
		TRY{
			CString Sql("select * from [UserInformation] where UI_Position = '����' AND UI_Department = '");
			CString Sqlpart("'");
			Sql.Format(Sql + Department + Sqlpart);
			UserIM.Open(CRecordset::dynaset, Sql);
			change.m_UI_Name = UserIM.m_UI_Name;
			change.m_UI_Phone = UserIM.m_UI_Phone;
		}
		CATCH(CDBException, ex)
		{
			//��ʾ���ݿ��������
			AfxMessageBox(ex->m_strError);
			AfxMessageBox(ex->m_strStateNativeOrigin);
		}
		AND_CATCH(CMemoryException, pEx)
		{
			pEx->ReportError();
			AfxMessageBox(_T("memory exception"));
		}
		END_CATCH
	UserIM.Close();
	return change;
}


CString UseDatabase::CM_Inquire(CString id, CString Sex, CString Name, CString Position, CString Department) {
	CString Sex_part, Name_part, Id_part, Position_part, Department_part;
	CString fenhao = _T("'");
	CString and = _T(" and ");

	Id_part = fenhao + +_T("%") + fenhao;
	Name_part = _T("UI_Name like ") + fenhao + Name + _T("%") + fenhao;
	Sex_part = _T("UI_Sex like ") + fenhao + Sex + _T("%") + fenhao;
	Position_part = _T(" UI_Position like ") + fenhao + Position + _T("%") + fenhao;
	Department_part = _T(" UI_Department like ") + fenhao + Department + _T("%") + fenhao;

	CString sql;
	sql = _T("select  *  from   [dbo].[UserInformation] where Ui_id !=0  and Ui_id like") + Id_part + and +Name_part + and +Sex_part + and +Position_part + and +Department_part;
	return sql;
}
