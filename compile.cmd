@ECHO OFF
cd ./objects
g++ -c ../source/*.cpp
g++ -o ../build/main.exe ./*.o
cd ..\build
main.exe
