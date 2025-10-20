#include <iostream>

int main()
{
	long long number;
	std::cin >> number;

	int digitsSum = number;

	while (number >= 10) {
		digitsSum = 0;

		while (number != 0) {
			digitsSum += (number % 10);
			number /= 10;
		}

		number = digitsSum;
	}

	std::cout << digitsSum;
}
