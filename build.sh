#!/bin/bash
echo Compilation Started
gcc main.c lib/*.c -o bin/app.out -I include

echo Running program .....
echo
./bin/app.out
echo 

