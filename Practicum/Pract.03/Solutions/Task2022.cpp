#include <iostream>

int main()
{
	unsigned int elementsCount;
	std::cin >> elementsCount;

	if (elementsCount == 0)
	{
		std::cout << "No input given!";
		return 0;
	}

	unsigned int totalGcd;
	std::cin >> totalGcd;

	for (size_t i = 1; i < elementsCount; i++)
	{
		unsigned int currentElement;
		std::cin >> currentElement;

		//gcd(totalGcd, currentElement)
		//swap
		if (totalGcd < currentElement) {
			int temp = totalGcd;
			totalGcd = currentElement;
			currentElement = temp;
		}
		
		while (currentElement != 0)
		{
			int temp = totalGcd % currentElement;
			totalGcd = currentElement;
			currentElement = temp;
		}
	}

	std::cout << (totalGcd == 1);

	return 0;
}