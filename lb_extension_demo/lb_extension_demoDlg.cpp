
// lb_extension_demoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "lb_extension_demo.h"
#include "lb_extension_demoDlg.h"
#include "afxdialogex.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clb_extension_demoDlg 对话框



Clb_extension_demoDlg *Clb_extension_demoDlg::pThis = NULL;
Clb_extension_demoDlg::Clb_extension_demoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LB_EXTENSION_DEMO_DIALOG, pParent)
{
	pThis = this;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clb_extension_demoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_setKey);
	DDX_Control(pDX, IDC_COMBO2, m_getKey);
	DDX_Control(pDX, IDC_EDIT17, m_workDir);
	DDX_Control(pDX, IDC_EDIT1, m_sn);
	DDX_Control(pDX, IDC_EDIT2, m_sipAcc);
	DDX_Control(pDX, IDC_EDIT3, m_sipPwd);
	DDX_Control(pDX, IDC_EDIT4, m_udpPort);
	DDX_Control(pDX, IDC_EDIT5, m_tip);
	DDX_Control(pDX, IDC_EDIT9, m_hungup_displayNum);
	DDX_Control(pDX, myvideo, m_myVideo);
	DDX_Control(pDX, video, m_video);
	DDX_Control(pDX, IDC_EDIT6, m_setValue);
}

BEGIN_MESSAGE_MAP(Clb_extension_demoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Clb_extension_demoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &Clb_extension_demoDlg::OnBnClickedButton3)
	ON_BN_CLICKED(setSetting, &Clb_extension_demoDlg::OnBnClickedsetsetting)
	ON_BN_CLICKED(getSetting, &Clb_extension_demoDlg::OnBnClickedgetsetting)
END_MESSAGE_MAP()


// Clb_extension_demoDlg 消息处理程序

BOOL Clb_extension_demoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	this->m_sn.SetWindowText(_T("1003"));
	this->m_sipAcc.SetWindowText(_T("111111"));
	this->m_sipPwd.SetWindowText(_T("222242"));
	this->m_udpPort.SetWindowText(_T("5062"));
	m_workDir.SetWindowText(L"..\\Debug\\win32\\ipIntercom");
	// TODO: 在此添加额外的初始化代码
	this->m_setKey.AddString(_T("LBSETTING_KEY_DISPLAYNUM(编号)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_ADDRMANAGESVR(地址盒地址)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTNVOL(直属分机音量)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_LAN_CODEC(点对点模式编码方案)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_WAN_CODEC(服务器模式编码方案)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_HEADMST(上级主机)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_NOASWUPTRANS_TIME(无应答上传时间)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_REPMST(托管主机)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTN_NSALARM_LVL(喧哗报警级别)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_RECORD_PATH(录音录像文件路径)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_RECORD_ENA(录音录像使能)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTNCALLIN_ADPY_MODE(分机呼入报号模式)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_CRCLISTENTIME(循环监听时长)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_MYEXTNCALLOUT_MAXTIME(直属分机呼叫最大时长)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_TRANS_EXTNINFO_ADTLMST(分机描述信息上传的附加主机列表)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_CALL_ADTLMST(分机呼叫的附加主机列表)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_CALL_ADTLMST_DLYTM(分机呼叫附加主机的延时时长)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_TRIAGE_MSTNUM(分诊主机编号)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_TRIAGE_GROUPNUM(分诊组号)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_TRIAGE_DEVNUM(分诊设备号)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_RECORD_UPLOAD_ENA(录音录像文件自动上传使能)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_RECORD_UPLOAD_SERVERIP(录音录像文件接收服务器)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_RINGMUSIC_NANME(普通呼叫振铃音乐名称)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_FORBID_EXTNCALLIN(禁止分机呼入使能)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_HIS_ENABLED(连接HIS使能)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_HIS_SERVERIP(HIS服务器地址)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_HIS_ZONENUMBER(病区号)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_DOORLAMPCOLOR(门灯颜色标准)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_DUTYDOCTOR_PATH(责任医生照片存储路径)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_DUTYNURSE_PATH(责任护士照片存储路径)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_CALLONBUSY_TRANS_ENA(遇忙转移功能使能)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_CALLONBUSY_TRANS_MST(遇忙转移的被叫主机号)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_CONSULTCALL_MST(咨询呼叫主机号)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_LANGUAGE(语言)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_RING_ONCONN_ENA(通话中呼入振铃使能)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTNOFFLN_VNTY_ENA(直属分机掉线语音提示使能)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_MYEXTN_TKBELSN_ENA(第三方监听使能)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC1(外接报警信号1的描述信息)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC2(外接报警信号2的描述信息)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC3(外接报警信号3的描述信息)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC4(外接报警信号4的描述信息)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC5(外接报警信号5的描述信息)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC6(外接报警信号6的描述信息)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC7(外接报警信号7的描述信息)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC8(外接报警信号8的描述信息)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC9(外接报警信号9的描述信息)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC10(外接报警信号10的描述信息)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_VIDEOCLARITY(视频清晰度)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_MULTITALKVID_ENA(多方通话支持视频使能)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_ALARMRINGMUSIC_NAME(紧急报警振铃音乐名称)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_RINGINTERNAL_DIS(禁止内部振铃及语音播报使能)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_DR1OP_TIMEOUTALARM_ENA(门磁1触发启用超时报警使能)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_DR1OP_TIMEOUTALARM_TM(门磁1触发超时报警超时时长)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_PLAYFILE_ENA(通话中插播文件使能)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_FONT_SCREEN_TIME_TYPE(点阵屏显示格式)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_FONT_SCREEN_PROMPTING(点阵屏显示语)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_FONT_SCREEN_MODE(点阵屏模式设置)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_ENABLE(是否启用标准SIP)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_ADDRESS(标准SIP服务器IP)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_PORT(标准SIP服务器端口)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_USERNAME(标准SIP账户用户名)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_PASSWORD(标准SIP账户密码)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_ENABLE(是否启用标准SIP2)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_ADDRESS(标准SIP服务器IP2)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_PORT(标准SIP服务器端口2)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_USERNAME(标准SIP账户用户名2)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_PASSWORD(标准SIP账户密码2)"));
	this->m_setKey.SetCurSel(0);

	this->m_getKey.AddString(_T("LBSETTING_KEY_DISPLAYNUM(编号)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_ADDRMANAGESVR(地址盒地址)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTNVOL(直属分机音量)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_LAN_CODEC(点对点模式编码方案)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_WAN_CODEC(服务器模式编码方案)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_HEADMST(上级主机)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_NOASWUPTRANS_TIME(无应答上传时间)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_REPMST(托管主机)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTN_NSALARM_LVL(喧哗报警级别)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_RECORD_PATH(录音录像文件路径)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_RECORD_ENA(录音录像使能)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTNCALLIN_ADPY_MODE(分机呼入报号模式)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_CRCLISTENTIME(循环监听时长)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_MYEXTNCALLOUT_MAXTIME(直属分机呼叫最大时长)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_TRANS_EXTNINFO_ADTLMST(分机描述信息上传的附加主机列表)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_CALL_ADTLMST(分机呼叫的附加主机列表)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_CALL_ADTLMST_DLYTM(分机呼叫附加主机的延时时长)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_TRIAGE_MSTNUM(分诊主机编号)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_TRIAGE_GROUPNUM(分诊组号)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_TRIAGE_DEVNUM(分诊设备号)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_RECORD_UPLOAD_ENA(录音录像文件自动上传使能)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_RECORD_UPLOAD_SERVERIP(录音录像文件接收服务器)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_RINGMUSIC_NANME(振铃音乐名称)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_FORBID_EXTNCALLIN(禁止分机呼入使能)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_HIS_ENABLED(连接HIS使能)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_HIS_SERVERIP(HIS服务器地址)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_HIS_ZONENUMBER(病区号)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_DOORLAMPCOLOR(门灯颜色标准)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_DUTYDOCTOR_PATH(责任医生照片存储路径)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_DUTYNURSE_PATH(责任护士照片存储路径)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_CALLONBUSY_TRANS_ENA(遇忙转移功能使能)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_CALLONBUSY_TRANS_MST(遇忙转移的被叫主机号)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_CONSULTCALL_MST(咨询呼叫主机号)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_LANGUAGE(语言)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_RING_ONCONN_ENA(通话中呼入振铃使能)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTNOFFLN_VNTY_ENA(直属分机掉线语音提示使能)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_MYEXTN_TKBELSN_ENA(第三方监听使能)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC1(外接报警信号1的描述信息)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC2(外接报警信号2的描述信息)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC3(外接报警信号3的描述信息)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC4(外接报警信号4的描述信息)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC5(外接报警信号5的描述信息)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC6(外接报警信号6的描述信息)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC7(外接报警信号7的描述信息)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC8(外接报警信号8的描述信息)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC9(外接报警信号9的描述信息)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC10(外接报警信号10的描述信息)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_VIDEOCLARITY(视频清晰度)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_MULTITALKVID_ENA(多方通话支持视频使能)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_ALARMRINGMUSIC_NAME(紧急报警振铃音乐名称)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_RINGINTERNAL_DIS(禁止内部振铃及语音播报使能)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_DR1OP_TIMEOUTALARM_ENA(门磁1触发启用超时报警使能)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_DR1OP_TIMEOUTALARM_TM(门磁1触发超时报警超时时长)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_PLAYFILE_ENA(通话中插播文件使能)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_FONT_SCREEN_TIME_TYPE(点阵屏显示格式)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_FONT_SCREEN_PROMPTING(点阵屏显示语)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_FONT_SCREEN_MODE(点阵屏模式设置)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_ENABLE(是否启用标准SIP)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_ADDRESS(标准SIP服务器IP)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_PORT(标准SIP服务器端口)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_USERNAME(标准SIP账户用户名)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_PASSWORD(标准SIP账户密码)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_ENABLE(是否启用标准SIP2)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_ADDRESS(标准SIP服务器IP2)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_PORT(标准SIP服务器端口2)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_USERNAME(标准SIP账户用户名2)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_PASSWORD(标准SIP账户密码2)"));
	this->m_getKey.SetCurSel(0);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Clb_extension_demoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Clb_extension_demoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
