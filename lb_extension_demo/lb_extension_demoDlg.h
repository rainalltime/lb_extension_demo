
// lb_extension_demoDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "lb_extnDvpInf.h"
#include "lb_IPIntercom.h"
#include "../../lb_win32/src/lb_inc/lb_initial_lonbon.h"
#include "ss_base/ss_device.h"

// Clb_extension_demoDlg 对话框
class Clb_extension_demoDlg : public CDialogEx
{
// 构造
public:
	Clb_extension_demoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LB_EXTENSION_DEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	static int WINAPI UI_processEvent(lb_ua2ui_event_e UA2UIEvent, int param1, void *param2);
	static Clb_extension_demoDlg *pThis;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();


	void Clb_extension_demoDlg::showLogInfo(char *tip);
	char *Clb_extension_demoDlg::getEditText(HWND edtHwnd, char *buf, int bufSize);



	CComboBox m_setKey;
	CComboBox m_getKey;
	BOOL isInitialOK=FALSE;
	HANDLE quitThread=NULL;
	CEdit m_workDir;
	CEdit m_sn;
	CEdit m_sipAcc;
	CEdit m_sipPwd;
	CEdit m_udpPort;
	CEdit m_tip;
	CEdit m_hungup_displayNum;
	CStatic m_myVideo;
	CStatic m_video;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedsetsetting();
	CEdit m_setValue;
	afx_msg void OnBnClickedgetsetting();
};
