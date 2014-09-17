
// MainDlg.cpp : файл реализации
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


BYTE qcount = 20;//Количество вопросов
BYTE vcount = 4;//Количество вариантов ответа
Question *questions = NULL;//Вопросы
BYTE qnumber;//Номер выдаваемого вопроса
CButton *abuttons = NULL;//Галки для ответов
BYTE *userans = NULL;//Ответы пользователя
CString topic;

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// диалоговое окно CMainDlg




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


// обработчики сообщений CMainDlg

BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	this->SetBackgroundColor(0xbbbbbb);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
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

	char snum[4],//Номер показываемого вопроса в текстовом представлении
		scount[4];//Количество вопросов в текстовом представлении
	itoa(num + 1, snum, 10);
	itoa(qcount, scount, 10);
	lNumQuest.SetWindowText((CString)snum + (CString)"/" +(CString)scount);
	RedrawWindow();
}

void CMainDlg::On10ToN()
{
	// TODO: добавьте свой код обработчика команд
	f10ToN();
	topic = "Практика по теме \"Системы счисления, перевод чисел из десятичной с.с. в любую другую\"";
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
	// TODO: добавьте свой код обработчика уведомлений
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
	// TODO: добавьте свой код обработчика уведомлений
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
	// TODO: добавьте свой код обработчика уведомлений
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
	lQuestion.SetWindowText((CString)"Павильно: " + (CString)sn + (CString)" из " + (CString)sqcount);
	RedrawWindow();
}


void CMainDlg::OnBnClickedHelp()
{
	// TODO: добавьте свой код обработчика уведомлений
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
		USHORT a = rand() % 1000 + 1;//Десятичное число которое требуется перевести
		BYTE ns;//В какую систему счисления требуется перевести число
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
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	//Вопросы готовы
	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
}

