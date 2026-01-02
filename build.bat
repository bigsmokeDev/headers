@echo off

set ccflags = -std=c99 -Wall
set ldflags = -luser32
gcc %ccflags% %ldflags% -O0 -g -o bin/out.exe src/main.c
