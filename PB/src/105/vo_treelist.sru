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
type tv_find from structure within vo_treelist
end type
type nmtreeview from structure within vo_treelist
end type
type nmhdr from structure within vo_treelist
end type
type point from structure within vo_treelist
end type
type logfont from structure within vo_treelist
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

type tv_item from structure
	unsignedlong		mask
	unsignedlong		hitem
	unsignedlong		state
	unsignedlong		statemask
	string		psztext
	unsignedlong		cchtextmax
	unsignedlong		iimage
	unsignedlong		iselectedimage
	unsignedlong		cchildren
	unsignedlong		lparam
end type

type tv_insertstruct from structure
	unsignedlong		hparent
	ulong		hinsertafter
	tv_item		item
end type

type tv_find from structure
	ulong		uFlags
	ulong		uColumn
	ulong		uState
	ulong		uStateMask
	ulong		lParam
	string		pText
end type

type NMTREEVIEW from structure
	nmhdr		hdr
	ulong		action
	tv_item		itemOld
	tv_item		itemNew
	point		ptDrag
end type

type nmhdr from structure
	ulong		hwndFrom
	ulong		idFrom
	ulong		code
end type

type point from structure
	long		x
	long		y
end type

type logfont from structure
	long		lfheight
	long		lfwidth
	long		lfescapement
	long		lforientation
	long		lfweight
	byte		lfitalic
	byte		lfunderline
	byte		lfstrikeout
	byte		lfcharset
	byte		lfoutprecision
	byte		lfclipprecision
	byte		lfquality
	character		lfpitchandfamily
	character		lffacename[32]
end type

global type vo_treelist from userobject
integer width = 247
integer height = 144
userobjects objecttype = externalvisual!
long backcolor = 67108864
string classname = "TreeList"
string libraryname = "treelist.dll"
string text = "none"
event wm_notify pbm_notify
event type long oncbstatechanged ( unsignedlong action,  unsignedlong itemhandle,  unsignedlong olditemstate,  unsignedlong newitemstate,  long ptdrag_x,  long ptdrag_y )
event post_constructor ( )
end type
global vo_treelist vo_treelist

type prototypes
Function uLong SendMessageColumn( uLong _hwnd, uLong Msg, uLong wParam, Ref TV_COLUMN lvcolstruct ) Library "user32.dll" Alias For "SendMessageW"
Function uLong SendMessageInsertItem( uLong _hwnd, uLong Msg, uLong wParam, Ref TV_INSERTSTRUCT data ) Library "user32.dll" Alias For "SendMessageW"
Function uLong SendMessageItem( uLong _hwnd, uLong Msg, uLong wParam, Ref TV_item data ) Library "user32.dll" Alias For "SendMessageW"
Function uLong SendMessageFind( uLong _hwnd, uLong Msg, uLong wParam, Ref TV_FIND data ) Library "user32.dll" Alias For "SendMessageW"

subroutine CopyMemory(ulong Destination,ulong Source,ulong Length ) library "kernel32.dll" alias for "RtlMoveMemory"
subroutine CopyMemoryNMHDR(ref nmhdr Destination,ulong Source,ulong Length ) library "kernel32.dll" alias for "RtlMoveMemory"
subroutine CopyMemorynmtreeview(ref nmtreeview Destination,ulong Source,ulong Length ) library "kernel32.dll" alias for "RtlMoveMemory"

Function ULONG GetWindowLong(Ulong hWn, long nIndex) library "user32.dll" alias for "GetWindowLongW"
Function ULONG SetWindowLong(Ulong hWn, long nIndex, ULONG dwNewLong) library "user32.dll" alias for "SetWindowLongW"

Function ulong CreateFont(long nHeight,ulong nWidth,ulong nEscapement,ulong nOrientation,ulong fnWeight,boolean fdwItalic,boolean fdwUnderline,boolean fdwStrikeOut,ulong fdwCharSet,ulong fdwOutputPrecision,ulong fdwClipPrecision,ulong fdwQuality,ulong dwPitchAndFamily,ref string lpszFace) LIBRARY "gdi32.dll" ALIAS FOR "CreateFontW"  
Function uLong CreateFontIndirect( Ref Logfont lplf ) Library 'gdi32' alias for "CreateFontIndirectW"
Function Boolean DeleteObject( uLong hObject ) Library "gdi32"
function long MulDiv(long nNumber, long nNumerator, int nDenominator) library "kernel32.dll"
Function ulong GetDeviceCaps(ulong hdc,ulong nIndex) library "gdi32.dll"
Function ULong GetDC(ULong handle) Library "User32.DLL"
Function ULong ReleaseDC(ULong handle, ULong hDC) Library "User32.DLL"


end prototypes

type variables
public:
//styles
boolean IBS_HASBUTTONS = true	//adds a button to the left of each parent item
boolean IBS_HASLINES = true		//lines linking child items to their corresponding parent items
boolean IBS_LINESATROOT = true	//lines linking child items to the root of the hierarchy
boolean IBS_SHOWSELALWAYS		//a selected item remains selected when the tree-view control loses focus
boolean IBS_NOTOOLTIPS			//uses no tooltips
//TODO boolean IBS_INFOTIP
boolean IBS_CHECKBOXES			//checkboxes before the icons
boolean IBS_TRACKSELECT			//hot tracking
boolean IBS_SINGLEEXPAND			//expande selected item, collapse unselected item
boolean IBS_FULLROWSELECT		//full-row selection in the tree view. The entire row of the selected item is highlighted, and clicking anywhere on an item's row will cause it to be selected.
										//This style cannot be used in conjunction with the TVS_HASLINES style
