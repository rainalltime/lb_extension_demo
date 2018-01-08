
// lb_extension_demoDlg.cpp : ʵ���ļ�
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


// Clb_extension_demoDlg �Ի���



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


// Clb_extension_demoDlg ��Ϣ�������

BOOL Clb_extension_demoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	this->m_sn.SetWindowText(_T("1003"));
	this->m_sipAcc.SetWindowText(_T("111111"));
	this->m_sipPwd.SetWindowText(_T("222242"));
	this->m_udpPort.SetWindowText(_T("5062"));
	m_workDir.SetWindowText(L"..\\Debug\\win32\\ipIntercom");
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	this->m_setKey.AddString(_T("LBSETTING_KEY_DISPLAYNUM(���)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_ADDRMANAGESVR(��ַ�е�ַ)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTNVOL(ֱ���ֻ�����)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_LAN_CODEC(��Ե�ģʽ���뷽��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_WAN_CODEC(������ģʽ���뷽��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_HEADMST(�ϼ�����)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_NOASWUPTRANS_TIME(��Ӧ���ϴ�ʱ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_REPMST(�й�����)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTN_NSALARM_LVL(������������)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_RECORD_PATH(¼��¼���ļ�·��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_RECORD_ENA(¼��¼��ʹ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTNCALLIN_ADPY_MODE(�ֻ����뱨��ģʽ)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_CRCLISTENTIME(ѭ������ʱ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_MYEXTNCALLOUT_MAXTIME(ֱ���ֻ��������ʱ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_TRANS_EXTNINFO_ADTLMST(�ֻ�������Ϣ�ϴ��ĸ��������б�)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_CALL_ADTLMST(�ֻ����еĸ��������б�)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_CALL_ADTLMST_DLYTM(�ֻ����и�����������ʱʱ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_TRIAGE_MSTNUM(�����������)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_TRIAGE_GROUPNUM(�������)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_TRIAGE_DEVNUM(�����豸��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_RECORD_UPLOAD_ENA(¼��¼���ļ��Զ��ϴ�ʹ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_RECORD_UPLOAD_SERVERIP(¼��¼���ļ����շ�����)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_RINGMUSIC_NANME(��ͨ����������������)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_FORBID_EXTNCALLIN(��ֹ�ֻ�����ʹ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_HIS_ENABLED(����HISʹ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_HIS_SERVERIP(HIS��������ַ)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_HIS_ZONENUMBER(������)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_DOORLAMPCOLOR(�ŵ���ɫ��׼)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_DUTYDOCTOR_PATH(����ҽ����Ƭ�洢·��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_DUTYNURSE_PATH(���λ�ʿ��Ƭ�洢·��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_CALLONBUSY_TRANS_ENA(��æת�ƹ���ʹ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_CALLONBUSY_TRANS_MST(��æת�Ƶı���������)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_CONSULTCALL_MST(��ѯ����������)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_LANGUAGE(����)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_RING_ONCONN_ENA(ͨ���к�������ʹ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTNOFFLN_VNTY_ENA(ֱ���ֻ�����������ʾʹ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_MYEXTN_TKBELSN_ENA(����������ʹ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC1(��ӱ����ź�1��������Ϣ)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC2(��ӱ����ź�2��������Ϣ)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC3(��ӱ����ź�3��������Ϣ)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC4(��ӱ����ź�4��������Ϣ)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC5(��ӱ����ź�5��������Ϣ)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC6(��ӱ����ź�6��������Ϣ)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC7(��ӱ����ź�7��������Ϣ)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC8(��ӱ����ź�8��������Ϣ)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC9(��ӱ����ź�9��������Ϣ)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC10(��ӱ����ź�10��������Ϣ)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_VIDEOCLARITY(��Ƶ������)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_MULTITALKVID_ENA(�෽ͨ��֧����Ƶʹ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_ALARMRINGMUSIC_NAME(��������������������)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_RINGINTERNAL_DIS(��ֹ�ڲ����弰��������ʹ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_DR1OP_TIMEOUTALARM_ENA(�Ŵ�1�������ó�ʱ����ʹ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_DR1OP_TIMEOUTALARM_TM(�Ŵ�1������ʱ������ʱʱ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_PLAYFILE_ENA(ͨ���в岥�ļ�ʹ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_FONT_SCREEN_TIME_TYPE(��������ʾ��ʽ)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_FONT_SCREEN_PROMPTING(��������ʾ��)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_FONT_SCREEN_MODE(������ģʽ����)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_ENABLE(�Ƿ����ñ�׼SIP)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_ADDRESS(��׼SIP������IP)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_PORT(��׼SIP�������˿�)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_USERNAME(��׼SIP�˻��û���)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_PASSWORD(��׼SIP�˻�����)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_ENABLE(�Ƿ����ñ�׼SIP2)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_ADDRESS(��׼SIP������IP2)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_PORT(��׼SIP�������˿�2)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_USERNAME(��׼SIP�˻��û���2)"));
	this->m_setKey.AddString(_T("LBSETTING_KEY_SIP_PASSWORD(��׼SIP�˻�����2)"));
	this->m_setKey.SetCurSel(0);

	this->m_getKey.AddString(_T("LBSETTING_KEY_DISPLAYNUM(���)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_ADDRMANAGESVR(��ַ�е�ַ)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTNVOL(ֱ���ֻ�����)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_LAN_CODEC(��Ե�ģʽ���뷽��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_WAN_CODEC(������ģʽ���뷽��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_HEADMST(�ϼ�����)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_NOASWUPTRANS_TIME(��Ӧ���ϴ�ʱ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_REPMST(�й�����)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTN_NSALARM_LVL(������������)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_RECORD_PATH(¼��¼���ļ�·��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_RECORD_ENA(¼��¼��ʹ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTNCALLIN_ADPY_MODE(�ֻ����뱨��ģʽ)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_CRCLISTENTIME(ѭ������ʱ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_MYEXTNCALLOUT_MAXTIME(ֱ���ֻ��������ʱ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_TRANS_EXTNINFO_ADTLMST(�ֻ�������Ϣ�ϴ��ĸ��������б�)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_CALL_ADTLMST(�ֻ����еĸ��������б�)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_CALL_ADTLMST_DLYTM(�ֻ����и�����������ʱʱ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_TRIAGE_MSTNUM(�����������)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_TRIAGE_GROUPNUM(�������)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_TRIAGE_DEVNUM(�����豸��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_RECORD_UPLOAD_ENA(¼��¼���ļ��Զ��ϴ�ʹ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_RECORD_UPLOAD_SERVERIP(¼��¼���ļ����շ�����)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_RINGMUSIC_NANME(������������)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_FORBID_EXTNCALLIN(��ֹ�ֻ�����ʹ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_HIS_ENABLED(����HISʹ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_HIS_SERVERIP(HIS��������ַ)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_HIS_ZONENUMBER(������)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_DOORLAMPCOLOR(�ŵ���ɫ��׼)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_DUTYDOCTOR_PATH(����ҽ����Ƭ�洢·��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_DUTYNURSE_PATH(���λ�ʿ��Ƭ�洢·��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_CALLONBUSY_TRANS_ENA(��æת�ƹ���ʹ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_CALLONBUSY_TRANS_MST(��æת�Ƶı���������)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_CONSULTCALL_MST(��ѯ����������)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_LANGUAGE(����)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_RING_ONCONN_ENA(ͨ���к�������ʹ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTNOFFLN_VNTY_ENA(ֱ���ֻ�����������ʾʹ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_MYEXTN_TKBELSN_ENA(����������ʹ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC1(��ӱ����ź�1��������Ϣ)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC2(��ӱ����ź�2��������Ϣ)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC3(��ӱ����ź�3��������Ϣ)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC4(��ӱ����ź�4��������Ϣ)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC5(��ӱ����ź�5��������Ϣ)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC6(��ӱ����ź�6��������Ϣ)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC7(��ӱ����ź�7��������Ϣ)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC8(��ӱ����ź�8��������Ϣ)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC9(��ӱ����ź�9��������Ϣ)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_EXTERNALALARM_DESC10(��ӱ����ź�10��������Ϣ)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_VIDEOCLARITY(��Ƶ������)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_MULTITALKVID_ENA(�෽ͨ��֧����Ƶʹ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_ALARMRINGMUSIC_NAME(��������������������)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_RINGINTERNAL_DIS(��ֹ�ڲ����弰��������ʹ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_DR1OP_TIMEOUTALARM_ENA(�Ŵ�1�������ó�ʱ����ʹ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_DR1OP_TIMEOUTALARM_TM(�Ŵ�1������ʱ������ʱʱ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_PLAYFILE_ENA(ͨ���в岥�ļ�ʹ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_FONT_SCREEN_TIME_TYPE(��������ʾ��ʽ)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_FONT_SCREEN_PROMPTING(��������ʾ��)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_FONT_SCREEN_MODE(������ģʽ����)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_ENABLE(�Ƿ����ñ�׼SIP)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_ADDRESS(��׼SIP������IP)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_PORT(��׼SIP�������˿�)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_USERNAME(��׼SIP�˻��û���)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_PASSWORD(��׼SIP�˻�����)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_ENABLE(�Ƿ����ñ�׼SIP2)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_ADDRESS(��׼SIP������IP2)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_SERVER_PORT(��׼SIP�������˿�2)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_USERNAME(��׼SIP�˻��û���2)"));
	this->m_getKey.AddString(_T("LBSETTING_KEY_SIP_PASSWORD(��׼SIP�˻�����2)"));
	this->m_getKey.SetCurSel(0);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Clb_extension_demoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	case LB_UA2UI_CALL_PROCESSING:                //����������
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "����%d�����ڴ����С���\r\n", param1);
		break;
	case LB_UA2UI_CALL_RINGBACK:                  //��������
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "����%d������\r\n", param1);
		break;
	case LB_UA2UI_CALL_LSTN_CONNECT:              //������ͨ
	{
		int rmtProperty = *(int *)param2;
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		if (lb_info_isRmtSupportVideo(rmtProperty))
		{
			//�Է�֧������ͷ����Ҫ����Ƶ��ʾ�򡭡�
			//......
			pThis->m_video.ShowWindow(SW_SHOW);
			pThis->m_myVideo.ShowWindow(SW_SHOW);

			//��ʾ���ʼ����ɣ��򿪶Է�������ͷ
			//if (!lb_info_isRmtVideoCtrEna(rmtProperty))
			//{
			//	lb_fun_notifyRmtVideo_on();            //��ͨ�ʹ򿪶Է�������ͷ
			//}
		}
		sprintf(tip, "����%d�Ž�ͨ\r\n��һ�οո��תΪ�Խ�ģʽ\r\n", param1);
	}
	break;
	case LB_UA2UI_CALL_TALK_CONNECT:              //�Խ���ͨ
	{
		int rmtProperty = *(int *)param2;
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		if (lb_info_isRmtSupportVideo(rmtProperty))
		{
			//�Է�֧������ͷ����Ҫ����Ƶ��ʾ�򡭡�
			//......
			pThis->m_video.ShowWindow(SW_SHOW);
			pThis->m_myVideo.ShowWindow(SW_SHOW);

			//��ʾ���ʼ����ɣ��򿪶Է�������ͷ
			//if (!lb_info_isRmtVideoCtrEna(rmtProperty))
			//{
			//	lb_fun_notifyRmtVideo_on();            //��ͨ�ʹ򿪶Է�������ͷ
			//}

			//pThis->m_btn_myVd_on.EnableWindow(TRUE);
			//pThis->m_btn_myVd_off.EnableWindow(FALSE);
		}
		sprintf(tip, "��%d�ŶԽ���ͨ\r\n", param1);
		//if (!pThis->fullDuplexEna)
		//{
		//	sprintf(&tip[strlen(tip)], "Ҫ�����밴ס�ո�����������ɿ��ո�����Է�����\r\n");
		//}
	}
	break;
	case LB_UA2UI_CALL_DISCONNECT:                //ͨ������йҶ�
	{
		//��Ƶ�����Դ�ͷ�
		pThis->m_video.ShowWindow(SW_HIDE);
		pThis->m_myVideo.ShowWindow(SW_HIDE);

		//pThis->m_btn_myVd_on.EnableWindow(FALSE);
		//pThis->m_btn_myVd_off.EnableWindow(FALSE);

		sprintf(tip, "�Ҷ���%d�ŵ�ͨ�������\r\n", param1);
	}
	break;
	case LB_UA2UI_CALL_REFUSE:                    //�������ܾ�
		sprintf(tip, "%d�žܾ���������\r\n", param1);
		break;
	case LB_UA2UI_CALL_BUSY:                      //�Է�æ
		sprintf(tip, "%d�ŵ�ǰ��æ\r\n", param1);
		break;
	case LB_UA2UI_CALL_FAIL:                      //����ʧ��
		sprintf(tip, "����%d��ʧ��\r\n", param1);
		break;
	case LB_UA2UI_CALL_TIMEOUT:                   //������ʱ����Ӧ
		sprintf(tip, "����%d�ų�ʱ\r\n", param1);
		break;
	case LB_UA2UI_CALL_CALLIN:                    //��ͨ����
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "%d�ź���\r\n", param1);
		break;
	case LB_UA2UI_CALL_EMERGENCYCALL:             //��������
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "%d�Ž�������\r\n", param1);
		break;
	case LB_UA2UI_CALL_NSALARM:                   //��������
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "%d����������\r\n", param1);
		break;
	case LB_UA2UI_CALL_CANCEL:                    //�Է�ȡ������
		sprintf(tip, "%d��ȡ������\r\n", param1);
		break;

	case LB_UA2UI_BC_START:                       //�㲥�ɹ�����
		sprintf(tip, "�㲥�����ɹ�������Ϊ%d\r\n", param1);
		break;
	case LB_UA2UI_BC_STOP:                        //�㲥ֹͣ
		sprintf(tip, "����Ϊ%d�Ĺ㲥ֹͣ\r\n", param1);
		break;
	case LB_UA2UI_BC_NOTALLOW:                    //�㲥�г�ͻ������������
		sprintf(tip, "����Ϊ%d�Ĺ㲥�����г�ͻ�����ܵ�ǰ�Ѿ��и��߼���㲥���Ѿ���������㲥�ڶԱ���㲥������һ��������Ա�㲥\r\n", param1);
		break;
	case LB_UA2UI_BC_FAIL:
		sprintf(tip, "����Ϊ%d�Ĺ㲥����ʧ�ܣ�������û�ж��󣬻��߱���û�л�ȡ����ĵ�ַ�������ļ��㲥û���ļ���\r\n", param1);
		break;
	case LB_UA2UI_BC_SPK_PROCESSING:              //�����㲥�����С���
		sprintf(tip, "�����㲥��������������Ϊ%d\r\n", param1);
		break;
	case LB_UA2UI_BC_SPK_START:                   //�����㲥�ɹ����������Ժ���
		sprintf(tip, "�����㲥�����ɹ�������Ϊ%d�����Ժ���\r\n", param1);
		break;
	case LB_UA2UI_BC_SPK_STOP:                    //�����㲥ֹͣ
		sprintf(tip, "����Ϊ%d�ĺ����㲥ֹͣ\r\n", param1);
		break;
	case LB_UA2UI_BC_SPK_FAIL:                    //�����㲥����ʧ��
		sprintf(tip, "�����㲥����ʧ�ܣ�����Ϊ%d��������û�ж��󣬻��߱���û�л�ȡ����ĵ�ַ\r\n", param1);
		break;
	case LB_UA2UI_BC_FILE_PAUSE:                  //�ļ��㲥��ͣ�����ؿ�����ͣ��ִ�гɹ����ص��¼�
		sprintf(tip, "����Ϊ%d���ļ��㲥��ͣ\r\n", param1);
		break;
	case LB_UA2UI_BC_FILE_BREAK2PAUSE:            //�ļ��㲥��ʱ��ͣ����Ϊ�廰��߼���㲥��������ͣ�����Զ��ָ�
		sprintf(tip, "����Ϊ%d���ļ��㲥��ͣ\r\n", param1);
		break;
	case LB_UA2UI_BC_FILE_PLAY_END:               //�ļ��㲥ʱ��һ���ļ����Ž���������������һ���ļ�
	{
		int fileIndex = *(int *)param2;
		sprintf(tip, "����Ϊ%d���ļ��㲥�ĵ�%d���ļ����Ž���������������һ���ļ�\r\n", param1, fileIndex + 1);
	}
	break;
	case LB_UA2UI_BC_TRANS2EXTN_START:            //�յ����������Ա�����ֱ���ֻ��㲥������ת����ֱ���ֻ�
		sprintf(tip, "����ת��%d�������Ĺ㲥��ֱ���ֻ�\r\n", param1);
		break;
	case LB_UA2UI_BC_TRANS2EXTN_STOP:             //ת���㲥��ֱ���ֻ�����
		sprintf(tip, "��������ת��%d�������Ĺ㲥��ֱ���ֻ�\r\n", param1);
		break;
	case LB_UA2UI_BEBC_START:                     //��ʼ���㲥
		sprintf(tip, "�����յ�%d�������Ա����Ĺ㲥\r\n", param1);
		break;
	case LB_UA2UI_BEBC_STOP:                      //ֹͣ���㲥
		sprintf(tip, "%d�������Ա����Ĺ㲥����\r\n", param1);
		break;

	case LB_UA2UI_CRCLST_FAIL:                    //ѭ����������ʧ��
		sprintf(tip, "ѭ����������ʧ�ܣ������Ǳ���æ������%d������û�зֻ�\r\n", param1);
		break;
	case LB_UA2UI_CRCLST_EXTN_START:              //��ʼ����ĳһ�ֻ�
		sprintf(tip, "��ʼ����%d�ŷֻ�\r\n", param1);
		break;
	case LB_UA2UI_CRCLST_EXTN_STOP:               //��������ĳһ�ֻ�
		sprintf(tip, "��������%d�ŷֻ�\r\n", param1);
		break;
	case LB_UA2UI_CRCLST_EXTN_FAIL:               //ѭ������ĳһ�ֻ�ʧ�ܣ������������һ���ֻ�
		sprintf(tip, "����%d�ŷֻ�ʧ��\r\n", param1);
		break;
	case LB_UA2UI_CRCLST_FINISH:                  //ѭ������ֹͣ
		sprintf(tip, "ѭ������%d�������ķֻ�ֹͣ\r\n", param1);
		break;

	case LB_UA2UI_EXTN_IO_DR1_OPEN:               //�ֻ����Ŵ�1�Ͽ���ʾ
		sprintf(tip, "%d�ŷֻ��Ŵ�1�Ͽ�\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_DR1_CLOSE:              //�ֻ����Ŵ�1�պ���ʾ
		sprintf(tip, "%d�ŷֻ��Ŵ�1�պ�\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_DR2_OPEN:               //�ֻ����Ŵ�2�Ͽ���ʾ
		sprintf(tip, "%d�ŷֻ��Ŵ�2�Ͽ�\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_DR2_CLOSE:              //�ֻ����Ŵ�2�պ���ʾ
		sprintf(tip, "%d�ŷֻ��Ŵ�2�պ�\r\n", param1);
		break;

	case LB_UA2UI_AGENT_REQUEST:                  //�յ��й�����
		sprintf(tip, "%d�����������й�\r\n", param1);
		break;
	case LB_UA2UI_AGENT_REQ_CANCLE:               //�й�����ȡ�������յ�������δӦ��
		sprintf(tip, "%d������ȡ���й�����\r\n", param1);
		break;
	case LB_UA2UI_AGENT_QUIT:                     //�յ��˳��й�����
		sprintf(tip, "%d�������˳��й�\r\n", param1);
		break;
	case LB_UA2UI_BEAGENTED_REQ_ACCEPTED:         //���������������󣬶Է�ͬ�����
		sprintf(tip, "���������йܣ�%d������ͬ��\r\n", param1);
		break;
	case LB_UA2UI_BEAGENTED_REQ_REJECTED:         //���������������󣬶Է��ܾ�����
		sprintf(tip, "���������йܣ�%d�������ܾ�\r\n", param1);
		break;
	case LB_UA2UI_BEAGENTED_REQ_TIMEOUT:          //����������������û��Ӧ��û���ʹ��û��Ӧ��
		sprintf(tip, "���������йܣ�����Ӧ��ʱ\r\n");
		break;
	case LB_UA2UI_BEAGENTED_REQ_FAIL:             //�����������ʧ�ܣ�������û��Ԥ����ܻ���û�д��ܻ��ĵ�ַ
		sprintf(tip, "���������йܣ�ʧ��\r\n");
		break;
	case LB_UA2UI_BEAGENTED_QUIT:                 //�����˳�������״̬
		sprintf(tip, "�����˳��й�״̬\r\n");
		break;

	case LB_UA2UI_SYSTEM_BUSY:                   //��ǰæ��������Ч
		sprintf(tip, "����æ��������Ӧ��ǰ����\r\n");
		break;
	case LB_UA2UI_NETWORK_INIT_FAIL:             //�����ʼ��ʧ��
		sprintf(tip, "�����ʼ��ʧ��\r\n");
		break;
	case LB_UA2UI_NETWORK_DISCONNECTED:          //����Ͽ�
		sprintf(tip, "����Ͽ�\r\n");
		break;

	case LB_UA2UI_EXTN_IO_OPLK1_UNALLOW:         //��ǰ��������1
		if (lb_info_terminalIsMaster(param1)) sprintf(tip, "��ǰ�������%d�������ķֻ�����1\r\n", param1);
		else sprintf(tip, "��ǰ�������%d�ŷֻ�����1\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_OPLK1_SUCC:            //����1�ɹ�
		sprintf(tip, "��%d�ŷֻ�����1�ɹ�\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_OPLK1_DISABLE:    //��1û������
		sprintf(tip, "%d�ŷֻ��ĵ����1û������\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_OPLK2_UNALLOW:         //��ǰ��������2
		if (lb_info_terminalIsMaster(param1)) sprintf(tip, "��ǰ�������%d�������ķֻ�����2\r\n", param1);
		else sprintf(tip, "��ǰ�������%d�ŷֻ�����2\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_OPLK2_SUCC:            //����2�ɹ�
		sprintf(tip, "��%d�ŷֻ�����2�ɹ�\r\n", param1);
		break;
	case LB_UA2UI_EXTN_IO_OPLK2_DISABLE:         //��2û������
		sprintf(tip, "%d�ŷֻ��ĵ����2û������\r\n", param1);
		break;

	case LB_UA2UI_ADDRQUERY_FINISHED:            //�ѻ�ȡ�������ַ��Ϣ���������ˢ����ʾ�ĺ����б�
		sprintf(tip, "�����ķֻ��и��»��߹�����¼���������\r\n");
		//�����������ʾ���룬��Ҫˢ����ʾ
		break;
		//case LB_UA2UI_BEMANGED_RFSH_EXTNDSCRBINFO:   //һ������֪ͨ�ϼ��������й������������ķֻ���������Ϣ
		//	lb_info_extnDescriptInfo_decode(param1, (char*)param2, Clb_extension_demoDlg::extnDescriptInfo_update);
		//	sprintf(tip, "");
		//	break;
		//case LB_UA2UI_BEMANGED_EXTNCNT_CHANGED:      //���ܵ������ķֻ�����ˢ��
		//	sprintf(tip, "�¼�����%d��ֱ���ֻ����%d��\r\n", param1, lb_info_getMaxExtnCntBelongMst(param1));
		//	break;
		//case LB_UA2UI_BEMANGED_RFSH_EXTNVOCRGINFO:     //һ������֪ͨ�ϼ��������й������������ķֻ��ĺ���ʱ������������Ϣ
		//	lb_info_extnCallInVoiceRingInfo_decode(param1, (char*)param2, Clb_extension_demoDlg::extnCallInAdPyInfo_update);
		//	sprintf(tip, "");
		//	break;
	case LB_UA2UI_NO_AUDIOINPUTDEV:               //û����Ƶ�����豸
		sprintf(tip, "û����Ƶ�����豸��\r\n");
		break;
	case LB_UA2UI_NO_AUDIOOUTPUTDEV:              //û����Ƶ����豸
		sprintf(tip, "û����Ƶ����豸��\r\n");
		break;
	case LB_UA2UI_NO_NETCONNECTION:               //û���������ӣ���ʼ��lb_ipIntercom_start()��һֱ�ȴ�ֱ������������
		sprintf(tip, "û���������磬������û������������������·���ӱ����ã�\r\n");
		break;
	case LB_UA2UI_ADDRLOG_SUCCESS:                //�ڵ�ַ�еǼǱ�����ַ�ɹ����״��������߱�š���ַ���б仯�������ڵ�ַ���ϸ��µ�ַ��Ϣ��������������
		sprintf(tip, "�ڵ�ַ�еǼǱ�����ַ�ɹ���\r\n");
		break;

		//case LB_UA2UI_CALL_ATM_LSTN_SELTER:        //ATM���ߺ��Ѿ���ͨ����Ҫѡ��Ҫ�������ն˵��ն˺ţ�����Ϊ�ɹ�ѡ����ն˺��б�
		//{
		//	char *AtmTerNumList = (char *)param2;
		//	if (AtmTerNumList)
		//	{
		//		int terNum = 0, numList[30] = { 0 }, cnt = 0, i = 0;
		//		strInfoDecodeToIntList(AtmTerNumList, ',', numList, 30, &cnt);//���ַ�����������������
		//		if (cnt == 0)
		//		{
		//			lb_fun_hungup(param1);
		//			break;
		//		}
		//		sprintf(tip, "�����ѡ��%d��ATM���ߺе������ն˼�����%s\r\n��", param1, AtmTerNumList);
		//	}
		//}
		//break;
		//case LB_UA2UI_CALL_ATM_TALK_SELTER:        //ATM���ߺ��Ѿ���ͨ����Ҫѡ��Ҫ�Խ����ն˵��ն˺Ż���Ҫ�������ն˵��ն˺ţ�����Ϊ�ɹ�ѡ����ն˺��б�
		//{
		//	char *AtmTerNumList = (char *)param2;
		//	if (AtmTerNumList)
		//	{
		//		int terNum = 0, numList[30] = { 0 }, cnt = 0, i = 0;
		//		strInfoDecodeToIntList(AtmTerNumList, ',', numList, 30, &cnt);//���ַ�����������������
		//		if (cnt == 0)
		//		{
		//			lb_fun_hungup(param1);
		//			break;
		//		}
		//		sprintf(tip, "�����ѡ��%d��ATM���ߺе������ն˶Խ��������%s\r\n", param1, AtmTerNumList);
		//	}
		//}
		//break;
	//case LB_UA2UI_CALL_ATM_LSTN_CONNECT:              //����ATM�ն˽�ͨ
	//{
	//	int rmtProperty = *(int *)param2, extnNum = 0, atmTerNum = 0;

	//	//param1Ϊ���9λ��ŵ�������ǰ6λΪATM���ߺк��룬��3λΪ�ն˵ĺ���
	//	extnNum = param1 / 1000;   //ATM���ߺк��룬6λ������ͨ���ַֻ��ĺ���һ���Ĺ���
	//	atmTerNum = param1 % 1000; //ATM�ն˵ĺ���

	//	if (lb_info_isRmtSupportVideo(rmtProperty))
	//	{
	//		//�Է�֧������ͷ����Ҫ����Ƶ��ʾ�򡭡�
	//		//......
	//		pThis->m_video.ShowWindow(SW_SHOW);
	//		pThis->m_myVideo.ShowWindow(SW_SHOW);

	//		//��ʾ���ʼ����ɣ��򿪶Է�������ͷ
	//		if (!lb_info_isRmtVideoCtrEna(rmtProperty))
	//		{
	//			lb_fun_notifyRmtVideo_on();            //��ͨ�ʹ򿪶Է�������ͷ
	//		}
	//	}
	//	sprintf(tip, "����%d��ATM���ߺе�%d���ն˽�ͨ\r\n��һ�οո��תΪ�Խ�ģʽ\r\n", extnNum, atmTerNum);
	//}
	//break;
	case LB_UA2UI_CALL_ATM_TALK_CONNECT:              //�Խ�ATM�ն˽�ͨ
	{
		int rmtProperty = *(int *)param2, extnNum = 0, atmTerNum = 0;

		//param1Ϊ���9λ��ŵ�������ǰ6λΪATM���ߺк��룬��3λΪ�ն˵ĺ���
		extnNum = param1 / 1000;   //ATM���ߺк��룬6λ������ͨ���ַֻ��ĺ���һ���Ĺ���
		atmTerNum = param1 % 1000; //ATM�ն˵ĺ���

	//	if (lb_info_isRmtSupportVideo(rmtProperty))
	//	{
	//		//�Է�֧������ͷ����Ҫ����Ƶ��ʾ�򡭡�
	//		//......
	//		pThis->m_video.ShowWindow(SW_SHOW);
	//		pThis->m_myVideo.ShowWindow(SW_SHOW);

	//		//��ʾ���ʼ����ɣ��򿪶Է�������ͷ
	//		if (!lb_info_isRmtVideoCtrEna(rmtProperty))
	//		{
	//			lb_fun_notifyRmtVideo_on();            //��ͨ�ʹ򿪶Է�������ͷ
	//		}

	//		pThis->m_btn_myVd_on.EnableWindow(TRUE);
	//		pThis->m_btn_myVd_off.EnableWindow(FALSE);
	//	}
	//	sprintf(tip, "��%d��ATM���ߺе�%d���ն˶Խ���ͨ\r\n", extnNum, atmTerNum);
	//	if (!pThis->fullDuplexEna)
	//	{
	//		sprintf(&tip[strlen(tip)], "Ҫ�����밴ס�ո�����������ɿ��ո�����Է�����\r\n");
	//	}
	//}
	}
	break;
	case LB_UA2UI_CALL_ATM_DISCONNECT:                //��ATM�ն�ͨ���Ҷ�
	{
		int extnNum = 0, atmTerNum = 0;

		//param1Ϊ���9λ��ŵ�������ǰ6λΪATM���ߺк��룬��3λΪ�ն˵ĺ���
		extnNum = param1 / 1000;   //ATM���ߺк��룬6λ������ͨ���ַֻ��ĺ���һ���Ĺ���
		atmTerNum = param1 % 1000; //ATM�ն˵ĺ���

								   //��Ƶ�����Դ�ͷ�
		pThis->m_video.ShowWindow(SW_HIDE);
		pThis->m_myVideo.ShowWindow(SW_HIDE);

		//pThis->m_btn_myVd_on.EnableWindow(FALSE);
		//pThis->m_btn_myVd_off.EnableWindow(FALSE);

		sprintf(tip, "�Ҷ���%d��ATM���ߺе�%d���ն˵�ͨ��\r\n", extnNum, atmTerNum);
	}
	break;
	case LB_UA2UI_CALL_ATM_FAIL:                      //ѡ��ATM�ն�ʧ�ܣ���ִ��lb_fun_selectATMTer()����ͨ���ն˲��ɹ�
	{
		int extnNum = 0, atmTerNum = 0;

		//param1Ϊ���9λ��ŵ�������ǰ6λΪATM���ߺк��룬��3λΪ�ն˵ĺ���
		extnNum = param1 / 1000;   //ATM���ߺк��룬6λ������ͨ���ַֻ��ĺ���һ���Ĺ���
		atmTerNum = param1 % 1000; //ATM�ն˵ĺ���

		sprintf(tip, "ѡ��%d��ATM���ߺе�%d���ն�ͨ��ʧ��\r\n", extnNum, atmTerNum);
	}
	break;
	case LB_UA2UI_ONBUSYCALLINMST_NOTIFY:          //������ͨ�������У�����������ͼ���б����������Ǻ��������ģ������Ϣ��ʾ��Щ�������й�
		sprintf(tip, "%s���������й�����\r\n", (char *)param2);
		break;
	case LB_UA2UI_ONBUSYCALLINATMTER_NOTIFY:       //��������ĳһ��ATM���ߺе�һ���ն�ͨ�������У��ý��ߺе������ն˷�����У�������ͨ�����Ǻ����������ģ������Ϣ��ʾ��Щ�ն����ں���
		sprintf(tip, "%d��ATM���ߺе�%s���ն����ں���\r\n", param1, (char *)param2);
		break;

	case LB_UA2UI_CALL_PRISONER_ESCAPE:	  //��������
		sprintf(tip, "%d�ű��淸������\r\n", param1);
		break;
	case LB_UA2UI_CALL_PRISONER_OUTBREAK:  //���˱���
		sprintf(tip, "%d�ű��淸�˱���\r\n", param1);
		break;
	case LB_UA2UI_CALL_PRISONER_FIGHTS:	  //���˴��
		sprintf(tip, "%d�ű��淸�˴��\r\n", param1);
		break;
	case LB_UA2UI_CALL_INTRUSION_ATTACK:	  //����Ϯ��
		sprintf(tip, "%d�ű�������Ϯ��\r\n", param1);
		break;
	case LB_UA2UI_CALL_NATURAL_DISASTER:	  //��Ȼ�ֺ�
		sprintf(tip, "%d�ű�����Ȼ�ֺ�\r\n", param1);
		break;

	case LB_UA2UI_EXTN_ONLINE:                //�ֻ�����
											  //sprintf(tip,"%d�ŷֻ�����\r\n",param1);
		break;
	case LB_UA2UI_EXTN_OFFLINE:               //�ֻ�����
											  //sprintf(tip,"%d�ŷֻ�����\r\n",param1);
		break;
	case LB_UA2UI_OFFLINENTY_STOP:          //�ֻ����ߵ�������ʾ�Ѿ�ֹͣ
		sprintf(tip, "%d�ŷֻ����ߵ�������ʾ�Ѿ�ֹͣ\r\n", param1);
		break;
	case LB_UA2UI_AREAINFO_UPDATE:           //������Ϣ�и���
		sprintf(tip, "������Ϣ�и���\r\n");  //�༶����ϵͳ
		break;
	case LB_UA2UI_DTMFINPUT_ENA:             //��ʾDTMF�������
		sprintf(tip, "%d�������أ���Ҫ���β�������Ҫת�ӵĵ绰��������ֻ�����\r\n", param1);
		break;
	case LB_UA2UI_PLAY_FILE_STOP:            //ͨ���в岥�ļ����Ž���
		sprintf(tip, "�岥�ļ����Ž���\r\n");
		break;
	case LB_UA2UI_CALL_RMALARM:					 //���𱨾�
		sprintf(tip, "%d�ֻ��������\r\n", param1);
		break;
	case LB_UA2UI_EXTN_TALK_OTHER_START:      //�ֻ�������������ֻ���ʼͨ�����÷ֻ���ֱ��������߼������ڸ÷ֻ��������豸ͨ����ʼʱ���յ����¼�
		sprintf(tip, "%d�ŷֻ�ͨ����\r\n", param1);
		break;
	case LB_UA2UI_EXTN_TALK_OTHER_STOP:       //�ֻ�������������ֻ�����ͨ�����÷ֻ���ֱ��������߼������ڸ÷ֻ��������豸ͨ������ʱ���յ����¼�
		sprintf(tip, "%d�ŷֻ�ͨ������\r\n", param1);
		break;
	case LB_UA2UI_SIPCALL_PROCESSING:                //����������
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "����%s���ڴ����С���\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPCALL_RINGBACK:                  //��������
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "����%s����\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPCALL_CONNECT:                   //�Խ���ͨ
		pThis->m_video.ShowWindow(SW_SHOW);
		pThis->m_myVideo.ShowWindow(SW_SHOW);
		//pThis->m_btn_myVd_on.EnableWindow(TRUE);
		//pThis->m_btn_myVd_off.EnableWindow(FALSE);
		wsprintfW(buf, L"%d", param1);
		pThis->m_hungup_displayNum.SetWindowText((LPCWSTR)buf);
		sprintf(tip, "��%s�Խ���ͨ\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPCALL_DISCONNECT:                //ͨ������йҶ�
		sprintf(tip, "�Ҷ���%s��ͨ�������\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPCALL_BUSY:                      //�Է�æ
		sprintf(tip, "%s��ǰ��æ\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPCALL_FAIL:                      //����ʧ��
		sprintf(tip, "����%sʧ��\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPCALL_CALLIN:                    //��ͨ����
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
			sprintf(tip, "%s����%d�˻�\r\naccount��%s\r\nDisplay:%s\r\nserviceIp:%s\r\nport:%d\r\n", (char*)callAcc, accinfo.accId,
				accinfo.account, accinfo.Display, accinfo.serviceIp, accinfo.port);

		}
		break;

	case LB_UA2UI_SIPREGISTER_FAIL:                //SIPע��ʧ��
		sprintf(tip, "�˺�<%s>ע��ʧ��\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPREGISTER_SUCC:                //SIPע��ɹ�
		sprintf(tip, "�˺�<%s>ע��ɹ�\r\n", (char*)param2);
		break;
	case LB_UA2UI_SIPUNREGISTER_SUCC:              //SIPע���ɹ�
		sprintf(tip, "�˺�<%s>ע��\r\n", (char*)param2);
		break;

		//case LB_UA2UI_MLTK_SPK_PROCESSING:         //�෽ͨ���������յ�����ʾ�����㲥׼���С���1.5���Ӻ���ʾ���Ժ���
		//	sprintf(tip,"�෽ͨ��������\r\n");
		//	break;
		//case LB_UA2UI_MLTK_SPK_OK:           //�෽ͨ��,��ʾ���Ժ���
		//	sprintf(tip,"�෽ͨ���Ѿ����������Ժ���\r\n");
		//	break;
		//case LB_UA2UI_MLTK_SPK_STOP:         //�෽ͨ��ֹͣ
		//	sprintf(tip,"�෽ͨ���Ѿ�ֹͣ\r\n");
		//	break;
		//case LB_UA2UI_MLTK_FAIL:             //�෽ͨ��ʧ��
		//	sprintf(tip,"�෽ͨ������ʧ��\r\n");
		//	break;
		//case LB_UA2UI_MLTK_NOTALLOW:         //�෽ͨ���г�ͻ������������
		//	sprintf(tip,"�෽ͨ�������г�ͻ������������\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_APPLY_SPK:        //��������뷢��
		//	sprintf(tip,"%d�����뷢��\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_APPLY_SPK_CONNECT:      //���Կ�ʼ
		//	sprintf(tip,"%d�ſ�ʼ����\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_APPLY_SPK_DISCONNECT:   //���Խ���
		//	sprintf(tip,"%d�ŷ��Խ���\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_APPLY_SPK_FAIL:         //����ʧ�ܣ�SIP��ͨʧ��
		//	sprintf(tip,"%d�ŷ�������ʧ��\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_WAIT_SPK:               //��������뷢��,�����Ѿ���������������ڷ��ԣ�����ʧ��
		//	sprintf(tip,"%d�ŵȴ�����\r\n",param1);
		//	break;

		//case LB_UA2UI_MLTK_BE_CONFERENCE_START:      //�������ģʽ��ʼ���ͻ��ˣ�
		//	sprintf(tip,"����ģʽ�෽ͨ����������֯����%d��\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_BE_CONDUCT_START:         //����ָ��ģʽ��ʼ���ͻ��ˣ�
		//	sprintf(tip,"ָ��ģʽ�෽ͨ����������֯����%d��\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_BE_STOP:                  //�෽ͨ���������ͻ��ˣ�
		//	sprintf(tip,"�෽ͨ���������෽ͨ����֯����%d��\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_CLT_APYSPK:               //��������뷢�ԣ��ͻ��ˣ�
		//	sprintf(tip,"���������У��෽ͨ����֯����%d��\r\n");
		//	break;
		//case LB_UA2UI_MLTK_CLT_APYSPK_CONNECT:       //���Կ�ʼ���ͻ��ˣ�
		//	sprintf(tip,"���Կ�ʼ���෽ͨ����֯����%d��\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_CLT_APYSPK_DISCONNECT:    //���Խ������ͻ��ˣ�
		//	sprintf(tip,"���Խ������෽ͨ����֯����%d��\r\n",param1);
		//	break;
		//case LB_UA2UI_MLTK_CLT_APYSPK_FAIL:          //����ʧ�ܣ��ͻ��ˣ�
		//	sprintf(tip,"��������ʧ�ܣ��෽ͨ����֯����%d��\r\n",param1);
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
		sprintf(tip, "LonBon IP����Խ�������!\r\n");
		this->showLogInfo(tip); return;
	}
	if (0 == this->m_workDir.GetWindowTextLength())
	{
		cstr_WorkDir += _T("../bin");
		if (!CheckFolderExist(cstr_WorkDir))
		{
			this->showLogInfo("��ǰĿ¼����һ��Ŀ¼��û��bin�ļ��У�");
			return;
		}
		strcpy(workDir, "..");    //Ĭ�ϵĹ���·����Ϊ��ǰĿ¼�������㣬Ϊ���������㲥����ָ��Ŀ¼
	}
	else
	{
		this->m_workDir.GetWindowText(cstr_WorkDir);
		cstr_WorkDir += _T("/bin");
		if (!CheckFolderExist(cstr_WorkDir))
		{
			this->showLogInfo("��ǰָ��Ŀ¼��û��bin�ļ��У�");
			return;
		}
		this->getEditText(this->m_workDir.GetSafeHwnd(), workDir, sizeof(workDir));
		if (0 != lb_ipIntercom_workDirectory_set(workDir))
		{
			this->showLogInfo("ָ������Ŀ¼ʧ�ܣ�");
			return;
		}
	}


	this->m_udpPort.GetWindowText(cs_udpPort);
	udpPort = _ttoi(cs_udpPort);

	sprintf(tip, "LonBon IP����Խ���ʼ������\r\n");
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
		sprintf(tip, "LonBon IP����Խ�����ʧ��!!!\r\n");
		this->showLogInfo(tip);
		return;
	}
	else sprintf(tip, "LonBon IP����Խ������ɹ�!\r\n");
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString workPath = _T("");

	WCHAR szDir[MAX_PATH];
	BROWSEINFO bi;
	ITEMIDLIST *pidl;

	bi.hwndOwner = this->m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szDir;
	bi.lpszTitle = L"��ѡ��Ŀ¼";
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
		// TODO: �ڴ���ӿؼ�֪ͨ����������
		if (!this->isInitialOK)
		{
			this->showLogInfo("�����У����Ե�...\r\n");
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
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
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
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isValidIP(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_EXTNVOL:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
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
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
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
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		//case LBSETTING_KEY_HEADMST:
		//	if (this->runLevel_mode == LB_RUNLVL_SENIOR)
		//	{
		//		this->showLogInfo("�߼�����û�б�������\r\n");
		//		break;
		//	}
		//	this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
		//	if (0 == strlen(cBuf))
		//	{
		//		if (0 == lb_setting_set((lb_setting_key_e)selKey, NULL, 0))
		//		{
		//			this->showLogInfo("���óɹ���\r\n");
		//		}
		//		else this->showLogInfo("����ʧ�ܣ�\r\n");
		//		return;
		//	}
		//	else
		//	{
		//		int *mstNumList = NULL, cnt = 0;
		//		cnt = lb_strToIntList(cBuf, ',', &mstNumList);
		//		if (cnt > 5)
		//		{
		//			this->showLogInfo("�߼��������֧��5����\r\n");
		//		}
		//		else
		//		{
		//			int headMst[5] = { 0 };
		//			memcpy(headMst, mstNumList, cnt * sizeof(int));
		//			if (0 == lb_setting_set((lb_setting_key_e)selKey, headMst, 5 * sizeof(int)))
		//			{
		//				this->showLogInfo("���óɹ���\r\n");
		//			}
		//			else this->showLogInfo("����ʧ�ܣ�\r\n");
		//		}
		//		delete[] mstNumList;
		//		return;
		//	}
		//	break;
		//case LBSETTING_KEY_NOASWUPTRANS_TIME:
		//	if (this->runLevel_mode == LB_RUNLVL_SENIOR)
		//	{
		//		this->showLogInfo("�߼�����û�б�������\r\n");
		//		break;
		//	}
		//	this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
		//	if (0 == strlen(cBuf))
		//	{
		//		this->showLogInfo("û������ֵ��\r\n");
		//		break;
		//	}
		//	if (!isDigit(cBuf))
		//	{
		//		this->showLogInfo("�Ƿ����룡\r\n");
		//		break;
		//	}
		//	nVal = atoi(cBuf);
		//	pVal = &nVal;
		//	len = sizeof(int);
		//	break;
		//case LBSETTING_KEY_REPMST:
		//	if (this->runLevel_mode == LB_RUNLVL_SENIOR)
		//	{
		//		this->showLogInfo("�߼�����û�б�������\r\n");
		//		break;
		//	}
		//	this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
		//	if (0 == strlen(cBuf))
		//	{
		//		this->showLogInfo("û������ֵ��\r\n");
		//		break;
		//	}
		//	if (!isDigit(cBuf))
		//	{
		//		this->showLogInfo("�Ƿ����룡\r\n");
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
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
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
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_RECORD_UPLOAD_ENA:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_RECORD_UPLOAD_SERVERIP:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));

			if (0 < strlen(cBuf) && !isValidIP(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_EXTNCALLIN_ADPY_MODE:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <LBSET_VOICERING_GENERAL || nVal >LBSET_VOICERING_BUILDING_LIFT)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_CRCLISTENTIME:         //ѭ�����������ֻ���ʱ��
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_MYEXTNCALLOUT_MAXTIME:    //����ֱ���ֻ����У����˽��������е����ʱ������ʱ�Զ��Ҷϣ���Ϊ��0����һֱ���У������Զ��Ҷ�
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		//case LBSETTING_KEY_TRANS_EXTNINFO_ADTLMST:     //�����ϴ�������Ϣ�ͱ�����Ϣ�ĸ�����������ָ�����ϼ�����֮�����Ҫ����ֱ���ֻ���Ϣ��������������
		//	if (this->runLevel_mode == LB_RUNLVL_SENIOR)
		//	{
		//		this->showLogInfo("�߼�����û�б�������\r\n");
		//		break;
		//	}
		//	this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
		//	if (0 == strlen(cBuf))
		//	{
		//		if (0 == lb_setting_set((lb_setting_key_e)selKey, NULL, 0))
		//		{
		//			this->showLogInfo("���óɹ���\r\n");
		//		}
		//		else this->showLogInfo("����ʧ�ܣ�\r\n");
		//		return;
		//	}
		//	else
		//	{
		//		int *mstNumList = NULL, cnt = 0;
		//		cnt = lb_strToIntList(cBuf, ',', &mstNumList);
		//		if (0 == lb_setting_set((lb_setting_key_e)selKey, mstNumList, cnt * sizeof(int)))
		//		{
		//			this->showLogInfo("���óɹ���\r\n");
		//		}
		//		else this->showLogInfo("����ʧ�ܣ�\r\n");
		//		delete[] mstNumList;
		//		return;
		//	}
		//	break;
		//case LBSETTING_KEY_CALL_ADTLMST:     //���ú��еĸ�����������ָ�����ϼ�����֮�����������ֱ���ֻ���Ҫ���е�������������
		//	this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
		//	if (0 == strlen(cBuf))
		//	{
		//		if (0 == lb_setting_set((lb_setting_key_e)selKey, NULL, 0))
		//		{
		//			this->showLogInfo("���óɹ���\r\n");
		//		}
		//		else this->showLogInfo("����ʧ�ܣ�\r\n");
		//		return;
		//	}
		//	else
		//	{
		//		int *mstNumList = NULL, cnt = 0;
		//		cnt = lb_strToIntList(cBuf, ',', &mstNumList);
		//		if (0 == lb_setting_set((lb_setting_key_e)selKey, mstNumList, cnt * sizeof(int)))
		//		{
		//			this->showLogInfo("���óɹ���\r\n");
		//		}
		//		else this->showLogInfo("����ʧ�ܣ�\r\n");
		//		delete[] mstNumList;
		//		return;
		//	}
		//	break;
		case LBSETTING_KEY_CALL_ADTLMST_DLYTM:    //��Ⱥ���ֱ���������ֻ��ӳٶ�ú��и�����������Ϊ��0����ͬʱ����
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_TRIAGE_MSTNUM:
			this->showLogInfo("����ϵͳ����Ч\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
			this->showLogInfo("û������ֵ��\r\n");
			break;
			}
			if (!isDigit(cBuf))
			{
			this->showLogInfo("�Ƿ����룡\r\n");
			break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);*/
			break;
		case LBSETTING_KEY_TRIAGE_GROUPNUM:
			this->showLogInfo("����ϵͳ����Ч\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
			this->showLogInfo("û������ֵ��\r\n");
			break;
			}
			if (!isDigit(cBuf))
			{
			this->showLogInfo("�Ƿ����룡\r\n");
			break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);*/
			break;
		case LBSETTING_KEY_TRIAGE_DEVNUM:
			this->showLogInfo("����ϵͳ����Ч\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
			this->showLogInfo("û������ֵ��\r\n");
			break;
			}
			if (!isDigit(cBuf))
			{
			this->showLogInfo("�Ƿ����룡\r\n");
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
		//		this->showLogInfo("һ������û�б�������\r\n");
		//		break;
		//	}
		//	this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
		//	if (0 == strlen(cBuf))
		//	{
		//		this->showLogInfo("û������ֵ��\r\n");
		//		break;
		//	}
		//	if (!isDigit(cBuf))
		//	{
		//		this->showLogInfo("�Ƿ����룡\r\n");
		//		break;
		//	}
		//	nVal = atoi(cBuf);
		//	if (nVal != 0 && nVal != 1)
		//	{
		//		this->showLogInfo("�Ƿ����룡\r\n");
		//		break;
		//	}
		//	pVal = &nVal;
		//	len = sizeof(int);
		//	break;
		case LBSETTING_KEY_HIS_ENABLED:					// �Ƿ�����HISϵͳ����
			this->showLogInfo("ҽԺ�Խ�ϵͳ����Ч\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
			this->showLogInfo("û������ֵ��\r\n");
			break;
			}
			if (!isDigit(cBuf))
			{
			this->showLogInfo("�Ƿ����룡\r\n");
			break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
			this->showLogInfo("�Ƿ����룡\r\n");
			break;
			}
			pVal = &nVal;
			len = sizeof(int);*/
			break;
		case LBSETTING_KEY_HIS_SERVERIP:				// HIS������IP
			this->showLogInfo("ҽԺ�Խ�ϵͳ����Ч\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));

			if (0 < strlen(cBuf) && !isValidIP(cBuf))
			{
			this->showLogInfo("�Ƿ����룡\r\n");
			break;
			}
			pVal = cBuf;
			len = strlen(cBuf);*/
			break;
		case LBSETTING_KEY_HIS_ZONENUMBER:				// ������
			this->showLogInfo("ҽԺ�Խ�ϵͳ����Ч\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
			this->showLogInfo("û������ֵ��\r\n");
			break;
			}
			if (!isDigit(cBuf))
			{
			this->showLogInfo("�Ƿ����룡\r\n");
			break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);*/
			break;
		case LBSETTING_KEY_DOORLAMPCOLOR:				// �ŵ���ɫ��׼
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_DUTYDOCTOR_PATH:				// ����ҽ����Ƭ�洢·��
			this->showLogInfo("ҽԺ�Խ�ϵͳ����Ч\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);*/
			break;
		case LBSETTING_KEY_DUTYNURSE_PATH:				// ���λ�ʿ��Ƭ�洢·��
			this->showLogInfo("ҽԺ�Խ�ϵͳ����Ч\r\n");
			/*this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);*/
			break;
		case LBSETTING_KEY_CALLONBUSY_TRANS_ENA:         // ��æת�ƹ���ʹ��
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_CALLONBUSY_TRANS_MST:         // ��æת�Ƶı���������
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_CONSULTCALL_MST:              // ��ѯ���������ĺ���
			this->showLogInfo("������֧�ֱ������ã�\r\n");
			break;
		case LBSETTING_KEY_LANGUAGE:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_RING_ONCONN_ENA:              // ��ͨ���У����������Ƿ�������ʾ
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_EXTNOFFLN_VNTY_ENA:           // ֱ���ֻ����ߣ��Ƿ�������ʾ
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_MYEXTN_TKBELSN_ENA:           // ֱ���ֻ��뱾�����й�����ͨ�����Ƿ�����߼���������,����������
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_EXTERNALALARM_DESC1:          // ��ӱ����ź�1��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC2:          // ��ӱ����ź�2��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC3:          // ��ӱ����ź�3��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC4:          // ��ӱ����ź�4��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC5:          // ��ӱ����ź�5��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC6:          // ��ӱ����ź�6��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC7:          // ��ӱ����ź�7��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC8:          // ��ӱ����ź�8��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC9:          // ��ӱ����ź�9��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC10:         // ��ӱ����ź�10��������Ϣ
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_VIDEOCLARITY:                 // ��Ƶͼ��������ȣ�0�����壬1�����壬2������
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal < 0 || nVal > 2)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_MULTITALKVID_ENA:             //�෽ͨ��֧����Ƶ
		case LBSETTING_KEY_RINGINTERNAL_DIS:		    	// ��ֹ�ڲ����弰��������
		case LBSETTING_KEY_DR1OP_TIMEOUTALARM_ENA:		// �Ŵ�1��������ʱ����ʹ��
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal != 0 && nVal != 1)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_ALARMRINGMUSIC_NAME:			// ������������
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_DR1OP_TIMEOUTALARM_TM:		// �Ŵ�1��������ʱ������ʱʱ��
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <= 0)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_SIP_ENABLE:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <= 0)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case LBSETTING_KEY_SIP_SERVER_ADDRESS:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isValidIP(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_SIP_SERVER_PORT:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <= 0)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
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
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <= 0)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case  LBSETTING_KEY_SIP_SERVER_ADDRESS_2:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isValidIP(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_SIP_SERVER_PORT_2:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <= 0)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
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
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <= 0)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = &nVal;
			len = sizeof(int);
			break;
		case  LBSETTING_KEY_SIP_SERVER_ADDRESS_3:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isValidIP(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			pVal = cBuf;
			len = strlen(cBuf);
			break;
		case LBSETTING_KEY_SIP_SERVER_PORT_3:
			this->getEditText(this->m_setValue.GetSafeHwnd(), cBuf, sizeof(cBuf));
			if (0 == strlen(cBuf))
			{
				this->showLogInfo("û������ֵ��\r\n");
				break;
			}
			if (!isDigit(cBuf))
			{
				this->showLogInfo("�Ƿ����룡\r\n");
				break;
			}
			nVal = atoi(cBuf);
			if (nVal <= 0)
			{
				this->showLogInfo("�Ƿ����룡\r\n");
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
				this->showLogInfo("���óɹ���\r\n");
			}
			else this->showLogInfo("����ʧ�ܣ�\r\n");
		}
	}
}


void Clb_extension_demoDlg::OnBnClickedgetsetting()
{

	{
		// TODO: �ڴ���ӿؼ�֪ͨ����������
		if (!this->isInitialOK)
		{
			this->showLogInfo("�����У����Ե�...\r\n");
		}
		int selKey = this->m_getKey.GetCurSel();
		int nVal = 0, bufSize = 0, valSize = 0;
		char cBuf[256] = { 0 }, tip[256] = { 0 };
		switch (selKey)
		{
		case LBSETTING_KEY_DISPLAYNUM:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "������ţ�%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_ADDRMANAGESVR:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "��ַ�е�ַ��%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_EXTNVOL:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "ֱ���ֻ�������%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_LAN_CODEC:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "��Ե�ģʽ����뷽����%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_WAN_CODEC:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "������ģʽ����뷽����%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		//case LBSETTING_KEY_HEADMST:
		//	if (this->runLevel_mode == LB_RUNLVL_SENIOR)
		//	{
		//		this->showLogInfo("�߼�����û�б�������\r\n");
		//		break;
		//	}
		//	else
		//	{
		//		int headerNumList[5] = { 0 };
		//		if (0 == lb_setting_get((lb_setting_key_e)selKey, headerNumList, sizeof(headerNumList), &valSize))
		//		{
		//			int cnt = valSize / sizeof(int), i = 0;
		//			strcpy(tip, "�ϼ�������");
		//			for (i = 0; i < cnt; i++)
		//			{
		//				if (headerNumList[i]>0) sprintf(tip + strlen(tip), "  %d", headerNumList[i]);
		//			}
		//			strcat(tip, "\r\n");
		//			this->showLogInfo(tip);
		//		}
		//		else this->showLogInfo("��ȡʧ��\r\n");
		//	}
		//	break;
		//case LBSETTING_KEY_NOASWUPTRANS_TIME:
		//	if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
		//	{
		//		sprintf(tip, "�����ϴ�ʱ�䣺%d\r\n", nVal);
		//		this->showLogInfo(tip);
		//	}
		//	else this->showLogInfo("��ȡʧ��\r\n");
		//	break;
		//case LBSETTING_KEY_REPMST:
		//	if (this->runLevel_mode == LB_RUNLVL_SENIOR)
		//	{
		//		this->showLogInfo("�߼�����û�б�������\r\n");
		//		break;
		//	}
		//	if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
		//	{
		//		sprintf(tip, "�й�������%d\r\n", nVal);
		//		this->showLogInfo(tip);
		//	}
		//	else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_EXTN_NSALARM_LVL:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "�������������ȼ���%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_RECORD_PATH:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "¼��¼���ļ��洢·����%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_RECORD_ENA:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "¼��¼��ʹ�ܣ�%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_RECORD_UPLOAD_ENA:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "¼��¼���ļ��Զ��ϴ�ʹ�ܣ�%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_RECORD_UPLOAD_SERVERIP:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "¼��¼���ļ��Զ��ϴ��Ľ��շ�������ַ��%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_EXTNCALLIN_ADPY_MODE:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "�ֻ���������������ʽ��%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_CRCLISTENTIME:         //ѭ�����������ֻ���ʱ��
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "ѭ�����������ֻ���ʱ����%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_MYEXTNCALLOUT_MAXTIME:    //����ֱ���ֻ����У����˽��������е����ʱ������ʱ�Զ��Ҷϣ���Ϊ��0����һֱ���У������Զ��Ҷ�
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "ֱ���ֻ��������ʱ����%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_TRANS_EXTNINFO_ADTLMST:     //�����ϴ�������Ϣ�ͱ�����Ϣ�ĸ�����������ָ�����ϼ�����֮�����Ҫ����ֱ���ֻ���Ϣ��������������
		{
			int *numList = NULL, cnt = 0;
			lb_setting_get((lb_setting_key_e)selKey, NULL, 0, &valSize);
			cnt = valSize / sizeof(int);
			numList = new int[cnt];
			bufSize = valSize;
			if (0 == lb_setting_get((lb_setting_key_e)selKey, numList, bufSize, &valSize))
			{
				int cnt = valSize / sizeof(int), i = 0;
				strcpy(tip, "���ձ����ֻ���������Ϣ�ͱ�����Ϣ�ĸ���������");
				for (i = 0; i < cnt; i++)
				{
					if (numList[i]>0) sprintf(tip + strlen(tip), "  %d", numList[i]);
				}
				strcat(tip, "\r\n");
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
		}
		break;
		case LBSETTING_KEY_CALL_ADTLMST:     //���ú��еĸ�����������ָ�����ϼ�����֮�����������ֱ���ֻ���Ҫ���е�������������
		{
			int *numList = NULL, cnt = 0;
			lb_setting_get((lb_setting_key_e)selKey, NULL, 0, &valSize);
			cnt = valSize / sizeof(int);
			numList = new int[cnt];
			bufSize = valSize;
			if (0 == lb_setting_get((lb_setting_key_e)selKey, numList, bufSize, &valSize))
			{
				int cnt = valSize / sizeof(int), i = 0;
				strcpy(tip, "�����ֻ����еĸ���������");
				for (i = 0; i < cnt; i++)
				{
					if (numList[i]>0) sprintf(tip + strlen(tip), "  %d", numList[i]);
				}
				strcat(tip, "\r\n");
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
		}
		break;
		case LBSETTING_KEY_CALL_ADTLMST_DLYTM:    //��Ⱥ���ֱ���������ֻ��ӳٶ�ú��и�����������Ϊ��0����ͬʱ����
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "���и��������ӳ�ʱ����%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_TRIAGE_MSTNUM:
			this->showLogInfo("����ϵͳ����Ч\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
			sprintf(tip, "����������ţ�%d\r\n", nVal);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");*/
			break;
		case LBSETTING_KEY_TRIAGE_GROUPNUM:
			this->showLogInfo("����ϵͳ����Ч\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
			sprintf(tip, "������ţ�%d\r\n", nVal);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");*/
			break;
		case LBSETTING_KEY_TRIAGE_DEVNUM:
			this->showLogInfo("����ϵͳ����Ч\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
			sprintf(tip, "�����豸�ţ�%d\r\n", nVal);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");*/
			break;
		case LBSETTING_KEY_RINGMUSIC_NANME:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "���������ļ���%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		//case LBSETTING_KEY_FORBID_EXTNCALLIN:
		//	if (this->runLevel_mode == LB_RUNLVL_PRIMARY)
		//	{
		//		this->showLogInfo("һ������û�б�������\r\n");
		//		break;
		//	}
		//	if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
		//	{
		//		sprintf(tip, "��ֹ�ֻ����룺%d\r\n", nVal);
		//		this->showLogInfo(tip);
		//	}
		//	else this->showLogInfo("��ȡʧ��\r\n");
		//	break;
		case LBSETTING_KEY_HIS_ENABLED:					// �Ƿ�����HISϵͳ����
			this->showLogInfo("ҽԺ�Խ�ϵͳ����Ч\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
			sprintf(tip, "����HISʹ�ܣ�%d\r\n", nVal);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");*/
			break;
		case LBSETTING_KEY_HIS_SERVERIP:				// HIS������IP
			this->showLogInfo("ҽԺ�Խ�ϵͳ����Ч\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
			sprintf(tip, "HIS��������ַ��%s\r\n", cBuf);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");*/
			break;
		case LBSETTING_KEY_HIS_ZONENUMBER:				// ������
			this->showLogInfo("ҽԺ�Խ�ϵͳ����Ч\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
			sprintf(tip, "�����ţ�%d\r\n", nVal);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");*/
			break;
		case LBSETTING_KEY_DOORLAMPCOLOR:				// �ŵ���ɫ��׼
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "�ŵ���ɫ��׼��%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_DUTYDOCTOR_PATH:				// ����ҽ����Ƭ�洢·��
			this->showLogInfo("ҽԺ�Խ�ϵͳ����Ч\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
			sprintf(tip, "����ҽ����Ƭ�洢·����%s\r\n", cBuf);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");*/
			break;
		case LBSETTING_KEY_DUTYNURSE_PATH:				// ���λ�ʿ��Ƭ�洢·��
			this->showLogInfo("ҽԺ�Խ�ϵͳ����Ч\r\n");
			/*if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
			sprintf(tip, "���λ�ʿ��Ƭ�洢·����%s\r\n", cBuf);
			this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");*/
			break;
		case LBSETTING_KEY_CALLONBUSY_TRANS_ENA:         // ��æת�ƹ���ʹ��
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "��æת��ʹ�ܣ�%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_CALLONBUSY_TRANS_MST:         // ��æת�Ƶı���������
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "��æת�Ƶı��������ţ�%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_CONSULTCALL_MST:              // ��ѯ���������ĺ���
			this->showLogInfo("������֧�ֱ������ã�\r\n");
			break;
		case LBSETTING_KEY_LANGUAGE:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "���ԣ�%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_RING_ONCONN_ENA:              // ��ͨ���У����������Ƿ�������ʾ
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "ͨ�������������Ƿ�������ʾ��%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_EXTNOFFLN_VNTY_ENA:           // ֱ���ֻ����ߣ��Ƿ�������ʾ
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "ֱ���ֻ������Ƿ�������ʾ��%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_MYEXTN_TKBELSN_ENA:           // ֱ���ֻ��뱾�����й�����ͨ�����Ƿ�����߼���������,����������
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "����������ʹ�ܣ�%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_EXTERNALALARM_DESC1:          // ��ӱ����ź�1��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC2:          // ��ӱ����ź�2��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC3:          // ��ӱ����ź�3��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC4:          // ��ӱ����ź�4��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC5:          // ��ӱ����ź�5��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC6:          // ��ӱ����ź�6��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC7:          // ��ӱ����ź�7��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC8:          // ��ӱ����ź�8��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC9:          // ��ӱ����ź�9��������Ϣ
		case LBSETTING_KEY_EXTERNALALARM_DESC10:         // ��ӱ����ź�10��������Ϣ
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "��ӱ���%d������%s\r\n", selKey - LBSETTING_KEY_EXTERNALALARM_DESC1 + 1, cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_VIDEOCLARITY:                 // ��Ƶͼ��������ȣ�0�����壬1�����壬2������
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "��Ƶͼ��������ȣ�%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_MULTITALKVID_ENA:             //�෽ͨ��֧����Ƶ
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "�෽ͨ��֧����Ƶʹ�ܣ�%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_ALARMRINGMUSIC_NAME:			// ������������
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "�����������������ļ���%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_RINGINTERNAL_DIS:		    	// ��ֹ�ڲ����弰��������
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "��ֹ�ڲ����弰��������ʹ�ܣ�%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_DR1OP_TIMEOUTALARM_ENA:		// �Ŵ�1��������ʱ����ʹ��
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "�Ŵ�1������ʱ����ʹ�ܣ�%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_DR1OP_TIMEOUTALARM_TM:		// �Ŵ�1��������ʱ������ʱʱ��
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "�Ŵ�1������ʱ������ʱʱ����%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_ENABLE:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "���ñ�׼SIPʹ�ܣ�%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_SERVER_ADDRESS:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP��������ַ��%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_SERVER_PORT:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP�������˿ڣ�%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_USERNAME:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP�˺��û�����%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_PASSWORD:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP�˺����룺%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_ENABLE_2:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "���ñ�׼SIP2ʹ�ܣ�%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_SERVER_ADDRESS_2:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP��������ַ2��%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_SERVER_PORT_2:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP�������˿�2��%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_USERNAME_2:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP�˺��û���2��%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_PASSWORD_2:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP�˺�����2��%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_ENABLE_3:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, &nVal, sizeof(int), &valSize))
			{
				sprintf(tip, "���ñ�׼SIP3ʹ�ܣ�%d\r\n", nVal);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_SERVER_ADDRESS_3:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP��������ַ3��%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_SERVER_PORT_3:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP�������˿�3��%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_USERNAME_3:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP�˺��û���3��%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		case LBSETTING_KEY_SIP_PASSWORD_3:
			if (0 == lb_setting_get((lb_setting_key_e)selKey, cBuf, sizeof(cBuf), &valSize))
			{
				sprintf(tip, "SIP�˺�����3��%s\r\n", cBuf);
				this->showLogInfo(tip);
			}
			else this->showLogInfo("��ȡʧ��\r\n");
			break;
		default:
			break;
		}
	}
}
