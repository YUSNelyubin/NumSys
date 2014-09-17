
// NumSys.cpp : ќпредел€ет поведение классов дл€ приложени€.
//

#include "stdafx.h"
#include "NumSys.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNumSysApp

BEGIN_MESSAGE_MAP(CNumSysApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// создание CNumSysApp

CNumSysApp::CNumSysApp()
{
	// TODO: добавьте код создани€,
	// –азмещает весь важный код инициализации в InitInstance
}


// ≈динственный объект CNumSysApp

CNumSysApp theApp;


// инициализаци€ CNumSysApp

BOOL CNumSysApp::InitInstance()
{
	// InitCommonControlsEx() требуетс€ дл€ Windows XP, если манифест
	// приложени€ использует ComCtl32.dll версии 6 или более поздней версии дл€ включени€
	// стилей отображени€. ¬ противном случае будет возникать сбой при создании любого окна.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ¬ыберите этот параметр дл€ включени€ всех общих классов управлени€, которые необходимо использовать
	// в вашем приложении.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// —оздать диспетчер оболочки, в случае, если диалоговое окно содержит
	// представление дерева оболочки или какие-либо его элементы управлени€.
	CShellManager *pShellManager = new CShellManager;

	// —тандартна€ инициализаци€
	// ≈сли эти возможности не используютс€ и необходимо уменьшить размер
	// конечного исполн€емого файла, необходимо удалить из следующих
	// конкретных процедур инициализации, которые не требуютс€
	// »змените раздел реестра, в котором хран€тс€ параметры
	// TODO: следует изменить эту строку на что-нибудь подход€щее,
	// например на название организации
	//SetRegistryKey(_T("Ћокальные приложени€, созданные с помощью мастера приложений"));

	CMainDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	// ”далить диспетчер оболочки, созданный выше.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ѕоскольку диалоговое окно закрыто, возвратите значение FALSE, чтобы можно было выйти из
	//  приложени€ вместо запуска генератора сообщений приложени€.
	return FALSE;
}

