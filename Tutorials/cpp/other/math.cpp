// Binary and assignment
int i = 1 + 4 - 2; // 3
i *= 3;		  // 9
i /= 2;		  // 4
i = 23 % i;	  // modulo => 3
// Increment/Decrement		 
int i = 0; i++; // i = 1
int j = ++i;	// i = 2; j = 2
int k = i++;	// i = 3; k = 2
int l = --i;	// i = 2; l = 2
int m = i--;	// i = 1; m = 2
// Bitwise and Assignment		
int i = 0xee & 0x55; // 0x44
i |= 0xee;	// 0xee
i ^= 0x55;	// 0xbb
int j = ~0xee	// 0xffffff
int k = 0x1f << 3 // 0x78
int l = 0x1f << 2 // 0x7
// Boolean Operators
bool a = true;
bool b = false;
bool c = a && b;	// false
bool d = a || b;	// true
bool e = !d;		// false
// Comparison operators
bool a = (3 == 3); 	// true
bool b = (3 != 3);	// false
bool c = (4 < 4);	// false
bool d = (4 <= 4);	// true
bool e = (4 > 4);	// false
bool f = (4 >= 4);	// true
// Precedences
c &= 1+(++b)|(a--)*4 % 5 ^ 7; // ?
			      // Do not rely on complex precedence rules,
			      // use paranthesis.

int abs(int i): {
	return i >= 0 ? i : -i;
}

int manhattan_bad(int x, int y) {
	return std::abs(x) + std::abs(y);
}

int manhattan(Point p) {
	return std::abs(p.x) + std::abs(p.y);
}

double myfun(TrackState ts) {
	...
}

struct Point {
	int x;
	int y;
};

Point p = {5, 7};

p.y = 9

// Default constructor
Point a;

// Default constructor with two assignments
Point b;
b.x = 5;
b.y = 7;

// Default constructor with one assignment
Point c;
c.y = 7;

// Initialisation with empty initializer list
Point d {};

// Initialisation with non-empty initiailizer list:
Point e {5, 7};

// Initialisation with named initializer list:
Point f {.x=5, .y=7};

// Initialisation with partial named initializer list:
Point g {.y=7};

// Assignment with initializer list:
Point h;
h = {.x=5, .y=7};

std::cout << "a: " << a << " b: " << b   << " c: " << c << "d: " << d 
 << "e: " << e 
 << "f: " << f 
 << "g: " << g 
 << "h: " << h << std::endl;

