/**************************************************************************\
*
* Copyright (c)  �Ųʽ����. All Rights Reserved.
*
* �Ųʽ���� - �ٷ���վ : http://www.xcgui.com
*
\**************************************************************************/

//v1.5.3

#include <docobj.h> //��DLL�ļ�ʹ�ø�ͷ�ļ�ʱ,��ȡ��ע��
#include <exdispid.h>

#ifndef XCGUI_HEADER_FILE_
#define XCGUI_HEADER_FILE_

// �û��Զ�����Ϣ��Χ     WM_USER -  0x7000
// �Ų��ڲ��Զ�����Ϣ��Χ 0x7001  -  0x7FFF


#define XC_API

//�ӿ�����

/// @defgroup groupObjectType �ӿھ������
/// @ingroup macroDefine
/// @{
//����:
#define  XC_WINDOW         1   ///<����
#define  XC_MODALWINDOW    2   ///<ģ̬����
#define  XC_FRAMEWND       3   ///<��ܴ���
#define  XC_FLOATWND       4   ///<��������

//Ԫ�� :
#define  XC_ELE            20  ///<Ԫ��
#define  XC_BUTTON         21  ///<��ť
#define  XC_RADIO          22  ///<��ѡ��ť
#define  XC_CHECK          23  ///<��ѡ��ťԪ��
#define  XC_EDIT           24  ///<�༭��Ԫ��
#define  XC_RICHEDIT       25  ///<���ı��༭��
#define  XC_COMBOBOX       26  ///<������Ͽ�Ԫ��
#define  XC_SCROLLBAR      27  ///<������Ԫ��
#define  XC_SCROLLVIEW     28  ///<������ͼԪ��
#define  XC_LIST           29  ///<�б�Ԫ��
#define  XC_LISTBOX        30  ///<�б��Ԫ��
#define  XC_TREE           31  ///<��Ԫ��
#define  XC_MENUBAR        32  ///<�˵���
#define  XC_PROPERTYPAGE   33  ///<����ҳ
#define  XC_SLIDERBAR      34  ///<������
#define  XC_PROGRESSBAR    35  ///<������
#define  XC_TOOLBAR        36  ///<������
#define  XC_STATIC         37  ///<��̬�ı�Ԫ��
#define  XC_GROUPBOX       38  ///<���
#define  XC_PICTURE        39  ///<ͼƬԪ��
#define  XC_MONTHCAL       40  ///<����Ԫ��
#define  XC_DATETIME       41  ///<ʱ��Ԫ��
#define  XC_PROPERTYGRID   42  ///<��������
#define  XC_CHOOSECOLOR    43  ///<��ɫѡ��Ԫ��
#define  XC_OUTLOOK        44  ///<��������
#define  XC_TEXTLINK       45  ///<�����ı�
#define  XC_TABBAR         46  ///<TabBar
#define  XC_GIF            47  ///<GIF����
#define  XC_EDITFILE       48  ///<�ļ�ѡ��༭��
#define  XC_LISTVIEW       49  ///<�б���ͼ,��ͼ��
#define  XC_PANE           50  ///<���ִ���
#define  XC_DRAGBAR        51  ///<���ִ����϶��ָ���

#define  XC_SCROLLVIEW_VIEW     52  ///<������ͼԪ�ص���


#define  XC_MENUBAR_BUTTON        60  ///<�˵����ϵİ�ť
#define  XC_TOOLBAR_BUTTON        61  ///<�������ϰ�ť
#define  XC_PROPERTYPAGE_LABEL    62  ///<����ҳ��ǩ��ť


#define  XC_ARRAY          70  ///<�������
#define  XC_STRING         71  ///<�ַ�������
#define  XC_IMAGELIST      72  ///<ͼƬ�б�
#define  XC_MENU           73  ///<�����˵�
#define  XC_IMAGE          74  ///<ͼƬ����
#define  XC_HDRAW          75  ///<��ͼ����
#define  XC_FONT           76  ///<�Ų�����

#define  XC_PIER           102  ///<����ͣ����ͷ
#define  XC_PANE_CELL      103  

///@}



//���ⰴť:
#define XC_BUTTON_MIN     201  //��С�����ڰ�ť
#define XC_BUTTON_MAX     202  //��󻯴��ڰ�ť
#define XC_BUTTON_CLOSE   203  //�رմ��ڰ�ť

//#define XC_BUTTON_HSCROLLBAR_SLIDER   104  //ˮƽ������,���鰴ť
//#define XC_BUTTON_VSCROLLBAR_SLIDER   105  //��ֱ������,���鰴ť
//#define XC_BUTTON_HSCROLLBAR_LEFT     106  //ˮƽ������,�������ť
//#define XC_BUTTON_HSCROLLBAR_RIGHT    107  //ˮƽ������,�ҹ�����ť
//#define XC_BUTTON_VSCROLLBAR_TOP      108  //��ֱ������,�Ϲ�����ť
//#define XC_BUTTON_VSCROLLBAR_BOTTOM   109  //��ֱ������,�¹�����ť
#define XC_BUTTON_SLIDERBAR_SLIDER    210  //������,���鰴ť
//#define XC_BUTTON_COMBOBOX_POP        111  //��Ͽ������б�����ť
//#define XC_BUTTON_PROPERTYPAGE_LEFT   112  //����ҳ,�������ť
//#define XC_BUTTON_PROPERTYPAGE_RIGHT  113  //����ҳ,�ҹ�����ť
//#define XC_BUTTON_PROPERTYPAGE_LABEL  114  //����ҳ,��ǩ��ť
//#define XC_BUTTON_DATETIME_POP        115  //����ʱ��Ԫ��,����ѡ��Ƭ��ť



///�������///////////////////
#define in_
#define out_
#define in_out_


#ifdef _DEBUG
#define DECLARE_HANDLEX(name) struct name##__ { int unused; }; typedef struct name##__ *name
#else
#define	DECLARE_HANDLEX(name) typedef void* name
#endif


//�ӿھ������

/// @defgroup groupHandle ����б�
/// @ingroup macroDefine
/// @{
typedef void*  HXCGUI;    ///<��Դ���
DECLARE_HANDLEX(HWINDOW); ///<������Դ���
DECLARE_HANDLEX(HELE);    ///<Ԫ����Դ���
DECLARE_HANDLEX(HMENUX);  ///<�˵���Դ���
DECLARE_HANDLEX(HSTRING); ///<�ַ�����Դ���
DECLARE_HANDLEX(HDRAW);   ///<ͼ�λ�����Դ���
DECLARE_HANDLEX(HARRAY);  ///<������Դ���
DECLARE_HANDLEX(HIMAGE);  ///<ͼƬ��Դ���
DECLARE_HANDLEX(HXMLRES); ///<XML��Դ���
DECLARE_HANDLEX(HARRAY_ITERATOR); ///<���������
DECLARE_HANDLEX(HFONTX);    ///<�Ų�������

DECLARE_HANDLEX(HPANE_GROUP); ///<��������
///@}


/// @defgroup groupImageDrawType ͼƬ��������
/// @ingroup macroDefine
/// @{
#define XC_IMAGE_DEFAULT  0  ///<Ĭ��
#define XC_IMAGE_STRETCH  1  ///<����
#define XC_IMAGE_ADAPTIVE 2  ///<����Ӧ
#define XC_IMAGE_TILE     3  ///<ƽ��

///@}

//״̬--------------------------------------
/// @defgroup groupButtonState ��ť״̬
/// @ingroup macroDefine
/// @{
#define  STATE_LEAVE   0   ///<�뿪
#define  STATE_DOWN    1   ///<����
#define  STATE_STAY    2   ///<ͣ��
#define  STATE_SELECT  3   ///<ѡ��,����

///@}


//������ʽ----------------------------

/// @defgroup groupWindowStyle �Ųʴ�����ʽ
/// @ingroup macroDefine
/// @{
#define  XC_SY_MINIMIZE   0x00000001  ///<��С�����ڰ�ť
#define  XC_SY_MAXIMIZE   0x00000002  ///<��󻯴��ڰ�ť
#define  XC_SY_CLOSE      0x00000004  ///<�رմ��ڰ�ť
#define  XC_SY_CAPTION    0x00000008  ///<������
#define  XC_SY_BORDER     0x00000010  ///<�߿�
#define  XC_SY_ROUND      0x00000020  ///<Բ�Ǵ���
#define  XC_SY_CENTER     0x00000040  ///<���ھ���

#define  XC_SY_DRAG_BORDER 0x00000080  ///<�϶����ڱ߿�
#define  XC_SY_DRAG_WINDOW 0x00000100  ///<�϶�����
#define  XC_SY_DRAW_CAPTION_ICON  0x00000200 ///<���ƴ��ڱ�����ͼ��
#define  XC_SY_DRAW_CAPTION_TITLE 0x00000400 ///<���ƴ��ڱ������ı�

///����Ĭ����ʽ 1791
#define  XC_SY_DEFAULT (XC_SY_MINIMIZE | \
	XC_SY_MAXIMIZE | \
	XC_SY_CLOSE | \
	XC_SY_CAPTION | \
	XC_SY_BORDER | \
	XC_SY_ROUND | \
	XC_SY_CENTER | \
	XC_SY_DRAG_BORDER | \
	XC_SY_DRAW_CAPTION_ICON | \
	XC_SY_DRAW_CAPTION_TITLE)

///ģ̬����
#define  XC_SY_MODAL_WINDOW (XC_SY_CLOSE | \
	XC_SY_CAPTION | \
	XC_SY_BORDER | \
	XC_SY_ROUND | \
	XC_SY_DRAW_CAPTION_ICON | \
	XC_SY_DRAW_CAPTION_TITLE)

///@}

//͸������
/// @defgroup groupWindowTransparent �Ųʴ���͸����ʶ
/// @ingroup macroDefine
/// @{
#define XC_WIND_TRANSPARENT_NO       0 ///<Ĭ�ϴ���,��͸��
#define XC_WIND_TRANSPARENT_SHAPED   1 ///<͸������,��͸��ͨ��,����.
#define XC_WIND_TRANSPARENT_SHADOW   2 ///<��Ӱ����,��͸��ͨ��,�߿���Ӱ,����͸�����͸��.
#define XC_WIND_TRANSPARENT_SIMPLE   4 ///<͸������,����͸��ͨ��,ָ����͸����,ָ��͸��ɫ.
#define XC_WIND_TRANSPARENT_WIN7     8 ///<WIN7��������,��ҪWIN7������Ч,��ǰδ����.

///@}

//������Ϣ������
/// @defgroup groupMessageBox ������Ϣ��
/// @ingroup macroDefine
/// @{
#define  XMB_OK       1  ///<ȷ����ť
#define  XMB_CANCEL   2  ///<ȡ����ť

///@}

//����Ԫ��------------------------------------------------
/// @defgroup groupAddElement ���Ԫ��
/// @ingroup macroDefine
/// @{
#define  XC_ADDELE_END      0    ///<���ӵ�ĩβ
#define  XC_ADDELE_FRIST    1    ///<���ӵ���һλ��
#define  XC_ADDELE_BEFORE   2    ///<���ӵ�ָ��Ԫ��ǰ��
#define  XC_ADDELE_AFTER    3    ///<���ӵ�ָ��Ԫ�غ���
#define  XC_ADDELE_INDEX    4    ///<���ӵ�ָ��λ������

///@}

//����Ԫ��Z��-----------------------
/// @defgroup groupSetZOrder Ԫ��Z��
/// @ingroup macroDefine
/// @{
#define XC_ZORDER_TOP     0  ///<������
#define XC_ZORDER_BOTTOM  1  ///<������
#define XC_ZORDER_BEFORE  2  ///<ָ��Ԫ����Ŀ��Ԫ������
#define XC_ZORDER_AFTER   3  ///<ָ��Ԫ����Ŀ��Ԫ������
#define XC_ZORDER_INDEX   4  ///<ָ������λ��

///@}

//��ťͼ����뷽ʽ
/// @defgroup groupIconAlign ��ťͼ����뷽ʽ
/// @ingroup macroDefine
/// @{
#define XC_ICON_ALIGN_LEFT     0  ///<ͼ�������
#define XC_ICON_ALIGN_TOP      1  ///<ͼ���ڶ���
#define XC_ICON_ALIGN_RIGHT    2  ///<ͼ�����ұ�
#define XC_ICON_ALIGN_BOTTOM   3  ///<ͼ���ڵײ�

///@}

//������
/// @defgroup groupScrollBar ������
/// @ingroup macroDefine
/// @{
#define  SY_HSCROLL     TRUE   ///<ˮƽ������
#define  SY_VSCROLL     FALSE  ///<��ֱ������

///@}

//��Ԫ��
/// @defgroup groupTree �б���Ԫ��
/// @ingroup macroDefine
/// @{
#define  XTREE_INSERT_BEGIN  -2  ///<���뵱ǰ�㿪ʼ
#define  XTREE_INSERT_LAST   -1  ///<���뵱ǰ��ĩβ

#define  XTREE_ROOT  0       ///<���ڵ�

///@}

//���ڶ������Ķ�������ڵ�ID
#define  XMTREE_ROOT   -1            //���ڵ�ID
//�����˵����ڵ�ID
#define  XMENU_ROOT    XMTREE_ROOT   //���ڵ�ID

/// @defgroup groupMenu �����˵�
/// @ingroup macroDefine
/// @{

//�����˵����ʶ
///@name �����˵����ʶ
///@{
#define  XM_SELECT      1   ///<ѡ��
#define  XM_DISABLED    2   ///<����
#define  XM_CHECK       4   ///<��ѡ
#define  XM_POPUP       8   ///<����
#define  XM_SEPARATOR   16  ///<�ָ��� ID������,ID�ű�����

///@}

//�����˵�����
///@name �����˵�����
///@{
#define  XM_LEFT_TOP       0   ///<���Ͻ�
#define  XM_LEFT_BOTTOM    1   ///<���½�
#define  XM_RIGHT_TOP      2   ///<���Ͻ�
#define  XM_RIGHT_BOTTOM   3   ///<���½�
#define  XM_CENTER_LEFT    4   ///<�����
#define  XM_CENTER_TOP     5   ///<�Ͼ���
#define  XM_CENTER_RIGHT   6   ///<�Ҿ���
#define  XM_CENTER_BOTTOM  7   ///<�¾���

///@}

//�˵�ID--------------------------------------
///@name �˵�ID
///@{
#define  IDM_CLIP          1000000000    ///<����
#define  IDM_COPY          1000000001    ///<����
#define  IDM_PASTE         1000000002    ///<ճ��
#define  IDM_DELETE        1000000003    ///<ɾ��
#define  IDM_SELECTALL     1000000004    ///<ȫѡ
#define  IDM_DELETEALL     1000000005    ///<���

///@}

//����˵�
///@name ����˵�
///@{
#define  IDM_LOCK          1000000006    ///<����
#define  IDM_DOCK          1000000007    ///<ͣ��
#define  IDM_FLOAT         1000000008    ///<����
#define  IDM_HIDE          1000000009    ///<����

///@}


///@}

//��������Ԫ��,������
/// @defgroup groupPropertyGrid ��������Ԫ��
/// @ingroup macroDefine
/// @{

///@name ������
///@{
#define  PGRID_STRING       0  ///<Ĭ��,�ַ�������
#define  PGRID_EDIT         1  ///<�༭��
#define  PGRID_COMBOBOX     2  ///<��Ͽ�
#define  PGRID_CHOOSECOLOR  3  ///<��ɫѡ��Ԫ��
#define  PGRID_EDIT_FILE    4  ///<�ļ�ѡ��༭��
///@}

///@}

enum align_type_
{
	align_any=1,
	align_left,
	align_top,
	align_right,
	align_bottom,
	align_group_member, //���Ա
};

//����״̬
enum pane_state_
{
	pane_state_any=0,
	pane_state_lock,
	pane_state_dock,
	pane_state_float,
	pane_state_hide,
};

//������Ϣ
/**
@addtogroup wndMSG

<hr>
<h2>Windows ��׼��Ϣ</h2>
- @ref WM_PAINT ���ڻ�����Ϣ
- @ref WM_CLOSE ���ڹر���Ϣ.
- @ref WM_DESTROY ����������Ϣ.
- @ref WM_NCDESTROY ���ڷǿͻ���������Ϣ.
- @ref WM_MOUSEMOVE ��������ƶ���Ϣ.
- @ref WM_LBUTTONDOWN ����������������Ϣ
- @ref WM_LBUTTONUP ����������������Ϣ.
- @ref WM_RBUTTONDOWN ��������Ҽ�������Ϣ.
- @ref WM_RBUTTONUP ��������Ҽ�������Ϣ.
- @ref WM_MOUSEWHEEL ���������ֹ�����Ϣ.
- @ref WM_EXITSIZEMOVE �����˳��ƶ��������Сģʽѭ���ģ�����μ�MSDN.
- @ref WM_MOUSELEAVE ��������뿪��Ϣ.
- @ref WM_SIZE ���ڴ�С�ı���Ϣ.
- @ref WM_TIMER ���ڶ�ʱ����Ϣ.
- @ref WM_SETFOCUS ���ڻ�ý���.
- @ref WM_KILLFOCUS ����ʧȥ����.
- @ref WM_KEYDOWN ���ڼ��̰�����Ϣ.
- @ref WM_CAPTURECHANGED ������겶��ı���Ϣ.
- @ref other ����Windowsϵͳ��Ϣ,�������Զ����Windows��Ϣ.

<hr>
@anchor WM_PAINT WM_PAINT ���ڻ�����Ϣ
@code   BOOL CALLBACK WndDrawWindow(HWINDOW hWindow,HDRAW hDraw); @endcode
@param  hWindow ���ھ��.
@param  hDraw   ͼ�λ��ƾ��.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_CLOSE WM_CLOSE ���ڹر���Ϣ.
@code   BOOL CALLBACK WndClose(HWINDOW hWindow); @endcode
@param  hWindow ���ھ��.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_DESTROY WM_DESTROY ����������Ϣ.
@code   BOOL CALLBACK WndDestroy(HWINDOW hWindow);  @endcode
@param  hWindow ���ھ��.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_NCDESTROY WM_NCDESTROY ���ڷǿͻ���������Ϣ.
@code   BOOL CALLBACK WndNCDestroy(HWINDOW hWindow); @endcode
@param  hWindow ���ھ��.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_MOUSEMOVE WM_MOUSEMOVE ��������ƶ���Ϣ.
@code   BOOL CALLBACK WndMouseMove(HWINDOW hWindow,UINT flags,POINT *pPt);  @endcode
@param  hWindow ���ھ��.
@param  flags   ��μ�MSDN WM_MOUSEMOVE wParam����.
@param  pPt     ��������.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_LBUTTONDOWN WM_LBUTTONDOWN ����������������Ϣ
@code   BOOL CALLBACK WndLButtonDown(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
@param  hWindow ���ھ��.
@param  flags   ��μ�MSDN WM_LBUTTONDOWN.
@param  pPt     ��������.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_LBUTTONUP WM_LBUTTONUP ����������������Ϣ.
@code   BOOL CALLBACK WndLButtonUp(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
@param  hWindow ���ھ��.
@param  flags   ��μ�MSDN WM_LBUTTONUP.
@param  pPt     ��������.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_RBUTTONDOWN WM_RBUTTONDOWN ��������Ҽ�������Ϣ.
@code   BOOL CALLBACK WndRButtonDown(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
@param  hWindow ���ھ��.
@param  flags   ��μ�MSDN WM_RBUTTONDOWN.
@param  pPt     ��������.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_RBUTTONUP WM_RBUTTONUP ��������Ҽ�������Ϣ.
@code   BOOL CALLBACK WndRButtonUp(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
@param  hWindow ���ھ��.
@param  flags   ��μ�MSDN WM_RBUTTONUP.
@param  pPt     ��������.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_MOUSEWHEEL WM_MOUSEWHEEL ���������ֹ�����Ϣ.
@code   BOOL CALLBACK WndMouseWheel(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
@param  hWindow ���ھ��.
@param  flags   ��μ�MSDN WM_MOUSEWHEEL��ϢwParam����.
@param  pPt     ��������.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_EXITSIZEMOVE WM_EXITSIZEMOVE �����˳��ƶ��������Сģʽѭ���ģ�����μ�MSDN.
@code   BOOL CALLBACK WndExitSizeMove(HWINDOW hWindow); @endcode
@param  hWindow ���ھ��.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_MOUSELEAVE WM_MOUSELEAVE ��������뿪��Ϣ.
@code   BOOL CALLBACK WndMouseLeave(HWINDOW hWindow); @endcode
@param  hWindow ���ھ��.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_SIZE WM_SIZE ���ڴ�С�ı���Ϣ.
@code   BOOL CALLBACK WndSize(HWINDOW hWindow,UINT flags,SIZE *pSize); @endcode
@param  hWindow ���ھ��.
@param  flags   ��μ�MSDN WM_SIZE��ϢwParam����.
@param  pSize   ���ڴ�С.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_TIMER WM_TIMER ���ڶ�ʱ����Ϣ.
@code   BOOL CALLBACK WndTimer(HWINDOW hWindow,UINT_PTR nIDEvent,UINT uElapse); @endcode
@param  hWindow  ���ھ��.
@param  nIDEnent ��ʱ����ʾ��.
@param  uElapse  ָ����������ϵͳ���������ĺ�����,������GetTickCount�����ķ���ֵ.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_SETFOCUS WM_SETFOCUS ���ڻ�ý���.
@code   BOOL CALLBACK WndSetFocus(HWINDOW hWindow); @endcode
@param  hWindow ���ھ��.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_KILLFOCUS WM_KILLFOCUS ����ʧȥ����.
@code   BOOL CALLBACK WndKillFocus(HWINDOW hWindow); @endcode
@param  hWindow ���ھ��.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor WM_KEYDOWN WM_KEYDOWN ���ڼ��̰�����Ϣ.
@code   BOOL CALLBACK WndKeyDown(HWINDOW hWindow,WPARAM wParam,LPARAM lParam); @endcode
@param  hWindow ���ھ��.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
@note   wParam,lParam:��μ�MSDN WM_KEYDOWN.

<hr>
@anchor WM_CAPTURECHANGED WM_CAPTURECHANGED ������겶��ı���Ϣ.
@code   BOOL CALLBACK WndCaptureChanged(HWINDOW hWindow,HWND hWnd); @endcode
@param  hWindow ���ھ��.
@param  hWnd    �����겶��Ĵ��ھ��.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.

<hr>
@anchor other ����Windowsϵͳ��Ϣ,�������Զ����Windows��Ϣ.
@code   BOOL CALLBACK WndOther(HWINDOW hWindow,WPARAM wParam,LPARAM lParam); @endcode
@param  hWindow ���ھ��.
@param  wParam  ��Ϣ����.
@param  lParam  ��Ϣ����.
@return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
@note   ������Ϣ��μ�MSDN.
@{
*/

///@brief ��굥������
///@code  BOOL CALLBACK WndMouseClick(HWINDOW hWindow,POINT *pPt); @endcode
#define  XWM_MOUSECLICK       0x7000+1 //wParam:x����, lParam:y����

///@brief ���˫������
///@code  BOOL CALLBACK WndMouseDBClick(HWINDOW hWindow,POINT *pPt) @endcode
///@param hWindow ���ھ��
///@param pPt     ���λ��
#define  XWM_MOUSEDBCLICK     0x7000+2 //wParam:x����, lParam:y����

///@brief �ػ�Ԫ��
///@code BOOL CALLBACK WndRedrawEle(HWINDOW hWindow,HELE hEle,RECT *pRect);  @endcode
#define  XWM_REDRAW_ELE       0x7000+3 //�ػ�Ԫ�� wParam:Ԫ�ؾ��, lParam:*

///@brief �˵�ѡ��
///@code  BOOL CALLBACK WndMenuSelect(HWINDOW hWindow,int id); @endcode
#define  XWM_MENUSELECT       0x7000+4 //�˵�ѡ�� wParam:�˵���ID, lParam:0

///@brief �˵��˳�
///@code  BOOL CALLBACK WndMenuExit(HWINDOW hWindow); @endcode
#define  XWM_MENUEXIT         0x7000+5 //�˵��˳� wParam:0, lParam:0

///@brief ��������ı�
///@code  BOOL CALLBACK WndSetFont(HWINDOW hWindow);  @endcode
#define  XWM_SETFONT          0x7000+6 //��������ı�

//�Ųʶ�ʱ��
///@code  BOOL CALLBACK WndTimer2(HWINDOW hWindow,int timerID,int userData);  @endcode
#define  XWM_TIMER            0x7000+8 //wParam:, lParam:


#define  XWM_DRAW_T           0x7000+9  //���ڻ���,�ڲ�ʹ��, wParam:0, lParam:0


///@}



//���ڷǿͻ�����Ϣ-�߼��ϵķǿͻ���
/// @addtogroup wndNCMSG
/// ���ڷǿͻ�����Ϣ-�߼��ϵķǿͻ���
/// @{

/// @brief ���ڷǿͻ���������Ϣ
/// @code  BOOL CALLBACK WndNCDrawWindow(HWINDOW hWindow,HDRAW hDraw); @endcode
/// @param hWindow ���ھ��
/// @param hDraw   ͼ�λ��ƾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XWM_NCPAINT         0  //wParam:HDC lParam:0

/// @brief ���ڻ��������Ϣ,����ʾ֮ǰ
/// @code  BOOL CALLBACK WndNCEndDrawWindow(HWINDOW hWindow,HDRAW hDraw); @endcode
/// @param hWindow ���ھ��
/// @param hDraw   ͼ�λ��ƾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XWM_NCENDPAINT      1  //wParam:HDC lParam:0       ���ڻ�����ɺ����,������Ч�ϳ�

/// @brief ���ڷǿͻ�������ƶ���Ϣ.
/// @code  BOOL CALLBACK WndNCMouseMove(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
/// @param hWindow ���ھ��
/// @param flags   ��μ�msdn WM_MOUSEMOVE.
/// @param pPt     ��������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XWM_NCMOUSEMOVE     2  //wParam:��ӦϵͳwParam lParam:�����

/// @brief ���ڷǿͻ���������������Ϣ.
/// @code  BOOL CALLBACK WndNCLButtonDown(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
/// @param hWindow ���ھ��
/// @param flags   ��μ�msdn WM_LBUTTONDOWN.
/// @param pPt     ��������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XWM_NCLBUTTONDOWN   3  //wParam:��ӦϵͳwParam lParam:�����

/// @brief ���ڷǿͻ���������������Ϣ.
/// @code  BOOL CALLBACK WndNCLButtonUp(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
/// @param hWindow ���ھ��
/// @param flags   ��μ�msdn MSDN WM_LBUTTONUP.
/// @param pPt     ��������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XWM_NCLBUTTONUP     4  //wParam:��ӦϵͳwParam lParam:�����

/// @brief ���ڷǿͻ�������Ҽ�������Ϣ.
/// @code  BOOL CALLBACK WndNCRButtonDown(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
/// @param hWindow ���ھ��
/// @param flags   ��μ�msdn MSDN WM_RBUTTONDOWN.
/// @param pPt     ��������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XWM_NCRBUTTONDOWN   5  //wParam:��ӦϵͳwParam lParam:�����

/// @brief ���ڷǿͻ�������Ҽ�������Ϣ.
/// @code  BOOL CALLBACK WndNCRButtonUp(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
/// @param hWindow ���ھ��
/// @param flags   ��μ�msdn MSDN WM_RBUTTONUP.
/// @param pPt     ��������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XWM_NCRBUTTONUP     6  //wParam:��ӦϵͳwParam lParam:�����

