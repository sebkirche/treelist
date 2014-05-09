//*****************************************************************************
//*
//*
//*		TreeListWnd.h
//*
//*
//*****************************************************************************
#ifndef 	__TREELISTWND_H__
#define 	__TREELISTWND_H__

#if _MSC_VER > 1000
#pragma once
#endif

#include	<commctrl.h>

typedef int (CALLBACK *PFNTVCOMPAREEX)(HWND hWnd,HTREEITEM hItem1,HTREEITEM hItem2,LPARAM lParam1,LPARAM lParam2,LPARAM lParam);
typedef int (CALLBACK *PFNTVSORTEX   )(HWND hWnd,HTREEITEM hItem ,LPCTSTR pTextItem,LPCTSTR pTextInsert,LPARAM lParamItem,LPARAM lParamInsert);

typedef struct {
    HTREEITEM       hParent;
    PFNTVCOMPAREEX  lpfnCompare;
    LPARAM          lParam;
} TVSORTEX;

typedef struct {
	UINT			uFlags;
	UINT			uColumn;
	UINT			uState;
	UINT			uStateMask;
	LPARAM			lParam;
	LPCTSTR			pText;
} TVFIND;

typedef struct {
    NMHDR			hdr;
    WORD			wVKey;
	WORD			wScan;
    UINT			flags;
} TV_KEYDOWN_EX;

typedef struct {
    NMHDR			hdr;
    TVITEM			item;
	UINT			uAction;
	UINT			uHeight;
	UINT			uMaxEntries;
	LPCTSTR			pTextEntries;
	LPCTSTR		   *pTextList;
	POINT			ptAction;
} TV_STARTEDIT;

typedef struct {
    NMHDR			hdr;
    UINT			uColumn;
	UINT			uIndex;
	UINT			uPosX;
	INT				iSize;
} TV_COLSIZE;

typedef		TVSORTEX			   *LPTVSORTEX;
typedef		TVSORTEX			   *LPTV_SORTEX;
typedef		TVSORTEX				TV_SORTEX;


#define 	TVCOLUMN				LV_COLUMN
#define 	TV_COLUMN				LV_COLUMN
#define 	TV_FIND					TVFIND
#define 	TV_NOIMAGE				(-2)
#define 	TV_NOCOLOR				0xFFFFFFFF
#define 	TV_NOAUTOEXPAND			0x20000000
#define 	TV_SECONDICON			0x40000000
#define 	TVLE_DONOTIFY			0xF5A5A500
#define 	TVIF_TEXTPTR			0x80000000
#define 	TVIF_TOOLTIPTIME		0x40000000
#define		TVIF_TEXTCHANGED		0x20000000
#define		TVIF_RETURNEXIT			0x10000000
#define 	TVIF_CASE				0x08000000
#define 	TVIF_NEXT				0x04000000
#define 	TVIF_CHILD				0x02000000
#define 	TVIF_CANCELED			0x01000000
#define 	TVIF_ONLYFOCUS			0x00800000
#define		TVIF_SUBITEM	        0x8000
#define 	TVIF_SUBNUMBER			0x4000
#define 	TVIS_UNTERLINE			0x0001
#define 	TVSIL_CHECK				0x0003
#define 	TVSIL_SUBIMAGES			0x0004
#define		TVN_COLUMNCLICK			HDN_ITEMCLICK
#define 	TVN_COLUMNDBLCLICK		HDN_ITEMDBLCLICK
#define 	TVE_EXPANDRECURSIVE		(0x80000000)
#define 	TVE_EXPANDFORCE			(0x40000000)
#define 	TVE_EXPANDNEXT			(0x20000000)
#define 	TVE_ALLCHILDS			(0x10000000)
#define 	TVE_ONLYCHILDS			(0x00000008)
#define 	TVI_SORTEX				((HTREEITEM) 0xFFFF0007)
#define 	TVI_BEFORE				((HTREEITEM) 0xFFFF0006)
#define 	TVI_AFTER				((HTREEITEM) 0xFFFF0005)
#define		TVI_ROW(n)		        ((HTREEITEM)(0xFFE00000+(n)))
#ifndef		VK_DBLCLK
#define 	VK_DBLCLK				0x10000				// Edit with doubleclick
#endif
#ifndef		VK_ICONCLK
#define 	VK_ICONCLK				0x10001				// Edit with click on icon
#endif
#ifndef		VK_EDITCLK
#define 	VK_EDITCLK				0x10002				// Edit mit Klick auf augewähltes Element
#endif
#ifdef		UNICODE
#define		TV_UINICODE				1
#else		
#define		TV_UINICODE				0
#endif		

#define TVC_CLASSNAME "TreeList"