boolean IBS_NOSCROLL
boolean IBS_NOHSCROLL
boolean IBS_NONEVENHEIGHT		//The height of the items can be set to an odd height with the TVM_SETITEMHEIGHT message. 
										//By default, the height of items must be an even value
boolean IBS_EDITLABELS			//allows the user to edit the labels of tree view items
boolean IBS_DISABLEDRAGDROP		//do not send TVN_BEGINDRAG notification messages
boolean IBS_RTLREADING

//extended styles
boolean IBS_EX_ALTERNATECOLOR
boolean IBS_EX_AUTOEXPANDICON
boolean IBS_EX_AUTOHSCROLL
boolean IBS_EX_BITCHECKBOX
boolean IBS_EX_EDITCLICK
boolean IBS_EX_FIXEDCOLSIZE
boolean IBS_EX_FULLROWITEMS
boolean IBS_EX_FULLROWMARK
boolean IBS_EX_GRAYEDDISABLE
boolean IBS_EX_HEADERCHGNOTIFY
boolean IBS_EX_HEADERDRAGDROP
boolean IBS_EX_HIDEHEADERS
boolean IBS_EX_HOMEENDSELECT
boolean IBS_EX_ITEMLINES
boolean IBS_EX_MULTISELECT
boolean IBS_EX_NOCHARSELCET
boolean IBS_EX_NOCOLUMNRESIZE
boolean IBS_EX_NOCURSORSET
boolean IBS_EX_SHAREIMAGELISTS
boolean IBS_EX_SINGLECHECKBOX
boolean IBS_EX_STEPOUT
boolean IBS_EX_SUBSELECT
boolean IBS_EX_TOOLTIPNOTIFY

constant long GWL_STYLE = -16
constant long GWL_EXSTYLE = -20
constant unsignedlong WS_CHILD = 1073741824
constant unsignedlong WS_VISIBLE = 268435456
constant long CS_ENABLE = 1

//Constants computed:
constant long SIZEOF_NMHDR=12
constant long SIZEOF_TVITEM=40
constant long SIZEOF_POINT=8
constant long SIZEOF_NMTREEVIEW=104
constant long SIZEOF_TVFIND=24
constant long SIZEOF_TVCOLUMN=44
constant long SIZEOF_TVINSERTSTRUCT=64

//Constants generated from conv_defs.pl ( TreeListWnd.h + commctrl.h )
constant ulong TVCFMT_BITMAP_ON_RIGHT = 4096
constant ulong TVCFMT_CENTER = 2
constant ulong TVCFMT_COL_HAS_IMAGES = 32768
constant ulong TVCFMT_FIXED = 536870912
constant ulong TVCFMT_IMAGE = 2048
constant ulong TVCFMT_LEFT = 0
constant ulong TVCFMT_MARK = 268435456
constant ulong TVCFMT_RIGHT = 1

