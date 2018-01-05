
// lb_extension_demo.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// Clb_extension_demoApp: 
// 有关此类的实现，请参阅 lb_extension_demo.cpp
//

class Clb_extension_demoApp : public CWinApp
{
public:
	Clb_extension_demoApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern Clb_extension_demoApp theApp;