// Color Constants (TVM_SETBKCOLOR)
#define 	TVC_BK					0					// Hintergrundfarbe
#define 	TVC_ODD					1					// Abwechselnte Farbe        (siehe TVS_EX_ALTERNATECOLOR)
#define 	TVC_EVEN				2					// Abwechselnte Farbe gerade (siehe TVS_EX_ALTERNATECOLOR)
#define 	TVC_FRAME				3					// Farbe für Trennlinien (siehe TVS_EX_ITEMLINES)
#define 	TVC_TEXT				4					// Textfarbe
#define 	TVC_LINE				5					// Innere Farbe der Schaltflächen
#define 	TVC_BOX					6					// Äußere Farbe der Schaltflächen
#define 	TVC_TRACK				7					// Farbe für getrakte Texte
#define 	TVC_MARK				8					// Markierte Zeile
#define 	TVC_MARKODD				8					// Markierte Zeile (ungerade)
#define 	TVC_MARKEVEN			9					// Markierte Zeile (gerade)
#define 	TVC_INSERT				10					// Farbe der Einfügemarke
#define 	TVC_BOXBG				11					// Hindergrundfarbe der Schaltflächen
#define 	TVC_COLBK				12					// Hintergrundfarbe wenn Spalte markiert
#define 	TVC_COLODD				13					// Abwechselnte Farbe wenn Spalte markiert
#define 	TVC_COLEVEN				14					// Abwechselnte Farbe gerade wenn Spalte markiert
#define 	TVC_GRAYED				15					// Hindergrundfarbe wenn gesperrt


// Konstanten für GetNextItem (TVM_GETNEXTITEM)
#define 	TVGN_DROPHILITESUB		0x000C				// Ausgewählte Spalte holen
#define 	TVGN_CARETSUB			0x000D				// Drophighilite Spalte holen
#ifndef		TVGN_NEXTSELECTED
#define 	TVGN_NEXTSELECTED		0x000E				// Nächster ausgewählter Eintrag
#endif
#define 	TVGN_FOCUS				0x000F				// Eintrag der den Focus hat
#define 	TVGN_FOCUSSUB			0x0010				// Spalte  die den Focus hat
#define 	TVGN_NEXTSELCHILD		0x0011				// Nächster ausgewählter Kindeintrag
#define 	TVGN_LASTCHILD			0x0012				// Letzter Kindeintrag
#define 	TVGN_NEXTITEM			0x0013				// Für Enumerierung der Einträge


// Konstanten für InsertColumn (mask)
#define 	TVCF_FMT				LVCF_FMT			// Die Textausrichting einstellen
#define 	TVCF_IMAGE				LVCF_IMAGE			// Ein Icon der Spalte zu ortenen
#define 	TVCF_TEXT				LVCF_TEXT			// Den Text der Spalte setzen
#define 	TVCF_WIDTH				LVCF_WIDTH			// Fixe Breite festlegen
#define 	TVCF_VWIDTH				LVCF_SUBITEM		// Variable Breite festlegen
#define 	TVCF_MIN				LVCF_ORDER			// Minimale Breite festlegen
#define 	TVCF_MARK				0x80000000			// Soll die Spalte markiert werden
#define 	TVCF_FIXED				0x40000000			// Darf die Spaltenbreite verändert werden
#define 	TVCF_LASTSIZE			0x44332211			// Breite vor dem Fixieren wieder herstellen


// Konstanten für InsertColumn (format mask)
#define 	TVCFMT_BITMAP_ON_RIGHT	LVCFMT_BITMAP_ON_RIGHT
#define 	TVCFMT_COL_HAS_IMAGES	LVCFMT_COL_HAS_IMAGES
#define 	TVCFMT_CENTER			LVCFMT_CENTER
#define 	TVCFMT_IMAGE			LVCFMT_IMAGE
#define 	TVCFMT_LEFT				LVCFMT_LEFT
#define 	TVCFMT_RIGHT			LVCFMT_RIGHT
#define 	TVCFMT_FIXED			0x20000000			// Maske für Spalten fixieren
#define 	TVCFMT_MARK				0x10000000			// Maske für Spalten markieren


