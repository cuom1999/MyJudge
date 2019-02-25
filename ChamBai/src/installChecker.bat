@echo off
g++ -O2 MyJudgeFcts.cpp Checker.cpp Main.cpp -o Checker.exe
cd ..
move "src\Checker.exe" %cd%
echo Successful!
pause