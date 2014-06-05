@echo off

set pbver=%1
set target=%2

%~d0
cd "%~dp0\src\%pbver%"

echo Rebuild the pbl from sources
echo.
orcascr%pbver% /D targetname="%target%" ..\..\rebuild_pbl_from_src.orca
echo.

if errorlevel 1 goto failed
goto ok

:failed
echo Process failed ?
goto end:

:ok
copy /Y %target%.pbt ..\..\
move /Y %target%.pbl ..\..\
cd "%~dp0"
echo Done. 
echo %lib%.pbl should have been copied in the project directory.

:end
pause
