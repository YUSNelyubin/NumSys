
// MainDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "NumSys.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "Question.h"
#include "QCountDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


BYTE qcount = 20;//���������� ��������
BYTE vcount = 4;//���������� ��������� ������
Question *questions = NULL;//�������
BYTE qnumber;//����� ����������� �������
CButton *abuttons = NULL;//����� ��� �������
BYTE *userans = NULL;//������ ������������
CString topic;

// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
public:

};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CMainDlg




CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_QNUM, lNumQuest);
	DDX_Control(pDX, IDC_QUESTION, lQuestion);
	DDX_Control(pDX, IDC_BACK, bBack);
	DDX_Control(pDX, IDC_NEXT, bNext);
	DDX_Control(pDX, IDC_HELP, bHelp);
	DDX_Control(pDX, IDC_END, bEnd);
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32773, &CMainDlg::On10ToN)
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_NEXT, &CMainDlg::OnBnClickedNext)
	ON_BN_CLICKED(IDC_BACK, &CMainDlg::OnBnClickedBack)
	ON_BN_CLICKED(IDC_END, &CMainDlg::OnBnClickedEnd)
	ON_BN_CLICKED(IDC_HELP, &CMainDlg::OnBnClickedHelp)
	ON_COMMAND(ID_32782, &CMainDlg::On10ToNTest)
	ON_COMMAND(ID_Menu, &CMainDlg::OnNTo10)
	ON_COMMAND(ID_32783, &CMainDlg::OnNTo10Test)
	ON_COMMAND(ID_32776, &CMainDlg::On2To8)
	ON_COMMAND(ID_32784, &CMainDlg::On2To8Test)
	ON_COMMAND(ID_32777, &CMainDlg::On8To2)
	ON_COMMAND(ID_32785, &CMainDlg::On8To2Test)
	ON_COMMAND(ID_32779, &CMainDlg::On2To16)
	ON_COMMAND(ID_32786, &CMainDlg::On2To16Test)
	ON_COMMAND(ID_32780, &CMainDlg::On16To2)
	ON_COMMAND(ID_32787, &CMainDlg::On16To2Test)
	ON_COMMAND(ID_32790, &CMainDlg::OnNToN)
	ON_COMMAND(ID_32791, &CMainDlg::OnAdd)
	ON_COMMAND(ID_32796, &CMainDlg::OnAddTest)
	ON_COMMAND(ID_32792, &CMainDlg::OnMin)
	ON_COMMAND(ID_32797, &CMainDlg::OnMinTest)
	ON_COMMAND(ID_32793, &CMainDlg::OnMul)
	ON_COMMAND(ID_32798, &CMainDlg::OnMulTest)
	ON_COMMAND(ID_32794, &CMainDlg::OnDiv)
	ON_COMMAND(ID_32799, &CMainDlg::OnDivTest)
	ON_COMMAND(ID_32800, &CMainDlg::OnArith)
	ON_COMMAND(ID_32810, &CMainDlg::OnAbout)
	ON_COMMAND(ID_32771, &CMainDlg::OnTheoryNs)
	ON_COMMAND(ID_32788, &CMainDlg::OnTheoryArithm)
	ON_COMMAND(ID_32805, &CMainDlg::OnMach_FixPoint)
	ON_COMMAND(ID_32812, &CMainDlg::OnMach_FixPointTest)
	ON_COMMAND(ID_32804, &CMainDlg::OnMach_FloatPoint)
	ON_COMMAND(ID_32811, &CMainDlg::OnMach_FloatPointTest)
	ON_COMMAND(ID_32807, &CMainDlg::OnMach_AddSign)
	ON_COMMAND(ID_32813, &CMainDlg::OnMach_AddSignTest)
	ON_COMMAND(ID_32808, &CMainDlg::OnMach_AddUnsign)
	ON_COMMAND(ID_32814, &CMainDlg::OnMach_AddUnsignTest)
	ON_COMMAND(ID_32801, &CMainDlg::OnTheoryMach)
	ON_COMMAND(ID_32809, &CMainDlg::OnViewHelp)
	ON_COMMAND(ID_32815, &CMainDlg::OnSetQCount)
END_MESSAGE_MAP()


