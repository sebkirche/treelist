HA$PBExportHeader$w_test.srw
forward
global type w_test from window
end type
type uo_tree from vo_treelist within w_test
end type
end forward

global type w_test from window
integer width = 1536
integer height = 908
boolean titlebar = true
string title = "Untitled"
boolean controlmenu = true
boolean minbox = true
boolean maxbox = true
boolean resizable = true
long backcolor = 67108864
string icon = "AppIcon!"
boolean center = true
uo_tree uo_tree
end type
global w_test w_test

type variables

long il_deltaheight

end variables

on w_test.create
this.uo_tree=create uo_tree
this.Control[]={this.uo_tree}
end on

on w_test.destroy
destroy(this.uo_tree)
end on

event open;
il_deltaheight = height - uo_tree.height - uo_tree.y

uo_tree.insertcolumn(0, "col 1")
uo_tree.insertcolumn(1,"col 2")
uo_tree.addcolumn("col 3")

ulong i1, i2
uo_tree.insertitem(0,"foo")
i1 = uo_tree.insertitem(1,"bar")
uo_tree.insertitem(2,"baz")
uo_tree.insertitem(1,"asdf")

end event

event resize;
uo_tree.width = newwidth - uo_tree.x * 2
uo_tree.height = max(newheight - il_deltaheight, pixelstounits(50,YPixelsToUnits!))

end event

type uo_tree from vo_treelist within w_test
integer x = 32
integer y = 32
integer width = 1426
integer height = 452
integer taborder = 10
end type

