//*****************************************************************************
//*
//*		
//*		TreeListCtrl.h
//*
//*
//*****************************************************************************
#ifndef 	__TREELISTCTRL_H__
#define 	__TREELISTCTRL_H__

#if _MSC_VER > 1000
#pragma once
#endif

#include	<AfxCmn.h>
#include	"TreeListWnd.h"

class CHeaderCtrl;
class CDialog;

#define 	ID_TREELISTCTRL_DEF		0x9719


//*****************************************************************************
//*
//*		CTreeListCtrl
//*
//*****************************************************************************
class CTreeListCtrl : public CTreeCtrl
{
		
	DECLARE_DYNAMIC(CTreeListCtrl)

public:
	CTreeListCtrl(){};

	BOOL		 Create					(                DWORD dwStyle,const RECT &sRect,CWnd *pParentWnd,UINT nId=ID_TREELISTCTRL_DEF);
	BOOL		 CreateEx				(DWORD dwExStyle,DWORD dwStyle,const RECT &sRect,CWnd *pParentWnd,UINT nId=ID_TREELISTCTRL_DEF);
	BOOL		 Create  				(                DWORD dwStyle,UINT uItem,CDialog *pDlg,UINT nId=ID_TREELISTCTRL_DEF);
	BOOL		 CreateEx				(DWORD dwExStyle,DWORD dwStyle,UINT uItem,CDialog *pDlg,UINT nId=ID_TREELISTCTRL_DEF);
	INT  		 InsertColumn  		 	(int nCol, LPCTSTR pColumnText, int nFormat=TVCFMT_LEFT,int nWidth=-1,int nMin=0x8000);
	INT  		 InsertColumn  		 	(int nCol, const TV_COLUMN* pColumn );
	BOOL		 SetColumn     		 	(int nCol, const TV_COLUMN* pColumn );
	BOOL		 GetColumn     		 	(int nCol, TV_COLUMN* pColumn ) const;
	INT			 GetColumnWidth		 	(int nCol) const;
	BOOL		 SetColumnWidth		 	(int nCol, int iWidth);
	BOOL		 SetColumnImage			(int nCol, int iImage);
	BOOL		 SetColumnText		 	(int nCol, LPCTSTR pText);
	BOOL 		 SetColumnMark	 		(int nCol, BOOL bOn=TRUE);
	BOOL		 FixColumnSize			(int nCol, BOOL bOn=TRUE,int iWidth=-1);
	BOOL 		 DeleteColumn		 	(int nCol);
	INT 		 GetColumnCount			() const;
	CEdit       *GetEditControl			() const;
	CHeaderCtrl *GetHeaderCtrl		 	() const;
	CComboBox   *GetComboControl		() const;
	VOID		 GetEditControl			(HWND &hWnd) const;
	VOID		 GetHeaderCtrl		 	(HWND &hWnd) const;
	VOID		 GetComboControl		(HWND &hWnd) const;
	CEdit		*EditLabel			 	(HTREEITEM hItem,int nCol=0,int iFull=0            ,int iSel=0);
	CComboBox	*EditLabelCb		 	(HTREEITEM hItem,int nCol=0,int iFull=0,int iList=0,int iSel=0);
	CImageList  *CreateDragImage	 	(HTREEITEM hItem,int nCol=0); 	
	CImageList  *SetImageList			(CImageList *pImageList,int nImageListType);
	HIMAGELIST	 SetImageList			(HIMAGELIST  hImageList,int nImageListType);
	DWORD		 GetStyle			 	() const;
	DWORD		 SetStyle			 	(DWORD dwStyle);
	DWORD		 SetStyle			 	(DWORD dwStyle,DWORD dwMask);
	DWORD		 GetExtendedStyle	 	() const;
	DWORD		 SetExtendedStyle	 	(DWORD dwStyle);
	DWORD		 SetExtendedStyle	 	(DWORD dwStyle,DWORD dwMask);
	COLORREF	 GetColor			 	(int iIndex) const;
	COLORREF	 SetColor			 	(int iIndex ,COLORREF uColor);
	COLORREF	 GetItemBkColor		 	(HTREEITEM hItem,int nCol=0) const;
	COLORREF	 SetItemBkColor		 	(HTREEITEM hItem,int nCol,COLORREF uColor);
	COLORREF	 GetItemTextColor	 	(HTREEITEM hItem,int nCol=0) const;
	COLORREF	 SetItemTextColor	 	(HTREEITEM hItem,int nCol,COLORREF uColor);
	BOOL		 ExpandAll			 	(HTREEITEM hItem,int iCode=0);
	BOOL		 CollapseAll		 	(HTREEITEM hItem,int iCode=0);
	INT 		 IsItemVisible			(HTREEITEM hItem,int nCol=-1);
	BOOL		 EnsureVisible		 	(HTREEITEM hItem,int nCol);
	BOOL 		 DeleteChildItems	 	(HTREEITEM hItem);
	BOOL		 EnsureVisible		 	(HTREEITEM hItem);
	BOOL		 SelectDropTarget	 	(HTREEITEM hItem,int nCol=0);
	BOOL		 SelectItem			 	(HTREEITEM hItem,int nCol=0);
	BOOL		 StartEdit				(HTREEITEM hItem,int nCol=0);
	BOOL		 SelectChilds		 	(HTREEITEM hItem=TVI_ROOT,int iMode=TVIS_WITHCHILDS);
	BOOL		 GetItemRect		 	(HTREEITEM hItem,int nCol,RECT *pRect,int iCode);
	BOOL		 GetItemRect		 	(HTREEITEM hItem,		  RECT *pRect,int iCode);
	BOOL		 GetItemText		 	(HTREEITEM hItem,LPTSTR pBuffer,int iMax,int nCol=0);
	LPCTSTR		 GetItemText		 	(HTREEITEM hItem,                        int nCol=0);
	BOOL		 SetItemText		 	(HTREEITEM hItem,LPCTSTR pText          ,int nCol=0);
	INT 		 GetItemImageEx		 	(HTREEITEM hItem                        ,int nCol=0);
	BOOL		 GetItemImageEx	     	(HTREEITEM hItem,int *pImage            ,int nCol=0);
	BOOL		 SetItemImageEx		 	(HTREEITEM hItem,int  nImage            ,int nCol=0);
	UINT 		 GetItemState        	(HTREEITEM hItem,UINT nStateMask        ,int nCol=0);
	BOOL		 SetItemState        	(HTREEITEM hItem,         UINT nState,UINT nStateMask);
	BOOL		 SetItemState        	(HTREEITEM hItem,int nCol,UINT nState,UINT nStateMask);
	BOOL		 SetItem			 	(HTREEITEM hItem,int nCol,UINT nMask, LPCTSTR pText,int nImage,int nSelectedImage,UINT nState,UINT nStateMask, LPARAM lParam=0);
	BOOL		 SetItem			 	(TVITEM   *pItem);
	BOOL		 SortChildrenEX		 	(LPTVSORTEX pSort,BOOL bRecusive=FALSE);
	BOOL		 SortChildrenCB		 	(LPTVSORTCB pSort,BOOL bRecusive=FALSE);
	BOOL		 SortChildren		 	(HTREEITEM hItem ,BOOL bRecusive=FALSE);
	BOOL		 SetColumnOrderArray	(int iCount,const int *pArray);
	BOOL		 GetColumnOrderArray	(int iCount,int       *pArray);
	BOOL		 SetItemCheckBox		(HTREEITEM hItem,int iState,int nCol=0,UINT uMask=0x0F);
	INT			 GetItemCheckBox		(HTREEITEM hItem		   ,int nCol=0,UINT uMask=0x0F);
	BOOL		 DisableItemAutoEdit	(HTREEITEM hItem,int nCol,BOOL bDisable =TRUE);
	BOOL		 SetFocusItem			(HTREEITEM hItem,int nCol=-1);
	LPVOID		 GetUserData		 	(HTREEITEM hItem) const;
	INT			 SetUserDataSize     	(int iSize);
	INT			 GetUserDataSize	 	() const;
	HTREEITEM	 GetFirstItem			();
	HTREEITEM	 GetFocusItem		 	();
	HTREEITEM	 GetFirstSelected	 	();
	HTREEITEM	 GetLastChild   	 	(HTREEITEM hItem);
	HTREEITEM	 GetNextItem			(HTREEITEM hItem,UINT nCode=TVGN_NEXT);
	HTREEITEM	 GetNextSelected	 	(HTREEITEM hItem);
	HTREEITEM	 GetNextSelectedChild	(HTREEITEM hItem);
	HTREEITEM	 FindItem				(HTREEITEM hItem,TVFIND *pFind);
	HTREEITEM	 FindItem				(HTREEITEM hItem,int     iFlags,int nCol,LPCTSTR pText,LPARAM lParam=0,UINT uState=0,UINT uStateMask=0);
	HTREEITEM	 FindItem				(HTREEITEM hItem,LPCTSTR pText ,int nCol=0,int iCase=0);
	HTREEITEM	 FindItem				(HTREEITEM hItem,LPARAM  lParam);
	HTREEITEM	 InsertItem				(UINT nMask, LPCTSTR pText,int nImage,int nSelImage,UINT nState,UINT nStateMask,LPARAM lParam,HTREEITEM   hParent=TVI_ROOT,HTREEITEM hInsertAfter=TVI_LAST);
	HTREEITEM	 InsertItem				(UINT nMask, LPCTSTR pText,int nImage,int nSelImage,UINT nState,UINT nStateMask,LPARAM lParam,PFNTVSORTEX pCmpProc        ,HTREEITEM hParent     =TVI_ROOT);
	HTREEITEM	 InsertItem				(            LPCTSTR pText,int nImage,int nSelImg,                                            HTREEITEM   hParent=TVI_ROOT,HTREEITEM hInsertAfter=TVI_LAST);
	HTREEITEM	 InsertItem				(            LPCTSTR pText,int nImage,int nSelImg,                                            HTREEITEM   hParent         ,HTREEITEM hInsertAfter         ,LPARAM lParam  );
	HTREEITEM	 InsertItem				(            LPCTSTR pText,int nImage,int nSelImg,                                            PFNTVSORTEX pCmpProc        ,HTREEITEM hParent     =TVI_ROOT,LPARAM lParam=0);
	HTREEITEM	 InsertItem				(            LPCTSTR pText,int nImage,                                                        HTREEITEM   hParent=TVI_ROOT,HTREEITEM hInsertAfter=TVI_LAST);
	HTREEITEM	 InsertItem				(            LPCTSTR pText,int nImage,                                                        HTREEITEM   hParent         ,HTREEITEM hInsertAfter         ,LPARAM lParam  );
	HTREEITEM	 InsertItem				(            LPCTSTR pText,int nImage,                                                        PFNTVSORTEX pCmpProc        ,HTREEITEM hParent     =TVI_ROOT,LPARAM lParam=0);
	HTREEITEM	 InsertItem				(            LPCTSTR pText,                                                                   HTREEITEM   hParent=TVI_ROOT,HTREEITEM hInsertAfter=TVI_LAST);
	HTREEITEM	 InsertItem				(            LPCTSTR pText,                                                                   HTREEITEM   hParent         ,HTREEITEM hInsertAfter         ,LPARAM lParam  );
	HTREEITEM	 InsertItem				(            LPCTSTR pText,                                                                   PFNTVSORTEX pCmpProc        ,HTREEITEM hParent     =TVI_ROOT,LPARAM lParam=0);
	HTREEITEM	 InsertItem				(LPTVINSERTSTRUCT    pInsert);
	HTREEITEM	 EnumItems   	 		(HTREEITEM hLast=TVI_ROOT);
	INT			 GetOption				(int iOption);
	INT			 SetOption				(int iOption,int  iValue);
	INT			 SetColumnAutoEdit		(int nCol,int iMode=TVAE_EDIT);
	INT			 SetColumnAutoEdit		(int nCol,int iMode,            LPTSTR  *pList,int iMax=0);
	INT			 SetColumnAutoEdit		(int nCol,int iMode,            LPCTSTR *pList,int iMax=0);
	INT			 SetColumnAutoEdit		(int nCol,int iMode,            LPCTSTR  pText,int iMax=0);
	INT			 SetColumnAutoEdit		(int nCol,int iMode,TCHAR cChar,LPCTSTR  pText,int iMax=0);
	INT			 SetColumnAutoIcon		(int nCol,int iIcon);
	INT 		 GetFocusColumn		 	(); 
	INT 		 GetSelectionColumn	 	(); 
	INT 		 GetDropHilightColumn	();

