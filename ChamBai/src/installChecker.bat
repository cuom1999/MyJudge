@echo off

g++ MyJudgeFcts.cpp Checker.cpp Main.cpp SideFcts.cpp -o Checker.exe
g++ -DCOMPILED MyJudgeFcts.cpp Checker.cpp Main.cpp SideFcts.cpp -o Checker_Compiled.exe

cd ..
move "src\Checker.exe" %cd%
move "src\Checker_Compiled.exe" %cd%

echo Successful!
pause