int WINAPI Clb_extension_demoDlg::UI_processEvent(lb_ua2ui_event_e UA2UIEvent, int param1, void *param2)
{
	char tip[256] = { 0 };
	WCHAR buf[32];
	switch (UA2UIEvent)
	{
	case LB_UA2UI_CALL_PROCESSING:                //呼出处理中
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "呼叫%d号正在处理中……\r\n", param1);
		break;
	case LB_UA2UI_CALL_RINGBACK:                  //呼出振铃
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "呼叫%d号振铃\r\n", param1);
		break;
	case LB_UA2UI_CALL_LSTN_CONNECT:              //监听接通
	{
		int rmtProperty = *(int *)param2;
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		if (lb_info_isRmtSupportVideo(rmtProperty))
		{
			//对方支持摄像头，需要打开视频显示框……
			//......
			pThis->m_video.ShowWindow(SW_SHOW);
			pThis->m_myVideo.ShowWindow(SW_SHOW);

			//显示框初始化完成，打开对方的摄像头
			//if (!lb_info_isRmtVideoCtrEna(rmtProperty))
			//{
			//	lb_fun_notifyRmtVideo_on();            //接通就打开对方的摄像头
			//}
		}
		sprintf(tip, "监听%d号接通\r\n按一次空格键转为对讲模式\r\n", param1);
	}
	break;
	case LB_UA2UI_CALL_TALK_CONNECT:              //对讲接通
	{
		int rmtProperty = *(int *)param2;
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		if (lb_info_isRmtSupportVideo(rmtProperty))
		{
			//对方支持摄像头，需要打开视频显示框……
			//......
			pThis->m_video.ShowWindow(SW_SHOW);
			pThis->m_myVideo.ShowWindow(SW_SHOW);

			//显示框初始化完成，打开对方的摄像头
			//if (!lb_info_isRmtVideoCtrEna(rmtProperty))
			//{
			//	lb_fun_notifyRmtVideo_on();            //接通就打开对方的摄像头
			//}

			//pThis->m_btn_myVd_on.EnableWindow(TRUE);
			//pThis->m_btn_myVd_off.EnableWindow(FALSE);
		}
		sprintf(tip, "与%d号对讲接通\r\n", param1);
		//if (!pThis->fullDuplexEna)
		//{
		//	sprintf(&tip[strlen(tip)], "要讲话请按住空格键，讲完请松开空格键听对方讲！\r\n");
		//}
	}
	break;
	case LB_UA2UI_CALL_DISCONNECT:                //通话或呼叫挂断
	{
		//视频相关资源释放
		pThis->m_video.ShowWindow(SW_HIDE);
		pThis->m_myVideo.ShowWindow(SW_HIDE);

		//pThis->m_btn_myVd_on.EnableWindow(FALSE);
		//pThis->m_btn_myVd_off.EnableWindow(FALSE);

		sprintf(tip, "挂断与%d号的通话或呼叫\r\n", param1);
	}
	break;
	case LB_UA2UI_CALL_REFUSE:                    //呼出被拒绝
		sprintf(tip, "%d号拒绝本机呼叫\r\n", param1);
		break;
	case LB_UA2UI_CALL_BUSY:                      //对方忙
		sprintf(tip, "%d号当前正忙\r\n", param1);
		break;
	case LB_UA2UI_CALL_FAIL:                      //呼出失败
		sprintf(tip, "呼叫%d号失败\r\n", param1);
		break;
	case LB_UA2UI_CALL_TIMEOUT:                   //呼出超时无响应
		sprintf(tip, "呼叫%d号超时\r\n", param1);
		break;
	case LB_UA2UI_CALL_CALLIN:                    //普通呼入
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "%d号呼叫\r\n", param1);
		break;
	case LB_UA2UI_CALL_EMERGENCYCALL:             //紧急报警
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "%d号紧急报警\r\n", param1);
		break;
	case LB_UA2UI_CALL_NSALARM:                   //喧哗报警
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "%d号喧哗报警\r\n", param1);
		break;
	case LB_UA2UI_CALL_CANCEL:                    //对方取消呼入
		sprintf(tip, "%d号取消呼入\r\n", param1);
		break;

	case LB_UA2UI_BC_START:                       //广播成功启动
		sprintf(tip, "广播启动成功，组序为%d\r\n", param1);
		break;
	case LB_UA2UI_BC_STOP:                        //广播停止
		sprintf(tip, "组序为%d的广播停止\r\n", param1);
		break;
	case LB_UA2UI_BC_NOTALLOW:                    //广播有冲突，不允许启动
		sprintf(tip, "组序为%d的广播启动有冲突，可能当前已经有更高级别广播或已经有其他组广播在对本组广播对象中一个或多个成员广播\r\n", param1);
		break;
	case LB_UA2UI_BC_FAIL:
		sprintf(tip, "组序为%d的广播启动失败，可能是没有对象，或者本机没有获取对象的地址，或者文件广播没有文件。\r\n", param1);
		break;
	case LB_UA2UI_BC_SPK_PROCESSING:              //喊话广播启动中……
		sprintf(tip, "喊话广播正在启动，组序为%d\r\n", param1);
		break;
	case LB_UA2UI_BC_SPK_START:                   //喊话广播成功启动，可以喊话
		sprintf(tip, "喊话广播启动成功，组序为%d，可以喊话\r\n", param1);
		break;
	case LB_UA2UI_BC_SPK_STOP:                    //喊话广播停止
		sprintf(tip, "组序为%d的喊话广播停止\r\n", param1);
		break;
	case LB_UA2UI_BC_SPK_FAIL:                    //喊话广播启动失败
		sprintf(tip, "喊话广播启动失败，组序为%d，可能是没有对象，或者本机没有获取对象的地址\r\n", param1);
		break;
	case LB_UA2UI_BC_FILE_PAUSE:                  //文件广播暂停，本地控制暂停，执行成功返回的事件
		sprintf(tip, "组序为%d的文件广播暂停\r\n", param1);
		break;
	case LB_UA2UI_BC_FILE_BREAK2PAUSE:            //文件广播临时暂停，因为插话或高级别广播而被迫暂停，可自动恢复
		sprintf(tip, "组序为%d的文件广播暂停\r\n", param1);
		break;
	case LB_UA2UI_BC_FILE_PLAY_END:               //文件广播时，一个文件播放结束，即将播放下一个文件
	{
		int fileIndex = *(int *)param2;
		sprintf(tip, "组序为%d的文件广播的第%d个文件播放结束，即将播放下一个文件\r\n", param1, fileIndex + 1);
	}
	break;
	case LB_UA2UI_BC_TRANS2EXTN_START:            //收到其他主机对本机的直属分机广播，本机转发给直属分机
		sprintf(tip, "本机转发%d号主机的广播给直属分机\r\n", param1);
		break;
	case LB_UA2UI_BC_TRANS2EXTN_STOP:             //转发广播给直属分机结束
		sprintf(tip, "本机结束转发%d号主机的广播给直属分机\r\n", param1);
		break;
	case LB_UA2UI_BEBC_START:                     //开始被广播
		sprintf(tip, "本机收到%d号主机对本机的广播\r\n", param1);
		break;
	case LB_UA2UI_BEBC_STOP:                      //停止被广播
		sprintf(tip, "%d号主机对本机的广播结束\r\n", param1);
		break;

	case LB_UA2UI_CRCLST_FAIL:                    //循环监听启动失败
		sprintf(tip, "循环监听启动失败，可能是本机忙或者是%d号主机没有分机\r\n", param1);
		break;
	case LB_UA2UI_CRCLST_EXTN_START:              //开始监听某一分机
		sprintf(tip, "开始监听%d号分机\r\n", param1);
		break;
	case LB_UA2UI_CRCLST_EXTN_STOP:               //结束监听某一分机
		sprintf(tip, "结束监听%d号分机\r\n", param1);
		break;
	case LB_UA2UI_CRCLST_EXTN_FAIL:               //循环监听某一分机失败，会继续监听下一个分机
		sprintf(tip, "监听%d号分机失败\r\n", param1);
		break;
	case LB_UA2UI_CRCLST_FINISH:                  //循环监听停止
		sprintf(tip, "循环监听%d号主机的分机停止\r\n", param1);
		break;

	case LB_UA2UI_EXTN_IO_DR1_OPEN:               //分机端门磁1断开提示
		sprintf(tip, "%d号分机门磁1断开\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_DR1_CLOSE:              //分机端门磁1闭合提示
		sprintf(tip, "%d号分机门磁1闭合\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_DR2_OPEN:               //分机端门磁2断开提示
		sprintf(tip, "%d号分机门磁2断开\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_DR2_CLOSE:              //分机端门磁2闭合提示
		sprintf(tip, "%d号分机门磁2闭合\r\n", param1);
		break;

	case LB_UA2UI_AGENT_REQUEST:                  //收到托管请求
		sprintf(tip, "%d号主机请求托管\r\n", param1);
		break;
	case LB_UA2UI_AGENT_REQ_CANCLE:               //托管请求取消（已收到请求，尚未应答）
		sprintf(tip, "%d号主机取消托管请求\r\n", param1);
		break;
	case LB_UA2UI_AGENT_QUIT:                     //收到退出托管请求
		sprintf(tip, "%d号主机退出托管\r\n", param1);
		break;
	case LB_UA2UI_BEAGENTED_REQ_ACCEPTED:         //本机发出代管请求，对方同意代管
		sprintf(tip, "本机请求托管，%d号主机同意\r\n", param1);
		break;
	case LB_UA2UI_BEAGENTED_REQ_REJECTED:         //本机发出代管请求，对方拒绝代管
		sprintf(tip, "本机请求托管，%d号主机拒绝\r\n", param1);
		break;
	case LB_UA2UI_BEAGENTED_REQ_TIMEOUT:          //本机发出代管请求没响应（没有送达或没有应答）
		sprintf(tip, "本机请求托管，无响应超时\r\n");
		break;
	case LB_UA2UI_BEAGENTED_REQ_FAIL:             //本机请求代管失败，可能是没有预设代管机或没有代管机的地址
		sprintf(tip, "本机请求托管，失败\r\n");
		break;
	case LB_UA2UI_BEAGENTED_QUIT:                 //本机退出被代管状态
		sprintf(tip, "本机退出托管状态\r\n");
		break;

	case LB_UA2UI_SYSTEM_BUSY:                   //当前忙，操作无效
		sprintf(tip, "本机忙，不能响应当前操作\r\n");
		break;
	case LB_UA2UI_NETWORK_INIT_FAIL:             //网络初始化失败
		sprintf(tip, "网络初始化失败\r\n");
		break;
	case LB_UA2UI_NETWORK_DISCONNECTED:          //网络断开
		sprintf(tip, "网络断开\r\n");
		break;

	case LB_UA2UI_EXTN_IO_OPLK1_UNALLOW:         //当前不允许开锁1
		if (lb_info_terminalIsMaster(param1)) sprintf(tip, "当前不允许给%d号主机的分机开锁1\r\n", param1);
		else sprintf(tip, "当前不允许给%d号分机开锁1\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_OPLK1_SUCC:            //开锁1成功
		sprintf(tip, "给%d号分机开锁1成功\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_OPLK1_DISABLE:    //锁1没有启用
		sprintf(tip, "%d号分机的电控锁1没有启用\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_OPLK2_UNALLOW:         //当前不允许开锁2
		if (lb_info_terminalIsMaster(param1)) sprintf(tip, "当前不允许给%d号主机的分机开锁2\r\n", param1);
		else sprintf(tip, "当前不允许给%d号分机开锁2\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_OPLK2_SUCC:            //开锁2成功
		sprintf(tip, "给%d号分机开锁2成功\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_OPLK2_DISABLE:         //锁2没有启用
		sprintf(tip, "%d号分机的电控锁2没有启用\r\n", param1);
		break;

	case LB_UA2UI_ADDRQUERY_FINISHED:            //已获取到所需地址信息，界面可以刷新显示的号码列表
		sprintf(tip, "本机的分机有更新或者管理的下级主机更新\r\n");
		//如果界面有显示号码，需要刷新显示
		break;
		//case LB_UA2UI_BEMANGED_RFSH_EXTNDSCRBINFO:   //一级主机通知上级主机或托管主机更新它的分机的描述信息
		//	lb_info_extnDescriptInfo_decode(param1, (char*)param2, Clb_extension_demoDlg::extnDescriptInfo_update);
		//	sprintf(tip, "");
		//	break;
		//case LB_UA2UI_BEMANGED_EXTNCNT_CHANGED:      //被管的主机的分机个数刷新
		//	sprintf(tip, "下级主机%d号直属分机最多%d个\r\n", param1, lb_info_getMaxExtnCntBelongMst(param1));
		//	break;
		//case LB_UA2UI_BEMANGED_RFSH_EXTNVOCRGINFO:     //一级主机通知上级主机或托管主机更新它的分机的呼入时的语音播报信息
		//	lb_info_extnCallInVoiceRingInfo_decode(param1, (char*)param2, Clb_extension_demoDlg::extnCallInAdPyInfo_update);
		//	sprintf(tip, "");
		//	break;
	case LB_UA2UI_NO_AUDIOINPUTDEV:               //没有音频输入设备
		sprintf(tip, "没有音频输入设备！\r\n");
		break;
	case LB_UA2UI_NO_AUDIOOUTPUTDEV:              //没有音频输出设备
		sprintf(tip, "没有音频输出设备！\r\n");
		break;
	case LB_UA2UI_NO_NETCONNECTION:               //没有网络连接，初始化lb_ipIntercom_start()会一直等待直到网络正常。
		sprintf(tip, "没有连接网络，可能是没有网络适配器或者网路连接被禁用！\r\n");
		break;
	case LB_UA2UI_ADDRLOG_SUCCESS:                //在地址盒登记本机地址成功，首次启动或者编号、地址等有变化，必须在地址盒上更新地址信息，才能正常工作
		sprintf(tip, "在地址盒登记本机地址成功！\r\n");
		break;

		//case LB_UA2UI_CALL_ATM_LSTN_SELTER:        //ATM接线盒已经接通，需要选择要监听的终端的终端号，参数为可供选择的终端号列表
		//{
		//	char *AtmTerNumList = (char *)param2;
		//	if (AtmTerNumList)
		//	{
		//		int terNum = 0, numList[30] = { 0 }, cnt = 0, i = 0;
		//		strInfoDecodeToIntList(AtmTerNumList, ',', numList, 30, &cnt);//将字符串解析成整数数组
		//		if (cnt == 0)
		//		{
		//			lb_fun_hungup(param1);
		//			break;
		//		}
		//		sprintf(tip, "你可以选择%d号ATM接线盒的下列终端监听：%s\r\n）", param1, AtmTerNumList);
		//	}
		//}
		//break;
		//case LB_UA2UI_CALL_ATM_TALK_SELTER:        //ATM接线盒已经接通，需要选择要对讲的终端的终端号或者要接听的终端的终端号，参数为可供选择的终端号列表
		//{
		//	char *AtmTerNumList = (char *)param2;
		//	if (AtmTerNumList)
		//	{
		//		int terNum = 0, numList[30] = { 0 }, cnt = 0, i = 0;
		//		strInfoDecodeToIntList(AtmTerNumList, ',', numList, 30, &cnt);//将字符串解析成整数数组
		//		if (cnt == 0)
		//		{
		//			lb_fun_hungup(param1);
		//			break;
		//		}
		//		sprintf(tip, "你可以选择%d号ATM接线盒的下列终端对讲或接听：%s\r\n", param1, AtmTerNumList);
		//	}
		//}
		//break;
	//case LB_UA2UI_CALL_ATM_LSTN_CONNECT:              //监听ATM终端接通
	//{
	//	int rmtProperty = *(int *)param2, extnNum = 0, atmTerNum = 0;

	//	//param1为最多9位编号的整数，前6位为ATM接线盒号码，后3位为终端的号码
	//	extnNum = param1 / 1000;   //ATM接线盒号码，6位，与普通数字分机的号码一样的规则
	//	atmTerNum = param1 % 1000; //ATM终端的号码

	//	if (lb_info_isRmtSupportVideo(rmtProperty))
	//	{
	//		//对方支持摄像头，需要打开视频显示框……
	//		//......
	//		pThis->m_video.ShowWindow(SW_SHOW);
	//		pThis->m_myVideo.ShowWindow(SW_SHOW);

	//		//显示框初始化完成，打开对方的摄像头
	//		if (!lb_info_isRmtVideoCtrEna(rmtProperty))
	//		{
	//			lb_fun_notifyRmtVideo_on();            //接通就打开对方的摄像头
	//		}
	//	}
	//	sprintf(tip, "监听%d号ATM接线盒的%d号终端接通\r\n按一次空格键转为对讲模式\r\n", extnNum, atmTerNum);
	//}
	//break;
	case LB_UA2UI_CALL_ATM_TALK_CONNECT:              //对讲ATM终端接通
	{
		int rmtProperty = *(int *)param2, extnNum = 0, atmTerNum = 0;

		//param1为最多9位编号的整数，前6位为ATM接线盒号码，后3位为终端的号码
		extnNum = param1 / 1000;   //ATM接线盒号码，6位，与普通数字分机的号码一样的规则
		atmTerNum = param1 % 1000; //ATM终端的号码

	//	if (lb_info_isRmtSupportVideo(rmtProperty))
	//	{
	//		//对方支持摄像头，需要打开视频显示框……
	//		//......
	//		pThis->m_video.ShowWindow(SW_SHOW);
	//		pThis->m_myVideo.ShowWindow(SW_SHOW);

	//		//显示框初始化完成，打开对方的摄像头
	//		if (!lb_info_isRmtVideoCtrEna(rmtProperty))
	//		{
	//			lb_fun_notifyRmtVideo_on();            //接通就打开对方的摄像头
	//		}

	//		pThis->m_btn_myVd_on.EnableWindow(TRUE);
	//		pThis->m_btn_myVd_off.EnableWindow(FALSE);
	//	}
	//	sprintf(tip, "与%d号ATM接线盒的%d号终端对讲接通\r\n", extnNum, atmTerNum);
	//	if (!pThis->fullDuplexEna)
	//	{
	//		sprintf(&tip[strlen(tip)], "要讲话请按住空格键，讲完请松开空格键听对方讲！\r\n");
	//	}
	//}
	}
	break;
	case LB_UA2UI_CALL_ATM_DISCONNECT:                //与ATM终端通话挂断
	{
		int extnNum = 0, atmTerNum = 0;

		//param1为最多9位编号的整数，前6位为ATM接线盒号码，后3位为终端的号码
		extnNum = param1 / 1000;   //ATM接线盒号码，6位，与普通数字分机的号码一样的规则
		atmTerNum = param1 % 1000; //ATM终端的号码

								   //视频相关资源释放
		pThis->m_video.ShowWindow(SW_HIDE);
		pThis->m_myVideo.ShowWindow(SW_HIDE);

		//pThis->m_btn_myVd_on.EnableWindow(FALSE);
		//pThis->m_btn_myVd_off.EnableWindow(FALSE);

		sprintf(tip, "挂断与%d号ATM接线盒的%d号终端的通话\r\n", extnNum, atmTerNum);
	}
	break;
	case LB_UA2UI_CALL_ATM_FAIL:                      //选择ATM终端失败，即执行lb_fun_selectATMTer()，接通该终端不成功
	{
		int extnNum = 0, atmTerNum = 0;

		//param1为最多9位编号的整数，前6位为ATM接线盒号码，后3位为终端的号码
		extnNum = param1 / 1000;   //ATM接线盒号码，6位，与普通数字分机的号码一样的规则
		atmTerNum = param1 % 1000; //ATM终端的号码

		sprintf(tip, "选择%d号ATM接线盒的%d号终端通话失败\r\n", extnNum, atmTerNum);
	}
	break;
	case LB_UA2UI_ONBUSYCALLINMST_NOTIFY:          //本机在通话过程中，其他主机试图呼叫本机，但是是呼不进来的，这个消息提示这些主机呼叫过
		sprintf(tip, "%s号主机呼叫过本机\r\n", (char *)param2);
		break;
	case LB_UA2UI_ONBUSYCALLINATMTER_NOTIFY:       //本机在与某一个ATM接线盒的一个终端通话过程中，该接线盒的其他终端发起呼叫，但是在通话中是呼不到主机的，这个消息提示这些终端正在呼叫
		sprintf(tip, "%d号ATM接线盒的%s号终端正在呼叫\r\n", param1, (char *)param2);
		break;

	case LB_UA2UI_CALL_PRISONER_ESCAPE:	  //犯人逃跑
		sprintf(tip, "%d号报告犯人逃跑\r\n", param1);
		break;
	case LB_UA2UI_CALL_PRISONER_OUTBREAK:  //犯人暴狱
		sprintf(tip, "%d号报告犯人暴狱\r\n", param1);
		break;
	case LB_UA2UI_CALL_PRISONER_FIGHTS:	  //犯人打架
		sprintf(tip, "%d号报告犯人打架\r\n", param1);
		break;
	case LB_UA2UI_CALL_INTRUSION_ATTACK:	  //入侵袭击
		sprintf(tip, "%d号报告入侵袭击\r\n", param1);
		break;
	case LB_UA2UI_CALL_NATURAL_DISASTER:	  //自然灾害
		sprintf(tip, "%d号报告自然灾害\r\n", param1);
		break;

	case LB_UA2UI_EXTN_ONLINE:                //分机在线
											  //sprintf(tip,"%d号分机在线\r\n",param1);
		break;
	case LB_UA2UI_EXTN_OFFLINE:               //分机掉线
											  //sprintf(tip,"%d号分机掉线\r\n",param1);
		break;
	case LB_UA2UI_OFFLINENTY_STOP:          //分机掉线的语音提示已经停止
		sprintf(tip, "%d号分机掉线的语音提示已经停止\r\n", param1);
		break;
	case LB_UA2UI_AREAINFO_UPDATE:           //区号信息有更新
		sprintf(tip, "分区信息有更新\r\n");  //多级联网系统
		break;
	case LB_UA2UI_DTMFINPUT_ENA:             //显示DTMF输入键盘
		sprintf(tip, "%d号是网关，需要二次拨号输入要转接的电话号码或者手机号码\r\n", param1);
		break;
	case LB_UA2UI_PLAY_FILE_STOP:            //通话中插播文件播放结束
		sprintf(tip, "插播文件播放结束\r\n");
		break;
	case LB_UA2UI_CALL_RMALARM:					 //防拆报警
		sprintf(tip, "%d分机拆除报警\r\n", param1);
		break;
	case LB_UA2UI_EXTN_TALK_OTHER_START:      //分机与其他主机或分机开始通话，该分机的直属主机或高级主机在该分机与其他设备通话开始时会收到该事件
		sprintf(tip, "%d号分机通话中\r\n", param1);
		break;
	case LB_UA2UI_EXTN_TALK_OTHER_STOP:       //分机与其他主机或分机结束通话，该分机的直属主机或高级主机在该分机与其他设备通话结束时会收到该事件
		sprintf(tip, "%d号分机通话结束\r\n", param1);
		break;
	case LB_UA2UI_SIPCALL_PROCESSING:                //呼出处理中
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "呼叫%s正在处理中……\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPCALL_RINGBACK:                  //呼出振铃
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "呼叫%s振铃\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPCALL_CONNECT:                   //对讲接通
		pThis->m_video.ShowWindow(SW_SHOW);
		pThis->m_myVideo.ShowWindow(SW_SHOW);
		//pThis->m_btn_myVd_on.EnableWindow(TRUE);
		//pThis->m_btn_myVd_off.EnableWindow(FALSE);
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "与%s对讲接通\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPCALL_DISCONNECT:                //通话或呼叫挂断
		sprintf(tip, "挂断与%s的通话或呼叫\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPCALL_BUSY:                      //对方忙
		sprintf(tip, "%s当前正忙\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPCALL_FAIL:                      //呼出失败
		sprintf(tip, "呼叫%s失败\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPCALL_CALLIN:                    //普通呼入
		if (param1 != -1) {
			wsprintfW(buf, L"%d", param1);
			lb_acc_info accinfo;
			int accid;
			lb_info_get_accId_by_callId(param1, &accid);
			lb_info_get_acc_by_accId(accid, &accinfo);
			//pThis->m_asw_displayNum.SetWindowText((LPCWSTR)buf);
			pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);

			char  callAcc[64];
			lb_info_get_call_by_callId(param1, callAcc);
			sprintf(tip, "%s呼叫%d账户\r\naccount：%s\r\nDisplay:%s\r\nserviceIp:%s\r\nport:%d\r\n", (char*)callAcc, accinfo.accId,
				accinfo.account, accinfo.Display, accinfo.serviceIp, accinfo.port);

		}
		break;

	case LB_UA2UI_SIPREGISTER_FAIL:                //SIP注册失败
		sprintf(tip, "账号<%s>注册失败\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPREGISTER_SUCC:                //SIP注册成功
		sprintf(tip, "账号<%s>注册成功\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPUNREGISTER_SUCC:              //SIP注销成功
		sprintf(tip, "账号<%s>注销\r\n", (char*)param2);
		break;

		//case LB_UA2UI_MLTK_SPK_PROCESSING:         //多方通话启动，收到就提示喊话广播准备中…，1.5秒钟后提示可以喊话
		//	sprintf(tip,"多方通话启动中\r\n");
		//	break;
		//case LB_UA2UI_MLTK_SPK_OK:           //多方通话,提示可以喊话
		//	sprintf(tip,"多方通话已经启动，可以喊话\r\n");
		//	break;
		//case LB_UA2UI_MLTK_SPK_STOP:         //多方通话停止
		//	sprintf(tip,"多方通话已经停止\r\n");
		//	break;
		//case LB_UA2UI_MLTK_FAIL:             //多方通话失败
		//	sprintf(tip,"多方通话启动失败\r\n");
		//	break;
		//case LB_UA2UI_MLTK_NOTALLOW:         //多方通话有冲突，不允许启动
		//	sprintf(tip,"多方通话启动有冲突，不允许启动\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_APPLY_SPK:        //与会者申请发言
		//	sprintf(tip,"%d号申请发言\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_APPLY_SPK_CONNECT:      //发言开始
		//	sprintf(tip,"%d号开始发言\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_APPLY_SPK_DISCONNECT:   //发言结束
		//	sprintf(tip,"%d号发言结束\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_APPLY_SPK_FAIL:         //发言失败，SIP接通失败
		//	sprintf(tip,"%d号发言申请失败\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_WAIT_SPK:               //与会者申请发言,但是已经有其它与会者正在发言，申请失败
		//	sprintf(tip,"%d号等待发言\r\n",param1);
		//	break;

		//case LB_UA2UI_MLTK_BE_CONFERENCE_START:      //参与会议模式开始（客户端）
		//	sprintf(tip,"会议模式多方通话启动，组织者是%d号\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_BE_CONDUCT_START:         //参与指挥模式开始（客户端）
		//	sprintf(tip,"指挥模式多方通话启动，组织者是%d号\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_BE_STOP:                  //多方通话结束（客户端）
		//	sprintf(tip,"多方通话结束，多方通话组织者是%d号\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_CLT_APYSPK:               //与会者申请发言（客户端）
		//	sprintf(tip,"发言申请中，多方通话组织者是%d号\r\n");
		//	break;
		//case LB_UA2UI_MLTK_CLT_APYSPK_CONNECT:       //发言开始（客户端）
		//	sprintf(tip,"发言开始，多方通话组织者是%d号\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_CLT_APYSPK_DISCONNECT:    //发言结束（客户端）
		//	sprintf(tip,"发言结束，多方通话组织者是%d号\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_CLT_APYSPK_FAIL:          //发言失败（客户端）
		//	sprintf(tip,"发言申请失败，多方通话组织者是%d号\r\n",param1);
		//	break;
	default:
		break;
	}
	pThis->showLogInfo(tip);
	return 0;

}




static BOOL  CheckFolderExist(CString strPath);
static BOOL isDigit(char*);
static BOOL isValidIP(char *hostIP);
BOOL isValidNum(char *num, int low, int hi);
int strIPSplit(char *strIP, char **subPart, int len);



void Clb_extension_demoDlg::OnBnClickedOk()
{


	//if (this->quitThread)
	//{
	//	WaitForSingleObject(this->quitThread, INFINITE);
	//	CloseHandle(this->quitThread);
	//	this->quitThread = NULL;
	//}

	char tip[256] = { 0 };
	char workDir[256] = { 0 }, sn[32] = { 0 }, sipAcc[32] = { 0 }, sipPwd[32] = { 0 };
	int udpPort = 0;
	CString cs_udpPort = _T("");
	CString cstr_WorkDir = _T("");
	if (this->isInitialOK) {
		sprintf(tip, "LonBon IP网络对讲已启动!\r\n");
		this->showLogInfo(tip); return;
	}
	if (0 == this->m_workDir.GetWindowTextLength())
	{
		cstr_WorkDir += _T("../bin");
		if (!CheckFolderExist(cstr_WorkDir))
		{
			this->showLogInfo("当前目录的上一级目录下没有bin文件夹！");
			return;
		}
		strcpy(workDir, "..");    //默认的工作路径，为当前目录向上两层，为后面启动广播程序指定目录
	}
	else
	{
		this->m_workDir.GetWindowText(cstr_WorkDir);
		cstr_WorkDir += _T("/bin");
		if (!CheckFolderExist(cstr_WorkDir))
		{
			this->showLogInfo("当前指定目录下没有bin文件夹！");
			return;
		}
		this->getEditText(this->m_workDir.GetSafeHwnd(), workDir, sizeof(workDir));
		if (0 != lb_ipIntercom_workDirectory_set(workDir))
		{
			this->showLogInfo("指定工作目录失败！");
			return;
		}
	}


	this->m_udpPort.GetWindowText(cs_udpPort);
	udpPort = _ttoi(cs_udpPort);

	sprintf(tip, "LonBon IP网络对讲初始化……\r\n");
	this->showLogInfo(tip);
	SS_DeviceInfo deviceInfo = {0};
	deviceInfo.sn = (unsigned char*)this->getEditText(this->m_sn.GetSafeHwnd(), sn, sizeof(sn));
	deviceInfo.account = (unsigned char*)this->getEditText(this->m_sipAcc.GetSafeHwnd(), sipAcc, sizeof(sipAcc));
	deviceInfo.password = (unsigned char*)this->getEditText(this->m_sipPwd.GetSafeHwnd(), sipAcc, sizeof(sipAcc));
	deviceInfo.sipPort = udpPort;
	deviceInfo.type = SS_SN_TYPE_SLAVE;
	deviceInfo.deviceModel = (unsigned char*)"NLV-AE6B-S";
	deviceInfo.ip =(unsigned char*) "192.168.1.36";
	deviceInfo.dns1 = (unsigned char*)"192.168.1.1";
	deviceInfo.mac =(unsigned char*) "2C4D5459518F";
	deviceInfo.gateway = (unsigned char*)"192.168.1.1";
	deviceInfo.netmask = (unsigned char*) "255.255.255.0";
	if (0 != lb_ipIntercom_extn_start_local	(&deviceInfo,(fun_ua2ui_event_ext_callback)Clb_extension_demoDlg::UI_processEvent, NULL,NULL,NULL))
	{
		sprintf(tip, "LonBon IP网络对讲启动失败!!!\r\n");
		this->showLogInfo(tip);
		return;
	}
	else sprintf(tip, "LonBon IP网络对讲启动成功!\r\n");
	this->showLogInfo(tip);
	isInitialOK = TRUE;
}
void Clb_extension_demoDlg::showLogInfo(char *tip)
{
	CString w_tip = _T("");
	w_tip = tip;
	this->m_tip.SetSel(0, 0);
	this->m_tip.ReplaceSel(w_tip);
	this->m_tip.SetSel(0, 0);
	this->m_tip.ReplaceSel(_T("\r\n"));
	this->m_tip.Invalidate(FALSE);
}
static BOOL CheckFolderExist(CString strPath)
{
	WIN32_FIND_DATA  wfd;
	BOOL rValue = FALSE;
	HANDLE hFind = FindFirstFile(strPath.GetBuffer(), &wfd);
	if ((hFind != INVALID_HANDLE_VALUE) && (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
	{
		rValue = TRUE;
	}
	FindClose(hFind);
	return rValue;
}
BOOL isDigit(char *num)
{
	char *check = num;
	while (*check)
	{
		if (('9'<*check) || (*check<'0'))
		{
			return FALSE;
		}
		else
		{
			check++;
		}
	}
	return TRUE;
}
char *Clb_extension_demoDlg::getEditText(HWND edtHwnd, char *buf, int bufSize)
{
	wchar_t edtText[256] = { 0 };
	::GetWindowText(edtHwnd, (LPWSTR)edtText, 256);

	if (0<wcslen(edtText) && 0<WideCharToMultiByte(CP_ACP, 0, edtText, -1, buf, bufSize, NULL, NULL))
	{
		return buf;
	}
	return NULL;
}

void Clb_extension_demoDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	CString workPath = _T("");

	WCHAR szDir[MAX_PATH];
	BROWSEINFO bi;
	ITEMIDLIST *pidl;

	bi.hwndOwner = this->m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szDir;
	bi.lpszTitle = L"请选择目录";
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;

	pidl = SHBrowseForFolder(&bi);
	if (pidl == NULL)
		return;

	if (SHGetPathFromIDList(pidl, szDir))
	{

		workPath.Format(_T("%s"), szDir);

	}

	this->m_workDir.SetWindowText(workPath);
}

BOOL isValidNum(char *num, int low, int hi) {
	if (!isDigit(num) || atoi(num)<low || atoi(num)>hi)return FALSE;
	return TRUE;
}

int strIPSplit(char *strIP, char **subPart, int len)
{
	int i = 0;
	if (strIP)
	{
		char *p1 = strIP, *p2 = NULL;
		while ((p2 = strchr(p1, '.')) && i<len - 1)
		{
			subPart[i] = (char *)malloc(p2 - p1 + 1);
			memset(subPart[i], 0, p2 - p1 + 1);
			strncpy(subPart[i], p1, p2 - p1);
			i++;
			p1 = p2 + 1;
			p2 = NULL;
		}
		if (p1)
		{
			subPart[i] = (char *)malloc(strlen(p1) + 1);
			memset(subPart[i], 0, strlen(p1) + 1);
			strcpy(subPart[i], p1);
			i++;
		}
	}
	return i;
}
static BOOL isValidIP(char *hostIP) {
	int len = 0;
	char *subPart[10];

	if (!hostIP)return FALSE;
	len = strIPSplit(hostIP, subPart, 10);
	if (len != 4)
	{
		for (; len>0; len--) {
			free(subPart[len - 1]);
		}
		return FALSE;
	}
	for (; len>0; len--) {
		if (!isValidNum(subPart[len - 1], 0, 255))
		{
			for (; len>0; len--) {
				free(subPart[len - 1]);
			}
			return FALSE;
		}
		free(subPart[len - 1]);
	}

	return TRUE;
}


void Clb_extension_demoDlg::OnBnClickedsetsetting()
{

	{
		// TODO: 在此添加控件通知处理程序代码
		if (!this->isInitialOK)
		{
			this->showLogInfo("启动中，请稍等...\r\n");
		}
		int selKey = this->m_setKey.GetCurSel();
		int nVal = 0;
		char cBuf[256] = { 0 };
		void *pVal = NULL;
		int len = 0;
		switch (selKey)
		{
		case LBSETTING_KEY_DISPLAYNUM:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_ADDRMANAGESVR:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isValidIP(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_EXTNVOL:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_LAN_CODEC:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_WAN_CODEC:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		//case LBSETTING_KEY_HEADMST:
		//	if (this->runLevel_mode == LB_RUNLVL_SENIOR)
		//	{
		//		this->showLogInfo("高级主机没有本项设置\r\n");
		//		break;
		//	}
		//	this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
		//	if (0 == strlen(cBuf))
		//	{
		//		if (0 == lb_setting_set((lb_setting_key_e)selKey, NULL, 0))
		//		{
		//			this->showLogInfo("设置成功！\r\n");
		//		}
		//		else this->showLogInfo("设置失败！\r\n");
		//		return;
		//	}
		//	else
		//	{
		//		int *mstNumList = NULL, cnt = 0;
		//		cnt = lb_strToIntList(cBuf, ',', &mstNumList);
		//		if (cnt > 5)
		//		{
		//			this->showLogInfo("高级主机最多支持5个！\r\n");
		//		}
		//		else
		//		{
		//			int headMst[5] = { 0 };
		//			memcpy(headMst, mstNumList, cnt * sizeof(int));
		//			if (0 == lb_setting_set((lb_setting_key_e)selKey, headMst, 5 * sizeof(int)))
		//			{
		//				this->showLogInfo("设置成功！\r\n");
		//			}
		//			else this->showLogInfo("设置失败！\r\n");
		//		}
		//		delete[] mstNumList;
		//		return;
		//	}
		//	break;
		//case LBSETTING_KEY_NOASWUPTRANS_TIME:
		//	if (this->runLevel_mode == LB_RUNLVL_SENIOR)
		//	{
		//		this->showLogInfo("高级主机没有本项设置\r\n");
		//		break;
		//	}
		//	this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
		//	if (0 == strlen(cBuf))
		//	{
		//		this->showLogInfo("没有输入值！\r\n");
		//		break;
		//	}
		//	if (!isDigit(cBuf))
		//	{
		//		this->showLogInfo("非法输入！\r\n");
		//		break;
		//	}
		//	nVal = atoi(cBuf);
		//	pVal = &nVal;
		//	len = sizeof(int);
		//	break;
		//case LBSETTING_KEY_REPMST:
		//	if (this->runLevel_mode == LB_RUNLVL_SENIOR)
		//	{
		//		this->showLogInfo("高级主机没有本项设置\r\n");
		//		break;
		//	}
		//	this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
		//	if (0 == strlen(cBuf))
		//	{
		//		this->showLogInfo("没有输入值！\r\n");
		//		break;
		//	}
		//	if (!isDigit(cBuf))
		//	{
		//		this->showLogInfo("非法输入！\r\n");
		//		break;
		//	}
		//	nVal = atoi(cBuf);
		//	pVal = &nVal;
		//	len = sizeof(int);
		//	break;
		case LBSETTING_KEY_EXTN_NSALARM_LVL:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_RECORD_PATH:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_RECORD_ENA:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_RECORD_UPLOAD_ENA:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_RECORD_UPLOAD_SERVERIP:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));

			if (0 < strlen(cBuf) && !isValidIP(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_EXTNCALLIN_ADPY_MODE:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <LBSET_VOICERING_GENERAL || nVal >LBSET_VOICERING_BUILDING_LIFT)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_CRCLISTENTIME:         //循环监听单个分机的时长
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_MYEXTNCALLOUT_MAXTIME:    //本机直属分机呼叫，无人接听，呼叫的最大时长，超时自动挂断，设为‘0’则一直呼叫，不会自动挂断
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		//case LBSETTING_KEY_TRANS_EXTNINFO_ADTLMST:     //设置上传描述信息和报号信息的附加主机，是指除了上级主机之外的需要本机直属分机信息的主机，可设多个
		//	if (this->runLevel_mode == LB_RUNLVL_SENIOR)
		//	{
		//		this->showLogInfo("高级主机没有本项设置\r\n");
		//		break;
		//	}
		//	this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
		//	if (0 == strlen(cBuf))
		//	{
		//		if (0 == lb_setting_set((lb_setting_key_e)selKey, NULL, 0))
		//		{
		//			this->showLogInfo("设置成功！\r\n");
		//		}
		//		else this->showLogInfo("设置失败！\r\n");
		//		return;
		//	}
		//	else
		//	{
		//		int *mstNumList = NULL, cnt = 0;
		//		cnt = lb_strToIntList(cBuf, ',', &mstNumList);
		//		if (0 == lb_setting_set((lb_setting_key_e)selKey, mstNumList, cnt * sizeof(int)))
		//		{
		//			this->showLogInfo("设置成功！\r\n");
		//		}
		//		else this->showLogInfo("设置失败！\r\n");
		//		delete[] mstNumList;
		//		return;
		//	}
		//	break;
		//case LBSETTING_KEY_CALL_ADTLMST:     //设置呼叫的附加主机，是指除了上级主机之外的其他本机直属分机还要呼叫的主机，可设多个
		//	this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
		//	if (0 == strlen(cBuf))
		//	{
		//		if (0 == lb_setting_set((lb_setting_key_e)selKey, NULL, 0))
		//		{
		//			this->showLogInfo("设置成功！\r\n");
		//		}
		//		else this->showLogInfo("设置失败！\r\n");
		//		return;
		//	}
		//	else
		//	{
		//		int *mstNumList = NULL, cnt = 0;
		//		cnt = lb_strToIntList(cBuf, ',', &mstNumList);
		//		if (0 == lb_setting_set((lb_setting_key_e)selKey, mstNumList, cnt * sizeof(int)))
		//		{
		//			this->showLogInfo("设置成功！\r\n");
		//		}
		//		else this->showLogInfo("设置失败！\r\n");
		//		delete[] mstNumList;
		//		return;
		//	}
		//	break;
		case LBSETTING_KEY_CALL_ADTLMST_DLYTM:    //相比呼叫直属主机，分机延迟多久呼叫附加主机，设为‘0’则同时呼叫
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_TRIAGE_MSTNUM:
			this->showLogInfo("分诊系统才有效\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
			this->showLogInfo("没有输入值！\r\n");
			break;
			}
			if (!isDigit(cBuf))
			{
			this->showLogInfo("非法输入！\r\n");
			break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);*/
			break;
		case LBSETTING_KEY_TRIAGE_GROUPNUM:
			this->showLogInfo("分诊系统才有效\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
			this->showLogInfo("没有输入值！\r\n");
			break;
			}
			if (!isDigit(cBuf))
			{
			this->showLogInfo("非法输入！\r\n");
			break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);*/
			break;
		case LBSETTING_KEY_TRIAGE_DEVNUM:
			this->showLogInfo("分诊系统才有效\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
			this->showLogInfo("没有输入值！\r\n");
			break;
			}
			if (!isDigit(cBuf))
			{
			this->showLogInfo("非法输入！\r\n");
			break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);*/
			break;
		case LBSETTING_KEY_RINGMUSIC_NANME:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		//case LBSETTING_KEY_FORBID_EXTNCALLIN:
		//	if (this->runLevel_mode == LB_RUNLVL_PRIMARY)
		//	{
		//		this->showLogInfo("一级主机没有本项设置\r\n");
		//		break;
		//	}
		//	this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
		//	if (0 == strlen(cBuf))
		//	{
		//		this->showLogInfo("没有输入值！\r\n");
		//		break;
		//	}
		//	if (!isDigit(cBuf))
		//	{
		//		this->showLogInfo("非法输入！\r\n");
		//		break;
		//	}
		//	nVal = atoi(cBuf);
		//	if (nVal != 0 && nVal != 1)
		//	{
		//		this->showLogInfo("非法输入！\r\n");
		//		break;
		//	}
		//	pVal = &nVal;
		//	len = sizeof(int);
		//	break;
		case LBSETTING_KEY_HIS_ENABLED:					// 是否启用HIS系统连接
			this->showLogInfo("医院对讲系统才有效\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
			this->showLogInfo("没有输入值！\r\n");
			break;
			}
			if (!isDigit(cBuf))
			{
			this->showLogInfo("非法输入！\r\n");
			break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
			this->showLogInfo("非法输入！\r\n");
			break;
			}
			pVal = &nVal;
			len = sizeof(int);*/
			break;
		case LBSETTING_KEY_HIS_SERVERIP:				// HIS服务器IP
			this->showLogInfo("医院对讲系统才有效\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));

			if (0 < strlen(cBuf) && !isValidIP(cBuf))
			{
			this->showLogInfo("非法输入！\r\n");
			break;
			}
			pVal = cBuf;
			len = strlen(cBuf);*/
			break;
		case LBSETTING_KEY_HIS_ZONENUMBER:				// 病区号
			this->showLogInfo("医院对讲系统才有效\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
			this->showLogInfo("没有输入值！\r\n");
			break;
			}
			if (!isDigit(cBuf))
			{
			this->showLogInfo("非法输入！\r\n");
			break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);*/
			break;
		case LBSETTING_KEY_DOORLAMPCOLOR:				// 门灯颜色标准
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_DUTYDOCTOR_PATH:				// 责任医生照片存储路径
			this->showLogInfo("医院对讲系统才有效\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);*/
			break;
		case LBSETTING_KEY_DUTYNURSE_PATH:				// 责任护士照片存储路径
			this->showLogInfo("医院对讲系统才有效\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);*/
			break;
		case LBSETTING_KEY_CALLONBUSY_TRANS_ENA:         // 遇忙转移功能使能
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_CALLONBUSY_TRANS_MST:         // 遇忙转移的被叫主机号
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_CONSULTCALL_MST:              // 咨询呼叫主机的号码
			this->showLogInfo("主机不支持本项配置！\r\n");
			break;
		case LBSETTING_KEY_LANGUAGE:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_RING_ONCONN_ENA:              // 在通话中，其他呼叫是否振铃提示
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_EXTNOFFLN_VNTY_ENA:           // 直属分机掉线，是否语音提示
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_MYEXTN_TKBELSN_ENA:           // 直属分机与本机或托管主机通话，是否允许高级主机监听,第三方监听
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_EXTERNALALARM_DESC1:          // 外接报警信号1的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC2:          // 外接报警信号2的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC3:          // 外接报警信号3的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC4:          // 外接报警信号4的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC5:          // 外接报警信号5的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC6:          // 外接报警信号6的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC7:          // 外接报警信号7的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC8:          // 外接报警信号8的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC9:          // 外接报警信号9的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC10:         // 外接报警信号10的描述信息
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_VIDEOCLARITY:                 // 视频图像的清晰度，0－普清，1－标清，2－高清
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal < 0 || nVal > 2)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_MULTITALKVID_ENA:             //多方通话支持视频
		case LBSETTING_KEY_RINGINTERNAL_DIS:		    	// 禁止内部振铃及语音播报
		case LBSETTING_KEY_DR1OP_TIMEOUTALARM_ENA:		// 门磁1触发，超时报警使能
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_ALARMRINGMUSIC_NAME:			// 报警音乐铃声
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_DR1OP_TIMEOUTALARM_TM:		// 门磁1触发，超时报警超时时长
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <= 0)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_SIP_ENABLE:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <= 0)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_SIP_SERVER_ADDRESS:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isValidIP(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_SIP_SERVER_PORT:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <= 0)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_SIP_USERNAME:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_SIP_PASSWORD:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_SIP_ENABLE_2:

			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <= 0)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case  LBSETTING_KEY_SIP_SERVER_ADDRESS_2:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isValidIP(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_SIP_SERVER_PORT_2:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <= 0)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_SIP_USERNAME_2:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_SIP_PASSWORD_2:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_SIP_ENABLE_3:

			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <= 0)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case  LBSETTING_KEY_SIP_SERVER_ADDRESS_3:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isValidIP(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_SIP_SERVER_PORT_3:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("没有输入值！\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <= 0)
			{
				this->showLogInfo("非法输入！\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_SIP_USERNAME_3:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_SIP_PASSWORD_3:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		default:
			break;
		}
		if (pVal)
		{
			if (0 == lb_setting_set((lb_setting_key_e)selKey, pVal, len))
			{
				this->showLogInfo("设置成功！\r\n");
			}
			else this->showLogInfo("设置失败！\r\n");
		}
	}
}


void Clb_extension_demoDlg::OnBnClickedgetsetting()
{

	{
		// TODO: 在此添加控件通知处理程序代码
		if (!this->isInitialOK)
		{
			this->showLogInfo("启动中，请稍等...\r\n");
		}
		int selKey = this->m_getKey.GetCurSel();
		int nVal = 0, bufSize = 0, valSize = 0;
		char cBuf[256] = { 0 }, tip[256] = { 0 };
		switch (selKey)
		{
		case LBSETTING_KEY_DISPLAYNUM:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "本机编号：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_ADDRMANAGESVR:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "地址盒地址：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_EXTNVOL:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "直属分机音量：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_LAN_CODEC:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "点对点模式编解码方案：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_WAN_CODEC:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "服务器模式编解码方案：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		//case LBSETTING_KEY_HEADMST:
		//	if (this->runLevel_mode == LB_RUNLVL_SENIOR)
		//	{
		//		this->showLogInfo("高级主机没有本项设置\r\n");
		//		break;
		//	}
		//	else
		//	{
		//		int headerNumList[5] = { 0 };
		//		if (0 == lb_setting_get((lb_setting_key_e)selKey, headerNumList, sizeof(headerNumList), &valSize))
		//		{
		//			int cnt = valSize / sizeof(int), i = 0;
		//			strcpy(tip, "上级主机：");
		//			for (i = 0; i < cnt; i++)
		//			{
		//				if (headerNumList[i]>0) sprintf(tip + strlen(tip), "  %d", headerNumList[i]);
		//			}
		//			strcat(tip, "\r\n");
		//			this->showLogInfo(tip);
		//		}
		//		else this->showLogInfo("读取失败\r\n");
		//	}
		//	break;
		//case LBSETTING_KEY_NOASWUPTRANS_TIME:
		//	if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
		//	{
		//		sprintf(tip, "呼叫上传时间：%d\r\n", nVal);
		//		this->showLogInfo(tip);
		//	}
		//	else this->showLogInfo("读取失败\r\n");
		//	break;
		//case LBSETTING_KEY_REPMST:
		//	if (this->runLevel_mode == LB_RUNLVL_SENIOR)
		//	{
		//		this->showLogInfo("高级主机没有本项设置\r\n");
		//		break;
		//	}
		//	if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
		//	{
		//		sprintf(tip, "托管主机：%d\r\n", nVal);
		//		this->showLogInfo(tip);
		//	}
		//	else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_EXTN_NSALARM_LVL:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "喧哗报警灵敏度级别：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_RECORD_PATH:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "录音录像文件存储路径：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_RECORD_ENA:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "录音录像使能：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_RECORD_UPLOAD_ENA:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "录音录像文件自动上传使能：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_RECORD_UPLOAD_SERVERIP:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "录音录像文件自动上传的接收服务器地址：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_EXTNCALLIN_ADPY_MODE:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "分机呼入语音播报方式：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_CRCLISTENTIME:         //循环监听单个分机的时长
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "循环监听单个分机的时长：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_MYEXTNCALLOUT_MAXTIME:    //本机直属分机呼叫，无人接听，呼叫的最大时长，超时自动挂断，设为‘0’则一直呼叫，不会自动挂断
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "直属分机呼叫最大时长：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_TRANS_EXTNINFO_ADTLMST:     //设置上传描述信息和报号信息的附加主机，是指除了上级主机之外的需要本机直属分机信息的主机，可设多个
		{
			int *numList = NULL, cnt = 0;
			lb_setting_get((lb_setting_key_e)selKey, NULL, 0, &valSize);
			cnt = valSize / sizeof(int);
			numList = new int[cnt];
			bufSize = valSize;
			if (0 == lb_setting_get((lb_setting_key_e)selKey, numList, bufSize, &valSize))
			{
				int cnt = valSize / sizeof(int), i = 0;
				strcpy(tip, "接收本机分机的描述信息和报号信息的附加主机：");
				for (i = 0; i < cnt; i++)
				{
					if (numList[i]>0) sprintf(tip + strlen(tip), "  %d", numList[i]);
				}
				strcat(tip, "\r\n");
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
		}
		break;
		case LBSETTING_KEY_CALL_ADTLMST:     //设置呼叫的附加主机，是指除了上级主机之外的其他本机直属分机还要呼叫的主机，可设多个
		{
			int *numList = NULL, cnt = 0;
			lb_setting_get((lb_setting_key_e)selKey, NULL, 0, &valSize);
			cnt = valSize / sizeof(int);
			numList = new int[cnt];
			bufSize = valSize;
			if (0 == lb_setting_get((lb_setting_key_e)selKey, numList, bufSize, &valSize))
			{
				int cnt = valSize / sizeof(int), i = 0;
				strcpy(tip, "本机分机呼叫的附加主机：");
				for (i = 0; i < cnt; i++)
				{
					if (numList[i]>0) sprintf(tip + strlen(tip), "  %d", numList[i]);
				}
				strcat(tip, "\r\n");
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
		}
		break;
		case LBSETTING_KEY_CALL_ADTLMST_DLYTM:    //相比呼叫直属主机，分机延迟多久呼叫附加主机，设为‘0’则同时呼叫
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "呼叫附加主机延迟时长：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_TRIAGE_MSTNUM:
			this->showLogInfo("分诊系统才有效\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
			sprintf(tip, "分诊主机编号：%d\r\n", nVal);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");*/
			break;
		case LBSETTING_KEY_TRIAGE_GROUPNUM:
			this->showLogInfo("分诊系统才有效\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
			sprintf(tip, "分诊组号：%d\r\n", nVal);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");*/
			break;
		case LBSETTING_KEY_TRIAGE_DEVNUM:
			this->showLogInfo("分诊系统才有效\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
			sprintf(tip, "分诊设备号：%d\r\n", nVal);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");*/
			break;
		case LBSETTING_KEY_RINGMUSIC_NANME:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "振铃音乐文件：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		//case LBSETTING_KEY_FORBID_EXTNCALLIN:
		//	if (this->runLevel_mode == LB_RUNLVL_PRIMARY)
		//	{
		//		this->showLogInfo("一级主机没有本项设置\r\n");
		//		break;
		//	}
		//	if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
		//	{
		//		sprintf(tip, "禁止分机呼入：%d\r\n", nVal);
		//		this->showLogInfo(tip);
		//	}
		//	else this->showLogInfo("读取失败\r\n");
		//	break;
		case LBSETTING_KEY_HIS_ENABLED:					// 是否启用HIS系统连接
			this->showLogInfo("医院对讲系统才有效\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
			sprintf(tip, "连接HIS使能：%d\r\n", nVal);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");*/
			break;
		case LBSETTING_KEY_HIS_SERVERIP:				// HIS服务器IP
			this->showLogInfo("医院对讲系统才有效\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
			sprintf(tip, "HIS服务器地址：%s\r\n", cBuf);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");*/
			break;
		case LBSETTING_KEY_HIS_ZONENUMBER:				// 病区号
			this->showLogInfo("医院对讲系统才有效\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
			sprintf(tip, "病区号：%d\r\n", nVal);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");*/
			break;
		case LBSETTING_KEY_DOORLAMPCOLOR:				// 门灯颜色标准
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "门灯颜色标准：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_DUTYDOCTOR_PATH:				// 责任医生照片存储路径
			this->showLogInfo("医院对讲系统才有效\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
			sprintf(tip, "责任医生照片存储路径：%s\r\n", cBuf);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");*/
			break;
		case LBSETTING_KEY_DUTYNURSE_PATH:				// 责任护士照片存储路径
			this->showLogInfo("医院对讲系统才有效\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
			sprintf(tip, "责任护士照片存储路径：%s\r\n", cBuf);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");*/
			break;
		case LBSETTING_KEY_CALLONBUSY_TRANS_ENA:         // 遇忙转移功能使能
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "遇忙转移使能：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_CALLONBUSY_TRANS_MST:         // 遇忙转移的被叫主机号
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "遇忙转移的被叫主机号：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_CONSULTCALL_MST:              // 咨询呼叫主机的号码
			this->showLogInfo("主机不支持本项配置！\r\n");
			break;
		case LBSETTING_KEY_LANGUAGE:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "语言：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_RING_ONCONN_ENA:              // 在通话中，其他呼叫是否振铃提示
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "通话中其他呼叫是否振铃提示：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_EXTNOFFLN_VNTY_ENA:           // 直属分机掉线，是否语音提示
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "直属分机掉线是否语音提示：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_MYEXTN_TKBELSN_ENA:           // 直属分机与本机或托管主机通话，是否允许高级主机监听,第三方监听
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "第三方监听使能：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_EXTERNALALARM_DESC1:          // 外接报警信号1的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC2:          // 外接报警信号2的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC3:          // 外接报警信号3的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC4:          // 外接报警信号4的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC5:          // 外接报警信号5的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC6:          // 外接报警信号6的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC7:          // 外接报警信号7的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC8:          // 外接报警信号8的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC9:          // 外接报警信号9的描述信息
		case LBSETTING_KEY_EXTERNALALARM_DESC10:         // 外接报警信号10的描述信息
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "外接报警%d描述：%s\r\n", selKey - LBSETTING_KEY_EXTERNALALARM_DESC1 + 1, cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_VIDEOCLARITY:                 // 视频图像的清晰度，0－普清，1－标清，2－高清
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "视频图像的清晰度：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_MULTITALKVID_ENA:             //多方通话支持视频
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "多方通话支持视频使能：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_ALARMRINGMUSIC_NAME:			// 报警音乐铃声
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "紧急报警振铃音乐文件：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_RINGINTERNAL_DIS:		    	// 禁止内部振铃及语音播报
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "禁止内部振铃及语音播报使能：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_DR1OP_TIMEOUTALARM_ENA:		// 门磁1触发，超时报警使能
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "门磁1触发超时报警使能：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_DR1OP_TIMEOUTALARM_TM:		// 门磁1触发，超时报警超时时长
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "门磁1触发超时报警超时时长：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_ENABLE:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "启用标准SIP使能：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_SERVER_ADDRESS:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP服务器地址：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_SERVER_PORT:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP服务器端口：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_USERNAME:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP账号用户名：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_PASSWORD:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP账号密码：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_ENABLE_2:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "启用标准SIP2使能：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_SERVER_ADDRESS_2:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP服务器地址2：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_SERVER_PORT_2:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP服务器端口2：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_USERNAME_2:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP账号用户名2：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_PASSWORD_2:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP账号密码2：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_ENABLE_3:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "启用标准SIP3使能：%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_SERVER_ADDRESS_3:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP服务器地址3：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_SERVER_PORT_3:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP服务器端口3：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_USERNAME_3:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP账号用户名3：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		case LBSETTING_KEY_SIP_PASSWORD_3:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP账号密码3：%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("读取失败\r\n");
			break;
		default:
			break;
		}
	}
}