	// ListCtrl Functions

	INT			 GetCountPerPage	 	() const;
	INT			 GetRowCount		 	() const;
	INT			 GetRowOfItem		 	(HTREEITEM hItem) const;
	HTREEITEM	 GetItemOfRow		 	(int iRow) const;
	CEdit		*ListEditLabel		 	(int iRow,int nCol=0,int iFull=0            ,int iSel=0);
	CComboBox	*ListEditLabelCb	 	(int iRow,int nCol=0,int iFull=0,int iList=0,int iSel=0);
	CImageList  *ListCreateDragImage 	(int iRow,int nCol=0); 	
	BOOL		 ListDeleteItem		 	(int iRow);
	INT 		 ListInsertItem		 	(int iRow,		   LPCTSTR pText,int nImage=-1,int nState=-1,int iMask=TVIS_BOLD|TVIS_UNDERLINE|TVIS_SELECTED|TVIS_OVERLAYMASK|TVIS_STATEIMAGEMASK);	
	BOOL		 ListSetItem		 	(int iRow,		   LPCTSTR pText,int nImage=-1,int nState=-1,int iMask=TVIS_BOLD|TVIS_UNDERLINE|TVIS_SELECTED|TVIS_OVERLAYMASK|TVIS_STATEIMAGEMASK);	
	BOOL		 ListSetItem		 	(int iRow,int iCol,LPCTSTR pText,int nImage=-1,int nState=-1,int iMask=TVIS_BOLD|TVIS_UNDERLINE|TVIS_SELECTED|TVIS_OVERLAYMASK|TVIS_STATEIMAGEMASK);	
	BOOL		 ListSetColor		 	(int iRow,int iCol,COLORREF  uBkColor=TV_NOCOLOR,COLORREF  uTextColor=TV_NOCOLOR); 
	BOOL		 ListGetColor		 	(int iRow,int iCol,COLORREF &uBkColor           ,COLORREF &uTextColor);
	LRESULT		 ListGetItemData		(int iRow);		
	LPCTSTR		 ListGetItemText	 	(int iRow,                         int nCol=0);
	BOOL		 ListGetItemText        (int iRow,LPTSTR  pBuffer,int iMax,int nCol=0);
	BOOL		 ListSetItemText	 	(int iRow,LPCTSTR pText           ,int nCol=0);
	UINT 		 ListGetItemState    	(int iRow,UINT nStateMask         ,int nCol=0);
	BOOL		 ListSetItemState    	(int iRow,         UINT nState ,UINT nStateMask);
	BOOL		 ListSetItemState    	(int iRow,int nCol,UINT nState ,UINT nStateMask);
	INT			 ListGetItemCheckBox	(int iRow		    ,int nCol=0,UINT uMask=0x0F);
	BOOL		 ListSetItemCheckBox	(int iRow,int iState,int nCol=0,UINT uMask=0x0F);
	BOOL		 ListSelectItem		 	(int iRow,int nCol= 0);
	BOOL		 ListSetFocusItem		(int iRow,int nCol=-1);
	BOOL		 ListEnsureVisible	 	(int iRow,int nCol   );
	INT			 ListEnsureVisible	 	(int iRow);
	INT 		 ListGetItemImageEx	 	(int iRow             ,int nCol=0);
	BOOL		 ListGetItemImageEx	 	(int iRow,int *pImage ,int nCol=0);
	BOOL		 ListSetItemImageEx	 	(int iRow,int  nImage ,int nCol=0);
	INT			 ListGetItemImage    	(int iRow,int &nImage,int &nSelectedImage);
	BOOL		 ListSetItemImage    	(int iRow,int  nImage,int  nSelectedImage);
	LPVOID		 ListGetUserData	 	(int iRow) const;
	INT			 ListGetNextSelected 	(int iRow);
	COLORREF	 ListGetItemBkColor	 	(int iRow,int nCol=0) const;
	COLORREF	 ListSetItemBkColor		(int iRow,int nCol,COLORREF uColor);
	COLORREF	 ListGetItemTextColor	(int iRow,int nCol=0) const;
	COLORREF	 ListSetItemTextColor	(int iRow,int nCol,COLORREF uColor);
	BOOL		 ListSelectDropTarget	(int iRow,int nCol=0);
	BOOL		 ListGetItemRect		(int iRow,int nCol,RECT *pRect,int iCode);
	BOOL		 ListGetItemRect		(int iRow,		   RECT *pRect,int iCode);
	BOOL		 ListSetTopIndex        (int iRow);
	INT			 ListGetFirstSelected 	();
	INT			 ListGetFocusItem	 	();
	INT			 ListGetTopIndex	 	();
	
	
	
};


