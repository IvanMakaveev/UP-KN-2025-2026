#include <iostream>

bool haveCommonBit(int first, int second) {
	return (first & second) != 0;
}

/*
Example of how haveCommonBit works (first = 5, second = 3):

Step 0 (input):
first  = 5  -> 0101
second = 3  -> 0011

Step 1: first & second
0101 & 0011 = 0001 (1)

Step 2: check if != 0
0001 != 0 -> true

Result:
The function returns true because first and second have at least one common bit set (the least significant bit in this case).
*/

int main()
{
	int first, second;
	std::cin >> first >> second;
	std::cout << haveCommonBit(first, second);
}
