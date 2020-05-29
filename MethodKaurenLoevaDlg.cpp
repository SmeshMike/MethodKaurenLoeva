
// MethodKaurenLoevaDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MethodKaurenLoeva.h"
#include "MethodKaurenLoevaDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CMethodKaurenLoevaDlg dialog



CMethodKaurenLoevaDlg::CMethodKaurenLoevaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_METHODKAURENLOEVA_DIALOG, pParent)
	, a1(0)
	, a2(0)
	, a3(0)
	, a4(0)
	, b1(0)
	, b2(0)
	, b3(0)
	, b4(0)
	, c1(0)
	, c2(0)
	, c3(0)
	, c4(0)
	, size(750)
	, radioSin(false)
	, radioExp(false)
	, radioExpSin(false)
	, number(0)
	, corNum(100)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMethodKaurenLoevaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_A1, a1);
	DDX_Text(pDX, IDC_A2, a2);
	DDX_Text(pDX, IDC_A3, a3);
	DDX_Text(pDX, IDC_A4, a4);
	DDX_Text(pDX, IDC_B1, b1);
	DDX_Text(pDX, IDC_B2, b2);
	DDX_Text(pDX, IDC_B3, b3);
	DDX_Text(pDX, IDC_B4, b4);
	DDX_Text(pDX, IDC_C1, c1);
	DDX_Text(pDX, IDC_C2, c2);
	DDX_Text(pDX, IDC_C3, c3);
	DDX_Text(pDX, IDC_C4, c4);
	DDX_Text(pDX, IDC_CORNUM, corNum);
	DDX_Text(pDX, IDC_SIZE, size);
	DDX_Text(pDX, IDC_NUMBER, number);
}

BEGIN_MESSAGE_MAP(CMethodKaurenLoevaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CMethodKaurenLoevaDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMethodKaurenLoevaDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMethodKaurenLoevaDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RUNBUTTON, &CMethodKaurenLoevaDlg::OnBnClickedRunbutton)
END_MESSAGE_MAP()


// CMethodKaurenLoevaDlg message handlers

BOOL CMethodKaurenLoevaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	frameWnd1 = GetDlgItem(IDC_STATIC1);
	frameDC1 = frameWnd1->GetDC();
	frameWnd1->GetClientRect(&rect1);

	frameWnd2 = GetDlgItem(IDC_STATIC2);
	frameDC2 = frameWnd2->GetDC();
	frameWnd2->GetClientRect(&rect2);

	frameWnd3 = GetDlgItem(IDC_STATIC3);
	frameDC3 = frameWnd3->GetDC();
	frameWnd3->GetClientRect(&rect3);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMethodKaurenLoevaDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMethodKaurenLoevaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		CDC* MDc1 = new CDC();
		MDc1->CreateCompatibleDC(frameDC1);
		CBitmap bmp1;
		bmp1.CreateCompatibleBitmap(frameDC1, rect1.Width(), rect1.Height());
		CBitmap* tmp1 = MDc1->SelectObject(&bmp1);

		CDC* MDc2 = new CDC();
		MDc2->CreateCompatibleDC(frameDC2);
		CBitmap bmp2;
		bmp2.CreateCompatibleBitmap(frameDC2, rect2.Width(), rect2.Height());
		CBitmap* tmp2 = MDc2->SelectObject(&bmp2);

		CDC* MDc3 = new CDC();
		MDc3->CreateCompatibleDC(frameDC3);
		CBitmap bmp3;
		bmp3.CreateCompatibleBitmap(frameDC3, rect3.Width(), rect3.Height());
		CBitmap* tmp3 = MDc3->SelectObject(&bmp3);

		if (forSignal == true)
		{
			picture(MDc1, rect1, signal, 0, size);
			Draw(MDc1, rect1, signal, 255, 0, 0);
			picture(MDc2, rect2, sigmaGraph, 0, corNum);
			Draw(MDc2, rect2, sigmaGraph, 255, 0, 0);
		}

		if (forOther == true)
		{
			picture(MDc3, rect3, V1, 0, corNum);
			Draw(MDc3, rect3, V1, 255, 0, 0);

		}

		frameDC1->BitBlt(0, 0, rect1.Width(), rect1.Height(), MDc1, 0, 0, SRCCOPY);
		delete MDc1;
		frameDC2->BitBlt(0, 0, rect2.Width(), rect2.Height(), MDc2, 0, 0, SRCCOPY);
		delete MDc2;
		frameDC3->BitBlt(0, 0, rect3.Width(), rect3.Height(), MDc3, 0, 0, SRCCOPY);
		delete MDc3;

	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMethodKaurenLoevaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMethodKaurenLoevaDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	radioSin = true;
	radioExp = false;
	radioExpSin = false;

	GetDlgItem(IDC_AMPL)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_FREQUENCY)->ShowWindow(SW_SHOW);//делает видимой подпись частоты
	GetDlgItem(IDC_PHASE)->ShowWindow(SW_SHOW);//делает видимой подпись фазы

	GetDlgItem(IDC_CENTER)->ShowWindow(SW_HIDE);//делает невидимой подпись коэффициент затухания
	GetDlgItem(IDC_DISPERTION)->ShowWindow(SW_HIDE);//делает невидимой подпись дисперсии
	GetDlgItem(IDC_ATTENCOEF)->ShowWindow(SW_HIDE);//делает невидимой подпись средние

	a1 = 2; a2 = 1; a3 = 3; a4 = 0;
	b1 = 0.5; b2 = 0.1; b3 = 0.03; b4 = 0;
	c1 = 0; c2 = 0; c3 = 0; c4 = 0;

	UpdateData(false);
}


void CMethodKaurenLoevaDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	radioSin = false;
	radioExp = true;
	radioExpSin = false;

	GetDlgItem(IDC_AMPL)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_DISPERTION)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_CENTER)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_FREQUENCY)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PHASE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ATTENCOEF)->ShowWindow(SW_HIDE);

	a1 = 3; a2 = 2; a3 = 4; a4 = 0;
	b1 = 10; b2 = 12; b3 = 50; b4 = 10;
	c1 = 20; c2 = 120; c3 = 500; c4 = 0;

	UpdateData(false);
}


void CMethodKaurenLoevaDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	radioSin = false;
	radioExp = false;
	radioExpSin = true;

	GetDlgItem(IDC_AMPL)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_FREQUENCY)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ATTENCOEF)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_CENTER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_DISPERTION)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PHASE)->ShowWindow(SW_HIDE);

	a1 = 3; a2 = 1; a3 = 2; a4 = 0;
	b1 = 0.5; b2 = 0.7; b3 = 0.07; b4 = 0;
	c1 = 0.1; c2 = 0.2; c3 = 0.1; c4 = 0;

	UpdateData(false);
}


void CMethodKaurenLoevaDlg::OnBnClickedRunbutton()
{
	// TODO: Add your control notification handler code here

	UpdateData(true);

	signal.clear(); signal.resize(size + 1);

	if (radioSin == true)
		for (int i = 0; i < size; i++)
			signal[i] = a1 * sin(b1 * i + c1) +
			a2 * sin(b2 * i + c2) +
			a3 * sin(b3 * i + c3) +
			a4 * sin(b4 * i + c4);

	if (radioExp == true)
		for (int i = 0; i < size; i++)
			signal[i] = a1 * exp(-(double)(((i - c1) * (i - c1)) / (b1 * b1))) +
			a2 * exp(-(double)(((i - c2) * (i - c2)) / (b2 * b2))) +
			a3 * exp(-(double)(((i - c3) * (i - c3)) / (b3 * b3))) +
			a4 * exp(-(double)(((i - c4) * (i - c4)) / (b4 * b4)));

	if (radioExpSin == true)
		for (int i = 0; i < size + 1; i++)
			signal[i] = a1 * exp(-c1 * i) * sin(b1 * i) +
			a2 * exp(-c2 * i) * sin(b2 * i) +
			a3 * exp(-c3 * i) * sin(b3 * i) +
			a4 * exp(-c4 * i) * sin(b4 * i);
			
	corr = new double[(corNum + 1) * (corNum + 1)];
	U = new double[(corNum + 1) * (corNum + 1)];
	V = new double[(corNum + 1) * (corNum + 1)];
	sigma = new double[(corNum + 1)];
	double y;

	for (int i = 0; i < corNum + 1; i++)
	{
		y = 0;
		for (int j = 0; j < size - i; j++)
		{
			y += signal[j] * signal[i + j];
		}
		corr[i] = y / (size + 1 - i);
	}

	for (int i = 1; i < (corNum + 1); i++)
	{
		for (int j = 0; j < (corNum + 1); j++)
		{
			corr[i * (corNum + 1) + j] = corr[abs(j - i)];
		}
	}

	svd_hestenes((corNum + 1), (corNum + 1), corr, U, V, sigma);

	V1.clear(); V1.resize(corNum + 1);
	V2.clear(); V2.resize(corNum + 1);
	V3.clear(); V3.resize(corNum + 1);
	sigmaGraph.clear(); sigmaGraph.resize(corNum + 1);

	for (int i = 0; i < corNum + 1; i++)
	{
		sigmaGraph[i] = sigma[i];
		V1[i] = V[i * (corNum + 1) + number];
	}

	forSignal = true;
	forOther = true;
	Invalidate(0);

	UpdateData(false);

}


