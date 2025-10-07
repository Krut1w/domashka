@echo off
chcp 1251 > log
del log

set MAIN=main.cpp
set SORT=sort.cpp
set EXE=main.exe

set CHARSET="-finput-charset=utf-8 -fexec-charset=windows-1251"
if exist %EXE% del %EXE%

g++ "%CHARSET" 