
//#define UNICODE
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "TreeListWnd.h"

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int main(int argc, char *argv[]){
	
	HINSTANCE hInst;

	hInst = GetModuleHandle(NULL);
	
	WNDCLASSEX wcex = {
		sizeof(WNDCLASSEX), 0, WndProc, 0, 0, hInst, LoadIcon(NULL, IDI_APPLICATION),
		LoadCursor(NULL, IDC_ARROW), (HBRUSH)(COLOR_WINDOW + 1), NULL, TEXT("TreeListDemo"), NULL,
	};
	if(!RegisterClassEx(&wcex))
		return MessageBox(NULL, TEXT("Cannot register class !"), TEXT("Error"), MB_ICONERROR | MB_OK);

	int nX = (GetSystemMetrics(SM_CXSCREEN) - 860) / 2, nY = (GetSystemMetrics(SM_CYSCREEN) - 600) / 2;
	HWND hWnd = CreateWindowEx(0, wcex.lpszClassName, TEXT("TestTreeList"),
	        WS_OVERLAPPEDWINDOW, nX, nY, 860, 600, NULL, NULL, hInst, NULL);
	if(!hWnd)
		return MessageBox(NULL, TEXT("Cannot create window !"), TEXT("Error"), MB_ICONERROR | MB_OK);
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
	MSG msg;
	while(GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	static HWND hWndTL;
	switch(message) {
		case WM_CREATE: {
			BOOL bRet;

			//~ typedef int (* PTLR)(HINSTANCE hInstance); 
			HINSTANCE hInst;
			//~ PTLR pTLR;
			//~ int initRet = 0;
			hInst = GetModuleHandle(NULL);
			//~ HMODULE hLib = LoadLibrary(TEXT("TreeList.dll"));
			TreeListRegister(hInst);
			//~ if(hLib){
				//~ pTLR = (PTLR)GetProcAddress(hLib, "TreeListRegister");
				//~ if(pTLR)
					//~ initRet = pTLR(hInst);
			//~ }
			//~ printf("class registration: hInst=%08lx, hLib=%08lx, TreeListRegister=%08lx returned %d\n", hInst, hLib, pTLR, initRet);
			
			//~ hWndTL = CreateWindow( TEXT(TVC_CLASSNAME),  TEXT("blah"), WS_VISIBLE |WS_CHILD|TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS, 0, 0, 430, 300, hWnd, 0, hLib, NULL );
			hWndTL = CreateWindow( TEXT(TVC_CLASSNAME),  TEXT("blah"), WS_VISIBLE |WS_CHILD|TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS, 0, 0, 430, 300, hWnd, 0, hInst, NULL );
			printf("created windows is %08lx\n", hWndTL);

			int colIdx = 0;
			int lret;
			TV_COLUMN col;
			memset(&col, 0, sizeof(TV_COLUMN));
			col.mask = 0;
			col.mask |= TVCF_TEXT;
			col.pszText = TEXT("titi");
			col.cchTextMax = 256;
			//TreeList_InsertColumn(hWndTL, colIdx++, &col);
			lret = SendMessage(hWndTL, TVM_INSERTCOLUMN, (WPARAM)colIdx++, (LPARAM)&col);
			printf("TVM_INSERTCOLUMN returned %08lx\n", lret);
			
			col.pszText = TEXT("toto");
			//TreeList_InsertColumn(hWndTL, colIdx++, &col);
			lret = SendMessage(hWndTL, TVM_INSERTCOLUMN, (WPARAM)colIdx++, (LPARAM)&col);
			printf("TVM_INSERTCOLUMN returned %08lx\n", lret);
			
			//~ InsertItem(pItems1[i], i, i, TVI_ROOT)
			//~ InsertItem(TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE           ,I,M,S,0,0,0,P,A)
			//~ InsertItem(UINT nMask, LPCTSTR pText, int nImage, int nSelImage, UINT nState, UINT nStateMask, LPARAM lParam, HTREEITEM hParent, HTREEITEM hInsertAfter) {
			
			HTREEITEM inserted, inserted2;
			TVINSERTSTRUCT item;
			item.hParent				= 0;
			item.hInsertAfter		= TVI_SORTEX;
			item.item.hItem			= 0;//(HTREEITEM)pCmpProc;
			item.item.pszText		= TEXT("Item 1");
			item.item.mask			= TVIF_TEXT;
			item.item.iImage		= TV_NOIMAGE;
			item.item.iSelectedImage = TV_NOIMAGE;
			item.item.state			= 0;
			item.item.stateMask		= 0;
			item.item.lParam			= 0;
			inserted = (HTREEITEM)SendMessage(hWndTL, TVM_INSERTITEM, 0, (LPARAM)&item);
			printf("inserted = %08lx\n", inserted);
			
			TVINSERTSTRUCT item2;
			item2.hParent = inserted;
			item2.hInsertAfter = TVI_LAST  ;
			item2.item.hItem = 0;
			item2.item.pszText		= TEXT("Item 2");
			item2.item.mask			= TVIF_TEXT;
			item2.item.iImage		= TV_NOIMAGE;
			item2.item.iSelectedImage = TV_NOIMAGE;
			item2.item.state			= 0;
			item2.item.stateMask		= 0;
			item2.item.lParam			= 0;
			inserted2 = (HTREEITEM)SendMessage(hWndTL, TVM_INSERTITEM, 0, (LPARAM)&item2);
			printf("inserted = %08lx\n", inserted2);
			if(inserted2){
				SendMessage(hWndTL, TVM_EXPAND, TVE_EXPAND, (LPARAM)inserted);
				TV_ITEM itm;
				itm.mask			= TVIF_SUBITEM | TVIF_TEXT;
				itm.hItem			= inserted2;
				itm.state			= 0;
				itm.stateMask		= 0;
				itm.pszText			= TEXT("blah blah");
				itm.cchTextMax		= 256;
				itm.iImage			= 0;
				itm.iSelectedImage	= 0;
				itm.cChildren		= 1;
				itm.lParam			= 0;
				SendMessage(hWndTL, TVM_SETITEM, 0, (LPARAM)&itm);
			}
			
			TVINSERTSTRUCT item3;
			item3.hParent = inserted2;
			item3.hInsertAfter = TVI_LAST  ;
			item3.item.hItem = 0;
			item3.item.pszText		= TEXT("Item 3");
			item3.item.mask			= TVIF_TEXT;
			item3.item.iImage		= TV_NOIMAGE;
			item3.item.iSelectedImage = TV_NOIMAGE;
			item3.item.state			= 0;
			item3.item.stateMask		= 0;
			item3.item.lParam			= 0;
			inserted2 = (HTREEITEM)SendMessage(hWndTL, TVM_INSERTITEM, 0, (LPARAM)&item3);
			printf("inserted = %08lx\n", inserted2);
			
			TVINSERTSTRUCT item4;
			item4.hParent = inserted;
			item4.hInsertAfter = TVI_LAST  ;
			item4.item.hItem = 0;
			item4.item.pszText		= TEXT("Item 4");
			item4.item.mask			= TVIF_TEXT;
			item4.item.iImage		= TV_NOIMAGE;
			item4.item.iSelectedImage = TV_NOIMAGE;
			item4.item.state			= 0;
			item4.item.stateMask		= 0;
			item4.item.lParam			= 0;
			inserted = (HTREEITEM)SendMessage(hWndTL, TVM_INSERTITEM, 0, (LPARAM)&item4);
			printf("inserted = %08lx\n", inserted);
			
			
			return 0;
		}
		break;
		case WM_SIZE: {
			MoveWindow(hWndTL, 0, 0, LOWORD(lParam), HIWORD(lParam), TRUE);
			return 0;
		}
		break;
		case WM_DESTROY: {
			TCHAR sMsg[50];
			wsprintf(sMsg, TEXT("%d items"), SendMessage(hWndTL, TVM_GETROWCOUNT, (WPARAM)NULL, (LPARAM)NULL));
			OutputDebugString(sMsg);
			printf("%s",sMsg);
			PostQuitMessage(0);
			return 0;
		}
		break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
