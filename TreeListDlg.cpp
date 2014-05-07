//*****************************************************************************
//*
//*
//*		TreeListDlg.cpp
//*
//*
//*****************************************************************************
#include	"StdAfx.h"
#include	"TreeList.h"
#include	"TreeListDlg.h"

#ifdef		_DEBUG
#define new	 DEBUG_NEW
#undef		 THIS_FILE
static char	 THIS_FILE[] = __FILE__;
#endif


TCHAR	   *pItems1[]	    = {_T("Europe" ),_T("Asia"   ),_T("America")};
TCHAR	   *pItems2[]		= {_T("Austria"),_T("Germany"),_T("China"  ),_T("Japan" ),_T("Canada"),_T("Mexico" )};
TCHAR	   *pItems3[]		= {_T("Vienna" ),_T("Graz"   ),_T("Linz"   ),_T("Berlin"),_T("Munich"),_T("Hamburg"),_T("Beijing"),_T("Shanghai"),_T("Hongkong"),_T("Tokyo"),_T("Osaka"),_T("Kobe"),_T("Ottawa"),_T("Toronto"),_T("Vancouver"),_T("Mexico City"),_T("Monerrey"),_T("Guadalajara")};
							   
#define 	ENTRIES(a)	(sizeof(a)/sizeof(a[0]))
#define 	IDC_TREELIST	123
#define 	USER_DATA_SIZE	256

COLORREF	aColors[]= 	{
							TV_NOCOLOR,
							RGB(0,0,0),
							RGB(255,0,0),
							RGB(0,255,0),
							RGB(0,0,255),
							RGB(255,255,0),
							RGB(255,0,255),
							RGB(0,255,255),
							RGB(128,128,128),
							RGB(255,128,128),
							RGB(128,255,128),
							RGB(128,128,255),
							RGB(255,255,128),
							RGB(255,128,255),
							RGB(128,255,255),
							RGB(192,192,192),
							RGB(255,192,192),
							RGB(192,255,192),
							RGB(192,192,255),
							RGB(255,255,192),
							RGB(255,192,255),
							RGB(192,255,255),
							RGB(255,255,255),
							};


int			aComboIds[] =	{
							IDC_COMBO1,
							IDC_COMBO2,
							IDC_COMBO3,
							IDC_COMBO4,
							IDC_COMBO5,
							IDC_COMBO6,
							IDC_COMBO7,
							IDC_COMBO8,
							};

int			aIdList[] =		{
							IDC_CHECK1	,TVS_HASBUTTONS         ,0,
							IDC_CHECK2	,TVS_HASLINES           ,0,
							IDC_CHECK3	,TVS_LINESATROOT        ,0,
							IDC_CHECK4	,TVS_SHOWSELALWAYS      ,0,
							IDC_CHECK5	,TVS_NOTOOLTIPS         ,0,
							IDC_CHECK6	,TVS_CHECKBOXES         ,0,
							IDC_CHECK7	,TVS_TRACKSELECT        ,0,
							IDC_CHECK8	,TVS_SINGLEEXPAND       ,0,
							IDC_CHECK9 	,TVS_FULLROWSELECT      ,0,
							IDC_CHECK10	,TVS_NOSCROLL           ,0,
							IDC_CHECK11	,TVS_NONEVENHEIGHT      ,0,
							IDC_CHECK18	,TVS_EDITLABELS         ,0,
							IDC_CHECK12	,TVS_EX_ITEMLINES		,1,
							IDC_CHECK13	,TVS_EX_ALTERNATECOLOR	,1,
							IDC_CHECK14	,TVS_EX_SUBSELECT		,1,
							IDC_CHECK15	,TVS_EX_FULLROWMARK		,1,
							IDC_CHECK16	,TVS_EX_MULTISELECT		,1,
							IDC_CHECK17	,TVS_EX_AUTOHSCROLL 	,1,
							IDC_CHECK22	,TVS_EX_TOOLTIPNOTIFY	,1,
							IDC_CHECK31	,TVS_EX_BITCHECKBOX  	,1,
							IDC_CHECK32	,TVS_EX_NOCOLUMNRESIZE 	,1,
							IDC_CHECK33	,TVS_EX_NOCHARSELCET 	,1,
							IDC_CHECK34	,TVS_EX_HIDEHEADERS		,1,
							IDC_CHECK35	,TVS_EX_GRAYEDDISABLE	,1,
							IDC_CHECK38	,TVS_EX_FULLROWITEMS	,1,
							IDC_CHECK39	,TVS_EX_FIXEDCOLSIZE	,1,
							IDC_CHECK41	,TVS_EX_EDITCLICK		,1,
							IDC_CHECK42	,TVS_EX_STEPOUT			,1,
							IDC_CHECK43	,TVS_EX_HEADERDRAGDROP	,1,
							};