constant ulong TVCF_FIXED = 1073741824
constant ulong TVCF_FMT = 1
constant ulong TVCF_IMAGE = 16
constant ulong TVCF_LASTSIZE = 1144201745
constant ulong TVCF_MARK = 2147483648
constant ulong TVCF_MIN = 32
constant ulong TVCF_TEXT = 4
constant ulong TVCF_VWIDTH = 8
constant ulong TVCF_WIDTH = 2
constant ulong TVE_ALLCHILDS = 268435456
constant ulong TVE_COLLAPSE = 1
constant ulong TVE_COLLAPSERESET = 32768
constant ulong TVE_EXPAND = 2
constant ulong TVE_EXPANDFORCE = 1073741824
constant ulong TVE_EXPANDNEXT = 536870912
constant ulong TVE_EXPANDPARTIAL = 16384
constant ulong TVE_EXPANDRECURSIVE = 2147483648
constant ulong TVE_ONLYCHILDS = 8
constant ulong TVE_TOGGLE = 3
constant ulong TVGN_CARET = 9
constant ulong TVGN_CARETSUB = 13
constant ulong TVGN_CHILD = 4
constant ulong TVGN_DROPHILITE = 8
constant ulong TVGN_DROPHILITESUB = 12
constant ulong TVGN_FIRSTVISIBLE = 5
constant ulong TVGN_FOCUS = 15
constant ulong TVGN_FOCUSSUB = 16
constant ulong TVGN_LASTCHILD = 18
constant ulong TVGN_LASTVISIBLE = 10
constant ulong TVGN_NEXT = 1
constant ulong TVGN_NEXTITEM = 19
constant ulong TVGN_NEXTSELCHILD = 17
constant ulong TVGN_NEXTSELECTED = 14
constant ulong TVGN_NEXTVISIBLE = 6
constant ulong TVGN_PARENT = 3
constant ulong TVGN_PREVIOUS = 2
constant ulong TVGN_PREVIOUSVISIBLE = 7
constant ulong TVGN_ROOT = 0
constant ulong TVIF_CANCELED = 16777216
constant ulong TVIF_CASE = 134217728
constant ulong TVIF_CHILD = 33554432
constant ulong TVIF_CHILDREN = 64
constant ulong TVIF_DI_SETITEM = 4096
constant ulong TVIF_HANDLE = 16
constant ulong TVIF_IMAGE = 2
constant ulong TVIF_INTEGRAL = 128
constant ulong TVIF_NEXT = 67108864
constant ulong TVIF_ONLYFOCUS = 8388608
constant ulong TVIF_PARAM = 4
constant ulong TVIF_RETURNEXIT = 268435456
constant ulong TVIF_SELECTEDIMAGE = 32
constant ulong TVIF_STATE = 8
constant ulong TVIF_SUBITEM = 32768
constant ulong TVIF_SUBNUMBER = 16384
constant ulong TVIF_TEXT = 1
constant ulong TVIF_TEXTCHANGED = 536870912
constant ulong TVIF_TEXTPTR = 2147483648
constant ulong TVIF_TOOLTIPTIME = 1073741824
constant ulong TVI_AFTER = 4294901765
constant ulong TVI_BEFORE = 4294901766
constant long TVI_FIRST = -65535
constant long TVI_LAST = -65534
constant long TVI_ROOT = -65536
constant long TVI_SORT = -65533
constant ulong TVI_SORTEX = 4294901767
constant long TVM_COLUMNAUTOEDIT = 4454
constant long TVM_COLUMNAUTOICON = 4453
constant ulong TVM_CREATEDRAGIMAGE = 4370
constant long TVM_DELETECOLUMN = 4477
constant ulong TVM_DELETEITEM = 4353
constant ulong TVM_EDITLABEL = 4417
constant ulong TVM_EDITLABELA = 4366
constant ulong TVM_EDITLABELW = 4417
constant ulong TVM_ENDEDITLABELNOW = 4374
constant ulong TVM_ENSUREVISIBLE = 4372
constant ulong TVM_EXPAND = 4354
constant long TVM_FINDITEM = 4450
constant ulong TVM_GETBKCOLOR = 4383
constant long TVM_GETCOLUMN = 4462
constant long TVM_GETCOLUMNCOUNT = 4478
constant long TVM_GETCOLUMNORDERARRAY = 4445
constant long TVM_GETCOLUMNWIDTH = 4460
constant ulong TVM_GETCOUNT = 4357
constant long TVM_GETCOUNTPERPAGE = 4452
constant ulong TVM_GETEDITCONTROL = 4367
constant ulong TVM_GETEXTENDEDSTYLE = 4397
constant long TVM_GETHEADER = 4479
constant ulong TVM_GETIMAGELIST = 4360
constant ulong TVM_GETINDENT = 4358
constant ulong TVM_GETINSERTMARKCOLOR = 4390
constant ulong TVM_GETISEARCHSTRING = 4416
constant ulong TVM_GETISEARCHSTRINGA = 4375
constant ulong TVM_GETISEARCHSTRINGW = 4416
constant ulong TVM_GETITEM = 4414
constant ulong TVM_GETITEMA = 4364
constant long TVM_GETITEMBKCOLOR = 4471
constant ulong TVM_GETITEMHEIGHT = 4380
constant long TVM_GETITEMOFROW = 4468
constant ulong TVM_GETITEMRECT = 4356
constant ulong TVM_GETITEMSTATE = 4391
constant long TVM_GETITEMTEXTCOLOR = 4469
constant ulong TVM_GETITEMW = 4414
constant ulong TVM_GETLINECOLOR = 4393
constant ulong TVM_GETNEXTITEM = 4362
constant long TVM_GETROWCOUNT = 4467
constant long TVM_GETROWOFITEM = 4466
constant ulong TVM_GETSCROLLTIME = 4386
constant long TVM_GETSETOPTION = 4448
constant ulong TVM_GETTEXTCOLOR = 4384
constant ulong TVM_GETTOOLTIPS = 4377
constant ulong TVM_GETUNICODEFORMAT = 8198
constant long TVM_GETUSERDATA = 4457
constant long TVM_GETUSERDATASIZE = 4458
constant ulong TVM_GETVISIBLECOUNT = 4368
constant ulong TVM_HITTEST = 4369
constant long TVM_INSERTCOLUMN = 4475
constant ulong TVM_INSERTITEM = 4402
constant ulong TVM_INSERTITEMA = 4352
constant ulong TVM_INSERTITEMW = 4402
constant long TVM_ISITEMVISIBLE = 4447
constant ulong TVM_MAPACCIDTOHTREEITEM = 4394
constant ulong TVM_MAPHTREEITEMTOACCID = 4395
constant long TVM_SELECTCHILDS = 4449
constant long TVM_SELECTDROP = 4473
constant ulong TVM_SELECTITEM = 4363
constant long TVM_SELECTSUBITEM = 4474
constant ulong TVM_SETBKCOLOR = 4381
constant long TVM_SETCOLUMN = 4464
constant long TVM_SETCOLUMNORDERARRAY = 4444
constant long TVM_SETCOLUMNWIDTH = 4461
constant ulong TVM_SETEXTENDEDSTYLE = 4396
constant long TVM_SETFOCUSITEM = 4446
constant ulong TVM_SETIMAGELIST = 4361
constant ulong TVM_SETINDENT = 4359
constant ulong TVM_SETINSERTMARK = 4378
constant ulong TVM_SETINSERTMARKCOLOR = 4389
constant ulong TVM_SETITEM = 4415
constant ulong TVM_SETITEMA = 4365
constant long TVM_SETITEMBKCOLOR = 4472
constant ulong TVM_SETITEMHEIGHT = 4379
constant long TVM_SETITEMTEXTCOLOR = 4470
constant ulong TVM_SETITEMW = 4415
constant ulong TVM_SETLINECOLOR = 4392
constant ulong TVM_SETSCROLLTIME = 4385
constant ulong TVM_SETTEXTCOLOR = 4382
constant ulong TVM_SETTOOLTIPS = 4376
constant ulong TVM_SETUNICODEFORMAT = 8197
constant long TVM_SETUSERDATASIZE = 4459
constant ulong TVM_SORTCHILDREN = 4371
constant ulong TVM_SORTCHILDRENCB = 4373
constant long TVM_SORTCHILDRENEX = 4456
constant ulong TVN_BEGINDRAG = -456
constant long TVN_BEGINDRAGA = -407
constant long TVN_BEGINDRAGW = -456
constant ulong TVN_BEGINLABELEDIT = -459
constant long TVN_BEGINLABELEDITA = -410
constant long TVN_BEGINLABELEDITW = -459
constant ulong TVN_BEGINRDRAG = -457
constant long TVN_BEGINRDRAGA = -408
constant long TVN_BEGINRDRAGW = -457
constant long TVN_CBSTATECHANGED = -433
constant long TVN_COLUMNCHANGED = -438
constant ulong TVN_COLUMNCLICK = -322
constant ulong TVN_COLUMNDBLCLICK = -323
constant ulong TVN_DELETEITEM = -458
constant long TVN_DELETEITEMA = -409
constant long TVN_DELETEITEMW = -458
constant ulong TVN_ENDLABELEDIT = -460
constant long TVN_ENDLABELEDITA = -411
constant long TVN_ENDLABELEDITW = -460
constant long TVN_FIRST = -400
constant ulong TVN_GETDISPINFO = -452
constant long TVN_GETDISPINFOA = -403
constant long TVN_GETDISPINFOW = -452
constant ulong TVN_GETINFOTIP = -414
constant long TVN_GETINFOTIPA = -413
constant long TVN_GETINFOTIPW = -414
constant ulong TVN_ITEMEXPANDED = -455
constant long TVN_ITEMEXPANDEDA = -406
constant long TVN_ITEMEXPANDEDW = -455
constant ulong TVN_ITEMEXPANDING = -454
constant long TVN_ITEMEXPANDINGA = -405
constant long TVN_ITEMEXPANDINGW = -454
constant long TVN_ITEMTOOLTIP = -432
constant long TVN_KEYDOWN = -412
constant long TVN_LAST = -499
constant long TVN_LBUTTONUP = -436
constant long TVN_RBUTTONUP = -437
constant ulong TVN_SELCHANGED = -451
constant long TVN_SELCHANGEDA = -402
constant long TVN_SELCHANGEDW = -451
constant ulong TVN_SELCHANGING = -450
constant long TVN_SELCHANGINGA = -401
constant long TVN_SELCHANGINGW = -450
constant ulong TVN_SETDISPINFO = -453
constant long TVN_SETDISPINFOA = -404
constant long TVN_SETDISPINFOW = -453
constant long TVN_SINGLEEXPAND = -415
constant long TVN_STARTEDIT = -435
constant long TVN_STEPSTATECHANGED = -434
constant ulong TVS_CHECKBOXES = 256
constant ulong TVS_DISABLEDRAGDROP = 16
constant ulong TVS_EDITLABELS = 8
constant ulong TVS_EX_ALTERNATECOLOR = 131072
constant ulong TVS_EX_AUTOEXPANDICON = 2097152
constant ulong TVS_EX_AUTOHSCROLL = 32
constant ulong TVS_EX_BITCHECKBOX = 32768
constant ulong TVS_EX_EDITCLICK = 1073741824
constant ulong TVS_EX_FIXEDCOLSIZE = 134217728
constant ulong TVS_EX_FULLROWITEMS = 67108864
constant ulong TVS_EX_FULLROWMARK = 524288
constant ulong TVS_EX_GRAYEDDISABLE = 33554432
constant ulong TVS_EX_HEADERCHGNOTIFY = 2048
constant ulong TVS_EX_HEADERDRAGDROP = 4096
constant ulong TVS_EX_HIDEHEADERS = 16777216
constant ulong TVS_EX_HOMEENDSELECT = 268435456
constant ulong TVS_EX_ITEMLINES = 65536
constant ulong TVS_EX_MULTISELECT = 2
constant ulong TVS_EX_NOCHARSELCET = 4194304
constant ulong TVS_EX_NOCOLUMNRESIZE = 8388608
constant ulong TVS_EX_NOCURSORSET = 2147483648
constant ulong TVS_EX_SHAREIMAGELISTS = 536870912
constant ulong TVS_EX_SINGLECHECKBOX = 8192
constant ulong TVS_EX_STEPOUT = 16384
constant ulong TVS_EX_SUBSELECT = 262144
constant ulong TVS_EX_TOOLTIPNOTIFY = 1048576
constant ulong TVS_FULLROWSELECT = 4096
constant ulong TVS_HASBUTTONS = 1
constant ulong TVS_HASLINES = 2
constant ulong TVS_INFOTIP = 2048
constant ulong TVS_LINESATROOT = 4
constant ulong TVS_NOHSCROLL = 32768
constant ulong TVS_NONEVENHEIGHT = 16384
constant ulong TVS_NOSCROLL = 8192
constant ulong TVS_NOTOOLTIPS = 128
constant ulong TVS_RTLREADING = 64
constant ulong TVS_SHOWSELALWAYS = 32
constant ulong TVS_SINGLEEXPAND = 1024
constant ulong TVS_TRACKSELECT = 512
constant ulong TV_FIRST = 4352
constant long TV_NOIMAGE = -2

