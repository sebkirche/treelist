
//#define UNICODE
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "../TreeListWnd.h"
#include "../resource.h"

HINSTANCE hInst;
BOOL bUseDll = FALSE;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void showConstants(void);


int main(int argc, char *argv[]) {

	HINSTANCE hInst;

	hInst = GetModuleHandle(NULL);

	showConstants();

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

			HINSTANCE hInst;
			HMODULE hLib;

			hInst = GetModuleHandle(NULL);
			if (bUseDll){
				hLib = LoadLibrary(TEXT("..\\PB\\TreeListA.dll"));
				printf("class registration: hInst=%08lx, hLib=%08lx\n", hInst, hLib);
			}
			else
				TreeListRegister(hInst);

			hWndTL = CreateWindow(TEXT(TVC_CLASSNAME),  TEXT("TreeList"), WS_VISIBLE | WS_CHILD | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS, 0, 0, 430, 300, hWnd, 0, hInst, NULL);
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
			TV_COLUMN col;
			memset(&col, 0, sizeof(TV_COLUMN));
			col.mask = TVCF_TEXT;
			col.pszText = TEXT("Tree (col 0)");
			col.cchTextMax = 256;
			//TreeList_InsertColumn(hWndTL, colIdx++, &col);
			LRESULT col1 = SendMessage(hWndTL, TVM_INSERTCOLUMN, (WPARAM)colIdx++, (LPARAM)&col);
			printf("TVM_INSERTCOLUMN returned %08lx\n", col1);

			col.mask = TVCF_TEXT | TVCF_IMAGE | TVCF_FMT;
			col.fmt = /*LVCFMT_CENTER | */ LVCFMT_BITMAP_ON_RIGHT;
			col.pszText = TEXT("col 1");
			col.iImage = 0;
			//TreeList_InsertColumn(hWndTL, colIdx++, &col);
			LRESULT col2 = SendMessage(hWndTL, TVM_INSERTCOLUMN, (WPARAM)colIdx++, (LPARAM)&col);
			printf("TVM_INSERTCOLUMN returned %08lx\n", col2);

			col.mask = TVCF_TEXT | TVCF_IMAGE | TVCF_FMT;
			col.fmt = /*LVCFMT_CENTER | */ LVCFMT_BITMAP_ON_RIGHT;
			col.pszText = TEXT("col 2");
			col.iImage = 1;
			col.fmt = /*LVCFMT_CENTER | */ LVCFMT_BITMAP_ON_RIGHT;
			//TreeList_InsertColumn(hWndTL, colIdx++, &col);
			LRESULT col3 = SendMessage(hWndTL, TVM_INSERTCOLUMN, (WPARAM)colIdx++, (LPARAM)&col);
			printf("TVM_INSERTCOLUMN returned %08lx\n", col3);

			col.mask = TVCF_TEXT | TVCF_IMAGE | TVCF_FMT;
			col.fmt = /*LVCFMT_CENTER | */ LVCFMT_BITMAP_ON_RIGHT;
			col.pszText = TEXT("col 3");
			col.iImage = 2;
			col.fmt = /*LVCFMT_CENTER | */ LVCFMT_BITMAP_ON_RIGHT;
			//TreeList_InsertColumn(hWndTL, colIdx++, &col);
			LRESULT col4 = SendMessage(hWndTL, TVM_INSERTCOLUMN, (WPARAM)colIdx++, (LPARAM)&col);
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
			printf("inserted 1 = %08lx\n", inserted);
			if (inserted){
				TV_ITEM itm;
				itm.mask = TVIF_SUBITEM | TVIF_TEXT | TVIF_STATE;
				itm.hItem = inserted;
				itm.state = 2;
				itm.stateMask = 2;
				itm.cChildren = 1;
				itm.pszText = "un texte";
				itm.cchTextMax = strlen(itm.pszText);
				SendMessage(hWndTL, TVM_SETITEM, 0, (LPARAM)&itm);
			}

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
			printf("inserted 2 = %08lx\n", inserted2);
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
				
				itm.mask			= TVIF_SUBITEM | TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_STATE;
				itm.pszText			= TEXT("bli bli");
				itm.cChildren		= 2;
				itm.iImage			= 11;
				itm.iSelectedImage  = 11;
				itm.stateMask = TVIS_BOLD | TVIS_EXPANDED;
				itm.state = TVIS_BOLD | TVIS_EXPANDED;
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
			printf("inserted 3 = %08lx\n", inserted2);

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
			printf("inserted 4 = %08lx\n", inserted);

			SetWindowLong(hWndTL, GWL_EXSTYLE, GetWindowLong(hWndTL, GWL_EXSTYLE) | TVS_EX_ITEMLINES);

			//---------------SET THE FONT--------------------------------------------

			HFONT hf;
			HDC hdc;
			long lfHeight;
			
			hdc = GetDC(NULL);
			lfHeight = -MulDiv(10, GetDeviceCaps(hdc, LOGPIXELSY), 72);
			ReleaseDC(NULL, hdc);

			hf = CreateFont(lfHeight, 0, 0, 0, FW_NORMAL, FALSE /*italic*/, FALSE /*underline*/, FALSE /*strikethrough*/, 0, 0, 0, 0, 0, TEXT("Comic Sans MS"));
			//hf = CreateFont(lfHeight, 0, 0, 0, FW_NORMAL, FALSE /*italic*/, FALSE /*underline*/, FALSE /*strikethrough*/, 0, 0, 0, 0, 0, TEXT("Arial"));
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


			TVITEM itm;
			char buffer[42];
			itm.hItem = (HTREEITEM)2;
			itm.cChildren = 1;
			itm.mask = TVIF_STATE | TVIF_HANDLE | TVIF_SUBITEM | TVIF_TEXT;
			itm.stateMask = TVIS_BOLD;
			itm.state = 0;
			itm.pszText = buffer;
			itm.cchTextMax = sizeof(buffer);

			LRESULT lr = SendMessage(hWndTL, TVM_GETITEM, 0, (LPARAM)&itm);
			printf("getstate = %d state = %08lx text = `%s` \n", lr, itm.state, itm.pszText);

			itm.state |= TVIS_BOLD;
			lr = SendMessage(hWndTL, TVM_SETITEM, 0, (LPARAM)&itm);
			printf("setstate = %d \n", lr);


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

void showConstants(void){
	printf("sizeof(NMHDR) = %ld\n", sizeof(NMHDR));
	printf("sizeof(TVITEM) = %ld\n", sizeof(TVITEM));
	printf("sizeof(POINT) = %ld\n", sizeof(POINT));
	printf("sizeof(NMTREEVIEW) = %ld\n", sizeof(NMTREEVIEW));
	printf("sizeof(TVFIND) = %ld\n", sizeof(TVFIND));
	printf("sizeof(TVCOLUMN) = %ld\n", sizeof(TVCOLUMN));
	printf("sizeof(TVINSERTSTRUCT) = %ld\n", sizeof(TVINSERTSTRUCT));
	//printf("//SIZEOF_NMHEADER=SIZEOF_NMHDR+3*4 = %ld\n", //SIZEOF_NMHEADER=SIZEOF_NMHDR+3*4);

	printf("TVC_BK = %ld\n", TVC_BK);
	printf("TVC_ODD = %ld\n", TVC_ODD);
	printf("TVC_EVEN = %ld\n", TVC_EVEN);
	printf("TVC_FRAME = %ld\n", TVC_FRAME);
	printf("TVC_TEXT = %ld\n", TVC_TEXT);
	printf("TVC_LINE = %ld\n", TVC_LINE);
	printf("TVC_BOX = %ld\n", TVC_BOX);
	printf("TVC_TRACK = %ld\n", TVC_TRACK);
	printf("TVC_MARK = %ld\n", TVC_MARK);
	printf("TVC_MARKODD = %ld\n", TVC_MARKODD);
	printf("TVC_MARKEVEN = %ld\n", TVC_MARKEVEN);
	printf("TVC_INSERT = %ld\n", TVC_INSERT);
	printf("TVC_BOXBG = %ld\n", TVC_BOXBG);
	printf("TVC_COLBK = %ld\n", TVC_COLBK);
	printf("TVC_COLODD = %ld\n", TVC_COLODD);
	printf("TVC_COLEVEN = %ld\n", TVC_COLEVEN);
	printf("TVC_GRAYED = %ld\n", TVC_GRAYED);

	printf("TVCFMT_BITMAP_ON_RIGHT  = %ld\n", TVCFMT_BITMAP_ON_RIGHT );
	printf("TVCFMT_CENTER  = %ld\n", TVCFMT_CENTER );
	printf("TVCFMT_COL_HAS_IMAGES  = %ld\n", TVCFMT_COL_HAS_IMAGES );
	printf("TVCFMT_FIXED  = %ld\n", TVCFMT_FIXED );
	printf("TVCFMT_IMAGE  = %ld\n", TVCFMT_IMAGE );
	printf("TVCFMT_LEFT  = %ld\n", TVCFMT_LEFT );
	printf("TVCFMT_MARK  = %ld\n", TVCFMT_MARK );
	printf("TVCFMT_RIGHT  = %ld\n", TVCFMT_RIGHT );
	printf("TVCF_FIXED  = %ld\n", TVCF_FIXED );
	printf("TVCF_FMT  = %ld\n", TVCF_FMT );
	printf("TVCF_IMAGE  = %ld\n", TVCF_IMAGE );
	printf("TVCF_LASTSIZE  = %ld\n", TVCF_LASTSIZE );
	printf("TVCF_MARK  = %ld\n", TVCF_MARK );
	printf("TVCF_MIN  = %ld\n", TVCF_MIN );
	printf("TVCF_TEXT  = %ld\n", TVCF_TEXT );
	printf("TVCF_VWIDTH  = %ld\n", TVCF_VWIDTH );
	printf("TVCF_WIDTH  = %ld\n", TVCF_WIDTH );
	printf("TVE_ALLCHILDS  = %ld\n", TVE_ALLCHILDS );
	printf("TVE_COLLAPSE  = %ld\n", TVE_COLLAPSE );
	printf("TVE_COLLAPSERESET  = %ld\n", TVE_COLLAPSERESET );
	printf("TVE_EXPAND  = %ld\n", TVE_EXPAND );
	printf("TVE_EXPANDFORCE  = %ld\n", TVE_EXPANDFORCE );
	printf("TVE_EXPANDNEXT  = %ld\n", TVE_EXPANDNEXT );
	printf("TVE_EXPANDPARTIAL  = %ld\n", TVE_EXPANDPARTIAL );
	printf("TVE_EXPANDRECURSIVE  = %ld\n", TVE_EXPANDRECURSIVE );
	printf("TVE_ONLYCHILDS  = %ld\n", TVE_ONLYCHILDS );
	printf("TVE_TOGGLE  = %ld\n", TVE_TOGGLE );
	printf("TVGN_CARET  = %ld\n", TVGN_CARET );
	printf("TVGN_CARETSUB  = %ld\n", TVGN_CARETSUB );
	printf("TVGN_CHILD  = %ld\n", TVGN_CHILD );
	printf("TVGN_DROPHILITE  = %ld\n", TVGN_DROPHILITE );
	printf("TVGN_DROPHILITESUB  = %ld\n", TVGN_DROPHILITESUB );
	printf("TVGN_FIRSTVISIBLE  = %ld\n", TVGN_FIRSTVISIBLE );
	printf("TVGN_FOCUS  = %ld\n", TVGN_FOCUS );
	printf("TVGN_FOCUSSUB  = %ld\n", TVGN_FOCUSSUB );
	printf("TVGN_LASTCHILD  = %ld\n", TVGN_LASTCHILD );
	printf("TVGN_LASTVISIBLE  = %ld\n", TVGN_LASTVISIBLE );
	printf("TVGN_NEXT  = %ld\n", TVGN_NEXT );
	printf("TVGN_NEXTITEM  = %ld\n", TVGN_NEXTITEM );
	printf("TVGN_NEXTSELCHILD  = %ld\n", TVGN_NEXTSELCHILD );
	printf("TVGN_NEXTSELECTED  = %ld\n", TVGN_NEXTSELECTED );
	printf("TVGN_NEXTVISIBLE  = %ld\n", TVGN_NEXTVISIBLE );
	printf("TVGN_PARENT  = %ld\n", TVGN_PARENT );
	printf("TVGN_PREVIOUS  = %ld\n", TVGN_PREVIOUS );
	printf("TVGN_PREVIOUSVISIBLE  = %ld\n", TVGN_PREVIOUSVISIBLE );
	printf("TVGN_ROOT  = %ld\n", TVGN_ROOT );
	printf("TVIF_CANCELED  = %ld\n", TVIF_CANCELED );
	printf("TVIF_CASE  = %ld\n", TVIF_CASE );
	printf("TVIF_CHILD  = %ld\n", TVIF_CHILD );
	printf("TVIF_CHILDREN  = %ld\n", TVIF_CHILDREN );
	printf("TVIF_DI_SETITEM  = %ld\n", TVIF_DI_SETITEM );
	printf("TVIF_HANDLE  = %ld\n", TVIF_HANDLE );
	printf("TVIF_IMAGE  = %ld\n", TVIF_IMAGE );
	printf("TVIF_INTEGRAL  = %ld\n", TVIF_INTEGRAL );
	printf("TVIF_NEXT  = %ld\n", TVIF_NEXT );
	printf("TVIF_ONLYFOCUS  = %ld\n", TVIF_ONLYFOCUS );
	printf("TVIF_PARAM  = %ld\n", TVIF_PARAM );
	printf("TVIF_RETURNEXIT  = %ld\n", TVIF_RETURNEXIT );
	printf("TVIF_SELECTEDIMAGE  = %ld\n", TVIF_SELECTEDIMAGE );
	printf("TVIF_STATE  = %ld\n", TVIF_STATE );
	printf("TVIF_SUBITEM  = %ld\n", TVIF_SUBITEM );
	printf("TVIF_SUBNUMBER  = %ld\n", TVIF_SUBNUMBER );
	printf("TVIF_TEXT  = %ld\n", TVIF_TEXT );
	printf("TVIF_TEXTCHANGED  = %ld\n", TVIF_TEXTCHANGED );
	printf("TVIF_TEXTPTR  = %ld\n", TVIF_TEXTPTR );
	printf("TVIF_TOOLTIPTIME  = %ld\n", TVIF_TOOLTIPTIME );
	printf("TVIS_BOLD  = %ld\n", TVIS_BOLD );
	printf("TVIS_UNDERLINE  = %ld\n", TVIS_UNTERLINE );
	printf("TVI_AFTER  = %ld\n", TVI_AFTER );
	printf("TVI_BEFORE  = %ld\n", TVI_BEFORE );
	printf("TVI_FIRST  = %ld\n", TVI_FIRST );
	printf("TVI_LAST  = %ld\n", TVI_LAST );
	printf("TVI_ROOT  = %ld\n", TVI_ROOT );
	printf("TVI_SORT  = %ld\n", TVI_SORT );
	printf("TVI_SORTEX  = %ld\n", TVI_SORTEX );
	printf("TVM_COLUMNAUTOEDIT  = %ld\n", TVM_COLUMNAUTOEDIT );
	printf("TVM_COLUMNAUTOICON  = %ld\n", TVM_COLUMNAUTOICON );
	printf("TVM_CREATEDRAGIMAGE  = %ld\n", TVM_CREATEDRAGIMAGE );
	printf("TVM_DELETECOLUMN  = %ld\n", TVM_DELETECOLUMN );
	printf("TVM_DELETEITEM  = %ld\n", TVM_DELETEITEM );
	printf("TVM_EDITLABEL  = %ld\n", TVM_EDITLABEL );
	printf("TVM_EDITLABELA  = %ld\n", TVM_EDITLABELA );
	printf("TVM_EDITLABELW  = %ld\n", TVM_EDITLABELW );
	printf("TVM_ENDEDITLABELNOW  = %ld\n", TVM_ENDEDITLABELNOW );
	printf("TVM_ENSUREVISIBLE  = %ld\n", TVM_ENSUREVISIBLE );
	printf("TVM_EXPAND  = %ld\n", TVM_EXPAND );
	printf("TVM_FINDITEM  = %ld\n", TVM_FINDITEM );
	printf("TVM_GETBKCOLOR  = %ld\n", TVM_GETBKCOLOR );
	printf("TVM_GETCOLUMN  = %ld\n", TVM_GETCOLUMN );
	printf("TVM_GETCOLUMNCOUNT  = %ld\n", TVM_GETCOLUMNCOUNT );
	printf("TVM_GETCOLUMNORDERARRAY  = %ld\n", TVM_GETCOLUMNORDERARRAY );
	printf("TVM_GETCOLUMNWIDTH  = %ld\n", TVM_GETCOLUMNWIDTH );
	printf("TVM_GETCOUNT  = %ld\n", TVM_GETCOUNT );
	printf("TVM_GETCOUNTPERPAGE  = %ld\n", TVM_GETCOUNTPERPAGE );
	printf("TVM_GETEDITCONTROL  = %ld\n", TVM_GETEDITCONTROL );
	printf("TVM_GETEXTENDEDSTYLE  = %ld\n", TVM_GETEXTENDEDSTYLE );
	printf("TVM_GETHEADER  = %ld\n", TVM_GETHEADER );
	printf("TVM_GETIMAGELIST  = %ld\n", TVM_GETIMAGELIST );
	printf("TVM_GETINDENT  = %ld\n", TVM_GETINDENT );
	printf("TVM_GETINSERTMARKCOLOR  = %ld\n", TVM_GETINSERTMARKCOLOR );
	printf("TVM_GETISEARCHSTRING  = %ld\n", TVM_GETISEARCHSTRING );
	printf("TVM_GETISEARCHSTRINGA  = %ld\n", TVM_GETISEARCHSTRINGA );
	printf("TVM_GETISEARCHSTRINGW  = %ld\n", TVM_GETISEARCHSTRINGW );
	printf("TVM_GETITEM  = %ld\n", TVM_GETITEM );
	printf("TVM_GETITEMA  = %ld\n", TVM_GETITEMA );
	printf("TVM_GETITEMBKCOLOR  = %ld\n", TVM_GETITEMBKCOLOR );
	printf("TVM_GETITEMHEIGHT  = %ld\n", TVM_GETITEMHEIGHT );
	printf("TVM_GETITEMOFROW  = %ld\n", TVM_GETITEMOFROW );
	printf("TVM_GETITEMRECT  = %ld\n", TVM_GETITEMRECT );
	printf("TVM_GETITEMSTATE  = %ld\n", TVM_GETITEMSTATE );
	printf("TVM_GETITEMTEXTCOLOR  = %ld\n", TVM_GETITEMTEXTCOLOR );
	printf("TVM_GETITEMW  = %ld\n", TVM_GETITEMW );
	printf("TVM_GETLINECOLOR  = %ld\n", TVM_GETLINECOLOR );
	printf("TVM_GETNEXTITEM  = %ld\n", TVM_GETNEXTITEM );
	printf("TVM_GETROWCOUNT  = %ld\n", TVM_GETROWCOUNT );
	printf("TVM_GETROWOFITEM  = %ld\n", TVM_GETROWOFITEM );
	printf("TVM_GETSCROLLTIME  = %ld\n", TVM_GETSCROLLTIME );
	printf("TVM_GETSETOPTION  = %ld\n", TVM_GETSETOPTION );
	printf("TVM_GETTEXTCOLOR  = %ld\n", TVM_GETTEXTCOLOR );
	printf("TVM_GETTOOLTIPS  = %ld\n", TVM_GETTOOLTIPS );
	printf("TVM_GETUNICODEFORMAT  = %ld\n", TVM_GETUNICODEFORMAT );
	printf("TVM_GETUSERDATA  = %ld\n", TVM_GETUSERDATA );
	printf("TVM_GETUSERDATASIZE  = %ld\n", TVM_GETUSERDATASIZE );
	printf("TVM_GETVISIBLECOUNT  = %ld\n", TVM_GETVISIBLECOUNT );
	printf("TVM_HITTEST  = %ld\n", TVM_HITTEST );
	printf("TVM_INSERTCOLUMN  = %ld\n", TVM_INSERTCOLUMN );
	printf("TVM_INSERTITEM  = %ld\n", TVM_INSERTITEM );
	printf("TVM_INSERTITEMA  = %ld\n", TVM_INSERTITEMA );
	printf("TVM_INSERTITEMW  = %ld\n", TVM_INSERTITEMW );
	printf("TVM_ISITEMVISIBLE  = %ld\n", TVM_ISITEMVISIBLE );
//	printf("TVM_MAPACCIDTOHTREEITEM  = %ld\n", TVM_MAPACCIDTOHTREEITEM );
//	printf("TVM_MAPHTREEITEMTOACCID  = %ld\n", TVM_MAPHTREEITEMTOACCID );
	printf("TVM_SELECTCHILDS  = %ld\n", TVM_SELECTCHILDS );
	printf("TVM_SELECTDROP  = %ld\n", TVM_SELECTDROP );
	printf("TVM_SELECTITEM  = %ld\n", TVM_SELECTITEM );
	printf("TVM_SELECTSUBITEM  = %ld\n", TVM_SELECTSUBITEM );
	printf("TVM_SETBKCOLOR  = %ld\n", TVM_SETBKCOLOR );
	printf("TVM_SETCOLUMN  = %ld\n", TVM_SETCOLUMN );
	printf("TVM_SETCOLUMNORDERARRAY  = %ld\n", TVM_SETCOLUMNORDERARRAY );
	printf("TVM_SETCOLUMNWIDTH  = %ld\n", TVM_SETCOLUMNWIDTH );
	printf("TVM_SETEXTENDEDSTYLE  = %ld\n", TVM_SETEXTENDEDSTYLE );
	printf("TVM_SETFOCUSITEM  = %ld\n", TVM_SETFOCUSITEM );
	printf("TVM_SETIMAGELIST  = %ld\n", TVM_SETIMAGELIST );
	printf("TVM_SETINDENT  = %ld\n", TVM_SETINDENT );
	printf("TVM_SETINSERTMARK  = %ld\n", TVM_SETINSERTMARK );
	printf("TVM_SETINSERTMARKCOLOR  = %ld\n", TVM_SETINSERTMARKCOLOR );
	printf("TVM_SETITEM  = %ld\n", TVM_SETITEM );
	printf("TVM_SETITEMA  = %ld\n", TVM_SETITEMA );
	printf("TVM_SETITEMBKCOLOR  = %ld\n", TVM_SETITEMBKCOLOR );
	printf("TVM_SETITEMHEIGHT  = %ld\n", TVM_SETITEMHEIGHT );
	printf("TVM_SETITEMTEXTCOLOR  = %ld\n", TVM_SETITEMTEXTCOLOR );
	printf("TVM_SETITEMW  = %ld\n", TVM_SETITEMW );
	printf("TVM_SETLINECOLOR  = %ld\n", TVM_SETLINECOLOR );
	printf("TVM_SETSCROLLTIME  = %ld\n", TVM_SETSCROLLTIME );
	printf("TVM_SETTEXTCOLOR  = %ld\n", TVM_SETTEXTCOLOR );
	printf("TVM_SETTOOLTIPS  = %ld\n", TVM_SETTOOLTIPS );
	printf("TVM_SETUNICODEFORMAT  = %ld\n", TVM_SETUNICODEFORMAT );
	printf("TVM_SETUSERDATASIZE  = %ld\n", TVM_SETUSERDATASIZE );
	printf("TVM_SORTCHILDREN  = %ld\n", TVM_SORTCHILDREN );
	printf("TVM_SORTCHILDRENCB  = %ld\n", TVM_SORTCHILDRENCB );
	printf("TVM_SORTCHILDRENEX  = %ld\n", TVM_SORTCHILDRENEX );
	printf("TVN_BEGINDRAG  = %ld\n", TVN_BEGINDRAG );
	printf("TVN_BEGINDRAGA  = %ld\n", TVN_BEGINDRAGA );
	printf("TVN_BEGINDRAGW  = %ld\n", TVN_BEGINDRAGW );
	printf("TVN_BEGINLABELEDIT  = %ld\n", TVN_BEGINLABELEDIT );
	printf("TVN_BEGINLABELEDITA  = %ld\n", TVN_BEGINLABELEDITA );
	printf("TVN_BEGINLABELEDITW  = %ld\n", TVN_BEGINLABELEDITW );
	printf("TVN_BEGINRDRAG  = %ld\n", TVN_BEGINRDRAG );
	printf("TVN_BEGINRDRAGA  = %ld\n", TVN_BEGINRDRAGA );
	printf("TVN_BEGINRDRAGW  = %ld\n", TVN_BEGINRDRAGW );
	printf("TVN_CBSTATECHANGED  = %ld\n", TVN_CBSTATECHANGED );
	printf("TVN_COLUMNCHANGED  = %ld\n", TVN_COLUMNCHANGED );
	printf("TVN_COLUMNCLICK  = %ld\n", TVN_COLUMNCLICK );
	printf("TVN_COLUMNDBLCLICK  = %ld\n", TVN_COLUMNDBLCLICK );
	printf("TVN_DELETEITEM  = %ld\n", TVN_DELETEITEM );
	printf("TVN_DELETEITEMA  = %ld\n", TVN_DELETEITEMA );
	printf("TVN_DELETEITEMW  = %ld\n", TVN_DELETEITEMW );
	printf("TVN_ENDLABELEDIT  = %ld\n", TVN_ENDLABELEDIT );
	printf("TVN_ENDLABELEDITA  = %ld\n", TVN_ENDLABELEDITA );
	printf("TVN_ENDLABELEDITW  = %ld\n", TVN_ENDLABELEDITW );
	printf("TVN_FIRST  = %ld\n", TVN_FIRST );
	printf("TVN_GETDISPINFO  = %ld\n", TVN_GETDISPINFO );
	printf("TVN_GETDISPINFOA  = %ld\n", TVN_GETDISPINFOA );
	printf("TVN_GETDISPINFOW  = %ld\n", TVN_GETDISPINFOW );
	printf("TVN_GETINFOTIP  = %ld\n", TVN_GETINFOTIP );
	printf("TVN_GETINFOTIPA  = %ld\n", TVN_GETINFOTIPA );
	printf("TVN_GETINFOTIPW  = %ld\n", TVN_GETINFOTIPW );
	printf("TVN_ITEMEXPANDED  = %ld\n", TVN_ITEMEXPANDED );
	printf("TVN_ITEMEXPANDEDA  = %ld\n", TVN_ITEMEXPANDEDA );
	printf("TVN_ITEMEXPANDEDW  = %ld\n", TVN_ITEMEXPANDEDW );
	printf("TVN_ITEMEXPANDING  = %ld\n", TVN_ITEMEXPANDING );
	printf("TVN_ITEMEXPANDINGA  = %ld\n", TVN_ITEMEXPANDINGA );
	printf("TVN_ITEMEXPANDINGW  = %ld\n", TVN_ITEMEXPANDINGW );
	printf("TVN_ITEMTOOLTIP  = %ld\n", TVN_ITEMTOOLTIP );
	printf("TVN_KEYDOWN  = %ld\n", TVN_KEYDOWN );
	printf("TVN_LAST  = %ld\n", TVN_LAST );
	printf("TVN_LBUTTONUP  = %ld\n", TVN_LBUTTONUP );
	printf("TVN_RBUTTONUP  = %ld\n", TVN_RBUTTONUP );
	printf("TVN_SELCHANGED  = %ld\n", TVN_SELCHANGED );
	printf("TVN_SELCHANGEDA  = %ld\n", TVN_SELCHANGEDA );
	printf("TVN_SELCHANGEDW  = %ld\n", TVN_SELCHANGEDW );
	printf("TVN_SELCHANGING  = %ld\n", TVN_SELCHANGING );
	printf("TVN_SELCHANGINGA  = %ld\n", TVN_SELCHANGINGA );
	printf("TVN_SELCHANGINGW  = %ld\n", TVN_SELCHANGINGW );
	printf("TVN_SETDISPINFO  = %ld\n", TVN_SETDISPINFO );
	printf("TVN_SETDISPINFOA  = %ld\n", TVN_SETDISPINFOA );
	printf("TVN_SETDISPINFOW  = %ld\n", TVN_SETDISPINFOW );
	printf("TVN_SINGLEEXPAND  = %ld\n", TVN_SINGLEEXPAND );
	printf("TVN_STARTEDIT  = %ld\n", TVN_STARTEDIT );
	printf("TVN_STEPSTATECHANGED  = %ld\n", TVN_STEPSTATECHANGED );
	printf("TVS_CHECKBOXES  = %ld\n", TVS_CHECKBOXES );
	printf("TVS_DISABLEDRAGDROP  = %ld\n", TVS_DISABLEDRAGDROP );
	printf("TVS_EDITLABELS  = %ld\n", TVS_EDITLABELS );
	printf("TVS_EX_ALTERNATECOLOR  = %ld\n", TVS_EX_ALTERNATECOLOR );
	printf("TVS_EX_AUTOEXPANDICON  = %ld\n", TVS_EX_AUTOEXPANDICON );
	printf("TVS_EX_AUTOHSCROLL  = %ld\n", TVS_EX_AUTOHSCROLL );
	printf("TVS_EX_BITCHECKBOX  = %ld\n", TVS_EX_BITCHECKBOX );
	printf("TVS_EX_EDITCLICK  = %ld\n", TVS_EX_EDITCLICK );
	printf("TVS_EX_FIXEDCOLSIZE  = %ld\n", TVS_EX_FIXEDCOLSIZE );
	printf("TVS_EX_FULLROWITEMS  = %ld\n", TVS_EX_FULLROWITEMS );
	printf("TVS_EX_FULLROWMARK  = %ld\n", TVS_EX_FULLROWMARK );
	printf("TVS_EX_GRAYEDDISABLE  = %ld\n", TVS_EX_GRAYEDDISABLE );
	printf("TVS_EX_HEADERCHGNOTIFY  = %ld\n", TVS_EX_HEADERCHGNOTIFY );
	printf("TVS_EX_HEADERDRAGDROP  = %ld\n", TVS_EX_HEADERDRAGDROP );
	printf("TVS_EX_HEADEROWNIMGLIST  = %ld\n", TVS_EX_HEADEROWNIMGLIST );
	printf("TVS_EX_HIDEHEADERS  = %ld\n", TVS_EX_HIDEHEADERS );
	printf("TVS_EX_HOMEENDSELECT  = %ld\n", TVS_EX_HOMEENDSELECT );
	printf("TVS_EX_ITEMLINES  = %ld\n", TVS_EX_ITEMLINES );
	printf("TVS_EX_MULTISELECT  = %ld\n", TVS_EX_MULTISELECT );
	printf("TVS_EX_NOCHARSELCET  = %ld\n", TVS_EX_NOCHARSELCET );
	printf("TVS_EX_NOCOLUMNRESIZE  = %ld\n", TVS_EX_NOCOLUMNRESIZE );
	printf("TVS_EX_NOCURSORSET  = %ld\n", TVS_EX_NOCURSORSET );
	printf("TVS_EX_SHAREIMAGELISTS  = %ld\n", TVS_EX_SHAREIMAGELISTS );
	printf("TVS_EX_SINGLECHECKBOX  = %ld\n", TVS_EX_SINGLECHECKBOX );
	printf("TVS_EX_STEPOUT  = %ld\n", TVS_EX_STEPOUT );
	printf("TVS_EX_SUBSELECT  = %ld\n", TVS_EX_SUBSELECT );
	printf("TVS_EX_TOOLTIPNOTIFY  = %ld\n", TVS_EX_TOOLTIPNOTIFY );
	printf("TVS_FULLROWSELECT  = %ld\n", TVS_FULLROWSELECT );
	printf("TVS_HASBUTTONS  = %ld\n", TVS_HASBUTTONS );
	printf("TVS_HASLINES  = %ld\n", TVS_HASLINES );
	printf("TVS_INFOTIP  = %ld\n", TVS_INFOTIP );
	printf("TVS_LINESATROOT  = %ld\n", TVS_LINESATROOT );
	printf("TVS_NOHSCROLL  = %ld\n", TVS_NOHSCROLL );
	printf("TVS_NONEVENHEIGHT  = %ld\n", TVS_NONEVENHEIGHT );
	printf("TVS_NOSCROLL  = %ld\n", TVS_NOSCROLL );
	printf("TVS_NOTOOLTIPS  = %ld\n", TVS_NOTOOLTIPS );
	printf("TVS_RTLREADING  = %ld\n", TVS_RTLREADING );
	printf("TVS_SHOWSELALWAYS  = %ld\n", TVS_SHOWSELALWAYS );
	printf("TVS_SINGLEEXPAND  = %ld\n", TVS_SINGLEEXPAND );
	printf("TVS_TRACKSELECT  = %ld\n", TVS_TRACKSELECT );
	printf("TVSIL_NORMAL  = %ld\n", TVSIL_NORMAL );
	printf("TVSIL_STATE  = %ld\n", TVSIL_STATE );
	printf("TVSIL_CHECK  = %ld\n", TVSIL_CHECK );
	printf("TVSIL_SUBIMAGES  = %ld\n", TVSIL_SUBIMAGES );
	printf("TVSIL_HEADER  = %ld\n", TVSIL_HEADER );

	printf("TV_FIRST  = %ld\n", TV_FIRST );
	printf("TV_NOIMAGE = %ld\n", TV_NOIMAGE);
	printf("TV_NOCOLOR = %ld\n", TV_NOCOLOR);


}