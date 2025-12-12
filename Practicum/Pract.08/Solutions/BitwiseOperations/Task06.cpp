#include <iostream>;

unsigned powerOfTwo(unsigned power)
{
	if (power > 31) {
		return 0;
	}

	return 1 << power;
}

unsigned getNumFromBits(unsigned number, unsigned startIndex, unsigned n)
{
	// If the starting index is larger than the length of bits we want,
   // then we shift the number to the right 
   // (startIndex - n + 1) determines how much to shift

	if (startIndex > n) {
		number = number >> startIndex - n + 1;
	}
	else {
		// Otherwise, if startIndex <= n, 
        // we reduce n so that we only extract
		n = startIndex;
	}

	// Build a mask of n bits:
	// powerOfTwo(n) creates 1 << n:
	// n = 3 → 0000 1000
	// Subtract 1:
	// 0000 1000 - 1 = 0000 0111
	unsigned mask = powerOfTwo(n) - 1; 

	return number & mask;
	//     01000
	// AND 00111
	// ---------
	//     00100   = 4
}

int main()
{
	unsigned x, m, n;
	std::cin >> x >> m >> n;
	std::cout << getNumFromBits(x, m, n);
}