protected:
ulong hwnd
long il_curcol = 0

private:
ulong il_custom_font = 0

constant long WM_SETFONT = 48
constant integer FW_NORMAL     = 400
constant integer FW_BOLD       = 700
constant ulong LOGPIXELSX = 88  //Number of pixels per logical inch along the screen width.
constant ulong DEFAULT_CHARSET     = 1   //(x01)

end variables

forward prototypes
public function long addcolumn (string as_text)
public function long insertcolumn (long al_index, string as_text)
public function long setitemtext (unsignedlong aul_parent, long al_column, string as_text)
public function long expand (unsignedlong aul_parent)
public function long expandall (unsignedlong aul_parent)
public function unsignedlong finditem (treenavigation navigationcode, unsignedlong itemhandle)
public function unsignedlong finditem (treenavigation navigationcode, unsignedlong itemhandle, long al_column, string as_text, boolean ab_ignore_case)
public function boolean getitemcheckbox (unsignedlong handle)
public subroutine setitemcheckbox (unsignedlong handle, boolean ab_state)
protected function long setitem (unsignedlong handle, ref tv_item item)
public function long deleteitem (unsignedlong handle)
public function integer deleteitem (integer i)
public function long insertitemlast (unsignedlong aul_parent, string as_text)
public function long insertitem (unsignedlong aul_parent, unsignedlong aul_posflags, unsignedlong aul_flags, string as_text, long al_image, long al_selectedimage)
public function long insertitemlast (unsignedlong aul_parent, string as_text, long al_image)
protected function boolean getitem (unsignedlong handle, ref tv_item item)
public function unsignedlong getnextitem (unsignedlong handle, unsignedlong which)
public function unsignedlong getnextsiblingitem (unsignedlong handle)
public function ulong getprevsiblingitem (unsignedlong handle)
public function unsignedlong getchild (unsignedlong handle)
protected function boolean getitem (ref tv_item item)
public function string getlabel (unsignedlong handle)
public function integer reset ()
private function unsignedlong _createfont (string as_facename, integer ai_height, integer ai_weight, boolean ab_italic, boolean ab_underline, boolean ab_strikeout)
public subroutine setfont (string as_facename, integer ai_height, integer ai_weight, boolean ab_italic, boolean ab_underline, boolean ab_strikeout)
public subroutine setfont (unsignedlong hfont)
public function long deletecolumn (long al_column_id)
public function long showcolumn (long al_column_id)
public function long hidecolumn (long al_column_id)
public function long setitembackcolor (long handle, long al_column_id, long al_color)
public function ulong getstyle ()
public function unsignedlong setstyle (unsignedlong aul_style)
public function unsignedlong getexstyle ()
public function unsignedlong setexstyle (unsignedlong aul_style)
public function unsignedlong updateexstyles ()
public function unsignedlong updatestyles ()
end prototypes

