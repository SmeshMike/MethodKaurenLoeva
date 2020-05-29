
// MethodKaurenLoeva.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "MethodKaurenLoeva.h"
#include "MethodKaurenLoevaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMethodKaurenLoevaApp

BEGIN_MESSAGE_MAP(CMethodKaurenLoevaApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMethodKaurenLoevaApp construction

CMethodKaurenLoevaApp::CMethodKaurenLoevaApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CMethodKaurenLoevaApp object

CMethodKaurenLoevaApp theApp;


// CMethodKaurenLoevaApp initialization

BOOL CMethodKaurenLoevaApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CMethodKaurenLoevaDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Delete the shell manager created above.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CMethodKaurenLoevaDlg::svd_hestenes(int m_m, int n_n, double* a, double* u, double* v, double* sigma)
{
	double thr = 1.E-4f, nul = 1.E-16f;
	int n, m, i, j, l, k, lort, iter, in, ll, kk;
	double alfa, betta, hamma, eta, t, cos0, sin0, buf, s;
	n = n_n;
	m = m_m;
	for (i = 0; i < n; i++)
	{
		in = i * n;
		for (j = 0; j < n; j++)
			if (i == j) v[in + j] = 1.;
			else v[in + j] = 0.;
	}
	for (i = 0; i < m; i++)
	{
		in = i * n;
		for (j = 0; j < n; j++)
		{
			u[in + j] = a[in + j];
		}
	}

	iter = 0;
	while (1)
	{
		lort = 0;
		iter++;
		for (l = 0; l < n - 1; l++)
			for (k = l + 1; k < n; k++)
			{
				alfa = 0.; betta = 0.; hamma = 0.;
				for (i = 0; i < m; i++)
				{
					in = i * n;
					ll = in + l;
					kk = in + k;
					alfa += u[ll] * u[ll];
					betta += u[kk] * u[kk];
					hamma += u[ll] * u[kk];
				}

				if (sqrt(alfa * betta) < nul)	continue;
				if (fabs(hamma) / sqrt(alfa * betta) < thr) continue;

				lort = 1;
				eta = (betta - alfa) / (2.f * hamma);
				t = (double)((eta / fabs(eta)) / (fabs(eta) + sqrt(1. + eta * eta)));
				cos0 = (double)(1. / sqrt(1. + t * t));
				sin0 = t * cos0;

				for (i = 0; i < m; i++)
				{
					in = i * n;
					buf = u[in + l] * cos0 - u[in + k] * sin0;
					u[in + k] = u[in + l] * sin0 + u[in + k] * cos0;
					u[in + l] = buf;

					if (i >= n) continue;
					buf = v[in + l] * cos0 - v[in + k] * sin0;
					v[in + k] = v[in + l] * sin0 + v[in + k] * cos0;
					v[in + l] = buf;
				}
			}

		if (!lort) break;
	}

	for (i = 0; i < n; i++)
	{
		s = 0.;
		for (j = 0; j < m; j++)	s += u[j * n + i] * u[j * n + i];
		s = (double)sqrt(s);
		sigma[i] = s;
		if (s < nul)	continue;
		for (j = 0; j < m; j++)	u[j * n + i] /= s;
	}
	//======= Sortirovka ==============
	for (i = 0; i < n - 1; i++)
		for (j = i; j < n; j++)
			if (sigma[i] < sigma[j])
			{
				s = sigma[i]; sigma[i] = sigma[j]; sigma[j] = s;
				for (k = 0; k < m; k++)
				{
					s = u[i + k * n]; u[i + k * n] = u[j + k * n]; u[j + k * n] = s;
				}
				for (k = 0; k < n; k++)
				{
					s = v[i + k * n]; v[i + k * n] = v[j + k * n]; v[j + k * n] = s;
				}
			}

	return iter;
}

void CMethodKaurenLoevaDlg::picture(CDC* pDC, CRect rect, vector <double> A, double x0, double x1)
{
	pDC->Rectangle(&rect);
	xCenter1 = (int)(rect.Width() - 50);// Вычитеам пиксели из всего окошка по оси х для того чтобы выводить амплитуды
	yCenter1 = (int)(rect.Height() - 30);// Вычитеам пиксели из всего окошка по оси у для того чтобы выводить отсчеты
	zoom(A);
	/*double xj = 0;
	double step = 1 / fd;

	xScale1 = xCenter1 / (N / fd);
	yScale1 = yCenter1 / ((y_max1 - y_min1));

	xstart1 = (int)(xj*xScale1) + 30;

	ystart1 = 10 + (int)(y_max1*(yCenter1 / (y_max1 - y_min1)));
	*/
	double y_step1 = (y_max1 - y_min1) / 10;
	CPen setka;
	setka.CreatePen(PS_SOLID, 1, RGB(128, 128, 128));
	pDC->SelectObject(&setka);

	CFont font;
	font.CreateFontW(13, 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, _T("Times New Roman"));
	CString str;

	pDC->SelectObject(&font);
	pDC->SetBkMode(1);

	///////////////////  ось X   ///////////////////////////////////////////////////////////////////////////
	for (double i = 40; i < (xCenter1 + 40); i += (xCenter1 / 10))
	{
		pDC->MoveTo(i, 10);
		pDC->LineTo(i, yCenter1 + 10);
	}
	for (int i = 0; i < 11; i++)
	{
		CString  str;
		str.Format(_T("%.2f"), i * ((x1 - x0) / 10));
		pDC->TextOutW(30 + (int)((xCenter1) / 10) * i, yCenter1 + 15, str);
		/*else
			for (int i = 0; i < 10; i++)
			{
			CString  str;
			str.Format(_T("%.2f"), i*(fd / 9));
			pDC->TextOutW(30 + (int)((xCenter1) / 9)*i, yCenter1 + 15, str);
			}*/
			///////////////////  ось У   ///////////////////////////////////////////////////////////////////////////
		for (double i = 0; i <= (yCenter1); i += ((yCenter1) / (10) + 0.9))
		{
			pDC->MoveTo(xCenter1 + 40, 10 + i);
			pDC->LineTo(40, 10 + i);
		}
		for (int i = (0); i <= 10; i++)
		{
			CString  str;
			if (y_step1 < 30)
			{

				str.Format(_T("%.2f"), (double)(y_max1 - y_step1 * (i)));
				pDC->TextOutW(5, 5 + i * (int)(yCenter1) / 10, str);

			}
			else
			{
				if ((y_max1 - y_step1 * i) <= 1 && (y_max1 - y_step1 * i) >= -1)
				{
					str.Format(_T("%.2f"), (double)(y_max1 - y_step1 * (i)));
					pDC->TextOutW(5, 5 + i * (int)(yCenter1) / 10, str);
				}
				else
					str.Format(_T("%.0f"), (double)(y_max1 - y_step1 * (i)));
				pDC->TextOutW(5, 5 + i * (int)(yCenter1) / 10, str);
			}
		}
	}
}

void CMethodKaurenLoevaDlg::zoom(vector <double> A)
{
	double max = A[0];
	double min = A[0];

	int len = A.size();

	for (int i = 0; i < len; i++)//Вычисляет мах элемент
	{
		if (max < A[i]) max = A[i];
	}
	for (int i = 0; i < len; i++)//мин элемент
	{
		if (min > A[i]) min = A[i];
	}
	y_max1 = max;
	y_min1 = min;
}


void CMethodKaurenLoevaDlg::Draw(CDC* pDC, CRect rect, vector <double> A, int R, int G, int B)
{
	zoom(A);
	xCenter1 = (int)(rect.Width() - 50);//Вычитаем из всего окошка число пикселей для подписи чисел
	yCenter1 = (int)(rect.Height() - 30);//

	double xj = 0;//Текущий х
	double step = 1;//Шаг

	xScale1 = (double)(xCenter1 - xCenter1 % 10);//Шаг в пикселях по х
	xScale1 /= A.size() - 1;
	yScale1 = yCenter1 / ((y_max1 - y_min1));// по у

	xstart1 = 40;// Точка начала отрисовки графика в пикселях по х

	ystart1 = 10 + (int)(y_max1 * (yCenter1 / (y_max1 - y_min1)));// по у

	CPen pen, * oldpen;
	pen.CreatePen(PS_SOLID, 2, RGB(R, G, B));

	oldpen = pDC->SelectObject(&pen);

	pDC->MoveTo(xstart1, (int)(-A[0] * yScale1) + ystart1);

	int len = A.size();
	int asd = len;
	for (int i = 0; i < asd; i++)//Отрисовка графика
	{
		pDC->LineTo(xstart1 + (int)(xj * xScale1), (int)(-A[i] * yScale1) + ystart1);
		xj += step;
	}
	pen.DeleteObject();
}