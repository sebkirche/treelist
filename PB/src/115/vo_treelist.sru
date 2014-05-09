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

global type vo_treelist from userobject
integer width = 247
integer height = 144
userobjects objecttype = externalvisual!
long backcolor = 67108864
string classname = "TreeList"
string libraryname = "treelist.dll"
string text = "none"
long style = 7
event wm_notify pbm_notify
event type long oncbstatechanged ( unsignedlong action,  unsignedlong itemhandle,  unsignedlong olditemstate,  unsignedlong newitemstate,  long ptdrag_x,  long ptdrag_y )
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
end prototypes

type variables
protected ulong hwnd
private:
	long il_curcol = 0

protected:

//Constants computed:
constant long SIZEOF_NMHDR=12
constant long SIZEOF_TVITEM=40
constant long SIZEOF_POINT=8
constant long SIZEOF_NMTREEVIEW=104
constant long SIZEOF_TVFIND=24
constant long SIZEOF_TVCOLUMN=44
constant long SIZEOF_TVINSERTSTRUCT=64

//Constants generated from conv_defs.pl ( TreeListWnd.h + commctrl.h )
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
constant ulong TV_FIRST = 4352
constant long TV_NOIMAGE = -2


end variables

forward prototypes
public function long addcolumn (string as_text)
public function long insertcolumn (long al_index, string as_text)
public function long insertitem (unsignedlong aul_parent, unsignedlong aul_flags, string as_text)
public function long insertitem (unsignedlong aul_parent, string as_text)
public function long setitemtext (unsignedlong aul_parent, long al_column, string as_text)
public function long expand (unsignedlong aul_parent)
public function long expandall (unsignedlong aul_parent)
public function unsignedlong finditem (treenavigation navigationcode, unsignedlong itemhandle)
public function unsignedlong finditem (treenavigation navigationcode, unsignedlong itemhandle, long al_column, string as_text, boolean ab_ignore_case)
public function boolean getitemcheckbox (unsignedlong handle)
public subroutine setitemcheckbox (unsignedlong handle, boolean ab_state)
protected function long getitem (unsignedlong handle, ref tv_item item)
protected function long setitem (unsignedlong handle, ref tv_item item)
public function long deleteitem (unsignedlong handle)
public function integer deleteitem (integer i)
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

public function long insertitem (unsignedlong aul_parent, unsignedlong aul_flags, string as_text);
/*
	Insert intem into tree
	
*/

TV_INSERTSTRUCT item

item.hParent			= aul_parent;
item.hInsertAfter		= TVI_LAST;
item.item.hItem		= 0;
item.item.pszText		= as_text
item.item.mask			= TVIF_TEXT;
item.item.iImage		= TV_NOIMAGE;
item.item.iSelectedImage = TV_NOIMAGE;
item.item.state			= 0;
item.item.stateMask		= 0;
item.item.lParam			= 0;

long l_ret
l_ret = SendMessageInsertItem(hwnd, TVM_INSERTITEM, 0, ref item);

return l_ret

end function

public function long insertitem (unsignedlong aul_parent, string as_text);
return insertitem(aul_parent, TVIF_TEXT, as_text)

end function

public function long setitemtext (unsignedlong aul_parent, long al_column, string as_text);tv_item itemdata
itemdata.mask = TVIF_SUBITEM + TVIF_TEXT
itemdata.hitem = aul_parent
itemdata.stateMask = 0
itemdata.psztext = as_text
itemdata.cchTextMax = 256
itemdata.cChildren = al_column

return SendMessageItem( hwnd , TVM_SETITEM, 0, itemdata)
end function

public function long expand (unsignedlong aul_parent);return Send(hwnd, TVM_EXPAND, TVE_EXPAND, aul_parent)
end function

public function long expandall (unsignedlong aul_parent);return Send(hwnd, TVM_EXPAND, &
	TVE_EXPANDRECURSIVE + TVE_EXPANDFORCE + TVE_ALLCHILDS + TVE_EXPAND, &
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
tv_item item
item.mask = TVIF_STATE
item.statemask = -1
r = getitem(handle, ref item)
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

protected function long getitem (unsignedlong handle, ref tv_item item);long l_ret
item.hitem = handle
l_ret = SendMessageItem(hwnd, TVM_GETITEM, 0, ref item);

return l_ret

end function

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

on vo_treelist.create
end on

on vo_treelist.destroy
end on

event constructor;hwnd = handle(this)
end event