// Konstanten für ColumnAutoEdit
#define 	TVAE_NONE				(0<<TVAE_MODEPOS)	// Kein atomatisches Editieren
#define 	TVAE_EDIT				(1<<TVAE_MODEPOS)	// Atomatisches Editieren mit Edit-Fenster
#define 	TVAE_COMBO				(2<<TVAE_MODEPOS)	// Atomatisches Editieren mit ComboBox
#define 	TVAE_CBLIST				(3<<TVAE_MODEPOS)	// Atomatisches Editieren mit ComboListBox
#define 	TVAE_STEP				(4<<TVAE_MODEPOS)	// Einzelnes Weiterschalten mit Enter
#define 	TVAE_STEPED				(5<<TVAE_MODEPOS)	// Einzelnes Weiterschalten mit Enter
#define 	TVAE_CHECK				(6<<TVAE_MODEPOS)	// Atomatisches Editieren mit CheckBox
#define 	TVAE_CHECKED			(7<<TVAE_MODEPOS)	// Atomatisches Editieren mit CheckBox mit Edit
#define 	TVAE_NEXTLINE			0x0001				// Nach Enter in die nächste Zeile
#define 	TVAE_DBLCLICK			0x0002				// Editieren mit Doppelklick
#define 	TVAE_FULLWIDTH			0x0004				// Combobox über die volle Breite einblenden
#define 	TVAE_PTRLIST			0x0008				// Die Datenliste wird als Zeigerliste übergeben
#define 	TVAE_ONLYRETURN			0x0010				// Das Editeren kann nur mit Return begonnen werden
#define 	TVAE_STATEENABLE		0x0020				// Das Editeren kann mit dem 0x8000 State-Bit gesperrt werden
#define 	TVAE_ICONCLICK			0x0040				// Editieren mit einem Einfachlick auf das Icon
#define 	TVAE_DROPDOWN			0x0080				// Die DropDownListe der ComboBox aufklappen
#define 	TVAE_COL(c)				(((c)&0x3F)<<11)	// Ist die Spalte fürs automatische Editieren
#define 	TVAE_CHAR(c)			(((c)&0xFF)<<17)	// Ist das Trennzeichen für die Datenliste
#define 	TVAE_COUNT(c)			(((c)&0x7F)<<25)	// Bestimmt die Anzahl der Einträge in der Datenliste (0=auto)
#define 	TVAE_MODEMASK			(7<<TVAE_MODEPOS)	// Maske für die Modusbits
#define 	TVAE_MODEPOS			0x0008				// Maske für die Modusbits
#define 	TVIS_DISABLEBIT			0x8000				// Ist das State-Bit für's sperren der Auto-Edit-Option


// Konstanten für HitTest (flags)
#define 	TVHT_SUBTOCOL(u)		(((unsigned)u)>>24)	// Umwandeln von Spaltemasken zu Spaltenummern
#define 	TVHT_SUBMASK			0xFF000000			// Maske in der die Spalte gespeichert wird
#define 	TVHT_ONRIGHTSPACE		0x00800000			// Auf rechtem Rand nach den Exträgen
#define 	TVHT_ONSUBLABEL			0x00400000			// Koordinate ist auf dem Text eines Extraeintrages
#define 	TVHT_ONSUBICON			0x00200000			// Koordinate ist auf einem Extraeintrag
#define 	TVHT_ONSUBRIGHT			0x00100000			// Koordinate ist auf einem Extraeintrag rechts vom Text
#define 	TVHT_ONSUBITEM			(TVHT_ONSUBICON|TVHT_ONSUBLABEL)


// Konstanten für GetItemRect (TVM_GETITEMRECT)
#define 	TVIR_COLTOSUB(u)		((u)<<24)			// Splate angeben
#define 	TVIR_GETCOLUMN			0x00000080			// Nur Splate abfragen
#define 	TVIR_TEXT				0x00000001			// Nur den Textbereich abfragen


// Konstanten für SelectChilds (TVM_SELECTCHILDS)
#define 	TVIS_WITHCHILDS			0x00000001			// Auch Kinder auswählen
#define 	TVIS_DESELECT			0x00000002			// Einträge abwählen

// Konstanten für Optionen (TVM_GETSETOPTION)
#define 	TVOP_AUTOEXPANDOFF		0x00000001			// Icon Offset für TVS_EX_AUTOEXPANDICON
#define 	TVOP_WRITEOPTION		0x80000000			// Die Option auch schreiben


// Konstanten für EditLabel (LVM_EDITLABEL)
#define 	TVIR_EDITCOMBOCHAR(n)	(((n)&0xFF)<<8)		// Trennzeichen der Combobox-Einträge (nur für Notify-Nachricht)
#define 	TVIR_EDITCOMBODEL		0x00000080			// Löscht den Puffer für die Einträge (nur für Notify-Nachricht)
#define 	TVIR_EDITCOMBODOWN		0x10000000			// Die Combobox aufklappen (nur für Notify-Nachricht)
#define 	TVIR_EDITCOMBOBOX		0x20000000			// Statt dem Edit-Fenster eine ComboBox einblenden
#define 	TVIR_EDITCOMBOLIST		0x40000000			// Statt dem Edit-Fenster eine ComboBox nur mit Listenauswahl einblenden
#define 	TVIR_EDITFULL			0x80000000			// Das Edit-Fenster über die volle Breite einblenden
#define 	TVIR_EDITTEXT			0x00000001			// Das Edit-Fenster über den Text einblenden (nur für Notify-Nachricht)
#define 	TVIR_EDITCOL(u)			((u)&0xFF)			// Splate angeben
#define 	TVIR_SELALL				0x00000000			// Alles wählen
#define 	TVIR_SELAREA(a,b)		((0x0C0000|(a&0x1FF)|((b&0x1FF)<<9))<<8)	// Textbereich wählen
#define 	TVIR_SETCURSOR(a)		((0x080000|(a&0x3FFFF))<<8)					// Cursor auf Textstelle
#define 	TVIR_SETAT(a)			((0x040000|(a&0x3FFFF))<<8)					// Cursor auf Pixel-Offset