/// @brief ���ڷǿͻ��������������Ϣ.
/// @code  BOOL CALLBACK WndNCMouseClick(HWINDOW hWindow,POINT *pPt); @endcode
/// @param hWindow ���ھ��
/// @param pPt     ��������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XWM_NCMOUSECLICK    7  //wParam:����� lParam:0    ��굥��      �ǿͻ���

/// @brief ���ڷǿͻ���������˫����Ϣ.
/// @code  BOOL CALLBACK WndNCMouseDBClick(HWINDOW hWindow,POINT *pPt); @endcode
/// @param hWindow ���ھ��
/// @param pPt     ��������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XWM_NCMOUSEDBCLICK  8  //wParam:����� lParam:0    ���˫������  �ǿͻ���

///@}

//Ԫ����Ϣ
/// @addtogroup eleMSG
/// @{

/// @brief Ԫ�ػ�����Ϣ.
/// @code  BOOL CALLBACK EleDraw(HELE hEle,HDRAW hDraw); @endcode
/// @param hEle Ԫ�ؾ��.
/// @param hDraw ͼ�λ��ƾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XM_PAINT          100   //wParam:hDraw,lParam:0

/// @brief Ԫ�������������Ϣ.
/// @code  BOOL CALLBACK EleMouseClick(HELE hEle,POINT *pPt); @endcode
/// @param hEle Ԫ�ؾ��.
/// @param pPt  ��������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XM_MOUSECLICK     101   //��굥��  wParam:POINT����,lParam:0

/// @brief Ԫ��������˫����Ϣ.
/// @code  BOOL CALLBACK EleMouseDBClick(HELE hEle,POINT *pPt); @endcode
/// @param hEle Ԫ�ؾ��.
/// @param pPt  ��������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XM_MOUSEDBCLICK   102   //���˫��  wParam:POINT����,lParam:0

/// @brief Ԫ������ƶ���Ϣ.
/// @code  BOOL CALLBACK EleMouseMove(HELE hEle,UINT flags,POINT *pPt); @endcode
/// @param hEle Ԫ�ؾ��.
/// @param flags ��μ�MSDN WM_MOUSEMOVE.
/// @param pPt   ��������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XM_MOUSEMOVE      103   //����ƶ�  wParam:��ʶ, lParam:POINT����

/// @brief Ԫ��������������Ϣ.
/// @code  BOOL CALLBACK EleLButtonDown(HELE hEle,UINT flags,POINT *pPt); @endcode
/// @param hEle Ԫ�ؾ��.
/// @param flags ��μ�MSDN WM_LBUTTONDOWN.
/// @param pPt   ��������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XM_LBUTTONDOWN    104   //wParam:��ʶ, lParam:POINT����

/// @brief Ԫ��������������Ϣ.
/// @code  BOOL CALLBACK EleLButtonUp(HELE hEle,UINT flags,POINT *pPt); @endcode
/// @param hEle Ԫ�ؾ��.
/// @param flags ��μ�MSDN WM_LBUTTONUP.
/// @param pPt   ��������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XM_LBUTTONUP      105   //wParam:��ʶ, lParam:POINT����

/// @brief Ԫ������Ҽ�������Ϣ.
/// @code  BOOL CALLBACK EleRButtonDown(HELE hEle,UINT flags,POINT *pPt); @endcode
/// @param hEle Ԫ�ؾ��.
/// @param flags ��μ�MSDN WM_RBUTTONDOWN.
/// @param pPt   ��������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XM_RBUTTONDOWN    106   //wParam:��ʶ, lParam:POINT����

/// @brief Ԫ������Ҽ�������Ϣ.
/// @code  BOOL CALLBACK EleRButtonUp(HELE hEle,UINT flags,POINT *pPt); @endcode
/// @param hEle Ԫ�ؾ��.
/// @param flags ��μ�MSDN WM_RBUTTONUP.
/// @param pPt   ��������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ��Ϣ���ݷ���TRUE.
#define  XM_RBUTTONUP      107   //wParam:��ʶ, lParam:POINT����

//�Ųʶ�ʱ��
// BOOL (CALLBACK *pFunEleTimerEx)(HELE hEle,UINT timerID,int userData); //��ʱ����Ϣ XWM_TIMER
#define  XM_TIMER          108


///@}

//Ԫ���¼�
/// @addtogroup eleEvents
/// @{

/// @brief Ԫ�������¼�.
/// @code  void CALLBACK EventDestroy(HELE hEle); @endcode
/// @param hEle  Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_DESTROY        -1  //Ԫ������ �����¼�

/// @brief ��ťԪ�ص���¼�.
/// @code  BOOL CALLBACK EventBtnClick(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_BNCLICK        0   //��ť����¼�,û��ʱ���� wParam:0, lParam:0

/// @brief Ԫ�����ͣ���¼�.
/// @code  BOOL CALLBACK EventMouseStay(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_MOUSESTAY      1   //���ͣ��  wParam:0,lParam:0

/// @brief Ԫ������뿪�¼�.
/// @code  BOOL CALLBACK EventMouseLeave(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_MOUSELEAVE     2   //����뿪  wParam:0,lParam:0

/// @brief Ԫ�������ֹ����¼�.
/// @code  BOOL CALLBACK EventMouseWheel(HELE hEle,HELE hEventEle,UINT flags,POINT *pPt); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_MOUSEWHEEL     3   //������  wParam:��ʶ,lParam:POINT����

/// @brief Ԫ�ػ�ý����¼�.
/// @code  BOOL CALLBACK EventSetFocus(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_SETFOCUS       4   //��ý���  wParam:0,lParam:0

/// @brief Ԫ��ʧȥ�����¼�.
/// @code  BOOL CALLBACK EventKillFocus(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_KILLFOCUS      5   //ʧȥ����  wParam:0,lParam:0

/// @brief Ԫ�ذ����¼�.
/// @code  BOOL CALLBACK EventKeyDown(HELE hEle,HELE hEventEle,WPARAM wParam,LPARAM lParam); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
/// @note   wParam,lParam:��μ�MSDN WM_KEYDOWN. 
#define  XE_KEYDOWN        6   //wParam��lParam�������׼��Ϣ��ͬ

/// @brief ͨ��TranslateMessage����������ַ��¼�.
/// @code  BOOL CALLBACK EventChar(HELE hEle,HELE hEventEle,WPARAM wParam,LPARAM lParam); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
/// @note   wParam,lParam:��μ�MSDN WM_KEYDOWN. 
#define  XE_CHAR           7   //wParam��lParam�μ�MSDN

/// @brief ˮƽ������Ԫ�ع����¼�,����������.
/// @code  BOOL CALLBACK EventHScroll(HELE hEle,HELE hEventEle,int pos); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param pos         ��ǰ������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_HSCROLL        8   //ˮƽ�����������¼� wParam:������,lParam:0 (����������)

/// @brief ��ֱ������Ԫ�ع����¼�,����������.
/// @code  BOOL CALLBACK EventVScroll(HELE hEle,HELE hEventEle,int pos); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param pos         ��ǰ������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_VSCROLL        9   //��ֱ�����������¼� wParam:������,lParam:0 (����������)

/// @brief ������ͼԪ��ˮƽ�����¼�,������ͼ����.
/// @code  BOOL CALLBACK EventHScrollView(HELE hEle,HELE hEventEle,int pos); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param pos         ��ǰ������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_HSCROLLVIEW    10  //������ͼ �����¼� wParam:������,lParam:0 (������ͼ����,����������ͼ�ѹ������)

/// @brief ������ͼԪ�ش�ֱ�����¼�,������ͼ����.
/// @code  BOOL CALLBACK EventVScrollView(HELE hEle,HELE hEventEle,int pos); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param pos         ��ǰ������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_VSCROLLVIEW    11  //������ͼ �����¼� wParam:������,lParam:0 (������ͼ����,����������ͼ�ѹ������)

/// @brief Ԫ��������겶���¼�.
/// @code  BOOL CALLBACK EventSetCapture(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_SETCAPTURE     12  //������겶��  wParam:0,lParam:0

/// @brief Ԫ��ʧȥ��겶���¼�.
/// @code  BOOL CALLBACK EventKillCapture(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_KILLCAPTURE    13  //ʧȥ��겶��  wParam:0,lParam:0

/// @brief �����˵���ѡ���¼�.
/// @code  BOOL CALLBACK EventMenuSelect(HELE hEle,HELE hEventEle,int id); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param id          �˵���id.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_MENUSELECT     14  //�˵���ѡ�� wParam:�˵�ID,lParam:0

/// @brief �����˵��˳��¼�.
/// @code  BOOL CALLBACK EventMenuExit(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_MENUEXIT       15  //�˵��˳�

/// @brief Ԫ�ش�С�ı��¼�.
/// @code  BOOL CALLBACK EventSize(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_SIZE           16  //Ԫ�ش�Сλ�øı�,wParam:0,lParam:0

/// @brief Ԫ������ı��¼�.
/// @code  BOOL CALLBACK EventSetFont(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_SETFONT        17  //Ԫ������ı��¼�,wParam:0,lParam:0

/// @brief Ԫ����ʾ�������¼�.
/// @code  BOOL CALLBACK EventShow(HELE hEle,HELE hEventEle,BOOL bShow); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param bShow       ���Ԫ����ʾTRUE,����FALSE.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_SHOW            18   //wParam:TRUE��FALSE, lParam:0


/// @brief �б�Ԫ��,��ѡ���¼�.
/// @code  BOOL CALLBACK EventListSelect(HELE hEle,HELE hEventEle,int index); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param index       ѡ��������,�����-1û��ѡ����.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_LIST_SELECT          50   //�б���ѡ��, wParam:��index,�����-1û��ѡ����, lParam:0

/// @brief �б�Ԫ��,�б�ͷ�����¼�.
/// @code  BOOL CALLBACK EventListHeaderClick(HELE hEle,HELE hEventEle,int id); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param index          ������.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_LIST_HEADER_CLICK    51   //�б�ͷ����,wParam:��index,   lParam:0

/// @brief �б�Ԫ��,�б�ͷ���ȸı��¼�.
/// @code  BOOL CALLBACK EventListHeaderChange(HELE hEle,HELE hEventEle,int index,int width); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param index       �б�ͷ������.
/// @param width       ����.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_LIST_HEADER_CHANGE   52   //�б�ͷ���ȸı�,wParam:��index, lParam:����

/// @brief ��Ԫ��,��ѡ���¼�.
/// @code  BOOL CALLBACK EventTreeSelect(HELE hEle,HELE hEventEle,int id); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param id          ѡ����id,�����-1û��ѡ����.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_TREE_SELECT          53   //����ѡ��,  wParam:ѡ����id,�����-1û��ѡ����, lParam:0

/// @brief ��Ԫ��,��չ���������¼�.
/// @code  BOOL CALLBACK EventTreeExpand(HELE hEle,HELE hEventEle,int id,BOOL bExpand); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param id          ����id.
/// @param bExpand     TRUEչ��,FALSE����.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_TREE_EXPAND          54   //����չ��������, wParam:��id; lParam:չ��TRUE,����FALSE

/// @brief ��Ͽ�Ԫ��,��Ͽ򵯳������б���ѡ���¼�.
/// @code  BOOL CALLBACK EventComboBoxSelect(HELE hEle,HELE hEventEle,int index); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param index       ѡ��������,���-1û��ѡ����
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_COMBOBOX_SELECT      55   //������Ͽ�ѡ���¼�,wParam:ѡ��������,���-1û��ѡ����, lParam:0

/// @brief ��Ͽ�Ԫ��,��Ͽ������б����¼�.
/// @code  BOOL CALLBACK EventComboBoxPopupList(HELE hEle,HELE hEventEle,HWINDOW hWindow,HELE hListBox); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param hWindow     �������ھ��.
/// @param hListBox    �����б���.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define XE_COMBOBOX_POPUP_LIST   56 //��Ͽ������б����¼�,wParam:�������ھ��, lParam:listBox���

/// @brief ��Ͽ�Ԫ��,��Ͽ򵯳������б��˳��¼�.
/// @code  BOOL CALLBACK EventComboBoxExitList(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define XE_COMBOBOX_EXIT_LIST   57 //��Ͽ򵯳������б�ر��¼�,wParam:0, lParam:0

/// @brief ����ҳԪ��,��ǩ��ѡ���¼�.
/// @code  BOOL CALLBACK EventPPageSelect(HELE hEle,HELE hEventEle,int index); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param index       ѡ���ǩ����,���-1û��ѡ���ǩ.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_PPAGE_SELECT         58   //����ҳ��ǩѡ��,wParam:��ǩ����,���-1û��ѡ���ǩ, lParam:0

/// @brief TabBarԪ��,��ǩ��ѡ���¼�.
/// @code  BOOL CALLBACK EventTabBarSelect(HELE hEle,HELE hEventEle,int index); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param index       ѡ���ǩ����,���-1û��ѡ���ǩ.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_TABBAR_SELECT         58   //TabBar��ǩѡ��,wParam:��ǩ����,���-1û��ѡ���ǩ, lParam:0


/// @brief ������Ԫ��,����λ�øı��¼�.
/// @code  BOOL CALLBACK EventSliderChange(HELE hEle,HELE hEventEle,int pos); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param pos         ���鵱ǰ����λ�õ�.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_SLIDER_CHANGE        59   //������λ�øı�,wParam:���鵱ǰ����λ�õ�, lParam:0

//wParam:TRUE���ڷ����ı�; FALSE:����δ�ı�,����ǰ����һ��, 
//lParam:�������ĵ�һ��ͼ,ͨ����������ں�(1-31)ѡ��,ΪTRUE; ��������ѡ����ͼ,����ѡ����ͼ����FALSE;
/// @brief ����Ԫ��,���ڸı��¼�.
/// @code  BOOL CALLBACK EventMonthChange(HELE hEle,HELE hEventEle,BOOL bChange,BOOL bDownDayNum); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param bChange     TRUE���ڷ����ı�; FALSE����δ�ı�,����ǰ����һ��.
/// @param bDownDayNum �������ĵ�һ��ͼ,ͨ����������ں�(1-31)ѡ��,ΪTRUE; ��������ѡ����ͼ,����ѡ����ͼ����FALSE;
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_MONTHCAL_CHANGE      60   //����Ԫ��,���ڸı��¼�,

/// @brief ���ڱ༭��Ԫ��,���ڸı��¼�,���ڸ�ʽΪ:��-��-��.
/// @code  BOOL CALLBACK EventDateTimeChange(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_DATETIME_CHANGE          61   //����Ԫ��,���ڸı��¼�,wParam:0,lParam:0

/// @brief ���ڱ༭��Ԫ��,��������ѡ�񴰿��¼�.
/// @code  BOOL CALLBACK EventDateTimePopupMonthCal(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_DATETIME_POPUP_MONTHCAL  62  //����Ԫ�� ��������ѡ�񴰿��¼�,wParam:0,lParam:0

/// @brief ���ڱ༭��Ԫ��,��������ѡ�񴰿��˳��¼�.
/// @code  BOOL CALLBACK EventDateTimeExitMonthCal(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_DATETIME_EXIT_MONTHCAL   63  //����Ԫ�� ��������ѡ�񴰿��˳��¼�,wParam:0,lParam:0

/// @brief �б��Ԫ��,��ѡ���¼�.
/// @code  BOOL CALLBACK EventListBoxSelect(HELE hEle,HELE hEventEle,int index); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param index       ѡ���������,�����-1û��ѡ���κ���.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_LISTBOX_SELECT       64   //�б��Ԫ����ѡ��,wParam:ѡ��������,�����-1û��ѡ����; lParam:0

/// @brief ��������Ԫ��,��ѡ��ı��¼�.
/// @code  BOOL CALLBACK EventPGridSelChange(HELE hEle,HELE hEventEle,int prevID,int id); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param prevID      ��ǰѡ����id,�����-1û��ѡ����.
/// @param id          ��ǰѡ����id,�����-1û��ѡ����.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_PGRID_SELCHANGE      65   //�������� ��ѡ��ı�, wParam:��ǰѡ����id,�����-1û��ѡ����; lParam:��ǰѡ����id,�����-1û��ѡ����

/// @brief ��������Ԫ��,��ֵ�ı��¼�.
/// @code  BOOL CALLBACK EventPGridValueChange(HELE hEle,HELE hEventEle,int id); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param id          ��ID.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_PGRID_VALUECHANGE    66   //�������� ��ֵ�ı��¼�, wParam:ֵ�ı����id; lPara:0

/// @brief �б���ͼԪ��,��ѡ���¼�.
/// @code  BOOL CALLBACK EventListViewSelect(HELE hEle,HELE hEventEle,int groupIndex,int itemIndex); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param id          ��ID.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_LISTVIEW_SELECT      67 //�б���ͼԪ��,��ѡ���¼�, wParam:������,���-1û��ѡ����, lParam:�����������-1û��ѡ����

/// @brief �б���ͼԪ��,��չ�������¼�
/// @code  BOOL CALLBACK EventListViewExpand(HELE hEle,HELE hEventEle,int groupIndex,BOOL bExpand); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param id          ��ID.
/// @param bExpand     TRUEչ��,FALSE����.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_LISTVIEW_EXPAND      68 //�б���ͼԪ��,��չ�������¼�, wParam:������; lParam:չ��TRUE,����FALSE

/// @brief �б���ͼԪ��,�û��϶�������¼�
/// @code  BOOL CALLBACK EventListViewDragInsert(HELE hEle,HELE hEventEle,listView_dragInsert_ *pInfo); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param pInfo       ��Ϣ�ṹ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_LISTVIEW_DRAG_INSERT 69  //wParam:listView_dragInsert_*; lParam:0

/// @brief ���������¼�
/// @code  BOOL CALLBACK EventPaneLock(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define XE_PANE_LOACK     70   //wParam:0; lParam:0

/// @brief ����ͣ������ͷ�¼�
/// @code  BOOL CALLBACK EventPaneDock(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_PANE_DOCK     80  //wParam:0; lParam:0

/// @brief ���񸡶��¼�
/// @code  BOOL CALLBACK EventPaneFloat(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_PANE_FLOAT    81  //wParam:0; lParam:0


/// @brief �༭�����ݸı��¼�
/// @code  BOOL CALLBACK EventEditChange(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_EDIT_CHANGE 82  //wParam:0; lParam:0

/// @brief ������Ͽ�Ԫ��,ѡ�������ڸı�.
/// @code  BOOL CALLBACK EventComboBoxSelecting(HELE hEle,HELE hEventEle,int index,BOOL *pBOOL); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param index       ѡ���������,�����-1û��ѡ���κ���.
/// @param pBOOL       �Ƿ���ֹ�ı�,TRUE��ֹ.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_COMBOBOX_SELECT_ING  83  //wParam:index; lParam:pBOOL


/// @brief �б��Ԫ��,��ѡ�����ڸı�.
/// @code  BOOL CALLBACK EventListBoxSelecting(HELE hEle,HELE hEventEle,int index,BOOL *pBOOL); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param index       ѡ���������,�����-1û��ѡ���κ���.
/// @param pBOOL       �Ƿ���ֹ�ı�,TRUE��ֹ.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_LISTBOX_SELECT_ING       84   //�б��Ԫ����ѡ��,wParam:ѡ��������,�����-1û��ѡ����; lParam:pBOOL


/// @brief ��Ԫ��,��ѡ�����ڸı�.
/// @code  BOOL CALLBACK EventTreeSelecting(HELE hEle,HELE hEventEle,int id,BOOL *pBOOL); @endcode
/// @param hEle        ��ǰ�����¼���Ԫ�ؾ��.
/// @param hEventEle   �����¼���Ԫ�ؾ��.
/// @param id          ѡ����id,�����-1û��ѡ����.
/// @param pBOOL       �Ƿ���ֹ�ı�,TRUE��ֹ.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  XE_TREE_SELECT_ING         85   //����ѡ��,  wParam:ѡ����id,�����-1û��ѡ����, lParam:pBOOL

///@}


#ifdef _DEBUG
#define XTRACE   xtrace
#define XTRACEW  xtracew
#define XERROR   XTRACE 
#define XERRORW  XTRACEW
#else
#define XTRACE
#define XTRACEW
#define XERROR 
#define XERRORW
#endif

#ifndef  GET_X_LPARAM
#define  GET_X_LPARAM(lp)   ((int)(short)LOWORD(lp))
#endif
#ifndef  GET_Y_LPARAM
#define  GET_Y_LPARAM(lp)   ((int)(short)HIWORD(lp))
#endif


///////////////////IE begin///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//IE�¼�:
///@defgroup IE_Event IE�¼�
///@details  ע��IE�¼�,DWebBrowserEvents2�ӿ��¼�,ע��API: XWeb_RegEvent().
///@ingroup  msgAndEvents
///@{

/// @brief �ڵ�������֮ǰ.
/// @code  BOOL CALLBACK IE_BeforeNavigate2(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl,in_ int Flags,in_ wchar_t *pTargetFrameName,in_ wchar_t *pPostData,in_ wchar_t *pHeaders,in_out_ VARIANT_BOOL *bCancel); @endcode
/// @param hWebBrowser ������ؼ����.
/// @param pDisp   ��μ�MSDN.
/// @param pUrl    ��μ�MSDN.
/// @param Flags   ��μ�MSDN.
/// @param pTargetFrameName ��μ�MSDN.
/// @param pPostData ��μ�MSDN.
/// @param pHeaders ��μ�MSDN.
/// @param bCancel TRUEȡ��������������FALSE������е���������
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_BEFORENAVIGATE2     DISPID_BEFORENAVIGATE2    //BeforeNavigate2

/// @brief �������,�ͻ������ڴ�Сת�����������ڴ�С.
/// @code  BOOL CALLBACK IE_ClientToHostWindow(HXCGUI hWebBrowser,in_out_ long *pCx,in_out_ long *pCy); @endcode
/// @param hWebBrowser ������ؼ����.
/// @param pCx ���պ�ָ���Ŀͻ��˴��ڵĿ��.
/// @param pCy ���պ�ָ���Ŀͻ��˴��ڵĸ߶�.
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_CLIENTTOHOSTWINDOW  DISPID_CLIENTTOHOSTWINDOW //ClientToHostWindow

/// @brief ����״̬���������.
/// @code BOOL CALLBACK IE_CommandStateChange(HXCGUI hWebBrowser,in_ long command,in_ VARIANT_BOOL enable); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_COMMANDSTATECHANGE  DISPID_COMMANDSTATECHANGE //CommandStateChange  

/// @brief һ���ĵ���ȫ���غͳ�ʼ��.
/// @code BOOL CALLBACK IE_DocumentComplete(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_DOCUMENTCOMPLETE    DISPID_DOCUMENTCOMPLETE   //DocumentComplete

/// @brief ��ʼ��������.
/// @code  BOOL CALLBACK IE_DownloadBegin(HXCGUI hWebBrowser); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_DOWNLOADBEGIN       DISPID_DOWNLOADBEGIN      //DownloadBegin 

/// @brief �����������ʱ��ֹͣ��ʧ��.
/// @code BOOL CALLBACK IE_DownloadComplete(HXCGUI hWebBrowser); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_DOWNLOADCOMPLETE    DISPID_DOWNLOADCOMPLETE   //DownloadComplete 

/// @brief �����ļ��Ǽ�������.
/// @code BOOL CALLBACK IE_FileDownload(HXCGUI hWebBrowser,in_ VARIANT_BOOL ActiveDocument,in_out_ VARIANT_BOOL *Cancel); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_FILEDOWNLOAD        DISPID_FILEDOWNLOAD       //FileDownload

/// @brief ������һ������,һ������Ԫ�ػ�һ�����Ԫ�����.
/// @code BOOL CALLBACK IE_NavigateComplete2(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_NAVIGATECOMPLETE2   DISPID_NAVIGATECOMPLETE2 //NavigateComplete2

/// @brief �ڵ��������з�������ʱ����.
/// @code BOOL CALLBACK IE_NavigateError(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl,in_ wchar_t *pTargetFrameName,in_ int statusCode,in_out_ VARIANT_BOOL *bCancel); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_NAVIGATEERROR       DISPID_NAVIGATEERROR     //NavigateError

//       IE_NEWPROCESS          DISPID_NEWPROCESS        //NewProcess �Ҳ���

/// @brief ����һ���µĴ���ʱ����.
/// @code BOOL CALLBACK IE_NewWindow2(HXCGUI hWebBrowser,in_out_ IDispatch **pDisp,in_out_ VARIANT_BOOL *bCancel); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_NEWWINDOW2          DISPID_NEWWINDOW2        //NewWindow2

/// @brief ����һ���´���ʱ����.
/// @code BOOL (CALLBACK *pFunIE_NewWindow3)(HXCGUI hWebBrowser,in_out_ IDispatch **pDisp,in_out_ VARIANT_BOOL *bCancel,in_ DWORD dwFlags,in_ wchar_t *pUrlContext,in_ wchar_t *pUrl); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_NEWWINDOW3          DISPID_NEWWINDOW3       //NewWindow3

/// @brief IWebBrowser2::FullScreen���Ա��ı�ʱ����.
/// @code BOOL CALLBACK IE_OnFullScreen(HXCGUI hWebBrowser,in_ VARIANT_BOOL bFullScreen); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_ONFULLSCREEN        DISPID_ONFULLSCREEN     //OnFullScreen

/// @brief IWebBrowser2::MenuBar���Ա��ı�ʱ����.
/// @code BOOL CALLBACK IE_OnMenuBar(HXCGUI hWebBrowser,in_ VARIANT_BOOL bMenuBar); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_ONMENUBAR           DISPID_ONMENUBAR        //OnMenuBar

/// @brief Internet Explorer��Ӧ�ó����˳�֮ǰ����.
/// @code BOOL CALLBACK IE_OnQuit(HXCGUI hWebBrowser); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_ONQUIT              DISPID_ONQUIT           //OnQuit

/// @brief IWebBrowser2::StatusBar���Ա��ı�ʱ����.
/// @code BOOL CALLBACK IE_OnStatusBar(HXCGUI hWebBrowser,in_ VARIANT_BOOL bStatusBar); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_ONSTATUSBAR         DISPID_ONSTATUSBAR      //OnStatusBar

/// @brief IWebBrowser2::TheaterMode���Ա��ı�ʱ����.
/// @code BOOL CALLBACK IE_OnTheaterMode(HXCGUI hWebBrowser,in_ VARIANT_BOOL bTheaterMode); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_ONTHEATERMODE       DISPID_ONTHEATERMODE     //OnTheaterMode

/// @brief IWebBrowser2::ToolBar���Ա��ı�ʱ����.
/// @code BOOL CALLBACK IE_OnToolBar(HXCGUI hWebBrowser,in_ VARIANT_BOOL bToolBar); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_ONTOOLBAR           DISPID_ONTOOLBAR         //OnToolBar

/// @brief IWebBrowser2::Visible���Ա��ı�ʱ����.
/// @code BOOL CALLBACK IE_OnVisible(HXCGUI hWebBrowser,in_ VARIANT_BOOL bVisible); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_ONVISIBLE           DISPID_ONVISIBLE         //OnVisible

/// @brief ��ӡģ��ʵ����ʱ����.
/// @code BOOL CALLBACK IE_PrintTemplateInstantiation(HXCGUI hWebBrowser,in_ IDispatch *pDisp); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_PRINTTEMPLATEINSTANTIATION DISPID_PRINTTEMPLATEINSTANTIATION //PrintTemplateInstantiation