BEGIN_MESSAGE_MAP(CTreeListDlg, CDialog)
	//{{AFX_MSG_MAP(CTreeListDlg)
	ON_WM_PAINT()
	ON_WM_DRAWITEM()
	ON_WM_SYSCOMMAND()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EDIT,		OnEdit)
	ON_BN_CLICKED(IDC_COMBO,	OnCombo)
	ON_BN_CLICKED(IDC_RADIO1, 	OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, 	OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, 	OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, 	OnRadio4)
	ON_BN_CLICKED(IDC_RADIO5, 	OnRadio5)
	ON_BN_CLICKED(IDC_RADIO6, 	OnRadio6)
	ON_BN_CLICKED(IDC_RADIO7, 	OnRadio7)
	ON_BN_CLICKED(IDC_RADIO8, 	OnRadio8)
	ON_BN_CLICKED(IDC_CHECK1,	OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2,  	OnCheck2)
	ON_BN_CLICKED(IDC_CHECK3,  	OnCheck3)
	ON_BN_CLICKED(IDC_CHECK4,  	OnCheck4)
	ON_BN_CLICKED(IDC_CHECK5,  	OnCheck5)
	ON_BN_CLICKED(IDC_CHECK6,  	OnCheck6)
	ON_BN_CLICKED(IDC_CHECK7,  	OnCheck7)
	ON_BN_CLICKED(IDC_CHECK8,  	OnCheck8)
	ON_BN_CLICKED(IDC_CHECK9,  	OnCheck9)
	ON_BN_CLICKED(IDC_CHECK10, 	OnCheck10)
	ON_BN_CLICKED(IDC_CHECK11, 	OnCheck11)
	ON_BN_CLICKED(IDC_CHECK12, 	OnCheck12)
	ON_BN_CLICKED(IDC_CHECK13, 	OnCheck13)
	ON_BN_CLICKED(IDC_CHECK14, 	OnCheck14)
	ON_BN_CLICKED(IDC_CHECK15, 	OnCheck15)
	ON_BN_CLICKED(IDC_CHECK16, 	OnCheck16)
	ON_BN_CLICKED(IDC_CHECK17, 	OnCheck17)
	ON_BN_CLICKED(IDC_CHECK18, 	OnCheck18)
	ON_BN_CLICKED(IDC_CHECK19, 	OnCheck19)
	ON_BN_CLICKED(IDC_CHECK20, 	OnCheck20)
	ON_BN_CLICKED(IDC_CHECK21, 	OnCheck21)
	ON_BN_CLICKED(IDC_CHECK22, 	OnCheck22)
	ON_BN_CLICKED(IDC_CHECK23, 	OnCheck23)
	ON_BN_CLICKED(IDC_CHECK24, 	OnCheck24)
	ON_BN_CLICKED(IDC_CHECK25, 	OnCheck25)
	ON_BN_CLICKED(IDC_CHECK26, 	OnCheck26)
	ON_BN_CLICKED(IDC_CHECK27,  OnCheck27)
	ON_BN_CLICKED(IDC_CHECK28, 	OnCheck28)
	ON_BN_CLICKED(IDC_CHECK29,  OnCheck29)
	ON_BN_CLICKED(IDC_CHECK30,  OnCheck30)
	ON_BN_CLICKED(IDC_CHECK31,  OnCheck31)
	ON_BN_CLICKED(IDC_CHECK32,  OnCheck32)
	ON_BN_CLICKED(IDC_CHECK33,  OnCheck33)
	ON_BN_CLICKED(IDC_CHECK34,  OnCheck34)
	ON_BN_CLICKED(IDC_CHECK35,  OnCheck35)
	ON_BN_CLICKED(IDC_CHECK36,  OnCheck36)
	ON_BN_CLICKED(IDC_CHECK37,  OnCheck37)
	ON_BN_CLICKED(IDC_CHECK38,  OnCheck38)
	ON_BN_CLICKED(IDC_CHECK39,  OnCheck39)
	ON_BN_CLICKED(IDC_CHECK40,	OnCheck40)
	ON_BN_CLICKED(IDC_CHECK41,	OnCheck41)
	ON_BN_CLICKED(IDC_CHECK42,	OnCheck42)
	ON_BN_CLICKED(IDC_CHECK43,	OnCheck43)
	ON_BN_CLICKED(IDC_CHECK44,	OnCheck44)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnChangeColor1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnChangeColor2)
	ON_CBN_SELCHANGE(IDC_COMBO3, OnChangeColor3)
	ON_CBN_SELCHANGE(IDC_COMBO4, OnChangeColor4)
	ON_CBN_SELCHANGE(IDC_COMBO5, OnChangeColor5)
	ON_CBN_SELCHANGE(IDC_COMBO6, OnChangeColor6)
	ON_CBN_SELCHANGE(IDC_COMBO7, OnChangeColor7)
	ON_CBN_SELCHANGE(IDC_COMBO8, OnChangeColor8)
	ON_CBN_SELCHANGE(IDC_COMBO9, OnChangeCheck)
	//}}AFX_MSG_MAP
	ON_NOTIFY(NM_RETURN,		 IDC_TREELIST, OnReturn)
	ON_NOTIFY(TVN_SELCHANGED,    IDC_TREELIST, OnSelChanged)
	ON_NOTIFY(TVN_COLUMNCLICK,   IDC_TREELIST, OnColumnClick)
	ON_NOTIFY(TVN_ITEMTOOLTIP,	 IDC_TREELIST, OnTooltipNotify)
	ON_NOTIFY(TVN_ITEMEXPANDED,  IDC_TREELIST, OnItemExpanded)
	ON_NOTIFY(TVN_ENDLABELEDIT,  IDC_TREELIST, OnEndLabelEdit)
	ON_NOTIFY(TVN_BEGINLABELEDIT,IDC_TREELIST, OnBeginLabelEdit)
	ON_NOTIFY(TVN_CBSTATECHANGED,IDC_TREELIST, OnCbStateChanged)
END_MESSAGE_MAP()


