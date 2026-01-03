@echo off

set ccflags=-std=c99 -Wall
set ldflags=-luser32 -lgdi32 -lopengl32
gcc %ccflags% -O0 -g -o bin/out.exe src/main.c %ldflags%
.\bin\out.exe
