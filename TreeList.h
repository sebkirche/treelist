//*****************************************************************************
//*
//*
//*		TreeList.h
//*
//*
//*****************************************************************************
// TreeList.h : Haupt-Header-Datei für die Anwendung TREELIST
//

#ifndef		AFX_TREELIST_H__B659124F_885D_44B5_BA14_7C996BFF0657__INCLUDED_
#define		AFX_TREELIST_H__B659124F_885D_44B5_BA14_7C996BFF0657__INCLUDED_	

#if _MSC_VER > 1000
#pragma once
#endif
#ifndef		__AFXWIN_H__				
	#error include 'stdafx.h' before including this file for PCH
#endif

#include	"resource.h"										

//*****************************************************************************
//*
//*		CTreeListApp
//*
//*****************************************************************************
class CTreeListApp : public CWinApp
{
public:
	CTreeListApp();

	//{{AFX_VIRTUAL(CTreeListApp)
public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL


	//{{AFX_MSG(CTreeListApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//{{AFX_INSERT_LOCATION}}

#endif