//*****************************************************************************
//*
//*		CDialog
//*
//*****************************************************************************
CTreeListDlg::CTreeListDlg(CWnd *pParent): CDialog(CTreeListDlg::IDD,pParent)
{
	//{{AFX_DATA_INIT(CTreeListDlg)
	m_bFullWidth	= TRUE;
	m_bOnlyReturn	= FALSE;
	m_bPtrList		= FALSE;
	m_bDblClick		= FALSE;
	m_bDropDown		= FALSE;
	m_bNextLine		= FALSE;
	m_bStateEnable	= FALSE;
	m_bIconClick	= FALSE;
	m_bAutoEnable	= FALSE;
	m_iCheckMode	= 0;
	m_iAutoEditMode = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

//*****************************************************************************
//*
//*		DoDataExchange
//*
//*****************************************************************************
void CTreeListDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTreeListDlg)
	DDX_Check  (pDX, IDC_CHECK23, m_bFullWidth);
	DDX_Check  (pDX, IDC_CHECK24, m_bOnlyReturn);
	DDX_Check  (pDX, IDC_CHECK25, m_bPtrList);
	DDX_Check  (pDX, IDC_CHECK26, m_bDblClick);
	DDX_Check  (pDX, IDC_CHECK27, m_bNextLine);
	DDX_Check  (pDX, IDC_CHECK28, m_bStateEnable);
	DDX_Check  (pDX, IDC_CHECK29, m_bIconClick);
	DDX_Check  (pDX, IDC_CHECK40, m_bDropDown);
	DDX_Radio  (pDX, IDC_RADIO1 , m_iAutoEditMode);
	DDX_CBIndex(pDX, IDC_COMBO9 , m_iCheckMode);
	//}}AFX_DATA_MAP
}

//*****************************************************************************
//*
//*		OnInitDialog
//*
//*****************************************************************************
BOOL CTreeListDlg::OnInitDialog()
{
CRect		sRect;
CPoint		sPoint(0,0);
CMenu      *pSysMenu;
HTREEITEM	hItem1[3];
HTREEITEM	hItem2[3*2];
HTREEITEM	hItem3[3*2*3];
unsigned	uStyle;
unsigned	uExStyle;
int			i,j;




	GetDlgItem(IDC_FRAME)->GetWindowRect(&sRect);
	ClientToScreen(&sPoint);

	sRect.left	 -= sPoint.x;
	sRect.right	 -= sPoint.x;
	sRect.top	 -= sPoint.y;
	sRect.bottom -= sPoint.y;

	uStyle		= TVS_HASBUTTONS|TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT|TVS_FULLROWSELECT;
	uExStyle	= TVS_EX_ITEMLINES|TVS_EX_ITEMLINES|TVS_EX_ALTERNATECOLOR|TVS_EX_SUBSELECT;
	m_hSelect	= NULL;
	m_iSelCol	= 0;
	
	m_cImages  .Create  (IDB_FLAGS ,16,8,RGB(0,255,255));
	m_cChecks  .Create  (IDB_CHECKS,16,8,RGB(0,255,255));
	m_cTreeList.CreateEx(WS_EX_CLIENTEDGE,uStyle|WS_CHILD|WS_VISIBLE|WS_TABSTOP,sRect,this,IDC_TREELIST);

	m_cTreeList.SetImageList(&m_cImages,TVSIL_NORMAL);
	m_cTreeList.InsertColumn(0,_T("Tree"));
	m_cTreeList.InsertColumn(1,_T("Column 1"));
	m_cTreeList.InsertColumn(2,_T("Column 2"));
	m_cTreeList.InsertColumn(3,_T("Column 3"));
	m_cTreeList.SetExtendedStyle(uExStyle);
	m_cTreeList.SetUserDataSize(USER_DATA_SIZE);



	for(i=0;i<ENTRIES(aComboIds);i++)
		{
		for(j=0;j<ENTRIES(aColors);j++)
			{
			((CComboBox*)GetDlgItem(aComboIds[i]))->InsertString(j,_T(""));
			}
		((CComboBox*)GetDlgItem(aComboIds[i]))->SetCurSel(0);
		}

	for(i=0;i<3;i++)
		{
		hItem1[i]=m_cTreeList.InsertItem(pItems1[i],i,i,TVI_ROOT);
		m_cTreeList.Expand(hItem1[i],TVE_EXPAND);
		}

	for(i=0;i<3*2;i++)
		{
		hItem2[i]=m_cTreeList.InsertItem(pItems2[i],i+3,i+3,hItem1[i/2]);
		if(i==0)m_cTreeList.Expand(hItem2[i],TVE_EXPAND);
		m_cTreeList.SetItem(hItem2[i],1+(i&1),TVIF_IMAGE|TVIF_TEXT,_T("Text"),i+3,i+3,0,0,0);
		}

	for(i=0;i<3*2*3;i++)
		{
		hItem3[i]=m_cTreeList.InsertItem(pItems3[i],TV_NOIMAGE,TV_NOIMAGE,hItem2[i/3]);
		m_cTreeList.SetItem(hItem3[i],1+(i&1),TVIF_TEXT,_T("Text"),0,0,0,0,0);
		}

	for(i=0;i<ENTRIES(aIdList);i+=3)
		{
		if(aIdList[i+2]==0)
			{
			if(uStyle&aIdList[i+1])GetDlgItem(aIdList[i])->SendMessage(BM_SETCHECK,BST_CHECKED);
			}
 
		if(aIdList[i+2]==1)
			{
			if(uExStyle&aIdList[i+1])GetDlgItem(aIdList[i])->SendMessage(BM_SETCHECK,BST_CHECKED);
			}
		}
 
 	CDialog::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT( IDM_ABOUTBOX < 0xF000);

	   pSysMenu  = GetSystemMenu(FALSE);
	if(pSysMenu != NULL)
		{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if(!strAboutMenu.IsEmpty())
			{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
			}
		}

	SetIcon(m_hIcon, TRUE); 	
	SetIcon(m_hIcon, FALSE);	



return TRUE;  
}

//*****************************************************************************
//*
//*		OnSysCommand
//*
//*****************************************************************************
void CTreeListDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if((nID & 0xFFF0) == IDM_ABOUTBOX)
		{
		CDialog dlgAbout(IDD_ABOUTBOX);
		dlgAbout.DoModal();
		}
	else{
		if(nID==0xF060)OnCancel();
		CDialog::OnSysCommand(nID, lParam);
		}
}

