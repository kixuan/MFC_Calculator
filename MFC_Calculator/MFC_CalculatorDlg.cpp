// MFC_CalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFC_Calculator.h"
#include "MFC_CalculatorDlg.h"
#include "afxdialogex.h"
#include "Calculator.h"			//计算类头文件包含计算方法

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
END_MESSAGE_MAP()


// CMFCCalculatorDlg 对话框



CMFCCalculatorDlg::CMFCCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LBRACKET, &CMFCCalculatorDlg::OnBnClickedButtonLbracket)
	ON_BN_CLICKED(IDC_BUTTON_RBRACKET, &CMFCCalculatorDlg::OnBnClickedButtonRbracket)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CMFCCalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CMFCCalculatorDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_ABS, &CMFCCalculatorDlg::OnBnClickedButtonAbs)
	ON_BN_CLICKED(IDC_BUTTON_FAC, &CMFCCalculatorDlg::OnBnClickedButtonFac)
	ON_BN_CLICKED(IDC_BUTTON_POW, &CMFCCalculatorDlg::OnBnClickedButtonPow)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CMFCCalculatorDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CMFCCalculatorDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CMFCCalculatorDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMFCCalculatorDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_REM, &CMFCCalculatorDlg::OnBnClickedButtonRem)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CMFCCalculatorDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CMFCCalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_0, &CMFCCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &CMFCCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CMFCCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CMFCCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CMFCCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CMFCCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CMFCCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CMFCCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CMFCCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CMFCCalculatorDlg::OnBnClickedButton9)
	ON_EN_CHANGE(IDC_EDIT_EXP, &CMFCCalculatorDlg::OnEnChangeEditExp)
	ON_BN_CLICKED(IDC_RADIO_SIN, &CMFCCalculatorDlg::OnBnClickedRadioSin)
	ON_BN_CLICKED(IDC_RADIO_COS, &CMFCCalculatorDlg::OnBnClickedRadioCos)
	ON_BN_CLICKED(IDC_RADIO_TAN, &CMFCCalculatorDlg::OnBnClickedRadioTan)
	ON_BN_CLICKED(IDC_RADIO_LOG10, &CMFCCalculatorDlg::OnBnClickedRadioLog10)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CMFCCalculatorDlg::OnDtnDatetimechangeDatetimepicker1)
END_MESSAGE_MAP()


// CMFCCalculatorDlg 消息处理程序

BOOL CMFCCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCCalculatorDlg::OnPaint()
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
		CPaintDC   dc(this);
		CRect rect;
		GetClientRect(&rect);
		CDC   dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP1);  //对话框的背景图片  

		BITMAP   bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap   *pbmpOld = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 输入区显示按钮操作
void CMFCCalculatorDlg::AddToEditExp(UINT IDC_Button)
{
	CString strBtn;
	CString strExp;
	GetDlgItem(IDC_Button)->GetWindowText(strBtn);
	GetDlgItem(IDC_EDIT_EXP)->GetWindowText(strExp);
	SetDlgItemText(IDC_EDIT_EXP, strExp + strBtn);
}


// ‘（’左括号，按钮事件响应
void CMFCCalculatorDlg::OnBnClickedButtonLbracket()
{
	AddToEditExp(IDC_BUTTON_LBRACKET);
}


// ‘）’右括号，按钮事件响应
void CMFCCalculatorDlg::OnBnClickedButtonRbracket()
{
	AddToEditExp(IDC_BUTTON_RBRACKET);
}


//‘||’绝对值，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButtonAbs()
{
	AddToEditExp(IDC_BUTTON_ABS);
}


//‘！’阶乘，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButtonFac()
{
	AddToEditExp(IDC_BUTTON_FAC);
}


//‘^’幂次方，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButtonPow()
{
	AddToEditExp(IDC_BUTTON_POW);
}


//‘/’除法，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButtonDiv()
{
	AddToEditExp(IDC_BUTTON_DIV);
}


//‘*’乘法，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButtonMul()
{
	AddToEditExp(IDC_BUTTON_MUL);
}


//‘-’减法，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButtonSub()
{
	AddToEditExp(IDC_BUTTON_SUB);
}


//‘+’加法，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButtonAdd()
{
	AddToEditExp(IDC_BUTTON_ADD);
}