// ����������� ��������� CMainDlg

BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
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

	// ������ ������ ��� ����� ����������� ����. ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������
	this->SetBackgroundColor(0xbbbbbb);
	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������. ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CMainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMainDlg::ShowQuestion(BYTE num)
{
	if (questions == NULL)
		return;
	if (abuttons != NULL)
	{
		delete[] abuttons;
		abuttons = NULL;
	}
	DWORD style;
	abuttons = new CButton[questions[num].GetVariantAnswerCount()];
	if (questions[num].GetAnswerCount() == 1)
		style = WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON;
	else
		style = WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX;
	for (BYTE i = 0; i < questions[num].GetVariantAnswerCount(); i++)
	{
		abuttons[i].Create(questions[num].GetVariant(i), style, CRect(10, i * 40 + 80, 500, i * 40 + 130), this, 2000 + i);
		abuttons[i].SetFont(this->GetFont());
	}

	lQuestion.SetWindowText(questions[num].name);

	char snum[4],//����� ������������� ������� � ��������� �������������
		scount[4];//���������� �������� � ��������� �������������
	itoa(num + 1, snum, 10);
	itoa(qcount, scount, 10);
	lNumQuest.SetWindowText((CString)snum + (CString)"/" +(CString)scount);
	RedrawWindow();
}

void CMainDlg::On10ToN()
{
	// TODO: �������� ���� ��� ����������� ������
	f10ToN();
	topic = "�������� �� ���� \"������� ���������, ������� ����� �� ���������� �.�. � ����� ������\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnDestroy()
{
	if (questions != NULL)
		delete[] questions;

	if (abuttons != NULL)
		delete[] abuttons;

	if (userans != NULL)
		delete[] userans;

	CDialogEx::OnDestroy();
}


void CMainDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	
}


void CMainDlg::OnBnClickedNext()
{
	// TODO: �������� ���� ��� ����������� �����������
	if (abuttons == NULL)
		return;
	for (BYTE i = 0; i < vcount; i++)
	{
		if (abuttons[i].GetCheck())
		{
			userans[qnumber] = i;
			break;
		}
	}

	if (qnumber + 1 < qcount)
	{
		qnumber++;
		ShowQuestion(qnumber);
		if (userans[qnumber] != 255)
			abuttons[userans[qnumber]].SetCheck(TRUE);
	}
}


void CMainDlg::OnBnClickedBack()
{
	// TODO: �������� ���� ��� ����������� �����������
	if (abuttons == NULL)
		return;

	for (BYTE i = 0; i < vcount; i++)
		if (abuttons[i].GetCheck())
		{
			userans[qnumber] = i;
			break;
		}

	if (qnumber - 1 >= 0)
	{
		qnumber--;
		ShowQuestion(qnumber);
		if (userans[qnumber] != 255)
			abuttons[userans[qnumber]].SetCheck(TRUE);
	}
}


void CMainDlg::OnBnClickedEnd()
{
	// TODO: �������� ���� ��� ����������� �����������
	for (BYTE i = 0; i < vcount; i++)
	{
		if (abuttons[i].GetCheck())
		{
			userans[qnumber] = i;
			break;
		}
	}

	bBack.EnableWindow(FALSE);
	bNext.EnableWindow(FALSE);
	bEnd.EnableWindow(FALSE);
	bHelp.EnableWindow(FALSE);
	if (abuttons != NULL)
	{
		delete[] abuttons;
		abuttons = NULL;
	}
	lNumQuest.SetWindowText(topic);
	BYTE n = 0;
	for (BYTE i = 0; i < qcount; i++)
		if (questions[i].GetAnswer(0) == userans[i])
			n++;

	char sn[4], sqcount[4];
	itoa(n, sn, 10);
	itoa(qcount, sqcount, 10);
	lQuestion.SetWindowText((CString)"��������: " + (CString)sn + (CString)" �� " + (CString)sqcount);
	RedrawWindow();
}


void CMainDlg::OnBnClickedHelp()
{
	// TODO: �������� ���� ��� ����������� �����������
	if (questions == NULL || abuttons == NULL)
		return;
	BYTE index = questions[qnumber].GetAnswer(0);
	CString str;
	abuttons[index].GetWindowText(str);
	abuttons[index].SetWindowText((CString)"-> " + str);
	RedrawWindow();
}

