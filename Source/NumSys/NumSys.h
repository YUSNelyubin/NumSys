
// NumSys.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CNumSysApp:
// О реализации данного класса см. NumSys.cpp
//

class CNumSysApp : public CWinApp
{
public:
	CNumSysApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CNumSysApp theApp;