//‘%’余数，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButtonRem()
{
	AddToEditExp(IDC_BUTTON_REM);
}

//‘Cos’cos，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedRadioCos()
{
	if (test == 1)OnBnClickedButtonDelete();
	AddToEditExp(IDC_RADIO_COS);
	CString strExp;
	GetDlgItem(IDC_EDIT_EXP)->GetWindowText(strExp);
	strExp = strExp.Left(strExp.GetLength() - 2);
	SetDlgItemText(IDC_EDIT_EXP, strExp);
	test = 1;
}

//‘Sin’sin，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedRadioSin()
{
	if (test == 1)OnBnClickedButtonDelete();
	AddToEditExp(IDC_RADIO_SIN);
	CString strExp;
	GetDlgItem(IDC_EDIT_EXP)->GetWindowText(strExp);
	strExp = strExp.Left(strExp.GetLength() - 2);
	SetDlgItemText(IDC_EDIT_EXP, strExp);
	test = 1;
}

//‘Tan’tan，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedRadioTan()
{
	if (test == 1)OnBnClickedButtonDelete();
	AddToEditExp(IDC_RADIO_TAN);
	CString strExp;
	GetDlgItem(IDC_EDIT_EXP)->GetWindowText(strExp);
	strExp = strExp.Left(strExp.GetLength() - 2);
	SetDlgItemText(IDC_EDIT_EXP, strExp);
	test = 1;

}

//‘Log10’log10，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedRadioLog10()
{
	if (test == 1)OnBnClickedButtonDelete();
	AddToEditExp(IDC_RADIO_LOG10);
	CString strExp;
	GetDlgItem(IDC_EDIT_EXP)->GetWindowText(strExp);
	strExp = strExp.Left(strExp.GetLength() - 4);
	SetDlgItemText(IDC_EDIT_EXP, strExp);
	test = 1;
}


//‘.’小数点，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButtonDot()
{
	AddToEditExp(IDC_BUTTON_DOT);
}

//‘0’数字，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButton0()
{
	AddToEditExp(IDC_BUTTON_0);
}

//‘1’数字，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButton1()
{
	AddToEditExp(IDC_BUTTON_1);
}

//‘2’数字，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButton2()
{
	AddToEditExp(IDC_BUTTON_2);
}

//‘3’数字，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButton3()
{
	AddToEditExp(IDC_BUTTON_3);
}

//‘4’数字，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButton4()
{
	AddToEditExp(IDC_BUTTON_4);
}

//‘5’数字，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButton5()
{
	AddToEditExp(IDC_BUTTON_5);
}

//‘6’数字，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButton6()
{
	AddToEditExp(IDC_BUTTON_6);
}

//‘7’数字，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButton7()
{
	AddToEditExp(IDC_BUTTON_7);
}

//‘8’数字，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButton8()
{
	AddToEditExp(IDC_BUTTON_8);
}

//‘9’数字，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButton9()
{
	AddToEditExp(IDC_BUTTON_9);
}


// ‘C/CE’清0，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButtonClear()
{
	SetDlgItemText(IDC_EDIT_EXP, NULL);
	CString cstr;
	cstr = "0";
	SetDlgItemText(IDC_STATIC_RESULT, cstr);
}


// ‘delete’退格，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButtonDelete()
{
	CString strExp;
	GetDlgItem(IDC_EDIT_EXP)->GetWindowText(strExp);
	strExp = strExp.Left(strExp.GetLength() - 1);
	SetDlgItemText(IDC_EDIT_EXP, strExp);
}


//‘=’等于，按钮事件处理
void CMFCCalculatorDlg::OnBnClickedButtonEqual()
{
	CString strExp;
	Calculator cal;		//计算类
	CString cstr_Result;
	CString cstr_ErrorInfo;

	GetDlgItem(IDC_EDIT_EXP)->GetWindowText(strExp);
	string infix(CW2A(strExp.GetString()));
	cal.calculate(infix);
	cstr_Result.Format(_T("%f"), cal.getResult());
	SetDlgItemText(IDC_STATIC_RESULT, cstr_Result);
}

//表达式输入文本区
void CMFCCalculatorDlg::OnEnChangeEditExp()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}





void CMFCCalculatorDlg::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	UpdateData(FALSE);
}