//*****************************************************************************
//*
//*		Inline Funktions
//*
//*****************************************************************************
#define 	TLC_SORT_PARAMS1	HTREEITEM   P,HTREEITEM A,LPARAM L	
#define 	TLC_SORT_PARAMS2	PFNTVSORTEX O,HTREEITEM P,LPARAM L	

inline	LPVOID		 CTreeListCtrl::GetUserData(HTREEITEM hItem) const							{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetUserData(m_hWnd,hItem);}
inline	INT			 CTreeListCtrl::GetUserDataSize() const										{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetUserDataSize(m_hWnd);}
inline	INT			 CTreeListCtrl::SetUserDataSize(int iSize)									{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetUserDataSize(m_hWnd,iSize);}
inline	BOOL		 CTreeListCtrl::GetColumn   (int nCol,       TV_COLUMN *pColumn) const		{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetColumn(m_hWnd,nCol,pColumn);}
inline	BOOL		 CTreeListCtrl::SetColumn   (int nCol, const TV_COLUMN *pColumn)			{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetColumn(m_hWnd,nCol,pColumn);}
inline	INT 		 CTreeListCtrl::InsertColumn(int nCol, const TV_COLUMN *pColumn)			{ ASSERT(::IsWindow(m_hWnd)); return TreeList_InsertColumn(m_hWnd,nCol,pColumn); }
inline	BOOL		 CTreeListCtrl::DeleteColumn(int nCol)										{ ASSERT(::IsWindow(m_hWnd)); return TreeList_DeleteColumn(m_hWnd,nCol); }
inline	INT 		 CTreeListCtrl::GetColumnCount() const										{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetColumnCount(m_hWnd); }
inline	BOOL		 CTreeListCtrl::SortChildren  (HTREEITEM  hItem,BOOL bRecusive)				{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SortChildren  (m_hWnd,hItem,bRecusive); }
inline	BOOL		 CTreeListCtrl::SortChildrenCB(LPTVSORTCB pSort,BOOL bRecusive)				{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SortChildrenCB(m_hWnd,pSort,bRecusive); }
inline	BOOL		 CTreeListCtrl::SortChildrenEX(LPTVSORTEX pSort,BOOL bRecusive)				{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SortChildrenEX(m_hWnd,pSort,bRecusive); }
inline	INT			 CTreeListCtrl::GetColumnWidth(int nCol) const								{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetColumnWidth(m_hWnd,nCol); }
inline	BOOL		 CTreeListCtrl::SetColumnWidth(int nCol, int iWidth)						{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetColumnWidth(m_hWnd,nCol,iWidth); }
inline	BOOL		 CTreeListCtrl::SetColumnOrderArray	(int iCount,const int *pArray)			{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetColumnOrderArray(m_hWnd,iCount,pArray);}
inline	BOOL		 CTreeListCtrl::GetColumnOrderArray	(int iCount,int       *pArray)			{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetColumnOrderArray(m_hWnd,iCount,pArray);} 
inline	HTREEITEM	 CTreeListCtrl::FindItem(HTREEITEM hItem,TVFIND *pFind)						{ ASSERT(::IsWindow(m_hWnd)); return TreeList_FindItem(m_hWnd,hItem,pFind); }
inline	HTREEITEM	 CTreeListCtrl::GetItemOfRow(int iRow) const								{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetItemOfRow(m_hWnd,iRow); }
inline	INT			 CTreeListCtrl::GetRowOfItem(HTREEITEM hItem) const							{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetRowOfItem(m_hWnd,hItem); }
inline	INT			 CTreeListCtrl::GetRowCount () const										{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetRowCount (m_hWnd); }
inline	INT			 CTreeListCtrl::GetCountPerPage() const										{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetCountPerPage(m_hWnd); }
inline	DWORD		 CTreeListCtrl::GetStyle() const											{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetStyle(m_hWnd); }
inline	DWORD		 CTreeListCtrl::SetStyle(DWORD dwStyle)										{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetStyle(m_hWnd,dwStyle); }
inline	DWORD		 CTreeListCtrl::SetStyle(DWORD dwStyle,DWORD dwMask)						{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetStyleEx(m_hWnd,dwStyle,dwMask); }
inline	DWORD		 CTreeListCtrl::GetExtendedStyle() const									{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetExtendedStyle(m_hWnd); }
inline	DWORD		 CTreeListCtrl::SetExtendedStyle(DWORD dwStyle)								{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetExtendedStyle(m_hWnd,dwStyle); }
inline	DWORD		 CTreeListCtrl::SetExtendedStyle(DWORD dwStyle,DWORD dwMask)				{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetExtendedStyleEx(m_hWnd,dwStyle,dwMask); }
inline	COLORREF	 CTreeListCtrl::GetColor(int iIndex) const									{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetColor(m_hWnd,iIndex); }
inline	COLORREF	 CTreeListCtrl::SetColor(int iIndex,COLORREF uColor)						{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetColor(m_hWnd,iIndex,uColor); }
inline	COLORREF	 CTreeListCtrl::GetItemBkColor  (HTREEITEM hItem,int nCol) const			{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetItemBkColor(m_hWnd,hItem,nCol); }
inline	COLORREF	 CTreeListCtrl::SetItemBkColor  (HTREEITEM hItem,int nCol,COLORREF uColor)	{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetItemBkColor(m_hWnd,hItem,nCol,uColor); }
inline	COLORREF	 CTreeListCtrl::GetItemTextColor(HTREEITEM hItem,int nCol) const			{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetItemTextColor(m_hWnd,hItem,nCol); }
inline	COLORREF	 CTreeListCtrl::SetItemTextColor(HTREEITEM hItem,int nCol,COLORREF uColor)	{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetItemTextColor(m_hWnd,hItem,nCol,uColor); }
inline	INT 		 CTreeListCtrl::IsItemVisible   (HTREEITEM hItem,int nCol)					{ ASSERT(::IsWindow(m_hWnd)); return TreeList_IsItemVisible(m_hWnd,hItem,nCol); }
inline	BOOL		 CTreeListCtrl::EnsureVisible   (HTREEITEM hItem,int nCol)					{ ASSERT(::IsWindow(m_hWnd)); return TreeList_EnsureVisibleEx(m_hWnd,hItem,nCol); }
inline	BOOL		 CTreeListCtrl::SelectDropTarget(HTREEITEM hItem,int nCol)					{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SelectDropTargetEx(m_hWnd,hItem,nCol); }
inline	BOOL		 CTreeListCtrl::SelectItem      (HTREEITEM hItem,int nCol)					{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SelectSubItem(m_hWnd,hItem,nCol); }
inline	BOOL		 CTreeListCtrl::StartEdit	    (HTREEITEM hItem,int nCol)					{ ASSERT(::IsWindow(m_hWnd)); return TreeList_StartEdit(m_hWnd,hItem,nCol); }
inline	BOOL		 CTreeListCtrl::SelectChilds    (HTREEITEM hItem,int iMode)					{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SelectChilds(m_hWnd,hItem,iMode); }
inline	BOOL 		 CTreeListCtrl::DeleteChildItems(HTREEITEM hItem)							{ ASSERT(::IsWindow(m_hWnd)); return TreeList_DeleteChildItems(m_hWnd,hItem); }
inline	BOOL		 CTreeListCtrl::GetItemRect     (HTREEITEM hItem,int nCol,RECT *pRect,int C){ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetItemRect (m_hWnd,hItem,nCol,pRect,C); }			
inline	BOOL		 CTreeListCtrl::SetFocusItem    (HTREEITEM hItem,int nCol)					{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetFocusItem(m_hWnd,hItem,nCol);}
inline	HTREEITEM	 CTreeListCtrl::GetNextItem     (HTREEITEM hItem,UINT nCode)				{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetNextItem (m_hWnd,hItem,nCode); }			
inline	HTREEITEM	 CTreeListCtrl::GetNextSelectedChild(HTREEITEM hItem) 						{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetNextSelectedChild(m_hWnd,hItem); }	
inline	HTREEITEM	 CTreeListCtrl::GetNextSelected (HTREEITEM hItem) 							{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetNextSelected(m_hWnd,hItem); }
inline	HTREEITEM	 CTreeListCtrl::GetLastChild    (HTREEITEM hItem) 							{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetLastChild(m_hWnd,hItem); }
inline	HTREEITEM	 CTreeListCtrl::GetFirstSelected()											{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetNextSelected(m_hWnd,TVI_ROOT); }
inline	HTREEITEM	 CTreeListCtrl::GetFirstItem()												{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetNextItem(m_hWnd,TVI_ROOT,TVGN_CHILD); }
inline	HTREEITEM	 CTreeListCtrl::GetFocusItem()												{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetFocus(m_hWnd); }
inline	INT 		 CTreeListCtrl::GetFocusColumn() 											{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetFocusColumn(m_hWnd); }														
inline	INT 		 CTreeListCtrl::GetSelectionColumn() 										{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetSelectionColumn(m_hWnd); }
inline	INT 		 CTreeListCtrl::GetDropHilightColumn() 										{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetDropHilightColumn(m_hWnd); }	
inline	CEdit		*CTreeListCtrl::EditLabel  (HTREEITEM hItem,int nCol,int iF       ,int iS)	{ ASSERT(::IsWindow(m_hWnd)); return (CEdit      *)CEdit      ::FromHandle(TreeList_EditLabel(m_hWnd,hItem,TVIR_EDITCOL(nCol)|((iF)? TVIR_EDITFULL:0)|(iS))); }
inline	CComboBox	*CTreeListCtrl::EditLabelCb(HTREEITEM hItem,int nCol,int iF,int iL,int iS)	{ ASSERT(::IsWindow(m_hWnd)); return (CComboBox  *)CEdit      ::FromHandle(TreeList_EditLabel(m_hWnd,hItem,TVIR_EDITCOL(nCol)|((iF)? TVIR_EDITFULL:0)|(iS)|((iL)? TVIR_EDITCOMBOLIST:TVIR_EDITCOMBOBOX))); }
inline	CHeaderCtrl *CTreeListCtrl::GetHeaderCtrl  () const										{ ASSERT(::IsWindow(m_hWnd)); return (CHeaderCtrl*)CHeaderCtrl::FromHandle(TreeList_GetHeader(m_hWnd)); }
inline	CComboBox   *CTreeListCtrl::GetComboControl() const										{ ASSERT(::IsWindow(m_hWnd)); return (CComboBox  *)CWnd       ::FromHandle((HWND)::SendMessage(m_hWnd,TVM_GETEDITCONTROL,0,0));}
inline	CEdit       *CTreeListCtrl::GetEditControl () const										{ ASSERT(::IsWindow(m_hWnd)); return (CEdit      *)CWnd       ::FromHandle((HWND)::SendMessage(m_hWnd,TVM_GETEDITCONTROL,0,0));}
inline	INT			 CTreeListCtrl::SetColumnAutoEdit(int n,int m							  )	{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetColumnAutoEdit(m_hWnd,n, m                                          ,NULL ); }			
inline	INT			 CTreeListCtrl::SetColumnAutoEdit(int n,int m,        LPTSTR  *pList,int x)	{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetColumnAutoEdit(m_hWnd,n,(m|TVAE_COUNT(x)             )| TVAE_PTRLIST,pList); }			
inline	INT			 CTreeListCtrl::SetColumnAutoEdit(int n,int m,        LPCTSTR *pList,int x)	{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetColumnAutoEdit(m_hWnd,n,(m|TVAE_COUNT(x)             )| TVAE_PTRLIST,pList); }			
inline	INT			 CTreeListCtrl::SetColumnAutoEdit(int n,int m,        LPCTSTR  pText,int x)	{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetColumnAutoEdit(m_hWnd,n,(m|TVAE_COUNT(x)             )&~TVAE_PTRLIST,pText); }			
inline	INT			 CTreeListCtrl::SetColumnAutoEdit(int n,int m,TCHAR c,LPCTSTR  pText,int x)	{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetColumnAutoEdit(m_hWnd,n,(m|TVAE_COUNT(x)|TVAE_CHAR(c))&~TVAE_PTRLIST,pText); }			
inline	INT			 CTreeListCtrl::SetColumnAutoIcon(int n,int iIcon                         )	{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetColumnAutoIcon(m_hWnd,n,iIcon); }			
inline	INT			 CTreeListCtrl::GetOption(int iOption)										{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetOption(m_hWnd,iOption); }			
inline	INT			 CTreeListCtrl::SetOption(int iOption,int  iValue)							{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetOption(m_hWnd,iOption,iValue); }			
inline	HIMAGELIST	 CTreeListCtrl::SetImageList(HIMAGELIST hImageList,int nImageListType     )	{ ASSERT(::IsWindow(m_hWnd)); return TreeList_SetImageList(m_hWnd,hImageList,nImageListType);}
inline	HTREEITEM	 CTreeListCtrl::InsertItem(LPTVINSERTSTRUCT pInsert)	 					{ ASSERT(::IsWindow(m_hWnd)); return (HTREEITEM)  ::SendMessage(m_hWnd,TVM_INSERTITEM,0,(LPARAM)pInsert);}
inline	HTREEITEM	 CTreeListCtrl::InsertItem(LPCTSTR I,int M,int S,HTREEITEM   P,HTREEITEM A)	{ ASSERT(::IsWindow(m_hWnd)); return InsertItem(TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE           ,I,M,S,0,0,0,P,A);}
inline	HTREEITEM	 CTreeListCtrl::InsertItem(LPCTSTR I,int M,int S,TLC_SORT_PARAMS1         )	{ ASSERT(::IsWindow(m_hWnd)); return InsertItem(TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE|TVIF_PARAM,I,M,S,0,0,L,P,A);}
inline	HTREEITEM	 CTreeListCtrl::InsertItem(LPCTSTR I,int M,int S,TLC_SORT_PARAMS2         )	{ ASSERT(::IsWindow(m_hWnd)); return InsertItem(TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE|TVIF_PARAM,I,M,S,0,0,L,O,P);}
inline	HTREEITEM	 CTreeListCtrl::InsertItem(LPCTSTR I,int M,      HTREEITEM   P,HTREEITEM A)	{ ASSERT(::IsWindow(m_hWnd)); return InsertItem(TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE           ,I,M,M,0,0,0,P,A);}
inline	HTREEITEM	 CTreeListCtrl::InsertItem(LPCTSTR I,int M,      TLC_SORT_PARAMS1         )	{ ASSERT(::IsWindow(m_hWnd)); return InsertItem(TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE|TVIF_PARAM,I,M,M,0,0,L,P,A);}
inline	HTREEITEM	 CTreeListCtrl::InsertItem(LPCTSTR I,int M,      TLC_SORT_PARAMS2         )	{ ASSERT(::IsWindow(m_hWnd)); return InsertItem(TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE|TVIF_PARAM,I,M,M,0,0,L,O,P);}
inline	HTREEITEM	 CTreeListCtrl::InsertItem(LPCTSTR I,            HTREEITEM   P,HTREEITEM A)	{ ASSERT(::IsWindow(m_hWnd)); return InsertItem(TVIF_TEXT                                         ,I,0,0,0,0,0,P,A);}
inline	HTREEITEM	 CTreeListCtrl::InsertItem(LPCTSTR I,            TLC_SORT_PARAMS1         )	{ ASSERT(::IsWindow(m_hWnd)); return InsertItem(TVIF_TEXT                              |TVIF_PARAM,I,0,0,0,0,L,P,A);}
inline	HTREEITEM	 CTreeListCtrl::InsertItem(LPCTSTR I,            TLC_SORT_PARAMS2         )	{ ASSERT(::IsWindow(m_hWnd)); return InsertItem(TVIF_TEXT                              |TVIF_PARAM,I,0,0,0,0,L,O,P);}
inline	HTREEITEM	 CTreeListCtrl::EnumItems(HTREEITEM hLast)									{ ASSERT(::IsWindow(m_hWnd)); return TreeList_GetNextItem(m_hWnd,hLast,TVGN_NEXTITEM); }
																																									   