event wm_notify;if lparam > 0 then
	nmhdr header
	CopyMemoryNMHDR( ref header, lparam, SIZEOF_NMHDR )
	choose case header.code 
		case TVN_CBSTATECHANGED
			nmtreeview msgdata
			CopyMemorynmtreeview( ref msgdata, lparam, SIZEOF_NMTREEVIEW)
			return event oncbstatechanged( &
									msgdata.action, &
									msgdata.itemnew.hitem, &
									msgdata.itemold.state, &
									msgdata.itemnew.state, &
									msgdata.ptdrag.x, &
									msgdata.ptdrag.y)
		//TODO:
		case TVN_DELETEITEM
		case TVN_COLUMNCHANGED
		case TVN_BEGINLABELEDIT
		case TVN_ENDLABELEDIT
		case TVN_SETDISPINFO
		case TVN_KEYDOWN
		case TVN_STARTEDIT
		case TVN_STEPSTATECHANGED
		case TVN_BEGINDRAG
		case TVN_ITEMTOOLTIP
		case TVN_GETINFOTIP
		case TVN_ITEMEXPANDING
		case TVN_ITEMEXPANDED
		case TVN_SELCHANGED
		case TVN_SELCHANGING
		case TVN_SINGLEEXPAND
		case TVN_LBUTTONUP
		case TVN_RBUTTONUP
//		case NM_RETURN
//		case NM_SETFOCUS
//		case NM_KILLFOCUS
//		case NM_DBLCLK
//		case NM_RCLICK
//		case NM_RDBLCLK
		case TVN_LAST
		case TVN_FIRST
		case TVN_COLUMNDBLCLICK
		case TVN_COLUMNCLICK
		case TVN_BEGINRDRAG
		case else
	end choose	
end if
return 0

end event

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
l_ret = SendMessageColumn(hwnd, TVM_INSERTCOLUMN, al_index, ref col);
if l_ret >= 0 then il_curcol++

return l_ret

end function

public function long setitemtext (unsignedlong aul_parent, long al_column, string as_text);
tv_item itemdata

if isnull(as_text) then as_text = ""

itemdata.mask = TVIF_TEXT
if al_column > 0 then itemdata.mask += TVIF_SUBITEM 
itemdata.hitem = aul_parent
itemdata.stateMask = 0
itemdata.psztext = as_text
itemdata.cchTextMax = 256
itemdata.cChildren = al_column

return SendMessageItem( hwnd , TVM_SETITEM, 0, itemdata)

end function

public function long expand (unsignedlong aul_parent);return Send(hwnd, TVM_EXPAND, TVE_EXPAND, aul_parent)
end function

public function long expandall (unsignedlong aul_parent);if aul_parent = TVI_ROOT then
	ulong lul_handle
	lul_handle = getchild( TVI_ROOT )
	do while lul_handle > 0
		expandall( lul_handle )
		lul_handle = getNextsiblingitem( lul_handle )
	loop
	return 0
end if

return Send(hwnd, TVM_EXPAND, TVE_ALLCHILDS + TVE_EXPAND, &
	aul_parent)
end function