void CMainDlg::f10ToN()
{
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];

	srand(time(NULL));
	for (BYTE i = 0; i < qcount; i++)
	{
		USHORT a = rand() % 1000 + 1;//���������� ����� ������� ��������� ���������
		BYTE ns;//� ����� ������� ��������� ��������� ��������� �����
		switch (rand() % 3)
		{
		case 0: ns = 2;
			break;
		case 1: ns = 8;
			break;
		case 2: ns = 16;
			break;
		}
		char an[11], sa[4], sns[3];
		itoa(a, sa, 10);
		itoa(ns, sns, 10);
		itoa(a, an, ns);
		questions[i].name = (CString)sa + (CString)"(10) -> " + (CString)sns + (CString)"?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			a = rand() % 1000 + 1;
			itoa(a, an, ns);
			questions[i].SetVariant(j, (CString)an);
		}
	}
	//������� ������
	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::On10ToNTest()
{
	// TODO: �������� ���� ��� ����������� ������
	f10ToN();
	topic = "������������ �� ���� \"������� ���������, ������� ����� �� ���������� �.�. � ����� ������\"";
	bHelp.EnableWindow(FALSE);
}

void CMainDlg::fNTo10()
{
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];

	srand(time(NULL));
	//
	for (BYTE i = 0; i < qcount; i++)
	{
		USHORT a = rand() % 1000 + 1;
		BYTE ns;
		switch (rand() % 3)
		{
		case 0: ns = 2;
			break;
		case 1: ns = 8;
			break;
		case 2: ns = 16;
			break;
		}
		char an[4], sa[11], sns[3];
		itoa(a, sa, ns);
		itoa(ns, sns, 10);
		itoa(a, an, 10);
		questions[i].name = (CString)sa + (CString)"(" + (CString)sns + (CString)") -> 10?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			a = rand() % 1000 + 1;
			itoa(a, an, 10);
			questions[i].SetVariant(j, (CString)an);
		}
	}

	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::OnNTo10()
{
	// TODO: �������� ���� ��� ����������� ������
	fNTo10();
	topic = "�������� �� ���� \"������� ���������, ������� ����� �� ����� �.�. � ����������\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnNTo10Test()
{
	// TODO: �������� ���� ��� ����������� ������
	fNTo10();
	topic = "������������ �� ���� \"������� ���������, ������� ����� �� ����� �.�. � ����������\"";
	bHelp.EnableWindow(FALSE);
}

void CMainDlg::f2To8()
{
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];

	srand(time(NULL));
	//
	for (BYTE i = 0; i < qcount; i++)
	{
		USHORT a = rand() % 1000 + 1;
		char an[8], sa[11];
		itoa(a, sa, 2);
		itoa(a, an, 8);
		questions[i].name = (CString)sa + (CString)"(2) -> 8?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			a = rand() % 1000 + 1;
			itoa(a, an, 8);
			questions[i].SetVariant(j, (CString)an);
		}
	}

	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::On2To8()
{
	// TODO: �������� ���� ��� ����������� ������
	f2To8();
	topic = "�������� �� ���� \"������� ���������, ������� ����� �� �������� �.�. � �����������\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::On2To8Test()
{
	// TODO: �������� ���� ��� ����������� ������
	f2To8();
	topic = "������������ �� ���� \"������� ���������, ������� ����� �� �������� �.�. � �����������\"";
	bHelp.EnableWindow(FALSE);
}

void CMainDlg::f8To2()
{
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];

	srand(time(NULL));
	//
	for (BYTE i = 0; i < qcount; i++)
	{
		USHORT a = rand() % 1000 + 1;
		char an[11], sa[8];
		itoa(a, sa, 8);
		itoa(a, an, 2);
		questions[i].name = (CString)sa + (CString)"(8) -> 2?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			a = rand() % 1000 + 1;
			itoa(a, an, 2);
			questions[i].SetVariant(j, (CString)an);
		}
	}

	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::On8To2()
{
	// TODO: �������� ���� ��� ����������� ������
	f8To2();
	topic = "�������� �� ���� \"������� ���������, ������� ����� �� ����������� �.�. � ��������\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::On8To2Test()
{
	// TODO: �������� ���� ��� ����������� ������
	f8To2();
	topic = "������������ �� ���� \"������� ���������, ������� ����� �� ����������� �.�. � ��������\"";
	bHelp.EnableWindow(FALSE);
}

void CMainDlg::f2To16()
{
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];

	srand(time(NULL));
	//
	for (BYTE i = 0; i < qcount; i++)
	{
		USHORT a = rand() % 1000 + 1;
		char an[8], sa[11];
		itoa(a, sa, 2);
		itoa(a, an, 16);
		questions[i].name = (CString)sa + (CString)"(2) -> 16?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			a = rand() % 1000 + 1;
			itoa(a, an, 16);
			questions[i].SetVariant(j, (CString)an);
		}
	}

	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::On2To16()
{
	// TODO: �������� ���� ��� ����������� ������
	f2To16();
	topic = "�������� �� ���� \"������� ���������, ������� ����� �� �������� �.�. � �����������������\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::On2To16Test()
{
	// TODO: �������� ���� ��� ����������� ������
	f2To16();
	topic = "������������ �� ���� \"������� ���������, ������� ����� �� �������� �.�. � �����������������\"";
	bHelp.EnableWindow(FALSE);
}

void CMainDlg::f16To2()
{
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];

	srand(time(NULL));
	//
	for (BYTE i = 0; i < qcount; i++)
	{
		USHORT a = rand() % 1000 + 1;
		char an[11], sa[8];
		itoa(a, sa, 16);
		itoa(a, an, 2);
		questions[i].name = (CString)sa + (CString)"(16) -> 2?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			a = rand() % 1000 + 1;
			itoa(a, an, 2);
			questions[i].SetVariant(j, (CString)an);
		}
	}

	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::On16To2()
{
	// TODO: �������� ���� ��� ����������� ������
	f16To2();
	topic = "�������� �� ���� \"������� ���������, ������� ����� �� ����������������� �.�. � ��������\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::On16To2Test()
{
	// TODO: �������� ���� ��� ����������� ������
	f16To2();
	topic = "������������ �� ���� \"������� ���������, ������� ����� �� ����������������� �.�. � ��������\"";
	bHelp.EnableWindow(FALSE);
}


void CMainDlg::OnNToN()
{
	// TODO: �������� ���� ��� ����������� ������
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];
	srand(time(NULL));
	for (BYTE i = 0; i < qcount; i++)
	{
		USHORT a = rand() % 1000 + 1;
		BYTE ns, ns2;
		switch (rand() % 3)
		{
		case 0: ns = 2;
			break;
		case 1: ns = 8;
			break;
		case 2: ns = 16;
			break;
		}

		switch (rand() % 3)
		{
		case 0: 
			if (ns != 2)
				ns2 = 2;
			else
				ns2 = 16;
			break;
		case 1:
			if (ns != 8)
				ns2 = 8;
			else
				ns2 = 2;
			break;
		case 2:
			if (ns != 16)
				ns2 = 16;
			else
				ns2 = 2;
			break;
		}

		char an[11], sa[11], sns[3], sns2[3];
		itoa(a, sa, ns2);
		itoa(ns, sns, 10);
		itoa(ns2, sns2, 10);
		itoa(a, an, ns);
		questions[i].name = (CString)sa + (CString)"(" + (CString)sns2 + (CString)") -> " + (CString)sns + (CString)"?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			a = rand() % 1000 + 1;
			itoa(a, an, ns);
			questions[i].SetVariant(j, (CString)an);
		}
	}
	//������� ������
	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
	topic = "�������� ���� �� ���� \"������� ���������\"";
	bHelp.EnableWindow(FALSE);
}

