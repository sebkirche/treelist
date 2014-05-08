HA$PBExportHeader$w_test.srw
forward
global type w_test from window
end type
type uo_1 from vo_treelist within w_test
end type
end forward

global type w_test from window
integer width = 1563
integer height = 824
boolean titlebar = true
string title = "Untitled"
boolean controlmenu = true
boolean minbox = true
boolean maxbox = true
boolean resizable = true
long backcolor = 67108864
string icon = "AppIcon!"
boolean center = true
uo_1 uo_1
end type
global w_test w_test

on w_test.create
this.uo_1=create uo_1
this.Control[]={this.uo_1}
end on

on w_test.destroy
destroy(this.uo_1)
end on

event open;

uo_1.insertcolumn(0, "test")
end event

type uo_1 from vo_treelist within w_test
integer x = 119
integer y = 108
integer width = 1243
integer height = 452
integer taborder = 10
end type

