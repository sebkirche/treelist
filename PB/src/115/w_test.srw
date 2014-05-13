HA$PBExportHeader$w_test.srw
forward
global type w_test from window
end type
type cb_5 from commandbutton within w_test
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
end forward

global type w_test from window
integer width = 2949
integer height = 1868
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
cb_5 cb_5
cb_4 cb_4
cb_3 cb_3
cb_2 cb_2
cb_1 cb_1
uo_tree uo_tree
end type
global w_test w_test

type variables

long il_deltaheight

end variables

event onnotify;if isvalid(uo_tree) and not isnull(uo_tree) then
	return uo_tree.event WM_NOTIFY(wparam,lparam)
end if
end event

on w_test.create
this.cb_5=create cb_5
this.cb_4=create cb_4
this.cb_3=create cb_3
this.cb_2=create cb_2
this.cb_1=create cb_1
this.uo_tree=create uo_tree
this.Control[]={this.cb_5,&
this.cb_4,&
this.cb_3,&
this.cb_2,&
this.cb_1,&
this.uo_tree}
end on

on w_test.destroy
destroy(this.cb_5)
destroy(this.cb_4)
destroy(this.cb_3)
destroy(this.cb_2)
destroy(this.cb_1)
destroy(this.uo_tree)
end on

event open;il_deltaheight = height - uo_tree.height - uo_tree.y

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

end event

event resize;
uo_tree.width = newwidth - uo_tree.x * 2
uo_tree.height = max(newheight - il_deltaheight, pixelstounits(50,YPixelsToUnits!))

end event

type cb_5 from commandbutton within w_test
integer x = 1079
integer y = 1496
integer width = 402
integer height = 112
integer taborder = 20
integer textsize = -10
integer weight = 400
fontcharset fontcharset = ansi!
fontpitch fontpitch = variable!
fontfamily fontfamily = swiss!
string facename = "Tahoma"
string text = "none"
end type

event clicked;
uo_tree.style *= 2
end event

type cb_4 from commandbutton within w_test
integer x = 439
integer y = 1632
integer width = 562
integer height = 112
integer taborder = 40
integer textsize = -10
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
integer x = 439
integer y = 1500
integer width = 507
integer height = 112
integer taborder = 30
integer textsize = -10
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
integer x = 23
integer y = 1632
integer width = 402
integer height = 112
integer taborder = 30
integer textsize = -10
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
integer x = 23
integer y = 1500
integer width = 402
integer height = 112
integer taborder = 20
integer textsize = -10
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
integer x = 32
integer y = 32
integer width = 2848
integer height = 1436
integer taborder = 10
boolean ibs_ex_hideheaders = true
boolean ibs_ex_itemlines = true
end type

event oncbstatechanged;call super::oncbstatechanged;messagebox(classname(), "TVN_CBSTATECHANGED:"+&
	"~r~naction:"+string(action)+&
	"~r~nItem handle:"+string(itemhandle)+&
	"~r~nOld state:"+string(olditemstate)+&
	"~r~New state:"+string(newitemstate)+&
	"~r~nCheckbox:"+string(getitemcheckbox(itemhandle)))

return 0
end event

