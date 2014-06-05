HA$PBExportHeader$treelist115.sra
$PBExportComments$Generated Application Object
forward
global type treelist115 from application
end type
global transaction sqlca
global dynamicdescriptionarea sqlda
global dynamicstagingarea sqlsa
global error error
global message message
end forward

global type treelist115 from application
string appname = "treelist115"
end type
global treelist115 treelist115

on treelist115.create
appname="treelist115"
message=create message
sqlca=create transaction
sqlda=create dynamicdescriptionarea
sqlsa=create dynamicstagingarea
error=create error
end on

on treelist115.destroy
destroy(sqlca)
destroy(sqlda)
destroy(sqlsa)
destroy(error)
destroy(message)
end on

event open;
open(w_test)

end event

