@echo off

REM This is the build script for the project
REM The output is called engine.exe

g++ main.c search.c board.c util.c eval.c build.c tests.c -o engine