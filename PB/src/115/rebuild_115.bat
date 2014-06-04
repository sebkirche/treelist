echo off
%~d0
cd "%~dp0"

set lib=TreeList115
set pbver=115

echo Rebuild the pbl from sources
echo.
orcascr%pbver% /D targetname="%lib%" ..\..\rebuild_pbl_from_src.orca
echo.

if errorlevel 1 goto failed
goto ok

:failed
echo Process failed ?
goto end:

:ok
echo Done. 
echo %lib%.pbl should have been copied in the project directory.

:end
pause
