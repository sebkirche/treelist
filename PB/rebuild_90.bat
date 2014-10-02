rem @echo off

set target=TreeList90

%~d0
set logfile=%~dp0src\90\rebuild_%target%.log

set lpath=%~dp0
if %lpath:~-1%==\ set lpath=%lpath:~0,-1%



echo Rebuild the pbl from sources
echo.
orcascr9 /D targetname="%target%" /D lpath="%lpath%" /D ppath="%~dp0src\90" /D logfilename="%logfile%" rebuild_pbl_from_src_90.orca
echo.

if errorlevel 1 goto failed
goto ok

:failed
echo Process failed ?
goto end:

:ok
REM ~ attrib -R ..\..\%target%.pbt
REM ~ copy /Y %target%.pbt ..\..\
REM ~ move /Y %target%.pbl ..\..\
REM ~ cd "%~dp0"
echo Done. 
echo %lib%.pbl should have been copied in the project directory.

:end
pause