//*****************************************************************************
//*
//*		OnPaint
//*
//*****************************************************************************
void CTreeListDlg::OnPaint()
{
	if(IsIconic())
		{
		CPaintDC dc(this);						

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		
		GetClientRect(&rect);
		
		int x = (rect.Width () - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
		}
	else{
		CDialog::OnPaint();
		}
}

//*****************************************************************************
//*
//*		OnQueryDragIcon
//*
//*****************************************************************************
HCURSOR CTreeListDlg::OnQueryDragIcon()
{

return (HCURSOR) m_hIcon;
}


//*****************************************************************************
//*
//*		OnDrawItem
//*
//*****************************************************************************
void CTreeListDlg::OnDrawItem(int nIDCtl,LPDRAWITEMSTRUCT pDrawItemStruct) 
{
unsigned	uId;



	uId = GetWindowLong(pDrawItemStruct->hwndItem,GWL_ID);

	if(uId==IDC_COMBO9)
		{
		COLORREF	uColor;
		CPoint		sPt(pDrawItemStruct->rcItem.left+10,pDrawItemStruct->rcItem.top);
		CDC		   *pDc=CDC::FromHandle(pDrawItemStruct->hDC);

		                                           uColor=RGB(255,255,255);
		if(pDrawItemStruct->itemState&ODS_FOCUS   )uColor=RGB(108,148,255);
		if(pDrawItemStruct->itemState&ODS_DISABLED)uColor=GetSysColor(COLOR_3DFACE);

		SetBkColor(pDrawItemStruct->hDC,uColor);
		ExtTextOut(pDrawItemStruct->hDC,0,0,ETO_OPAQUE,&pDrawItemStruct->rcItem,NULL,0,NULL);
		
		m_cChecks.Draw(pDc,pDrawItemStruct->itemID*2  ,sPt,ILD_TRANSPARENT); sPt.x += 24;
		m_cChecks.Draw(pDc,pDrawItemStruct->itemID*2+1,sPt,ILD_TRANSPARENT);
		
		return;
		}


	if(pDrawItemStruct->itemID<=0)
		{
		SetBkColor  (pDrawItemStruct->hDC,GetSysColor(COLOR_WINDOW));
		SetTextColor(pDrawItemStruct->hDC,GetSysColor(COLOR_WINDOWTEXT));
		ExtTextOut  (pDrawItemStruct->hDC,3,3,ETO_OPAQUE,&pDrawItemStruct->rcItem,_T(" default"),8,NULL);
		}
	else{
		SetBkColor(pDrawItemStruct->hDC,aColors[pDrawItemStruct->itemID]);
		ExtTextOut(pDrawItemStruct->hDC,0,0,ETO_OPAQUE,&pDrawItemStruct->rcItem,NULL,0,NULL);
		}

}


//*****************************************************************************
//*
//*		OnCheck
//*
//*****************************************************************************
void CTreeListDlg::OnCheck1 (){OnCheck(IDC_CHECK1 );}
void CTreeListDlg::OnCheck2 (){OnCheck(IDC_CHECK2 );}
void CTreeListDlg::OnCheck3 (){OnCheck(IDC_CHECK3 );}
void CTreeListDlg::OnCheck4 (){OnCheck(IDC_CHECK4 );}
void CTreeListDlg::OnCheck5 (){OnCheck(IDC_CHECK5 );}
void CTreeListDlg::OnCheck6 (){OnCheck(IDC_CHECK6 );}
void CTreeListDlg::OnCheck7 (){OnCheck(IDC_CHECK7 );}
void CTreeListDlg::OnCheck8 (){OnCheck(IDC_CHECK8 );}
void CTreeListDlg::OnCheck9 (){OnCheck(IDC_CHECK9 );}
void CTreeListDlg::OnCheck10(){OnCheck(IDC_CHECK10);}
void CTreeListDlg::OnCheck11(){OnCheck(IDC_CHECK11);}
void CTreeListDlg::OnCheck12(){OnCheck(IDC_CHECK12);}
void CTreeListDlg::OnCheck13(){OnCheck(IDC_CHECK13);}
void CTreeListDlg::OnCheck14(){OnCheck(IDC_CHECK14);}
void CTreeListDlg::OnCheck15(){OnCheck(IDC_CHECK15);}
void CTreeListDlg::OnCheck16(){OnCheck(IDC_CHECK16);}
void CTreeListDlg::OnCheck17(){OnCheck(IDC_CHECK17);}
void CTreeListDlg::OnCheck18(){OnCheck(IDC_CHECK18);}
void CTreeListDlg::OnCheck22(){OnCheck(IDC_CHECK22);}
void CTreeListDlg::OnCheck31(){OnCheck(IDC_CHECK31);}
void CTreeListDlg::OnCheck32(){OnCheck(IDC_CHECK32);}
void CTreeListDlg::OnCheck33(){OnCheck(IDC_CHECK33);}
void CTreeListDlg::OnCheck34(){OnCheck(IDC_CHECK34);}
void CTreeListDlg::OnCheck35(){OnCheck(IDC_CHECK35);}
void CTreeListDlg::OnCheck36(){OnCheck(IDC_CHECK36);}
void CTreeListDlg::OnCheck37(){OnCheck(IDC_CHECK37);}
void CTreeListDlg::OnCheck38(){OnCheck(IDC_CHECK38);}
void CTreeListDlg::OnCheck39(){OnCheck(IDC_CHECK39);}
void CTreeListDlg::OnCheck41(){OnCheck(IDC_CHECK41);}
void CTreeListDlg::OnCheck42(){OnCheck(IDC_CHECK42);}
void CTreeListDlg::OnCheck43(){OnCheck(IDC_CHECK43);}
void CTreeListDlg::OnCheck44(){OnCheck(IDC_CHECK44);}
void CTreeListDlg::OnCheck(int iID) 
{
int			i,iOn;
unsigned 	uStyle;
unsigned	uStyleEx;



	for(i=0;i<ENTRIES(aIdList);i+=3)
		{
		if(aIdList[i]!=iID)continue;

		iOn	   = (GetDlgItem(iID)->SendMessage(BM_GETCHECK)==BST_CHECKED)? 1:0;
		uStyle =  GetWindowLong(m_cTreeList.m_hWnd,GWL_STYLE);

		if(aIdList[i+2]==0)
			{
			
			if(iOn)uStyle|= aIdList[i+1];
			else   uStyle&=~aIdList[i+1];	
			
			SetWindowLong(m_cTreeList.m_hWnd,GWL_STYLE,uStyle);
			GetDlgItem(IDC_EDIT   )->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_COMBO  )->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			
			GetDlgItem(IDC_RADIO1 )->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_RADIO2 )->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_RADIO3 )->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_RADIO4 )->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_RADIO5 )->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_RADIO6 )->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_RADIO7 )->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_RADIO8 )->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			
			GetDlgItem(IDC_CHECK23)->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_CHECK24)->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_CHECK25)->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_CHECK26)->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_CHECK27)->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_CHECK28)->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_CHECK29)->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			GetDlgItem(IDC_CHECK40)->EnableWindow((uStyle&TVS_EDITLABELS)? TRUE:FALSE);
			}

		if(aIdList[i+2]==1)
			{
			m_cTreeList.SetExtendedStyle(aIdList[i+1]*iOn,aIdList[i+1]);
			}

		if(aIdList[i+1]==TVS_EX_BITCHECKBOX)
			{
			GetDlgItem(IDC_COMBO9)->EnableWindow(iOn);
			m_cTreeList.SetImageList((iOn && (uStyle&TVS_CHECKBOXES))? &m_cChecks:0,TVSIL_STATE);
			m_cTreeList.SetImageList((iOn                           )? &m_cChecks:0,TVSIL_CHECK);
			}
		
		if(aIdList[i+1]==TVS_CHECKBOXES)
			{
			uStyleEx  = m_cTreeList.GetExtendedStyle();
			uStyleEx &= TVS_EX_BITCHECKBOX;
			m_cTreeList.SetImageList((uStyleEx && (uStyle&TVS_CHECKBOXES))? &m_cChecks:0,TVSIL_STATE);
			}
		}
	
	iOn = (GetDlgItem(iID)->SendMessage(BM_GETCHECK)==BST_CHECKED)? 1:0;

	if(iID==IDC_CHECK36)
		{
		m_cTreeList.EnableWindow(!iOn);				
		}
			

	if(iID==IDC_CHECK37)
		{
		m_cTreeList.SetColumnMark(2,iOn);				
		}
			
	if(iID==IDC_CHECK44)
		{
		m_cTreeList.FixColumnSize(2,iOn,(iOn)? 0:TVCF_LASTSIZE);				
		}

}

