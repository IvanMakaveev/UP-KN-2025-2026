#include <iostream>

int main()
{
	int number;
	std::cin >> number;

	for (int i = 2; i <= number / 2; i++)
	{
		bool isPrimeFirst = true;
		double firstNumSqrt = sqrt(i);
		for (int j = 2; j <= firstNumSqrt; j++)
		{
			if (i % j == 0)
			{
				isPrimeFirst = false;
				break;
			}
		}

		if (!isPrimeFirst)
		{
			continue;
		}

		int otherNumber = number - i;

		bool isPrimeSecond = true;
		double otherNumSqrt = sqrt(otherNumber);
		for (int j = 2; j <= otherNumSqrt; j++)
		{
			if (otherNumber % j == 0)
			{
				isPrimeSecond = false;
				break;
			}
		}

		if (!isPrimeSecond)
		{
			continue;
		}

		std::cout << number << " = " << i << " + " << otherNumber << std::endl;
	}
}