// Konstanten für uStyleEx
#define 	TVS_EX_HEADERCHGNOTIFY	0x00000800			// Nachrichten versenden wenn eine Spaltenbreite verändert wurde
#define 	TVS_EX_HEADERDRAGDROP	0x00001000			// Die Spalten ab 1 können mit Drag&Drop sortiert werden
#define 	TVS_EX_SINGLECHECKBOX	0x00002000			// Nur einfache Auswahl bei Checkboxen
#define 	TVS_EX_STEPOUT			0x00004000			// Mit Cursor Edit und Checkboxen verlassen
#define 	TVS_EX_BITCHECKBOX		0x00008000			// Bei Checkboxen nur das unterste Bit ändern
#define 	TVS_EX_ITEMLINES		0x00010000			// Um die Einträge Linien zeichnen
#define 	TVS_EX_ALTERNATECOLOR	0x00020000			// Die Farbe abwechselnd darstellen
#define 	TVS_EX_SUBSELECT		0x00040000			// Sub-Einträge seperat auswählen
#define 	TVS_EX_FULLROWMARK		0x00080000			// Die ganze Zeile markieren wenn selektiert
#define 	TVS_EX_TOOLTIPNOTIFY	0x00100000			// Spezielle Notify-Abfrage bei Tooltips
#define 	TVS_EX_AUTOEXPANDICON	0x00200000			// Automatisch das nächste Icon benutzen bei Expandet
#define 	TVS_EX_NOCHARSELCET		0x00400000			// Keine Auswahl über eine Texteingabe
#define 	TVS_EX_NOCOLUMNRESIZE	0x00800000			// Der User darf die Spaltenbreite nicht ändern
#define 	TVS_EX_HIDEHEADERS		0x01000000			// Ausblenden der Header-Leiste
#define 	TVS_EX_GRAYEDDISABLE	0x02000000			// Das Control grau zeichnen wenn es gesperrt ist
#define 	TVS_EX_FULLROWITEMS		0x04000000			// Einträge über die ganze Zeile zeichnen
#define 	TVS_EX_FIXEDCOLSIZE		0x08000000			// Gesamtbreite aller Splaten gleich belassen
#define 	TVS_EX_HOMEENDSELECT	0x10000000			// Mit Ctrl+Home/End das erste und letze Element wählen
#define 	TVS_EX_SHAREIMAGELISTS	0x20000000			// Image-Listen nicht löschen bei Fensterzerstörung
#define 	TVS_EX_EDITCLICK		0x40000000			// Mit einem Klick das gewählte Item berabreiten
#define 	TVS_EX_NOCURSORSET		0x80000000			// Bei VK_EDITCLK immer den gesammten Text wählen
#ifndef		TVS_EX_MULTISELECT
#define 	TVS_EX_MULTISELECT		0x00000002			// Eine Mehrfachauswahl erlauben
#endif
#ifndef		TVS_EX_AUTOHSCROLL
#define		TVS_EX_AUTOHSCROLL      0x00000020			// Horizontale Scrollbar ausblenden
#endif


// Konstanten für Notify-Nachrichten
#define		TVN_ITEMTOOLTIP			(TVN_FIRST-32)		// Notify Nachricht für Tooltip-Fenster
#define     TVN_CBSTATECHANGED      (TVN_FIRST-33)		// Notify Nachricht für geänderte Checkbox
#define		TVN_STEPSTATECHANGED	(TVN_FIRST-34)		// Notify Nachricht für geänderten Autoedit-Zustand
#define		TVN_STARTEDIT			(TVN_FIRST-35)		// Notify Nachricht Felder zu editieren
#define 	TVN_LBUTTONUP			(TVN_FIRST-36)		// Notify Nachricht wenn linke  Maustaste losgelassen wurde
#define 	TVN_RBUTTONUP			(TVN_FIRST-37)		// Notify Nachricht wenn rechte Maustaste losgelassen wurde
#define 	TVN_COLUMNCHANGED		(TVN_FIRST-38)		// Notify Nachricht wenn eine Spalte verändert wurde


