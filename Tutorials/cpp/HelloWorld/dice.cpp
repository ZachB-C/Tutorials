#include <iostream>
#include <random>

//using namespace std;

int main() {
	// Cannot map a number to 100 if it is not multiple of 100
	// random_device
	// mt19937 (Merson twister)
	// mt19937_64	
	// Distributions
	// uniform_int_distribution
	// uniform_real_distribution
	// poisson_distribution ...
	std::random_device rd;
	// mt is not cryptographically secure
	// seedable
	// 499 MB/s = 6.5 cycles/byte for me
	// 2^197 - 1 period
	// Can replicate a run as seedable.
	// Reproducible (standard-mandated algorithm)
	// 	not platform dependent.
	//
	// Random device
	// 	1.93 MB/s = 1684 cycles/byte
	// 		Platform dependent (GCC 4.8 can use IVB RDRAND)
	// 	Possibly crypto-secure (true for VC)
	// 		(check documentation)
	//
	// 	Non-seedable, non-reproducible.
	//
	// 	Uniform_int_distribution
	// 	Takes any uniform random generator
	// 	Emits any desired range of integers [low, high]
	// 	signed/unsigned short/int/long/long long
	// 	not char/signed char/unsigned char
	//	Preserves perfect uniformity, potentially 
	//	running multiple times.
	//	1/3 speed of the engine.
	//	Deterministic but not invariant, varies across platforms.
	//
	//	don't use random_shuffle
	//	shuffle
	//	run mt19937 fast copying or constructing is slow
	//	Multiple threads cannot simultaneously call a single generator. One per thread, thread local.
	//	Skip uniform_int_distribution if you want to map to a power of 2 as mt19937 is power of two. Then you can use % 2^3 or something.
	// Don't use default rng engine.	
	// Deterministic 32-bit seed
	//std::mt19937 mt(1729);	
	//Random 32 bit seed, if you need more randomness
	//use something else.
	std::mt19937 mt(rd());
       	// [Inclusive, Inclusive] 
	// Pass the engine to the distribution
	std::uniform_int_distribution<int> dist(1, 6);
	std::cout << dist(mt);
	std::cout << std::endl;


	// bad version
	// srand(time(nullptr))
	// const short minValue = 1;
	// cont short maxValue = 6; 
	// // short first = rand() % (maxValue - minValue +1)  + minValue
	// short second = rand() % (maxValue - minValue +1)  + minValue
	return 0;
}

