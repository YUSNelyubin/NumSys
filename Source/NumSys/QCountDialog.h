#pragma once


// ���������� ���� CQCountDialog

class CQCountDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CQCountDialog)

public:
	CQCountDialog(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CQCountDialog();

// ������ ����������� ����
	enum { IDD = IDD_DIALOGQCOUNT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString sQCount;
	afx_msg void OnBnClickedOk();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnEnUpdateQedit();
};