public function unsignedlong finditem (treenavigation navigationcode, unsignedlong itemhandle);ulong uFlags
choose case navigationcode
	case RootTreeItem!				; uFlags = TVGN_ROOT
	case NextTreeItem! 				; uFlags = TVGN_NEXT
	case PreviousTreeItem!			; uFlags = TVGN_PREVIOUS
	case ParentTreeItem!				; uFlags = TVGN_PARENT
	case ChildTreeItem!				; uFlags = TVGN_CHILD
	case FirstVisibleTreeItem!		; uFlags = TVGN_FIRSTVISIBLE
	case NextVisibleTreeItem!		; uFlags = TVGN_NEXTVISIBLE
	case PreviousVisibleTreeItem!	; uFlags = TVGN_PREVIOUSVISIBLE
	case CurrentTreeItem!			; uFlags = TVGN_FOCUS
	case DropHighlightTreeItem!	; uFlags = TVGN_DROPHILITE
	case else
//		some missing nagivationcode from pb:
//		uFlags =	TVGN_LASTCHILD, TVGN_NEXTSELECTED, TVGN_NEXTSELCHILD
//					TVGN_NEXTITEM, TVGN_LASTVISIBLE, TVGN_DROPHILITESUB,
//					TVGN_CARET, TVGN_CARETSUB, TVGN_FOCUSSUB
		
end choose

return send( hwnd, TVM_GETNEXTITEM, uFlags, itemhandle )
end function

public function unsignedlong finditem (treenavigation navigationcode, unsignedlong itemhandle, long al_column, string as_text, boolean ab_ignore_case);tv_find data
data.uFlags = TVIF_TEXT
if ab_ignore_case then
	data.uFlags += TVIF_CASE
end if
if navigationcode = ChildTreeItem! then
	data.uFlags += TVIF_CHILD
elseif navigationcode = NextTreeItem! then
	data.uFlags += TVIF_NEXT
end if
data.uColumn = al_column
return sendmessagefind( hwnd, TVM_FINDITEM, itemhandle, data)
end function

public function boolean getitemcheckbox (unsignedlong handle);ulong r

r = send( hwnd, TVM_GETITEMSTATE, handle, 0)
n_cst_numerical ln_bitops
r = ln_bitops.of_bitwiseand( r, 8192)
return r>0 //= 0x2000
end function

public subroutine setitemcheckbox (unsignedlong handle, boolean ab_state);ulong r
boolean lb
tv_item item
item.mask = TVIF_STATE
item.statemask = -1
lb = getitem(handle, ref item)
r = item.state
n_cst_numerical ln_bitops
r = ln_bitops.of_bitwiseand( r, ln_bitops.of_bitwisenot( 8192 + 4096 ) )
if ab_state then
	r = ln_bitops.of_bitwiseor( r, 8192)
else
	r = ln_bitops.of_bitwiseor( r, 4096 )
end if
item.state = r
item.mask = TVIF_STATE
item.statemask = -1
setitem( handle, ref item )

end subroutine

protected function long setitem (unsignedlong handle, ref tv_item item);long l_ret
item.hitem = handle
l_ret = SendMessageItem(hwnd, TVM_SETITEM, 0, ref item);

return l_ret

end function

public function long deleteitem (unsignedlong handle);constant int mode = 1	// or 0x88 => 136
//Doc de TreeListDeleteItem : 
// 0 = supprimer l'entr$$HEX1$$e900$$ENDHEX$$e et pas Redessiner Supprimer 
// 1 = entr$$HEX1$$e900$$ENDHEX$$e et de redessiner 
// 2 = uniquement les entr$$HEX1$$e900$$ENDHEX$$es de l'enfant $$HEX2$$e0002000$$ENDHEX$$supprimer et redessiner 
// Retourne 1 si l'entr$$HEX1$$e900$$ENDHEX$$e a $$HEX1$$e900$$ENDHEX$$t$$HEX2$$e9002000$$ENDHEX$$supprim$$HEX1$$e900$$ENDHEX$$e.

//Mais le message TVM_DELETEITEM est trait$$HEX2$$e9002000$$ENDHEX$$tel que :
//lRet  = TreeListDeleteItem(pData, U(lParam), (U(wParam) == 0x88) ? 2 : 1);
// => Donc le mode 0 n'est jamais disponible depuis le sendmessage
return send( hwnd, TVM_DELETEITEM, mode, handle )
end function

public function integer deleteitem (integer i);//to be sure an user will not call it with an integer...
return deleteitem(long(i))
end function

public function long insertitemlast (unsignedlong aul_parent, string as_text);
return insertitem(aul_parent, TVI_LAST, TVIF_TEXT, as_text, TV_NOIMAGE, TV_NOIMAGE)

end function

public function long insertitem (unsignedlong aul_parent, unsignedlong aul_posflags, unsignedlong aul_flags, string as_text, long al_image, long al_selectedimage);
/*
	Insert intem into tree
	
*/

TV_INSERTSTRUCT item

item.hParent			= aul_parent;
item.hInsertAfter		= aul_posflags;
item.item.hItem		= 0;
item.item.pszText		= as_text
item.item.cchTextMax = 256 //!!!!!!!!!!!!!!!!!!!
item.item.mask			= aul_flags;
item.item.iImage		= al_image;
item.item.iSelectedImage = al_selectedimage;
item.item.state			= 0;
item.item.stateMask		= 0;
item.item.lParam			= 0;

long l_ret
l_ret = SendMessageInsertItem(hwnd, TVM_INSERTITEM, 0, ref item);

return l_ret

end function

public function long insertitemlast (unsignedlong aul_parent, string as_text, long al_image);
return insertitem(aul_parent, TVI_LAST, TVIF_TEXT, as_text, al_image, al_image)

end function

protected function boolean getitem (unsignedlong handle, ref tv_item item);
item.hitem = handle
return getitem(item)


end function

