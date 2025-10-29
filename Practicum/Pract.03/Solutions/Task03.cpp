#include <iostream>

int main()
{
	int number;
	std::cin >> number;

	int result = 1;

	for (int i = 2; i <= number; i++) {
		result *= i;
	}

	std::cout << "Factorial: " << result << std::endl;
}
