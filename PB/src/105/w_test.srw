HA$PBExportHeader$w_test.srw
forward
global type w_test from window
end type
type cbx_ex_headerdragdrop from checkbox within w_test
end type
type cbx_ex_stepout from checkbox within w_test
end type
type cbx_ex_editclick from checkbox within w_test
end type
type cbx_ex_fixedcolsize from checkbox within w_test
end type
type cbx_ex_fullrowitems from checkbox within w_test
end type
type cbx_ex_grayeddisable from checkbox within w_test
end type
type cbx_ex_hideheaders from checkbox within w_test
end type
type cbx_ex_nocharselcet from checkbox within w_test
end type
type cbx_ex_nocolumnresize from checkbox within w_test
end type
type cbx_ex_bitcheckbox from checkbox within w_test
end type
type cbx_ex_tooltipnotify from checkbox within w_test
end type
type cbx_ex_autohscroll from checkbox within w_test
end type
type cbx_ex_multiselect from checkbox within w_test
end type
type cbx_ex_fullrowmark from checkbox within w_test
end type
type cbx_ex_subselect from checkbox within w_test
end type
type cbx_ex_alternatecolor from checkbox within w_test
end type
type cbx_ex_itemlines from checkbox within w_test
end type
type cbx_rtlreading from checkbox within w_test
end type
type cbx_disabledragdrop from checkbox within w_test
end type
type cbx_nohscroll from checkbox within w_test
end type
type cbx_editlabels from checkbox within w_test
end type
type cbx_nonevenheight from checkbox within w_test
end type
type cbx_noscroll from checkbox within w_test
end type
type cbx_fullrowselect from checkbox within w_test
end type
type cbx_singleexpand from checkbox within w_test
end type
type cbx_trackselect from checkbox within w_test
end type
type cbx_checkboxes from checkbox within w_test
end type
type cbx_notooltips from checkbox within w_test
end type
type cbx_showselalways from checkbox within w_test
end type
type cbx_linesatroot from checkbox within w_test
end type
type cbx_haslines from checkbox within w_test
end type
type cbx_hasbuttons from checkbox within w_test
end type
type cb_4 from commandbutton within w_test
end type
type cb_3 from commandbutton within w_test
end type
type cb_2 from commandbutton within w_test
end type
type cb_1 from commandbutton within w_test
end type
type uo_tree from vo_treelist within w_test
end type
type gb_styles from groupbox within w_test
end type
type gb_exstyles from groupbox within w_test
end type
end forward

global type w_test from window
integer width = 3456
integer height = 2500
boolean titlebar = true
string title = "Untitled"
boolean controlmenu = true
boolean minbox = true
boolean maxbox = true
boolean resizable = true
long backcolor = 67108864
string icon = "AppIcon!"
boolean center = true
event onnotify pbm_notify
cbx_ex_headerdragdrop cbx_ex_headerdragdrop
cbx_ex_stepout cbx_ex_stepout
cbx_ex_editclick cbx_ex_editclick
cbx_ex_fixedcolsize cbx_ex_fixedcolsize
cbx_ex_fullrowitems cbx_ex_fullrowitems
cbx_ex_grayeddisable cbx_ex_grayeddisable
cbx_ex_hideheaders cbx_ex_hideheaders
cbx_ex_nocharselcet cbx_ex_nocharselcet
cbx_ex_nocolumnresize cbx_ex_nocolumnresize
cbx_ex_bitcheckbox cbx_ex_bitcheckbox
cbx_ex_tooltipnotify cbx_ex_tooltipnotify
cbx_ex_autohscroll cbx_ex_autohscroll
cbx_ex_multiselect cbx_ex_multiselect
cbx_ex_fullrowmark cbx_ex_fullrowmark
cbx_ex_subselect cbx_ex_subselect
cbx_ex_alternatecolor cbx_ex_alternatecolor
cbx_ex_itemlines cbx_ex_itemlines
cbx_rtlreading cbx_rtlreading
cbx_disabledragdrop cbx_disabledragdrop
cbx_nohscroll cbx_nohscroll
cbx_editlabels cbx_editlabels
cbx_nonevenheight cbx_nonevenheight
cbx_noscroll cbx_noscroll
cbx_fullrowselect cbx_fullrowselect
cbx_singleexpand cbx_singleexpand
cbx_trackselect cbx_trackselect
cbx_checkboxes cbx_checkboxes
cbx_notooltips cbx_notooltips
cbx_showselalways cbx_showselalways
cbx_linesatroot cbx_linesatroot
cbx_haslines cbx_haslines
cbx_hasbuttons cbx_hasbuttons
cb_4 cb_4
cb_3 cb_3
cb_2 cb_2
cb_1 cb_1
uo_tree uo_tree
gb_styles gb_styles
gb_exstyles gb_exstyles
end type
global w_test w_test

