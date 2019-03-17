@echo off
javac MyJudge.java
javac ShowResult.java

set a=%cd%
md "D:\Path"
echo %a%\ >"D:\Path\Path.txt"
pause