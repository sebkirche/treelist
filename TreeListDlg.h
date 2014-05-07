//*****************************************************************************
//*
//*
//*		TreeListDlg.h
//*
//*
//*****************************************************************************
#ifndef		AFX_TREELISTDLG_H__C9C3C776_6449_4E21_8D23_9B5ED42A4027__INCLUDED_
#define		AFX_TREELISTDLG_H__C9C3C776_6449_4E21_8D23_9B5ED42A4027__INCLUDED_	

#if _MSC_VER > 1000
#pragma once
#endif

#include	"TreeListCtrl.h"

//*****************************************************************************
//*
//*		CTreeListDlg
//*
//*****************************************************************************
class CTreeListDlg : public CDialog
{
public:
	CTreeListDlg(CWnd *pParent = NULL); 			

	//{{AFX_DATA(CTreeListDlg)
	enum { IDD = IDD_TREELIST_DIALOG };
	BOOL	m_bFullWidth;
	BOOL	m_bOnlyReturn;
	BOOL	m_bPtrList;
	BOOL	m_bDropDown;
	BOOL	m_bDblClick;
	BOOL	m_bNextLine;
	BOOL	m_bStateEnable;
	BOOL	m_bIconClick;
	BOOL	m_bAutoEnable;
	int		m_iCheckMode;
	int		m_iAutoEditMode;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CTreeListDlg)
protected:
	virtual void DoDataExchange(CDataExchange *pDX);
	//}}AFX_VIRTUAL

protected:

	HTREEITEM		m_hSelect;
	int				m_iSelCol;
	HICON			m_hIcon;
	CTreeListCtrl	m_cTreeList;
	CImageList		m_cImages;
	CImageList		m_cChecks;
	CString			m_sUserData;
	unsigned		m_uSelState;

	//{{AFX_MSG(CTreeListDlg)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT pDrawItemStruct);
	afx_msg void OnPaint();
	afx_msg void OnCombo();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnRadio5();
	afx_msg void OnRadio6();
	afx_msg void OnRadio7();
	afx_msg void OnRadio8();
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck3();
	afx_msg void OnCheck4();
	afx_msg void OnCheck5();
	afx_msg void OnCheck6();
	afx_msg void OnCheck7();
	afx_msg void OnCheck8();
	afx_msg void OnCheck9();
	afx_msg void OnCheck10();
	afx_msg void OnCheck11();
	afx_msg void OnCheck12();
	afx_msg void OnCheck13();
	afx_msg void OnCheck14();
	afx_msg void OnCheck15();
	afx_msg void OnCheck16();
	afx_msg void OnCheck17();
	afx_msg void OnCheck18();
	afx_msg void OnCheck19();
	afx_msg void OnCheck20();
	afx_msg void OnCheck21();
	afx_msg void OnCheck22();
	afx_msg void OnCheck23();
	afx_msg void OnCheck24();
	afx_msg void OnCheck25();
	afx_msg void OnCheck26();
	afx_msg void OnCheck27();
	afx_msg void OnCheck28();
	afx_msg void OnCheck29();
	afx_msg void OnCheck30();
	afx_msg void OnCheck31();
	afx_msg void OnCheck32();
	afx_msg void OnCheck33();
	afx_msg void OnCheck34();
	afx_msg void OnCheck35();
	afx_msg void OnCheck36();
	afx_msg void OnCheck37();
	afx_msg void OnCheck38();
	afx_msg void OnCheck39();
	afx_msg void OnCheck40();
	afx_msg void OnCheck41();
	afx_msg void OnCheck42();
	afx_msg void OnCheck43();
	afx_msg void OnCheck44();
	afx_msg void OnChangeCheck();
	afx_msg void OnChangeColor1();
	afx_msg void OnChangeColor2();
	afx_msg void OnChangeColor3();
	afx_msg void OnChangeColor4();
	afx_msg void OnChangeColor5();
	afx_msg void OnChangeColor6();
	afx_msg void OnChangeColor7();
	afx_msg void OnChangeColor8();
	afx_msg void OnContextMenu(CWnd *pWnd,CPoint sPoint);
	afx_msg void OnEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	void OnCheck(int iID);
	void OnReturn        (NMHDR *pNmHdr, LRESULT *pResult);
	void OnSelChanged    (NMHDR *pNmHdr, LRESULT *pResult);
	void OnColumnClick   (NMHDR *pNmHdr, LRESULT *pResult);
	void OnItemExpanded  (NMHDR *pNmHdr, LRESULT *pResult);
	void OnEndLabelEdit	 (NMHDR *pNmHdr, LRESULT *pResult);
	void OnTooltipNotify (NMHDR *pNmHdr, LRESULT *pResult);
	void OnBeginLabelEdit(NMHDR *pNmHdr, LRESULT *pResult);
	void OnCbStateChanged(NMHDR *pNmHdr, LRESULT *pResult);
	void OnUpdateAutoEdit();		
	void OnUpdateState   ();

};

//{{AFX_INSERT_LOCATION}}

#endif
