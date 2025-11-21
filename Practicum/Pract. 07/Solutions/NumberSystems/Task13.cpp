#include <iostream>

unsigned pow(unsigned base, unsigned exp) {
	unsigned result = 1;
	for (unsigned i = 0; i < exp; i++) {
		result *= base;
	}
	return result;
}

void printSubset(const int arr[], size_t size, unsigned mask) {
	std::cout << "[ ";

	for (size_t i = 0; i < size; i++) {
		// check if the current bit in mask is 1
		// if yes, include arr[i] in the current subset
		if (mask & 1) {
			std::cout << arr[i] << " ";
		}

		// move to the next bit 
		mask /= 2; // <=> mask>>=1;
	}

	std::cout << "]" << std::endl;
}

void printSubsets(const int arr[], size_t size) {
	// total number of subsets = 2^size
	unsigned subsetsCount = pow(2, size); // <=> 1 << size;  

	// loop through all possible masks (0 to 2^size - 1)
	// each mask represents a unique subset
	for (unsigned i = 0; i < subsetsCount; i++) {
		printSubset(arr, size, i);
	}
}

int main()
{
	const size_t SIZE = 4;
	int arr[SIZE] = { 1, 4, 7, 8 };
	printSubsets(arr, SIZE);
}

/*
Example (arr = {1, 4, 7, 8}):

Mask = 0 (0000) -> {}          // no bits set
Mask = 1 (0001) -> {1}         // first bit set
Mask = 2 (0010) -> {4}         // second bit set
Mask = 3 (0011) -> {1, 4}      // first and second bits set
Mask = 4 (0100) -> {7}         // third bit set
Mask = 5 (0101) -> {1, 7}      // first and third bits set
Mask = 6 (0110) -> {4, 7}      // second and third bits set
Mask = 7 (0111) -> {1, 4, 7}   // first, second, third bits set
...
Mask = 15 (1111) -> {1, 4, 7, 8} // all bits set

Explanation:
- Each bit in the mask corresponds to an element in the array.
- If a bit is 1, the corresponding element is included in the subset.
- Iterating masks from 0 to 2^size - 1 generates all possible subsets.
*/