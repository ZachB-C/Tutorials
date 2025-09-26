#!/bin/bash
# Compiles and runs a program displaying errors
clear
echo $1
rm -f $1.exe;
g++ $1.cpp -Werror -Wpedantic -pedantic-errors -Wall -Wextra -Wno-change-meanings -o $1.exe; ./$1.exe;
