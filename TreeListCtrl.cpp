//*****************************************************************************
//*
//*
//*		TreeListCtrl.cpp
//*
//*
//*****************************************************************************
//
//	(C) Copyright Anton Zechner 2007
//
//	This code creates a Tree-List-Control for MFC
//
#include	<Afx.h>
#include	<tchar.h>
#include	"TreeListCtrl.h"



IMPLEMENT_DYNAMIC(CTreeListCtrl, CWnd)



//*****************************************************************************
//*
//*		Create
//*
//*****************************************************************************
//	Creates a new Tree-List-Control
//	dwStyle		: Style of the Window
//					TVS_CHECKBOXES
//					TVS_DISABLEDRAGDROP
//					TVS_EDITLABELS
//					TVS_FULLROWSELECT
//					TVS_HASBUTTONS
//					TVS_HASLINES
//					TVS_INFOTIP
//					TVS_LINESATROOT
//					TVS_NONEVENHEIGHT
//					TVS_NOSCROLL
//					TVS_NOTOOLTIPS
//					TVS_RTLREADING
//					TVS_SHOWSELALWAYS
//					TVS_SINGLEEXPAND
//					TVS_TRACKSELECT
//	sRect		: Rectangle where the window should be shown
//	pParentWnd	: Pointer to parent window
//	nId			: Is the ID of the window
//	Returns TRUE if the window was created or FALSE if an error occurs
BOOL CTreeListCtrl::Create(DWORD dwStyle, const RECT &sRect, CWnd *pParentWnd, UINT nId) {

	TreeListRegister(AfxGetInstanceHandle());


	return CWnd::Create(_T("TreeList"), NULL, dwStyle, sRect, pParentWnd, nId);
}

//*****************************************************************************
//*
//*		Create
//*
//*****************************************************************************
//	Creates a new Tree-List-Control over a dialog item
//	dwExStyle	: Is the exdended style of the window (WS_EX_????)
//	dwStyle     : Style of the Window
//                	TVS_CHECKBOXES
//                	TVS_DISABLEDRAGDROP
//                	TVS_EDITLABELS
//                	TVS_FULLROWSELECT
//                	TVS_HASBUTTONS
//                	TVS_HASLINES
//                	TVS_INFOTIP
//                	TVS_LINESATROOT
//                	TVS_NONEVENHEIGHT
//                	TVS_NOSCROLL
//                	TVS_NOTOOLTIPS
//                	TVS_RTLREADING
//                	TVS_SHOWSELALWAYS
//                	TVS_SINGLEEXPAND
//                	TVS_TRACKSELECT
//	uItem       : Is the ID of the dialog item
//	pDlg		: Pointer to parent dialog
//	nId			: Is the ID of the window
//	Returns TRUE if the window was created or FALSE if an error occurs
BOOL CTreeListCtrl::Create(DWORD dwStyle, UINT uItem, CDialog *pDlg, UINT nId) {
	return CreateEx(0, dwStyle, uItem, pDlg, nId);
}

//*****************************************************************************
//*
//*		CreateEx
//*
//*****************************************************************************
//	Creates a new Tree-List-Control
//	dwExStyle	: Is the exdended style of the window (WS_EX_????)
//	dwStyle     : Style of the Window
//                	TVS_CHECKBOXES
//                	TVS_DISABLEDRAGDROP
//                	TVS_EDITLABELS
//                	TVS_FULLROWSELECT
//                	TVS_HASBUTTONS
//                	TVS_HASLINES
//                	TVS_INFOTIP
//                	TVS_LINESATROOT
//                	TVS_NONEVENHEIGHT
//                	TVS_NOSCROLL
//                	TVS_NOTOOLTIPS
//                	TVS_RTLREADING
//                	TVS_SHOWSELALWAYS
//                	TVS_SINGLEEXPAND
//                	TVS_TRACKSELECT
//	sRect		: Rectangle where the window should be shown
//	pParentWnd  : Pointer to parent window
//	nId         : Is the ID of the window
//	Returns TRUE if the window was created or FALSE if an error occurs
BOOL CTreeListCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT &sRect, CWnd *pParentWnd, UINT nId) {

	TreeListRegister(AfxGetInstanceHandle());

	return CWnd::CreateEx(dwExStyle, _T("TreeList"), NULL, dwStyle, sRect, pParentWnd, nId);
}