type variables

long il_deltaheight, il_deltawidth

end variables

forward prototypes
public subroutine updatestyle ()
end prototypes

event onnotify;if isvalid(uo_tree) and not isnull(uo_tree) then
	return uo_tree.event WM_NOTIFY(wparam,lparam)
end if
end event

public subroutine updatestyle ();
uo_tree.ibs_hasbuttons = cbx_hasbuttons.checked
uo_tree.ibs_haslines = cbx_haslines.checked
uo_tree.ibs_linesatroot = cbx_linesatroot.checked
uo_tree.ibs_showselalways = cbx_showselalways.checked
uo_tree.ibs_notooltips = cbx_notooltips.checked
uo_tree.ibs_checkboxes = cbx_checkboxes.checked
uo_tree.ibs_trackselect = cbx_trackselect.checked
uo_tree.ibs_singleexpand = cbx_singleexpand.checked
uo_tree.ibs_fullrowselect = cbx_singleexpand.checked
uo_tree.ibs_noscroll = cbx_noscroll.checked
uo_tree.ibs_nohscroll = cbx_nohscroll.checked
uo_tree.ibs_nonevenheight = cbx_nonevenheight.checked
uo_tree.ibs_editlabels = cbx_editlabels.checked
uo_tree.ibs_disabledragdrop = cbx_disabledragdrop.checked
uo_tree.ibs_rtlreading = cbx_rtlreading.checked
uo_tree.updatestyles()

uo_tree.ibs_ex_itemlines = cbx_ex_itemlines.checked
uo_tree.ibs_ex_alternatecolor = cbx_ex_alternatecolor.checked
uo_tree.ibs_ex_subselect = cbx_ex_subselect.checked
uo_tree.ibs_ex_fullrowmark = cbx_ex_fullrowmark.checked
uo_tree.ibs_ex_multiselect = cbx_ex_multiselect.checked
uo_tree.ibs_ex_autohscroll = cbx_ex_autohscroll.checked
uo_tree.ibs_ex_tooltipnotify = cbx_ex_tooltipnotify.checked
uo_tree.ibs_ex_bitcheckbox = cbx_ex_bitcheckbox.checked
uo_tree.ibs_ex_nocolumnresize = cbx_ex_nocolumnresize.checked
uo_tree.ibs_ex_nocharselcet = cbx_ex_nocharselcet.checked
uo_tree.ibs_ex_hideheaders = cbx_ex_hideheaders.checked
uo_tree.ibs_ex_grayeddisable = cbx_ex_grayeddisable.checked
uo_tree.ibs_ex_fullrowitems = cbx_ex_fullrowitems.checked
uo_tree.ibs_ex_fixedcolsize = cbx_ex_fixedcolsize.checked
uo_tree.ibs_ex_editclick = cbx_ex_editclick.checked
uo_tree.ibs_ex_stepout = cbx_ex_stepout.checked
uo_tree.ibs_ex_headerdragdrop = cbx_ex_headerdragdrop.checked
uo_tree.updateexstyles()
end subroutine

