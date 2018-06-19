// hrDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// ChrDlg 对话框



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


// ChrDlg 消息处理程序
//初始化时 完成连接数据库
BOOL ChrDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	db.InitDatabase();
	CDialogEx::SetBackgroundImage(IDB_BITMAP_hrDlg);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void ChrDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR ChrDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//登录按钮
void ChrDlg::OnBnClickedButtonLogin()
{	
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);	
	UpdateData(TRUE);
	
	if (m_UserName == ""){
			CString title("错误");
			CString error("账号不能为空 ");
			MessageBox(error, title, MB_OK);
			ChrDlg dlg;
			dlg.DoModal();
		}
		else{
			if (m_Passkey == ""){
					CString title("错误");
					CString error(" 密码不能为空 ");
					MessageBox(error, title, MB_OK);
					ChrDlg dlg;
					dlg.DoModal();
			}
			else{	
					CString result = db.Verify(m_UserName, m_Passkey); //函数返回 101 账号错误 102 密码错误  
																										//111 进入管理员界面 100 ceo界面 200 经理界面 300 员工界面
					SaveUserName = m_UserName;
						if (result == "101"){   
							//101错误是账号错误 
							CString title("账号错误");
							CString error("请检查账号 是否为纯数字或者账号位数");
							MessageBox(error, title, MB_OK);
							ChrDlg dlg;
							dlg.DoModal();
						}
						else if (result == "102")
						{  //101错误是密码错误 
							CString title("密码错误");
							CString error("请检查密码是否错误或者账号与账号不匹配");
							MessageBox(error, title, MB_OK);
							
							ChrDlg dlg;
							dlg.DoModal();
						}
						else if (result == "111")
						{	//账号类型111 打开管理员界面
								CSuperManager dlg;
								dlg.DoModal();
						}
						else if (result == "100")
						{	//账号类型100 打开CEO界面
							CCeo dlg;
							dlg.DoModal();
						}
						else if (result == "200")
						{	//账号类型200 打开经理界面
							CManager dlg;
							dlg.DoModal();
						}
						else if (result == "300")
						{   //账号类型300 打开员工界面
							CStaff dlg;
							dlg.DoModal();
						}
						else
						{   //除去以上情况 出现了未知情况
							CString title("未知错误");
							title = result;
							CString error("很抱歉 出现了一个奇怪的事故 请联系管理员");
							MessageBox(error, title, MB_OK);
							ChrDlg dlg;
							dlg.DoModal();

						}
				}
		}
}

//注册按钮
void ChrDlg::OnBnClickedButtonRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
	Register dlg;
	dlg.DoModal();
}


//热键捆绑
BOOL ChrDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:    // 屏蔽回车
			OnBnClickedButtonLogin();
				return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void ChrDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}