//*****************************************************************************
//*
//*		CreateEx
//*
//*****************************************************************************
//	Creates a new Tree-List-Control over a dialog item
//	dwExStyle	: Is the exdended style of the window (WS_EX_????)
//	dwStyle     : Style of the Window
//                	TVS_CHECKBOXES
//                	TVS_DISABLEDRAGDROP
//                	TVS_EDITLABELS
//                	TVS_FULLROWSELECT
//                	TVS_HASBUTTONS
//                	TVS_HASLINES
//                	TVS_INFOTIP
//                	TVS_LINESATROOT
//                	TVS_NONEVENHEIGHT
//                	TVS_NOSCROLL
//                	TVS_NOTOOLTIPS
//                	TVS_RTLREADING
//                	TVS_SHOWSELALWAYS
//                	TVS_SINGLEEXPAND
//                	TVS_TRACKSELECT
//	uItem       : Is the ID of the dialog item
//	pDlg		: Pointer to parent dialog
//	nId			: Is the ID of the window
//	Returns TRUE if the window was created or FALSE if an error occurs
BOOL CTreeListCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, UINT uItem, CDialog *pDlg, UINT nId) {
	CPoint	sPoint(0, 0);
	CRect	sRect;
	CWnd   *pWnd;


	pWnd = pDlg->GetDlgItem(uItem);
	ASSERT(pWnd != 0);


	pWnd->GetWindowRect(&sRect);
	pDlg->ClientToScreen(&sPoint);

	sRect.left	  -= sPoint.x;
	sRect.right   -= sPoint.x;
	sRect.top	  -= sPoint.y;
	sRect.bottom  -= sPoint.y;


	return CTreeListCtrl::CreateEx(dwExStyle, dwStyle | WS_CHILD | WS_VISIBLE, sRect, pDlg, nId);
}


//*****************************************************************************
//*
//*		InsertColumn
//*
//*****************************************************************************
//	Inserts a column in the header of the Tree-List-Control
//	nCol		: Position where the column should be inserted (use -1 for end)
//	pColumnText	: Text for the column
//	nFormat		: Ist the format for the text
//					TVCFMT_CENTER
//					TVCFMT_IMAGE
//					TVCFMT_RIGHT
//					TVCFMT_LEFT
//					TVCFMT_MARK
//	nWidth		: Is the width for the column in pixels.
//				  A negative value means is a autoexpanting column.
//				  The value of abs(nWidth) is the weight of the collumn.
//	nMin		: Ist the minimal size for the column.
//				  A negative value means abs(nMin)  the minimal size
//				  is only for dynamic size changing.
//				  Use 0x8000 for no minimal size
//	Returns the position of the column or -1 if an error occurs
int CTreeListCtrl::InsertColumn(int nCol, LPCTSTR pColumnText, int nFormat, int nWidth, int nMin) {
	TV_COLUMN	sItem;


	ASSERT(::IsWindow(m_hWnd));

	sItem.mask = 0;

	if(pColumnText) {
		sItem.mask		|=  TVCF_TEXT;
		sItem.pszText	 = (LPTSTR)pColumnText;
		sItem.cchTextMax =  256;
	}

	if(nFormat >= 0) {
		sItem.mask		|=  TVCF_FMT | TVCF_MARK;
		sItem.fmt		 =  nFormat;
	}

	if(nMin != 0x8000) {
		sItem.mask		|=  TVCF_MIN;
		sItem.iOrder	 =  nMin;
	}

	if(nWidth >= 0) {
		sItem.mask		|=  TVCF_WIDTH;
		sItem.cx		 =  nWidth;
	} else {
		sItem.mask		|=  TVCF_VWIDTH;
		sItem.cx		 = -nWidth;
	}



	return InsertColumn(nCol, &sItem);
}

