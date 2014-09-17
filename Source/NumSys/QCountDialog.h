#pragma once


// диалоговое окно CQCountDialog

class CQCountDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CQCountDialog)

public:
	CQCountDialog(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CQCountDialog();

// Данные диалогового окна
	enum { IDD = IDD_DIALOGQCOUNT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString sQCount;
	afx_msg void OnBnClickedOk();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnEnUpdateQedit();
};
