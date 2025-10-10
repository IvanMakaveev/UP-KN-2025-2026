#include <iostream>

int main()
{
	unsigned int first = 0, second = 0, third = 0;
	std::cin >> first >> second >> third;

	if (first > 9 || second > 9 || third > 9)
	{
		std::cout << "Incorrect input data";
	}

	int temp = 0;
	if (first > second)
	{
		temp = first;
		first = second;
		second = temp;
	}

	if (second > third)
	{
		temp = second;
		second = third;
		third = temp;
	}

	if (first > second)
	{
		temp = first;
		first = second;
		second = temp;
	}

	std::cout << third << second << first;
}