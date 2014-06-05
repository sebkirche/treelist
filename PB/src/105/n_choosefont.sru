HA$PBExportHeader$n_choosefont.sru
forward
global type n_choosefont from nonvisualobject
end type
type choosefont from structure within n_choosefont
end type
type logfont from structure within n_choosefont
end type
end forward

type choosefont from structure
	long		lstructsize
	ulong		hwnd
	ulong		hdc
	long		lplogfont
	long		ipointsize
	long		flags
	long		rgbcolors
	long		lcustdata
	long		lpfnhook
	string		templatename
	ulong		hinstance
	string		lpszstyle
	integer		nfonttype
	integer		missingalignment
	long		nsizemin
	ulong		nsizelong
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
	byte		lfpitchandfamily
	character		lffacename[32]
end type

global type n_choosefont from nonvisualobject autoinstantiate
end type

type prototypes
Function boolean ChooseFont ( &
	Ref CHOOSEFONT lpcf &
	) Library "comdlg32.dll" Alias For "ChooseFontW" 

Subroutine CopyMemory ( &
	Ref LOGFONT Destination, &
	long Source, &
	long Length &
	) Library "kernel32.dll" Alias For "RtlMoveMemory"

Subroutine CopyMemory ( &
	long Destination, &
	LOGFONT Source, &
	long Length &
	) Library "kernel32.dll" Alias For "RtlMoveMemory"

Function ulong GlobalAlloc ( &
	ulong uFlags, &
	long dwBytes &
	) Library "kernel32.dll"

Function ulong GlobalLock ( &
	ulong hMem &
	) Library "kernel32.dll"

Function ulong GlobalUnlock ( &
	ulong hMem &
	) Library "kernel32.dll"

Function ulong GlobalFree ( &
	ulong hMem &
	) Library "kernel32.dll"

end prototypes

type variables

// ChooseFont standard dialog wrapper - Roland Smith 2009
//
// see http://www.topwizprogramming.com/freecode_choosefont.html

Integer iTextSize
Boolean iBold
Boolean iUnderline
Boolean iItalic
Boolean iStrikeout
String iFaceName
Long iTextColor
Long iWeight

end variables

forward prototypes
public function boolean of_choosefont (window aw_parent, string as_fontname)
end prototypes

public function boolean of_choosefont (window aw_parent, string as_fontname);Constant Integer CF_SCREENFONTS = 1
Constant Integer CF_INITTOLOGFONTSTRUCT = 64
Constant Integer CF_EFFECTS = 256
Constant Integer GMEM_MOVEABLE = 2
CHOOSEFONT lstr_choosefont
LOGFONT lstr_logfont
Long ll_LogFont

// we allocate a piece of memory with the size of the logfont structure
// and we lock it
ll_LogFont = GlobalAlloc(GMEM_MOVEABLE, 120)
If ll_LogFont = 0 Then Return False

ll_LogFont = GlobalLock(ll_LogFont)
If ll_LogFont = 0 Then Return False

/* initialise the logfont structure */

// default font
If as_fontname = "" Then
	lstr_logfont.lffacename = "Arial"
Else
	lstr_logfont.lffacename = as_fontname
End If
lstr_logfont.lfweight = 400
lstr_logfont.lfheight = 12

// copy the structure to the allocated piece in memory
CopyMemory(ll_LogFont, lstr_Logfont, 60)

// assign the pointer to the fontinfo in memory to the dialog font
lstr_ChooseFont.lplogfont = ll_LogFont

// initialise the structure further
lstr_ChooseFont.lstructsize = 60
lstr_ChooseFont.hwnd = Handle(aw_parent)
lstr_ChooseFont.flags = CF_SCREENFONTS+CF_INITTOLOGFONTSTRUCT+CF_EFFECTS

// call the dialog
If Not ChooseFont(lstr_ChooseFont) Then
	GlobalUnlock(ll_LogFont)
	GlobalFree(ll_LogFont)
	Return False
End If

// The memory piece now contains the selected log information
// Copy this information back to the structure so we can access it
CopyMemory(lstr_LogFont, lstr_ChooseFont.lplogfont, 120)

// release the used memory
GlobalUnlock(ll_LogFont) 
GlobalFree(ll_LogFont) 

// save the results in instance variables
iTextSize = (lstr_ChooseFont.iPointSize / 10) * -1
iWeight = lstr_LogFont.lfWeight
If iWeight = 700 Then
	iBold = True
Else
	iBold = False
End If
iFaceName = Trim(lstr_LogFont.lfFaceName)
iTextColor = lstr_ChooseFont.rgbColors

iUnderline = (lstr_LogFont.lfUnderline > 0)
iItalic = (lstr_LogFont.lfItalic > 0)
iStrikeout = (lstr_LogFont.lfStrikeout > 0)

Return True

end function

on n_choosefont.create
call super::create
TriggerEvent( this, "constructor" )
end on

on n_choosefont.destroy
TriggerEvent( this, "destructor" )
call super::destroy
end on

