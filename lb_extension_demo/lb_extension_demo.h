
// lb_extension_demo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Clb_extension_demoApp: 
// �йش����ʵ�֣������ lb_extension_demo.cpp
//

class Clb_extension_demoApp : public CWinApp
{
public:
	Clb_extension_demoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Clb_extension_demoApp theApp;