void CTreeListDlg::OnCheck19()
{
	if(((CButton*)GetDlgItem(IDC_CHECK19))->GetCheck())
			m_uSelState |=  TVIS_BOLD;
	else	m_uSelState &= ~TVIS_BOLD;

	m_cTreeList.SetItemState(m_hSelect,m_iSelCol,m_uSelState,TVIS_BOLD);
}

void CTreeListDlg::OnCheck20()
{
	if(((CButton*)GetDlgItem(IDC_CHECK20))->GetCheck())
			m_uSelState |=  TVIS_UNTERLINE;
	else	m_uSelState &= ~TVIS_UNTERLINE;

	m_cTreeList.SetItemState(m_hSelect,m_iSelCol,m_uSelState,TVIS_UNTERLINE);
}

void CTreeListDlg::OnCheck21()
{
	if(((CButton*)GetDlgItem(IDC_CHECK21))->GetCheck())
			m_uSelState |=  TVIS_EXPANDED;
	else	m_uSelState &= ~TVIS_EXPANDED;

	m_cTreeList.SetItemState(m_hSelect,m_iSelCol,m_uSelState,TVIS_EXPANDED);
}

void CTreeListDlg::OnCheck30()
{
	if(((CButton*)GetDlgItem(IDC_CHECK30))->GetCheck())
			m_uSelState |=  TVIS_DISABLEBIT;
	else	m_uSelState &= ~TVIS_DISABLEBIT;
	
	m_cTreeList.DisableItemAutoEdit(m_hSelect,3,(m_uSelState&TVIS_DISABLEBIT)? 1:0);
	
	OnUpdateState();

}

//*****************************************************************************
//*
//*		OnEdit
//*
//*****************************************************************************
void CTreeListDlg::OnEdit() 
{

	if(!m_hSelect)return;

	m_cTreeList.EditLabel(m_hSelect,m_iSelCol,0);
	
}

//*****************************************************************************
//*
//*		OnCombo
//*
//*****************************************************************************
void CTreeListDlg::OnCombo() 
{
CComboBox	*pCombo;


	if(!m_hSelect)return;

	pCombo = m_cTreeList.EditLabelCb(m_hSelect,m_iSelCol,1);

	if(!pCombo)return;

	pCombo->AddString(_T("Hallo"));
	pCombo->AddString(_T("Wauuu.."));
	pCombo->AddString(_T("Yes"));
	pCombo->AddString(_T("End"));
	
		 
}