/// @brief ��ӡģ�屻����ʱ����.
/// @code BOOL CALLBACK IE_PrintTemplateTeardown(HXCGUI hWebBrowser,in_ IDispatch *pDisp); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_PRINTTEMPLATETEARDOWN  DISPID_PRINTTEMPLATETEARDOWN  // PrintTemplateTeardown

/// @brief ��һ����Ӱ���˽���¼�,���û������Ѿ���Ӱ���Զ��URLʱ����.
/// @code  BOOL CALLBACK IE_PrivacyImpactedStateChange(HXCGUI hWebBrowser,in_ VARIANT_BOOL bPrivacyImpacted); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_PRIVACYIMPACTEDSTATECHANGE  DISPID_PRIVACYIMPACTEDSTATECHANGE //PrivacyImpactedStateChange

/// @brief ���¶���ʱ���������ز����Ľ���.
/// @code  BOOL CALLBACK IE_ProgressChangee(HXCGUI hWebBrowser,in_ long Progress,in_ long ProgressMax); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_PROGRESSCHANGE       DISPID_PROGRESSCHANGE   //ProgressChange

/// @brief IWebBrowser2::PutProperty����ķ����ı�����ֵʱ����.
/// @code  BOOL CALLBACK IE_PropertyChange(HXCGUI hWebBrowser,in_ wchar_t *pProperty); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_PROPERTYCHANGE       DISPID_PROPERTYCHANGE   //PropertyChange

//       IE_REDIRECTXDOMAINBLOCKED  DISPID_REDIRECTXDOMAINBLOCKED // RedirectXDomainBlocked �Ҳ���

/// @brief ����������ǰ��ҳ��ð���˷���΢��Ľ��Ⱥ�״̬��.
/// @code  BOOL CALLBACK IE_SetPhishingFilterStatus(HXCGUI hWebBrowser,in_ long phishingFilterStatus); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_SETPHISHINGFILTERSTATUS DISPID_SETPHISHINGFILTERSTATUS //SetPhishingFilterStatus

/// @brief �ڼ��ܼ���ı仯ʱ����.
/// @code  BOOL CALLBACK IE_SetSecureLockIcon(HXCGUI hWebBrowser,in_ signed int SecureLockIcon); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_SETSECURELOCKICON    DISPID_SETSECURELOCKICON  //SetSecureLockIcon

/// @brief �ı�����״̬���ı�ʱ����.
/// @code  BOOL CALLBACK IE_StatusTextChange(HXCGUI hWebBrowser,in_ wchar_t *pText); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_STATUSTEXTCHANGE     DISPID_STATUSTEXTCHANGE    //StatusTextChange

//       IE_THIRDPARTYURLBLOCKED DISPID_THIRDPARTYURLBLOCKED //ThirdPartyUrlBlocked �Ҳ���

/// @brief ������ĵ��ı����Ϊ���û�ı�ʱ����.
/// @code  BOOL CALLBACK IE_TitleChange(HXCGUI hWebBrowser,in_ wchar_t *pText); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_TITLECHANGE          DISPID_TITLECHANGE        //TitleChange

//UpdatePageStatus IEû��ʵ��

/// @brief �ö���Ĵ��ڱ��رսű�ʱ����.
/// @code  BOOL CALLBACK IE_WindowClosing(HXCGUI hWebBrowser,in_ VARIANT_BOOL IsChildWindow,in_out_ VARIANT_BOOL *bCancel); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_WINDOWCLOSING       DISPID_WINDOWCLOSING      //WindowClosing

/// @brief ������ı���߶ȵĴ���.
/// @code  BOOL CALLBACK IE_WindowSetHeight(HXCGUI hWebBrowser,in_ long height); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_WINDOWSETHEIGHT     DISPID_WINDOWSETHEIGHT    //WindowSetHeight

/// @brief ������ı������λ��ʱ����.
/// @code  BOOL CALLBACK IE_WindowSetLeft(HXCGUI hWebBrowser,in_ long left); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_WINDOWSETLEFT       DISPID_WINDOWSETLEFT      //WindowSetLeft

/// @brief ����ָʾ���������Ƿ�Ӧ�������������.
/// @code  BOOL CALLBACK IE_WindowSetResizable(HXCGUI hWebBrowser,in_ VARIANT_BOOL bResizable); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_WINDOWSETRESIZABLE  DISPID_WINDOWSETRESIZABLE   //WindowSetResizable

/// @brief ������ı��䶥��λ�õĴ���.
/// @code  BOOL CALLBACK IE_WindowSetTop(HXCGUI hWebBrowser,in_ long top); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_WINDOWSETTOP        DISPID_WINDOWSETTOP    //WindowSetTop

/// @brief ������ı����ȵĴ���.
/// @code  BOOL CALLBACK IE_WindowSetWidth(HXCGUI hWebBrowser,in_ long width); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_WINDOWSETWIDTH      DISPID_WINDOWSETWIDTH   //WindowSetWidth

/// @brief  ���������ݵĿɼ���״̬������������ڻ�ѡ�������ʱ����.
/// @code   BOOL CALLBACK IE_WindowStateChanged(HXCGUI hWebBrowser,in_ DWORD dwFlags,in_ DWORD dwValidFlagsMask); @endcode
/// @return Ĭ�Ϸ���FALSE,�����ֹ�¼����ݷ���TRUE.
#define  IE_WINDOWSTATECHANGED  DISPID_WINDOWSTATECHANGED  //WindowStateChanged

///@}

//����IE�ⲿ��������
typedef BOOL (CALLBACK *pFunIE_External0)(HXCGUI hWebBrowser,HSTRING hResultVal);
typedef BOOL (CALLBACK *pFunIE_External1)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1);
typedef BOOL (CALLBACK *pFunIE_External2)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1,wchar_t *pParam2);
typedef BOOL (CALLBACK *pFunIE_External3)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1,wchar_t *pParam2,wchar_t *pParam3);
typedef BOOL (CALLBACK *pFunIE_External4)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1,wchar_t *pParam2,wchar_t *pParam3,wchar_t *pParam4);
typedef BOOL (CALLBACK *pFunIE_External5)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1,wchar_t *pParam2,wchar_t *pParam3,wchar_t *pParam4,wchar_t *pParam5);
typedef BOOL (CALLBACK *pFunIE_External6)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1,wchar_t *pParam2,wchar_t *pParam3,wchar_t *pParam4,wchar_t *pParam5,wchar_t *pParam6);
typedef BOOL (CALLBACK *pFunIE_External7)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1,wchar_t *pParam2,wchar_t *pParam3,wchar_t *pParam4,wchar_t *pParam5,wchar_t *pParam6,wchar_t *pParam7);
typedef BOOL (CALLBACK *pFunIE_External8)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1,wchar_t *pParam2,wchar_t *pParam3,wchar_t *pParam4,wchar_t *pParam5,wchar_t *pParam6,wchar_t *pParam7,wchar_t *pParam8);


//����IE�¼��ص���������
typedef BOOL (CALLBACK *pFunIE_BeforeNavigate2)(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl,in_ int Flags,in_ wchar_t *pTargetFrameName,in_ wchar_t *pPostData,in_ wchar_t *pHeaders,in_out_ VARIANT_BOOL *bCancel);
typedef BOOL (CALLBACK *pFunIE_ClientToHostWindow)(HXCGUI hWebBrowser,in_out_ long *pCx,in_out_ long *pCy);
typedef BOOL (CALLBACK *pFunIE_CommandStateChange)(HXCGUI hWebBrowser,in_ long command,in_ VARIANT_BOOL enable);
typedef BOOL (CALLBACK *pFunIE_DocumentComplete)(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl);
typedef BOOL (CALLBACK *pFunIE_DownloadBegin)(HXCGUI hWebBrowser);
typedef BOOL (CALLBACK *pFunIE_DownloadComplete)(HXCGUI hWebBrowser);
typedef BOOL (CALLBACK *pFunIE_FileDownload)(HXCGUI hWebBrowser,in_ VARIANT_BOOL ActiveDocument,in_out_ VARIANT_BOOL *Cancel);
typedef BOOL (CALLBACK *pFunIE_NavigateComplete2)(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl);
typedef BOOL (CALLBACK *pFunIE_NavigateError)(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl,in_ wchar_t *pTargetFrameName,in_ int statusCode,in_out_ VARIANT_BOOL *bCancel);
typedef BOOL (CALLBACK *pFunIE_NewWindow2)(HXCGUI hWebBrowser,in_out_ IDispatch **pDisp,in_out_ VARIANT_BOOL *bCancel);
typedef BOOL (CALLBACK *pFunIE_NewWindow3)(HXCGUI hWebBrowser,in_out_ IDispatch **pDisp,in_out_ VARIANT_BOOL *bCancel,in_ DWORD dwFlags,in_ wchar_t *pUrlContext,in_ wchar_t *pUrl);
typedef BOOL (CALLBACK *pFunIE_OnFullScreen)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bFullScreen);
typedef BOOL (CALLBACK *pFunIE_OnMenuBar)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bMenuBar);
typedef BOOL (CALLBACK *pFunIE_OnQuit)(HXCGUI hWebBrowser);
typedef BOOL (CALLBACK *pFunIE_OnStatusBar)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bStatusBar);
typedef BOOL (CALLBACK *pFunIE_OnTheaterMode)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bTheaterMode);
typedef BOOL (CALLBACK *pFunIE_OnToolBar)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bToolBar);
typedef BOOL (CALLBACK *pFunIE_OnVisible)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bVisible);
typedef BOOL (CALLBACK *pFunIE_PrintTemplateInstantiation)(HXCGUI hWebBrowser,in_ IDispatch *pDisp);
typedef BOOL (CALLBACK *pFunIE_PrintTemplateTeardown)(HXCGUI hWebBrowser,in_ IDispatch *pDisp);
typedef BOOL (CALLBACK *pFunIE_PrivacyImpactedStateChange)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bPrivacyImpacted);
typedef BOOL (CALLBACK *pFunIE_ProgressChangee)(HXCGUI hWebBrowser,in_ long Progress,in_ long ProgressMax);
typedef BOOL (CALLBACK *pFunIE_PropertyChange)(HXCGUI hWebBrowser,in_ wchar_t *pProperty);
typedef BOOL (CALLBACK *pFunIE_SetPhishingFilterStatus)(HXCGUI hWebBrowser,in_ long phishingFilterStatus);
typedef BOOL (CALLBACK *pFunIE_SetSecureLockIcon)(HXCGUI hWebBrowser,in_ signed int SecureLockIcon);
typedef BOOL (CALLBACK *pFunIE_StatusTextChange)(HXCGUI hWebBrowser,in_ wchar_t *pText);
typedef BOOL (CALLBACK *pFunIE_TitleChange)(HXCGUI hWebBrowser,in_ wchar_t *pText);
typedef BOOL (CALLBACK *pFunIE_WindowClosing)(HXCGUI hWebBrowser,in_ VARIANT_BOOL IsChildWindow,in_out_ VARIANT_BOOL *bCancel);
typedef BOOL (CALLBACK *pFunIE_WindowSetHeight)(HXCGUI hWebBrowser,in_ long height);
typedef BOOL (CALLBACK *pFunIE_WindowSetLeft)(HXCGUI hWebBrowser,in_ long left);
typedef BOOL (CALLBACK *pFunIE_WindowSetResizable)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bResizable);
typedef BOOL (CALLBACK *pFunIE_WindowSetTop)(HXCGUI hWebBrowser,in_ long top);
typedef BOOL (CALLBACK *pFunIE_WindowSetWidth)(HXCGUI hWebBrowser,in_ long width);
typedef BOOL (CALLBACK *pFunIE_WindowStateChanged)(HXCGUI hWebBrowser,in_ DWORD dwFlags,in_ DWORD dwValidFlagsMask);

////////////////IE end///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

//������Ϣ�������
typedef BOOL (CALLBACK *pFunWndMsgProc)(HWINDOW hWindow,UINT message, WPARAM wParam, LPARAM lParam);
//Ԫ����Ϣ�������
typedef BOOL (CALLBACK *pFunEleMsgProc)(HELE hEle,UINT eleMessage,WPARAM wParam,LPARAM lParam);
//Ԫ���¼��������
typedef BOOL (CALLBACK *pFunEleEventProc)(HELE hEle,int type,WPARAM wParam,LPARAM lParam);
//���ƹ�����ͼ
typedef BOOL (CALLBACK *pFunDrawScrollView)(HELE hEle,HDRAW hDraw);



//////////////////////////////////////////////////////////
//��Ԫ���Ի�
///@addtogroup groupTree
///@{

///�б���Ԫ��,���Ի�ṹ
struct tree_drewItem_
{
	HDRAW     hDraw;    ///<ͼ�λ��ƾ��
	int      id;        ///<��ID
	int      imageId;   ///<ͼ��ID
	int      state;     ///<״̬
	BOOL     bExpand;   ///<�Ƿ�չ�����
	wchar_t  *pText;    ///<�ı�����

	RECT  rcButton; ///<��ť����
	RECT  rcImage;  ///<ͼƬ����
	RECT  rcText;   ///<�ı�����
};

///@}


///@defgroup groupList_draw �б�Ԫ���Ի�
///@ingroup macroDefine
///@{

///�б�Ԫ��,���Ի�ṹ
struct list_drawItem_
{
	HDRAW hDraw;     ///<ͼ�λ��ƾ��
	int   index;     ///<������
	int   subIndex;  ///<��������
	int   imageId;   ///<ͼ��ID
	int   state;     ///<״̬
	RECT  rect;      ///<������
	RECT  rcCheck;   ///<��ѡ������,��subIndex����Ϊ0����Ч
	wchar_t *pText;  ///<�ı�����
};

///�б�Ԫ��,�б�ͷ���Ի�ṹ
struct listHeader_drawItem_
{
	HDRAW hDraw;    ///<ͼ�λ��ƾ��
	int   index;    ///<������
	int   imageId;  ///<ͼ��ID
	int   state;    ///<״̬ ���ֵΪ-1,��ôΪ���Ʊ���
	RECT  rect;     ///<������
	wchar_t *pText; ///<�ı�����
};

///@}



///@defgroup groupListBox_draw �б��Ԫ���Ի�
///@ingroup macroDefine
///@{

///�б��Ԫ��,���Ի�ṹ
struct listBox_drawItem_
{
	HDRAW hDraw;    ///<ͼ�λ��ƾ��
	int   index;    ///<����
	int   imageId;  ///<ͼ��ID
	int   state;    ///<״̬
	RECT  rcItem;   ///<������
	RECT  rcCheck;  ///<��ѡ������,����ѡ������ʱ��Ч
	wchar_t *pText; ///<�ı�����
};
///@}


///@defgroup itemBindEle ���Ԫ����Ϣ�ṹ
///@ingroup macroDefine
///@{

///���Ԫ����Ϣ�ṹ.
struct itemBindEle_
{
	HELE hEle;   ///<�󶨵�Ԫ��,����󶨵��б�Ԫ��,��ô���ĸ�Ӧ��Ϊ�б�Ԫ��.
	int left;    ///<�������.
	int top;     ///<�������.
	int width;   ///<���.
	int height;  ///<�߶�.
};

///@}

///@defgroup groupListView_draw �б���ͼԪ���Ի�
///@ingroup macroDefine
///@{

///�б���ͼԪ��,���Ի�ṹ
struct listView_drawItem_	//������
{
	HDRAW     hDraw;   ///<ͼ�λ��ƾ��
	int       groupIndex; //������
	int       itemIndex;  //������
	int       imageID; ///<ͼƬID
	wchar_t   *pText;  ///<�ı�
	int       state;   ///<״̬,�Ƿ�ѡ��
	
	HIMAGE hImage_stay;    //��ͣ��ͼƬ
	HIMAGE hImage_select;  //��ѡ��ͼ��

	RECT  rcIcon; ///<ͼ������
	RECT  rcIconDraw; ///<ͼ��ʵ�ʻ�������
	RECT  rcText; ///<��������
	RECT  rect;   ///<��������,�����߿�

	int userData;  ///<�û�����
};

///�б���ͼԪ��,���Ի�ṹ
struct listView_drawGroup_ //������
{
	HDRAW hDraw;        ///<ͼ�λ��ƾ��
	BOOL  bExpand;      ///<�Ƿ�չ��

	wchar_t  *pText;    ///<�ı�
	RECT     rcText;    ///<�ı�����
	RECT     rcButton;  ///<չ����ť����
	RECT     rect;      ///<����������

	int userData;       ///<�û�����
};

///�б���ͼԪ��,�û��϶������
struct listView_dragInsert_
{
	int groupIndex;   ///<�϶��� - ������
	int itemIndex;    ///<�϶��� - ������

	int groupIndex_insert; ///<����λ�� - ������
	int itemIndex_insert;  ///<����λ�� - ������

	int groupIndex_new; //�����λ�� ������
	int itemIndex_new; //�����λ�� ������
};

///@}






///@defgroup groupMenu_draw �˵��Ի�
///@ingroup macroDefine
///@{

///�˵����Ի�ṹ
struct menu_drawItem_
{
	HWINDOW    hWindow;     ///<��ǰ�����˵���Ĵ��ھ��
	HDRAW      hDraw;       ///<ͼ�λ��ƾ��
	int        id;          ///<ID
	int        state;	    ///<״̬
	RECT       rcItem;      ///<����
	HIMAGE     hImage;      ///<ͼƬ
	wchar_t    *pText;      ///<�ı�
};

///�˵����ڱ����Ի�ṹ
struct menu_drawBG_
{
	HWINDOW    hWindow;       ///<��ǰ�����˵���Ĵ��ھ��
	HDRAW      hDraw;         ///<ͼ�λ��ƾ��
	int        parentItemId;  ///<�Ӳ˵���Ӧ�ĸ���˵�ID��-1û�и���
	HIMAGE     hImage;        ///<ͼƬ
};

///@}

//�б����Ի�
typedef void (CALLBACK *pFunList_DrawItem)(HELE hEle,list_drawItem_ *pDrawItem);
//�б�ͷ���Ի�
typedef void (CALLBACK *pFunListHeader_DrawItem)(HELE hEle,listHeader_drawItem_ *pDrawItem);

//�б�����Ի�
typedef void (CALLBACK *pFunListBox_DrawItem)(HELE hEle,listBox_drawItem_ *pDrawItem);

//�����Ի�
typedef void (CALLBACK *pFunTree_DrawItem)(HELE hEle,tree_drewItem_ *pDrawItem);

//�б���ͼ���Ի�
typedef void (CALLBACK *pFunListView_DrawItem)(HELE hEle,listView_drawItem_ *pDrawItem);

//�б���ͼ���Ի�
typedef void (CALLBACK *pFunListView_DrawGroup)(HELE hEle,listView_drawGroup_ *pDrawGroup);

//�˵����Ի�
typedef void (CALLBACK *pFunMenu_DrawItem)(HMENUX hMenu,menu_drawItem_ *pDrawItem);

//�˵������Ի�
typedef void (CALLBACK *pFunMenu_DrawBG)(HMENUX hMenu,menu_drawBG_ *pDrawBG);

//�˵������UI
typedef void (CALLBACK *pFunMenu_UpdateUI)(HMENUX hMenu,int id);

//////////////////////////////////////////////////////////////////////////////////
//���沿��ͨ������Ҫ�Ķ�//////////////////////////////////////////////////////////
#define XCGUI_PLUS  // C++��֧�ְ� , C plus plus

#ifdef	XCGUI_PLUS  //C++��֧��,�����Ա����ע���֧��
struct eventOrMsg_  //Ԫ����Ϣ�¼��ص���Ϣ,C++��֧��
{
	union
	{
		HELE hEle;
		HWINDOW hWindow;
		HMENUX  hMenu;
	};
	union
	{
		HELE hEventEle;
		int  xint;
	};
	WPARAM wParam;
	LPARAM lParam;
	void   *pClass_fun;  //���Ա����ָ��
};

//��ʽ xc_fun_��������_�������ͱ�...
//b:BOOL, e:HELE, w:HWINDOW, x:HXCGUI, hwnd:HWND, hdraw:HDRAW, i:int, p:void*, pt:POINT*, size:SIZE*, v:void
//pb:BOOL*;
//menu:HMENUX.
enum xcgui_fun_type //��������
{
	xc_fun_b_e_e,
	xc_fun_b_e_e_b,
	xc_fun_b_e_e_b_b,
	xc_fun_b_e_e_w_e,
	xc_fun_b_e_e_pb,
	xc_fun_b_e_e_i,
	xc_fun_b_e_e_i_pt,
	xc_fun_b_e_e_i_b,
	xc_fun_b_e_e_i_pb,
	xc_fun_b_e_e_i_i,
	xc_fun_b_e_i_i,
	xc_fun_b_e_i_i_i,
	xc_fun_b_e_e_listView_dragInsert,

	xc_fun_v_e, //Ԫ������
	xc_fun_b_e_pt,
	xc_fun_b_e_hdraw,
	xc_fun_b_e_i_pt,
	xc_fun_b_w,
	xc_fun_b_w_e,
	xc_fun_b_w_pt,
	xc_fun_b_w_i,
	xc_fun_b_w_i_pt,
	xc_fun_b_w_i_size,
	xc_fun_b_w_i_i,
	xc_fun_b_w_hdraw,
	xc_fun_b_w_hwnd,

	xc_fun_v_e_list_item,
	xc_fun_v_e_list_header,
	xc_fun_v_e_tree,
	xc_fun_v_e_listBox,
	xc_fun_v_e_listView_item,
	xc_fun_v_e_listView_group,
	xc_fun_v_x_menu_item,
	xc_fun_v_x_menu_bg,
	xc_fun_v_x_menu_i,
};

//�¼��ص�����
typedef BOOL (CALLBACK *pFunClassEventMsg)(eventOrMsg_ *pEvent,xcgui_fun_type funType);


//{
//����API�ڲ�ʹ��
extern XC_API void* WINAPI XC_Malloc(int size);
extern XC_API void WINAPI XEle_RegisterMessageEx(HELE hEle,int message,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);
extern XC_API void WINAPI XEle_RegisterEventEx(HELE hEle,int type,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);
extern XC_API void WINAPI XEle_RegisterMsgProcEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);    //ע��Ԫ����Ϣ�������
extern XC_API void WINAPI XEle_RegisterEventProcEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);  //ע���¼����ع��˺���

extern XC_API void WINAPI XWnd_RegisterMessageEx(HWINDOW hWindow,int message,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);  //ע����Ϣ�ص�����
extern XC_API void WINAPI XWnd_RegisterNCMessageEx(HWINDOW hWindow,int message,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //ע��ǿͻ�����Ϣ
extern XC_API void WINAPI XWnd_RegisterMsgProcEx(HWINDOW hWindow,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);	//ע�ᴰ����Ϣ�������

extern XC_API void WINAPI XSView_SetDrawScrollViewEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);
extern XC_API void WINAPI XList_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի��б���
extern XC_API void WINAPI XList_SetUserDrawItemHeaderEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի��б�ͷ��
extern XC_API void WINAPI XTree_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի���
extern XC_API void WINAPI XListBox_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի��б����
extern XC_API void WINAPI XListView_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի���
extern XC_API void WINAPI XListView_SetUserDrawGroupEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի���
extern XC_API void WINAPI XMenu_SetUserDrawItemEx(HMENUX hMenu,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի�˵���
extern XC_API void WINAPI XMenu_SetUserDrawBGEx(HMENUX hMenu,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի�˱���
extern XC_API void WINAPI XMenu_SetUserUpdateUIEx(HMENUX hMenu,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);

//}

class CXEventMsg
{
public:
	virtual void CXEventMsg__(void){} //�˺�������ɾ��

//ע��Ԫ���¼�
#define XCGUI_RegEleEvent(hEle,type,memberFunction) \
		RegisterAll(hEle,type,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_event)

//ע��Ԫ����Ϣ
#define XCGUI_RegEleMessage(hEle,type,memberFunction) \
		RegisterAll(hEle,type,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_msg)

//ע��Ԫ����Ϣ�������
#define XCGUI_RegEleMsgProc(hEle,type,memberFunction) \
		RegisterAll(hEle,type,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_msg_proc)

//ע��Ԫ���¼��������
#define XCGUI_RegEleEventProc(hEle,type,memberFunction) \
		RegisterAll(hEle,type,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_event_proc)

//ע�ᴰ����Ϣ
#define XCGUI_RegWndMessage(hWindow,type,memberFunction) \
		RegisterAll(hWindow,type,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),wnd_msg)

//ע�ᴰ���߼��ǿͻ�����Ϣ
#define XCGUI_RegWndNCMessage(hWindow,type,memberFunction) \
		RegisterAll(hWindow,type,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),wnd_msg_nc)

//ע�ᴰ����Ϣ�������
#define XCGUI_RegWndMsgProc(hWindow,memberFunction) \
		RegisterAll(hWindow,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),wnd_msg_proc)

//ע�������ͼ����
#define XCGUI_SView_SetDrawScrollView(hEle,memberFunction) \
		RegisterAll(hEle,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_scrollView_draw)

//ע���б������
#define XCGUI_List_SetUserDrawItem(hEle,memberFunction) \
		RegisterAll(hEle,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_list_drawItem)

//�б�ͷ�����
#define XCGUI_List_SetUserDrawItemHeader(hEle,memberFunction) \
		RegisterAll(hEle,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_list_drawItemHeader)

//�������
#define XCGUI_Tree_SetUserDrawItem(hEle,memberFunction) \
		RegisterAll(hEle,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_tree_drawItem)

//�б�������
#define XCGUI_ListBox_SetUserDrawItem(hEle,memberFunction) \
		RegisterAll(hEle,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_listBox_drawItem)

//�б���ͼ�����
#define XCGUI_ListView_SetUserDrawItem(hEle,memberFunction) \
		RegisterAll(hEle,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_listView_drawItem)

//�б���ͼ�����
#define XCGUI_ListView_SetUserDrawGroup(hEle,memberFunction) \
		RegisterAll(hEle,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_listView_drawGroup)

//�˵����Ի�
#define XCGUI_Menu_SetUserDrawItem(hMenu,memberFunction) \
	RegisterAll(hMenu,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_menu_drawItem)

//�˵������Ի�
#define XCGUI_Menu_SetUserDrawBG(hMenu,memberFunction) \
	RegisterAll(hMenu,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_menu_drawBG)

