#include <iostream>

int main()
{
	int first = 0, second = 0, third = 0;
	std::cin >> first >> second >> third;

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

	std::cout << first << ' ' << second << ' ' << third;
}