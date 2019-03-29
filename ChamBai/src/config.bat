@echo off
g++ Main.cpp SideFcts.cpp MyJudgeFcts.cpp SoFile.cpp -o SoFile.exe
g++ Main.cpp SideFcts.cpp MyJudgeFcts.cpp Float.cpp -o Float.exe
g++ -DCOMPILED Main.cpp SideFcts.cpp MyJudgeFcts.cpp SoFile.cpp -o SoFile_Compiled.exe
g++ -DCOMPILED Main.cpp SideFcts.cpp MyJudgeFcts.cpp Float.cpp -o Float_Compiled.exe

cd..

move "src\SoFile.exe" %cd%
move "src\SoFile_Compiled.exe" %cd%
move "src\Float.exe" %cd%
move "src\Float_Compiled.exe" %cd%

echo Successful!
pause