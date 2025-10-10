#include <iostream>

int main()
{
	double first = 0, second = 0, third = 0;
	std::cin >> first >> second >> third;

	if (first <= 0 || second <= 0 || third <= 0)
	{
		std::cout << "Incorrect input data";
	}
	else if ((first + second) > third &&
		(second + third) > first &&
		(first + third) > second)
	{
		std::cout << "This triangle exists.";
	}
	else
	{
		std::cout << "This triangle doesn't exist.";
	}
}