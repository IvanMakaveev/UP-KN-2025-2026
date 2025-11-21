#include <iostream>

bool isEven(int number) {
	int mask = 1;
	// check the last bit
	// if it is 1 -> number is odd
	// if it is 0 -> number is even
	return !(number & mask);
}

int main()
{
	int num;
	std::cin >> num;
	std::cout << isEven(num);
}

