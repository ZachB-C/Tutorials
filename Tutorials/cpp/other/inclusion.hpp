// file inclusion
#include "hello.cpp"

// macro defines a constant
#define MY_GOLDEN_NUMBER 1746

//compile time decision
#ifdef USE64BITS
typedef uint64_t myint;
#else 
typedef uint32_t myint;
#endif

// Only use preprocessor directives to include headers, hardcode constants, portability to 32 oer 64 bit architectures.
//
//
#ifndef PRINT_HELLO_HPP
#define PRINT_HELLO_HPP

void printHello();

#endif