//*****************************************************************************
//*
//*		OnCbStateChanged
//*
//*****************************************************************************
//	The state of an check box was changed
void CTreeListDlg::OnCbStateChanged(NMHDR *pNmHdr, LRESULT *pResult)
{
NM_TREEVIEW  *pNmTreeView = (NM_TREEVIEW*)pNmHdr;
TCHAR		  cState[16];


									
	_itot(((pNmTreeView->itemNew.state>>12)&0x0F)|0x10,cState,2);

	cState[0]=' ';
	SetDlgItemText(IDC_EDIT3,cState);

}

//*****************************************************************************
//*
//*		OnTooltipNotify
//*
//*****************************************************************************
void CTreeListDlg::OnTooltipNotify(NMHDR *pNmHdr,LRESULT *pResult)
{
NM_TREEVIEW  *pNmTreeView = (NM_TREEVIEW*)pNmHdr;
static TCHAR  cText[256]  = _T("User definded\nTooltip\nMessage");


	pNmTreeView->itemNew.pszText	= cText;			// Is the text fo the tootip  (""=no Tooltip)
	
	pNmTreeView->ptDrag.x		   += 20;				// Move Tooltip to an other position
	pNmTreeView->ptDrag.y		   += 20;
	
	pNmTreeView->itemNew.mask	   |= TVIF_TOOLTIPTIME;	// Set a delay to show the tooltip	
	pNmTreeView->itemNew.lParam		= 1000;

	*pResult = 1;										// 0=Common-Tooltip  1=User-Tooltip

}			 

//*****************************************************************************
//*
//*		OnSelChanged
//*
//*****************************************************************************
void CTreeListDlg::OnSelChanged(NMHDR *pNmHdr,LRESULT *pResult)
{
NM_TREEVIEW *pNmTreeView = (NM_TREEVIEW*)pNmHdr;
TV_ITEM		 sItem;
TCHAR		 cUserData[256];
TCHAR		 cState[256]=_T("");	
TCHAR		 cText[256]=_T("");	
COLORREF	 uColor;	
LPVOID		 pData;
CString		 sCol;
int			 i;




	if(pNmTreeView->itemOld.hItem)						// Update User-Data
		{
		i=GetDlgItemText(IDC_EDIT4,cUserData,sizeof(cUserData))+1;
		if(i>USER_DATA_SIZE)i=USER_DATA_SIZE;
		cUserData[sizeof(cUserData)/sizeof(cUserData[0])-1]=0;
		pData = m_cTreeList.GetUserData(m_hSelect);
		if(pData)memcpy(pData,cUserData,i);	
		}


	if(!pNmTreeView->itemNew.hItem)
		{
		GetDlgItem(IDC_CHECK30)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK19)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK20)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK21)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO7 )->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO8 )->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4  )->EnableWindow(FALSE);

		m_hSelect	 = NULL;
		m_iSelCol	 = 0;
		m_uSelState	 = 0;
		m_uSelState	 = 0;
		cUserData[0] = 0;   
		cState 	 [0] = 0;   
		sCol		 = _T("");

		((CComboBox*)GetDlgItem(IDC_COMBO7))->SetCurSel(0);
		((CComboBox*)GetDlgItem(IDC_COMBO8))->SetCurSel(0);
		}
	else{
		m_hSelect	= pNmTreeView->itemNew.hItem;
		m_iSelCol	= pNmTreeView->itemNew.cChildren;
		m_uSelState	= pNmTreeView->itemNew.state;

		GetDlgItem(IDC_CHECK30)->EnableWindow(m_iSelCol==3 && m_bStateEnable);
		GetDlgItem(IDC_CHECK19)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK20)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK21)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO7 )->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO8 )->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT4  )->EnableWindow(TRUE);
		
		sCol.Format(_T("%i"),m_iSelCol);

		sItem.mask		 = TVIF_TEXT|TVIF_HANDLE|TVIF_SUBITEM|TVIF_STATE;
		sItem.stateMask	 = TVIS_STATEIMAGEMASK;
		sItem.pszText	 = cText;
		sItem.cchTextMax = sizeof(cText);
		sItem.hItem		 = m_hSelect;
		sItem.cChildren	 = m_iSelCol;
		
		m_cTreeList.GetItem(&sItem);


		uColor = m_cTreeList.GetItemBkColor(m_hSelect,m_iSelCol);

		for(i=ENTRIES(aColors)-1;i>0;i--)
			{
			if(uColor==aColors[i])break;
			}

		((CComboBox*)GetDlgItem(IDC_COMBO7))->SetCurSel(i);
			
		uColor = m_cTreeList.GetItemTextColor(m_hSelect,m_iSelCol);

		for(i=ENTRIES(aColors)-1;i>0;i--)
			{
			if(uColor==aColors[i])break;
			}

		((CComboBox*)GetDlgItem(IDC_COMBO8))->SetCurSel(i);
		
		
		memcpy(cUserData,m_cTreeList.GetUserData(m_hSelect),USER_DATA_SIZE);
		cUserData[sizeof(cUserData)-1]=0;

		_itot(((sItem.state>>12)&0x0F)|0x10,cState,2);
		cState[0]=' ';

		m_iCheckMode = (sItem.state>>13)&3;
		((CComboBox*)GetDlgItem(IDC_COMBO9))->SetCurSel(m_iCheckMode);
		}	


	((CButton*)GetDlgItem(IDC_CHECK19))->SetCheck((m_uSelState&TVIS_BOLD      )? 1:0);
	((CButton*)GetDlgItem(IDC_CHECK20))->SetCheck((m_uSelState&TVIS_UNTERLINE )? 1:0);
	((CButton*)GetDlgItem(IDC_CHECK21))->SetCheck((m_uSelState&TVIS_EXPANDED  )? 1:0);
	((CButton*)GetDlgItem(IDC_CHECK30))->SetCheck((m_uSelState&TVIS_DISABLEBIT)? 1:0);

	
	SetDlgItemText(IDC_EDIT1,sCol     );
	SetDlgItemText(IDC_EDIT2,cText    );
	SetDlgItemText(IDC_EDIT3,cState   );
	SetDlgItemText(IDC_EDIT4,cUserData);

	
	*pResult = 0;

}

