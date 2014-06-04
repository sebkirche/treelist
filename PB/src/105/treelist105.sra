HA$PBExportHeader$treelist105.sra
$PBExportComments$Generated Application Object
forward
global type treelist105 from application
end type
global transaction sqlca
global dynamicdescriptionarea sqlda
global dynamicstagingarea sqlsa
global error error
global message message
end forward

global type treelist105 from application
string appname = "treelist105"
end type
global treelist105 treelist105

on treelist105.create
appname="treelist105"
message=create message
sqlca=create transaction
sqlda=create dynamicdescriptionarea
sqlsa=create dynamicstagingarea
error=create error
end on

on treelist105.destroy
destroy(sqlca)
destroy(sqlda)
destroy(sqlsa)
destroy(error)
destroy(message)
end on

event open;
open(w_test)

end event

