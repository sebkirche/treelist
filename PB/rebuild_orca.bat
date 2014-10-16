@echo off

set pbver=%1
set target=%2

%~d0

set logfile=%~dp0src\%pbver%\rebuild_%target%.log
REM ~ set lpath=%~dp0
REM ~ if %lpath:~-1%==\ set lpath=%lpath:~0,-1%
REM for offline reconstruct, we need to work with all files in the same directory
set lpath=".\\"

REM ~ for the project path, the backslashes need to be doubled (WTF ?!!)
set ppath=%~dp0src\%pbver%
set ppath=%ppath:\=\\%

REM ~ work in source directory
cd %~dp0src\%pbver%

echo Rebuild the pbl from sources
echo working dir=%cd%
echo lpath=%lpath%
echo ppath=%ppath%
echo.
if %pbver%==90 (
	rem orcascr9 is a different from later versions, we need a specific script
	orcascr9 /D targetname="%target%" /D lpath="%lpath%" /D ppath="%ppath%" /D logfilename="%logfile%" ..\..\rebuild_pbl_from_src_90.orca
) else (
	orcascr%pbver% /D targetname="%target%" /D lpath="%lpath%" /D ppath="%ppath%" /D logfilename="%logfile%" ..\..\rebuild_pbl_from_src.orca
)
echo.

if errorlevel 1 goto failed
goto ok

:failed
echo Process failed ?
goto end:

:ok
attrib -R ..\..\%target%.pbt
copy /Y %target%.pbt ..\..\
move /Y %target%.pbl ..\..\
cd "%~dp0"
echo Done. 
echo %target%.pbl should have been copied in the project directory.

:end
pause
