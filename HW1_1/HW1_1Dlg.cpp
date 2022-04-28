
// HW1_1Dlg.cpp : 實作檔
//

#include "stdafx.h"
#include "HW1_1.h"
#include "HW1_1Dlg.h"
#include "afxdialogex.h"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\opencv.hpp"
#include "iostream"
#include "cmath"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
using namespace cv;

// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
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


// CHW1_1Dlg 對話方塊



CHW1_1Dlg::CHW1_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HW1_1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHW1_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHW1_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CHW1_1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CHW1_1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CHW1_1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CHW1_1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CHW1_1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CHW1_1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CHW1_1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CHW1_1Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CHW1_1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CHW1_1Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CHW1_1Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CHW1_1Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CHW1_1Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CHW1_1Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CHW1_1Dlg::OnBnClickedButton15)
END_MESSAGE_MAP()


// CHW1_1Dlg 訊息處理常式

BOOL CHW1_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	


	// TODO: 在此加入額外的初始設定

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CHW1_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CHW1_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CHW1_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//string path = "./image/";
//1.1
Mat img,out,img2;

void CHW1_1Dlg::OnBnClickedButton1()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	img = imread("./image/sun.jpg");
	imshow("Hw1-1", img);
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	cout << "Height: "<<img.rows<<endl;
	cout << "Width: " << img.cols << endl;
	FreeConsole();
	
}

//1.2
void CHW1_1Dlg::OnBnClickedButton2()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	img = imread("./image/sun.jpg");
	vector<Mat>rgbchannels(3);
	split(img, rgbchannels);
	Mat zero_ch = Mat::zeros(Size(img.cols, img.rows), CV_8UC1);
	vector<Mat>bgr_channel;
	bgr_channel.push_back(rgbchannels[0]);
	bgr_channel.push_back(zero_ch);
	bgr_channel.push_back(zero_ch);
	merge(bgr_channel, out);
	imshow("B", out);

	bgr_channel.clear();
	bgr_channel.push_back(zero_ch);
	bgr_channel.push_back(rgbchannels[1]);
	bgr_channel.push_back(zero_ch);
	merge(bgr_channel, out);
	imshow("G", out);

	bgr_channel.clear();
	bgr_channel.push_back(zero_ch);
	bgr_channel.push_back(zero_ch);
	bgr_channel.push_back(rgbchannels[2]);
	merge(bgr_channel, out);
	imshow("R", out);

}

//1.3
void CHW1_1Dlg::OnBnClickedButton3()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	img = imread("./image/sun.jpg");
	transform(img, out, Matx13f(0.07, 0.72, 0.21));
	imshow("1-3.1", out);
	cvtColor(img, out, CV_RGB2GRAY);
	imshow("1-3.2", out);
}

//1.4
double alpha=0, beta;
int alpha_slider, alpha_slider_max=255;
void on_trackbar(int ,void*)
{
	alpha = (double)alpha_slider / alpha_slider_max;
	beta = 1.0 - alpha;
	addWeighted(img, alpha, img2, beta, 0.0, out);
	imshow("Blend", out);
}


void CHW1_1Dlg::OnBnClickedButton4()
{	
	// TODO: 在此加入控制項告知處理常式程式碼
	img = imread("./image/Dog_Weak.jpg");
	img2 = imread("./image/Dog_Strong.jpg");
	namedWindow("Blend", WINDOW_AUTOSIZE);
	createTrackbar("Blend: ", "Blend", &alpha_slider, alpha_slider_max,on_trackbar);
	on_trackbar(alpha_slider, 0);

}

//2.1

void CHW1_1Dlg::OnBnClickedButton5()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	img = imread("./image/Lenna_whiteNoise.jpg");
	GaussianBlur(img, out, Size(5, 5),0,0);
	imshow("2-1", out);
}

//2.2

void CHW1_1Dlg::OnBnClickedButton6()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	img = imread("./image/Lenna_whiteNoise.jpg");
	bilateralFilter(img,out,9,90,90);
	imshow("2-2", out);
}

//2.3
void CHW1_1Dlg::OnBnClickedButton7()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	img = imread("./image/Lenna_ pepperSalt.jpg");
	medianBlur(img, out, 3);
	imshow("2-3.1", out);
	medianBlur(img, out, 5);
	imshow("2-3.2", out);
}