//*****************************************************************************
//*
//*		SetItem
//*
//*****************************************************************************
//	Changes some properties of an item
//	hItem			: is the handle of the item
//	nCol			: is the column for the text (0=tree column)
//	nMask			: defies which propaties should be set (TVIF_????)
//	pText			: is the new text of the item (add TVIF_TEXT to nMask)
//	nImage			: is the new image for the item (add TVIF_IMAGE to nMask)
//	nSelectedImage	: is the new image for the item (add TVIF_SELECTEDIMAGE to nMask)
//	nState			: is the new state for the item (add TVIF_STATE to nMask)
//	nStateMask		: is a mask for the states
//	lParam			: is the new LPARAM parameter for the item (add TVIF_PARAM to nMask)
//	Returns TRUE if the text was changed or FALSE if an error occurs
BOOL CTreeListCtrl::SetItem(HTREEITEM hItem, int nCol, UINT nMask, LPCTSTR pText, int nImage, int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam) {
	TV_ITEM		sItem;


	ASSERT(::IsWindow(m_hWnd));

	sItem.mask				= nMask | TVIF_SUBITEM;
	sItem.hItem				= hItem;
	sItem.state				= nState;
	sItem.stateMask			= nStateMask;
	sItem.pszText			= (LPTSTR)pText;
	sItem.cchTextMax		= (pText) ? 256 : 0;
	sItem.iImage			= nImage;
	sItem.iSelectedImage	= nSelectedImage;
	sItem.cChildren			= nCol;
	sItem.lParam			= lParam;


	return SetItem(&sItem);
}



//*****************************************************************************
//*
//*		SetItemText
//*
//*****************************************************************************
//	Set the text of an item
//	hItem		: Is the handle of the item
//	pText		: Is the new text of the item
//	nCol		: Is the column for the text (0=tree column)
//	Returns TRUE if the text was changed or FALSE if an error occurs
BOOL CTreeListCtrl::SetItemText(HTREEITEM hItem, LPCTSTR pText, int nCol) {
	TV_ITEM		sItem;


	ASSERT(::IsWindow(m_hWnd));

	sItem.mask				= TVIF_SUBITEM | TVIF_TEXT;
	sItem.hItem				= hItem;
	sItem.stateMask			= 0;
	sItem.pszText			= (LPTSTR)pText;
	sItem.cchTextMax		= (pText) ? 256 : 0;
	sItem.cChildren			= nCol;


	return SetItem(&sItem);
}

//*****************************************************************************
//*
//*		ListDeleteItem
//*
//*****************************************************************************
//	Deletes an item in a Tree-List-Control which is used as List-Control
//	iRow	: Is the row of the item
//	Returns TRUE if the item was deleted or FALSE if an error occurs
BOOL CTreeListCtrl::ListDeleteItem(int iRow) {

	ASSERT(::IsWindow(m_hWnd));


	return DeleteItem(GetItemOfRow(iRow));
}


//*****************************************************************************
//*
//*		ListInsertItem
//*
//*****************************************************************************
//	Inserts an item in a Tree-List-Control which is used as List-Control
//	iRow	: Is the row of the item
//	pText	: Is the text for the item
//	nImage	: Is the number for the icon (use TV_NOIMAGE for no icon)
//	nState	: Is the state of the image
//				TVIS_BOLD		 	= text is bolded
//				TVIS_UNTERLINE	 	= text is underlined
//				TVIS_SELECTED		= sItem is selected
//				TVIS_OVERLAYMASK	= overlay bits for image
//				TVIS_STATEIMAGEMASK = image for state icons
//	iMask	: Is the mask of bits which are used in the nState parameter
//				TVIS_BOLD		 	= text is bolded
//				TVIS_UNTERLINE	 	= text is underlined
//				TVIS_SELECTED	 	= sItem is selected
//				TVIS_OVERLAYMASK	= overlay bits for image
//				TVIS_STATEIMAGEMASK = image for state icons
//	Returns the insert position of the item or -1 if an error occurs
int CTreeListCtrl::ListInsertItem(int iRow, LPCTSTR pText, int nImage, int nState, int iMask) {
	HTREEITEM		hItem;
	TVINSERTSTRUCT	sData;


	ASSERT(::IsWindow(m_hWnd));

	sData.item.mask	= 0;

	if(pText) {
		sData.item.mask		 |= TVIF_TEXT;
		sData.item.pszText	  = (LPTSTR)pText;
		sData.item.cchTextMax = 256;
	}

	if(nImage >= 0) {
		sData.item.mask		     |= (TVIF_SELECTEDIMAGE | TVIF_IMAGE) ;
		sData.item.iImage		  = nImage;
		sData.item.iSelectedImage = nImage;
	}

	if(nState >= 0) {
		sData.item.mask	    |= TVIF_STATE;
		sData.item.state	 = nState;
		sData.item.stateMask = iMask & (TVIS_BOLD | TVIS_UNDERLINE | TVIS_SELECTED | TVIS_OVERLAYMASK | TVIS_STATEIMAGEMASK);
	}


	hItem = GetItemOfRow(iRow);
	if(!hItem) {
		sData.hInsertAfter	= TVI_LAST;
		sData.hParent       = TVI_ROOT;
	} else {
		sData.hParent		= hItem;
		sData.hInsertAfter	= TVI_BEFORE;
	}

	hItem = InsertItem(&sData);


	return GetRowOfItem(hItem);
}