public function unsignedlong getnextitem (unsignedlong handle, unsignedlong which);
/* Return the next given item after the given handle or 0

TVGN_CARET  Retrieves the currently selected item.  
TVGN_CARETSUB  Retrieves the currently selected column.  
TVGN_CHILD  Retrieves the first child item.  
TVGN_DROPHILITE  Retrieves the item that is the target of a drag-and-drop operation.  
TVGN_DROPHILITESUB  Retrieves the column that is the target of a drag-and-drop operation.  
TVGN_FIRSTVISIBLE  Retrieves the first visible item.  
TVGN_FOCUS  Retrieves the item which has the focus. If the window not have the focus, the first selected item is retrieved.  
TVGN_FOCUSSUB  Retrieves the column which has the focus. If the window not have the focus, the selected column is retrieved.  
TVGN_LASTCHILD  Retrieves the last child item.  
TVGN_LASTVISIBLE  Retrieves the last expanded item in the tree. This does not retrieve the last item visible in the tree-view window.  
TVGN_NEXT  Retrieves the next sibling item.  
TVGN_NEXTITEM  Retrieves the next item. This is at first the child, then the sibling or at last the first sibling of the parent item.    
TVGN_NEXTSELCHILD  Retrieves the next selected child item (see TVS_EX_MULTISELECT).  
TVGN_NEXTSELECTED  Retrieves the next selected item (see TVS_EX_MULTISELECT).  
TVGN_NEXTVISIBLE  Retrieves the next visible item that follows the specified item.  
TVGN_PARENT  Retrieves the parent of the specified item.  
TVGN_PREVIOUS  Retrieves the previous sibling item.  
TVGN_PREVIOUSVISIBLE    Retrieves the first visible item that precedes the specified item.  
TVGN_ROOT  Retrieves the first child item of the root item.

*/

ulong r

r = send( hwnd, TVM_GETNEXTITEM, which, handle)

return r

end function

public function unsignedlong getnextsiblingitem (unsignedlong handle);
ulong r

r = send( hwnd, TVM_GETNEXTITEM, TVGN_NEXT, handle)

return r

end function

public function ulong getprevsiblingitem (unsignedlong handle);
ulong r

r = send( hwnd, TVM_GETNEXTITEM, TVGN_PREVIOUS, handle)

return r

end function

public function unsignedlong getchild (unsignedlong handle);
ulong r

r = send( hwnd, TVM_GETNEXTITEM, TVGN_CHILD, handle)

return r

end function

protected function boolean getitem (ref tv_item item);
long l_ret
l_ret = SendMessageItem(hwnd, TVM_GETITEM, 0, ref item);

return l_ret = 1


end function

public function string getlabel (unsignedlong handle);
tv_item item
item.hitem = handle
item.mask = TVIF_TEXT
item.psztext = space(256)
item.cchTextMax = 256 //FIXME => constante de l'objet !!!!!!!

if getitem(ref item) then
	return item.psztext
else
	return ""
end if	

end function

public function integer reset ();DeleteItem( TVI_ROOT )
return 0
end function

private function unsignedlong _createfont (string as_facename, integer ai_height, integer ai_weight, boolean ab_italic, boolean ab_underline, boolean ab_strikeout);uLong	lul_Font
logfont lf

lf.lfFaceName = as_FaceName
lf.lfWeight= ai_Weight
lf.lfHeight= ai_Height

lf.lfPitchAndFamily = '1'
lf.lfClipPrecision = 2
lf.lfOutPrecision = 1
lf.lfQuality = 1

If ab_Italic Then lf.lfItalic = 255
If ab_UnderLine Then lf.lfUnderline = 255
If ab_StrikeOut Then lf.lfStrikeOut = 255

lul_Font = CreateFontIndirect(lf)

Return lul_Font

end function

public subroutine setfont (string as_facename, integer ai_height, integer ai_weight, boolean ab_italic, boolean ab_underline, boolean ab_strikeout);
ulong ll_hdc
integer li_height

ll_hdc = GetDC(hwnd)
li_height = -MulDiv(ai_height, GetDeviceCaps(ll_hdc, LOGPIXELSX), 72)
if il_custom_font <> 0 then DeleteObject(il_custom_font)
//il_custom_font = _CreateFont( as_FaceName, li_height, ai_Weight, ab_Italic, ab_Underline, ab_StrikeOut )
il_custom_font = CreateFont(li_height, 0, 0, 0, ai_Weight, ab_italic, ab_underline, ab_strikeout, 0, DEFAULT_CHARSET, 0, 0, 0, as_facename)

If il_custom_font > 0 Then
	SetFont( il_custom_font )
	//no! do that if needed later when recreating a new font or destroying the item
	//DeleteObject( lul_Font )
End If
ReleaseDC(hwnd, ll_hdc)

end subroutine

public subroutine setfont (unsignedlong hfont);
Send( hwnd, WM_SETFONT, hFont, 1 )

end subroutine

public function long deletecolumn (long al_column_id);
/* 
	Delete a column by it's id
	
	al_column_id : the id of the column to delete
	
*/

long l_ret

l_ret = Send( hwnd, TVM_DELETECOLUMN, al_column_id, 0 )
return l_ret

end function

public function long showcolumn (long al_column_id);TV_COLUMN col

col.fmt = 0
col.mask = TVCF_FIXED + TVCF_WIDTH
col.cx = TVCF_LASTSIZE

long l_ret
l_ret = SendMessageColumn(hwnd, TVM_SETCOLUMN, al_column_id, ref col)

return l_ret

end function

public function long hidecolumn (long al_column_id);TV_COLUMN col

col.fmt = TVCFMT_FIXED
col.mask = TVCF_FIXED + TVCF_WIDTH
col.cx = 0

