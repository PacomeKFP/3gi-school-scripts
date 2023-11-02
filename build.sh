#!/bin/bash
echo Starting Compilation
gcc main.c lib/*.c -o bin/app -I include
echo Compilation Complete
echo Starting Execution
echo
./bin/app