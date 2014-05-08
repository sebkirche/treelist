HA$PBExportHeader$vo_treelist.sru
forward
global type vo_treelist from userobject
end type
type lvcolumn from structure within vo_treelist
end type
end forward

type LVCOLUMN from structure
	ulong		mask
	long		fmt
	long		cx
	string		pszText
	long		cchTextMax
	long		iSubItem
	long		iImage
	long		iOrder
end type

global type vo_treelist from userobject
integer width = 247
integer height = 144
userobjects objecttype = externalvisual!
long backcolor = 67108864
string classname = "TreeList"
string libraryname = "treelist.dll"
string text = "none"
end type
global vo_treelist vo_treelist

type prototypes
Function uLong SendMessageColumn( uLong hwnd, uLong Msg, uLong wParam, Ref lvcolumn lvcolstruct ) Library "user32.dll" Alias For "SendMessageW"

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

constant long TVCF_TEXT = 4

constant long TV_FIRST = 4352 //0x1100
constant long TV_UINICODE = 1

constant long TVM_INSERTCOLUMN =		(TV_FIRST + 128 - 4 - TV_UINICODE)


end variables
forward prototypes
public function long insertcolumn (long ai_index, string as_text)
end prototypes

public function long insertcolumn (long ai_index, string as_text);
lvcolumn col

col.mask = 0;
col.mask = TVCF_TEXT;
col.pszText = as_text;
col.cchTextMax = 256;

return SendMessageColumn(handle(this), TVM_INSERTCOLUMN, ai_index, ref col);
//return 42

end function

on vo_treelist.create
end on

on vo_treelist.destroy
end on

