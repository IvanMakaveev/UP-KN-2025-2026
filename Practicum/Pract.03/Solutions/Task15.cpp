#include <iostream>

int main()
{
	double element = 0.5;
	unsigned int N;
	std::cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		element = (element * element + 1) / 2;
	}

	std::cout << element;
}