//*****************************************************************************
//*
//*		ListSetItem
//*
//*****************************************************************************
//	Changes an item in a Tree-List-Control which is used as List-Control
//	iRow	: Is the row of the item
//	nCol	: Is the column of the item
//	pText	: Is the text for the item
//	nImage	: Is the number for the icon (use TV_NOIMAGE for no icon)
//	nState	: Is the state of the image
//				TVIS_BOLD			= text is bolded
//				TVIS_UNTERLINE		= text is underlined
//				TVIS_SELECTED		= sItem is selected
//				TVIS_OVERLAYMASK	= overlay bits for image
//				TVIS_STATEIMAGEMASK = image for state icons	(only for column 0)
//	iMask	: Is the mask of bits which are used in the nState parameter
//				TVIS_BOLD			= text is bolded
//				TVIS_UNTERLINE		= text is underlined
//				TVIS_SELECTED		= sItem is selected
//				TVIS_OVERLAYMASK	= overlay bits for image
//				TVIS_STATEIMAGEMASK = image for state icons (only for column 0)
//	Returns TRUE if ok or FALSE if an error occurs
BOOL CTreeListCtrl::ListSetItem(int iRow, int nCol, LPCTSTR pText, int nImage, int nState, int iMask) {
	TV_ITEM		sData;


	ASSERT(::IsWindow(m_hWnd));

	sData.mask		= TVIF_HANDLE | TVIF_SUBITEM;
	sData.hItem		= GetItemOfRow(iRow);
	sData.cChildren	= nCol;

	if(!sData.hItem)
		return FALSE;

	if(pText) {
		sData.mask		 |= TVIF_TEXT;
		sData.pszText	  = (LPTSTR)pText;
		sData.cchTextMax  = 256;
	}

	if(nImage >= 0) {
		sData.mask		     |= TVIF_SELECTEDIMAGE | TVIF_IMAGE ;
		sData.iImage		  = nImage;
		sData.iSelectedImage  = nImage;
	}

	if(nState >= 0) {
		sData.mask	    |= TVIF_STATE;
		sData.state	     = nState;
		sData.stateMask  = iMask & (TVIS_BOLD | TVIS_UNDERLINE | TVIS_SELECTED);
	}



	return SetItem(&sData);
}


//*****************************************************************************
//*
//*		ListSetColor
//*
//*****************************************************************************
//	Changes the colors of an item in a Tree-List-Control which is used as List-Control
//	iRow		: Is the row of the item
//	nCol		: Is the column of the item
//	uBkColor	: Is the new background color (use TV_NOCOLOR for the default color)
//	uTextColor	: Is the new text       color (use TV_NOCOLOR for the default color)
//	Returns TRUE if ok or FALSE if an error occurs
BOOL CTreeListCtrl::ListSetColor(int iRow, int nCol, COLORREF uBkColor, COLORREF uTextColor) {
	HTREEITEM	hItem;



	ASSERT(::IsWindow(m_hWnd));


	hItem = GetItemOfRow(iRow);
	if(!hItem)
		return FALSE;


	SetItemBkColor(hItem, nCol, uBkColor);
	SetItemTextColor(hItem, nCol, uTextColor);


	return TRUE;
}