// Konstanten für neue Nachrichten
#define 	TVM_GETHEADER			(TV_FIRST+128-1)
#define 	TVM_GETCOLUMNCOUNT		(TV_FIRST+128-2)
#define 	TVM_DELETECOLUMN		(TV_FIRST+128-3)
#define 	TVM_INSERTCOLUMN		(TV_FIRST+128-4-TV_UINICODE)
#define 	TVM_SELECTSUBITEM		(TV_FIRST+128-6)
#define 	TVM_SELECTDROP			(TV_FIRST+128-7)
#define 	TVM_SETITEMBKCOLOR		(TV_FIRST+128-8)
#define 	TVM_GETITEMBKCOLOR		(TV_FIRST+128-9)
#define 	TVM_SETITEMTEXTCOLOR	(TV_FIRST+128-10)
#define 	TVM_GETITEMTEXTCOLOR	(TV_FIRST+128-11)
#define 	TVM_GETITEMOFROW		(TV_FIRST+128-12)
#define 	TVM_GETROWCOUNT			(TV_FIRST+128-13)
#define 	TVM_GETROWOFITEM		(TV_FIRST+128-14)
#define 	TVM_SETCOLUMN			(TV_FIRST+128-15-TV_UINICODE)
#define 	TVM_GETCOLUMN			(TV_FIRST+128-17-TV_UINICODE)
#define 	TVM_SETCOLUMNWIDTH		(TV_FIRST+128-19)
#define 	TVM_GETCOLUMNWIDTH		(TV_FIRST+128-20)
#define 	TVM_SETUSERDATASIZE		(TV_FIRST+128-21)
#define 	TVM_GETUSERDATASIZE		(TV_FIRST+128-22)
#define 	TVM_GETUSERDATA			(TV_FIRST+128-23)
#define 	TVM_SORTCHILDRENEX		(TV_FIRST+128-24)
#define 	TVM_COLUMNAUTOEDIT		(TV_FIRST+128-25-TV_UINICODE)
#define 	TVM_COLUMNAUTOICON		(TV_FIRST+128-27)
#define 	TVM_GETCOUNTPERPAGE		(TV_FIRST+128-28)
#define 	TVM_FINDITEM			(TV_FIRST+128-29-TV_UINICODE)
#define 	TVM_SELECTCHILDS		(TV_FIRST+128-31)
#define 	TVM_GETSETOPTION		(TV_FIRST+128-32)
#define 	TVM_ISITEMVISIBLE		(TV_FIRST+128-33)
#define 	TVM_SETFOCUSITEM		(TV_FIRST+128-34)
#define 	TVM_GETCOLUMNORDERARRAY	(TV_FIRST+128-35)
#define 	TVM_SETCOLUMNORDERARRAY	(TV_FIRST+128-36)
#ifndef		TVM_GETITEMSTATE					  
#define 	TVM_GETITEMSTATE		(TV_FIRST+39) 
#endif											  
#ifndef		TVM_GETEXTENDEDSTYLE				  
#define 	TVM_GETEXTENDEDSTYLE	(TV_FIRST+45) 
#endif
#ifndef		TVM_SETEXTENDEDSTYLE
#define 	TVM_SETEXTENDEDSTYLE	(TV_FIRST+44)
#endif
#ifndef		TVM_GETLINECOLOR
#define 	TVM_GETLINECOLOR		(TV_FIRST+41)
#endif
#ifndef		TVM_SETLINECOLOR
#define 	TVM_SETLINECOLOR		(TV_FIRST+40)
#endif


#ifndef		TVNRET_DEFAULT
#define		TVNRET_DEFAULT			0
#endif
#ifndef		TVNRET_SKIPOLD
#define		TVNRET_SKIPOLD			1
#endif
#ifndef		TVNRET_SKIPNEW
#define		TVNRET_SKIPNEW			2
#endif