inline	HTREEITEM	 CTreeListCtrl::FindItem(HTREEITEM hItem,LPCTSTR pText,int nCol,int iCase)	{ return FindItem(hItem,(iCase)? TVIF_CHILD|TVIF_TEXT|TVIF_CASE:TVIF_CHILD|TVIF_TEXT,nCol,pText);}
inline	HTREEITEM	 CTreeListCtrl::FindItem(HTREEITEM hItem,LPARAM  lParam)					{ return FindItem(hItem,         TVIF_CHILD|TVIF_PARAM                              ,0,0,lParam);}
inline	BOOL		 CTreeListCtrl::DisableItemAutoEdit(HTREEITEM hItem,int nCol,BOOL bDisable)	{ return SetItemState(hItem,nCol,(bDisable)? TVIS_DISABLEBIT:0,TVIS_DISABLEBIT);}
inline	BOOL		 CTreeListCtrl::SetItemState(HTREEITEM hItem,UINT nState,UINT nMask)		{ return SetItemState(hItem,0,nState,nMask);}
inline	BOOL		 CTreeListCtrl::EnsureVisible(HTREEITEM hItem)								{ return EnsureVisible(hItem,0xFFFFFFFF); }		
inline	BOOL		 CTreeListCtrl::ExpandAll(HTREEITEM hItem,int iCode)						{ return Expand(hItem,iCode|TVE_EXPAND|TVE_EXPANDRECURSIVE); }		
inline	BOOL		 CTreeListCtrl::CollapseAll(HTREEITEM hItem,int iCode)						{ return Expand(hItem,iCode|TVE_COLLAPSE|TVE_ALLCHILDS); }		
inline	BOOL		 CTreeListCtrl::GetItemRect(HTREEITEM hItem,RECT *pRect,int iCode)			{ return GetItemRect(hItem,pRect,iCode); }
inline	BOOL		 CTreeListCtrl::SetItem(TVITEM* pItem)										{ return CTreeCtrl::SetItem(pItem); }
inline	BOOL		 CTreeListCtrl::SetItemCheckBox(HTREEITEM hItem,int iBits,int nCol,UINT uM) { return SetItemState(hItem,nCol,iBits<<12,TVIS_STATEIMAGEMASK&(uM<<12));}
inline	BOOL		 CTreeListCtrl::GetItemCheckBox(HTREEITEM hItem,          int nCol,UINT uM) { return(GetItemState(hItem,TVIS_STATEIMAGEMASK,nCol)>>12)&uM;  }
inline	CImageList  *CTreeListCtrl::SetImageList(CImageList* pImageList, int nImageListType   )	{ return CTreeCtrl::SetImageList(pImageList,nImageListType); 	}