//*****************************************************************************
//*
//*		ListGetColor
//*
//*****************************************************************************
//	Gets the colors of an item in a Tree-List-Control which is used as List-Control
//	iRow		: Is the row of the item
//	nCol		: Is the column of the item
//	uBkColor	: Is the new background color (TV_NOCOLOR for the default color)
//	uTextColor	: Is the new background color (TV_NOCOLOR for the default color)
//	Returns TRUE if ok or FALSE if an error occurs
BOOL CTreeListCtrl::ListGetColor(int iRow, int nCol, COLORREF &uBkColor, COLORREF &uTextColor) {
	HTREEITEM	hItem;


	hItem = GetItemOfRow(iRow);
	if(!hItem) {
		uBkColor   = TV_NOCOLOR;
		uTextColor = TV_NOCOLOR;
		return FALSE;
	}


	uBkColor   = GetItemBkColor(hItem, nCol);
	uTextColor = GetItemTextColor(hItem, nCol);


	return TRUE;
}



//*****************************************************************************
//*
//*		GetItemState
//*
//*****************************************************************************
//	Gets the state of an Item
//	hItem		: Is the handle of the item
//	nStateMask	: Is the state mask of the requested states
//	nCol		: Is the column of the item
//	Returns the state bits of the item
UINT CTreeListCtrl::GetItemState(HTREEITEM hItem, UINT uMask, int nCol) {
	TV_ITEM		sItem;


	ASSERT(::IsWindow(m_hWnd));

	sItem.mask		 = TVIF_STATE | TVIF_HANDLE | TVIF_SUBITEM;
	sItem.stateMask	 = uMask;
	sItem.hItem		 = hItem;
	sItem.cChildren	 = nCol;

	if(!GetItem(&sItem))
		return 0;


	return sItem.state;
}


//*****************************************************************************
//*
//*		SetItemState
//*
//*****************************************************************************
//	Sets the state of an Item
//	hItem		: Is the handle of the item
//	nCol		: Is the column of the item
//	nState		: New state bits
//	nStateMask	: Mask of the bits which should be changed
//	Returns the state bits of the item
BOOL CTreeListCtrl::SetItemState(HTREEITEM hItem, int nCol, UINT nState, UINT nStateMask) {
	TV_ITEM		sItem;

	ASSERT(::IsWindow(m_hWnd));

	sItem.mask		 = TVIF_STATE | TVIF_HANDLE | TVIF_SUBITEM;
	sItem.hItem		 = hItem;
	sItem.cChildren	 = nCol;
	sItem.stateMask	 = nStateMask;
	sItem.state		 = nState;


	return SetItem(&sItem);
}

//*****************************************************************************
//*
//*		GetItemText
//*
//*****************************************************************************
//	Gets the text of an item
//	hItem		: Is the handle of the item
//	nCol		: Is the column of the item
//	Returns a pointer to the text or NULL if an error occurs
LPCTSTR CTreeListCtrl::GetItemText(HTREEITEM hItem, int nCol) {
	TV_ITEM		sItem;


	ASSERT(::IsWindow(m_hWnd));

	sItem.mask		 = TVIF_TEXT | TVIF_SUBITEM | TVIF_TEXTPTR;
	sItem.hItem		 = hItem;
	sItem.cChildren	 = nCol;

	if(!GetItem(&sItem))
		return 0;


	return sItem.pszText;
}