on w_test.create
this.cbx_ex_headerdragdrop=create cbx_ex_headerdragdrop
this.cbx_ex_stepout=create cbx_ex_stepout
this.cbx_ex_editclick=create cbx_ex_editclick
this.cbx_ex_fixedcolsize=create cbx_ex_fixedcolsize
this.cbx_ex_fullrowitems=create cbx_ex_fullrowitems
this.cbx_ex_grayeddisable=create cbx_ex_grayeddisable
this.cbx_ex_hideheaders=create cbx_ex_hideheaders
this.cbx_ex_nocharselcet=create cbx_ex_nocharselcet
this.cbx_ex_nocolumnresize=create cbx_ex_nocolumnresize
this.cbx_ex_bitcheckbox=create cbx_ex_bitcheckbox
this.cbx_ex_tooltipnotify=create cbx_ex_tooltipnotify
this.cbx_ex_autohscroll=create cbx_ex_autohscroll
this.cbx_ex_multiselect=create cbx_ex_multiselect
this.cbx_ex_fullrowmark=create cbx_ex_fullrowmark
this.cbx_ex_subselect=create cbx_ex_subselect
this.cbx_ex_alternatecolor=create cbx_ex_alternatecolor
this.cbx_ex_itemlines=create cbx_ex_itemlines
this.cbx_rtlreading=create cbx_rtlreading
this.cbx_disabledragdrop=create cbx_disabledragdrop
this.cbx_nohscroll=create cbx_nohscroll
this.cbx_editlabels=create cbx_editlabels
this.cbx_nonevenheight=create cbx_nonevenheight
this.cbx_noscroll=create cbx_noscroll
this.cbx_fullrowselect=create cbx_fullrowselect
this.cbx_singleexpand=create cbx_singleexpand
this.cbx_trackselect=create cbx_trackselect
this.cbx_checkboxes=create cbx_checkboxes
this.cbx_notooltips=create cbx_notooltips
this.cbx_showselalways=create cbx_showselalways
this.cbx_linesatroot=create cbx_linesatroot
this.cbx_haslines=create cbx_haslines
this.cbx_hasbuttons=create cbx_hasbuttons
this.cb_4=create cb_4
this.cb_3=create cb_3
this.cb_2=create cb_2
this.cb_1=create cb_1
this.uo_tree=create uo_tree
this.gb_styles=create gb_styles
this.gb_exstyles=create gb_exstyles
this.Control[]={this.cbx_ex_headerdragdrop,&
this.cbx_ex_stepout,&
this.cbx_ex_editclick,&
this.cbx_ex_fixedcolsize,&
this.cbx_ex_fullrowitems,&
this.cbx_ex_grayeddisable,&
this.cbx_ex_hideheaders,&
this.cbx_ex_nocharselcet,&
this.cbx_ex_nocolumnresize,&
this.cbx_ex_bitcheckbox,&
this.cbx_ex_tooltipnotify,&
this.cbx_ex_autohscroll,&
this.cbx_ex_multiselect,&
this.cbx_ex_fullrowmark,&
this.cbx_ex_subselect,&
this.cbx_ex_alternatecolor,&
this.cbx_ex_itemlines,&
this.cbx_rtlreading,&
this.cbx_disabledragdrop,&
this.cbx_nohscroll,&
this.cbx_editlabels,&
this.cbx_nonevenheight,&
this.cbx_noscroll,&
this.cbx_fullrowselect,&
this.cbx_singleexpand,&
this.cbx_trackselect,&
this.cbx_checkboxes,&
this.cbx_notooltips,&
this.cbx_showselalways,&
this.cbx_linesatroot,&
this.cbx_haslines,&
this.cbx_hasbuttons,&
this.cb_4,&
this.cb_3,&
this.cb_2,&
this.cb_1,&
this.uo_tree,&
this.gb_styles,&
this.gb_exstyles}
end on