#define 	TreeList_DeleteChildItems(h,i)				((BOOL      )::SendMessage(h,TVM_DELETEITEM,0x88,(LPARAM)i))
#define 	TreeList_DeleteAllItems(h)					((BOOL      )::SendMessage(h,TVM_DELETEITEM,0,(LPARAM)TVI_ROOT))
#define		TreeList_DeleteItem(h,i)					((BOOL      )::SendMessage(h,TVM_DELETEITEM,0,(LPARAM)(HTREEITEM)(i)))
#define		TreeList_Expand(h,i,c)						((BOOL      )::SendMessage(h,TVM_EXPAND,(WPARAM)(c),(LPARAM)(HTREEITEM)(i)))
#define		TreeList_GetHeader(h)						((HWND      )::SendMessage(h,TVM_GETHEADER,0,0))
#define		TreeList_DeleteColumn(h,i)     				((BOOL      )::SendMessage(h,TVM_DELETECOLUMN,(WPARAM)(int)(i),0))
#define		TreeList_InsertColumn(h,i,p)				((INT       )::SendMessage(h,TVM_INSERTCOLUMN,(WPARAM)(int)(i),(LPARAM)(const TV_COLUMN*)(p)))
#define 	TreeList_GetColumnCount(h)					((INT       )::SendMessage(h,TVM_GETCOLUMNCOUNT,0,0))
#define 	TreeList_HitTest(h,p)						((HTREEITEM )::SendMessage(h,TVM_HITTEST,0,(LPARAM)(LPTV_HITTESTINFO)(p)))
#define 	TreeList_GetItemOfRow(h,r)					((HTREEITEM )::SendMessage(h,TVM_GETITEMOFROW,0,r))
#define 	TreeList_GetRowOfItem(h,i)					((INT       )::SendMessage(h,TVM_GETROWOFITEM,0,(LPARAM)(i)))
#define 	TreeList_GetRowCount(h)						((INT       )::SendMessage(h,TVM_GETROWCOUNT ,0,0))
#define 	TreeList_GetCountPerPage(h)					((INT       )::SendMessage(h,TVM_GETCOUNTPERPAGE ,0,0))
#define		TreeList_GetExtendedStyle(h)				((DWORD     )::SendMessage(h,TVM_GETEXTENDEDSTYLE,0,0))
#define		TreeList_SetExtendedStyle(h,d)	  			((DWORD     )::SendMessage(h,TVM_SETEXTENDEDSTYLE,0,d))
#define 	TreeList_SetExtendedStyleEx(h,d,m)			((DWORD     )::SendMessage(h,TVM_SETEXTENDEDSTYLE,m,d))
#define		TreeList_GetColor(h,i)						((COLORREF  )::SendMessage(h,TVM_GETBKCOLOR,(WPARAM)(i),0))
#define		TreeList_SetColor(h,i,c) 					((COLORREF  )::SendMessage(h,TVM_SETBKCOLOR,(WPARAM)(i),c))
#define		TreeList_GetItemBkColor(h,i,s)				((COLORREF  )::SendMessage(h,TVM_GETITEMBKCOLOR,(WPARAM)(i),s))
#define		TreeList_SetItemBkColor(h,i,s,c) 			((COLORREF  )::SendMessage(h,TVM_SETITEMBKCOLOR,((UINT)(i))|((s)<<24),c))
#define		TreeList_GetItemTextColor(h,i,s)			((COLORREF  )::SendMessage(h,TVM_GETITEMTEXTCOLOR,(WPARAM)(i),s))
#define		TreeList_SetItemTextColor(h,i,s,c) 			((COLORREF  )::SendMessage(h,TVM_SETITEMTEXTCOLOR,((UINT)(i))|((s)<<24),c))
#define 	TreeList_IsItemVisible(h,i,s)				((INT       )::SendMessage(h,TVM_ISITEMVISIBLE,s,(LPARAM)(HTREEITEM)(i)))
#define 	TreeList_EnsureVisible(h,i)					((BOOL      )::SendMessage(h,TVM_ENSUREVISIBLE,0,(LPARAM)(HTREEITEM)(i)))
#define 	TreeList_EnsureVisibleEx(h,i,s)				((BOOL      )::SendMessage(h,TVM_ENSUREVISIBLE,s,(LPARAM)(HTREEITEM)(i)))
#define 	TreeList_SelectDropTargetEx(h,i,s)			((BOOL      )::SendMessage(h,TVM_SELECTDROP,(WPARAM)(s),(LPARAM)(HTREEITEM)(i)))
#define 	TreeList_SelectSubItem(h,i,s)				((BOOL      )::SendMessage(h,TVM_SELECTSUBITEM,(WPARAM)(s),(LPARAM)(HTREEITEM)(i)))
#define 	TreeList_SelectChilds(h,i,s)				((BOOL      )::SendMessage(h,TVM_SELECTCHILDS,(WPARAM)(s),(LPARAM)(HTREEITEM)(i)))
#define 	TreeList_Select(h,i,c)						((BOOL      )::SendMessage(h,TVM_SELECTITEM,(WPARAM)(c),(LPARAM)(HTREEITEM)(i)))
#define		TreeList_EditLabel(h,i,s)				    ((HWND      )::SendMessage(h,TVM_EDITLABEL,s,(LPARAM)(HTREEITEM)(i)))
#define		TreeList_StartEdit(h,i,s)				    ((BOOL      )::SendMessage(h,TVM_EDITLABEL,TVIR_EDITCOL(s)|TVLE_DONOTIFY,(LPARAM)(HTREEITEM)(i)))
#define		TreeList_EndEditLabelNow(h,c)				((BOOL      )::SendMessage(h,TVM_ENDEDITLABELNOW,c,0))
#define		TreeList_GetItem(h,p)						((BOOL      )::SendMessage(h,TVM_GETITEM,0,(LPARAM)(TV_ITEM*)(p)))
#define		TreeList_GetCount()							((BOOL      )::SendMessage(h,TVM_GETCOUNT,0,0))
#define		TreeList_GetEditControl(h)					((HWND      )::SendMessage(h,TVM_GETEDITCONTROL,0,0))
#define		TreeList_GetImageList(h,i)					((HIMAGELIST)::SendMessage(h,TVM_GETIMAGELIST,i,0))
#define		TreeList_GetUserData(h,i)					((LPVOID    )::SendMessage(h,TVM_GETUSERDATA,0,(LPARAM)(HTREEITEM)(i)))
#define		TreeList_GetUserDataSize(h)					((INT       )::SendMessage(h,TVM_GETUSERDATASIZE,0,0))
#define		TreeList_SetUserDataSize(h,s)				((INT       )::SendMessage(h,TVM_SETUSERDATASIZE,0,s))
#define		TreeList_GetIndent							((UINT      )::SendMessage(h,TVM_GETINDENT,0,0))
#define		TreeList_GetVisibleCount					((UINT      )::SendMessage(h,TVM_GETVISIBLECOUNT,0,0))
#define		TreeList_InsertItem(h,p)					((HTREEITEM )::SendMessage(h,TVM_INSERTITEM,0,(LPARAM)(LPTV_INSERTSTRUCT)(p)))
#define		TreeList_FindItem(h,p,f)					((HTREEITEM )::SendMessage(h,TVM_FINDITEM ,(WPARAM)p,(LPARAM)f))
#define		TreeList_CreateDragImage(h,i)				((HIMAGELIST)::SendMessage(h,TVM_CREATEDRAGIMAGE, 0, (LPARAM)(HTREEITEM)(i)))
#define		TreeList_CreateDragImageEx(h,i,s)			((HIMAGELIST)::SendMessage(h,TVM_CREATEDRAGIMAGE, s, (LPARAM)(HTREEITEM)(i)))
#define		TreeList_SetImageList(h,l,i)				((HIMAGELIST)::SendMessage(h,TVM_SETIMAGELIST,i,(LPARAM)(UINT)(HIMAGELIST)(l)))
#define		TreeList_SetIndent(h,i)					    ((BOOL      )::SendMessage(h,TVM_SETINDENT,(WPARAM)(i),0))
#define		TreeList_SetItem(h,p)					    ((BOOL      )::SendMessage(h,TVM_SETITEM,0,(LPARAM)(const TV_ITEM*)(p)))
#define		TreeList_SortChildren(h,i,r)				((BOOL      )::SendMessage(h,TVM_SORTCHILDREN  ,(WPARAM)r,(LPARAM)(HTREEITEM)(i)))
#define		TreeList_SortChildrenCB(h,p,r)				((BOOL      )::SendMessage(h,TVM_SORTCHILDRENCB,(WPARAM)r,(LPARAM)(LPTV_SORTCB)(p)))
#define		TreeList_SortChildrenEX(h,p,r)				((BOOL      )::SendMessage(h,TVM_SORTCHILDRENEX,(WPARAM)r,(LPARAM)(LPTV_SORTEX)(p)))
#define		TreeList_SetColumn(h,i,p)					((BOOL      )::SendMessage(h,TVM_SETCOLUMN,i,(LPARAM)(const TV_COLUMN*)(p)))
#define		TreeList_GetColumn(h,i,p)					((BOOL      )::SendMessage(h,TVM_GETCOLUMN,i,(LPARAM)(TV_COLUMN*)(p)))
#define		TreeList_SetColumnWidth(h,i,w)				((BOOL      )::SendMessage(h,TVM_SETCOLUMNWIDTH,i,w))
#define		TreeList_GetColumnWidth(h,i)				((INT       )::SendMessage(h,TVM_GETCOLUMNWIDTH,i,0))
#define 	TreeList_SetColumnAutoEdit(h,i,f,p)			((BOOL      )::SendMessage(h,TVM_COLUMNAUTOEDIT,(WPARAM)((f)&~TVAE_COL(-1))|TVAE_COL(i),(LPARAM)(p)))
#define 	TreeList_SetColumnAutoIcon(h,i,n)			((BOOL      )::SendMessage(h,TVM_COLUMNAUTOICON,i,n))
#define 	TreeList_SetFocusItem(h,i,c)				((BOOL      )::SendMessage(h,TVM_SETFOCUSITEM,c,(LPARAM)(i)))
#define 	TreeList_SetOption(h,i,o)					((INT       )::SendMessage(h,TVM_GETSETOPTION,(i)|TVOP_WRITEOPTION,(LPARAM)(o)))
#define 	TreeList_GetOption(h,i)						((INT       )::SendMessage(h,TVM_GETSETOPTION,i,0))
#define 	TreeList_SetColumnOrderArray(h,n,p)			((BOOL      )::SendMessage(h,TVM_SETCOLUMNORDERARRAY,n,(LPARAM)(p)))
#define 	TreeList_GetColumnOrderArray(h,n,p)			((BOOL      )::SendMessage(h,TVM_GETCOLUMNORDERARRAY,n,(LPARAM)(p)))
#define		TreeList_GetStyle(h)						((DWORD     )::GetWindowLong(h,GWL_STYLE))
#define		TreeList_SetStyle(h,d)	  					((DWORD     )::SetWindowLong(h,GWL_STYLE,d))
#define 	TreeList_SetStyleEx(h,d,m)					((DWORD     )::SetWindowLong(h,GWL_STYLE,((d)&(m))|(::GetWindowLong(h,GWL_STYLE)&~(m))))
#define		TreeList_GetItemRect(h,i,s,p,c)			    (*(HTREEITEM*)p =(i),(BOOL)::SendMessage(h,TVM_GETITEMRECT,(WPARAM)((c)|(TVIR_COLTOSUB(s))),(LPARAM)(RECT*)(p)))