//*****************************************************************************
//*
//*		OnItemExpanded
//*
//*****************************************************************************
void CTreeListDlg::OnItemExpanded(NMHDR *pNmHdr,LRESULT *pResult)
{
NM_TREEVIEW *pNmTreeView = (NM_TREEVIEW*)pNmHdr;



	*pResult = 0;

}

//*****************************************************************************
//*
//*		OnColumnClick
//*
//*****************************************************************************
void CTreeListDlg::OnColumnClick(NMHDR *pNmHdr,LRESULT *pResult)
{
NMHEADER *pNMHeader = (NMHEADER*)pNmHdr;
 



	*pResult = 0;

}


//*****************************************************************************
//*
//*		OnBeginLabelEdit
//*
//*****************************************************************************
void CTreeListDlg::OnBeginLabelEdit(NMHDR *pNmHdr,LRESULT *pResult)
{
NMTVDISPINFO *pItem = (NMTVDISPINFO*)pNmHdr;
 

	*pResult = 0;

}

//*****************************************************************************
//*
//*		OnEndLabelEdit
//*
//*****************************************************************************
void CTreeListDlg::OnEndLabelEdit(NMHDR *pNmHdr,LRESULT *pResult)
{
NMTVDISPINFO   *pItem = (NMTVDISPINFO*)pNmHdr;


	
	if(pItem->item.mask&TVIF_TEXT)
	if(pItem->item.pszText)
		{
		SetDlgItemText(IDC_EDIT2,pItem->item.pszText);
		}

	*pResult = 0;


}


//*****************************************************************************
//*
//*		OnReturn
//*
//*****************************************************************************
void CTreeListDlg::OnReturn(NMHDR *pNmHdr, LRESULT *pResult)
{

	if(m_iSelCol==3)								// Column 3 is for AutoEdit
		{
		*pResult = 0;
		return;
		}

	m_cTreeList.EditLabel(m_hSelect,m_iSelCol,1);

	*pResult = 0;

}

//*****************************************************************************
//*
//*		OnOK
//*
//*****************************************************************************
void CTreeListDlg::OnOK() 
{

	CDialog::OnOK();
}

//*****************************************************************************
//*
//*		OnCancel
//*
//*****************************************************************************
void CTreeListDlg::OnCancel() 
{

	CDialog::OnCancel();

}