inline	VOID		 CTreeListCtrl::GetHeaderCtrl  (HWND &hWnd) const							{ ASSERT(::IsWindow(m_hWnd)); hWnd=(HWND)::SendMessage(m_hWnd,TVM_GETHEADER     ,0,0);}
inline	VOID		 CTreeListCtrl::GetEditControl (HWND &hWnd) const							{ ASSERT(::IsWindow(m_hWnd)); hWnd=(HWND)::SendMessage(m_hWnd,TVM_GETEDITCONTROL,0,0);}
inline	VOID		 CTreeListCtrl::GetComboControl(HWND &hWnd) const							{ ASSERT(::IsWindow(m_hWnd)); hWnd=(HWND)::SendMessage(m_hWnd,TVM_GETEDITCONTROL,0,0);}

// ListCtrl Functions

inline	BOOL		 CTreeListCtrl::ListSetItem(int iRow,LPCTSTR pTxt,int nImg,int nSt,int iMsk){ return ListSetItem(iRow,0,pTxt,nImg,nSt,iMsk);				}
inline	BOOL		 CTreeListCtrl::ListSetTopIndex     (int iRow)								{ return TreeList_SelectSetFirstVisible(m_hWnd,GetItemOfRow(iRow));}
inline	CEdit		*CTreeListCtrl::ListEditLabel	    (int iRow,int nCol,int iF       ,int iS){ return EditLabel	     (GetItemOfRow(iRow),nCol,iF   ,iS);	}
inline	CComboBox	*CTreeListCtrl::ListEditLabelCb	    (int iRow,int nCol,int iF,int iL,int iS){ return EditLabelCb	 (GetItemOfRow(iRow),nCol,iF,iL,iS);	}
inline	CImageList  *CTreeListCtrl::ListCreateDragImage (int iRow,int nCol)	 					{ return CreateDragImage (GetItemOfRow(iRow),nCol);				}
inline	LPCTSTR		 CTreeListCtrl::ListGetItemText     (int iRow,                     int nCol){ return GetItemText     (GetItemOfRow(iRow)             ,nCol);}
inline	BOOL		 CTreeListCtrl::ListSetItemText     (int iRow,LPCTSTR pText       ,int nCol){ return SetItemText     (GetItemOfRow(iRow),pText       ,nCol);}
inline	LRESULT		 CTreeListCtrl::ListGetItemData     (int iRow                              ){ return GetItemData     (GetItemOfRow(iRow)                  );}		
inline	UINT 		 CTreeListCtrl::ListGetItemState    (int iRow,UINT nStateMask     ,int nCol){ return GetItemState    (GetItemOfRow(iRow),nStateMask,  nCol);}		
inline	BOOL		 CTreeListCtrl::ListSetItemState    (int iRow,         UINT nStat,UINT nMsk){ return SetItemState    (GetItemOfRow(iRow),     nStat,nMsk);	}
inline	BOOL		 CTreeListCtrl::ListSetItemState    (int iRow,int nCol,UINT nStat,UINT nMsk){ return SetItemState    (GetItemOfRow(iRow),nCol,nStat,nMsk);	}
inline	BOOL		 CTreeListCtrl::ListGetItemCheckBox	(int iRow		    ,int nCol,UINT uMsk){ return GetItemCheckBox (GetItemOfRow(iRow),       nCol,uMsk);	}
inline	BOOL		 CTreeListCtrl::ListSetItemCheckBox	(int iRow,int iState,int nCol,UINT uMsk){ return SetItemCheckBox (GetItemOfRow(iRow),iState,nCol,uMsk);	}
inline	BOOL		 CTreeListCtrl::ListSelectItem	    (int iRow,int nCol)						{ return SelectItem	     (GetItemOfRow(iRow),nCol);				}
inline	BOOL		 CTreeListCtrl::ListSetFocusItem    (int iRow,int nCol)						{ return SetFocusItem    (GetItemOfRow(iRow),nCol);				}
inline	BOOL		 CTreeListCtrl::ListEnsureVisible   (int iRow,int nCol)						{ return EnsureVisible   (GetItemOfRow(iRow),nCol);				}
inline	BOOL		 CTreeListCtrl::ListEnsureVisible   (int iRow)								{ return EnsureVisible   (GetItemOfRow(iRow));					}
inline	LPVOID		 CTreeListCtrl::ListGetUserData	    (int iRow) const						{ return GetUserData     (GetItemOfRow(iRow));					}
inline	INT			 CTreeListCtrl::ListGetItemImageEx  (int iRow             ,int nCol)		{ return GetItemImageEx  (GetItemOfRow(iRow)       ,nCol);		}
inline	BOOL		 CTreeListCtrl::ListGetItemImageEx  (int iRow,int *pImage ,int nCol)		{ return GetItemImageEx  (GetItemOfRow(iRow),pImage,nCol);		}
inline	BOOL		 CTreeListCtrl::ListSetItemImageEx  (int iRow,int  nImage ,int nCol)		{ return SetItemImageEx  (GetItemOfRow(iRow),nImage,nCol);		}
inline	INT			 CTreeListCtrl::ListGetItemImage    (int iRow,int &nImage,int &nSelImage)	{ return GetItemImage    (GetItemOfRow(iRow),nImage,nSelImage);	}
inline	BOOL		 CTreeListCtrl::ListSetItemImage    (int iRow,int  nImage,int  nSelImage)	{ return SetItemImage    (GetItemOfRow(iRow),nImage,nSelImage);	}
inline	INT			 CTreeListCtrl::ListGetNextSelected (int iRow)								{ return GetRowOfItem    (GetNextSelected(GetItemOfRow(iRow)));	}
inline	INT			 CTreeListCtrl::ListGetFirstSelected(        )								{ return GetRowOfItem    (GetFirstSelected());					}
inline	COLORREF	 CTreeListCtrl::ListGetItemBkColor  (int iRow,int nCol) const				{ return GetItemBkColor  (GetItemOfRow(iRow),nCol);				}
inline	COLORREF	 CTreeListCtrl::ListSetItemBkColor  (int iRow,int nCol,COLORREF uColor)		{ return SetItemBkColor  (GetItemOfRow(iRow),nCol,uColor);		}
inline	COLORREF	 CTreeListCtrl::ListGetItemTextColor(int iRow,int nCol) const				{ return GetItemTextColor(GetItemOfRow(iRow),nCol);				}
inline	COLORREF	 CTreeListCtrl::ListSetItemTextColor(int iRow,int nCol,COLORREF uColor)		{ return SetItemTextColor(GetItemOfRow(iRow),nCol,uColor);		}
inline	BOOL		 CTreeListCtrl::ListSelectDropTarget(int iRow,int nCol)						{ return SelectDropTarget(GetItemOfRow(iRow),nCol);				}
inline	BOOL		 CTreeListCtrl::ListGetItemRect		(int iRow,int nCol,RECT *pRec,int iCode){ return GetItemRect	 (GetItemOfRow(iRow),nCol,pRec,iCode);	}
inline	BOOL		 CTreeListCtrl::ListGetItemRect		(int iRow,		   RECT *pRec,int iCode){ return GetItemRect	 (GetItemOfRow(iRow),     pRec,iCode);	}
inline	INT			 CTreeListCtrl::ListGetFocusItem    ()										{ return GetRowOfItem    (GetFocusItem());						}
inline	INT			 CTreeListCtrl::ListGetTopIndex     ()										{ int i= GetRowOfItem    (GetFirstVisibleItem());if(i<0)i=0;return i;}




#endif 	

