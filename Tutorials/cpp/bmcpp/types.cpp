#include <cstdint>

int8_t c = -3;			// 8 bits, replaces char
uint8_t c = 4;			// 8 bits, replaces unsigned char
				
int16_t s = -444;		// 16 bits, replaces short
uint16_t s = 444;		// 16 bits replaces unsigned short

int32_t s = -0674;		// 32 bits, replaces int
uint32_t s = 0674;		// 32 bits replaces unsigned int
				
int64_t s = -0x1bc;		// 64 bits, replaces long long
uint64_t s = 0x1bc;		// 64 bits, replaces unsigned long long





bool b = true;			// boolean, true or false

char c = 'a';			// 8 bit ASCII character
char* s = "a C string";		// array of chars ended by \0
std::string t = "a C++ string";	// class provided by the STL

char c = -3;			// 8 bit signed integer
signed char c = -3;		// 8 bits integer
unsigned char c = 4;		// 8 bits unsigned integer

short int s = -444;		// 16 bit signed integer
unsigned short s = 444;		// 16 bits unsigned integer
short s = -444;			// int is optional

int i = -123456;		// 32 bits signed integer
unsigned int i = 1234567;	// 32 bits signed integer

long l=0L;			// 32 or 64 bits (ptr size)
unsigned long l = 0UL;		// 32 or 64 bits (ptr size)

long long ll = 0LL;		// 64 bits unsigned integer
unsigned long long l = 0ULL;	// 64 bits unsigned integer

float f = 1.23f;		// 32 (23+7+1) bits float
double d = 1.23E34;		// 64 (52+11+1) bits float