//*****************************************************************************
//*
//*		GetItemText
//*
//*****************************************************************************
//	Gets the text of an item and stores it in an buffer
//	hItem		: Is the handle of the item
//	pBuffer		: Is the text buffer where the text will be saved
//	iMax		: Is the size of the text buffer in chars
//	nCol		: Is the column of the item
//	Returns a pointer to the text or NULL if an error occurs
BOOL CTreeListCtrl::GetItemText(HTREEITEM hItem, LPTSTR pBuffer, int iMax, int nCol) {
	TV_ITEM		sItem;


	ASSERT(::IsWindow(m_hWnd));


	if(iMax <= 0)
		return FALSE;

	pBuffer[0]		 = 0;
	sItem.mask		 = TVIF_TEXT | TVIF_SUBITEM;
	sItem.hItem		 = hItem;
	sItem.pszText	 = pBuffer;
	sItem.cchTextMax = iMax;
	sItem.cChildren	 = nCol;


	return GetItem(&sItem);
}

//*****************************************************************************
//*
//*		GetItemImageEx
//*
//*****************************************************************************
//	Reads the image of an entry
//	hItem		: Is the handle of the item
//	nCol		: Is the column of the item
//	Returns the image number or -1 if an error occurs
int CTreeListCtrl::GetItemImageEx(HTREEITEM hItem, int nCol) {
	TVITEM	sItem;



	ASSERT(::IsWindow(m_hWnd));

	sItem.mask		= TVIF_IMAGE | TVIF_SUBITEM;
	sItem.hItem		= hItem;
	sItem.cChildren	= nCol;

	if(!GetItem(&sItem))
		return -1;


	return sItem.iImage;
}

//*****************************************************************************
//*
//*		GetItemImageEx
//*
//*****************************************************************************
//	Reads the image of an entry
//	hItem		: Is the handle of the item
//	nImage		: Here the image number will be stored
//	nCol		: Is the column of the item
//	Returns TRUE if the image number was detected or FALSE if an error occurs
BOOL CTreeListCtrl::GetItemImageEx(HTREEITEM hItem, int *pImage, int nCol) {
	TVITEM	sItem;



	ASSERT(::IsWindow(m_hWnd));

	sItem.mask		= TVIF_IMAGE | TVIF_SUBITEM;
	sItem.hItem		= hItem;
	sItem.cChildren	= nCol;

	if(!GetItem(&sItem))
		return FALSE;

	pImage[0]		= sItem.iImage;


	return TRUE;
}

//*****************************************************************************
//*
//*		SetItemImageEx
//*
//*****************************************************************************
//	Changes the image of an entry
//	hItem		: Is the handle of the item
//	nImage		: Is the new the image number
//	nCol		: Is the column of the item
//	Returns TRUE if the image number was detected or FALSE if an error occurs
BOOL CTreeListCtrl::SetItemImageEx(HTREEITEM hItem, int nImage, int nCol) {
	TVITEM	sItem;



	ASSERT(::IsWindow(m_hWnd));

	sItem.mask		= TVIF_IMAGE | TVIF_SUBITEM;
	sItem.hItem		= hItem;
	sItem.iImage	= nImage;
	sItem.cChildren	= nCol;




	return SetItem(&sItem);
}

//*****************************************************************************
//*
//*		ListGetItemText
//*
//*****************************************************************************
//	Gets the text of an item and stores it in an buffer
//	iRow		: Row index of the item whose text is to be retrieved.
//	pBuffer		: Is the text buffer where the text will be saved
//	iMax		: Is the size of the text buffer in chars
//	nCol		: Is the column of the item
//	Returns a pointer to the text or NULL if an error occurs
BOOL CTreeListCtrl::ListGetItemText(int iRow, LPTSTR pBuffer, int iMax, int nCol) {
	TV_ITEM		sItem;
	HTREEITEM	hItem;


	ASSERT(::IsWindow(m_hWnd));

	hItem = GetItemOfRow(iRow);

	if(!hItem || iMax <= 0)
		return FALSE;

	pBuffer[0]		 = 0;
	sItem.mask		 = TVIF_TEXT | TVIF_SUBITEM;
	sItem.hItem		 = hItem;
	sItem.pszText	 = pBuffer;
	sItem.cchTextMax = iMax;
	sItem.cChildren	 = nCol;


	return GetItem(&sItem);
}


