// QCountDialog.cpp: файл реализации
//

#include "stdafx.h"
#include "NumSys.h"
#include "QCountDialog.h"
#include "afxdialogex.h"



// диалоговое окно CQCountDialog

IMPLEMENT_DYNAMIC(CQCountDialog, CDialogEx)

CQCountDialog::CQCountDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CQCountDialog::IDD, pParent)
{

}

CQCountDialog::~CQCountDialog()
{
}

void CQCountDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CQCountDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CQCountDialog::OnBnClickedOk)
	ON_WM_CREATE()
	ON_WM_CHAR()
	ON_EN_UPDATE(IDC_QEDIT, &CQCountDialog::OnEnUpdateQedit)
END_MESSAGE_MAP()


// обработчики сообщений CQCountDialog


void CQCountDialog::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CEdit *edit = (CEdit*)GetDlgItem(IDC_QEDIT);
	edit->GetWindowText(sQCount);
	
	CDialogEx::OnOK();
}


int CQCountDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания
	return 0;
}


void CQCountDialog::OnEnUpdateQedit()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// с флагом ENM_UPDATE ORed в маске lParam mask.
	// TODO:  Добавьте код элемента управления
	CEdit *edit = (CEdit*)GetDlgItem(IDC_QEDIT);
	CString s;
	edit->GetWindowText(s);
	if (s.IsEmpty())
		return;
	int a = _wtoi(s.GetBuffer());
	if (a > 250)
		edit->SetWindowText(L"250");
	else
		if (a <= 0)
			edit->SetWindowText(L"1");
	RedrawWindow();
}