//���²˵���
#define XCGUI_Menu_SetUserUpdateUI(hMenu,memberFunction) \
	RegisterAll(hMenu,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_menu_updateUI)

	union xcgui_functions //����ָ��
	{
		void (CXEventMsg::*fun_v_v)(void);
		BOOL (CXEventMsg::*fun_b_e_e_i_i)(HELE,HELE,int,int);
		BOOL (CXEventMsg::*fun_b_e_e_i)(HELE,HELE,int);
		BOOL (CXEventMsg::*fun_b_e_e)(HELE,HELE);
		BOOL (CXEventMsg::*fun_b_e_e_pb)(HELE,HELE,BOOL*);
		BOOL (CXEventMsg::*fun_b_e_e_i_pb)(HELE,HELE,int,BOOL*);
		BOOL (CXEventMsg::*fun_b_e_e_b)(HELE,HELE,BOOL);

		BOOL (CXEventMsg::*fun_b_e_e_i_p)(HELE,HELE,int,POINT*);
		BOOL (CXEventMsg::*fun_b_e_e_i_b)(HELE,HELE,int,BOOL);
		BOOL (CXEventMsg::*fun_b_e_e_b_b)(HELE,HELE,BOOL,BOOL);
		BOOL (CXEventMsg::*fun_b_e_i_i_i)(HELE,int,int,int);
		BOOL (CXEventMsg::*fun_b_e_i_i)(HELE,int,int);
		BOOL (CXEventMsg::*fun_b_e_e_w_e)(HELE,HELE,HWINDOW,HELE);
		BOOL (CXEventMsg::*fun_b_e_e_listViewDragInsert)(HELE,HELE,listView_dragInsert_*);

		void (CXEventMsg::*fun_v_e)(HELE);

		BOOL (CXEventMsg::*fun_b_e_i_p)(HELE,int,POINT*);
		BOOL (CXEventMsg::*fun_b_e_p)(HELE,POINT*);
		BOOL (CXEventMsg::*fun_b_e_hdraw)(HELE,HDRAW);

		BOOL (CXEventMsg::*fun_b_w_hdraw)(HWINDOW,HDRAW);
		BOOL (CXEventMsg::*fun_b_w)(HWINDOW);
		BOOL (CXEventMsg::*fun_b_w_i_p)(HWINDOW,int,POINT*);
		BOOL (CXEventMsg::*fun_b_w_i_size)(HWINDOW,int,SIZE*);
		BOOL (CXEventMsg::*fun_b_w_i_i)(HWINDOW,int,int);
		BOOL (CXEventMsg::*fun_b_w_p)(HWINDOW,POINT*);
		BOOL (CXEventMsg::*fun_b_w_e)(HWINDOW,HELE);
		BOOL (CXEventMsg::*fun_b_w_hwnd)(HWINDOW,HWND);
		BOOL (CXEventMsg::*fun_b_w_i)(HWINDOW,int);

		void (CXEventMsg::*fun_v_e_list)(HELE,list_drawItem_*);
		void (CXEventMsg::*fun_v_e_listHeader)(HELE,listHeader_drawItem_*);
		void (CXEventMsg::*fun_v_e_tree)(HELE,tree_drewItem_*);
		void (CXEventMsg::*fun_v_e_listBox)(HELE,listBox_drawItem_*);
		void (CXEventMsg::*fun_v_e_listView)(HELE,listView_drawItem_*);
		void (CXEventMsg::*fun_v_e_listViewGroup)(HELE,listView_drawGroup_*);
		void (CXEventMsg::*fun_v_x_menu_drawItem)(HMENUX,menu_drawItem_*);
		void (CXEventMsg::*fun_v_x_menu_drawBG)(HMENUX,menu_drawBG_*);
		void (CXEventMsg::*fun_v_x_menu_updateUI)(HMENUX,int);
	};
	enum xcgui_reg_type //ע������
	{
		ele_event,        //Ԫ���¼�
		ele_msg,          //Ԫ����Ϣ
		ele_msg_proc,     //Ԫ����Ϣ�������
		ele_event_proc,   //Ԫ���¼��������
		wnd_msg,          //������Ϣ
		wnd_msg_nc,       //�����߼��ǿͻ�����Ϣ
		wnd_msg_proc,     //������Ϣ�������
		//---------------
		ele_scrollView_draw,     //������ͼ�Ի�
		ele_list_drawItem,       //�б����Ի�
		ele_list_drawItemHeader, //�б�ͷ���Ի�
		ele_tree_drawItem,       //�����Ի�
		ele_listBox_drawItem,    //�б�����Ի�
		ele_listView_drawItem,   //�б���ͼ�����
		ele_listView_drawGroup,  //�б���ͼ�����
		ele_menu_drawItem,       //���Ʋ˵���
		ele_menu_drawBG,         //���Ʋ˵�����
		ele_menu_updateUI,       //�˵������UI
	};

	struct  xcgui_info_
	{
		CXEventMsg  *theThis;
		xcgui_functions  funs;
	};

	void RegisterAll(HXCGUI hXCGUI,int type,void (CXEventMsg::*fun)(void),int T) //ע����Ϣ�¼�
	{
		xcgui_info_ *pInfo=(xcgui_info_*)XC_Malloc(sizeof(xcgui_info_));
		pInfo->theThis=this;
		pInfo->funs.fun_v_v=fun;

		switch(T)
		{
		case ele_event: //ע��Ԫ���¼�
			XEle_RegisterEventEx((HELE)hXCGUI,type,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_msg: //Ԫ����Ϣ
			XEle_RegisterMessageEx((HELE)hXCGUI,type,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_msg_proc: //Ԫ����Ϣ�������
			XEle_RegisterMsgProcEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_event_proc: //Ԫ���¼��������
			XEle_RegisterEventProcEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case wnd_msg: //ע�ᴰ����Ϣ
			XWnd_RegisterMessageEx((HWINDOW)hXCGUI,type,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case wnd_msg_nc: //ע�ᴰ���߼��Ϸǿͻ�����Ϣ
			XWnd_RegisterNCMessageEx((HWINDOW)hXCGUI,type,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case wnd_msg_proc:
			XWnd_RegisterMsgProcEx((HWINDOW)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_scrollView_draw: //������ͼ����
			XSView_SetDrawScrollViewEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_list_drawItem: //�б����Ի�
			XList_SetUserDrawItemEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_list_drawItemHeader: //�б�ͷ�����
			XList_SetUserDrawItemHeaderEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_tree_drawItem: //�����Ի�
			XTree_SetUserDrawItemEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_listBox_drawItem://�б�����Ի�
			XListBox_SetUserDrawItemEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_listView_drawItem: //�б���ͼ���Ի�
			XListView_SetUserDrawItemEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_listView_drawGroup: //�б���ͼ���Ի�
			XListView_SetUserDrawGroupEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_menu_drawItem: //�˵����Ի�
			XMenu_SetUserDrawItemEx((HMENUX)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_menu_drawBG:
			XMenu_SetUserDrawBGEx((HMENUX)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_menu_updateUI:
			XMenu_SetUserUpdateUIEx((HMENUX)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		};
	}
	static BOOL CALLBACK OnEventAndMsg(eventOrMsg_ *pEvent,xcgui_fun_type funType)//�¼��ص�
	{
		xcgui_info_ *info=(xcgui_info_*)pEvent->pClass_fun;
		BOOL bResult=FALSE;
		switch(funType)
		{
			//////////////////////////////////////////////////
		case xc_fun_b_e_e_i_i:
			bResult=(info->theThis->*info->funs.fun_b_e_e_i_i)(pEvent->hEle,pEvent->hEventEle,pEvent->wParam,pEvent->lParam);
			break;
		case xc_fun_b_e_e_i:
			bResult=(info->theThis->*info->funs.fun_b_e_e_i)(pEvent->hEle,pEvent->hEventEle,pEvent->wParam);
			break;
		case xc_fun_b_e_e:
			bResult=(info->theThis->*info->funs.fun_b_e_e)(pEvent->hEle,pEvent->hEventEle);
			break;
		case xc_fun_b_e_e_pb:
			bResult=(info->theThis->*info->funs.fun_b_e_e_pb)(pEvent->hEle,pEvent->hEventEle,(BOOL*)&pEvent->wParam);
			break;
		case xc_fun_b_e_e_i_pb:
			bResult=(info->theThis->*info->funs.fun_b_e_e_i_pb)(pEvent->hEle,pEvent->hEventEle,pEvent->wParam,(BOOL*)pEvent->lParam);
			break;
		case xc_fun_b_e_e_b:
			bResult=(info->theThis->*info->funs.fun_b_e_e_b)(pEvent->hEle,pEvent->hEventEle,(BOOL)pEvent->wParam);
			break;
		case xc_fun_b_e_e_i_pt:
			bResult=(info->theThis->*info->funs.fun_b_e_e_i_p)(pEvent->hEle,pEvent->hEventEle,pEvent->wParam,(POINT*)pEvent->lParam);
			break;
		case xc_fun_b_e_e_i_b:
			bResult=(info->theThis->*info->funs.fun_b_e_e_i_b)(pEvent->hEle,pEvent->hEventEle,pEvent->wParam,pEvent->lParam?TRUE:FALSE);
			break;
		case xc_fun_b_e_e_b_b:
			bResult=(info->theThis->*info->funs.fun_b_e_e_b_b)(pEvent->hEle,pEvent->hEventEle,pEvent->wParam?TRUE:FALSE,pEvent->lParam?TRUE:FALSE);
			break;
		case xc_fun_b_e_e_w_e:
			bResult=(info->theThis->*info->funs.fun_b_e_e_w_e)(pEvent->hEle,pEvent->hEventEle,(HWINDOW)pEvent->wParam,(HELE)pEvent->lParam);
			break;
		case xc_fun_b_e_e_listView_dragInsert:
			bResult=(info->theThis->*info->funs.fun_b_e_e_listViewDragInsert)(pEvent->hEle,pEvent->hEventEle,(listView_dragInsert_*)pEvent->wParam);
			break;
			/////////////////////////////////////////////////////////
		case xc_fun_v_e:
			(info->theThis->*info->funs.fun_v_e)(pEvent->hEle);
			break;
		case xc_fun_b_e_i_i_i:
			bResult=(info->theThis->*info->funs.fun_b_e_i_i_i)(pEvent->hEle,pEvent->xint,pEvent->wParam,pEvent->lParam);
			break;
		case xc_fun_b_e_i_i:
			bResult=(info->theThis->*info->funs.fun_b_e_i_i)(pEvent->hEle,pEvent->wParam,pEvent->lParam);
			break;
		case xc_fun_b_e_i_pt:
			bResult=(info->theThis->*info->funs.fun_b_e_i_p)(pEvent->hEle,pEvent->wParam,(POINT*)pEvent->lParam);
			break;
		case xc_fun_b_e_pt:
			bResult=(info->theThis->*info->funs.fun_b_e_p)(pEvent->hEle,(POINT*)pEvent->wParam);
			break;
		case xc_fun_b_e_hdraw:
			bResult=(info->theThis->*info->funs.fun_b_e_hdraw)(pEvent->hEle,(HDRAW)pEvent->wParam);
			break;
		case xc_fun_b_w_hdraw:
			bResult=(info->theThis->*info->funs.fun_b_w_hdraw)(pEvent->hWindow,(HDRAW)pEvent->wParam);
			break;
		case xc_fun_b_w:
			bResult=(info->theThis->*info->funs.fun_b_w)(pEvent->hWindow);
			break;
		case xc_fun_b_w_i_pt:
			bResult=(info->theThis->*info->funs.fun_b_w_i_p)(pEvent->hWindow,pEvent->wParam,(POINT*)pEvent->lParam);
			break;
		case xc_fun_b_w_i_size:
			bResult=(info->theThis->*info->funs.fun_b_w_i_size)(pEvent->hWindow,pEvent->wParam,(SIZE*)pEvent->lParam);
			break;
		case xc_fun_b_w_i_i:
			bResult=(info->theThis->*info->funs.fun_b_w_i_i)(pEvent->hWindow,pEvent->wParam,pEvent->lParam);
			break;
		case xc_fun_b_w_pt:
			bResult=(info->theThis->*info->funs.fun_b_w_p)(pEvent->hWindow,(POINT*)pEvent->wParam);
			break;
		case xc_fun_b_w_e:
			bResult=(info->theThis->*info->funs.fun_b_w_e)(pEvent->hWindow,(HELE)pEvent->wParam);
			break;
		case xc_fun_b_w_hwnd:
			bResult=(info->theThis->*info->funs.fun_b_w_hwnd)(pEvent->hWindow,(HWND)pEvent->wParam);
			break;
		case xc_fun_b_w_i:
			bResult=(info->theThis->*info->funs.fun_b_w_i)(pEvent->hWindow,pEvent->wParam);
			break;
			//////////////////////////////////////////////////////
		case xc_fun_v_e_list_item:
			(info->theThis->*info->funs.fun_v_e_list)(pEvent->hEle,(list_drawItem_*)pEvent->wParam);
			break;
		case xc_fun_v_e_list_header:
			(info->theThis->*info->funs.fun_v_e_listHeader)(pEvent->hEle,(listHeader_drawItem_*)pEvent->wParam);
			break;
		case xc_fun_v_e_tree:
			(info->theThis->*info->funs.fun_v_e_tree)(pEvent->hEle,(tree_drewItem_*)pEvent->wParam);
			break;
		case xc_fun_v_e_listBox:
			(info->theThis->*info->funs.fun_v_e_listBox)(pEvent->hEle,(listBox_drawItem_*)pEvent->wParam);
			break;
		case xc_fun_v_e_listView_item:
			(info->theThis->*info->funs.fun_v_e_listView)(pEvent->hEle,(listView_drawItem_*)pEvent->wParam);
			break;
		case xc_fun_v_e_listView_group:
			(info->theThis->*info->funs.fun_v_e_listViewGroup)(pEvent->hEle,(listView_drawGroup_*)pEvent->wParam);
			break;
		case xc_fun_v_x_menu_item:
			(info->theThis->*info->funs.fun_v_x_menu_drawItem)(pEvent->hMenu,(menu_drawItem_*)pEvent->wParam);
			break;
		case xc_fun_v_x_menu_bg:
			(info->theThis->*info->funs.fun_v_x_menu_drawBG)(pEvent->hMenu,(menu_drawBG_*)pEvent->wParam);
			break;
		case xc_fun_v_x_menu_i:
			(info->theThis->*info->funs.fun_v_x_menu_updateUI)(pEvent->hMenu,pEvent->wParam);
			break;
		}
		return bResult;
	}
};

#endif //XCGUI_PLUS


//������ӵ���API����////////////////////////////////////////////////////////

XC_API HWINDOW WINAPI XC_LoadXML_Window(wchar_t *pFileName,HXMLRES hXmlRes=NULL,HWND hWndParent=NULL);
XC_API HWINDOW WINAPI XC_LoadXML_WindowRes(int resID,wchar_t *pType,HXMLRES hXmlRes=NULL,HWND hWndParent=NULL);
XC_API BOOL WINAPI XC_LoadXML_Page(HXCGUI hParent,wchar_t *pFileName,HXMLRES hXmlRes=NULL);
XC_API BOOL WINAPI XC_LoadXML_PageRes(HXCGUI hParent,int resID,wchar_t *pType,HXMLRES hXmlRes=NULL);
XC_API BOOL WINAPI XC_LoadXML_Style(HWINDOW hWindow,wchar_t *pFileName,HXMLRES hXmlRes=NULL);
XC_API BOOL WINAPI XC_LoadXML_StyleRes(HWINDOW hWindow,int resID,wchar_t *pType,HXMLRES hXmlRes=NULL); //����Դ����
XC_API HXMLRES WINAPI XXmlRes_Load(wchar_t *pFileName);
XC_API HXMLRES WINAPI XXmlRes_LoadRes(int resID,wchar_t *pType);//��VC��Դ�ļ��м���
XC_API void WINAPI XXmlRes_Destroy(HXMLRES hXmlRes);
XC_API int WINAPI XXmlRes_FindId(HXMLRES hXmlRes,wchar_t *pName);
XC_API void WINAPI XXmlRes_FindImage(HXMLRES hXmlRes,wchar_t *pName,out_ wchar_t *pOut,int outLen);
XC_API void WINAPI XXmlRes_FindString(HXMLRES hXmlRes,wchar_t *pName,out_ wchar_t *pOut,int outLen);
XC_API HIMAGE WINAPI XXmlRes_FildHIMAGE(HXMLRES hXmlRes,wchar_t *pName);
XC_API HARRAY WINAPI XArray_Create(); //����
XC_API void WINAPI XArray_Destroy(HARRAY hArray); //����
XC_API int  WINAPI XArray_Add(HARRAY hArray,void *pElement);//����Ԫ�ص�ĩβ
XC_API void WINAPI XArray_AddFirst(HARRAY hArray,void *pElement); //���ӵ���ͷ
XC_API BOOL WINAPI XArray_insert(HARRAY hArray,void *pElement,int index); //���뵽ָ��λ��
XC_API void WINAPI XArray_DeleteIndex(HARRAY hArray,int index);
XC_API void WINAPI XArray_Delete(HARRAY hArray,void *pElement);
XC_API void WINAPI XArray_DeleteEnd(HARRAY hArray,int index); //ɾ��ĩβ����
XC_API void WINAPI XArray_DeleteRange(HARRAY hArray,int begin,int end);
XC_API void WINAPI XArray_DeleteAll(HARRAY hArray);
XC_API void WINAPI XArray_SetAt(HARRAY hArray,int index,void *pElement);
XC_API void* WINAPI XArray_GetAt(HARRAY hArray,int index);
XC_API int WINAPI XArray_GetCount(HARRAY hArray);
XC_API HARRAY_ITERATOR WINAPI XArrayIterator_Create(HARRAY hArray,BOOL bType=TRUE);  //����������
XC_API void* WINAPI XArrayIterator_GetAt(HARRAY_ITERATOR hArray_Iterator);
XC_API void  WINAPI XArrayIterator_Destroy(HARRAY_ITERATOR hArray_Iterator);
XC_API HELE WINAPI XBtn_Create(int x, int y, int cx, int cy,wchar_t *pTitle=NULL,HXCGUI hParent=NULL);  //������ť
XC_API wchar_t * WINAPI XBtn_GetText(HELE hEle);  //��ȡ�ı�
XC_API void  WINAPI XBtn_SetText(HELE hEle,wchar_t *pText);
XC_API void WINAPI XBtn_SetCheck(HELE hEle,BOOL bCheck);
XC_API BOOL WINAPI XBtn_IsCheck(HELE hEle); //��ť�Ƿ�ѡ��
XC_API int  WINAPI XBtn_GetState(HELE hEle);
XC_API void WINAPI XBtn_SetImageLeave(HELE hEle,HIMAGE hImage=NULL);  //����뿪ʱͼƬ
XC_API void WINAPI XBtn_SetImageStay(HELE hEle,HIMAGE hImage=NULL);   //���ͣ��ʱͼƬ
XC_API void WINAPI XBtn_SetImageDown(HELE hEle,HIMAGE hImage=NULL);   //��갴��ʱͼƬ
XC_API void WINAPI XBtn_SetImageCheck(HELE hEle,HIMAGE hImage=NULL);  //ѡ��ʱͼƬ
XC_API void WINAPI XBtn_SetImageDisable(HELE hEle,HIMAGE hImage=NULL); //��ť����״̬ͼƬ
XC_API void WINAPI XBtn_SetTextAlign(HELE hEle,int flag); //�����ı�����
XC_API void WINAPI XBtn_SetIcon(HELE hEle,HIMAGE hImage); //����ͼ��
XC_API void WINAPI XBtn_SetIconAlign(HELE hEle,int align);
XC_API void WINAPI XBtn_EnableCursorHand(HELE hEle,BOOL bEnable); //���ͣ��,����Ϊ����
XC_API void WINAPI XBtn_EnableAnimation(HELE hEle,BOOL bEnable,BOOL bLoopPlay=FALSE);
XC_API void WINAPI XBtn_AddAnimationFrame(HELE hEle,HIMAGE hImage,UINT uElapse);
XC_API void WINAPI XBtn_SetOffset(HELE hEle,int x,int y); //������������ƫ����
XC_API HELE WINAPI XCheck_Create(int x, int y, int cx, int cy,wchar_t *pTitle=NULL,HXCGUI hParent=NULL);
XC_API void WINAPI XCheck_SetImageLeave_UnCheck(HELE hEle,HIMAGE hImage);   //����뿪ʱͼƬ  δѡ��
XC_API void WINAPI XCheck_SetImageStay_UnCheck(HELE hEle,HIMAGE hImage);    //���ͣ��ʱͼƬ  δѡ��
XC_API void WINAPI XCheck_SetImageDown_UnCheck(HELE hEle,HIMAGE hImage);    //��갴��ʱͼƬ  δѡ��
XC_API void WINAPI XCheck_SetImageDisable_UnCheck(HELE hEle,HIMAGE hImage); //��ť����״̬ͼƬ  δѡ��
XC_API void WINAPI XCheck_SetImageLeave_Check(HELE hEle,HIMAGE hImage);   //����뿪ʱͼƬ   ѡ��
XC_API void WINAPI XCheck_SetImageStay_Check(HELE hEle,HIMAGE hImage);    //���ͣ��ʱͼƬ   ѡ��
XC_API void WINAPI XCheck_SetImageDown_Check(HELE hEle,HIMAGE hImage);    //��갴��ʱͼƬ   ѡ��
XC_API void WINAPI XCheck_SetImageDisable_Check(HELE hEle,HIMAGE hImage); //��ť����״̬ͼƬ  ѡ��
XC_API HELE WINAPI XCHColor_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API COLORREF WINAPI XCHColor_GetColor(HELE hEle); //��ȡ��ɫRGBֵ
XC_API void WINAPI XCHColor_SetColor(HELE hEle,COLORREF color);//������ɫ
XC_API HELE WINAPI XComboBox_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API BOOL WINAPI XComboBox_AddString(HELE hEle,wchar_t *pText,int data=0);  //����һ���ַ�������Ͽ�
XC_API void WINAPI XComboBox_DeleteItem(HELE hEle,int index);//ɾ����
XC_API void WINAPI XComboBox_DeleteItemAll(HELE hEle);  //ɾ��������
XC_API void WINAPI XComboBox_EnableEdit(HELE hEle,BOOL bEdit);  //�����༭����
XC_API void WINAPI XComboBox_SetSelectItem(HELE hEle,int index);  //����ѡ����
XC_API void WINAPI XComboBox_SetText(HELE hEle,wchar_t *pText);     //���ñ༭������
XC_API void WINAPI XComboBox_SetItemHeight(HELE hEle,int height); //���������б����
XC_API void WINAPI XComboBox_SetListHeight(HELE hEle,int height);   //���������б�߶�
XC_API void WINAPI XComboBox_SetButtonWidth(HELE hEle,int width); //����������ť���
XC_API void WINAPI XComboBox_SetItemData(HELE hEle,int index,int data);
XC_API int  WINAPI XComboBox_GetButtonWidth(HELE hEle); //��ȡ������ť���
XC_API void WINAPI XComboBox_GetText(HELE hEle,wchar_t *pOut,int len);  //��ȡ�༭���ı�
XC_API int  WINAPI XComboBox_GetItemHeight(HELE hEle);  //��ȡ���
XC_API int  WINAPI XComboBox_GetListHeight(HELE hEle); //��ȡ�����б�߶�
XC_API wchar_t* WINAPI XComboBox_GetItemText(HELE hEle,int index); //��ȡ�����б��ı�
XC_API int  WINAPI XComboBox_GetSelectItem(HELE hEle);  //��ȡ��ǰѡ��������
XC_API int WINAPI XComboBox_GetItemData(HELE hEle,int index);
XC_API int WINAPI XComboBox_GetItemCount(HELE hEle); //��ȡ������
XC_API void WINAPI XComboBox_SetImageLeave(HELE hEle,HIMAGE hImage=NULL); //����뿪
XC_API void WINAPI XComboBox_SetImageStay(HELE hEle,HIMAGE hImage=NULL); //���ͣ��
XC_API void WINAPI XComboBox_SetImageDown(HELE hEle,HIMAGE hImage=NULL); //��갴��
XC_API void WINAPI XDraw_FillSolidRect(HDC hdc,RECT *pRect,COLORREF clr);
XC_API BOOL WINAPI XDraw_GradientFill2(HDC hdc,COLORREF color1,COLORREF color2,RECT *pRect,int mode);
XC_API BOOL WINAPI XDraw_GradientFill4(HDC hdc,COLORREF color1,COLORREF color2,COLORREF colo3,COLORREF color4,RECT *pRect,int mode);
XC_API void WINAPI XDraw_Check(HDC hdc,int x,int y,COLORREF color,BOOL bCheck);
XC_API void WINAPI XDraw_HImage(HDC hdc,HIMAGE hImage,int x,int y);
XC_API void WINAPI XDraw_HImageStretch(HDC hdc,HIMAGE hImage,int x,int y,int width,int height);
XC_API void WINAPI XDraw_HImageSuper(HDC hdc,HIMAGE hImage,RECT *pRect);
XC_API void WINAPI XDraw_HImageEx(HDC hdc,HIMAGE hImage,int x,int y,int width,int height,int srcX,int srcY);
XC_API void WINAPI XDraw_HImageExTile(HDC hdc,HIMAGE hImage,RECT *pRect,int flag=0);
XC_API void WINAPI XDraw_HImageAdaptive(HDC hdc,HIMAGE hImage,RECT *pRect);
XC_API HDRAW WINAPI XDraw_Create_(HDC hdc); //����
XC_API void  WINAPI XDraw_Destroy_(HDRAW hDraw); //����
XC_API void  WINAPI XDraw_SetOffset_(HDRAW hDraw,int x,int y); //��������ƫ����
XC_API void  WINAPI XDraw_RestoreGDIOBJ_(HDRAW hDraw);  //��ԭ״̬,�ͷ��û��󶨵�GDI����
XC_API HDC   WINAPI XDraw_GetHDC_(HDRAW hDraw);
XC_API void  WINAPI XDraw_GetOffset_(HDRAW hDraw,out_ int *pX,out_ int *pY); //��ȡ����ƫ����
XC_API COLORREF WINAPI XDraw_SetTextColor_(HDRAW hDraw,COLORREF crColor);
XC_API HBRUSH WINAPI XDraw_CreateSolidBrush_(HDRAW hDraw,COLORREF crColor);
XC_API HPEN WINAPI XDraw_CreatePen_(HDRAW hDraw,int fnPenStyle,int nWidth,COLORREF crColor);
XC_API HRGN WINAPI XDraw_CreateRoundRectRgn_(HDRAW hDraw,int nLeftRect,int nTopRect,int nRightRect,int nBottomRect,int nWidthEllipse,int nHeightEllipse);
XC_API HRGN WINAPI XDraw_CreatePolygonRgn_(HDRAW hDraw,POINT *pPt,int cPoints,int fnPolyFillMode);
XC_API HGDIOBJ WINAPI XDraw_SelectObject_(HDRAW hDraw,HGDIOBJ hObj);
XC_API int WINAPI XDraw_SelectClipRgn_(HDRAW hDraw,HRGN hRgn);
XC_API BOOL WINAPI XDraw_DeleteObject_(HDRAW hDraw,HGDIOBJ hObj);
XC_API int WINAPI XDraw_FillRect_(HDRAW hDraw,RECT *pRect,HBRUSH hbr);
XC_API BOOL WINAPI XDraw_FillRgn_(HDRAW hDraw,HRGN hrgn,HBRUSH hbr);
XC_API void WINAPI XDraw_FillSolidRect_(HDRAW hDraw,RECT *pRect,COLORREF clr);
XC_API BOOL WINAPI XDraw_GradientFill2_(HDRAW hDraw,COLORREF color1,COLORREF color2, RECT *pRect,int mode);
XC_API BOOL WINAPI XDraw_GradientFill4_(HDRAW hDraw,COLORREF color1,COLORREF color2,COLORREF color3,COLORREF color4,RECT *pRect,int mode);
XC_API BOOL WINAPI XDraw_FrameRgn_(HDRAW hDraw,HRGN hrgn,HBRUSH hbr,int nWidth,int nHeight);
XC_API int  WINAPI XDraw_FrameRect_(HDRAW hDraw,RECT *pRect,HBRUSH hbr);
XC_API BOOL WINAPI XDraw_FocusRect_(HDRAW hDraw,RECT *pRect);
XC_API BOOL WINAPI XDraw_Rectangle_(HDRAW hDraw,int nLeftRect,int nTopRect,int nRightRect,int nBottomRect);
XC_API BOOL WINAPI XDraw_MoveToEx_(HDRAW hDraw,int X,int Y,LPPOINT lpPoint=NULL);
XC_API BOOL WINAPI XDraw_LineTo_(HDRAW hDraw,int nXEnd,int nYEnd);
XC_API void WINAPI XDraw_Check_(HDRAW hDraw,int x,int y,COLORREF color,BOOL bCheck);
XC_API void WINAPI XDraw_Dottedline_(HDRAW hDraw,int x,int y,int length,COLORREF color,BOOL bHorizontal=TRUE);  //��������
XC_API COLORREF WINAPI XDraw_SetPixel_(HDRAW hDraw,int X,int Y,COLORREF crColor);
XC_API BOOL WINAPI XDraw_DrawIconEx_(HDRAW hDraw,int xLeft,int yTop,HICON hIcon,int cxWidth,int cyWidth,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw, UINT diFlags);
XC_API BOOL WINAPI XDraw_BitBlt_(HDRAW hDrawDest,int nXDest,int nYDest,int nWidth,int nHeight,HDC hdcSrc,int nXSrc,int nYSrc,DWORD dwRop);
XC_API BOOL WINAPI XDraw_BitBlt2_(HDRAW hDrawDest,int nXDest,int nYDest,int nWidth,int nHeight,HDRAW hDrawSrc,int nXSrc,int nYSrc,DWORD dwRop);
XC_API void WINAPI XDraw_TriangularArrow(HDRAW hDraw,HBRUSH hBrush,int align,int x,int y,int width,int height);
XC_API void WINAPI XDraw_HImage_(HDRAW hDraw,HIMAGE hImage,int x,int y);
XC_API void WINAPI XDraw_HImage2_(HDRAW hDraw,HIMAGE hImage,int x,int y,int width,int height);
XC_API void WINAPI XDraw_HImageStretch_(HDRAW hDraw,HIMAGE hImage,int x,int y,int width,int height);
XC_API void WINAPI XDraw_HImageAdaptive_(HDRAW hDraw,HIMAGE hImage,RECT *pRect);
XC_API void WINAPI XDraw_HImageExTile_(HDRAW hDraw,HIMAGE hImage,RECT *pRect,int flag=0);
XC_API void WINAPI XDraw_HImageSuper_(HDRAW hDraw,HIMAGE hImage,RECT *pRect);
XC_API void WINAPI XDraw_HImageSuper2_(HDRAW hDraw,HIMAGE hImage,RECT *pRcDest,RECT *pSrcRect);
XC_API int WINAPI XDraw_DrawText_(HDRAW hDraw,wchar_t * lpString,int nCount,RECT* lpRect,UINT uFormat);
XC_API BOOL WINAPI XDraw_TextOut_(HDRAW hDraw,int nXStart,int nYStart,wchar_t * lpString,int cbString);
XC_API HELE WINAPI XEdit_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XEdit_EnableMultiLine(HELE hEle,BOOL b);  //���ö�������
XC_API void WINAPI XEdit_EnablePassBox(HELE hEle,BOOL bPass); //���������
XC_API void WINAPI XEdit_EnableNumber(HELE hEle,BOOL bNumber); //ֻ����������
XC_API void WINAPI XEdit_EnablePopupMenu(HELE hEle,BOOL bEnable);  //��������Ҽ��˵�
XC_API void WINAPI XEdit_InsertText(HELE hEle,wchar_t *pText,int row=-1,int column=-1); //�����ı�,row=-1ĩβ��,column=-1ĩβ��;
XC_API void WINAPI XEdit_DeleteSelectText(HELE hEle); //ɾ��ѡ���ı�,��ֻ������ʱ,Ҳ����ɾ���ı�
XC_API void WINAPI XEdit_SetText(HELE hEle,wchar_t *pText);  //�����ı�
XC_API void WINAPI XEdit_SetInt(HELE hEle,int value);  //������������
XC_API void WINAPI XEdit_SetReadOnly(HELE hEle,BOOL bRead);  //����ֻ���ı�
XC_API void WINAPI XEdit_SetTextSpacingLeft(HELE hEle,int spacing);  //���������������
XC_API void WINAPI XEdit_SetTextSpacingTop(HELE hEle,int spacing);  //���������϶�����
XC_API void WINAPI XEdit_SetPos(HELE hEle,int line,int column); //���ò����λ��
XC_API void WINAPI XEdit_SetCaretWidth(HELE hEle,int width); //���ñ༭���������
XC_API void WINAPI XEdit_SetBackspace(HELE hEle);  //�˸�
XC_API void WINAPI XEdit_SetSelectTextBkColor(HELE hEle,COLORREF color);//����ѡ���ı�������ɫ
XC_API void WINAPI XEdit_GetSelectText(HELE hEle,wchar_t *pOut,int len);  //��ȡѡ������
XC_API int  WINAPI XEdit_GetTextLength(HELE hEle); //��ȡ���ݳ���
XC_API void WINAPI XEdit_GetText(HELE hEle,wchar_t *pOut,int len); //��ȡ�ı�
XC_API int  WINAPI XEdit_GetInt(HELE hEle); //��ȡ��������
XC_API int WINAPI XEdit_GetRowCount(HELE hEle);   //��ȡ������
XC_API int WINAPI XEdit_GetColumnCount(HELE hEle,int row); //��ȡָ�����ַ���,row=-1ĩβ��;
XC_API int WINAPI XEdit_GetCurrentRow(HELE hEle);  //��ȡ�����λ�õ�ǰ��
XC_API int WINAPI XEdit_GetCurrentColumn(HELE hEle); //��ȡ�����λ�õ�ǰ��
XC_API BOOL WINAPI XEdit_IsEmpty(HELE hEle); //�ж������Ƿ�Ϊ��
XC_API void WINAPI XEdit_DeleteAll(HELE hEle);  //���  ɾ�������ı�
XC_API void WINAPI XEdit_Menu_Cut(HELE hEle);        //����  ɾ��ѡ����ı�,�����ı����������а���
XC_API void WINAPI XEdit_Menu_Copy(HELE hEle);       //����  ����ѡ����ı������а���
XC_API void WINAPI XEdit_Menu_Paste(HELE hEle);      //ճ��  �����а��е��ı����뵱ǰ���λ��
XC_API void WINAPI XEdit_Menu_Clear(HELE hEle);      //ɾ��  ɾ��ѡ����ı�,��ֻ������ʱ�޷�ɾ���ı�
XC_API void WINAPI XEdit_Menu_SelectAll(HELE hEle);  //ȫѡ  ѡ�������ı�
XC_API void WINAPI XEdit_Menu_DeleteAll(HELE hEle);  //���  ɾ�������ı�
XC_API void WINAPI XEdit_SetImageLeave(HELE hEle,HIMAGE hImage=NULL); //����뿪
XC_API void WINAPI XEdit_SetImageStay(HELE hEle,HIMAGE hImage=NULL); //���ͣ��
XC_API HELE WINAPI XEditFile_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XEditFile_SetOpenFileType(HELE hEle,wchar_t *pType); //���ô��ļ�����
XC_API void WINAPI XEditFile_SetDefaultFile(HELE hEle,wchar_t *pFile); //����Ĭ��Ŀ¼�ļ�
XC_API void WINAPI XEditFile_SetRelativeDir(HELE hEle,wchar_t *pDir); //TODO:�������·��
XC_API void WINAPI XEle_RegisterEventEx(HELE hEle,int type,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);
XC_API void WINAPI XEle_RegisterMessageEx(HELE hEle,int message,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //ע����Ϣ
XC_API void WINAPI XEle_RegisterMsgProcEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);    //ע��Ԫ����Ϣ�������
XC_API void WINAPI XEle_RegisterEventProcEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);  //ע���¼����ع��˺���
XC_API HELE WINAPI XEle_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL); //����
XC_API BOOL WINAPI XEle_Destroy(HELE hEle);  //����
XC_API void WINAPI XEle_RegisterMessage(HELE hEle,int message,void *pFun); 
XC_API void WINAPI XEle_RegisterEvent(HELE hEle,int type,void *pFun);
XC_API void WINAPI XEle_RegisterMsgProc(HELE hEle,pFunEleMsgProc pFun);    //ע��Ԫ����Ϣ�������
XC_API void WINAPI XEle_RegisterEventProc(HELE hEle,pFunEleEventProc pFun);  //ע��Ԫ���¼��������
XC_API void WINAPI XEle_SetBkTransparent(HELE hEle,BOOL bTran);   //����Ԫ�ر���͸��
XC_API void WINAPI XEle_SetFocus(HELE hEle,BOOL bFocus); //���ý���
XC_API void WINAPI XEle_SetId(HELE hEle,int id);
XC_API void WINAPI XEle_SetFont(HELE hEle,HFONTX hFontX);
XC_API HFONTX WINAPI XEle_GetFont(HELE hEle); //��ȡ����
XC_API BOOL WINAPI XEle_SetZOrder(HELE hEle,HELE hDestEle=NULL,int flag=XC_ZORDER_TOP,int index=NULL);
XC_API void WINAPI XEle_SetBkColor(HELE hEle,COLORREF color); //���ñ�����ɫ
XC_API COLORREF WINAPI XEle_GetBkColor(HELE hEle); //��ȡ������ɫ
XC_API void WINAPI XEle_SetBorderColor(HELE hEle,COLORREF color); //���ñ߿���ɫ
XC_API void WINAPI XEle_SetToolTips(HELE hEle,wchar_t *pText); //���ù�����ʾ����
XC_API void WINAPI XEle_SetCapture(HELE hEle);   //����Ԫ����겶��
XC_API wchar_t* WINAPI XEle_GetTooltips(HELE hEle);  //��ȡ������ʾ����
XC_API HELE WINAPI XEle_GetParentEle(HELE hEle);  //��ȡ��Ԫ�ؾ��
XC_API int  WINAPI XEle_GetChildCout(HELE hEle);  //��ȡ��Ԫ������
XC_API HELE WINAPI XEle_GetChildByIndex(HELE hEle,int index);	//��ȡָ����Ԫ��
XC_API HWND WINAPI XEle_GetHWnd(HELE hEle);  //��ȡ���ھ��
XC_API HWINDOW WINAPI XEle_GetHWindow(HELE hEle); //��ȡ������Դ���
XC_API int  WINAPI XEle_GetUserData(HELE hEle);  //��ȡ�û�����
XC_API int WINAPI XEle_GetId(HELE hEle);
XC_API void WINAPI XEle_ReleaseCapture(HELE hEle);   //�ͷ�Ԫ����겶��
XC_API void WINAPI XEle_EnableEle(HELE hEle,BOOL bEnable); //Ԫ���Ƿ���Ч
XC_API void WINAPI XEle_EnableFocus(HELE hEle,BOOL bFocus); //��������
XC_API void WINAPI XEle_EnableDrawFocus(HELE hEle,BOOL bFocus); //�Ƿ���ƽ���
XC_API void WINAPI XEle_EnableToolTips(HELE hEle,BOOL bTips);  //���ù�����ʾ
XC_API void WINAPI XEle_EnableBorder(HELE hEle,BOOL bEnable); //���Ʊ߿�
XC_API void WINAPI XEle_EnableTransparentChannel(HELE hEle,BOOL bEnable);
XC_API BOOL WINAPI XEle_AddEle(HELE hEle,HELE hNewEle,int flag=XC_ADDELE_END,HELE hDestEle=0,int index=0); //���Ԫ��
XC_API void WINAPI XEle_RemoveEle(HELE hEle);   //�Ƴ�Ԫ��,��������
XC_API void WINAPI XEle_RedrawEle(HELE hEle,BOOL bImmediately=FALSE); //�ػ�Ԫ��
XC_API void WINAPI XEle_RedrawRect(HELE hEle,RECT *pRect); //Ԫ���ػ�ָ������
XC_API void WINAPI XEle_ShowEle(HELE hEle,BOOL bShow);
XC_API BOOL WINAPI XEle_IsBkTransparent(HELE hEle); //Ԫ�ر����Ƿ�͸��
XC_API BOOL WINAPI XEle_IsFocus(HELE hEle); //Ԫ���Ƿ�ӵ�н���
XC_API BOOL WINAPI XEle_IsShowEle(HELE hEle); //Ԫ���Ƿ���ʾ
XC_API BOOL WINAPI XEle_IsHitChildEle(HELE hEle,POINT *pPt); //�ж��Ƿ�������Ԫ����
XC_API BOOL WINAPI XEle_IsChildEle(HELE hEle,HELE hChild);  //�ж�ָ��Ԫ���Ƿ�Ϊ��Ԫ��
XC_API void WINAPI XEle_SetUserData(HELE hEle,int data);  //�����û�����
XC_API UINT WINAPI XEle_SetTimerEx(HELE hEle,UINT nIDEvent,UINT uElapse,int userData=0);
XC_API BOOL WINAPI XEle_KillTimerEx(HELE hEle,UINT nIDEvent);
XC_API void WINAPI XEle_SetRect(HELE hEle,in_ RECT *pRect,BOOL bRedraw=FALSE);
XC_API void WINAPI XEle_GetClientRect(HELE hEle,out_ RECT *pRect);   //Ԫ�ؿͻ������� xy(0,0) ,���Ԫ���б߿�,�����߿�����
XC_API void WINAPI XEle_GetRect(HELE hEle,out_ RECT *pRect);         //���ڸ�Ԫ������
XC_API void WINAPI XEle_GetWndClientRect(HELE hEle,out_ RECT *pRect); //Ԫ�ػ��ڴ��ڿͻ�������(�������ǿͻ���)
XC_API void WINAPI XEle_GetNCWndRect(HELE hEle,out_ RECT *pRect); //���ڴ��ڷǿͻ�������(�����ǿͻ���)
XC_API void WINAPI XEle_PointToParent(HELE hEle,in_out_ POINT *pPt); 
XC_API void WINAPI XEle_PointToWndClient(HELE hEle,in_out_ POINT *pPt);     //Ԫ�������ת�������ڿͻ��������(�������ǿͻ���)
XC_API void WINAPI XEle_PointToNCWnd(HELE hEle,in_out_ POINT *pPt);
XC_API void WINAPI XEle_PointNCWndToEle(HELE hEle,in_out_ POINT *pPt);
XC_API void WINAPI XEle_PointWndClientToEle(HELE hEle,in_out_ POINT *pPt);
XC_API void WINAPI XEle_RectToWndClient(HELE hEle,in_out_ RECT *pRect);
XC_API void WINAPI XEle_RectToNCWnd(HELE hEle,in_out_ RECT *pRect);
XC_API void WINAPI XEle_SetTextColor(HELE hEle,COLORREF color); //�����ı���ɫ
XC_API COLORREF WINAPI XEle_GetTextColor(HELE hEle); //��ȡ�ı���ɫ
XC_API void WINAPI XEle_EnableMouseThrough(HELE hEle,BOOL bEnable);  //������괩͸Ԫ��
XC_API void WINAPI XEle_SetAlpha(HELE hEle,int alpha);  //����Ԫ��͸���� 0-255
XC_API HXCGUI WINAPI XFlash_Create(HWINDOW hWindow);
XC_API void  WINAPI XFlash_OpenFlashFile(HXCGUI hFlash,wchar_t *pFlashFile);
XC_API void* WINAPI XFlash_GetControl(HXCGUI hFlash);//��ȡ�ؼ��ӿ�
XC_API void  WINAPI XFlash_Destroy(HXCGUI hFlash);
XC_API HFONTX WINAPI XFont_Create(int size);//��������
XC_API HFONTX WINAPI XFont_Create2(wchar_t *pName=L"����",int size=12,BOOL bBold=FALSE,BOOL bItalic=FALSE,BOOL bUnderline=FALSE,BOOL bStrikeOut=FALSE);
XC_API HFONTX WINAPI XFont_CreateEx(LOGFONTW *pFontInfo);
XC_API void  WINAPI XFont_Destroy(HFONTX hFontX);  //��������
XC_API HFONT WINAPI XFont_GetHFONT(HFONTX hFontX);
XC_API HWINDOW WINAPI XFrameWnd_CreateWindow(int x,int y,int cx,int cy,wchar_t *pTitle,HWND hWndParent=NULL,int XCStyle=XC_SY_DEFAULT);
XC_API BOOL WINAPI XFrameWnd_AddPane(HWINDOW hWindow,HELE hPaneDest,HELE hPaneNew,align_type_ align=align_any,int scale=50);
XC_API HPANE_GROUP WINAPI XFrameWnd_MergePane(HWINDOW hWindow,HELE hPaneDest,HELE hPaneNew,int proportion=50);
XC_API BOOL WINAPI XFrameWnd_MergePaneToGroup(HWINDOW hWindow,HPANE_GROUP hGroup,HELE hPaneNew,int proportion=50); //����ϲ�����
XC_API void WINAPI XFrameWnd_AdjustLayout(HWINDOW hWindow,BOOL bFixedSize=FALSE);
XC_API void WINAPI XFrameWnd_GetLayoutAreaRect(HWINDOW hWindow,out_ RECT *pRect); //��ȡ�ͻ���������������
XC_API HELE WINAPI XFrameWnd_GetActivatePane(HWINDOW hWindow);//��ȡ��ܴ����ڼ���Ĵ���,��������������
XC_API HELE WINAPI XGif_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XGif_SetImage(HELE hEle,wchar_t  *pImageName);
XC_API void WINAPI XGif_SetImageRes(HELE hEle,int id,wchar_t *pType);
XC_API void WINAPI XGif_SetImageZip(HELE hEle,wchar_t *pZipFileName,wchar_t *pImageName,wchar_t *pPassword=NULL);
XC_API HELE WINAPI XGBox_Create(int x, int y, int cx, int cy,wchar_t *pTitle,HXCGUI hParent=NULL); //����
XC_API wchar_t* WINAPI XGBox_GetText(HELE hEle);
XC_API void WINAPI XGBox_SetText(HELE hEle,wchar_t *pText);
XC_API HIMAGE WINAPI XImage_LoadFile(wchar_t *pImageName,BOOL bStretch=FALSE);//���ļ��м���ͼƬ
XC_API HIMAGE WINAPI XImage_LoadRes(int id,wchar_t *pType,BOOL bStretch=FALSE);//����Դ�м���ͼƬ
XC_API HIMAGE WINAPI XImage_LoadZip(wchar_t *pZipFileName,wchar_t *pImageName,wchar_t *pPassword=NULL,BOOL bStretch=FALSE);//��ZIP�м���ͼƬ
XC_API HIMAGE WINAPI XImage_LoadFileAdaptive(wchar_t *pImageName,int x1,int x2,int y1,int y2);//���ļ��м���ͼƬ
XC_API HIMAGE WINAPI XImage_LoadResAdaptive(int id,wchar_t *pType,int x1,int x2,int y1,int y2);//����Դ�м���ͼƬ
XC_API HIMAGE WINAPI XImage_LoadZipAdaptive(wchar_t *pZipFileName,wchar_t *pImageName,wchar_t *pPassword,int x1,int x2,int y1,int y2);//��ZIP�м���ͼƬ
XC_API HIMAGE WINAPI XImage_LoadFileRect(wchar_t *pImageName,int x,int y,int cx,int cy);
XC_API HIMAGE WINAPI XImage_LoadFileFromExtractIcon(wchar_t *pImageName);
XC_API HIMAGE WINAPI XImage_LoadFileFromHICON(HICON hIcon);
XC_API HIMAGE WINAPI XImage_LoadFileFromHBITMAP(HBITMAP hBitmap);
XC_API BOOL WINAPI XImage_IsStretch(HIMAGE hImage);   //�Ƿ�����ͼƬ
XC_API BOOL WINAPI XImage_IsAdaptive(HIMAGE hImage);  //�Ƿ�Ϊ����ӦͼƬ
XC_API BOOL WINAPI XImage_IsTile(HIMAGE hImage);      //�Ƿ�Ϊƽ��ͼƬ
XC_API BOOL WINAPI XImage_SetDrawType(HIMAGE hImage,int type);//����ͼƬ��������
XC_API BOOL WINAPI XImage_SetDrawTypeAdaptive(HIMAGE hImage,int x1,int x2,int y1,int y2);//����ͼƬ����Ӧ
XC_API void WINAPI XImage_SetTranColor(HIMAGE hImage,COLORREF color); //����͸��ɫ
XC_API void WINAPI XImage_SetTranColorEx(HIMAGE hImage,COLORREF color,byte tranColor); //����͸��ɫ
XC_API void WINAPI XImage_EnableTranColor(HIMAGE hImage,BOOL bEnable); //����͸��ɫ
XC_API void WINAPI XImage_EnableAutoDestroy(HIMAGE hImage,BOOL bEnable); //���û�ر��Զ�����,����UIԪ�ع���ʱ��Ч
XC_API int WINAPI XImage_GetDrawType(HIMAGE hImage);
XC_API int WINAPI XImage_GetWidth(HIMAGE hImage);
XC_API int WINAPI XImage_GetHeight(HIMAGE hImage);
XC_API void WINAPI XImage_Destroy(HIMAGE hImage);
XC_API HXCGUI WINAPI XImageList_Create(int cx,int cy);
XC_API void WINAPI XImageList_Destroy(HXCGUI hImageList); //����
XC_API void WINAPI XImageList_AddImage(HXCGUI hImageList,HIMAGE hImage); //���ͼƬ
XC_API int  WINAPI XImageList_GetWidth(HXCGUI hImageList);   //��ȡͼƬ���
XC_API int  WINAPI XImageList_GetHeight(HXCGUI hImageList);  //��ȡͼƬ�߶�
XC_API int  WINAPI XImageList_GetCount(HXCGUI hImageList);   //��ȡͼƬ����
XC_API HIMAGE WINAPI XImageList_GetImage(HXCGUI hImageList,int index); //��ȡͼƬ
XC_API void WINAPI XImageList_DeleteIndex(HXCGUI hImageList,int index); //ɾ��ָ��ͼƬ
XC_API void WINAPI XImageList_DeleteAll(HXCGUI hImageList);  //ɾ��ȫ��ͼƬ
XC_API void WINAPI XImageList_DrawImage(HXCGUI hImageList,HDRAW hDraw,int index, int x, int y);
XC_API void WINAPI XImageList_DrawImage2(HXCGUI hImageList,HDRAW hDraw,int index, RECT *pRect);
XC_API void WINAPI XImageList_EnableFixedSize(HXCGUI hImageList,BOOL bEnable); //���ƹ̶���С Fixed-size
XC_API BOOL WINAPI XImageList_IsFixedSize(HXCGUI hImageList);
XC_API void WINAPI XList_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի��б���
XC_API void WINAPI XList_SetUserDrawItemHeaderEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի��б�ͷ��
XC_API HELE WINAPI XList_Create(int x,int y,int cx,int cy,HXCGUI hParent=NULL);
XC_API int WINAPI XList_AddColumn(HELE hEle,int width,wchar_t *pText,int imageId=-1); //������
XC_API int WINAPI XList_AddItem(HELE hEle,wchar_t *pText, int imageId=-1);  //������
XC_API BOOL WINAPI XList_InsertColumn(HELE hEle,int index,int width,wchar_t *pText,int imageId=-1);  //������
XC_API BOOL WINAPI XList_InsertItem(HELE hEle,int index,wchar_t *pText,int imageId=-1);  //������
XC_API BOOL WINAPI XList_SetItemText(HELE hEle,int item,int subItem,wchar_t *pText,int imageId=-1); //��������
XC_API BOOL WINAPI XList_SetColumnWidth(HELE hEle,int index, int width);   //�����п�
XC_API BOOL WINAPI XList_SetItemImage(HELE hEle,int item,int subItem,int imageId);   //��������ͼƬ
XC_API void WINAPI XList_SetImageList(HELE hEle,HXCGUI hImageList); //����ͼƬ�б�
XC_API void WINAPI XList_SetItemHeight(HELE hEle,int height);  //������߶�
XC_API void WINAPI XList_SetHeaderHeight(HELE hEle,int height); //�����б�ͷ�߶�
XC_API BOOL WINAPI XList_SetSelectItem(HELE hEle,int index);   //����ѡ����
XC_API void WINAPI XList_SetSelectItemAll(HELE hEle);     //ȫѡ
XC_API void WINAPI XList_SetSpacingLeft(HELE hEle,int spacing);  //������������
XC_API void WINAPI XList_SetSpacingRight(HELE hEle,int spacing); //���������Ҽ��
XC_API void WINAPI XList_SetItemData(HELE hEle,int index,int data);   //�����û�����
XC_API BOOL WINAPI XList_SetItemBindEle(HELE hEle,int item,int subItem,itemBindEle_ *pInfo); //��Ԫ��
XC_API void WINAPI XList_SetColumnMinWidth(HELE hEle,int index,int minWidth); //��������С���
XC_API int WINAPI XList_GetHeaderHeight(HELE hEle);        //��ȡ�б�ͷ�߶�
XC_API wchar_t* WINAPI XList_GetHeaderItemText(HELE hEle,int index);  //��ȡ�б�ͷ���ı�
XC_API int WINAPI XList_GetColumnWidth(HELE hEle,int index);     //��ȡ�п�
XC_API int WINAPI XList_GetSpacingLeft(HELE hEle);  //��ȡ��������
XC_API int WINAPI XList_GetSpacingRight(HELE hEle); //��ȡ�����Ҽ��
XC_API HXCGUI WINAPI XList_GetImageList(HELE hEle);     //��ȡͼƬ�б�
XC_API wchar_t* WINAPI XList_GetItemText(HELE hEle,int index, int subItem); //��ȡ���ı�
XC_API int WINAPI XList_GetItemImage(HELE hEle,int item,int subItem); //��ȡ����ͼƬ
XC_API int WINAPI XList_GetItemHeight(HELE hEle);       //��ȡ���
XC_API int WINAPI XList_GetItemData(HELE hEle,int index);   //�����û�����
XC_API int WINAPI XList_GetSelectCount(HELE hEle);      //��ȡѡ��������
XC_API int WINAPI XList_GetSelectItem(HELE hEle);       //��ȡѡ����
XC_API int WINAPI XList_GetSelectAllItem(HELE hEle,out_ int *pArray, int arrayLength);  //��ȡ����ѡ����
XC_API int WINAPI XList_GetItemCount(HELE hEle);        //��ȡ������
XC_API BOOL WINAPI XList_GetHeaderItemRect(HELE hEle,int item,out_ RECT *pRect); //��ȡ�б�ͷ������
XC_API BOOL WINAPI XList_GetSubItemRect(HELE hEle,int item,int sub,out_ RECT *pRect);//��ȡ��������
XC_API BOOL WINAPI XList_GetItemCheckRect(HELE hEle,int item,out_ RECT *pRect); //��ȡ��ѡ��ť����
XC_API int  WINAPI XList_GetItemBindEleCount(HELE hEle,int item,int subItem);
XC_API BOOL WINAPI XList_GetItemBindEleInfo(HELE hEle,int item,int subItem,out_ itemBindEle_ *pInfo,int index);//��ȡ������Ϣ
XC_API void WINAPI XList_CancelSelectAll(HELE hEle); //ȡ��ѡ��������
XC_API void WINAPI XList_CancelSelect(HELE hEle,int index); //ȡ��ѡ��ָ����
XC_API BOOL WINAPI XList_DeleteItem(HELE hEle,int index);  //ɾ����
XC_API BOOL WINAPI XList_DeleteColumn(HELE hEle,int index);  //ɾ����
XC_API void WINAPI XList_DeleteAllItems(HELE hEle);  //ɾ��������
XC_API void WINAPI XList_DeleteAllColumns(HELE hEle);   //ɾ��������
XC_API void WINAPI XList_EnableGrid(HELE hEle,BOOL bGrid); //����������ʽ
XC_API int  WINAPI XList_HitTest(HELE hEle,POINT *pPt);  //�����������ĸ�����,-1û�����κ�����
XC_API BOOL WINAPI XList_HitTestEx(HELE hEle,POINT *pPt,out_ int *item,out_ int *sub); //�����������ĸ����ϼ�����,-1û�����κ�����
XC_API void WINAPI XList_ShowHeader(HELE hEle,BOOL bShow);//��ʾ�����б�ͷ
XC_API void WINAPI XList_SetUserDrawItem(HELE hEle,pFunList_DrawItem pFunDrawItem); //�����û��Ի��б���
XC_API void WINAPI XList_SetUserDrawItemHeader(HELE hEle,pFunListHeader_DrawItem pFunDrawItem); //�����û��Ի��б�ͷ��
XC_API void WINAPI XList_EnableCheckBox(HELE hEle,BOOL bEnable); //���ø�ѡ��
XC_API void WINAPI XList_EnableMultilineSelect(HELE hEle,BOOL bEnable);  //���ùرն���ѡ�� XEdit_EnableMultiLine
XC_API void WINAPI XLsit_EnableLineHighlight(HELE hEle,BOOL bEnable); //���û�ر��и�����ʾ
XC_API BOOL WINAPI XList_IsItemCheck(HELE hEle,int index); //�ж���ĸ�ѡ���Ƿ�ѡ
XC_API void WINAPI XList_SetItemCheck(HELE hEle,int index, BOOL bCheck); //������ĸ�ѡ��
XC_API void WINAPI XListBox_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի��б����
XC_API HELE WINAPI XListBox_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API int  WINAPI XListBox_AddString(HELE hEle,wchar_t *pText,int imageId=-1);  //����һ���ַ������б�
XC_API BOOL WINAPI XListBox_InsertString(HELE hEle,int index,wchar_t *pText,int imageId=-1); //������
XC_API void WINAPI XListBox_EnableCheckBox(HELE hEle,BOOL bEnable); //���ø�ѡ��
XC_API void WINAPI XLsitBox_EnableLineHighlight(HELE hEle,BOOL bEnable);  //���û�ر��и�����ʾ
XC_API wchar_t* WINAPI XListBox_GetItemText(HELE hEle,int index);   //��ȡָ�����ı�
XC_API int  WINAPI XListBox_GetItemHeight(HELE hEle);              //��ȡ�и�
XC_API int  WINAPI XListBox_GetSelectItem(HELE hEle);              //��ȡѡ����
XC_API int  WINAPI XListBox_GetItemImage(HELE hEle,int index); //��ȡ��ͼ��ID
XC_API int  WINAPI XListBox_GetItemCount(HELE hEle); //��ȡ������
XC_API HXCGUI WINAPI XListBox_GetImageList(HELE hEle); //��ȡͼƬ�б�
XC_API BOOL WINAPI XListBox_GetItemRect(HELE hEle,in_ int index,out_ RECT *pRect);  //��ȡ������...
XC_API int  WINAPI XListBox_HitTest(HELE hEle,POINT *pPt);  //�����������ĸ�����,-1û�����κ�����
XC_API int  WINAPI XListBox_GetItemData(HELE hEle,int index); //��ȡ�������
XC_API void WINAPI XListBox_SetItemText(HELE hEle,int index, wchar_t *pText);  //����ָ�����ı�
XC_API void WINAPI XListBox_SetSelectItem(HELE hEle,int index);    //����ѡ����
XC_API void WINAPI XListBox_SetItemHeight(HELE hEle,int height);   //�����и�
XC_API void WINAPI XListBox_SetImageList(HELE hEle,HXCGUI hImageList); //����ͼ���б�
XC_API void WINAPI XListBox_SetItemImage(HELE hEle,int index,int imageId); //������ͼ��ID
XC_API void WINAPI XListBox_SetItemCheck(HELE hEle,int index, BOOL bCheck); //������ĸ�ѡ��
XC_API BOOL WINAPI XListBox_SetItemBindEle(HELE hEle,int index,itemBindEle_ *pInfo); //��Ԫ��
XC_API void WINAPI XListBox_SetItemData(HELE hEle,int index,int data); //�����������
XC_API void WINAPI XListBox_SetSelectItemColor(HELE hEle,COLORREF color); //����ѡ������ɫ
XC_API void WINAPI XListBox_SetItemMouseStayColor(HELE hEle,COLORREF color);//�������ͣ����������ɫ
XC_API void WINAPI XListBox_DeleteItem(HELE hEle,int index);  //ɾ����
XC_API void WINAPI XListBox_DeleteAll(HELE hEle);  //ɾ��������
XC_API BOOL WINAPI XListBox_IsItemCheck(HELE hEle,int index);      //�ж���ĸ�ѡ���Ƿ�ѡ
XC_API void WINAPI XListBox_Adjust(HELE hEle);
XC_API void WINAPI XListBox_SetUserDrawItem(HELE hEle,pFunListBox_DrawItem pFunDrawItem); //�����û��Ի��б����
XC_API void WINAPI XListView_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի���
XC_API void WINAPI XListView_SetUserDrawGroupEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի���
XC_API HELE WINAPI XListView_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API int  WINAPI XListView_AddItem(HELE hEle,wchar_t *pName,int imageID=-1,int groupIndex=-1); //������
XC_API int  WINAPI XListView_AddGroup(HELE hEle,wchar_t *pName,BOOL bExpand=TRUE); //������
XC_API int  WINAPI XListView_InsertItem(HELE hEle,int groupIndex,int itemIndex,wchar_t *pName,int imageID=-1);  //������
XC_API int  WINAPI XListView_InsertGroup(HELE hEle,int groupIndex,wchar_t *pName,BOOL bExpand=TRUE);  //������
XC_API void WINAPI XListView_SetImageList(HELE hEle,HXCGUI hImageList);
XC_API BOOL WINAPI XListView_SetItemData(HELE hEle,int groupIndex, int itemIndex,int data); //�����������
XC_API BOOL WINAPI XListView_SetGroupData(HELE hEle,int groupIndex,int data); //�����������
XC_API BOOL WINAPI XListView_SetSelectItem(HELE hEle,int goupIndex,int itemIndex,BOOL bSelect);//����ѡ����
XC_API BOOL WINAPI XListView_SetItemText(HELE hEle,int groupIndex,int itemIndex,wchar_t *pText);//�������ı�
XC_API BOOL WINAPI XListView_SetGroupText(HELE hEle,int groupIndex,wchar_t *pText);//�������ı�
XC_API BOOL WINAPI XListView_SetItemIcon(HELE hEle,int groupIndex,int itemIndex,int imageID);//������ͼ��ID
XC_API void WINAPI XListView_SetIconSize(HELE hEle,int cx,int cy); //����ͼ�������С,������ͼ��Ĵ�С.
XC_API void WINAPI XListView_SetItemBorderSpacing(HELE hEle,int left,int top,int right,int bottom); //������߼��
XC_API void WINAPI XListView_SetColumnSpacing(HELE hEle,int width); //�������м��
XC_API void WINAPI XListView_SetRowSpacing(HELE hEle,int height);  //�������м��
XC_API void WINAPI XListView_SetItemIconTextSpacing(HELE hEle,int height);  //����ͼ�����ı����
XC_API void WINAPI XListView_SetViewLeftAlign(HELE hEle,int size);  //������ͼ�����
XC_API void WINAPI XListView_SetViewTopAlign(HELE hEle,int size); //������ͼ�϶���
XC_API void WINAPI XListView_SetGroupHeight(HELE hEle,int height); //������߶�
XC_API void WINAPI XListView_GetIconSize(HELE hEle,out_ SIZE *pSize); //��ȡͼ�������С,������ͼ��Ĵ�С.
XC_API int  WINAPI XListView_GetItemBorderLeft(HELE hEle); //��ȡ��߼��
XC_API int  WINAPI XListView_GetItemBorderTop(HELE hEle); 
XC_API int  WINAPI XListView_GetItemBorderRight(HELE hEle); 
XC_API int  WINAPI XListView_GetItemBorderBottom(HELE hEle); 
XC_API int  WINAPI XListView_GetColumnSpacing(HELE hEle); //��ȡ���м��
XC_API int  WINAPI XListView_GetRowSpacing(HELE hEle);  //��ȡ���м��
XC_API int  WINAPI XListView_GetItemIconTextSpacing(HELE hEle);  //��ȡͼ�����ı����
XC_API int  WINAPI XListView_GetViewLeftAlign(HELE hEle);  //��ȡ��ͼ�����
XC_API int  WINAPI XListView_GetViewTopAlign(HELE hEle); //��ȡ��ͼ�϶���
XC_API int  WINAPI XListView_GetGroupHeight(HELE hEle); //��ȡ��߶�
XC_API void  WINAPI XListView_GetSelectItem(HELE hEle,out_ int *pGroupIndex,out_ int *pItemIndex);    //��ȡѡ����
XC_API int  WINAPI XListView_GetSelectCount(HELE hEle);  //��ȡѡ��������
XC_API int  WINAPI XListView_GetSelectAllItem(HELE hEle,int *pArrayGroupIndex,int *pArrayItemIndex,int arrayLength); //��ȡ����ѡ����
XC_API int  WINAPI XListView_GetGroupCount(HELE hEle); //��ȡ������
XC_API int  WINAPI XListView_GetGroupMemberCount(HELE hEle,int groupIndex); //��ȡ���Ա����
XC_API int  WINAPI XListView_GetUngroupMemberCount(HELE hEle);//��ȡδ����������
XC_API HXCGUI WINAPI XListView_GetImageList(HELE hEle); //��ȡͼƬ�б�
XC_API BOOL WINAPI XListView_GetItemRect(HELE hEle,int groupIndex,int itemIndex,out_ RECT *pRect); //��ȡ������
XC_API BOOL WINAPI XListView_GetItemIconRect(HELE hEle,int groupIndex,int itemIndex,out_ RECT *pRect);//��ȡ��ͼ������
XC_API BOOL WINAPI XListView_GetItemTextRect(HELE hEle,int groupIndex,int itemIndex,out_ RECT *pRect); //��ȡ���ı�����
XC_API wchar_t* WINAPI XListView_GetItemText(HELE hEle,int groupIndex,int itemIndex);//��ȡ���ı�
XC_API int  WINAPI XListView_GetItemIcon(HELE hEle,int groupIndex,int itemIndex);//��ȡ��ͼ��ID
XC_API wchar_t* WINAPI XListView_GetGroupText(HELE hEle,int groupIndex);//��ȡ���ı�
XC_API BOOL WINAPI XListView_GetGroupRect(HELE hEle,int groupIndex,out_ RECT *pRect);//��ȡ������
XC_API int  WINAPI XListView_GetItemData(HELE hEle,int groupIndex,int itemIndex); //��ȡ�������
XC_API int  WINAPI XListView_GetGroupData(HELE hEle,int groupIndex); //��ȡ�������
XC_API BOOL WINAPI XListView_DeleteItem(HELE hEle,int groupIndex,int itemIndex); //ɾ����
XC_API BOOL WINAPI XListView_DeleteGroup(HELE hEle,int groupIndex); //ɾ����
XC_API void WINAPI XListView_DeleteAllGroups(HELE hEle); //ɾ��������
XC_API void WINAPI XListView_DeleteAll(HELE hEle); //ɾ������,�������
XC_API int WINAPI XListView_IsItemSelect(HELE hEle,int groupIndex,int itemIndex);//������Ƿ�ѡ��
XC_API BOOL WINAPI XListView_HitTest(HELE hEle,POINT *pPt,out_ int *pGroupIndex,out_ int *pItemIndex);//�����û����,��,��
XC_API int WINAPI XListView_IsGroupExpand(HELE hEle,int groupIndex);//�ж����Ƿ�չ��
XC_API BOOL WINAPI XListView_SetGroupExpand(HELE hEle,int groupIndex,BOOL bExpand); //չ��ָ����
XC_API void WINAPI XListView_EnableMultiSelect(HELE hEle,BOOL bEnable); //���ùرն���ѡ��
XC_API void WINAPI XListView_EnableExpandButton(HELE hEle,BOOL bEnable); //����/�ر�չ����ť
XC_API void WINAPI XListView_EnableDragItem(HELE hEle,BOOL bEnable);  //���û�ر��϶����
XC_API void WINAPI XListView_CancelSelectItem(HELE hEle,int groupIndex,int itemIndex); //ȡ��ѡ��ָ����
XC_API void WINAPI XListView_CancelSelectAll(HELE hEle); //ȡ��ѡ��������
XC_API void WINAPI XListView_SetUserDrawItem(HELE hEle,pFunListView_DrawItem pFunDrawItem); //�����û��Ի���
XC_API void WINAPI XListView_SetUserDrawGroup(HELE hEle,pFunListView_DrawGroup pFunDrawGroup); //�����û��Ի���
XC_API void WINAPI XListView_SetItemImageSelect(HELE hEle,int groupIndex,int itemIndex,HIMAGE hImage);
XC_API void WINAPI XListView_SetItemImageStay(HELE hEle,int groupIndex,int itemIndex,HIMAGE hImage);
XC_API void WINAPI XListView_Adjust(HELE hEle); //��������
XC_API void WINAPI XMenu_SetUserDrawItemEx(HMENUX hMenu,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի�˵���
XC_API void WINAPI XMenu_SetUserDrawBGEx(HMENUX hMenu,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի�˱���
XC_API void WINAPI XMenu_SetUserUpdateUIEx(HMENUX hMenu,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);
XC_API HMENUX WINAPI XMenu_Create();
XC_API void WINAPI XMenu_AddItem(HMENUX hMenu,int id,wchar_t *pText,int parentId=XMENU_ROOT,int uFlags=0); //��Ӳ˵���
XC_API void WINAPI XMenu_AddItemImage(HMENUX hMenu,int id,wchar_t *pText,int parentId,int uFlags,HIMAGE hImage);
XC_API void WINAPI XMenu_InsertItem(HMENUX hMenu,int id,wchar_t *pText,int uFlags,int insertID);
XC_API void WINAPI XMenu_InsertItemImage(HMENUX hMenu,int id,wchar_t *pText,int uFlags,int insertID,HIMAGE hImage);
XC_API void WINAPI XMenu_DeleteItem(HMENUX hMenu,int id);
XC_API void WINAPI XMenu_SetAutoDestroy(HMENUX hMenu,BOOL bAuto); //�Ƿ��Զ����ٶ���,Ĭ�ϵ����˵��رպ��Զ�����
XC_API void WINAPI XMenu_SetItemHeight(HMENUX hMenu,int height); //���ò˵���߶�
XC_API BOOL WINAPI XMenu_SetBGImage(HMENUX hMenu,HIMAGE hImage);//���ò˵�����ͼƬ
XC_API BOOL WINAPI XMenu_SetItemImage(HMENUX hMenu,int id,HIMAGE hImage); //������ͼ��
XC_API BOOL WINAPI XMenu_SetItemText(HMENUX hMenu,int id,wchar_t *pText); //�������ı�
XC_API void WINAPI XMenu_SetItemFlags(HMENUX hMenu,int id,int uFlags);   //����������
XC_API void WINAPI XMenu_SetItemCheck(HMENUX hMenu,int id,BOOL bCheck);
XC_API BOOL WINAPI XMenu_IsItemCheck(HMENUX hMenu,int id);
XC_API int  WINAPI XMenu_GetItemFlags(HMENUX hMenu,int id);   //��ȡ������
XC_API int  WINAPI XMenu_GetItemHeight(HMENUX hMenu);  //��ȡ�˵���߶�
XC_API int  WINAPI XMenu_GetItemCount(HMENUX hMenu); //��ȡ�˵�������,�����Ӳ˵���
XC_API wchar_t* WINAPI XMenu_GetItemText(HMENUX hMenu,int id); //��ȡ�˵����ı�
XC_API int  WINAPI XMenu_GetItemLeftWidth(HMENUX hMenu); //��ȡ�����
XC_API int  WINAPI XMenu_GetItemLeftText(HMENUX hMenu);  //��ȡ�˵����ı�����
XC_API BOOL WINAPI XMenu_Popup(HMENUX hMenu,HWND hParentWnd,int x,int y,HELE hParentEle=NULL,int uFlags=NULL); //�����˵�
XC_API void WINAPI XMenu_Destroy(HMENUX hMenu);
XC_API void WINAPI XMenu_CloseMenu(HMENUX hMenu);
XC_API void WINAPI XMenu_SetUserDrawItem(HMENUX hMenu,pFunMenu_DrawItem pFunDrawItem); //�����û��Ի���
XC_API void WINAPI XMenu_SetUserDrawBG(HMENUX hMenu,pFunMenu_DrawBG pFunDrawBG); //�����û��Ի�˵�����
XC_API void WINAPI XMenu_SetUserUpdateUI(HMENUX hMenu,pFunMenu_UpdateUI pUpdateUI);
XC_API HELE WINAPI XMenuBar_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);  //������ť
XC_API int WINAPI XMenuBar_AddButton(HELE hEle,wchar_t *pText);     //���ӵ����˵���ť
XC_API int WINAPI XMenuBar_InsertButton(HELE hEle,wchar_t *pText,int index);     //���뵯���˵���ť
XC_API void WINAPI XMenuBar_AddMenuItem(HELE hEle,int index,int id,wchar_t *pText,int parentId=XMENU_ROOT,int uFlags=0);
XC_API void WINAPI XMenuBar_AddMenuItemImage(HELE hEle,int index,int id,wchar_t *pText,int parentId,int uFlags,HIMAGE hImage); //���Ӳ˵���
XC_API void WINAPI XMenuBar_InsertMenuItem(HELE hEle,int index,int id,wchar_t *pText,int uFlags,int insertID); //����˵���,���뵽IDΪinsertID�˵���ǰ��λ��
XC_API void WINAPI XMenuBar_InsertMenuItemImage(HELE hEle,int index,int id,wchar_t *pText,int uFlags,int insertID,HIMAGE hImage); //���Ӳ˵���
XC_API void WINAPI XMenuBar_DeleteMenuItem(HELE hEle,int index,int id); //ɾ���˵���
XC_API void WINAPI XMenuBar_SetButtonHeight(HELE hEle,int height); //���õ����˵���ť�߶�
XC_API HELE WINAPI XMenuBar_GetButton(HELE hEle,int index);  //��ȡ�����˵���ť���
XC_API HMENUX WINAPI XMenuBar_GetMenu(HELE hEle,int index); //��ȡ�˵����
XC_API void WINAPI XMenuBar_DeleteButton(HELE hEle,int index); //ɾ���˵��������,ͬʱ�ð�ť�µĵ����˵�Ҳ������
XC_API void WINAPI XMenuBar_SetImage(HELE hEle,HIMAGE hImage=NULL);
XC_API HWINDOW WINAPI XModalWnd_CreateWindow(int width,int height,wchar_t *pTitle,HWND hWndParent,int XCStyle=XC_SY_MODAL_WINDOW);//���ڸ���������
XC_API int WINAPI XModalWnd_DoModal(HWINDOW hWindow);     //����ģ̬����
XC_API void WINAPI XModalWnd_DoOk(HWINDOW hWindow);       //ȷ��
XC_API void WINAPI XModalWnd_DoCancel(HWINDOW hWindow);   //ȡ��
XC_API int WINAPI XMessageBox(HXCGUI hXCGUI, wchar_t *pText, wchar_t *pCaption=L"�Ųʽ����-��ʾ��",int type=XMB_OK);
XC_API HELE WINAPI XMonthCal_Create(int x, int y,int cx,int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XMonthCal_SetSpacingLeft(HELE hEle,int left); //�������
XC_API void WINAPI XMonthCal_SetSpacingTop(HELE hEle,int top); //�϶�����
XC_API void WINAPI XMonthCal_SetDate(HELE hEle,int year,int month,int day);  //����ʱ��
XC_API int WINAPI XMonthCal_GetYear(HELE hEle);
XC_API int WINAPI XMonthCal_GetMonth(HELE hEle);
XC_API int WINAPI XMonthCal_GetDay(HELE hEle);
XC_API HELE WINAPI XDateTime_Create(int x, int y,int cx,int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XDateTime_SetDate(HELE hEle,int year,int month,int day);  //����ʱ��
XC_API int WINAPI XDateTime_GetYear(HELE hEle);
XC_API int WINAPI XDateTime_GetMonth(HELE hEle);
XC_API int WINAPI XDateTime_GetDay(HELE hEle);
XC_API HELE WINAPI XDateTime_GetButton(HELE hEle);  //��ȡ������ť
XC_API void WINAPI XDateTime_SetImage(HELE hEle,HIMAGE hImage);
XC_API HELE WINAPI XOutlook_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XOutlook_AddView(HELE hEle,HELE hView,wchar_t *pTitle);
XC_API void WINAPI XOutlook_Adjust(HELE hEle);
XC_API void WINAPI XOutlook_Expand(HELE hEle,int index);  //չ��ָ����
XC_API int WINAPI XOutlook_GetExpand(HELE hEle); //��ȡ��ǰչ����������
XC_API HELE WINAPI XPane_Create(wchar_t *pTitle=NULL,HWINDOW hFrameWnd=NULL);  //������ť
XC_API wchar_t* WINAPI XPane_GetTitle(HELE hEle);
XC_API void WINAPI XPane_Hide(HELE hEle);      //���ش���
XC_API void WINAPI XPane_Dock(HELE hEle);      //ͣ������,�Զ�����
XC_API void WINAPI XPane_Lock(HELE hEle);      //��������
XC_API void WINAPI XPane_popup(HELE hEle);     //��������,������ͷ��
XC_API void WINAPI XPane_Show(HELE hEle);     //����-��ʾ��������
XC_API HPANE_GROUP WINAPI XPane_GetGroup(HELE hEle); //��ȡ����������,���û���鷵�ؿ�
XC_API BOOL WINAPI XPane_Destroy(HELE hEle); //���ٴ��� 
XC_API pane_state_ WINAPI XPane_GetState(HELE hEle);  //��ȡ״̬
XC_API void WINAPI XPane_DragPane(HELE hEle,POINT *pPtDown); //�϶�����
XC_API void WINAPI XPane_DragGroup(HELE hEle,POINT *pPtDown);//�϶�������
XC_API void WINAPI XPane_FloatPane(HELE hEle); //��������
XC_API void WINAPI XPane_SetView(HELE hEle,HELE hView);
XC_API void WINAPI XPane_SetToolBar(HELE hEle,HELE hToolBar); //���ù�����
XC_API void WINAPI XPane_SetMenuBar(HELE hEle,HELE hMenuBar); //���ò˵���
XC_API void WINAPI XPane_SetSpacing(HELE hEle,int left, int top, int right, int bottom);
XC_API void WINAPI XPane_SetFixedSize(HELE hEle,BOOL bFixedSize); //���ô���̶���С,���ΪFALSE�ǹ̶���С
XC_API void WINAPI XPane_SetTitle(HELE hEle,wchar_t *pTitle);
XC_API void WINAPI XPane_SetActivate(HELE hEle,BOOL bActivate); //�����
XC_API BOOL WINAPI XPane_IsActivate(HELE hEle); //�жϴ����Ƿ񼤻�,�������ڿ������Ч
XC_API void WINAPI XPane_SetCaptionHeight(HELE hEle,int height);//���ñ������߶�
XC_API int  WINAPI XPane_GetCaptionHeight(HELE hEle);//��ȡ�������߶�
XC_API HELE WINAPI XPane_GetButtonClose(HELE hEle); //��ȡ�رհ�ť
XC_API HELE WINAPI XPane_GetButtonLock(HELE hEle); //��ȡ������ť
XC_API HELE WINAPI XPane_GetButtonMenu(HELE hEle); //��ȡ�˵���ť
XC_API void WINAPI XFloatWnd_EnableLock(HWINDOW hWindow,BOOL bEnable); //���ùر���������,���ر��������ܺ�,�û��϶�������������������ܴ�����
XC_API HELE WINAPI XPic_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XPic_SetImage(HELE hEle,HIMAGE hImage);  //����ͼƬ
XC_API HELE WINAPI XProgBar_Create(int x, int y, int cx, int cy,BOOL bHorizon,HXCGUI hParent=NULL);
XC_API void WINAPI XProgBar_SetRange(HELE hEle,int range);  //���÷�Χ
XC_API void WINAPI XProgBar_SetPos(HELE hEle,int pos);   //���õ�ǰλ��
XC_API int  WINAPI XProgBar_GetRange(HELE hEle);
XC_API int  WINAPI XProgBar_GetPos(HELE hEle);
XC_API void WINAPI XProgBar_SetHorizon(HELE hEle,BOOL bHorizon); //ˮƽ��ʾ��ֱ
XC_API void WINAPI XProgBar_EnablePercent(HELE hEle,BOOL bPercent); //��ʾ�ٷֱ�
XC_API void WINAPI XProgBar_SetImage(HELE hEle,HIMAGE hImage); //����
XC_API void WINAPI XProgBar_SetImage2(HELE hEle,HIMAGE hImage); //��ʾ��ǰ����ͼƬ
XC_API HELE WINAPI XPGrid_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API int WINAPI XPGrid_AddGroup(HELE hEle,wchar_t *pName,BOOL bExpand=TRUE); //��ӷ���
XC_API int WINAPI XPGrid_AddItem(HELE hEle,wchar_t *pName,int type,int groupID=-1); //�����
XC_API int WINAPI XPGrid_AddItemString(HELE hEle,wchar_t *pName,wchar_t *pValue,int groupID=-1); //�����
XC_API HELE WINAPI XPGrid_GetItemHEle(HELE hEle,int itemID);
XC_API BOOL WINAPI XPGrid_SetItemString(HELE hEle,int itemID,wchar_t *pText);
XC_API BOOL WINAPI XPGrid_SetItemColor(HELE hEle,int itemID,COLORREF color);
XC_API void WINAPI XPGrid_GetItemValue(HELE hEle,int itemID,wchar_t *pOut,int len);
XC_API void WINAPI XPGrid_DeleteItem(HELE hEle,int itemID);   //ɾ����
XC_API void WINAPI XPGrid_DeleteGroup(HELE hEle,int groupID);  //ɾ����
XC_API void WINAPI XPGrid_DeleteAll(HELE hEle);  //ɾ������
XC_API void WINAPI XPGrid_SetSpacePoint(HELE hEle,int point);//���÷ָ��߻���X����λ��
XC_API int WINAPI XPGrid_GetSelectItem(HELE hEle); //��ȡ��ǰѡ����
XC_API void WINAPI XPGrid_Adjust(HELE hEle); //��������
XC_API HELE WINAPI XPPage_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API int WINAPI XPPage_AddLabel(HELE hEle,wchar_t *pName,HELE hPage=NULL); //���һ����ǩ
XC_API int WINAPI XPPage_InsertLabel(HELE hEle,int index,wchar_t *pName,HELE hPage=NULL);
XC_API void WINAPI XPPage_Adjust(HELE hEle);
XC_API BOOL WINAPI XPPage_SetBindEle(HELE hEle,int index,HELE hPage); //����ͼԪ�ص���ǩ
XC_API void WINAPI XPPage_SetLabelHeight(HELE hEle,int height);  //���ñ�ǩ�߶�
XC_API void WINAPI XPPage_SetLabelWidth(HELE hEle,int index,int width);   //���ñ�ǩ���
XC_API void WINAPI XPPage_SetSelect(HELE hEle,int index,BOOL reDraw=TRUE);   //����ѡ���ǩ
XC_API void WINAPI XPPage_SetLabelText(HELE hEle,int index,wchar_t *pText);  //���ñ�ǩ�ı�
XC_API void WINAPI XPPage_SetLabelSpacing(HELE hEle,int spacing);//���ñ�ǩ���, 0û�м��
XC_API void WINAPI XPPage_SetUp(HELE hEle);    //�����
XC_API void WINAPI XPPage_SetDown(HELE hEle);  //�ҹ���
XC_API int  WINAPI XPPage_GetSelect(HELE hEle);  //��ȡѡ��ı�ǩ
XC_API int  WINAPI XPPage_GetLabelHeight(HELE hEle);  //��ȡ��ǩ�߶�
XC_API int  WINAPI XPPage_GetLabelWidth(HELE hEle,int index);  //��ȡ��ǩ���
XC_API int  WINAPI XPPage_GetLabelCount(HELE hEle); //��ȡ��ǩ������
XC_API wchar_t * WINAPI XPPage_GetLabelText(HELE hEle,int index);  //��ȡ�ı�
XC_API HELE WINAPI XPPage_GetLabel(HELE hEle,int index);//��ȡ��ǩ��ťButton
XC_API HELE WINAPI XPPage_GetLabelPage(HELE hEle,int index);//��ȡ��ǩ��Ӧ��ҳ
XC_API int WINAPI XPPage_GetPageIndex(HELE hEle,HELE hPage); //������ҳ��Ӧ��ǩ����
XC_API int WINAPI XPPage_GetLabelIndex(HELE hEle,HELE hLabel); //��ȡ����ҳ��ǩ��ťԪ��λ������ֵ
XC_API int WINAPI XPPage_GetLabelSpacing(HELE hEle);//��ȡ��ǩ���, 0û�м��
XC_API void WINAPI XPPage_DeleteLabel(HELE hEle,int index,BOOL deletePage=FALSE);  //ɾ��
XC_API void WINAPI XPPage_DeleteLabelAll(HELE hEle,BOOL deletePage=FALSE);  //ɾ������TAB
XC_API void WINAPI XPPage_EnableScrollButton(HELE hEle,BOOL bEnable); //�Ƿ���ʾ������ť
XC_API HELE WINAPI XRadio_Create(int x, int y, int cx, int cy,wchar_t *pTitle=NULL,HXCGUI hParent=NULL);  //������ť
XC_API void WINAPI XRadio_SetImageLeave_UnCheck(HELE hEle,HIMAGE hImage=NULL);  //����뿪ʱͼƬ  δѡ��
XC_API void WINAPI XRadio_SetImageStay_UnCheck(HELE hEle,HIMAGE hImage=NULL);   //���ͣ��ʱͼƬ  δѡ��
XC_API void WINAPI XRadio_SetImageDown_UnCheck(HELE hEle,HIMAGE hImage=NULL);   //��갴��ʱͼƬ  δѡ��
XC_API void WINAPI XRadio_SetImageDisable_UnCheck(HELE hEle,HIMAGE hImage=NULL); //��ť����״̬ͼƬ  δѡ��
XC_API void WINAPI XRadio_SetImageLeave_Check(HELE hEle,HIMAGE hImage=NULL);  //����뿪ʱͼƬ  ѡ��
XC_API void WINAPI XRadio_SetImageStay_Check(HELE hEle,HIMAGE hImage=NULL);   //���ͣ��ʱͼƬ  ѡ��
XC_API void WINAPI XRadio_SetImageDown_Check(HELE hEle,HIMAGE hImage=NULL);   //��갴��ʱͼƬ  ѡ��
XC_API void WINAPI XRadio_SetImageDisable_Check(HELE hEle,HIMAGE hImage=NULL); //��ť����״̬ͼƬ  ѡ��
XC_API void WINAPI XRadio_SetGroupID(HELE hEle,int groupID);  //������ID
XC_API int  WINAPI XRadio_GetGroupID(HELE hEle);  //��ȡ��ID
XC_API void WINAPI XRadio_EnableButtonStyle(HELE hEle,BOOL bStyle); //���ð�ť��ʽ
XC_API void WINAPI XRadio_SetBindEle(HELE hEle,HELE bindEle);
XC_API HELE WINAPI XRichEdit_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API BOOL WINAPI XRichEdit_InsertText(HELE hEle,wchar_t *pText,int row,int column); //�����ı�����
XC_API BOOL WINAPI XRichEdit_InsertTextEx(HELE hEle,wchar_t *pText,int row,int column,LOGFONTW *pFont,BOOL bColor=FALSE,COLORREF color=0);
XC_API BOOL WINAPI XRichEdit_InsertData(HELE hEle,void *pData,int row,int column); 
XC_API BOOL WINAPI XRichEdit_InsertImage(HELE hEle,HIMAGE hImage,wchar_t *pImagePath,int row,int column); //����ͼƬ,����ǰλ��
XC_API BOOL WINAPI XRichEdit_InsertImageGif(HELE hEle,wchar_t *pImageName,int row,int column);//����GIFͼƬ,����ǰλ��
XC_API void WINAPI XRichEdit_SetText(HELE hEle,wchar_t *pText);  //�����ı�����,�����֮ǰ������
XC_API BOOL WINAPI XRichEdit_SetPos(HELE hEle,int row,int column); //���ò����λ��
XC_API BOOL WINAPI XRichEdit_SetItemFontEx(HELE hEle,int beginRow,int beginColumn,int endRow,int endColumn,LOGFONTW *pFont);
XC_API BOOL WINAPI XRichEdit_SetItemColorEx(HELE hEle,int beginRow,int beginColumn,int endRow,int endColumn,COLORREF color);
XC_API void WINAPI XRichEdit_SetRowHeight(HELE hEle,int height); //����Ĭ���и�
XC_API void WINAPI XRichEdit_SetReadOnly(HELE hEle,BOOL bRead);  //����ֻ������
XC_API int WINAPI XRichEdit_GetItemCount(HELE hEle); //��ȡ��������,����ͼƬ
XC_API void WINAPI XRichEdit_GetText(HELE hEle,HSTRING hString); //��ȡ�ı�����
XC_API void WINAPI XRichEdit_GetHTMLFormat(HELE hEle,HSTRING hString);  //��ȡHTML��ʽ����
XC_API void* WINAPI XRichEdit_GetData(HELE hEle);
XC_API void WINAPI XRichEdit_GetCurrentPos(HELE hEle,out_ int *pRow,out_ int *pColumn);//��ȡ�����λ��,��ǰ�к���
XC_API BOOL WINAPI XRichEdit_GetSelectPos(HELE hEle,out_ int *pBeginRow,out_ int *pBeginColumn,out_ int *pEndRow,out_ int *pEndColumn);//��ȡѡ������λ��
XC_API int  WINAPI XRichEdit_GetSelectText(HELE hEle,wchar_t *pOut,int len);//��ȡѡ������
XC_API int  WINAPI XRichEdit_GetRowCount(HELE hEle);   //��ȡ������
XC_API int  WINAPI XRichEdit_GetRowItemCount(HELE hEle,int row);   //��ȡָ������������
XC_API void WINAPI XRichEdit_GetVisibleRow(HELE hEle,out_ int *pBeginRow,out_ int *pEndRow); //��ȡ�����з�Χ
XC_API int  WINAPI XRichEdit_GetRowHeight(HELE hEle); //��ȡĬ���и�
XC_API int  WINAPI XRichEdit_GetFontCount(HELE hEle);  //��ȡ��������
XC_API BOOL WINAPI XRichEdit_IsEmpty(HELE hEle);  //�ж������Ƿ�Ϊ��
XC_API BOOL WINAPI XRichEdit_CancelSelect(HELE hEle); //ȡ��ѡ��
XC_API void WINAPI XRichEdit_SelectAll(HELE hEle);  //ȫѡ  ѡ�������ı�
XC_API void WINAPI XRichEdit_ClearFontTable(HELE hEle); //���������,����δʹ�õ�����
XC_API BOOL WINAPI XRichEdit_DeleteEx(HELE hEle,int beginRow,int beginColumn,int endRow,int endColumn); //ɾ��ָ������
XC_API BOOL WINAPI XRichEdit_DeleteSelect(HELE hEle); //ɾ��ѡ������
XC_API void WINAPI XRichEdit_DeleteAll(HELE hEle); //�������
XC_API BOOL WINAPI XRichEdit_Menu_Cut(HELE hEle);        //����  ɾ��ѡ����ı�,�����ı����������а���
XC_API BOOL WINAPI XRichEdit_Menu_Copy(HELE hEle);       //����  ����ѡ����ı������а���
XC_API BOOL WINAPI XRichEdit_Menu_Paste(HELE hEle);      //ճ��  �����а��е��ı����뵱ǰ���λ��
XC_API void WINAPI XRichEdit_Adjust(HELE hEle,int startIndex=0); //����
XC_API HELE WINAPI XSBar_Create(int x, int y, int cx, int cy,BOOL bHorizon,HXCGUI hParent=NULL);
XC_API BOOL WINAPI XSBar_ScrollUp(HELE hEle);       //�������
XC_API BOOL WINAPI XSBar_ScrollDown(HELE hEle);     //���ҹ���
XC_API BOOL WINAPI XSBar_ScrollTop(HELE hEle);      //����������
XC_API BOOL WINAPI XSBar_ScrollBottom(HELE hEle);   //�������ײ�
XC_API BOOL WINAPI XSBar_ScrollPos(HELE hEle,int pos); //������ָ����
XC_API void WINAPI XSBar_SetScrollRange(HELE hEle,int range);
XC_API void WINAPI XSBar_SetSliderLength(HELE hEle,int length); //���û��鳤��
XC_API void WINAPI XSBar_SetHorizon(HELE hEle,BOOL bHorizon);  //ˮƽ��ʾ��ֱ
XC_API int WINAPI XSBar_GetScrollPos(HELE hEle); //��ȡ��ǰ������
XC_API int WINAPI XSBar_GetButtonLength(HELE hEle); //��ť����
XC_API int WINAPI XSBar_GetSliderLength(HELE hEle); //���鳤��
XC_API int WINAPI XSBar_GetScrollRange(HELE hEle);  //��ȡ������Χ
XC_API void WINAPI XSBar_EnableScrollButton2(HELE hEle,BOOL bEnable); //�Ƿ���ʾ���¹�����ť
XC_API void WINAPI XSBar_Adjust(HELE hEle);            //����������
XC_API void WINAPI XSBar_SetImage(HELE hEle,HIMAGE hImage);     //���ñ���ͼƬ
XC_API void WINAPI XSBar_SetImageLeaveUp(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageStayUp(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageDownUp(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageLeaveDown(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageStayDown(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageDownDown(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageLeaveSlider(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageStaySlider(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageDownSlider(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSView_SetDrawScrollViewEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);
XC_API HELE WINAPI XSView_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XSView_SetDrawScrollView(HELE hEle,pFunDrawScrollView pFun);
XC_API HELE WINAPI XSView_GetView(HELE hEle); //��ȡ��Ԫ��
XC_API BOOL WINAPI XSView_AddEle(HELE hEle,HELE hNewEle); //���Ԫ�ص�������ͼ
XC_API int WINAPI XSView_GetHViewPos(HELE hEle);   //��ȡ�ӿ�ԭ��X����
XC_API int WINAPI XSView_GetVViewPos(HELE hEle);   //��ȡ�ӿ�ԭ��Y����
XC_API int WINAPI XSView_GetSpacingLeft(HELE hEle);
XC_API int WINAPI XSView_GetSpacingTop(HELE hEle);
XC_API int WINAPI XSView_GetSpacingRight(HELE hEle);
XC_API int WINAPI XSView_GetSpacingBottom(HELE hEle);
XC_API int WINAPI XSView_GetScrollBarWidth(HELE hEle);  //��ȡ���������
XC_API int WINAPI XSView_GetViewWidth(HELE hEle);  //��ȡ�ӿڿ��(�����߿�����������)
XC_API int WINAPI XSView_GetViewHeight(HELE hEle); //��ȡ�ӿڸ߶�(�����߿�����������)
XC_API int WINAPI XSView_GetHSizeTotalAccurate(HELE hEle); //��ȡ�����ܿ��,��ȷ��(�����߿�����������),�����ݴ�СС���ӿڴ�Сʱ,���ص����ӿڴ�С
XC_API int WINAPI XSView_GetVSizeTotalAccurate(HELE hEle); //��ȡ�����ܸ߶�,��ȷ��(�����߿�����������),�����ݴ�СС���ӿڴ�Сʱ,���ص����ӿڴ�С
XC_API void WINAPI XSView_GetViewRect(HELE hEle,out_ RECT *pRect); //��ȡ�ӿ�����(�����߿���),leftΪ�ӿ�������С,topΪ�ӿ��ϼ����С,��(0,0).
XC_API void WINAPI XSView_GetSize(HELE hEle,SIZE *pSize);  //��ȡ���õ����ݴ�С
XC_API HELE WINAPI XSView_GetHScrollBar(HELE hEle); //��ȡˮƽ������
XC_API HELE WINAPI XSView_GetVScrollBar(HELE hEle); //��ȡ��ֱ������
XC_API void WINAPI XSView_SetSize(HELE hEle,int cx, int cy); //������ͼ�����ܴ�С(�������߿���)
XC_API void WINAPI XSView_SetSpacing(HELE hEle,int left, int top, int right, int bottom);  
XC_API void WINAPI XSView_SetScrollSize(HELE hEle,int line,int column);  //���ù����к��д�С
XC_API void WINAPI XSView_SetImage(HELE hEle,HIMAGE hImage);//������ͼ
XC_API void WINAPI XSView_EnableHScroll(HELE hEle,BOOL bEnable); //����ˮƽ������
XC_API void WINAPI XSView_EnableVScroll(HELE hEle,BOOL bEnable); //���ô�ֱ������
XC_API BOOL WINAPI XSView_IsHScrollBarVisible(HELE hEle); //ˮƽ��������ǰ�Ƿ�ɼ�
XC_API BOOL WINAPI XSView_IsVScrollBarVisible(HELE hEle); //��ֱ��������ǰ�Ƿ�ɼ�
XC_API void WINAPI XSView_Adjust(HELE hEle);
XC_API BOOL WINAPI XSView_ScrollHPos(HELE hEle,int pos); //������ָ����
XC_API BOOL WINAPI XSView_ScrollVPos(HELE hEle,int pos); //������ָ����
XC_API BOOL WINAPI XSView_ScrollHPosX(HELE hEle,int posX); //������ָ������
XC_API BOOL WINAPI XSView_ScrollVPosY(HELE hEle,int posY); //������ָ������
XC_API BOOL WINAPI XSView_ScrollLeftLine(HELE hEle);    //�������
XC_API BOOL WINAPI XSView_ScrollRightLine(HELE hEle);   //���ҹ���
XC_API BOOL WINAPI XSView_ScrollTopLine(HELE hEle);     //���Ϲ���
XC_API BOOL WINAPI XSView_ScrollDownLine(HELE hEle);    //���¹���
XC_API BOOL WINAPI XSView_ScrollLeft(HELE hEle);    //ˮƽ���������
XC_API BOOL WINAPI XSView_ScrollRight(HELE hEle);   //ˮƽ�������Ҳ�
XC_API BOOL WINAPI XSView_ScrollTop(HELE hEle);     //����������
XC_API BOOL WINAPI XSView_ScrollBottom(HELE hEle);  //�������ײ�
XC_API HELE WINAPI XSliderBar_Create(int x, int y, int cx, int cy,BOOL bHorizon,HXCGUI hParent=NULL);
XC_API void WINAPI XSliderBar_SetRange(HELE hEle,int range);  //���û�����Χ
XC_API void WINAPI XSliderBar_SetPos(HELE hEle,int pos);     //���û���λ��
XC_API int  WINAPI XSliderBar_GetPos(HELE hEle);            //��ȡ����λ��
XC_API HELE WINAPI XSliderBar_GetButton(HELE hEle);        //��ȡ����ָ��
XC_API int  WINAPI XSliderBar_GetButtonWidth(HELE hEle); //��ȡ������
XC_API void WINAPI XSliderBar_SetHorizon(HELE hEle,BOOL bHorizon);  //ˮƽ��ʾ��ֱ
XC_API void WINAPI XSliderBar_SetButtonWidth(HELE hEle,int width); //���û�����
XC_API void WINAPI XSliderBar_SetImage(HELE hEle,HIMAGE hImage); //����
XC_API void WINAPI XSliderBar_SetImage2(HELE hEle,HIMAGE hImage); //��ʾ��ǰ����ͼƬ
XC_API HELE WINAPI XStatic_Create(int x, int y, int cx, int cy,wchar_t *pTitle=NULL,HXCGUI hParent=NULL);
XC_API void WINAPI XStatic_SetText(HELE hEle,wchar_t *pText);
XC_API wchar_t* WINAPI XStatic_GetText(HELE hEle);
XC_API void WINAPI XStatic_AdjustSize(HELE hEle);  //�����ı�����,����Ԫ�ش�С
XC_API void WINAPI XStatic_SetTextAlign(HELE hEle,int flag); //�����ı�����
XC_API HSTRING WINAPI XStr_Create(wchar_t *pString=NULL);
XC_API void WINAPI XStr_Destroy(HSTRING hStr);
XC_API void WINAPI XStr_InsertChar(HSTRING hStr,int index,wchar_t ch);  //����
XC_API void WINAPI XStr_InsertString(HSTRING hStr,int index,wchar_t *pStr);
XC_API void WINAPI XStr_SetString(HSTRING hStr, wchar_t *pStr); //�����ı�
XC_API void WINAPI XStr_AddString(HSTRING hStr, wchar_t *pStr); //����ı���ĩβ
XC_API void WINAPI XStr_AddStringLength(HSTRING hStr, wchar_t *pStr, int strLen); //����ı���ĩβ
XC_API void WINAPI XStr_SetLength(HSTRING hStr,int length); //�����ַ�������,������ַ�ȥ��
XC_API void WINAPI XStr_Replace(HSTRING hStr,wchar_t *pStrOld,wchar_t *pStrNew); //�ַ����滻 Replace
XC_API wchar_t* WINAPI XStr_GetBuffer(HSTRING hStr);
XC_API int WINAPI XStr_GetLength(HSTRING hStr);
XC_API wchar_t*  WINAPI XStr_Find(HSTRING hStr,wchar_t ch, int strart=0); //�����ַ�
XC_API void WINAPI XStr_SetAt(HSTRING hStr,int index, wchar_t ch);//����ָ��λ�õ�һ���ַ�
XC_API wchar_t WINAPI XStr_GetAt(HSTRING hStr,int index); //��ȡָ��λ�õ�һ���ַ�
XC_API void WINAPI XStr_Empty(HSTRING hStr);    //���
XC_API BOOL WINAPI XStr_IsEmpty(HSTRING hStr);  //�ж��Ƿ�Ϊ��
XC_API void WINAPI XStr_Delete(HSTRING hStr,wchar_t ch); //ɾ��ch,ȫ��chɾ��
XC_API void WINAPI XStr_DeleteLength(HSTRING hStr,int index, int count=1); //��indexλ��ɾ��count���ַ�
XC_API void WINAPI XStr_DeleteFront(HSTRING hStr, int index); //ɾ��ָ��λ��֮����ַ���
XC_API void WINAPI XStr_DeleteBack(HSTRING hStr, int index);  //ɾ��ָ��λ��֮ǰ���ַ���
XC_API HELE WINAPI XTabBar_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API int WINAPI XTabBar_AddLabel(HELE hEle,wchar_t *pName,HELE hPage=NULL); //���һ����ǩ
XC_API int WINAPI XTabBar_InsertLabel(HELE hEle,int index,wchar_t *pName,HELE hPage=NULL);
XC_API void WINAPI XTabBar_DeleteLabel(HELE hEle,int index,BOOL deletePage=FALSE);  //ɾ��
XC_API void WINAPI XTabBar_DeleteLabelAll(HELE hEle,BOOL deletePage=FALSE);  //ɾ������TAB
XC_API HELE WINAPI XTabBar_GetLabel(HELE hEle,int index);//��ȡ��ǩ��ťButton
XC_API HELE WINAPI XTabBar_GetLabelPage(HELE hEle,int index); //��ȡ��ǩ��Ӧ��ҳ
XC_API int  WINAPI XTabBar_GetPageIndex(HELE hEle,HELE hPage); //������ҳ��Ӧ��ǩ����
XC_API int  WINAPI XTabBar_GetSelect(HELE hEle);  //��ȡѡ��ı�ǩ
XC_API int  WINAPI XTabBar_GetLabelSpacing(HELE hEle); //��ȡ��ǩ���, 0û�м��
XC_API int  WINAPI XTabBar_GetLabelCount(HELE hEle); //��ȡ��ǩ������
XC_API void WINAPI XTabBar_SetLabelSpacing(HELE hEle,int spacing);//���ñ�ǩ���, 0û�м��
XC_API BOOL WINAPI XTabBar_SetBindEle(HELE hEle,int index,HELE hPage); //����ͼԪ�ص���ǩ
XC_API void WINAPI XTabBar_SetSelect(HELE hEle,int index,BOOL reDraw=TRUE);   //����ѡ���ǩ
XC_API void WINAPI XTabBar_SetAlign(HELE hEle,align_type_ align);
XC_API void WINAPI XTabBar_SetUp(HELE hEle);    //�����
XC_API void WINAPI XTabBar_SetDown(HELE hEle);  //�ҹ���
XC_API void WINAPI XTabBar_EnableTile(HELE hEle,BOOL bTile);  //ƽ�̱�ǩ,ÿ����ǩ��ʾ��ͬ��С
XC_API HELE WINAPI XTextLink_Create(int x, int y, int cx, int cy,wchar_t *pTitle=NULL,HXCGUI hParent=NULL);
XC_API void WINAPI XTextLink_SetStayColor(HELE hEle,COLORREF color); //�������ͣ��ʱ�ı���ɫ
XC_API COLORREF WINAPI XTextLink_GetStayColor(HELE hEle);  //��ȡ���ͣ��ʱ�ı���ɫ
XC_API void WINAPI XTextLink_AdjustSize(HELE hEle);  //�����ı�����,����Ԫ�ش�С
XC_API void WINAPI XTextLink_ShowUnderline(HELE hEle,BOOL bLeave,BOOL bStay);  //��ʾ�»���
XC_API HELE WINAPI XToolBarBtn_Create(int cx,int cy,wchar_t *pTitle);
XC_API void WINAPI XToolBarBtn_Adjust(HELE hEle);  //���������ʴ�С, ����ӵ���������֮��ſɵ���,��Ϊ��Ҫ֪����������С�����������
XC_API HELE WINAPI XToolBar_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API int WINAPI XToolBar_InsertEle(HELE hEle,HELE hNewEle,int index=-1); //���Ԫ�ص�������, -1���뵽ĩβ
XC_API int WINAPI XToolBar_InsertSeparator(HELE hEle,int index=-1); //��ӷָ���, -1���뵽ĩβ
XC_API HELE WINAPI XToolBar_GetHEle(HELE hEle,int index);  //��ȡ��������Ԫ�ؾ��
XC_API HELE WINAPI XToolBar_GetButtonLeft(HELE hEle);   //��ȡ�������������ťButton
XC_API HELE WINAPI XToolBar_GetButtonRight(HELE hEle);  //��ȡ�������ҹ�����ťButton
XC_API void WINAPI XToolBar_DeleteEle(HELE hEle,int index); //�Ƴ���������Ԫ�ز�����
XC_API void WINAPI XToolBar_Adjust(HELE hEle);          //��������
XC_API void WINAPI XToolBar_SetImage(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XTree_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //�����û��Ի���
XC_API HELE WINAPI XTree_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API int WINAPI XTree_InsertItem(HELE hEle,wchar_t *pText, int parentId=XTREE_ROOT,int imageId=-1, int selectImageId=-1,int insertAfter=XTREE_INSERT_LAST,BOOL bExpand=TRUE); //������
XC_API void WINAPI XTree_EnableButton(HELE hEle,BOOL bEnable);    //��ʾ��ť
XC_API void WINAPI XTree_EnableLine(HELE hEle,BOOL bEnable);      //��ʾ��������
XC_API void WINAPI XTree_EnableRootLine(HELE hEle,BOOL bEnable);  //�������Ӹ�������
XC_API BOOL WINAPI XTree_IsButton(HELE hEle);
XC_API BOOL WINAPI XTree_IsLine(HELE hEle);
XC_API BOOL WINAPI XTree_IsRootLine(HELE hEle);
XC_API BOOL WINAPI XTree_IsExpand(HELE hEle,int id); //�ж�ָ�����Ƿ�չ��
XC_API void WINAPI XTree_SetSpacingLeft(HELE hEle,int left);   //��������
XC_API void WINAPI XTree_SetSpacingTop(HELE hEle,int top);     //�����ϼ��
XC_API void WINAPI XTree_SetImageList(HELE hEle,HXCGUI hImageList); //����ͼƬ�б�
XC_API void WINAPI XTree_SetItemData(HELE hEle,int id, int data);   //�����û�����
XC_API void WINAPI XTree_SetExpandButtonSize(HELE hEle,int size);   //����չ����ť��С
XC_API void WINAPI XTree_SetIndentation(HELE hEle,int width);  //���������������
XC_API void WINAPI XTree_SetSelectItem(HELE hEle,int id);     //����ѡ����
XC_API void WINAPI XTree_SetItemText(HELE hEle,int id, wchar_t *pText);//�������ı�
XC_API void WINAPI XTree_SetItemImage(HELE hEle,int id, int imageId);  //������ͼƬ
XC_API void WINAPI XTree_SetItemHeight(HELE hEle,int height); //������߶�
XC_API BOOL WINAPI XTree_SetItemBindEle(HELE hEle,int id,itemBindEle_ *pInfo); //��Ԫ��
XC_API int WINAPI XTree_GetItemData(HELE hEle,int id); //��ȡ�û�����
XC_API int WINAPI XTree_GetItemHeight(HELE hEle);      //��ȡ��߶�
XC_API int WINAPI XTree_GetSelectItem(HELE hEle);   //��ȡ��ǰѡ�����
XC_API int WINAPI XTree_GetParentItem(HELE hEle,int id); //��ȡָ����ĸ���
XC_API int WINAPI XTree_GetChildItem(HELE hEle,int id);  //��ȡָ���������
XC_API int WINAPI XTree_GetNextSiblingItem(HELE hEle,int id); //��ȡָ�������һ���ֵ���
XC_API int WINAPI XTree_GetPrevSiblingItem(HELE hEle,int id); //��ȡָ�������һ���ֵ���
XC_API int WINAPI XTree_GetFirstItem(HELE hEle); //��ȡ��һ���ڵ�
XC_API int WINAPI XTree_GetItemDepth(HELE hEle,int id);//��ȡ�ڵ����
XC_API int WINAPI XTree_GetItemImage(HELE hEle,int id);  //��ȡ��ͼƬ
XC_API wchar_t* WINAPI XTree_GetItemText(HELE hEle,int id); //��ȡ���ı�
XC_API HXCGUI WINAPI XTree_GetImageList(HELE hEle); //��ȡͼƬ�б�
XC_API void WINAPI XTree_Expand(HELE hEle,int id, BOOL bExpand); //չ������ָ����
XC_API void WINAPI XTree_DeleteItem(HELE hEle,int id); //ɾ��һ����
XC_API void WINAPI XTree_DeleteAllItems(HELE hEle); //�����
XC_API int WINAPI XTree_HitTest(HELE hEle,POINT *pPt);  //���Ե��λ��,������ID
XC_API void WINAPI XTree_SetUserDrawItem(HELE hEle,pFunTree_DrawItem pFunDrawItem); //�����û��Ի���
XC_API void WINAPI XTree_EnableCheckBox(HELE hEle, BOOL bEnable);//���ø�ѡ��
XC_API BOOL WINAPI XTree_IsItemCheck(HELE hEle,int id); //�ж���ĸ�ѡ���Ƿ�ѡ
XC_API void WINAPI XTree_SetItemCheck(HELE hEle,int id, BOOL bCheck); //������ĸ�ѡ��
XC_API HXCGUI WINAPI XWeb_Create(HWINDOW hWindow,int x,int y,int cx,int cy);
XC_API BOOL WINAPI XWeb_OpenURL(HXCGUI hWebBrowser,wchar_t *pUrl);
XC_API void WINAPI XWeb_Show(HXCGUI hWebBrowser,BOOL bShow); //��ʾ����
XC_API HWND WINAPI XWeb_GetHWnd(HXCGUI hWebBrowser);       //��ȡ������ؼ�����(CAxWindow)HWND���
XC_API void* WINAPI XWeb_GetControl(HXCGUI hWebBrowser);   //��ȡ�ؼ��ӿ�IWebBrowser2*
XC_API void* WINAPI XWeb_GetCAxWindow(HXCGUI hWebBrowser); //��ȡ��������ָ��CAxWindow*
XC_API void WINAPI XWeb_Destroy(HXCGUI hWebBrowser);
XC_API BOOL WINAPI XWeb_GetClientRect(HXCGUI hWebBrowser,out_ RECT *pRect); //��ȡ����
XC_API BOOL WINAPI XWeb_SetRect(HXCGUI hWebBrowser,in_ RECT *pRect); //��������
XC_API BOOL WINAPI XWeb_ExeJavascript(HXCGUI hWebBrowser,wchar_t *pFun,wchar_t* pParam[],int paramCount);
XC_API void WINAPI XWeb_RegEvent(HXCGUI hWebBrowser,int type,void *pFun);
XC_API void WINAPI XWeb_RegExternalFunction0(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External0 pFun);  //ע��Js�ⲿ����
XC_API void WINAPI XWeb_RegExternalFunction1(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External1 pFun);  //ע��Js�ⲿ����
XC_API void WINAPI XWeb_RegExternalFunction2(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External2 pFun);  //ע��Js�ⲿ����
XC_API void WINAPI XWeb_RegExternalFunction3(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External3 pFun);  //ע��Js�ⲿ����
XC_API void WINAPI XWeb_RegExternalFunction4(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External4 pFun);  //ע��Js�ⲿ����
XC_API void WINAPI XWeb_RegExternalFunction5(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External5 pFun);  //ע��Js�ⲿ����
XC_API void WINAPI XWeb_RegExternalFunction6(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External6 pFun);  //ע��Js�ⲿ����
XC_API void WINAPI XWeb_RegExternalFunction7(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External7 pFun);  //ע��Js�ⲿ����
XC_API void WINAPI XWeb_RegExternalFunction8(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External8 pFun);  //ע��Js�ⲿ����
XC_API HRESULT WINAPI XWeb_get_AddressBar(HXCGUI hWebBrowser,out_ BOOL *pbValue);
XC_API HRESULT WINAPI XWeb_put_AddressBar(HXCGUI hWebBrowser,BOOL bValue);
XC_API HRESULT WINAPI XWeb_get_Application(HXCGUI hWebBrowser,IDispatch **ppDisp);
XC_API HRESULT WINAPI XWeb_get_Busy(HXCGUI hWebBrowser,out_ BOOL *pbBool);
XC_API HRESULT WINAPI XWeb_ClientToWindow(HXCGUI hWebBrowser,in_out_ int *pcx,in_out_ int *pcy);
XC_API HRESULT WINAPI XWeb_get_Container(HXCGUI hWebBrowser,IDispatch **ppDisp);
XC_API HRESULT WINAPI XWeb_get_Document(HXCGUI hWebBrowser,IDispatch **ppDisp);
XC_API HRESULT WINAPI XWeb_ExecWB(HXCGUI hWebBrowser,in_ OLECMDID cmdID,in_ OLECMDEXECOPT cmdexecopt,in_ VARIANT *pvaIn,in_out_ VARIANT *pvaOut);
XC_API HRESULT WINAPI XWeb_get_FullName(HXCGUI hWebBrowser,out_ wchar_t *pOut,in_ int outLen);
XC_API HRESULT WINAPI XWeb_get_FullScreen(HXCGUI hWebBrowser,BOOL *pbFullScreen);
XC_API HRESULT WINAPI XWeb_put_FullScreen(HXCGUI hWebBrowser,BOOL bFullScreen);
XC_API HRESULT WINAPI XWeb_GetProperty(HXCGUI hWebBrowser,in_ wchar_t *pProperty,out_ VARIANT *pvtValue);
XC_API HRESULT WINAPI XWeb_GoBack(HXCGUI hWebBrowser);
XC_API HRESULT WINAPI XWeb_GoForward(HXCGUI hWebBrowser);
XC_API HRESULT WINAPI XWeb_GoHome(HXCGUI hWebBrowser);
XC_API HRESULT WINAPI XWeb_GoSearch(HXCGUI hWebBrowser);
XC_API HRESULT WINAPI XWeb_get_Height(HXCGUI hWebBrowser,out_ long *pl);
XC_API HRESULT WINAPI XWeb_put_Height(HXCGUI hWebBrowser,in_ long height);
XC_API HRESULT WINAPI XWeb_get_HWND(HXCGUI hWebBrowser,out_ long *pHWND);
XC_API HRESULT WINAPI XWeb_get_Left(HXCGUI hWebBrowser,out_ long *pl);
XC_API HRESULT WINAPI XWeb_put_Left(HXCGUI hWebBrowser,in_ long left);
XC_API HRESULT WINAPI XWeb_get_LocationName(HXCGUI hWebBrowser,out_ wchar_t *pLocationName,in_ int outLen);
XC_API HRESULT WINAPI XWeb_get_LocationURL(HXCGUI hWebBrowser,out_ wchar_t *pLocationURL,in_ int outLen);
XC_API HRESULT WINAPI XWeb_get_MenuBar(HXCGUI hWebBrowser,out_ BOOL *pbValue);
XC_API HRESULT WINAPI XWeb_put_MenuBar(HXCGUI hWebBrowser,in_ BOOL bValue);
XC_API HRESULT WINAPI XWeb_get_Name(HXCGUI hWebBrowser,out_ wchar_t *pName,in_ int outLen);
XC_API HRESULT WINAPI XWeb_Navigate(HXCGUI hWebBrowser,in_ wchar_t *pUrl,in_ VARIANT *Flags,in_ VARIANT *TargetFrameName,in_ VARIANT *PostData,in_ VARIANT *Headers);
XC_API HRESULT WINAPI XWeb_Navigate2(HXCGUI hWebBrowser,in_ VARIANT *URL,in_ VARIANT *Flags,in_ VARIANT *TargetFrameName,in_ VARIANT *PostData,in_ VARIANT *Headers);
XC_API HRESULT WINAPI XWeb_get_Offline(HXCGUI hWebBrowser,out_ BOOL *pbOffline);
XC_API HRESULT WINAPI XWeb_put_Offline(HXCGUI hWebBrowser,in_ BOOL bOffline);
XC_API HRESULT WINAPI XWeb_get_Parent(HXCGUI hWebBrowser,IDispatch **ppDisp);
XC_API HRESULT WINAPI XWeb_get_Path(HXCGUI hWebBrowser,out_ wchar_t *pPath,in_ int outLen);
XC_API HRESULT WINAPI XWeb_PutProperty(HXCGUI hWebBrowser,in_ wchar_t *pProperty,in_ VARIANT vtValue);
XC_API HRESULT WINAPI XWeb_QueryStatusWB(HXCGUI hWebBrowser,in_ OLECMDID cmdID,out_ OLECMDF *pcmdf);
XC_API HRESULT WINAPI XWeb_Quit(HXCGUI hWebBrowser);
XC_API HRESULT WINAPI XWeb_get_ReadyState(HXCGUI hWebBrowser,out_ READYSTATE *plReadyState);
XC_API HRESULT WINAPI XWeb_Refresh(HXCGUI hWebBrowser);
XC_API HRESULT WINAPI XWeb_Refresh2(HXCGUI hWebBrowser,in_ int level);
XC_API HRESULT WINAPI XWeb_get_RegisterAsBrowser(HXCGUI hWebBrowser,out_ BOOL *pbRegister);
XC_API HRESULT WINAPI XWeb_put_RegisterAsBrowser(HXCGUI hWebBrowser,in_ BOOL bRegister);
XC_API HRESULT WINAPI XWeb_get_RegisterAsDropTarget(HXCGUI hWebBrowser,out_ BOOL *pbRegister);
XC_API HRESULT WINAPI XWeb_put_RegisterAsDropTarget(HXCGUI hWebBrowser,in_ BOOL bRegister);
XC_API HRESULT WINAPI XWeb_get_Resizable(HXCGUI hWebBrowser,out_ BOOL *pbValue);
XC_API HRESULT WINAPI XWeb_put_Resizable(HXCGUI hWebBrowser,in_ BOOL bValue);
XC_API HRESULT WINAPI XWeb_ShowBrowserBar(HXCGUI hWebBrowser,in_ VARIANT *pvaClsid,in_ BOOL bShow);
XC_API HRESULT WINAPI XWeb_get_Silent(HXCGUI hWebBrowser,out_ BOOL *pbSilent);
XC_API HRESULT WINAPI XWeb_put_Silent(HXCGUI hWebBrowser,in_ BOOL bSilent);
XC_API HRESULT WINAPI XWeb_get_StatusBar(HXCGUI hWebBrowser,out_ BOOL *pbBool);
XC_API HRESULT WINAPI XWeb_put_StatusBar(HXCGUI hWebBrowser,in_ BOOL bValue);
XC_API HRESULT WINAPI XWeb_get_StatusText(HXCGUI hWebBrowser,out_ wchar_t *pOut,in_ int outLen);
XC_API HRESULT WINAPI XWeb_put_StatusText(HXCGUI hWebBrowser,in_ wchar_t *pStatusText);
XC_API HRESULT WINAPI XWeb_Stop(HXCGUI hWebBrowser);
XC_API HRESULT WINAPI XWeb_get_TheaterMode(HXCGUI hWebBrowser,out_ BOOL *pbRegister);
XC_API HRESULT WINAPI XWeb_put_TheaterMode(HXCGUI hWebBrowser,in_ BOOL bRegister);
XC_API HRESULT WINAPI XWeb_get_ToolBar(HXCGUI hWebBrowser,out_ int *pValue);
XC_API HRESULT WINAPI XWeb_put_ToolBar(HXCGUI hWebBrowser,in_ int value);
XC_API HRESULT WINAPI XWeb_get_Top(HXCGUI hWebBrowser,out_ long *pl);
XC_API HRESULT WINAPI XWeb_put_Top(HXCGUI hWebBrowser,in_ long top);
XC_API HRESULT WINAPI XWeb_get_TopLevelContainer(HXCGUI hWebBrowser,out_ BOOL *pbBool);
XC_API HRESULT WINAPI XWeb_get_Type(HXCGUI hWebBrowser,out_ wchar_t *pOut,in_ int outLen);
XC_API HRESULT WINAPI XWeb_get_Visible(HXCGUI hWebBrowser,out_ BOOL *pBool);
XC_API HRESULT WINAPI XWeb_put_Visible(HXCGUI hWebBrowser,in_ BOOL bValue);
XC_API HRESULT WINAPI XWeb_get_Width(HXCGUI hWebBrowser,out_ long *pl);
XC_API HRESULT WINAPI XWeb_put_Width(HXCGUI hWebBrowser,in_ long width);
XC_API void WINAPI XWnd_RegisterMessageEx(HWINDOW hWindow,int message,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);  //ע����Ϣ�ص�����
XC_API void WINAPI XWnd_RegisterNCMessageEx(HWINDOW hWindow,int message,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //ע��ǿͻ�����Ϣ
XC_API void WINAPI XWnd_RegisterMsgProcEx(HWINDOW hWindow,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);	//ע�ᴰ����Ϣ�������
XC_API HWINDOW WINAPI XWnd_CreateWindow(int x,int y,int cx,int cy,wchar_t *pTitle,HWND hWndParent=NULL,int XCStyle=XC_SY_DEFAULT);
XC_API HWINDOW WINAPI XWnd_CreateWindowEx(DWORD dwExStyle, wchar_t* lpClassName,wchar_t* lpWindowName,DWORD dwStyle, int x,int y,int cx,int cy,HWND hWndParent,int XCStyle=XC_SY_DEFAULT);
XC_API void WINAPI XWnd_RegisterMessage(HWINDOW hWindow,int message,void *pFun);  //ע����Ϣ�ص�����
XC_API void WINAPI XWnd_RegisterNCMessage(HWINDOW hWindow,int message,void *pFun); //ע��ǿͻ�����Ϣ
XC_API void WINAPI XWnd_RegisterMsgProc(HWINDOW hWindow,pFunWndMsgProc pFun);	//ע�ᴰ����Ϣ�������
XC_API void WINAPI XWnd_GetDrawRect(HWINDOW hWindow,out_ RECT *pRect);//��ȡ��ǰ��������(�����ǿͻ���)
XC_API HELE WINAPI XWnd_GetFocusEle(HWINDOW hWindow); //��ȡӵ�н����Ԫ��
XC_API HWND WINAPI XWnd_GetHWnd(HWINDOW hWindow); //��ȡ���ھ��
XC_API HELE WINAPI XWnd_GetEle(HWINDOW hWindow,int eleID); //ͨ��ID��ȡԪ�ؾ��
XC_API HICON WINAPI XWnd_GetIcon(HWINDOW hWindow,BOOL bBigIcon);//��ȡ����ͼ��
XC_API int WINAPI XWnd_GetWindowText(HWINDOW hWindow,wchar_t *pOut,int len);
XC_API BOOL WINAPI XWnd_SetWindowText(HWINDOW hWindow,wchar_t *pText);
XC_API void WINAPI XWnd_SetFont(HWINDOW hWindow,HFONTX hFontX);
XC_API DWORD WINAPI XWnd_SetIcon(HWINDOW hWindow,HICON hIcon,BOOL bBigIcon);
XC_API DWORD WINAPI XWnd_SetIcon2(HWINDOW hWindow,wchar_t *pFileName,BOOL bBigIcon);
XC_API void WINAPI XWnd_SetIconSize(HWINDOW hWindow,int width,int height);  //���ñ�����ͼ����ʾ��С
XC_API void WINAPI XWnd_SetFontCaptionText(HWINDOW hWindow,HFONTX hFontX);//���ñ���������
XC_API void WINAPI XWnd_SetColorCaptionText(HWINDOW hWindow,COLORREF color);//���ñ�����������ɫ
XC_API UINT WINAPI XWnd_SetTimer(HWINDOW hWindow,UINT nIDEvent,UINT uElapse); //���ö�ʱ��
XC_API BOOL WINAPI XWnd_KillTimer(HWINDOW hWindow,UINT nIDEvent);
XC_API UINT WINAPI XWnd_SetTimerEx(HWINDOW hWindow,UINT nIDEvent,UINT uElapse,int userData=0);
XC_API BOOL WINAPI XWnd_KillTimerEx(HWINDOW hWindow,UINT nIDEvent);
XC_API void WINAPI XWnd_SetMinWidth(HWINDOW hWindow,int width);  //���ô�����С���
XC_API void WINAPI XWnd_SetMinHeight(HWINDOW hWindow,int height); //���ô�����С�߶�
XC_API void WINAPI XWnd_SetRoundSize(HWINDOW hWindow,int size);    //���ô���Բ�Ǵ�С,��Բ�Ǵ�����Ч
XC_API void WINAPI XWnd_AddEle(HWINDOW hWindow,HELE hEle);
XC_API void WINAPI XWnd_AddEleNC(HWINDOW hWindow,HELE hEle); //��ӵ��ǿͻ���
XC_API void WINAPI XWnd_AddMenuBar(HWINDOW hWindow,HELE hEle); //��ӹ�����
XC_API void WINAPI XWnd_AddToolBar(HWINDOW hWindow,HELE hEle); //��ӹ�����
XC_API void WINAPI XWnd_Adjust(HWINDOW hWindow);  //�������ڲ���
XC_API void WINAPI XWnd_MaximizeWnd(HWINDOW hWindow,BOOL bMax); //��� ��ԭ����
XC_API BOOL WINAPI XWnd_IsMaximizeWnd(HWINDOW hWindow);  //�����Ƿ����
XC_API void WINAPI XWnd_RedrawWndRect(HWINDOW hWindow,RECT *pRect,BOOL bImmediately=FALSE); //�ػ洰��ָ������
XC_API void WINAPI XWnd_RedrawWnd(HWINDOW hWindow,BOOL bImmediately=FALSE); //�ػ洰��
XC_API void WINAPI XWnd_RedrawEleRectNC(HWINDOW hWindow,HELE hEle,RECT *pRect);
XC_API void WINAPI XWnd_EnableDragBorder(HWINDOW hWindow,BOOL bDrag);  //ʹ���϶��߿�
XC_API void WINAPI XWnd_EnableDragWindow(HWINDOW hWindow,BOOL bDrag);  //�϶�����
XC_API HELE WINAPI XWnd_GetButtonMin(HWINDOW hWindow);   //��С����ť
XC_API HELE WINAPI XWnd_GetButtonMax(HWINDOW hWindow);   //��󻯰�ť
XC_API HELE WINAPI XWnd_GetButtonClose(HWINDOW hWindow); //�رհ�ť
XC_API void WINAPI XWnd_EnableMinButton(HWINDOW hWindow,BOOL bEnable,BOOL bRedraw=FALSE); //������С����ť
XC_API void WINAPI XWnd_EnableMaxButton(HWINDOW hWindow,BOOL bEnable,BOOL bRedraw=FALSE); //������󻯰�ť
XC_API void WINAPI XWnd_EnableCloseButton(HWINDOW hWindow,BOOL bEnable,BOOL bRedraw=FALSE);  //���ùرհ�ť
XC_API void WINAPI XWnd_EnableRound(HWINDOW hWindow,BOOL bEnable,BOOL bRedraw=FALSE); //Բ�ǹ��ܵ�������ر�
XC_API int  WINAPI XWnd_GetChildEleCount(HWINDOW hWindow);
XC_API int  WINAPI XWnd_GetChildEleCountNC(HWINDOW hWindow);
XC_API HELE WINAPI XWnd_GetChildEleByIndex(HWINDOW hWindow,int index);
XC_API HELE WINAPI XWnd_GetChildEleByIndexNC(HWINDOW hWindow,int index);
XC_API void WINAPI XWnd_SetTransparentFlag(HWINDOW hWindow,int flag);  //����͸������
XC_API void WINAPI XWnd_SetTransparentAlpha(HWINDOW hWindow,BYTE alpha); //���ô���͸����
XC_API void WINAPI XWnd_SetTransparentColor(HWINDOW hWindow,COLORREF color); //���ô���͸��ɫ
XC_API void WINAPI XWnd_SetImage(HWINDOW hWindow,HIMAGE hImage=NULL);    //�ͻ���ͼƬ
XC_API void WINAPI XWnd_SetImageNC(HWINDOW hWindow,HIMAGE hImage=NULL);  //�ǿͻ�������ͼƬ
XC_API void WINAPI XWnd_SetImageCaption(HWINDOW hWindow,HIMAGE hImage=NULL);   //������ͼƬ
XC_API void WINAPI XWnd_SetImageBorderLeft(HWINDOW hWindow,HIMAGE hImage=NULL);    //�߿�ͼƬ
XC_API void WINAPI XWnd_SetImageBorderRight(HWINDOW hWindow,HIMAGE hImage=NULL);    //�߿�ͼƬ
XC_API void WINAPI XWnd_SetImageBorderBottom(HWINDOW hWindow,HIMAGE hImage=NULL);    //�߿�ͼƬ
XC_API void WINAPI XWnd_SetBkColor(HWINDOW hWindow,COLORREF color); //���ñ�����ɫ
XC_API void WINAPI XWnd_EnableBorderStrokeInner(HWINDOW hWindow,BOOL bStroke); //���û������ ��
XC_API void WINAPI XWnd_EnableBorderStrokeOuter(HWINDOW hWindow,BOOL bStroke); //���û������ ��
XC_API void WINAPI XWnd_SetBorderStrokeInnerColor(HWINDOW hWindow,COLORREF color1,COLORREF color2); //���������ɫ ��
XC_API void WINAPI XWnd_SetBorderStrokeOuterColor(HWINDOW hWindow,COLORREF color1,COLORREF color2); //���������ɫ ��
XC_API void WINAPI XWnd_CloseWindow(HWINDOW hWindow);  //�رմ���
XC_API void WINAPI XWnd_CreateCaret(HWINDOW hWindow,HELE hEle, int width, int height);//���������
XC_API void WINAPI XWnd_SetCaretSize(HWINDOW hWindow,int width, int height); //���ò������С
XC_API void WINAPI XWnd_SetCaretPos(HWINDOW hWindow,int x,int y); //���ò����λ��
XC_API void WINAPI XWnd_SetCaretPosEx(HWINDOW hWindow,int x,int y,int width,int height); //���ò����λ��
XC_API void WINAPI XWnd_SetCaretColor(HWINDOW hWindow,COLORREF color); //���ò������ɫ
XC_API void WINAPI XWnd_ShowCaret(HWINDOW hWindow,BOOL bShow);  //��ʾ�����
XC_API void WINAPI XWnd_DestroyCaret(HWINDOW hWindow);    //���ٲ����
XC_API BOOL WINAPI XWnd_GetClientRect(HWINDOW hWindow,out_ RECT *pRect); //��ȡ�ͻ�������(���Ͻ�0,0)
XC_API void WINAPI XWnd_GetNCClientRect(HWINDOW hWindow,out_ RECT *pRect); //�ǿͻ�������,������������(���Ͻ�0,0)
XC_API int WINAPI XWnd_GetClientLeft(HWINDOW hWindow); //�ͻ�������
XC_API int WINAPI XWnd_GetClientTop(HWINDOW hWindow);  //�ͻ����ϼ��
XC_API int WINAPI XWnd_GetClientRight(HWINDOW hWindow); //�ͻ����Ҽ��
XC_API int WINAPI XWnd_GetClientBottom(HWINDOW hWindow); //�ͻ����¼��
XC_API int WINAPI XWnd_GetCaptionHeight(HWINDOW hWindow); //��ȡ�������߶�
XC_API void WINAPI XWnd_SetBorderSize(HWINDOW hWindow,int left,int top,int right,int bottom); //���ô��ڱ߿��С
XC_API void WINAPI XWnd_SetCaptionHeight(HWINDOW hWindow,int captionHeight); //���ñ������߶�
XC_API void WINAPI XWnd_WindowToClientRect(HWINDOW hWindow,in_out_ RECT *pRect); //���ڷǿͻ�������ת�����ͻ�������
XC_API void WINAPI XWnd_WindowToClientPt(HWINDOW hWindow,in_out_ POINT *pPt); //���ڷǿͻ�����ת�����ͻ��������
XC_API void WINAPI XWnd_SetUserData(HWINDOW hWindow,int data);
XC_API int  WINAPI XWnd_GetUserData(HWINDOW hWindow);
XC_API BOOL WINAPI XWnd_ShowWindow(HWINDOW hWindow,int nCmdShow);
XC_API BOOL WINAPI XWnd_SetWindowPos(HWINDOW hWindow,HWND hWndInsertAfter,int x,int y,int cx,int cy,UINT uFlags);
XC_API BOOL WINAPI XWnd_SetWindowRect(HWINDOW hWindow,in_ RECT *pRect);
XC_API BOOL WINAPI XWnd_SetWindowSize(HWINDOW hWindow,int width,int height);
XC_API BOOL WINAPI XWnd_GetWindowRect(HWINDOW hWindow,out_ RECT *pRect);
XC_API BOOL WINAPI XWnd_IsWindowVisible(HWINDOW hWindow);
XC_API int WINAPI XC_GetObjectType(HXCGUI hXCGUI); //��ȡ��Դ����
XC_API BOOL WINAPI XC_IsHELE(HELE hEle); //�����
XC_API BOOL WINAPI XC_IsHWINDOW(HWINDOW hWindow); //�����
XC_API BOOL WINAPI XC_IsSViewExtend(HELE hEle);  //�ж�Ԫ���Ƿ�ӹ�����ͼԪ����չ����Ԫ��,����������ͼԪ��
XC_API BOOL WINAPI XC_IsEditExtend(HELE hEle); //�жϸ�Ԫ���Ƿ��ָ��Ԫ����չ����
XC_API int WINAPI XC_UnicodeToAnsi(wchar_t *pIn,int inLen,char *pOut,int outLen);
XC_API int WINAPI XC_AnsiToUnicode(char *pIn,int inLen,wchar_t *pOut,int outLen);
XC_API int WINAPI XC_HexToDec(wchar_t *pHex);
XC_API void WINAPI XC_SetResourcesModule(HMODULE hModule);  //������Դģ����
XC_API BOOL WINAPI XC_RectInRect(RECT *pRect1,RECT *pRect2);
XC_API void WINAPI XC_CombineRect(RECT *pDest,RECT *pSrc1,RECT *pSrc2);
XC_API HMODULE WINAPI XC_GetModuleHandle(wchar_t *pModuleName);
XC_API HMODULE WINAPI XC_GetModuleHandle2();
XC_API HANDLE WINAPI XC_LoadImage(HINSTANCE hinst,wchar_t * lpszName,UINT uType,int cxDesired,int cyDesired,UINT fuLoad);
XC_API HFONT WINAPI XC_CreateFont(wchar_t *pName=L"����",int size=12,BOOL bBold=FALSE,BOOL bItalic=FALSE,BOOL bUnderline=FALSE,BOOL bStrikeOut=FALSE);
XC_API void  WINAPI XC_InitFont(LOGFONTW *pFont,wchar_t *pName,int size,BOOL bBold=FALSE,BOOL bItalic=FALSE,BOOL bUnderline=FALSE,BOOL bStrikeOut=FALSE);
XC_API  void* WINAPI XC_Malloc(int size);
XC_API  void  WINAPI XC_Free(void *p);
XC_API BOOL WINAPI XML_Register(int type,void *pFun); //ע��ص�����
XC_API BOOL WINAPI XC_RegisterWndClass(wchar_t *pClassName,HICON hIcon=NULL); //ע�ᴰ����
XC_API BOOL WINAPI XInitXCGUI(wchar_t *pText=NULL);
XC_API void WINAPI XRunXCGUI();
XC_API void WINAPI XExitProcess(); //�˳�����(�൱��������)
XC_API void WINAPI xtrace(char *pszFormat, ...);
XC_API void WINAPI xtracew(wchar_t *pszFormat, ...);


#endif //XCGUI_HEADER_FILE_