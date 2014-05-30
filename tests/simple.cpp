
//#define UNICODE
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "../TreeListWnd.h"
#include "../resource.h"

HINSTANCE hInst;
BOOL bUseDll = FALSE;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int main(int argc, char *argv[]) {

	HINSTANCE hInst;

	hInst = GetModuleHandle(NULL);

	//printf("argc = %d argv=%s\n", argc, argc==2 && argv[1]?argv[1]:"");
	if (argc == 2 && _stricmp(argv[1], "dll") == 0){
		printf("use dll\n");
		bUseDll = TRUE;
	}
		
	WNDCLASSEX wcex = {
		sizeof(WNDCLASSEX), 0, WndProc, 0, 0, hInst, /*IDR_MAINFRAME */ LoadIcon(NULL, IDI_APPLICATION),
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
			HMODULE hLib;
			//~ PTLR pTLR;
			//~ int initRet = 0;
			hInst = GetModuleHandle(NULL);
			if (bUseDll){
				hLib = LoadLibrary(TEXT("..\\PB\\TreeList.dll"));
				printf("class registration: hInst=%08lx, hLib=%08lx\n", hInst, hLib);
			}
			else
				TreeListRegister(hInst);
			//~ if(hLib){
			//~ pTLR = (PTLR)GetProcAddress(hLib, "TreeListRegister");
			//~ if(pTLR)
			//~ initRet = pTLR(hInst);
			//~ }
			//~ printf("class registration: hInst=%08lx, hLib=%08lx, TreeListRegister=%08lx returned %d\n", hInst, hLib, pTLR, initRet);

			//~ hWndTL = CreateWindow( TEXT(TVC_CLASSNAME),  TEXT("blah"), WS_VISIBLE |WS_CHILD|TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS, 0, 0, 430, 300, hWnd, 0, hLib, NULL );
			hWndTL = CreateWindow(TEXT(TVC_CLASSNAME),  TEXT("blah"), WS_VISIBLE | WS_CHILD | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS, 0, 0, 430, 300, hWnd, 0, hInst, NULL);
			//~ hWndTL = CreateWindow(TEXT(TVC_CLASSNAME),  TEXT("blah"), WS_VISIBLE |WS_CHILD|TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS, 0, 0, 430, 300, hWnd, 0, hInst, NULL );
			//hWndTL = CreateWindowEx( TVS_EX_ITEMLINES, TEXT(TVC_CLASSNAME), TEXT("blah"), WS_VISIBLE |WS_CHILD|TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS, 0, 0, 430, 300, hWnd, 0, hInst, NULL );
			printf("created windows is %08lx\n", hWndTL);

			SendMessage(hWndTL, TVM_SETEXTENDEDSTYLE, 0, TVS_EX_ITEMLINES | TVS_EX_ALTERNATECOLOR | TVS_EX_FULLROWMARK);

			HIMAGELIST hImgTree = ImageList_LoadImage(NULL, TEXT("flags.bmp"), 16, 10, CLR_DEFAULT, IMAGE_BITMAP, LR_LOADFROMFILE /*LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_SHARED | LR_LOADTRANSPARENT*/);
			if(NULL == hImgTree){
				DWORD dwErr = ::GetLastError();
				printf("ImageList_LoadImage() tree failed: %d.\n", dwErr);
			} else{
					printf("ImageList_LoadImage() tree succeeded, TVM_SETIMAGELIST returned %d.\n", SendMessage(hWndTL, TVM_SETIMAGELIST, TVSIL_NORMAL, (LPARAM)hImgTree));
					;
			}
			HIMAGELIST hImgHead = ImageList_LoadImage(NULL, TEXT("header.bmp"), 16, 10, CLR_DEFAULT, IMAGE_BITMAP, LR_LOADFROMFILE /*LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_SHARED | LR_LOADTRANSPARENT*/);
			if(NULL == hImgHead){
				DWORD dwErr = ::GetLastError();
				printf("ImageList_LoadImage() header failed: %d.\n", dwErr);
			} else{
					printf("ImageList_LoadImage() header succeeded, TVM_SETIMAGELIST returned %d.\n", SendMessage(hWndTL, TVM_SETIMAGELIST, TVSIL_HEADER, (LPARAM)hImgHead));
					;
			}

			//------------------------COLUMNS----------------------------------------------------------------
			int colIdx = 0;
			int lret;
			TV_COLUMN col;
			memset(&col, 0, sizeof(TV_COLUMN));
			col.mask = TVCF_TEXT;
			col.pszText = TEXT("Tree (col 0)");
			col.cchTextMax = 256;
			//TreeList_InsertColumn(hWndTL, colIdx++, &col);
			int col1 = SendMessage(hWndTL, TVM_INSERTCOLUMN, (WPARAM)colIdx++, (LPARAM)&col);
			printf("TVM_INSERTCOLUMN returned %08lx\n", col1);

			col.mask = TVCF_TEXT | TVCF_IMAGE | TVCF_FMT;
			col.fmt = /*LVCFMT_CENTER | */ LVCFMT_BITMAP_ON_RIGHT;
			col.pszText = TEXT("col 1");
			col.iImage = 0;
			//TreeList_InsertColumn(hWndTL, colIdx++, &col);
			int col2 = SendMessage(hWndTL, TVM_INSERTCOLUMN, (WPARAM)colIdx++, (LPARAM)&col);
			printf("TVM_INSERTCOLUMN returned %08lx\n", col2);

			col.mask = TVCF_TEXT | TVCF_IMAGE | TVCF_FMT;
			col.fmt = /*LVCFMT_CENTER | */ LVCFMT_BITMAP_ON_RIGHT;
			col.pszText = TEXT("col 2");
			col.iImage = 1;
			col.fmt = /*LVCFMT_CENTER | */ LVCFMT_BITMAP_ON_RIGHT;
			//TreeList_InsertColumn(hWndTL, colIdx++, &col);
			int col3 = SendMessage(hWndTL, TVM_INSERTCOLUMN, (WPARAM)colIdx++, (LPARAM)&col);
			printf("TVM_INSERTCOLUMN returned %08lx\n", col3);

			col.mask = TVCF_TEXT | TVCF_IMAGE | TVCF_FMT;
			col.fmt = /*LVCFMT_CENTER | */ LVCFMT_BITMAP_ON_RIGHT;
			col.pszText = TEXT("col 3");
			col.iImage = 2;
			col.fmt = /*LVCFMT_CENTER | */ LVCFMT_BITMAP_ON_RIGHT;
			//TreeList_InsertColumn(hWndTL, colIdx++, &col);
			int col4 = SendMessage(hWndTL, TVM_INSERTCOLUMN, (WPARAM)colIdx++, (LPARAM)&col);
			printf("TVM_INSERTCOLUMN returned %08lx\n", col4);

			//------------------------LINES----------------------------------------------------------------

			HTREEITEM inserted, inserted2;
			TVINSERTSTRUCT item;
			item.hParent				= 0;
			item.hInsertAfter		= TVI_SORTEX;
			item.item.hItem			= 0;//(HTREEITEM)pCmpProc;
			item.item.pszText		= TEXT("Item 1");
			item.item.mask			= TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
			item.item.iImage		= 0;
			item.item.iSelectedImage = 2;
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
			if(inserted2) {
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
				
				itm.mask			= TVIF_SUBITEM | TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
				itm.pszText			= TEXT("bli bli");
				itm.cChildren		= 2;
				itm.iImage			= 11;
				itm.iSelectedImage  = 11;
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

			SetWindowLong(hWndTL, GWL_EXSTYLE, GetWindowLong(hWndTL, GWL_EXSTYLE) | TVS_EX_ITEMLINES);

			//---------------SET THE FONT--------------------------------------------

			HFONT hf;
			HDC hdc;
			long lfHeight;
			
			hdc = GetDC(NULL);
			lfHeight = -MulDiv(10, GetDeviceCaps(hdc, LOGPIXELSY), 72);
			ReleaseDC(NULL, hdc);

			hf = CreateFont(lfHeight, 0, 0, 0, FW_NORMAL, FALSE /*italic*/, FALSE /*underline*/, FALSE /*strikethrough*/, 0, 0, 0, 0, 0, TEXT("Comic Sans MS"));
			if(hf){
				printf("CreateFont succeeded.\n");
				SendMessage(hWndTL, WM_SETFONT, (WPARAM)hf, TRUE);
				//DeleteObject(hf);
			} else
				printf("CreateFont failed!\n");

			LVCOLUMN tcol;
			tcol.fmt	= TVCFMT_FIXED|TVCFMT_MARK;
			tcol.mask	= TVCF_FIXED | TVCF_MARK | TVCF_WIDTH;
			tcol.cx    = 1;
			SendMessage(hWndTL, TVM_SETCOLUMN, col2, (LPARAM)&tcol);

			SendMessage(hWndTL, TVM_GETUNICODEFORMAT, 0, 0);

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
			printf("%s", sMsg);
			PostQuitMessage(0);
			return 0;
		}
		break;
		default
				:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