on w_test.destroy
destroy(this.cbx_ex_headerdragdrop)
destroy(this.cbx_ex_stepout)
destroy(this.cbx_ex_editclick)
destroy(this.cbx_ex_fixedcolsize)
destroy(this.cbx_ex_fullrowitems)
destroy(this.cbx_ex_grayeddisable)
destroy(this.cbx_ex_hideheaders)
destroy(this.cbx_ex_nocharselcet)
destroy(this.cbx_ex_nocolumnresize)
destroy(this.cbx_ex_bitcheckbox)
destroy(this.cbx_ex_tooltipnotify)
destroy(this.cbx_ex_autohscroll)
destroy(this.cbx_ex_multiselect)
destroy(this.cbx_ex_fullrowmark)
destroy(this.cbx_ex_subselect)
destroy(this.cbx_ex_alternatecolor)
destroy(this.cbx_ex_itemlines)
destroy(this.cbx_rtlreading)
destroy(this.cbx_disabledragdrop)
destroy(this.cbx_nohscroll)
destroy(this.cbx_editlabels)
destroy(this.cbx_nonevenheight)
destroy(this.cbx_noscroll)
destroy(this.cbx_fullrowselect)
destroy(this.cbx_singleexpand)
destroy(this.cbx_trackselect)
destroy(this.cbx_checkboxes)
destroy(this.cbx_notooltips)
destroy(this.cbx_showselalways)
destroy(this.cbx_linesatroot)
destroy(this.cbx_haslines)
destroy(this.cbx_hasbuttons)
destroy(this.cb_4)
destroy(this.cb_3)
destroy(this.cb_2)
destroy(this.cb_1)
destroy(this.uo_tree)
destroy(this.gb_styles)
destroy(this.gb_exstyles)
end on

event open;il_deltaheight = height - uo_tree.height //- uo_tree.y
il_deltawidth = width - uo_tree.width //+ pixelstounits(100, XPixelsToUnits!)

updatestyle()

uo_tree.insertcolumn(0, "col 1")
uo_tree.insertcolumn(1,"col 2")
uo_tree.addcolumn("col 3")

ulong r, i1, i2, i3, i4, i5
i1 = uo_tree.insertitemlast(0,"foo")
r = uo_tree.setitemtext(i1, 1, string(i1))
r = uo_tree.setitemtext(i1, 2, "data3")
i2 = uo_tree.insertitemlast(1,"bar")
r = uo_tree.setitemtext(i2, 1, string(i2))
i3 = uo_tree.insertitemlast(2,"baz")
r = uo_tree.setitemtext(i3, 1, string(i3))
i4 = uo_tree.insertitemlast(1,"asdf")
r = uo_tree.setitemtext(i4, 1, string(i4))
i5 = uo_tree.insertitemlast(0,"row2-crash")	//make ite crash!
r = uo_tree.setitemtext(i5, 1, string(i5))
i5 = uo_tree.insertitemlast(-1,"row2")
r = uo_tree.setitemtext(i5, 1, string(i5))

//uo_tree.expand( i1 )
//uo_tree.expand( i2 )
//uo_tree.expand( i3 )
//uo_tree.expand( i4 )
//uo_tree.expand( 0 )
uo_tree.expandall(i1)

uo_tree.setfont( "Times New Roman", 12, 400, false, false, false)

end event

event resize;
//uo_tree.width = newwidth - uo_tree.x - pixelstounits(8, XPixelsToUnits!)
uo_tree.width = max(newwidth - il_deltawidth, pixelstounits(50, XPixelsToUnits!))
uo_tree.height = max(newheight - il_deltaheight, pixelstounits(50, YPixelsToUnits!))

end event

type cbx_ex_headerdragdrop from checkbox within w_test
integer x = 69
integer y = 2208
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_HEADERDRAGDROP"
boolean checked = true
end type

event clicked;
updatestyle( )

end event

type cbx_ex_stepout from checkbox within w_test
integer x = 73
integer y = 2144
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_STEPOUT"
end type

event clicked;
updatestyle( )

end event