void CMainDlg::fAdd()
{
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];
	srand(time(NULL));


	for (BYTE i = 0; i < qcount; i++)
	{
		USHORT a = rand() % 1000 + 1,
			   b = rand() % 1000 + 1;
		char an[11], sa[11], sb[11];
		itoa(a, sa, 2);
		itoa(b, sb, 2);
		itoa(a + b, an, 2);
		questions[i].name = (CString)sa + (CString)" + " + (CString)sb + (CString)" = ?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			a = rand() % 1000 + 1;
			itoa(a, an, 2);
			questions[i].SetVariant(j, (CString)an);
		}
	}


	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::OnAdd()
{
	// TODO: �������� ���� ��� ����������� ������
	fAdd();
	topic = "�������� �� ���� \"�������� ����������, �������� �����\"";
	bHelp.EnableWindow(TRUE);

}


void CMainDlg::OnAddTest()
{
	// TODO: �������� ���� ��� ����������� ������
	fAdd();
	topic = "������������ �� ���� \"�������� ����������, �������� �����\"";
	bHelp.EnableWindow(FALSE);
}

void CMainDlg::fMin()
{
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];
	srand(time(NULL));


	for (BYTE i = 0; i < qcount; i++)
	{
		USHORT a = rand() % 1000 + 1,
			   b = rand() % 1000 + 1;
		char an[11], sa[11], sb[11];

		if (a < b)
		{
			a += b;
			b = a - b;
			a -= b;
		}

		itoa(a, sa, 2);
		itoa(b, sb, 2);
		itoa(a - b, an, 2);
		questions[i].name = (CString)sa + (CString)" - " + (CString)sb + (CString)" = ?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			a = rand() % 1000 + 1;
			itoa(a, an, 2);
			questions[i].SetVariant(j, (CString)an);
		}
	}


	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::OnMin()
{
	// TODO: �������� ���� ��� ����������� ������
	fMin();
	topic = "�������� �� ���� \"�������� ����������, ��������� �����\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnMinTest()
{
	// TODO: �������� ���� ��� ����������� ������
	fMin();
	topic = "������������ �� ���� \"�������� ����������, ��������� �����\"";
	bHelp.EnableWindow(FALSE);
}

void CMainDlg::fMul()
{
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];
	srand(time(NULL));


	for (BYTE i = 0; i < qcount; i++)
	{
		USHORT a = rand() % 100 + 2,
			   b = rand() % 10 + 2;
		char an[11], sa[11], sb[11];
		itoa(a, sa, 2);
		itoa(b, sb, 2);
		itoa(a * b, an, 2);
		questions[i].name = (CString)sa + (CString)" * " + (CString)sb + (CString)" = ?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			a = rand() % 1000 + 1;
			itoa(a, an, 2);
			questions[i].SetVariant(j, (CString)an);
		}
	}


	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}



