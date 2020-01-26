echo off
:loop

platex kaiseki
if %errorlevel%	geq 1 goto loop
call dellog.bat
rem dviout.exe kaiseki.dvi