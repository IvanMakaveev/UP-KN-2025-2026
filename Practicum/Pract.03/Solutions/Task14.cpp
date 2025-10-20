#include <iostream>

int main()
{
	unsigned int N;
	std::cin >> N;

	unsigned int sum = 0;
	unsigned int max = 0;
	for (size_t i = 0; i < N; i++)
	{
		unsigned int current = 0;
		std::cin >> current;

		if (max < current)
		{
			max = current;
		}

		sum += current;
	}

	if (sum - max == max)
	{
		std::cout << "Yes: " << max;
	}
	else
	{
		std::cout << "No";
	}
}