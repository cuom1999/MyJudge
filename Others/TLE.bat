@echo off

start test /s
timeout /t 5

tasklist /FI "IMAGENAME eq test.exe" 2>NUL | find /I /N "test.exe">NUL

if "%ERRORLEVEL%"=="0" (echo Time Limit Exceed > output.txt && taskkill /f /im "test.exe") else (echo Ok > output.txt)