void CMainDlg::On10ToNTest()
{
	// TODO: добавьте свой код обработчика команд
	f10ToN();
	topic = "Тестирование по теме \"Системы счисления, перевод чисел из десятичной с.с. в любую другую\"";
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
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	// TODO: добавьте свой код обработчика команд
	fNTo10();
	topic = "Практика по теме \"Системы счисления, перевод чисел из любой с.с. в десятичную\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnNTo10Test()
{
	// TODO: добавьте свой код обработчика команд
	fNTo10();
	topic = "Тестирование по теме \"Системы счисления, перевод чисел из любой с.с. в десятичную\"";
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
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	// TODO: добавьте свой код обработчика команд
	f2To8();
	topic = "Практика по теме \"Системы счисления, перевод чисел из двоичной с.с. в восмеричную\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::On2To8Test()
{
	// TODO: добавьте свой код обработчика команд
	f2To8();
	topic = "Тестирование по теме \"Системы счисления, перевод чисел из двоичной с.с. в восмеричную\"";
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
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	// TODO: добавьте свой код обработчика команд
	f8To2();
	topic = "Практика по теме \"Системы счисления, перевод чисел из восмеричной с.с. в двоичную\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::On8To2Test()
{
	// TODO: добавьте свой код обработчика команд
	f8To2();
	topic = "Тестирование по теме \"Системы счисления, перевод чисел из восмеричной с.с. в двоичную\"";
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
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	// TODO: добавьте свой код обработчика команд
	f2To16();
	topic = "Практика по теме \"Системы счисления, перевод чисел из двоичной с.с. в шестнадцатеричную\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::On2To16Test()
{
	// TODO: добавьте свой код обработчика команд
	f2To16();
	topic = "Тестирование по теме \"Системы счисления, перевод чисел из двоичной с.с. в шестнадцатеричную\"";
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
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	// TODO: добавьте свой код обработчика команд
	f16To2();
	topic = "Практика по теме \"Системы счисления, перевод чисел из шестнадцатеричной с.с. в двоичную\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::On16To2Test()
{
	// TODO: добавьте свой код обработчика команд
	f16To2();
	topic = "Тестирование по теме \"Системы счисления, перевод чисел из шестнадцатеричной с.с. в двоичную\"";
	bHelp.EnableWindow(FALSE);
}


void CMainDlg::OnNToN()
{
	// TODO: добавьте свой код обработчика команд
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
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	//Вопросы готовы
	qnumber = 0;
	ShowQuestion(qnumber);
	bBack.EnableWindow(TRUE);
	bNext.EnableWindow(TRUE);
	bEnd.EnableWindow(TRUE);
	topic = "Итоговый тест по теме \"Система счисления\"";
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
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	// TODO: добавьте свой код обработчика команд
	fAdd();
	topic = "Практика по теме \"Машинная арифметика, сложение чисел\"";
	bHelp.EnableWindow(TRUE);

}


void CMainDlg::OnAddTest()
{
	// TODO: добавьте свой код обработчика команд
	fAdd();
	topic = "Тестирование по теме \"Машинная арифметика, сложение чисел\"";
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
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	// TODO: добавьте свой код обработчика команд
	fMin();
	topic = "Практика по теме \"Машинная арифметика, вычитание чисел\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnMinTest()
{
	// TODO: добавьте свой код обработчика команд
	fMin();
	topic = "Тестирование по теме \"Машинная арифметика, вычитание чисел\"";
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
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	// TODO: добавьте свой код обработчика команд
	fMul();
	topic = "Практика по теме \"Машинная арифметика, умножение чисел\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnMulTest()
{
	// TODO: добавьте свой код обработчика команд
	fMul();
	topic = "Тестирование по теме \"Машинная арифметика, умножение чисел\"";
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
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	// TODO: добавьте свой код обработчика команд
	fDiv();
	topic = "Практика по теме \"Машинная арифметика, деление чисел\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnDivTest()
{
	// TODO: добавьте свой код обработчика команд
	fDiv();
	topic = "Тестирование по теме \"Машинная арифметика, деление чисел\"";
	bHelp.EnableWindow(FALSE);
}


void CMainDlg::OnArith()
{
	// TODO: добавьте свой код обработчика команд
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
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	// TODO: добавьте свой код обработчика команд
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
		questions[i].name = (CString)"Число " + (CString)sa + (CString)" в машинном представлении будет = ?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	// TODO: добавьте свой код обработчика команд
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
		questions[i].name = (CString)"Число " + (CString)sa + (CString)" в машинном представлении будет = ?";
		questions[i].SetVariantAnswerCount(vcount);
		questions[i].SetAnswerCount(1);
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	// TODO: добавьте свой код обработчика команд
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
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	// TODO: добавьте свой код обработчика команд
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
		BYTE ians = rand() % vcount;//Каким по счёту будет верный ответ
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
	// TODO: добавьте свой код обработчика команд
	CAboutDlg dlg;
	dlg.DoModal();
}


void CMainDlg::OnTheoryNs()
{
	// TODO: добавьте свой код обработчика команд
	HtmlHelpA(NULL, "NumSys.chm::/1.html", HH_DISPLAY_TOPIC, NULL);
}


void CMainDlg::OnTheoryArithm()
{
	// TODO: добавьте свой код обработчика команд
	HtmlHelpA(NULL, "NumSys.chm::/2.html", HH_DISPLAY_TOPIC, NULL);
}


void CMainDlg::OnMach_FixPoint()
{
	// TODO: добавьте свой код обработчика команд
	Mach_FixPoint();
	topic = "Практика по теме \"Машинное представление чисел с фиксированной точкой\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnMach_FixPointTest()
{
	// TODO: добавьте свой код обработчика команд
	Mach_FixPoint();
	topic = "Тестирование по теме \"Машинное представление чисел с фиксированной точкой\"";
	bHelp.EnableWindow(FALSE);
}


void CMainDlg::OnMach_FloatPoint()
{
	// TODO: добавьте свой код обработчика команд
	Mach_FloatPoint();
	topic = "Практика по теме \"Машинное представление чисел с плавающей точкой\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnMach_FloatPointTest()
{
	// TODO: добавьте свой код обработчика команд
	Mach_FloatPoint();
	topic = "Тестирование по теме \"Машинное представление чисел с плавающей точкой\"";
	bHelp.EnableWindow(FALSE);
}


void CMainDlg::OnMach_AddSign()
{
	// TODO: добавьте свой код обработчика команд
	Mach_AddSign();
	topic = "Практика по теме \"Машинное представление чисел, сложение знаковых чисел\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnMach_AddSignTest()
{
	// TODO: добавьте свой код обработчика команд
	Mach_AddSign();
	topic = "Тестирование по теме \"Машинное представление чисел, сложение знаковых чисел\"";
	bHelp.EnableWindow(FALSE);
}


void CMainDlg::OnMach_AddUnsign()
{
	// TODO: добавьте свой код обработчика команд
	Mach_AddUnsign();
	topic = "Практика по теме \"Машинное представление чисел, сложение беззнаковых чисел\"";
	bHelp.EnableWindow(TRUE);
}


void CMainDlg::OnMach_AddUnsignTest()
{
	// TODO: добавьте свой код обработчика команд
	Mach_AddUnsign();
	topic = "Тестирование по теме \"Машинное представление чисел, сложение беззнаковых чисел\"";
	bHelp.EnableWindow(FALSE);
}


void CMainDlg::OnTheoryMach()
{
	// TODO: добавьте свой код обработчика команд
	HtmlHelpA(NULL, "NumSys.chm::/4.html", HH_DISPLAY_TOPIC, NULL);
}


void CMainDlg::OnViewHelp()
{
	// TODO: добавьте свой код обработчика команд
	HtmlHelpA(NULL, "NumSys.chm::/3.html", HH_DISPLAY_TOPIC, NULL);
}


void CMainDlg::OnSetQCount()
{
	// TODO: добавьте свой код обработчика команд
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