#define		TreeList_SelectItem(h,i)					TreeList_Select(h,i,TVGN_CARET)
#define 	TreeList_SelectDropTarget(h,i)				TreeList_Select(h,i,TVGN_DROPHILITE)
#define 	TreeList_SelectSetFirstVisible(h,i)			TreeList_Select(h,i,TVGN_FIRSTVISIBLE)

#define 	TreeList_GetNextItem(h,i,c)					TreeView_GetNextItem(h, i,     c)
#define		TreeList_GetChild(h,i)						TreeView_GetNextItem(h, i,     TVGN_CHILD)
#define 	TreeList_GetParent(h, i)         			TreeView_GetNextItem(h, i,     TVGN_PARENT)
#define 	TreeList_GetNextSibling(h,i)    			TreeView_GetNextItem(h, i,     TVGN_NEXT)
#define 	TreeList_GetPrevSibling(h,i)    			TreeView_GetNextItem(h, i,     TVGN_PREVIOUS)
#define 	TreeList_GetNextSelected(h,i)			    TreeView_GetNextItem(h, i,     TVGN_NEXTSELECTED)
#define		TreeList_GetNextSelectedChild(h,i)			TreeView_GetNextItem(h, i,	   TVGN_NEXTSELCHILD)
#define 	TreeList_GetNextVisible(h,i)    			TreeView_GetNextItem(h, i,     TVGN_NEXTVISIBLE)
#define 	TreeList_GetPrevVisible(h,i)    			TreeView_GetNextItem(h, i,     TVGN_PREVIOUSVISIBLE)
#define 	TreeList_GetLastChild(h,i)				    TreeView_GetNextItem(h, i,     TVGN_LASTCHILD)
#define 	TreeList_GetSelection(h)					TreeView_GetNextItem(h, NULL,  TVGN_CARET)
#define 	TreeList_GetDropHilight(h)					TreeView_GetNextItem(h, NULL,  TVGN_DROPHILITE)
#define 	TreeList_GetFirstVisible(h)				    TreeView_GetNextItem(h, NULL,  TVGN_FIRSTVISIBLE)
#define		TreeList_GetLastVisible(h)					TreeView_GetNextItem(h, NULL,  TVGN_LASTVISIBLE)
#define 	TreeList_GetRoot(h)							TreeView_GetNextItem(h, NULL,  TVGN_ROOT)
#define		TreeList_GetFocus(h)						TreeView_GetNextItem(h, NULL,  TVGN_FOCUS)
#define		TreeList_GetFocusColumn(h)					((int)TreeView_GetNextItem(h, NULL,  TVGN_FOCUSSUB))
#define		TreeList_GetSelectionColumn(h)				((int)TreeView_GetNextItem(h, NULL,  TVGN_CARETSUB))
#define		TreeList_GetDropHilightColumn(h)			((int)TreeView_GetNextItem(h, NULL,  TVGN_DROPHILITESUB))

int			TreeListRegister(HINSTANCE hInstance=0);
BOOL		TreeListUnregister(HINSTANCE hInstance=0);

#endif
