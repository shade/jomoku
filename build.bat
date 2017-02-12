@echo off

REM This is the build script for the project
REM The output is called engine.exe

g++ main.cpp board.cpp util.cpp -o engine