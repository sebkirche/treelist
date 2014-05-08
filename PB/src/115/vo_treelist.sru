HA$PBExportHeader$vo_treelist.sru
forward
global type vo_treelist from userobject
end type
type tv_column from structure within vo_treelist
end type
type tv_item from structure within vo_treelist
end type
type tv_insertstruct from structure within vo_treelist
end type
end forward

type TV_COLUMN from structure
	unsignedlong		mask
	long		fmt
	long		cx
	string		psztext
	long		cchtextmax
	long		isubitem
	long		iimage
	long		iorder
end type

type TV_ITEM from structure
	ulong		mask
	ulong		hItem
	ulong		state
	ulong		stateMask
	string		pszText
	ulong		cchTextMax
	ulong		iImage
	ulong		iSelectedImage
	ulong		cChildren
	ulong		lParam
end type

type tv_insertstruct from structure
	unsignedlong		hparent
	ulong		hinsertafter
	tv_item		item
end type

global type vo_treelist from userobject
integer width = 247
integer height = 144
userobjects objecttype = externalvisual!
long backcolor = 67108864
string classname = "TreeList"
string libraryname = "treelist.dll"
string text = "none"
long style = 7
end type
global vo_treelist vo_treelist

type prototypes
Function uLong SendMessageColumn( uLong hwnd, uLong Msg, uLong wParam, Ref TV_COLUMN lvcolstruct ) Library "user32.dll" Alias For "SendMessageW"
Function uLong SendMessageInsertItem( uLong hwnd, uLong Msg, uLong wParam, Ref TV_INSERTSTRUCT lvcolstruct ) Library "user32.dll" Alias For "SendMessageW"

end prototypes

type variables

/*
#define 	TVCF_FMT				LVCF_FMT			// Die Textausrichting einstellen
#define 	TVCF_IMAGE				LVCF_IMAGE			// Ein Icon der Spalte zu ortenen
#define 	TVCF_TEXT				LVCF_TEXT			// Den Text der Spalte setzen
#define 	TVCF_WIDTH				LVCF_WIDTH			// Fixe Breite festlegen
#define 	TVCF_VWIDTH				LVCF_SUBITEM		// Variable Breite festlegen
#define 	TVCF_MIN				LVCF_ORDER			// Minimale Breite festlegen
#define 	TVCF_MARK				0x80000000			// Soll die Spalte markiert werden
#define 	TVCF_FIXED				0x40000000			// Darf die Spaltenbreite ver$$HEX1$$e400$$ENDHEX$$ndert werden
#define 	TVCF_LASTSIZE			0x44332211			// Breite vor dem Fixieren wieder herstellen
*/

//from commctrl.h
constant long TVIF_TEXT = 1
constant long TVIF_IMAGE = 2
constant long TVIF_PARAM = 4
constant long TVIF_STATE = 8
constant long TVS_HASBUTTONS = 1
constant long TVS_HASLINES = 2
constant long TVS_LINESATROOT = 4
constant long TVS_EDITLABELS = 8
constant long TVS_DISABLEDRAGDROP = 16
constant long TVS_SHOWSELALWAYS = 32

constant long TV_NOIMAGE = -2
constant long TV_NOCOLOR = -1

constant long TVI_ROOT = -65536		//((HTREEITEM)0xFFFF0000)
constant long TVI_FIRST = -65535		//((HTREEITEM)0xFFFF0001)
constant long TVI_LAST = -65534		//((HTREEITEM)0xFFFF0002)
constant long TVI_SORT = -65533		//((HTREEITEM)0xFFFF0003)
constant long TVI_AFTER = -65531		//((HTREEITEM) 0xFFFF0005)
constant long TVI_BEFORE = -65530	//((HTREEITEM) 0xFFFF0006)
constant long TVI_SORTEX = -65529	//((HTREEITEM) 0xFFFF0007)

//#define		TVI_ROW(n)		        ((HTREEITEM)(0xFFE00000+(n)))

constant long TVCF_TEXT = 4

constant long TV_FIRST = 4352 //0x1100
constant long TV_UINICODE = 1

constant long TVM_INSERTITEM   = (TV_FIRST + 50)
constant long TVM_INSERTCOLUMN =	(TV_FIRST + 128 - 4 - TV_UINICODE)


private:
	long il_curcol = 0

end variables
forward prototypes
public function long addcolumn (string as_text)
public function long insertcolumn (long al_index, string as_text)
public function long insertitem (unsignedlong aul_parent, unsignedlong aul_flags, string as_text)
public function long insertitem (unsignedlong aul_parent, string as_text)
end prototypes

public function long addcolumn (string as_text);
/* 
	Add a new column at the end of existing columns
	
	as_text : the title of the column
	
*/

long l_ret

l_ret = InsertColumn(il_curcol, as_text)
//il_curcol++

return l_ret

end function

public function long insertcolumn (long al_index, string as_text);
/* 
	Insert a new column

	ai_index : 0 based index of the new column
	as_text  : the column title
*/

TV_COLUMN col

col.mask = 0;
col.mask = TVCF_TEXT;
col.pszText = as_text;
col.cchTextMax = 256;

long l_ret
l_ret = SendMessageColumn(handle(this), TVM_INSERTCOLUMN, al_index, ref col);
if l_ret >= 0 then il_curcol++

return l_ret

end function

public function long insertitem (unsignedlong aul_parent, unsignedlong aul_flags, string as_text);
/*
	Insert intem into tree
	
*/

TV_INSERTSTRUCT item

item.hParent			= aul_parent;
if aul_parent = 0 then
	item.hInsertAfter		= TVI_SORTEX;
else
	item.hInsertAfter		= TVI_LAST;
end if
item.item.hItem		= 0;//(HTREEITEM)pCmpProc;
item.item.pszText		= as_text
item.item.mask			= TVIF_TEXT;
item.item.iImage		= TV_NOIMAGE;
item.item.iSelectedImage = TV_NOIMAGE;
item.item.state			= 0;
item.item.stateMask		= 0;
item.item.lParam			= 0;

long l_ret
l_ret = SendMessageInsertItem(handle(this), TVM_INSERTITEM, 0, ref item);

return l_ret

end function

public function long insertitem (unsignedlong aul_parent, string as_text);
return insertitem(aul_parent, TVIF_TEXT, as_text)

end function

on vo_treelist.create
end on

on vo_treelist.destroy
end on

