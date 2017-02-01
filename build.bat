@echo off

REM This is the build script for the project
REM The output is called engine.exe

gcc main.c board.c util.c -o engine