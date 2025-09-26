#ifndef PRINT_HELLO_HPP
#define PRINT_HELLO_HPP

void printHello();

#endif

// file inclusion
#include "hello.cpp"

// macro defines a constant
#define MY_GOLDEN_NUMBER 1746

// compile time decision
#ifdef USE64BITS
typedef uint64_t myint;
#else
typedef uint32_t myint;
#endif
