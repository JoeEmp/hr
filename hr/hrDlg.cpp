// hrDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "hr.h"
#include "hrDlg.h"
#include "afxdialogex.h"

#include "Register.h"
#include "Manager.h"
#include "Staff.h"
#include "Ceo.h"
#include "SuperManager.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_HOTKEY()
END_MESSAGE_MAP()


// ChrDlg �Ի���



ChrDlg::ChrDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HR_DIALOG, pParent)
	, m_UserName(_T("11111111"))
	, m_Passkey(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ChrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_UserName);
	DDX_Text(pDX, IDC_EDIT_PASSKEY, m_Passkey);
}

BEGIN_MESSAGE_MAP(ChrDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &ChrDlg::OnBnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_REGISTER, &ChrDlg::OnBnClickedButtonRegister)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// ChrDlg ��Ϣ�������
//��ʼ��ʱ ����������ݿ�
BOOL ChrDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		//ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	db.InitDatabase();
	CDialogEx::SetBackgroundImage(IDB_BITMAP_hrDlg);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void ChrDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void ChrDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR ChrDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//��¼��ť
void ChrDlg::OnBnClickedButtonLogin()
{	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(0);	
	UpdateData(TRUE);
	
	if (m_UserName == ""){
			CString title("����");
			CString error("�˺Ų���Ϊ�� ");
			MessageBox(error, title, MB_OK);
			ChrDlg dlg;
			dlg.DoModal();
		}
		else{
			if (m_Passkey == ""){
					CString title("����");
					CString error(" ���벻��Ϊ�� ");
					MessageBox(error, title, MB_OK);
					ChrDlg dlg;
					dlg.DoModal();
			}
			else{	
					CString result = db.Verify(m_UserName, m_Passkey); //�������� 101 �˺Ŵ��� 102 �������  
																										//111 �������Ա���� 100 ceo���� 200 ������� 300 Ա������
					SaveUserName = m_UserName;
						if (result == "101"){   
							//101�������˺Ŵ��� 
							CString title("�˺Ŵ���");
							CString error("�����˺� �Ƿ�Ϊ�����ֻ����˺�λ��");
							MessageBox(error, title, MB_OK);
							ChrDlg dlg;
							dlg.DoModal();
						}
						else if (result == "102")
						{  //101������������� 
							CString title("�������");
							CString error("���������Ƿ��������˺����˺Ų�ƥ��");
							MessageBox(error, title, MB_OK);
							
							ChrDlg dlg;
							dlg.DoModal();
						}
						else if (result == "111")
						{	//�˺�����111 �򿪹���Ա����
								CSuperManager dlg;
								dlg.DoModal();
						}
						else if (result == "100")
						{	//�˺�����100 ��CEO����
							CCeo dlg;
							dlg.DoModal();
						}
						else if (result == "200")
						{	//�˺�����200 �򿪾������
							CManager dlg;
							dlg.DoModal();
						}
						else if (result == "300")
						{   //�˺�����300 ��Ա������
							CStaff dlg;
							dlg.DoModal();
						}
						else
						{   //��ȥ������� ������δ֪���
							CString title("δ֪����");
							title = result;
							CString error("�ܱ�Ǹ ������һ����ֵ��¹� ����ϵ����Ա");
							MessageBox(error, title, MB_OK);
							ChrDlg dlg;
							dlg.DoModal();

						}
				}
		}
}

//ע�ᰴť
void ChrDlg::OnBnClickedButtonRegister()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(0);
	Register dlg;
	dlg.DoModal();
}


//�ȼ�����
BOOL ChrDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:    // ���λس�
			OnBnClickedButtonLogin();
				return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void ChrDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
}
