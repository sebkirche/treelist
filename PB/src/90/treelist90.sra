$PBExportHeader$treelist90.sra
$PBExportComments$Generated Application Object
forward
global type treelist90 from application
end type
global transaction sqlca
global dynamicdescriptionarea sqlda
global dynamicstagingarea sqlsa
global error error
global message message
end forward

global type treelist90 from application
string appname = "treelist90"
event myevent ( readonly integer ai_val )
end type
global treelist90 treelist90

event myevent(readonly integer ai_val);
int t
t = ai_val

int toto

toto = + 1

dec n

n = +4.0


int i = +12, j = -1; long z

i = -j
z = j - i + -2

for i = 42+5*7 to long("42") step -2.0
	
next

end event

on treelist90.create
appname="treelist90"
message=create message
sqlca=create transaction
sqlda=create dynamicdescriptionarea
sqlsa=create dynamicstagingarea
error=create error
end on

on treelist90.destroy
destroy(sqlca)
destroy(sqlda)
destroy(sqlsa)
destroy(error)
destroy(message)
end on

event open;
string s
s = "t~000est"
s += "truc"
//messagebox("escape", s)

/*
powerobject o

o.create()
*/

open(w_test)


end event