//*****************************************************************************
//*
//*		FindItem
//*
//*****************************************************************************
//	Seaches for an Item in the control with several properties
//	hItem		: Is the item handle where the seach begins
//	iFlags		: This flag define the seach options
//					TVIF_CHILD	= begin at the first child of hItem to seach
//					TVIF_NEXT	= begin at the next item after hItem to seach
//					TVIF_PARAM	= compare the the lParam  entry at the seach
//					TVIF_TEXT	= compare the the pText   entry at the seach
//					TVIF_STATE	= compare the the uState  entry at the seach
//					TVIF_CASE	= don't differ between lower and upper case
//	nCol		: Selects the column for the text comparison
//	pText		: Is the text option for the seach
//	lParam		: Is the param option for the seach
//	uState		: Are the state bits for the seach
//	uStateMask	: Only bits which are set in this mask will be comared
//	Retuns the handle of the item which was found, or NULL if no item was found
HTREEITEM CTreeListCtrl::FindItem(HTREEITEM hItem, int iFlags, int nCol, LPCTSTR pText, LPARAM lParam, UINT uState, UINT uStateMask) {
	TV_FIND		sFind;


	sFind.uFlags		= iFlags;
	sFind.uColumn		= nCol;
	sFind.pText			= pText;
	sFind.lParam		= lParam;
	sFind.uState		= uState;
	sFind.uStateMask	= uStateMask;


	return FindItem(hItem, &sFind);
}


//*****************************************************************************
//*
//*		InsertItem
//*
//*****************************************************************************
//	Call this function to insert a new item in a tree list control.
//	nMask			: Integer specifying which attributes to set. See theTVITEM structure in the Platform SDK.
//	pText			: Address of a string containing the item’s text.
//	nImage			: Index of the item’s image in the tree view control’s image list.
//	nSelImage		: Index of the item’s selected image in the tree view control’s image list.
//	nState			: Specifies values for the item’s states. SeeTree View Control Item States in the Platform SDK for a list of appropriate states.
//	nStateMask		: Specifies which states are to be set. See theTVITEM structure in the Platform SDK.
//	lParam			: A 32-bit application-specific value associated with the item.
//	hParent			: Handle of the inserted item’s parent.
//	hInsertAfter	: Handle of the item after which the new item is to be inserted.
//	Returns the handle of the new item if successful, otherwise NULL.
HTREEITEM CTreeListCtrl::InsertItem(UINT nMask, LPCTSTR pText, int nImage, int nSelImage, UINT nState, UINT nStateMask, LPARAM lParam, HTREEITEM hParent, HTREEITEM hInsertAfter) {
	TVINSERTSTRUCT	sInsert;


	ASSERT(::IsWindow(m_hWnd));

	sInsert.hParent				= hParent;
	sInsert.hInsertAfter		= hInsertAfter;
	sInsert.item.mask			= nMask;
	sInsert.item.pszText		= (LPTSTR)pText;
	sInsert.item.iImage			= nImage;
	sInsert.item.iSelectedImage = nSelImage;
	sInsert.item.state			= nState;
	sInsert.item.stateMask		= nStateMask;
	sInsert.item.lParam			= lParam;


	return (HTREEITEM)::SendMessage(m_hWnd, TVM_INSERTITEM, 0, (LPARAM)&sInsert);
}