//3.1
double gfilter[3][3];
int check = 0;
Mat out2,sobel,sobelx,sobely,magnitude_out;
void grayscale() {
	img = imread("./image/House.jpg");
	out = imread("./image/House.jpg");
	int i, j;
	//grayscale
	for (i = 0; i < img.rows; i++) {
		for (j = 0; j < img.cols; j++) {
			int b = img.at<Vec3b>(i, j)[0] * 0.114;
			int g = img.at<Vec3b>(i, j)[1] * 0.587;
			int r = img.at<Vec3b>(i, j)[2] * 0.299;
			out.at<Vec3b>(i, j)[0] = b + g + r;
			out.at<Vec3b>(i, j)[1] = b + g + r;
			out.at<Vec3b>(i, j)[2] = b + g + r;
		}
	}
}

void generate_filter() {
	double r = 0.0, sum = 0.0;
	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			r = sqrt(x * x + y * y);
			gfilter[x+1][y+1] = (float)(exp(-(r * r)));
			sum += gfilter[x + 1][y + 1];
		}
	}
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			gfilter[i][j] /= sum;
	//AllocConsole();
	//freopen("CONOUT$", "w", stdout);

}

void applyfilter() {
	out2 = Mat::zeros(out.cols-2,out.rows-2, out.type());
	out.copyTo(out2);
	for (int i = 1; i < out.rows-1; ++i) {
		for (int j = 1; j < out.cols-1; ++j) {
			out2.at<Vec3b>(i - 1, j - 1)[0] = 0;
			out2.at<Vec3b>(i - 1, j - 1)[1] = 0;
			out2.at<Vec3b>(i - 1, j - 1)[2] = 0;
				for (int x = -1; x <= 1; ++x) {
					for (int y = -1; y <= 1; ++y) {
						out2.at<Vec3b>(i-1, j-1)[0] += gfilter[x + 1][y + 1]*out.at<Vec3b>(i+x,j+y)[0];
						out2.at<Vec3b>(i - 1, j - 1)[1] += gfilter[x + 1][y + 1] * out.at<Vec3b>(i + x, j + y)[1];
						out2.at<Vec3b>(i - 1, j - 1)[2] += gfilter[x + 1][y + 1] * out.at<Vec3b>(i + x, j + y)[2];
					}
				}
		}
	}
}

void applysobel() {
	sobel.copyTo(sobelx);
	sobel.copyTo(sobely);
	sobel.copyTo(magnitude_out);
	float gx = 0;
	for (int i = 1; i < out.rows - 2; ++i) {
		for (int j = 1; j < out.cols - 2; ++j) {
			sobelx.at<Vec3b>(i, j)[0] = abs(sobel.at<Vec3b>(i - 1, j + 1)[0] - sobel.at<Vec3b>(i - 1, j - 1)[0] + 2 * sobel.at<Vec3b>(i, j + 1)[0] - 2 * sobel.at<Vec3b>(i, j - 1)[0] + sobel.at<Vec3b>(i + 1, j + 1)[0] - sobel.at<Vec3b>(i + 1, j - 1)[0]);
			sobelx.at<Vec3b>(i, j)[1] = abs(sobel.at<Vec3b>(i - 1, j + 1)[1] - sobel.at<Vec3b>(i - 1, j - 1)[1] + 2 * sobel.at<Vec3b>(i, j + 1)[1] - 2 * sobel.at<Vec3b>(i, j - 1)[1] + sobel.at<Vec3b>(i + 1, j + 1)[1] - sobel.at<Vec3b>(i + 1, j - 1)[1]);
			sobelx.at<Vec3b>(i, j)[2] = abs(sobel.at<Vec3b>(i - 1, j + 1)[2] - sobel.at<Vec3b>(i - 1, j - 1)[2] + 2 * sobel.at<Vec3b>(i, j + 1)[2] - 2 * sobel.at<Vec3b>(i, j - 1)[2] + sobel.at<Vec3b>(i + 1, j + 1)[2] - sobel.at<Vec3b>(i + 1, j - 1)[2]);
			
			sobely.at<Vec3b>(i, j)[0] = abs(sobel.at<Vec3b>(i - 1, j + 1)[0] - sobel.at<Vec3b>(i + 1, j + 1)[0] + 2 * sobel.at<Vec3b>(i-1, j )[0] - 2 * sobel.at<Vec3b>(i+1, j )[0] + sobel.at<Vec3b>(i - 1, j - 1)[0] - sobel.at<Vec3b>(i + 1, j - 1)[0]);
			sobely.at<Vec3b>(i, j)[1] = abs(sobel.at<Vec3b>(i - 1, j + 1)[1] - sobel.at<Vec3b>(i + 1, j + 1)[1] + 2 * sobel.at<Vec3b>(i-1, j )[1] - 2 * sobel.at<Vec3b>(i+1, j )[1] + sobel.at<Vec3b>(i - 1, j - 1)[1] - sobel.at<Vec3b>(i + 1, j - 1)[1]);
			sobely.at<Vec3b>(i, j)[2] = abs(sobel.at<Vec3b>(i - 1, j + 1)[2] - sobel.at<Vec3b>(i + 1, j + 1)[2] + 2 * sobel.at<Vec3b>(i-1, j )[2] - 2 * sobel.at<Vec3b>(i+1, j )[2] + sobel.at<Vec3b>(i - 1, j - 1)[2] - sobel.at<Vec3b>(i + 1, j - 1)[2]);

			magnitude_out.at<Vec3b>(i, j)[0] = sqrt(sobelx.at<Vec3b>(i, j)[0] * sobelx.at<Vec3b>(i, j)[0] + sobely.at<Vec3b>(i, j)[0] * sobely.at<Vec3b>(i, j)[0]);
			magnitude_out.at<Vec3b>(i, j)[1] = sqrt(sobelx.at<Vec3b>(i, j)[1] * sobelx.at<Vec3b>(i, j)[1] + sobely.at<Vec3b>(i, j)[1] * sobely.at<Vec3b>(i, j)[1]);
			magnitude_out.at<Vec3b>(i, j)[2] = sqrt(sobelx.at<Vec3b>(i, j)[2] * sobelx.at<Vec3b>(i, j)[2] + sobely.at<Vec3b>(i, j)[2] * sobely.at<Vec3b>(i, j)[2]);
		}
	}
}
//3.1
void CHW1_1Dlg::OnBnClickedButton8()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	grayscale();
	generate_filter();
	applyfilter();
	imshow("3.1", out2);

	//imshow("grayscale", out);
}