long l_ret
l_ret = SendMessageColumn(hwnd, TVM_SETCOLUMN, al_column_id, ref col)

return l_ret

end function

public function long setitembackcolor (long handle, long al_column_id, long al_color);return send(hwnd,TVM_SETITEMBKCOLOR, handle + al_column_id * 16777216,al_color)
end function

public function ulong getstyle ();
return GetWindowLong(hWnd, GWL_STYLE)

end function

public function unsignedlong setstyle (unsignedlong aul_style);

return SetWindowLong(hWnd, GWL_STYLE, aul_style)

end function

public function unsignedlong getexstyle ();
return Send(hwnd, TVM_GETEXTENDEDSTYLE, 0, 0)

end function

public function unsignedlong setexstyle (unsignedlong aul_style);
return Send(hwnd, TVM_SETEXTENDEDSTYLE, -1, aul_style)

end function

public function unsignedlong updateexstyles ();
long lul_exstyle = 0

//lul_exstyle = Send( hwnd, TVM_GETEXTENDEDSTYLE, 0, 0)
if IBS_EX_ALTERNATECOLOR then lul_exstyle += TVS_EX_ALTERNATECOLOR
if IBS_EX_AUTOEXPANDICON then lul_exstyle += TVS_EX_AUTOEXPANDICON
if IBS_EX_AUTOHSCROLL then lul_exstyle += TVS_EX_AUTOHSCROLL
if IBS_EX_BITCHECKBOX then lul_exstyle += TVS_EX_BITCHECKBOX
if IBS_EX_EDITCLICK then lul_exstyle += TVS_EX_EDITCLICK
if IBS_EX_FIXEDCOLSIZE then lul_exstyle += TVS_EX_FIXEDCOLSIZE
if IBS_EX_FULLROWITEMS then lul_exstyle += TVS_EX_FULLROWITEMS
if IBS_EX_FULLROWMARK then lul_exstyle += TVS_EX_FULLROWMARK
if IBS_EX_GRAYEDDISABLE then lul_exstyle += TVS_EX_GRAYEDDISABLE
if IBS_EX_HEADERCHGNOTIFY then lul_exstyle += TVS_EX_HEADERCHGNOTIFY
if IBS_EX_HEADERDRAGDROP then lul_exstyle += TVS_EX_HEADERDRAGDROP
if IBS_EX_HIDEHEADERS then lul_exstyle += TVS_EX_HIDEHEADERS
if IBS_EX_HOMEENDSELECT then lul_exstyle += TVS_EX_HOMEENDSELECT
if IBS_EX_ITEMLINES then lul_exstyle += TVS_EX_ITEMLINES
if IBS_EX_MULTISELECT then lul_exstyle += TVS_EX_MULTISELECT
if IBS_EX_NOCHARSELCET then lul_exstyle += TVS_EX_NOCHARSELCET
if IBS_EX_NOCOLUMNRESIZE then lul_exstyle += TVS_EX_NOCOLUMNRESIZE
if IBS_EX_NOCURSORSET then lul_exstyle += TVS_EX_NOCURSORSET
if IBS_EX_SHAREIMAGELISTS then lul_exstyle += TVS_EX_SHAREIMAGELISTS
if IBS_EX_SINGLECHECKBOX then lul_exstyle += TVS_EX_SINGLECHECKBOX
if IBS_EX_STEPOUT then lul_exstyle += TVS_EX_STEPOUT
if IBS_EX_SUBSELECT then lul_exstyle += TVS_EX_SUBSELECT
if IBS_EX_TOOLTIPNOTIFY then lul_exstyle += TVS_EX_TOOLTIPNOTIFY

return setexstyle(lul_exstyle)

end function

public function unsignedlong updatestyles ();
ulong lul_style = 0

lul_style = ws_child

if IBS_HASBUTTONS then lul_style += tvs_hasbuttons
if IBS_HASLINES then lul_style += tvs_haslines
if IBS_LINESATROOT then lul_style += tvs_linesatroot
if IBS_SHOWSELALWAYS then lul_style += tvs_showselalways
if IBS_NOTOOLTIPS then lul_style += tvs_notooltips
if IBS_CHECKBOXES then lul_style += tvs_checkboxes
if IBS_TRACKSELECT then lul_style += tvs_trackselect
if IBS_SINGLEEXPAND then lul_style += tvs_singleexpand
if IBS_FULLROWSELECT and not IBS_HASLINES then lul_style += tvs_fullrowselect
if IBS_NOSCROLL then lul_style += tvs_noscroll
if IBS_NOHSCROLL then lul_style += tvs_nohscroll
if IBS_NONEVENHEIGHT then lul_style += tvs_nonevenheight
if IBS_EDITLABELS then lul_style += tvs_editlabels
if IBS_DISABLEDRAGDROP then lul_style += tvs_disabledragdrop
if IBS_RTLREADING then lul_style += tvs_rtlreading

if visible then lul_style += ws_visible
//if enabled then lul_style += CS_ENABLE
//lul_style += ws_child

return setstyle(lul_style)

end function

on vo_treelist.create
end on

on vo_treelist.destroy
end on

event constructor;

hwnd = handle(this)

//unsignedlong lul_style
//lul_style = style
//lul_style = getstyle( )
//TODO? if IBS_INFOTIP

//if visible then lul_style += 1//ws_visible
//if enabled then lul_style += cs_enable
//style = lul_style
//setstyle(lul_style)
updatestyles()
updateexstyles()

post event post_constructor( )

end event

event destructor;
//clean the custom font if it was allocated
if il_custom_font <> 0 then DeleteObject(il_custom_font)

end event