//*****************************************************************************
//*
//*		InsertItem
//*
//*****************************************************************************
//	Call this function to insert a new item in a tree list control, with a sort fonction.
//	nMask			: Integer specifying which attributes to set. See theTVITEM structure in the Platform SDK.
//	pText			: Address of a string containing the item’s text.
//	nImage			: Index of the item’s image in the tree view control’s image list.
//	nSelImage		: Index of the item’s selected image in the tree view control’s image list.
//	nState			: Specifies values for the item’s states. SeeTree View Control Item States in the Platform SDK for a list of appropriate states.
//	nStateMask		: Specifies which states are to be set. See theTVITEM structure in the Platform SDK.
//	lParam			: A 32-bit application-specific value associated with the item.
//	pCmpProc		: Is the sort function which is used to find the insert position
//	hParent			: Handle of the inserted item’s parent.
//	Returns the handle of the new item if successful, otherwise NULL.
HTREEITEM CTreeListCtrl::InsertItem(UINT nMask, LPCTSTR pText, int nImage, int nSelImage, UINT nState, UINT nStateMask, LPARAM lParam, PFNTVSORTEX pCmpProc, HTREEITEM hParent) {
	TVINSERTSTRUCT	sInsert;


	ASSERT(::IsWindow(m_hWnd));

	sInsert.hParent				= hParent;
	sInsert.hInsertAfter		= TVI_SORTEX;
	sInsert.item.hItem			= (HTREEITEM)pCmpProc;
	sInsert.item.pszText		= (LPTSTR)pText;
	sInsert.item.mask			= nMask;
	sInsert.item.iImage			= nImage;
	sInsert.item.iSelectedImage = nSelImage;
	sInsert.item.state			= nState;
	sInsert.item.stateMask		= nStateMask;
	sInsert.item.lParam			= lParam;


	return (HTREEITEM)::SendMessage(m_hWnd, TVM_INSERTITEM, 0, (LPARAM)&sInsert);
}

//*****************************************************************************
//*
//*		SetColumnText
//*
//*****************************************************************************
//	Sets the text of an item in the column header
//	nCol	: is the number of the column
//	pText	: is the new text
//	Retuns TRUE if succesfull
BOOL CTreeListCtrl::SetColumnText(int nCol, LPCTSTR pText) {
	TV_COLUMN	sData;


	sData.pszText		= (LPTSTR)pText;
	sData.cchTextMax	= (int)_tcslen(pText);
	sData.mask			= TVCF_TEXT;


	return	SetColumn(nCol, &sData);
}

//*****************************************************************************
//*
//*		SetColumnImage
//*
//*****************************************************************************
//	Sets the text of an item in the column header
//	nCol	: is the number of the column
//	iImage	: is the new image number
//	Retuns TRUE if succesfull
BOOL CTreeListCtrl::SetColumnImage(int nCol, int iImage) {
	TV_COLUMN	sData;


	sData.iImage		= iImage;
	sData.mask			= TVCF_IMAGE;


	return	SetColumn(nCol, &sData);
}

//*****************************************************************************
//*
//*		SetColumnMark
//*
//*****************************************************************************
//	Sets the mark state of a column. A marked column will be drawn darker.
//	nCol	: is the number of the column
//	bOn		: is the mark state
//	Returns TRUE if succesfull
BOOL CTreeListCtrl::SetColumnMark(int nCol, BOOL bOn) {
	TV_COLUMN	sData;


	sData.fmt	= (bOn) ? TVCFMT_MARK : 0;
	sData.mask	= TVCF_MARK;


	return	SetColumn(nCol, &sData);
}

//*****************************************************************************
//*
//*		FixColumnSize
//*
//*****************************************************************************
//	Fixes the size of a a column. The size of a fixed column can't be changed.
//	nCol	: is the number of the column
//	bOn		: is the fixed state
//	iWidth	: is the new width for the column (-1 means don't change width)
//			  TVCF_LASTSIZE restore precedent size
//	Returns TRUE if succesfull
BOOL CTreeListCtrl::FixColumnSize(int nCol, BOOL bOn, int iWidth) {
	LV_COLUMN	sData;


	sData.fmt	= (bOn) ? TVCFMT_FIXED : 0;
	sData.mask	= TVCF_FIXED;

	if(iWidth >= 0) {									// set also the column width
		sData.mask |= TVCF_WIDTH;
		sData.cx    = iWidth;
	}


	return	SetColumn(nCol, &sData);
}

//*****************************************************************************
//*
//*		CreateDragImage
//*
//*****************************************************************************
CImageList *CTreeListCtrl::CreateDragImage(HTREEITEM hItem, int nCol) {
	CImageList *pImageList;
	HIMAGELIST	hImageList;


	ASSERT(::IsWindow(m_hWnd));

	hImageList = TreeList_CreateDragImageEx(m_hWnd, hItem, nCol);
	if(!hImageList) {
		return NULL;
	}

	pImageList = new CImageList;
	VERIFY(pImageList->Attach(hImageList));

	return pImageList;
}


