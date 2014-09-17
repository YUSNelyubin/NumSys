
// MainDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно CMainDlg
class CMainDlg : public CDialogEx
{
// Создание
public:
	CMainDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_NUMSYS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On10ToN();
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void ShowQuestion(BYTE num);
	CStatic lNumQuest;
	CStatic lQuestion;
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedEnd();
	afx_msg void OnBnClickedHelp();
	CButton bBack;
	CButton bNext;
	CButton bHelp;
	CButton bEnd;
	afx_msg void On10ToNTest();
	afx_msg void OnNTo10();
	afx_msg void OnNTo10Test();
	afx_msg void On2To8();
	afx_msg void On2To8Test();
	afx_msg void On8To2();
	afx_msg void On8To2Test();
	afx_msg void On2To16();
	afx_msg void On2To16Test();
	afx_msg void On16To2();
	afx_msg void On16To2Test();
	afx_msg void OnNToN();
	afx_msg void OnAdd();
	afx_msg void OnAddTest();
	afx_msg void OnMin();
	afx_msg void OnMinTest();
	void f10ToN();
	void fNTo10();
	void f2To8();
	void f8To2();
	void f2To16();
	void f16To2();
	void fAdd();
	void fMin();
	void fMul();
	afx_msg void OnMul();
	afx_msg void OnMulTest();
	void fDiv();
	afx_msg void OnDiv();
	afx_msg void OnDivTest();
	afx_msg void OnArith();
	afx_msg void OnAbout();
	afx_msg void OnTheoryNs();
	afx_msg void OnTheoryArithm();
	void Mach_FixPoint();
	afx_msg void OnMach_FixPoint();
	afx_msg void OnMach_FixPointTest();
	void Mach_FloatPoint();
	afx_msg void OnMach_FloatPoint();
	afx_msg void OnMach_FloatPointTest();
	void Mach_AddSign();
	afx_msg void OnMach_AddSign();
	afx_msg void OnMach_AddSignTest();
	void Mach_AddUnsign();
	afx_msg void OnMach_AddUnsign();
	afx_msg void OnMach_AddUnsignTest();
	afx_msg void OnTheoryMach();
	afx_msg void OnViewHelp();
	afx_msg void OnSetQCount();
};
