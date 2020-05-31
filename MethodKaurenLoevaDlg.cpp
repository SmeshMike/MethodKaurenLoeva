
// MethodKaurenLoevaDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MethodKaurenLoeva.h"
#include "MethodKaurenLoevaDlg.h"
#include "afxdialogex.h"
#include <fstream>
using namespace std;

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
	, n(3)
	, m(3)
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
	DDX_Text(pDX, IDC_M, m);
	DDX_Text(pDX, IDC_N, n);
}

BEGIN_MESSAGE_MAP(CMethodKaurenLoevaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CMethodKaurenLoevaDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMethodKaurenLoevaDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMethodKaurenLoevaDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RUNBUTTON, &CMethodKaurenLoevaDlg::OnBnClickedRunbutton)
	ON_BN_CLICKED(IDC_MATRIX, &CMethodKaurenLoevaDlg::OnBnClickedMatrix)
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




void CMethodKaurenLoevaDlg::OnBnClickedMatrix()
{
	// TODO: Add your control notification handler code here

	//if (n == m)
	//{

	//	double** mas = new double* [n];
	//	for (int i = 0; i < n; i++)
	//		mas[i] = new double[m];
	//	
	//	double* masTemp = new double[n * m];
	//	for (int i = 0; i < n*m; i++)
	//		masTemp[i] = (double)(rand() / RAND_MAX);
	//	


	//	for (int i = 0; i < n; i++)
	//		for (int j = 0; j < m; j++)
	//			mas[i][j] = masTemp[i * n + j];

	//	int** triangle = new int*[n];
	//	for (int i = 0; i < n * m; i++)
	//		triangle[i] = new int[m];
	//	
	//	for (int i = 0; i < n; i++)
	//		for (int j = 0; j < m; j++)
	//			triangle[i][j] = (int)mas[i, j];

	//	double** buf = new double* [n];
	//	for (int i = 0; i < n; i++)
	//		buf[i] = new double[m];

	//	for (int i = 0; i < n; i++)
	//		for (int j = 0; j < m; j++)
	//			buf[i, j] = mas[i, j];
	//			


	//	double** Pryamoy = Gaus_pryamoy_hod(R_Matrix(n, buf, Matrix(N)), N, 2 * M);


	//	Double[] U = new Double[N * M];
	//	Double[] V = new Double[N * M];
	//	Double[] Sigma = new Double[N * M];
	//	Double det = Determinant(Pryamoy, N);
	//	SVD(N, M, Mas, U, V, Sigma);
	//	Double[, ] V_ = new Double[N, M];
	//	Double[, ] U_ = new Double[N, M];
	//	Double[, ] U_transponirovannaya = new Double[N, M];

	//	Double[, ] Sigma_ = new Double[N, M];
	//	for (int i = 0; i < N; i++)
	//		for (int j = 0; j < M; j++)
	//			V_[i, j] = V[i * 3 + j];

	//	for (int i = 0; i < N; i++)
	//		for (int j = 0; j < M; j++)
	//			U_[i, j] = U[i * 3 + j];
	//	for (int i = 0; i < N; i++)
	//		for (int j = 0; j < M; j++)
	//			U_transponirovannaya[i, j] = U_[j, i];



	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < M; j++)
	//		{
	//			if (i == j)
	//			{
	//				if (Sigma[i] >= 0.1 * Sigma[0])
	//				{
	//					Sigma_[i, j] = 1 / Sigma[i];
	//				}
	//				else Sigma_[i, j] = 0;
	//			}

	//			else Sigma_[i, j] = 0;
	//		}
	//	}

	//	Double[, ] Matr = new Double[N, M];
	//	for (int i = 0; i < N; i++)
	//		for (int j = 0; j < M; j++)
	//			for (int k = 0; k < N; k++)
	//				Matr[i, j] += V_[i, k] * Sigma_[k, j];

	//	Double[, ] Psevdo_obratnaya_Matrix = new Double[N, M];
	//	for (int i = 0; i < N; i++)
	//		for (int j = 0; j < M; j++)
	//			for (int k = 0; k < N; k++)
	//				Psevdo_obratnaya_Matrix[i, j] += Matr[i, k] * U_transponirovannaya[k, j];
	//	Double[] B = new Double[N];

	//	for (int i = 0; i < N; i++)
	//		B[i] = Convert.ToDouble(rnd.Next(-2000, 2000)) / 2000;


	//	Double[] S = new Double[N];
	//	Double[] Ps = new Double[N * M];
	//	int z = 0;
	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < M; j++)
	//		{
	//			Ps[z] = Psevdo_obratnaya_Matrix[i, j];
	//			z++;
	//		}
	//	}

	//	for (int i = 0; i < N; i++)
	//	{
	//		S[i] = 0.0;

	//		for (int j = 0; j < N; j++)
	//		{
	//			S[i] += Ps[i * N + j] * B[j];
	//		}


	//	}

	//	// Вычисление невязки:
	//	Double E = 0.0;
	//	for (int i = 0; i < N; i++)
	//	{
	//		Double M_ = 0.0;
	//		for (int j = 0; j < N; j++)
	//		{
	//			M_ += Mas[i * N + j] * S[j];
	//		}

	//		E += (M_ - B[i]) * (M_ - B[i]) / N;
	//	}

	//	form.textBox_Nevayzky.Text = Convert.ToString(String.Format("{0:F4}", E));
	//	form.textBox_det.Text = Convert.ToString(String.Format("{0:F7}", det));
	//	StringBuilder S1 = new StringBuilder();
	//	StringBuilder S2 = new StringBuilder();
	//	StringBuilder S3 = new StringBuilder();
	//	StringBuilder S4 = new StringBuilder();
	//	StringBuilder S5 = new StringBuilder();
	//	StringBuilder S6 = new StringBuilder();
	//	StringBuilder S7 = new StringBuilder();
	//	StringBuilder S8 = new StringBuilder();
	//	//
	//	StringBuilder sw = new StringBuilder();

	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < M; j++)
	//		{
	//			S1.Append(Math.Round(mas[i, j], 2) + "   ");
	//		}

	//		S1.AppendLine("\n");
	//	}

	//	form.textBox_IshodMatr.TextAlign = HorizontalAlignment.Center;
	//	form.textBox_IshodMatr.Text = S1.ToString(); //Записывем в текст бокс исходный матрицу

	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < M; j++)
	//		{
	//			S2.Append(Math.Round(V_[i, j], 3) + "   ");
	//		}

	//		S2.AppendLine("\n");
	//	}

	//	form.textBox_MatrLS.TextAlign = HorizontalAlignment.Center;
	//	form.textBox_MatrLS.Text = S2.ToString(); //Записывем в текстбокс левую матрицу собственных векторов



	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < M; j++)
	//		{
	//			S3.Append(Math.Round(U_[i, j], 3) + "   ");
	//		}

	//		S3.AppendLine("\n");
	//	}

	//	form.textBox_MprS.TextAlign = HorizontalAlignment.Center;
	//	form.textBox_MprS.Text = S3.ToString(); //Записывем в текстбокс правую матрицу собственных векторов

	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < M; j++)
	//		{
	//			S4.Append(Math.Round(U_transponirovannaya[i, j], 3) + "   ");
	//		}

	//		S4.AppendLine("\n");
	//	}

	//	form.textBox_transpMatrL.TextAlign = HorizontalAlignment.Center;
	//	form.textBox_transpMatrL.Text =
	//		S4.ToString(); //Записывем в текстбокс правую матрицу собственных векторов



	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < M; j++)
	//		{
	//			S5.Append(Math.Round(Sigma_[i, j], 3) + "   ");
	//		}

	//		S5.AppendLine("\n" + "   ");
	//	}

	//	form.textBox_SZ.TextAlign = HorizontalAlignment.Center;
	//	form.textBox_SZ.Text = S5.ToString(); //Записывем в текстбокс матрицу соб.значений в степени -1.


	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < M; j++)
	//		{
	//			S6.Append(Math.Round(Psevdo_obratnaya_Matrix[i, j], 3) + "   ");
	//		}

	//		S6.AppendLine("\n");
	//	}

	//	form.textBox_PsObr.TextAlign = HorizontalAlignment.Center;
	//	form.textBox_PsObr.Text = S6.ToString(); //Записывем в текстбокс  псевдообратную  матрицу 

	//	for (int i = 0; i < N; i++)
	//		S7.AppendLine(Math.Round(S[i], 4) + "\n");
	//	S7.AppendLine("\n");
	//	form.textBox_Neizv.TextAlign = HorizontalAlignment.Center;
	//	form.textBox_Neizv.Text = S7.ToString(); //Записывем в текстбокс  псевдообратную  матрицу 
	//	for (int i = 0; i < N; i++)
	//		S8.AppendLine(Math.Round(B[i], 4) + "\n");
	//	form.textBox_svobod.TextAlign = HorizontalAlignment.Center;
	//	form.textBox_svobod.Text = S8.ToString(); //записываем в текстбокс векстор свободных членов
	//}

	UpdateData(TRUE);

	double** A = new double* [n];
	for (int i = 0; i < n; i++)
		A[i] = new double[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = (double)rand() * 2 / RAND_MAX - 1;

	ofstream fout; // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
	fout.open("cppstudio.txt"); // открываем файл для добавления информации к концу файла

	if (!fout.is_open())
	{
		return;
	}
	double A00 = A[0][0];
	double A01 = A[0][1];
	double A02 = A[0][2];
	double A10 = A[1][0];
	double A11 = A[1][1];
	double A12 = A[1][2];
	double A20 = A[2][0];
	double A21 = A[2][1];
	double A22 = A[2][2];

	fout << "Матрица А\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			fout << A[i][j] << "  ";
		}
		fout << "\n";
	}

	

	double* B = new double[m];
	for (int j = 0; j < m; j++)
		B[j] = (double)rand() * 2 / RAND_MAX - 1;

	double det;
	double* X = Reshenie(n, m, A, B, det);

	fout <<"\n\n\nДетерменант "<< det ; // запись строки в файл

	double* Am = new double[m * m];
	int r = 0;
	for (int i = 0; i < m; i++)//переход от двумерного массива в одномерный 
		for (int j = 0; j < n; j++)
		{
			Am[r] = A[i][j]; r++;
		}
	int Iter; double b1, b2;
	double* Sigma = new double[n];
	U = new double[m * m];
	V = new double[n * n];


	Iter = svd_hestenes(m, n, Am, U, V, Sigma);

	for (int i = 0; i < m; i++)//trasponirovanie+++ verno
	{
		for (int j = 0; j < n; j++)
		{
			if ((i * n + j) < (j * n + i))
			{
				b1 = V[i * n + j];
				V[i * n + j] = V[j * n + i];
				V[j * n + i] = b1;

				b2 = U[i * n + j];
				U[i * n + j] = U[j * n + i];
				U[j * n + i] = b2;
			}
		}
	}

	for (int i = 0; i < m; i++)//izmenenie sing chisel++++ verno
	{

		if (Sigma[i] != 0)
			Sigma[i] = 1 / Sigma[i];
		else Sigma[i] = 0;
	}
	double* Amx = new double[m * m];
	for (int i = 0; i < m; i++)//proizvedenie+++ verno
	{
		for (int j = 0; j < n; j++)
		{
			Amx[i * n + j] = V[i * n + j] * Sigma[j];
		}
	}
	double* Am_ = new double[m * m];
	Proizvedenie(n, m, Amx, U, Am_);/// Ам конечная матрица
	double* X0 = new double[n];
	for (int i = 0; i < m; i++)
	{
		X0[i] = 0;

	}

	for (int i = 0; i < m; i++)//proizvedenie 9x3+++++
		for (int j = 0; j < n; j++)
		{

			X0[i] += Am_[i * n + j] * B[j];

		}

	double X00;

	fout << "\n\nВектор B\n";
	for (int i = 0; i < n; i++)
	{
		fout << X0[i] << " ";
	}
	
	double buf = 0;  double E = 0;
	for (int i = 0; i < n; i++)
	{
		buf = 0;
		for (int j = 0; j < m; j++)
		{
			buf += Am[i * n + j] * X0[j];
		}
		E += (B[i] - buf) * (B[i] - buf);
	}
	E /= m;
	fout << "\n\n\nНевязка  "<< E <<'\n';

	fout.close(); // закрываем файл
	UpdateData(FALSE);
}


	double** CMethodKaurenLoevaDlg::R_Matrix(int n, double** A, double** Ed)//Расширенная матрица
	{
		double** R = new double* [n];
		for (int i = 0; i < 2 * n; i++)
			R[i] = new double[2 * n];


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 2 * n; j++)
				R[i][j] = ((j < n) ? A[i][j] : Ed[i][j - n]);

		}
		return R;
	}

	double** CMethodKaurenLoevaDlg::Gaus_pryamoy_hod(double** R, int n, int m)
	{
		double temp = 0;

		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				temp = (R[i][j] / R[i][i]);
				for (int k = i; k < m; k++)
				{
					R[j][k] -= (R[i][k] * temp);
				}

			}
		return R;
	}


	double** CMethodKaurenLoevaDlg::Matrix(int n)//создание матрицы размером NxM
	{
		double** A = new double* [n];
		for (int i = 0; i < 2 * n; i++)
			A[i] = new double[2 * n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				A[i][j] = ((i == j) ? 1 : 0);
		return A;
	}


double* CMethodKaurenLoevaDlg::Reshenie(int N, int M, double** A, double* B, double& det)
{
	double* X0 = new double[M];
		
	det = 0;
	double** A1;//obr matriza
	A1 = new double* [M];
	for (int i = 0; i < N; i++)
		A1[i] = new double[M];
	A1[0][0] = (A[1][1] * A[2][2] - A[2][1] * A[1][2]);
	A1[0][1] = -(A[1][0] * A[2][2] - A[2][0] * A[1][2]);
	A1[0][2] = (A[1][0] * A[2][1] - A[2][0] * A[1][1]);

	A1[1][0] = -(A[0][1] * A[2][2] - A[2][1] * A[0][2]);
	A1[1][1] = (A[0][0] * A[2][2] - A[2][0] * A[0][2]);
	A1[1][2] = -(A[0][0] * A[2][1] - A[2][0] * A[0][1]);

	A1[2][0] = (A[0][1] * A[1][2] - A[1][1] * A[0][2]);
	A1[2][1] = -(A[0][0] * A[1][2] - A[1][0] * A[0][2]);
	A1[2][2] = (A[0][0] * A[1][1] - A[1][0] * A[0][1]);

	det += A1[0][0] * A[0][0];
	det += A1[1][0] * A[1][0];
	det += A1[2][0] * A[2][0];

	double s;
	s = A1[1][0]; A1[1][0] = A1[0][1]; A1[0][1] = s;
	s = A1[2][0]; A1[2][0] = A1[0][2]; A1[0][2] = s;
	s = A1[2][1]; A1[2][1] = A1[1][2]; A1[1][2] = s;
	/*ofstream file("ReadMe.txt");
	for (int t = 0; t < N; t++)
	{
	for (int i = 0; i < N; i++)
	{
	file.width(10);
	file << A1[t][i] << setw(5) << endl;
	}
	}
	file.close();*/
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			A1[i][j] = A1[i][j] / det;//polychili obr matrizy



	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			X0[i] += A1[i][j] * B[j];

	return X0;
}

void CMethodKaurenLoevaDlg::Proizvedenie(int N, int M, double* A1, double* A2, double* Am)
{
	for (int j = 0; j < N * M; j++)
	{
		Am[j] = 0;
	}
	for (int i = 0; i < M; i++)//proizvedenie
	{
		for (int j = 0; j < N; j++)
		{
			for (int q = 0; q < N; q++)
			{
				Am[i * N + j] += A1[i * N + q] * A2[q * N + j];

			}
		}
	}
}