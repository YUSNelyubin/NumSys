
// NumSys.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CNumSysApp:
// � ���������� ������� ������ ��. NumSys.cpp
//

class CNumSysApp : public CWinApp
{
public:
	CNumSysApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CNumSysApp theApp;