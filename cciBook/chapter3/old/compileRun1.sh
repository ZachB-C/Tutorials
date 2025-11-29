#!/bin/bash
# Compiles and runs a program displaying errors
clear
g++ t_linkedlist.cpp stackqueue.cpp --include="t_linkedlist.h" -O0 -Werror -Wpedantic -pedantic-errors -Wall -Wextra -Wno-change-meanings -o t_linkedlist.exe
valgrind -s --leak-check=yes ./t_linkedlist.exe;