//*****************************************************************************
//*
//*		OnChangeColor?
//*
//*****************************************************************************
void CTreeListDlg::OnChangeColor1(){m_cTreeList.SetColor(TVC_BK   ,aColors[((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel()]);}
void CTreeListDlg::OnChangeColor2(){m_cTreeList.SetColor(TVC_TEXT ,aColors[((CComboBox*)GetDlgItem(IDC_COMBO2))->GetCurSel()]);}
void CTreeListDlg::OnChangeColor3(){m_cTreeList.SetColor(TVC_ODD  ,aColors[((CComboBox*)GetDlgItem(IDC_COMBO3))->GetCurSel()]);}
void CTreeListDlg::OnChangeColor4(){m_cTreeList.SetColor(TVC_EVEN ,aColors[((CComboBox*)GetDlgItem(IDC_COMBO4))->GetCurSel()]);}
void CTreeListDlg::OnChangeColor5(){m_cTreeList.SetColor(TVC_FRAME,aColors[((CComboBox*)GetDlgItem(IDC_COMBO5))->GetCurSel()]);}
void CTreeListDlg::OnChangeColor6(){m_cTreeList.SetColor(TVC_BOXBG,aColors[((CComboBox*)GetDlgItem(IDC_COMBO6))->GetCurSel()]);}
void CTreeListDlg::OnChangeColor7(){m_cTreeList.SetItemBkColor  (m_hSelect,m_iSelCol,aColors[((CComboBox*)GetDlgItem(IDC_COMBO7))->GetCurSel()]);}
void CTreeListDlg::OnChangeColor8(){m_cTreeList.SetItemTextColor(m_hSelect,m_iSelCol,aColors[((CComboBox*)GetDlgItem(IDC_COMBO8))->GetCurSel()]);}

//*****************************************************************************
//*
//*		OnChangeCheck
//*
//*****************************************************************************
void CTreeListDlg::OnChangeCheck()
{
TCHAR		cState[16];
unsigned	uBits;

	
	
	UpdateData();
	
			m_cTreeList.SetItemState(m_hSelect,m_iSelCol,(m_iCheckMode*2)<<12,0x6000);
	uBits = m_cTreeList.GetItemState(m_hSelect,0xF000,m_iSelCol);


	_itot(((uBits>>12)&0x0F)|0x10,cState,2);

	cState[0]=' ';
	SetDlgItemText(IDC_EDIT3,cState);

	
}

//*****************************************************************************
//*
//*		OnUpdateState
//*
//*****************************************************************************
void CTreeListDlg::OnUpdateState()
{
TCHAR		cState[16];
unsigned	uBits;

	
	
	UpdateData();
	
	uBits = m_cTreeList.GetItemState(m_hSelect,0xF000,m_iSelCol);
	_itot(((uBits>>12)&0x0F)|0x10,cState,2);

	cState[0]=' ';
	SetDlgItemText(IDC_EDIT3,cState);

	
}

//*****************************************************************************
//*
//*		On???? for AutoEdit
//*
//*****************************************************************************
void CTreeListDlg::OnRadio1 (){OnUpdateAutoEdit();} 
void CTreeListDlg::OnRadio2 (){OnUpdateAutoEdit();}  
void CTreeListDlg::OnRadio3 (){OnUpdateAutoEdit();}  
void CTreeListDlg::OnRadio4 (){OnUpdateAutoEdit();}  
void CTreeListDlg::OnRadio5 (){OnUpdateAutoEdit();}  
void CTreeListDlg::OnRadio6	(){OnUpdateAutoEdit();}  
void CTreeListDlg::OnRadio7	(){OnUpdateAutoEdit();}  
void CTreeListDlg::OnRadio8	(){OnUpdateAutoEdit();}  
void CTreeListDlg::OnCheck23(){OnUpdateAutoEdit();}  
void CTreeListDlg::OnCheck24(){OnUpdateAutoEdit();}  
void CTreeListDlg::OnCheck25(){OnUpdateAutoEdit();}  
void CTreeListDlg::OnCheck26(){OnUpdateAutoEdit();}  
void CTreeListDlg::OnCheck27(){OnUpdateAutoEdit();}   
void CTreeListDlg::OnCheck28(){OnUpdateAutoEdit();}  
void CTreeListDlg::OnCheck29(){OnUpdateAutoEdit();}   
void CTreeListDlg::OnCheck40(){OnUpdateAutoEdit();}   


//*****************************************************************************
//*
//*		OnUpdateAutoEdit
//*
//*****************************************************************************
void CTreeListDlg::OnUpdateAutoEdit()
{
int				i,iMode;
static LPTSTR	pTextList[]={_T("ListVal1"),_T("ListVal2"),_T("ListVal3"),_T("ListVal4"),NULL};



	UpdateData();

					  iMode = 0;
	if(m_bNextLine	 )iMode|= TVAE_NEXTLINE;
	if(m_bDblClick   )iMode|= TVAE_DBLCLICK;
	if(m_bDropDown   )iMode|= TVAE_DROPDOWN;
	if(m_bFullWidth  )iMode|= TVAE_FULLWIDTH;
	if(m_bIconClick  )iMode|= TVAE_ICONCLICK;
	if(m_bOnlyReturn )iMode|= TVAE_ONLYRETURN;
	if(m_bStateEnable)iMode|= TVAE_STATEENABLE;

	if(m_bPtrList)
		{
		switch(m_iAutoEditMode)
			{
		case 0:	m_cTreeList.SetColumnAutoEdit(3,TVAE_NONE);						break;
		case 1:	m_cTreeList.SetColumnAutoEdit(3,TVAE_EDIT   |iMode);			break;
		case 2:	m_cTreeList.SetColumnAutoEdit(3,TVAE_COMBO  |iMode,pTextList);	break;
		case 3:	m_cTreeList.SetColumnAutoEdit(3,TVAE_CBLIST |iMode,pTextList);	break;
		case 4:	m_cTreeList.SetColumnAutoEdit(3,TVAE_STEP   |iMode,pTextList,2);break;
		case 5:	m_cTreeList.SetColumnAutoEdit(3,TVAE_STEPED |iMode,pTextList,2);break;
		case 6:	m_cTreeList.SetColumnAutoEdit(3,TVAE_CHECK  |iMode);			break;
		case 7:	m_cTreeList.SetColumnAutoEdit(3,TVAE_CHECKED|iMode);			break;
			}
		}
	else{
		switch(m_iAutoEditMode)
			{
		case 0:	m_cTreeList.SetColumnAutoEdit(3,TVAE_NONE);												break;
		case 1:	m_cTreeList.SetColumnAutoEdit(3,TVAE_EDIT   |iMode);									break;
		case 2:	m_cTreeList.SetColumnAutoEdit(3,TVAE_COMBO  |iMode,'|',_T("Text|Auto|Bike|Sun"));		break;
		case 3:	m_cTreeList.SetColumnAutoEdit(3,TVAE_CBLIST |iMode,'|',_T("Text|Auto|Bike|Sun"));		break;
		case 4:	m_cTreeList.SetColumnAutoEdit(3,TVAE_STEP   |iMode,'|',_T("Yes|No|NoneSense|Dummy"),2);	break;
		case 5:	m_cTreeList.SetColumnAutoEdit(3,TVAE_STEPED |iMode,'|',_T("Yes|No|NoneSense|Dummy"),2);	break;
		case 6:	m_cTreeList.SetColumnAutoEdit(3,TVAE_CHECK  |iMode);									break;
		case 7:	m_cTreeList.SetColumnAutoEdit(3,TVAE_CHECKED|iMode);									break;
			}
		}

	switch(m_iAutoEditMode)													
		{
	case 2:	m_cTreeList.SetColumnAutoIcon(3,10);	break;
	case 3:	m_cTreeList.SetColumnAutoIcon(3,10);	break;
	case 4:	m_cTreeList.SetColumnAutoIcon(3,15);	break;
	case 5:	m_cTreeList.SetColumnAutoIcon(3,15);	break;
		}

	if(m_iAutoEditMode!=0)
		{
		for(i=0;i<ENTRIES(aIdList);i+=3)
			{
			if(aIdList[i+1]!=TVS_EDITLABELS)continue;

			((CButton*)GetDlgItem(aIdList[i]))->SetCheck(1);
			OnCheck(aIdList[i]);
			break; 
			}
		}


	GetDlgItem(IDC_CHECK30)->EnableWindow(m_hSelect && m_iSelCol==3 && m_bStateEnable);

}


