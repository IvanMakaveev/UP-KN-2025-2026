#include <iostream>

int main()
{
	int left, right;
	std::cin >> left >> right;

	if (left > right) {
		int temp = left;
		left = right;
		right = temp;
	}

	int sumOfPrimes = 0;

	for (int i = left; i <= right; i++) {
		if (i <= 1) {
			continue;
		}

		bool isPrime = true;
		double sqrt = std::sqrt(i);

		for (int j = 2; j <= sqrt; j++) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime) {
			sumOfPrimes += i;
		}
	}

	std::cout << "Sum of primes: " << sumOfPrimes;
}