//3.2
void CHW1_1Dlg::OnBnClickedButton9()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int i, j;
	//grayscale
	grayscale();
	generate_filter();
	applyfilter();
	//imshow("test", out2);

	sobel = Mat::zeros(out.cols - 2, out.rows - 2, out.type());
	out2.copyTo(sobel);
	applysobel();
	imshow("3.2", sobelx);
}

//3.3
void CHW1_1Dlg::OnBnClickedButton10()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	grayscale();
	generate_filter();
	applyfilter();
	sobel = Mat::zeros(out.cols - 2, out.rows - 2, out.type());
	out2.copyTo(sobel);
	applysobel();
	imshow("3.3", sobely);
}

//3.4
void CHW1_1Dlg::OnBnClickedButton11()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	grayscale();
	generate_filter();
	applyfilter();
	out2.copyTo(sobel);
	applysobel();
	imshow("3.4", magnitude_out);
}

//4.1
Mat resize_out=imread("./image/SQUARE-01.png"),translation_out = imread("./image/SQUARE-01.png"),rot_out = imread("./image/SQUARE-01.png"),shear_out = imread("./image/SQUARE-01.png");
void CHW1_1Dlg::OnBnClickedButton12()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	img = imread("./image/SQUARE-01.png");
	resize(img, resize_out, Size(256, 256));
	imshow("4.1", resize_out);
	//imshow("origin", img);
}

//4.2
void CHW1_1Dlg::OnBnClickedButton13()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	//img = imread("./image/SQUARE-01.png");
	Mat translation = Mat::zeros(2, 3, CV_32FC1);
	translation.at<float>(0, 0) = 1;
	translation.at<float>(1, 1) = 1;
	translation.at<float>(1, 2) = 60;
	warpAffine(resize_out, translation_out, translation, Size(400,300));
	//namedWindow("4.2", WINDOW_NORMAL);
	//resizeWindow("4.2", Size(400, 300));
	imshow("4.2", translation_out);

}

//4.3

void CHW1_1Dlg::OnBnClickedButton14()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat rot = getRotationMatrix2D(Point(128, 188), 10, 0.5);
	warpAffine(translation_out, rot_out, rot,Size(400, 300));
	imshow("4.3", rot_out);
}

//4.4
void CHW1_1Dlg::OnBnClickedButton15()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Point2f input[3] = { Point2f(50,50),Point2f(200,50) ,Point2f(50,200) };
	Point2f output[3] = { Point2f(10,100),Point2f(200,50) ,Point2f(100,250) };
	Mat warpMat(cv::Size(2, 3), CV_32F);
	warpMat = getAffineTransform(input, output);
	warpAffine(rot_out, out, warpMat, Size(400, 300));
	imshow("4.4", out);

}
