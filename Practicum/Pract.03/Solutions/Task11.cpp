#include <iostream>

int main()
{
	unsigned int number;
	std::cin >> number;

	unsigned int sum = 0;
	int current;
	std::cin >> current;

	while (current != -1)
	{
		int first = number;
		int second = current;

		if (first < second) 
		{
			int temp = first;
			first = second;
			second = temp;
		}

		while (second != 0)
		{
			int temp = first % second;
			first = second;
			second = temp;
		}

		if (first == 1)
		{
			sum += current;
		}

		std::cin >> current;
	}

	std::cout << sum;
}