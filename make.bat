REM it broken

cls
@echo off

setlocal

pause

call make


echo Now your driver is ready

pause


IF EXIST "filename" (
  REM Do one thing
  call rm *.o
)

@REM  ELSE (
@REM   REM Do another thing
@REM )