type cbx_ex_editclick from checkbox within w_test
integer x = 73
integer y = 2080
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_EDITCLICK"
end type

event clicked;
updatestyle( )

end event

type cbx_ex_fixedcolsize from checkbox within w_test
integer x = 73
integer y = 2016
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_FIXEDCOLSIZE"
end type

event clicked;
updatestyle( )

end event

type cbx_ex_fullrowitems from checkbox within w_test
integer x = 73
integer y = 1952
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_FULLROWITEMS"
end type

event clicked;
updatestyle( )

end event

type cbx_ex_grayeddisable from checkbox within w_test
integer x = 73
integer y = 1888
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_GRAYEDDISABLE"
boolean checked = true
end type

event clicked;
updatestyle( )

end event

type cbx_ex_hideheaders from checkbox within w_test
integer x = 73
integer y = 1824
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_HIDEHEADERS"
end type

event clicked;
updatestyle( )

end event

type cbx_ex_nocharselcet from checkbox within w_test
integer x = 73
integer y = 1760
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_NOCHARSELCET"
end type

event clicked;
updatestyle( )

end event

type cbx_ex_nocolumnresize from checkbox within w_test
integer x = 73
integer y = 1696
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_NOCOLUMNRESIZE"
end type

event clicked;
updatestyle( )

end event

type cbx_ex_bitcheckbox from checkbox within w_test
integer x = 73
integer y = 1632
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_BITCHECKBOX"
end type

event clicked;
updatestyle( )

end event

type cbx_ex_tooltipnotify from checkbox within w_test
integer x = 73
integer y = 1568
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_TOOLTIPNOTIFY"
end type

event clicked;
updatestyle( )

end event

type cbx_ex_autohscroll from checkbox within w_test
integer x = 73
integer y = 1504
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_AUTOHSCROLL"
end type

event clicked;
updatestyle( )

end event

type cbx_ex_multiselect from checkbox within w_test
integer x = 73
integer y = 1440
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_MULTISELECT"
boolean checked = true
end type

event clicked;
updatestyle( )

end event

type cbx_ex_fullrowmark from checkbox within w_test
integer x = 73
integer y = 1376
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_FULLROWMARK"
boolean checked = true
end type

event clicked;
updatestyle( )

end event

type cbx_ex_subselect from checkbox within w_test
integer x = 73
integer y = 1312
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_SUBSELECT"
boolean checked = true
end type

event clicked;
updatestyle( )

end event

type cbx_ex_alternatecolor from checkbox within w_test
integer x = 73
integer y = 1248
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_ALTERNATECOLOR"
boolean checked = true
end type

event clicked;
updatestyle( )

end event

type cbx_ex_itemlines from checkbox within w_test
integer x = 73
integer y = 1184
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EX_ITEMLINES"
boolean checked = true
end type

event clicked;
updatestyle( )

end event

type cbx_rtlreading from checkbox within w_test
integer x = 73
integer y = 1008
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_RTLREADING"
end type

event clicked;
updatestyle( )

end event

type cbx_disabledragdrop from checkbox within w_test
integer x = 73
integer y = 944
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_DISABLEDRAGDROP"
end type

event clicked;
updatestyle( )

end event

type cbx_nohscroll from checkbox within w_test
integer x = 73
integer y = 752
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_NOHSCROLL"
end type

event clicked;
updatestyle( )

end event

type cbx_editlabels from checkbox within w_test
integer x = 73
integer y = 880
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_EDITLABELS"
end type

event clicked;
updatestyle( )

end event

type cbx_nonevenheight from checkbox within w_test
integer x = 73
integer y = 816
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_NONEVENHEIGHT"
end type

event clicked;
updatestyle( )

end event

type cbx_noscroll from checkbox within w_test
integer x = 73
integer y = 688
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_NOSCROLL"
end type

event clicked;
updatestyle( )

end event

type cbx_fullrowselect from checkbox within w_test
integer x = 73
integer y = 624
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_FULLROWSELECT"
boolean checked = true
end type