void CMainDlg::OnMul()
{
	// TODO: �������� ���� ��� ����������� ������
	fMul();
	topic = "�������� �� ���� \"�������� ����������, ��������� �����\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnMulTest()
{
	// TODO: �������� ���� ��� ����������� ������
	fMul();
	topic = "������������ �� ���� \"�������� ����������, ��������� �����\"";
	bHelp.EnableWindow(FALSE);
}


void CMainDlg::fDiv()
{
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];
	srand(time(NULL));


	for (BYTE i = 0; i < qcount; i++)
	{
		USHORT a = rand() % 100 + 2,
			   b = rand() % 10 + 2;
		char an[11], sa[11], sb[11];

		if (a < b)
		{
			a += b;
			b = a - b;
			a -= b;
		}

		itoa(a, an, 2);
		a *= b;
		itoa(a, sa, 2);
		itoa(b, sb, 2);
		
		questions[i].name = (CString)sa + (CString)" / " + (CString)sb + (CString)" = ?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			a = rand() % 1000 + 1;
			itoa(a, an, 2);
			questions[i].SetVariant(j, (CString)an);
		}
	}


	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::OnDiv()
{
	// TODO: �������� ���� ��� ����������� ������
	fDiv();
	topic = "�������� �� ���� \"�������� ����������, ������� �����\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnDivTest()
{
	// TODO: �������� ���� ��� ����������� ������
	fDiv();
	topic = "������������ �� ���� \"�������� ����������, ������� �����\"";
	bHelp.EnableWindow(FALSE);
}


void CMainDlg::OnArith()
{
	// TODO: �������� ���� ��� ����������� ������
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];
	srand(time(NULL));


	for (BYTE i = 0; i < qcount; i++)
	{
		USHORT a = rand() % 100 + 1,
			   b = rand() % 10 + 1;
		char an[11], sa[11], sb[11], ch;

		if (a < b)
		{
			a += b;
			b = a - b;
			a -+ b;
		}
		itoa(b, sb, 2);
		switch (rand() % 4)
		{
		case 0: ch = '+';
			itoa(a, sa, 2);
			itoa(a + b, an, 2);
			break;
		case 1: ch = '-';
			itoa(a, sa, 2);
			itoa(a - b, an, 2);
			break;
		case 2: ch = '*';
			a++;
			b++;
			itoa(a, sa, 2);
			itoa(a * b, an, 2);
			break;
		case 3: ch = '/';
			a++;
			b++;
			itoa(a, an, 2);
			itoa(a * b, sa, 2);
			break;
		}
		questions[i].name = (CString)sa + (CString)" " + (CString)ch + (CString)" " + (CString)sb + (CString)" = ?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			a = rand() % 1000 + 1;
			itoa(a, an, 2);
			questions[i].SetVariant(j, (CString)an);
		}
	}


	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::Mach_FixPoint()
{
	// TODO: �������� ���� ��� ����������� ������
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];
	srand(time(NULL));


	for (BYTE i = 0; i < qcount; i++)
	{
		short a = rand() % 2000 - 1000;
		char an[19], sa[5];
		unsigned long *c = (unsigned long*)&a;
		BYTE k = 0;
		itoa(a, sa, 10);
		for (short l = sizeof(a) * 8 - 1; l >= 0; l--)
		{
			if ((*c >> l) & 1)
				an[k] = '1';
			else
				an[k] = '0';
			if (l % 8 == 0 && k != 0 && l != 0)
			{
				an[++k] = ' ';
				an[++k] = ' ';
			}
			k++;
		}
		an[k] = '\0';
		questions[i].name = (CString)"����� " + (CString)sa + (CString)" � �������� ������������� ����� = ?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			a = rand() % 2000 - 1000;
			k = 0;
			for (short l = sizeof(a) * 8 - 1; l >= 0; l--)
			{
				if ((*c >> l) & 1)
					an[k] = '1';
				else
					an[k] = '0';
				if (l % 8 == 0 && k != 0 && l != 0)
				{
					an[++k] = ' ';
					an[++k] = ' ';
				}
				k++;
			}
			an[k] = '\0';
			questions[i].SetVariant(j, (CString)an);
		}
	}


	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::Mach_FloatPoint()
{
	// TODO: �������� ���� ��� ����������� ������
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];
	srand(time(NULL));


	for (BYTE i = 0; i < qcount; i++)
	{
		float a = rand() % 2000 * 0.9;
		char an[38], sa[7];
		unsigned long *c = (unsigned long*)&a;
		BYTE k = 0;
		std::stringstream ss;
		ss << a;
		ss >> sa;
		for (short l = sizeof(a) * 8 - 1; l >= 0; l--)
		{
			if ((*c >> l) & 1)
				an[k] = '1';
			else
				an[k] = '0';
			if (l % 8 == 0 && k != 0 && l != 0)
			{
				an[++k] = ' ';
				an[++k] = ' ';
			}
			k++;
		}
		an[k] = '\0';
		questions[i].name = (CString)"����� " + (CString)sa + (CString)" � �������� ������������� ����� = ?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			a = rand() % 2000 * 0.9;
			k = 0;
			for (short l = sizeof(a) * 8 - 1; l >= 0; l--)
			{
				if ((*c >> l) & 1)
					an[k] = '1';
				else
					an[k] = '0';
				if (l % 8 == 0 && k != 0 && l != 0)
				{
					an[++k] = ' ';
					an[++k] = ' ';
				}
				k++;
			}
			an[k] = '\0';
			questions[i].SetVariant(j, (CString)an);
		}
	}


	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::Mach_AddSign()
{
	// TODO: �������� ���� ��� ����������� ������
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];
	srand(time(NULL));


	for (BYTE i = 0; i < qcount; i++)
	{
		short a = rand() % 2000,
			  b = rand() % 1000;
		if (b == 0)
			b = 4;
		b = -b;

		char an[19], sa[19], sb[19];
		unsigned long *p = (unsigned long*)&a;
		BYTE k = 0;

		for (short l = sizeof(a) * 8 - 1; l >= 0; l--)
		{
			if ((*p >> l) & 1)
				sa[k] = '1';
			else
				sa[k] = '0';
			if (l % 8 == 0 && k != 0 && l != 0)
			{
				sa[++k] = ' ';
				sa[++k] = ' ';
			}
			k++;
		}
		sa[k] = '\0';
		k = 0;
		p = (unsigned long*)&b;

		for (short l = sizeof(b) * 8 - 1; l >= 0; l--)
		{
			if ((*p >> l) & 1)
				sb[k] = '1';
			else
				sb[k] = '0';
			if (l % 8 == 0 && k != 0 && l != 0)
			{
				sb[++k] = ' ';
				sb[++k] = ' ';
			}
			k++;
		}
		sb[k] = '\0';
		k = 0;
		a += b;

		for (short l = sizeof(a) * 8 - 1; l >= 0; l--)
		{
			if ((*p >> l) & 1)
				an[k] = '1';
			else
				an[k] = '0';
			if (l % 8 == 0 && k != 0 && l != 0)
			{
				an[++k] = ' ';
				an[++k] = ' ';
			}
			k++;
		}
		an[k] = '\0';
		questions[i].name = (CString)sa + (CString)" + " + (CString)sb + (CString)" = ?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			b = rand() % 2000 - 1000;
			k = 0;
			for (short l = sizeof(b) * 8 - 1; l >= 0; l--)
			{
				if ((*p >> l) & 1)
					an[k] = '1';
				else
					an[k] = '0';
				if (l % 8 == 0 && k != 0 && l != 0)
				{
					an[++k] = ' ';
					an[++k] = ' ';
				}
				k++;
			}
			an[k] = '\0';
			questions[i].SetVariant(j, (CString)an);
		}
	}


	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::Mach_AddUnsign()
{
	// TODO: �������� ���� ��� ����������� ������
	if (userans == NULL)
		userans = new BYTE[qcount];

	for (BYTE i = 0; i < qcount; i++)
		userans[i] = 255;
	if (questions == NULL)
		questions = new Question[qcount];
	srand(time(NULL));


	for (BYTE i = 0; i < qcount; i++)
	{
		short a = rand() % 2000,
			  b = rand() % 1000;
		if (b == 0)
			b = 4;

		char an[19], sa[19], sb[19];
		unsigned long *p = (unsigned long*)&a;
		BYTE k = 0;

		for (short l = sizeof(a) * 8 - 1; l >= 0; l--)
		{
			if ((*p >> l) & 1)
				sa[k] = '1';
			else
				sa[k] = '0';
			if (l % 8 == 0 && k != 0 && l != 0)
			{
				sa[++k] = ' ';
				sa[++k] = ' ';
			}
			k++;
		}
		sa[k] = '\0';
		k = 0;
		p = (unsigned long*)&b;

		for (short l = sizeof(b) * 8 - 1; l >= 0; l--)
		{
			if ((*p >> l) & 1)
				sb[k] = '1';
			else
				sb[k] = '0';
			if (l % 8 == 0 && k != 0 && l != 0)
			{
				sb[++k] = ' ';
				sb[++k] = ' ';
			}
			k++;
		}
		sb[k] = '\0';
		k = 0;
		a += b;

		for (short l = sizeof(a) * 8 - 1; l >= 0; l--)
		{
			if ((*p >> l) & 1)
				an[k] = '1';
			else
				an[k] = '0';
			if (l % 8 == 0 && k != 0 && l != 0)
			{
				an[++k] = ' ';
				an[++k] = ' ';
			}
			k++;
		}
		an[k] = '\0';
		questions[i].name = (CString)sa + (CString)" + " + (CString)sb + (CString)" = ?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//����� �� ����� ����� ������ �����
		questions[i].SetAnswer(0, ians);
		questions[i].SetVariant(ians, (CString)an);
		for (BYTE j = 0; j < vcount; j++)
		{
			if (j == ians)
				continue;
			b = rand() % 2000 - 1000;
			k = 0;
			for (short l = sizeof(b) * 8 - 1; l >= 0; l--)
			{
				if ((*p >> l) & 1)
					an[k] = '1';
				else
					an[k] = '0';
				if (l % 8 == 0 && k != 0 && l != 0)
				{
					an[++k] = ' ';
					an[++k] = ' ';
				}
				k++;
			}
			an[k] = '\0';
			questions[i].SetVariant(j, (CString)an);
		}
	}


	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::OnAbout()
{
	// TODO: �������� ���� ��� ����������� ������
	CAboutDlg dlg;
	dlg.DoModal();
}


void CMainDlg::OnTheoryNs()
{
	// TODO: �������� ���� ��� ����������� ������
	HtmlHelpA(NULL, "NumSys.chm::/1.html", HH_DISPLAY_TOPIC, NULL);
}


void CMainDlg::OnTheoryArithm()
{
	// TODO: �������� ���� ��� ����������� ������
	HtmlHelpA(NULL, "NumSys.chm::/2.html", HH_DISPLAY_TOPIC, NULL);
}


void CMainDlg::OnMach_FixPoint()
{
	// TODO: �������� ���� ��� ����������� ������
	Mach_FixPoint();
	topic = "�������� �� ���� \"�������� ������������� ����� � ������������� ������\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnMach_FixPointTest()
{
	// TODO: �������� ���� ��� ����������� ������
	Mach_FixPoint();
	topic = "������������ �� ���� \"�������� ������������� ����� � ������������� ������\"";
	bHelp.EnableWindow(FALSE);
}


void CMainDlg::OnMach_FloatPoint()
{
	// TODO: �������� ���� ��� ����������� ������
	Mach_FloatPoint();
	topic = "�������� �� ���� \"�������� ������������� ����� � ��������� ������\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnMach_FloatPointTest()
{
	// TODO: �������� ���� ��� ����������� ������
	Mach_FloatPoint();
	topic = "������������ �� ���� \"�������� ������������� ����� � ��������� ������\"";
	bHelp.EnableWindow(FALSE);
}


void CMainDlg::OnMach_AddSign()
{
	// TODO: �������� ���� ��� ����������� ������
	Mach_AddSign();
	topic = "�������� �� ���� \"�������� ������������� �����, �������� �������� �����\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnMach_AddSignTest()
{
	// TODO: �������� ���� ��� ����������� ������
	Mach_AddSign();
	topic = "������������ �� ���� \"�������� ������������� �����, �������� �������� �����\"";
	bHelp.EnableWindow(FALSE);
}


void CMainDlg::OnMach_AddUnsign()
{
	// TODO: �������� ���� ��� ����������� ������
	Mach_AddUnsign();
	topic = "�������� �� ���� \"�������� ������������� �����, �������� ����������� �����\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnMach_AddUnsignTest()
{
	// TODO: �������� ���� ��� ����������� ������
	Mach_AddUnsign();
	topic = "������������ �� ���� \"�������� ������������� �����, �������� ����������� �����\"";
	bHelp.EnableWindow(FALSE);
}


void CMainDlg::OnTheoryMach()
{
	// TODO: �������� ���� ��� ����������� ������
	HtmlHelpA(NULL, "NumSys.chm::/4.html", HH_DISPLAY_TOPIC, NULL);
}


void CMainDlg::OnViewHelp()
{
	// TODO: �������� ���� ��� ����������� ������
	HtmlHelpA(NULL, "NumSys.chm::/3.html", HH_DISPLAY_TOPIC, NULL);
}


void CMainDlg::OnSetQCount()
{
	// TODO: �������� ���� ��� ����������� ������
	CQCountDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		BYTE a = _wtoi(dlg.sQCount);
		if (a == qcount || a == 0 || a > 250)
			return;
		qcount = a;
		if (userans != NULL)
			delete[] userans;
		if (questions != NULL)
			delete[] questions;
		userans = new BYTE[qcount];
		questions = new Question[qcount];



		bBack.EnableWindow(FALSE);
		bNext.EnableWindow(FALSE);
		bEnd.EnableWindow(FALSE);
		bHelp.EnableWindow(FALSE);
		if (abuttons != NULL)
		{
			delete[] abuttons;
			abuttons = NULL;
		}
		lNumQuest.SetWindowText(L"");
		lQuestion.SetWindowText(L"");
		RedrawWindow();
	}
}
