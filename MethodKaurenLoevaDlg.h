
// MethodKaurenLoevaDlg.h : header file
//
#include <vector>
#pragma once

using namespace std;

// CMethodKaurenLoevaDlg dialog
class CMethodKaurenLoevaDlg : public CDialogEx
{
// Construction
public:
	CMethodKaurenLoevaDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_METHODKAURENLOEVA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	int svd_hestenes(int m_m, int n_n, double* a, double* u, double* v, double* sigma);
	void Draw(CDC* pDC, CRect rect, vector <double> A, int R, int G, int B);// Отрисовка графика
	void setka(CDC* pDC, CRect rect, vector <double> A, double x0, double x1);// Сетки
	void zoom(vector <double> A);// Функция для автоподстройки границ графика по оси у
	void picture(CDC* pDC, CRect rect, vector <double> A, double x0, double x1);// Функция вызывающая методы сетка и зум
	double** R_Matrix(int n, double** A, double** Ed);//Расширенная матрица
	double** Gaus_pryamoy_hod(double** R, int n, int m);
	double** CMethodKaurenLoevaDlg::Matrix(int n);
	double* Reshenie(int N, int M, double** A, double* B, double& det);
	void Proizvedenie(int N, int M, double* A1, double* A2, double* Am);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	double a1;
	double a2;
	double a3;
	double a4;
	double b1;
	double b2;
	double b3;
	double b4;
	double c1;
	double c2;
	double c3;
	double c4;
	int corNum;
	int size;
	int number;
	int m;
	int n;
	bool radioSin;
	bool radioExp;
	bool radioExpSin;
	bool forSignal;
	bool forOther;
	vector <double> signal;
	vector <double> sigmaGraph, V1, V2, V3;
	double* corr;
	double* U;
	double* V;
	double* sigma;

	CDC* frameDC1;
	CWnd* frameWnd1;
	CRect frameRect1, rect1;

	CDC* frameDC2;
	CWnd* frameWnd2;
	CRect frameRect2, rect2;

	CDC* frameDC3;
	CWnd* frameWnd3;
	CRect frameRect3, rect3;

	CDC* frameDC4;
	CWnd* frameWnd4;
	CRect frameRect4, rect4;

	CDC* frameDC5;
	CWnd* frameWnd5;
	CRect frameRect5, rect5;

	int xCenter1, yCenter1;// Для задания границ отрисовки сетки и графика, определяют ширину и высоту в пикселях
	double xScale1, yScale1;
	double xstart1, ystart1;
	double y_min1, y_max1;// мин и макс значения по амплитуде

	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRunbutton();
	afx_msg void OnBnClickedMatrix();
};