event clicked;
updatestyle( )

end event

type cbx_singleexpand from checkbox within w_test
integer x = 73
integer y = 560
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_SINGLEEXPAND"
end type

event clicked;
updatestyle( )

end event

type cbx_trackselect from checkbox within w_test
integer x = 73
integer y = 496
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_TRACKSELECT"
end type

event clicked;
updatestyle( )

end event

type cbx_checkboxes from checkbox within w_test
integer x = 73
integer y = 432
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_CHECKBOXES"
boolean checked = true
end type

event clicked;
updatestyle( )

end event

type cbx_notooltips from checkbox within w_test
integer x = 73
integer y = 368
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_NOTOOLTIPS"
end type

event clicked;
updatestyle( )

end event

type cbx_showselalways from checkbox within w_test
integer x = 73
integer y = 304
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_SHOWSELALWAYS"
end type

event clicked;
updatestyle( )

end event

type cbx_linesatroot from checkbox within w_test
integer x = 73
integer y = 240
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_LINESATROOT"
boolean checked = true
end type

event clicked;
updatestyle( )

end event

type cbx_haslines from checkbox within w_test
integer x = 73
integer y = 176
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_HASLINES"
boolean checked = true
end type

event clicked;
updatestyle( )

end event

type cbx_hasbuttons from checkbox within w_test
integer x = 73
integer y = 112
integer width = 736
integer height = 64
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "TVS_HASBUTTONS"
boolean checked = true
end type

event clicked;
updatestyle( )

end event

type cb_4 from commandbutton within w_test
integer x = 2903
integer y = 320
integer width = 494
integer height = 76
integer taborder = 40
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
string text = "deleteitem(current)"
end type

event clicked;long r
r = uo_tree.finditem( currenttreeitem!, 0)
uo_tree.deleteitem( r )
end event

type cb_3 from commandbutton within w_test
integer x = 2903
integer y = 224
integer width = 494
integer height = 76
integer taborder = 30
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
string text = "finditem(current)"
end type

event clicked;long r
r = uo_tree.finditem( currenttreeitem!, 0)
messagebox("finditem", r )
end event

type cb_2 from commandbutton within w_test
integer x = 2903
integer y = 128
integer width = 494
integer height = 76
integer taborder = 30
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
string text = "uncheck item"
end type

event clicked;ulong ih
ih = uo_tree.finditem(currenttreeitem!,0)
uo_tree.setitemcheckbox( ih, false)
end event

type cb_1 from commandbutton within w_test
integer x = 2903
integer y = 32
integer width = 494
integer height = 76
integer taborder = 20
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
string text = "check item"
end type

event clicked;ulong ih
ih = uo_tree.finditem(currenttreeitem!,0)
uo_tree.setitemcheckbox( ih, true)
end event

type uo_tree from vo_treelist within w_test
integer x = 878
integer y = 32
integer width = 2002
integer height = 1436
integer taborder = 10
boolean ibs_hasbuttons = false
boolean ibs_haslines = false
boolean ibs_linesatroot = false
end type

event oncbstatechanged;call super::oncbstatechanged;messagebox(classname(), "TVN_CBSTATECHANGED:"+&
	"~r~naction:"+string(action)+&
	"~r~nItem handle:"+string(itemhandle)+&
	"~r~nOld state:"+string(olditemstate)+&
	"~r~New state:"+string(newitemstate)+&
	"~r~nCheckbox:"+string(getitemcheckbox(itemhandle)))

return 0
end event

type gb_styles from groupbox within w_test
integer x = 37
integer y = 32
integer width = 814
integer height = 1064
integer taborder = 10
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "Styles"
end type

type gb_exstyles from groupbox within w_test
integer x = 37
integer y = 1112
integer width = 814
integer height = 1184
integer taborder = 20
integer textsize = -8
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
long textcolor = 33554432
long backcolor = 67108864
string text = "Extended Styles"
end type

